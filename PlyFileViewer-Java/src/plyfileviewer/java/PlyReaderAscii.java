package plyfileviewer.java;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

class PlyReaderAscii extends PlyReader {

    @Override
    public void readPlyFile(String filePath) throws IOException {
        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            String line;
            boolean headerEnded = false;
            while ((line = reader.readLine()) != null) {
                plyContent.add(line);
                if (headerEnded) {
                    // Process the vertex and face lines
                    String[] parts = line.trim().split("\\s+");
                    if (parts.length == 3) { // Assuming a line with 3 parts is a vertex
                        double x = Double.parseDouble(parts[0]);
                        double y = Double.parseDouble(parts[1]);
                        double z = Double.parseDouble(parts[2]);
                        vertices.add(new Vertex(x, y, z));
                    } else if (parts.length > 3) { // Assuming a line with more than 3 parts is a face
                        int numVertices = Integer.parseInt(parts[0]);
                        int[] vertexIndices = new int[numVertices];
                        for (int i = 0; i < numVertices; i++) {
                            vertexIndices[i] = Integer.parseInt(parts[i + 1]);
                        }
                        faces.add(new Face(vertexIndices));
                    }
                }
                if (line.trim().equals("end_header")) {
                    headerEnded = true;
                }
            }
        }
    }
}
