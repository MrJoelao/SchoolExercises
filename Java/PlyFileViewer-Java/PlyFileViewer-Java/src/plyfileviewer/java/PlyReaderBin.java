package plyfileviewer.java;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.util.ArrayList;
import java.util.List;

class PlyReaderBin extends PlyReader {

    @Override
    public void readPlyFile(String filePath) throws IOException {
        // Utilizza un BufferedInputStream per leggere il file
        try (BufferedInputStream bis = new BufferedInputStream(new FileInputStream(filePath))) {
            // Leggi l'intestazione del file
            List<String> header = readHeader(bis);
            // Ottieni il numero di vertici e facce dal file
            int[] counts = getCounts(header);
            // Controlla se il file è in formato little endian o big endian
            boolean littleEndian = isLittleEndian(header);

            ByteOrder byteOrder = littleEndian ? ByteOrder.LITTLE_ENDIAN : ByteOrder.BIG_ENDIAN;

            // Leggi i vertici e le facce del file
            readVertices(bis, counts[0], byteOrder);
            readFaces(bis, counts[1], byteOrder);
        }
    }

    private List<String> readHeader(BufferedInputStream bis) throws IOException {
        List<String> header = new ArrayList<>();
        StringBuilder lineBuilder = new StringBuilder();
        int b;

        // Leggi l'intestazione del file fino a quando non trovi "end_header"
        while ((b = bis.read()) != -1) {
            if (b == '\n') {
                String line = lineBuilder.toString();
                header.add(line);
                plyContent.add(line);
                if (line.trim().equals("end_header")) {
                    break;
                }
                lineBuilder.setLength(0);
            } else {
                lineBuilder.append((char) b);
            }
        }

        return header;
    }

    private int[] getCounts(List<String> header) {
        int vertexCount = 0;
        int faceCount = 0;

        // Ottieni il numero di vertici e facce dal file
        for (String line : header) {
            if (line.startsWith("element vertex")) {
                vertexCount = Integer.parseInt(line.split(" ")[2]);
            } else if (line.startsWith("element face")) {
                faceCount = Integer.parseInt(line.split(" ")[2]);
            }
        }

        return new int[]{vertexCount, faceCount};
    }

    private boolean isLittleEndian(List<String> header) {
        // Controlla se il file è in formato little endian o big endian
        for (String line : header) {
            if (line.startsWith("format binary_little_endian")) {
                return true;
            } else if (line.startsWith("format binary_big_endian")) {
                return false;
            }
        }
        // Se il formato non è specificato, metti come default little endian
        return true;
    }

    private void readVertices(BufferedInputStream bis, int vertexCount, ByteOrder byteOrder) throws IOException {
        // Leggi i vertici del file
        for (int i = 0; i < vertexCount; i++) {
            byte[] vertexBytes = new byte[12]; // 3 float per vertice * 4 bytes per float
            bis.read(vertexBytes);
            ByteBuffer buffer = ByteBuffer.wrap(vertexBytes).order(byteOrder);
            float x = buffer.getFloat();
            float y = buffer.getFloat();
            float z = buffer.getFloat();
            vertices.add(new Vertex(x, y, z));
        }
    }

    private void readFaces(BufferedInputStream bis, int faceCount, ByteOrder byteOrder) throws IOException {
        // Leggi le facce del file
        for (int i = 0; i < faceCount; i++) {
            int vertexPerFace = bis.read(); // Leggi il numero di vertici per faccia
            byte[] faceBytes = new byte[vertexPerFace * 4]; // Ogni indice di vertice è un int (4 bytes)
            bis.read(faceBytes);
            ByteBuffer buffer = ByteBuffer.wrap(faceBytes).order(byteOrder);
            int[] vertexIndices = new int[vertexPerFace];
            for (int j = 0; j < vertexPerFace; j++) {
                vertexIndices[j] = buffer.getInt();
            }
            faces.add(new Face(vertexIndices));
        }
    }
}