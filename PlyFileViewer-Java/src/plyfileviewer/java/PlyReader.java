package plyfileviewer.java;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

abstract class PlyReader {
    protected List<String> plyContent;
    protected List<Vertex> vertices;
    protected List<Face> faces;

    public PlyReader() {
        plyContent = new ArrayList<>();
        vertices = new ArrayList<>();
        faces = new ArrayList<>();
    }

    public abstract void readPlyFile(String filePath) throws IOException;

    public List<String> getPlyContent() {
        return plyContent;
    }

    public List<Vertex> getVertices() {
        return vertices;
    }

    public List<Face> getFaces() {
        return faces;
    }

    public void debugPrintContent() {
        for (String line : plyContent) {
            System.out.println(line);
        }
    }

    public void debugPrintVertices() {
        for (Vertex vertex : vertices) {
            System.out.println("Vertex: X=" + vertex.getX() + " Y=" + vertex.getY() + " Z=" + vertex.getZ());
        }
    }

    public void debugPrintFaces() {
        for (Face face : faces) {
            System.out.println("Face: " + face.getVertexIndices()[0] + " " + face.getVertexIndices()[1] + " " + face.getVertexIndices()[2]);
        }
    }
}