package plyfileviewer.java;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

// Classe per leggere file PLY in formato binario
class PlyReaderBin extends PlyReader {

    @Override
    public void readPlyFile(String filePath) throws IOException {
        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                byte[] bytes = line.getBytes();
                StringBuilder binaryStringBuilder = new StringBuilder();
                if (line.startsWith("ply") || line.startsWith("format") || line.startsWith("element")
                        || line.startsWith("property") || line.startsWith("end_header")) {
                    plyContent.add(line);
                } else if (!line.startsWith("comment")) {
                    for (byte b : bytes) {
                        String binary = Integer.toBinaryString(b & 0xFF);
                        while (binary.length() < 8) {
                            binary = "0" + binary;
                        }
                        binaryStringBuilder.append(binary).append(" ");
                    }
                    plyContent.add(binaryStringBuilder.toString());
                }
            }
        }
    }
}