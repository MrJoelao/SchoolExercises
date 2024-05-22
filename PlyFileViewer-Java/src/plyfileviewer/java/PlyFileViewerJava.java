package plyfileviewer.java;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.PerspectiveCamera;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.scene.paint.PhongMaterial;
import javafx.scene.shape.DrawMode;
import javafx.scene.shape.MeshView;
import javafx.scene.shape.TriangleMesh;
import javafx.stage.Stage;
import java.io.IOException;
import java.util.List;
import javafx.scene.AmbientLight;
import javafx.scene.PointLight;
import javafx.scene.transform.Rotate;


/**
 *
 * @author joels
 */
public class PlyFileViewerJava extends Application {
    public static final int ASCII = 0;
    public static final int BINARY = 1;
    public static final int INVALID = -1;
    public static final int EXCEPTION = -2;

    private String filePath = "airplane.ply";

    @Override
    public void start(Stage primaryStage) throws IOException {

        // Creazione di un gruppo per contenere la mesh
        Group root = new Group();
        Scene scene = new Scene(root, 800, 600, true);
        scene.setFill(Color.LIGHTBLUE);


        PlyReader plyReader = null;
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

        // Stampa il numero di vertici e facce letti
        System.out.println("Number of vertices: " + plyReader.getVertices().size());
        System.out.println("Number of faces: " + plyReader.getFaces().size());

        plyReader.debugPrintContent();
        plyReader.debugPrintVertices();
        plyReader.debugPrintFaces();

        primaryStage.setTitle("PlyFileViewer-Java");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
