package plyfileviewer.java;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class PlyReaderAscii extends PlyReader {
    @Override
    public void readPlyFile(String filePath) throws IOException {
        // Utilizza un BufferedReader per leggere il file
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            // Leggi l'intestazione del file
            readHeader(br);
            // Leggi i vertici del file
            readVertices(br);
            // Leggi le facce del file
            readFaces(br);
        }
    }

    private void readHeader(BufferedReader br) throws IOException {
        String line;
        // Continua a leggere le righe fino a quando non trovi "end_header"
        while ((line = br.readLine()) != null) {
            plyContent.add(line);
            if (line.trim().equals("end_header")) {
                break;
            }
        }
    }

    private void readVertices(BufferedReader br) throws IOException {
        String line;
        // Continua a leggere le righe fino a quando non trovi una riga che non contiene esattamente tre numeri
        while ((line = br.readLine()) != null) {
            String[] parts = line.trim().split("\\s+");
            if (parts.length == 3) {
                // Converte i numeri in double e crea un nuovo vertice
                double x = Double.parseDouble(parts[0]);
                double y = Double.parseDouble(parts[1]);
                double z = Double.parseDouble(parts[2]);
                Vertex vertex = new Vertex(x, y, z);
                // Aggiungi il vertice alla lista dei vertici
                vertices.add(vertex);
            } else {
                break;
            }
        }
    }

    private void readFaces(BufferedReader br) throws IOException {
        String line;
        // Continua a leggere le righe fino a quando non trovi una riga che non inizia con il numero 3
        while ((line = br.readLine()) != null) {
            String[] parts = line.trim().split("\\s+");
            if (parts[0].equals("3")) {
                // Crea una nuova faccia con gli indici dei vertici
                int[] indices = new int[]{Integer.parseInt(parts[1]), Integer.parseInt(parts[2]), Integer.parseInt(parts[3])};
                Face face = new Face(indices);
                // Aggiungi la faccia alla lista delle facce
                faces.add(face);
            } else {
                break;
            }
        }
    }
}