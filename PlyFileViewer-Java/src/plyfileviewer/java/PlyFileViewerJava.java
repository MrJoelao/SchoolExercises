package plyfileviewer.java;

import javafx.application.Application;
import javafx.geometry.Point3D;
import javafx.scene.AmbientLight;
import javafx.scene.Camera;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.scene.paint.PhongMaterial;
import javafx.scene.shape.DrawMode;
import javafx.scene.shape.MeshView;
import javafx.scene.shape.TriangleMesh;
import javafx.scene.shape.VertexFormat;
import javafx.stage.Stage;
import java.io.IOException;

import javafx.scene.transform.Rotate;
import javafx.scene.PerspectiveCamera;
import javafx.scene.transform.Translate;

/**
 * Classe principale dell'applicazione PlyFileViewerJava.
 * Questa classe estende Application di JavaFX e gestisce la visualizzazione di un file PLY. così pulli :)
 */

public class PlyFileViewerJava extends Application {
    // Costanti per identificare il tipo di file PLY
    public static final int ASCII = 0;
    public static final int BINARY = 1;
    public static final int INVALID = -1;
    public static final int EXCEPTION = -2;
    private Point3D aCenterPoint;
    private Point3D CameraPosition;
    private Camera camera;
    private boolean debug = false;

    // Percorso del file PLY da visualizzare
    private String filePath = "airplane.ply"; // LowerJawScan.ply = Binario, airplane.ply = ASCII.

    @Override
    public void start(Stage primaryStage) throws IOException {
        // Creazione di un gruppo per contenere la mesh
        Group root = new Group();
        Scene scene = new Scene(root, 800, 600, true);
        scene.setFill(Color.WHITE);

        PlyReader plyReader = null;
        // Identificazione del tipo di file PLY
        int plyType = IdentifierPlyType.identifyPlyType(filePath);
        switch (plyType) {
            case ASCII:
                if(debug) System.out.println("The file is in ASCII format");
                plyReader = new PlyReaderAscii();
                plyReader.readPlyFile(filePath);
                break;
            case BINARY:
                if(debug) System.out.println("The file is in binary format");
                plyReader = new PlyReaderBin();
                plyReader.readPlyFile(filePath);
                break;
            case INVALID:
                System.err.println("Not a valid PLY file");
                return;
            case EXCEPTION:
                System.err.println("Exception while reading the PLY file");
                return;
        }

        // Creazione della mesh da visualizzare
        TriangleMesh mesh = new TriangleMesh(VertexFormat.POINT_TEXCOORD);
        // Aggiunta dei vertici al mesh
        for (Vertex vertex : plyReader.getVertices()) {
            mesh.getPoints().addAll((float) vertex.getX(), (float) vertex.getY(), (float) vertex.getZ());
        }

        // Aggiunta delle facce al mesh
        for (Face face : plyReader.getFaces()) {
            int[] vertexIndices = face.getVertexIndices();
            mesh.getFaces().addAll(vertexIndices[0], 0, vertexIndices[1], 0, vertexIndices[2], 0);
        }

        mesh.getTexCoords().addAll(0,0);

        // Creazione della vista della mesh
        MeshView meshView = new MeshView(mesh);
        meshView.setDrawMode(DrawMode.FILL);
        meshView.setMaterial(new PhongMaterial(Color.RED));
        root.getChildren().add(meshView);

        //Camera
        camera = new PerspectiveCamera();
        setCameraPosition(meshView);
        scene.setCamera(camera);

        // Titolo e scena
        primaryStage.setTitle("PlyFileViewer-Java");
        primaryStage.setScene(scene);
        primaryStage.show();

        // Stampa di debug
        if(debug){
            System.out.println("Number of vertices: " + plyReader.getVertices().size());
            System.out.println("Number of faces: " + plyReader.getFaces().size());
            plyReader.debugPrintContent();
            plyReader.debugPrintVertices();
            plyReader.debugPrintFaces();
        }

    }

    // Imposta la posizione della camera per visualizzare la mesh
    public void setCameraPosition(MeshView mesh){
        //camera = new PerspectiveCamera(); // Costruttore già chiamato in start

        // Reset della camera
        camera.getTransforms().clear();
        camera.setTranslateX(0);
        camera.setTranslateY(0);
        camera.setTranslateZ(0);

        // Calcolo del bounding box della mesh
        Rect3D boundingRect = calculateBoundingBox(mesh);

        // Calcolo del punto centrale del bounding box
        Point3D centerPoint = new Point3D((boundingRect.MinX + boundingRect.MaxX)/2, (boundingRect.MinY + boundingRect.MaxY) / 2, (boundingRect.MinZ + boundingRect.MaxZ)/2);
        Point3D cameraPoint = new Point3D(centerPoint.getX(), centerPoint.getY(), boundingRect.MinZ + ((boundingRect.MaxZ-boundingRect.MinZ)* 4));

        // Impostazione del punto centrale e della posizione della camera
        aCenterPoint = centerPoint;
        CameraPosition = cameraPoint;

        // Traslazione della camera
        Translate pivot = new Translate(cameraPoint.getX(), cameraPoint.getY(), cameraPoint.getZ());
        camera.translateXProperty().set(cameraPoint.getX());
        camera.translateYProperty().set(cameraPoint.getY());
        camera.translateZProperty().set(cameraPoint.getZ());

        // Rotazione della camera
        Rotate yRotate = new Rotate();
        yRotate.setAxis(Rotate.Y_AXIS);
        yRotate.setPivotX(cameraPoint.getX());
        yRotate.setPivotY(cameraPoint.getY());
        yRotate.setPivotZ(cameraPoint.getZ());
        yRotate.setAngle(180);

        // Aggiunta delle trasformazioni alla camera
        camera.getTransforms().add(yRotate);
        camera.setNearClip(0.125f);
        camera.setFarClip(100000f);

        // Aggiunta di una luce ambientale
        AmbientLight ambientLight = new AmbientLight();
        ambientLight.setColor(Color.CORAL);

        camera.setViewOrder(10);

    }

    // Calcola il bounding box di una MeshView
    public Rect3D calculateBoundingBox(MeshView mesh){
        // Calcolo del bounding box
        Rect3D boundingBox = new Rect3D(mesh.getBoundsInParent());
        aCenterPoint = new Point3D((boundingBox.MinX+boundingBox.MaxX)/2, (boundingBox.MinY+boundingBox.MaxY)/2, (boundingBox.MinZ+boundingBox.MaxZ)/2);

        return boundingBox;
    }

    public static void main(String[] args) {
        launch(args);
    }
}