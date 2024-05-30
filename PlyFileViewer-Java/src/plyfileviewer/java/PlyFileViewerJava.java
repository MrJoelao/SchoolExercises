package plyfileviewer.java;

import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.geometry.Bounds;
import javafx.geometry.Point3D;
import javafx.scene.Camera;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.input.MouseEvent;
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

/**
 * Classe principale dell'applicazione PlyFileViewerJava.
 * Questa classe estende Application di JavaFX e gestisce la visualizzazione di un file PLY.
 */

public class PlyFileViewerJava extends Application {
    // Costanti per identificare il tipo di file PLY
    public static final int ASCII = 0;
    public static final int BINARY = 1;
    public static final int INVALID = -1;
    public static final int EXCEPTION = -2;

    // Costanti per la dimensione della scena
    public static final int SCENE_HEIGHT = 600;
    public static final int SCENE_WIDTH = (int) (SCENE_HEIGHT * 1.7);

    // Debug
    public final boolean debug = false;

    // Percorso del file PLY da visualizzare
    public final String filePath = "airplane.ply"; // LowerJawScan.ply = Binario, airplane.ply = ASCII.

//    private Point3D aCenterPoint;
//    private Point3D CameraPosition;

    @Override
    public void start(Stage primaryStage) throws IOException {
        // Creazione di un gruppo per contenere la mesh
        Group root = new Group();
        Scene scene = new Scene(root, SCENE_WIDTH, SCENE_HEIGHT, true);
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
        assert plyReader != null;
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

        // Impostazione della camera
        scene.setCamera(setCameraPosition(meshView));

        // Titolo e scena
        primaryStage.setTitle("PlyFileViewer-Java");
        primaryStage.setScene(scene);
        primaryStage.show();

        // Gestione del mouse
        mouseHandler(meshView, scene);

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
    public Camera setCameraPosition(MeshView mesh){
        Camera camera = new PerspectiveCamera();

        // Reset della camera
        camera.getTransforms().clear();
        camera.setTranslateX(0);
        camera.setTranslateY(0);
        camera.setTranslateZ(0);

        // Calcolo del bounding box della mesh
        Rect3D boundingRect = calculateBoundingBox(mesh);

        // Calcolo del punto centrale del bounding box
        Point3D centerPoint = new Point3D((boundingRect.MinX + boundingRect.MaxX)/ 3.4, (boundingRect.MinY + boundingRect.MaxY) / 3, (boundingRect.MinZ + boundingRect.MaxZ) / 3);
        Point3D cameraPoint = new Point3D(centerPoint.getX(), centerPoint.getY(), boundingRect.MinZ + ((boundingRect.MaxZ-boundingRect.MinZ) * 4));

        // Impostazione del punto centrale e della posizione della camera
//        aCenterPoint = centerPoint;
//        CameraPosition = cameraPoint;

        // Traslazione della camera
        //Translate pivot = new Translate(cameraPoint.getX(), cameraPoint.getY(), cameraPoint.getZ());
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
        camera.setViewOrder(10);

        return camera;
    }

    public void mouseHandler(MeshView meshView, Scene scene){
        // Creo le trasformazioni di rotazione
        Rotate rotateX = new Rotate(0, Rotate.X_AXIS);
        Rotate rotateY = new Rotate(0, Rotate.Y_AXIS);

        // Calcolo il bounding box della mesh
        Bounds boundingRect = meshView.getBoundsInParent();

        // Calcolo il punto centrale del bounding box
        Point3D centerPoint = new Point3D((boundingRect.getMinX() + boundingRect.getMaxX()) / 2,
                (boundingRect.getMinY() + boundingRect.getMaxY()) / 2,
                (boundingRect.getMinZ() + boundingRect.getMaxZ()) / 2);

        // Imposto il centro di rotazione della mesh
        rotateX.setPivotX(centerPoint.getX());
        rotateX.setPivotY(centerPoint.getY());
        rotateX.setPivotZ(centerPoint.getZ());

        rotateY.setPivotX(centerPoint.getX());
        rotateY.setPivotY(centerPoint.getY());
        rotateY.setPivotZ(centerPoint.getZ());

        // Aggiungo le trasformazioni alla mesh
        meshView.getTransforms().addAll(rotateX, rotateY);

        double rotationScale = 0.5; // Fattore di scala per la rotazione

        EventHandler<MouseEvent> mouseHandler = event -> {
            if (event.getEventType() == MouseEvent.MOUSE_DRAGGED) {
                double deltaX = event.getX() - scene.getWidth() / 2;
                double deltaY = event.getY() - scene.getHeight() / 2;

                // Calcola l'angolo della rotazione in base alla posizione del mouse rispetto al centro della scena
                double angleX = deltaY / scene.getHeight() * 360 * rotationScale; // Rotazione lungo l'asse X
                double angleY = deltaX / scene.getWidth() * 360 * rotationScale; // Rotazione lungo l'asse Y

                // Applica la rotazione
                rotateX.setAngle(angleX);
                rotateY.setAngle(angleY);
            }
        };
        scene.setOnMouseDragged(mouseHandler);
    }

    // Calcola il bounding box di una MeshView
    public Rect3D calculateBoundingBox(MeshView mesh){
        //aCenterPoint = new Point3D((boundingBox.MinX+boundingBox.MaxX)/2, (boundingBox.MinY+boundingBox.MaxY)/2, (boundingBox.MinZ+boundingBox.MaxZ)/2);
        return new Rect3D(mesh.getBoundsInParent());
    }

    public static void main(String[] args) {
        launch(args);
    }
}