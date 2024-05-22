package plyfileviewer.java;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.scene.paint.PhongMaterial;
import javafx.scene.shape.DrawMode;
import javafx.scene.shape.MeshView;
import javafx.scene.shape.TriangleMesh;
import javafx.stage.Stage;
import java.io.IOException;
import javafx.scene.AmbientLight;
import javafx.scene.PointLight;
import javafx.scene.transform.Rotate;

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

    // Percorso del file PLY da visualizzare
    private String filePath = "airplane.ply";

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
        TriangleMesh mesh = new TriangleMesh();
        plyReader.getVertices().forEach(vertex -> mesh.getPoints().addAll((float) vertex.getX(), (float) vertex.getY(), (float) vertex.getZ()));
        plyReader.getFaces().forEach(face -> mesh.getFaces().addAll(face.getVertexIndices()));

        // Creazione della vista della mesh
        MeshView meshView = new MeshView(mesh);
        meshView.setDrawMode(DrawMode.FILL);
        meshView.setMaterial(new PhongMaterial(Color.RED));
        meshView.setTranslateX(400);
        meshView.setTranslateY(300);
        meshView.setTranslateZ(0);
        meshView.setRotationAxis(Rotate.Y_AXIS);
        meshView.setRotate(180);
        root.getChildren().add(meshView);

        // Creazione delle luci
        PointLight pointLight = new PointLight();
        pointLight.setColor(Color.WHITE);
        pointLight.setTranslateX(800);
        pointLight.setTranslateY(0);
        pointLight.setTranslateZ(-1000);
        root.getChildren().addAll(new AmbientLight(Color.WHITE), pointLight);

        // Impostazione del titolo e della scena del palcoscenico
        primaryStage.setTitle("PlyFileViewer-Java");
        primaryStage.setScene(scene);
        primaryStage.show();

        // Stampa di debug
        System.out.println("Number of vertices: " + plyReader.getVertices().size());
        System.out.println("Number of faces: " + plyReader.getFaces().size());
        plyReader.debugPrintContent();
        plyReader.debugPrintVertices();
        plyReader.debugPrintFaces();
    }

    public static void main(String[] args) {
        launch(args);
    }
}