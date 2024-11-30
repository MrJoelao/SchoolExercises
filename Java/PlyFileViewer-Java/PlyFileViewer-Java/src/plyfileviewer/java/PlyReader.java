package plyfileviewer.java;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;

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
            int[] vertexIndices = face.getVertexIndices();
            if (vertexIndices.length >= 3) {
                System.out.println("Face: " + vertexIndices[0] + " " + vertexIndices[1] + " " + vertexIndices[2]);
            } else {
                System.out.println("Face has less than 3 vertices. Indices: " + Arrays.toString(vertexIndices));
            }
        }
    }
}