package plyfileviewer.java;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class PlyReaderAscii extends PlyReader {


    @Override
    public void readPlyFile(String filePath) throws IOException {
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            // Read header
            readHeader(br);

            // Read vertex data
            readVertices(br);

            // Read face data
            readFaces(br);
        }
    }

    private void readHeader(BufferedReader br) throws IOException {
        String line;
        while ((line = br.readLine()) != null) {
            if (line.trim().equals("end_header")) {
                break; // Header ended
            }
            plyContent.add(line); // Store the header line
        }
    }

    private void readVertices(BufferedReader br) throws IOException {
        String line;
        while ((line = br.readLine()) != null) {
            line = line.trim();
            if (line.isEmpty() || line.equals("end_header")) {
                break; // End of vertices section
            }
            String[] parts = line.split("\\s+");
            double x = Double.parseDouble(parts[0]);
            double y = Double.parseDouble(parts[1]);
            double z = Double.parseDouble(parts[2]);
            Vertex vertex = new Vertex(x, y, z);
            vertices.add(vertex);
            plyContent.add(line); // Store the vertex line
        }
    }

    private void readFaces(BufferedReader br) throws IOException {
        String line;
        while ((line = br.readLine()) != null) {
            line = line.trim();
            if (line.isEmpty()) {
                continue; // Skip empty lines
            }
            String[] parts = line.split("\\s+");
            if (parts[0].equals("3")) {
                // Face data
                int[] indices = new int[]{Integer.parseInt(parts[1]), Integer.parseInt(parts[2]), Integer.parseInt(parts[3])};
                Face face = new Face(indices);
                faces.add(face);
                plyContent.add(line); // Store the face line
            }
        }
    }
}
