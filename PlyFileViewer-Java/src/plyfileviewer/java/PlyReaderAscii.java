package plyfileviewer.java;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class PlyReaderAscii extends PlyReader {
    @Override
    public void readPlyFile(String filePath) throws IOException {
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            readHeader(br);
            readVertices(br);
            readFaces(br);
        }
    }

    private void readHeader(BufferedReader br) throws IOException {
        String line;
        while ((line = br.readLine()) != null) {
            plyContent.add(line);
            if (line.trim().equals("end_header")) {
                break;
            }
        }
    }

    private void readVertices(BufferedReader br) throws IOException {
        String line;
        while ((line = br.readLine()) != null) {
            String[] parts = line.trim().split("\\s+");
            if (parts.length == 3) {
                double x = Double.parseDouble(parts[0]);
                double y = Double.parseDouble(parts[1]);
                double z = Double.parseDouble(parts[2]);
                Vertex vertex = new Vertex(x, y, z);
                vertices.add(vertex);
            } else {
                break;
            }
        }
    }

    private void readFaces(BufferedReader br) throws IOException {
        String line;
        while ((line = br.readLine()) != null) {
            String[] parts = line.trim().split("\\s+");
            if (parts[0].equals("3")) {
                int[] indices = new int[]{Integer.parseInt(parts[1]), Integer.parseInt(parts[2]), Integer.parseInt(parts[3])};
                Face face = new Face(indices);
                faces.add(face);
            } else {
                break;
            }
        }
    }
}