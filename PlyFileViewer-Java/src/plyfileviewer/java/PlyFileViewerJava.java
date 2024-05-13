package plyfileviewer.java;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.PerspectiveCamera;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

/**
 *
 * @author joels
 */
public class PlyFileViewerJava extends Application {

    @Override
    public void start(Stage primaryStage) {
        Group root = new Group();
        Scene scene = new Scene(root, 800, 600, Color.WHITE);
        PerspectiveCamera camera = new PerspectiveCamera(true);
        scene.setCamera(camera);

        // Logica per la visualizazione del file

        primaryStage.setTitle("Visualizzazione File .ply");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
