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
}