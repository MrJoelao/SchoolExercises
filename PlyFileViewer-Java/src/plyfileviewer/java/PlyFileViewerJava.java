package plyfileviewer.java;

import javafx.application.Application;
import javafx.geometry.Bounds;
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
import java.util.ArrayList;

import javafx.scene.transform.Rotate;
import javafx.scene.PerspectiveCamera;
import javafx.scene.transform.Translate;
import javafx.geometry.Point3D;

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
    Point3D aCenterPoint;

    // Percorso del file PLY da visualizzare
    private String filePath = "LowerJawScan.ply"; // LowerJawScan.ply = Binario, airplane.ply = ASCII.

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
                System.out.println("The file is in ASCII format");
                plyReader = new PlyReaderAscii();
                plyReader.readPlyFile(filePath);
                break;
            case BINARY:
                System.out.println("The file is in binary format");
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
            System.out.println("Vertex: X=" + vertex.getX() + " Y=" + vertex.getY() + " Z=" + vertex.getZ());
        }

        // Aggiunta delle facce al mesh
        for (Face face : plyReader.getFaces()) {
            int[] vertexIndices = face.getVertexIndices();
            mesh.getFaces().addAll(vertexIndices[0], 0, vertexIndices[1], 0, vertexIndices[2], 0);
            System.out.println("Face: " + vertexIndices[0] + " " + vertexIndices[1] + " " + vertexIndices[2]);
        }


        mesh.getTexCoords().addAll(0,0);

        // Creazione della vista della mesh
        MeshView meshView = new MeshView(mesh);
        meshView.setDrawMode(DrawMode.FILL);
        meshView.setMaterial(new PhongMaterial(Color.RED));
        root.getChildren().add(meshView);

        //Camera
        camera = new PerspectiveCamera(true);
        setCameraPosition(meshView);

        // Titolo e scena
        primaryStage.setTitle("PlyFileViewer-Java");
        primaryStage.setScene(scene);
        primaryStage.show();

        // Stampa di debug
        System.out.println("Number of vertices: " + plyReader.getVertices().size());
        System.out.println("Number of faces: " + plyReader.getFaces().size());
        plyReader.debugPrintContent();
        scene.setCamera(camera);
        /*plyReader.debugPrintVertices();
        plyReader.debugPrintFaces();*/
    }
    public Point3D CameraPosition;
    public Camera camera;

    public static void main(String[] args) {
        launch(args);
    }

    public void setCameraPosition(MeshView m){
        camera = new PerspectiveCamera();

        camera.getTransforms().clear();

        camera.setTranslateX(0);

        camera.setTranslateY(0);

        camera.setTranslateZ(0);

        Rect3D R = getRect3D(m);

        Point3D PC = new Point3D((R.MinX+R.MaxX)/2, (R.MinY + R.MaxY) / 2, (R.MinZ + R.MaxZ)/2);

        Point3D PP = new Point3D(PC.getX(), PC.getY(), R.MinZ + ((R.MaxZ-R.MinZ)* 4));

        aCenterPoint = PC;

        CameraPosition = PP;

        Translate pivot = new Translate(PP.getX(),PP.getY(),PP.getZ());

        camera.translateXProperty().set(PP.getX());

        camera.translateYProperty().set(PP.getY());

        camera.translateZProperty().set(PP.getZ());

        Rotate RRR = new Rotate();

        RRR.setAxis(Rotate.Y_AXIS);

        RRR.setPivotX(PP.getX());

        RRR.setPivotY(PP.getY());

        RRR.setPivotZ(PP.getZ());

        RRR.setAngle(180);

        camera.getTransforms().add(RRR);

        camera.setNearClip(0.125f);

        camera.setFarClip(100000f);

        AmbientLight ambientLight = new AmbientLight();

        ambientLight.setColor(Color.CORAL);

        camera.setViewOrder(10);

    }

    public Rect3D getRect3D (MeshView m){

        Rect3D R = new Rect3D(m.getBoundsInParent());

        aCenterPoint = new Point3D((R.MinX+R.MaxX)/2, (R.MinY+R.MaxY)/2, (R.MinZ+R.MaxZ)/2);

        return R;
    }
}