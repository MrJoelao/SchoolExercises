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
    public void readPlyFile(String filePath) throws IOException{
        try (BufferedInputStream bis = new BufferedInputStream(new FileInputStream(filePath))) {
            List<String> header = new ArrayList<>();
            StringBuilder lineBuilder = new StringBuilder();
            int b;

            // Leggi l'intestazione
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

            // Analizza l'intestazione per ottenere il numero di vertici e facce
            int vertexCount = 0;
            int faceCount = 0;
            boolean littleEndian = false;

            for (String line : header) {
                if (line.startsWith("element vertex")) {
                    vertexCount = Integer.parseInt(line.split(" ")[2]);
                } else if (line.startsWith("element face")) {
                    faceCount = Integer.parseInt(line.split(" ")[2]);
                } else if (line.startsWith("format binary_little_endian")) {
                    littleEndian = true;
                } else if (line.startsWith("format binary_big_endian")) {
                    littleEndian = false;
                }
            }

            ByteOrder byteOrder = littleEndian ? ByteOrder.LITTLE_ENDIAN : ByteOrder.BIG_ENDIAN;

            // Leggi i vertici
            for (int i = 0; i < vertexCount; i++) {
                byte[] vertexBytes = new byte[12]; // 3 float (x, y, z) * 4 bytes per float
                bis.read(vertexBytes);
                ByteBuffer buffer = ByteBuffer.wrap(vertexBytes).order(byteOrder);
                float x = buffer.getFloat();
                float y = buffer.getFloat();
                float z = buffer.getFloat();
                vertices.add(new Vertex(x, y, z));
            }

            // Leggi le facce
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
}
