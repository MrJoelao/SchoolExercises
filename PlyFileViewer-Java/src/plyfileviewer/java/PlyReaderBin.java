package plyfileviewer.java;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class PlyReaderBin {

    private List<String> plyContent;

    public PlyReaderBin(String filePath) {
        plyContent = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                byte[] bytes = line.getBytes();
                StringBuilder binaryStringBuilder = new StringBuilder();
                if (line.startsWith("ply") || line.startsWith("format") || line.startsWith("element")
                        || line.startsWith("property") || line.startsWith("end_header")) {
                    plyContent.add(line);
                } else if (!line.startsWith("comment")) {

                    // Converte ogni byte in una rappresentazione binaria e lo concatena
                    for (byte b : bytes) {
                        // Utilizzo il metodo Integer.toBinaryString per convertire il byte in una stringa binaria
                        String binary = Integer.toBinaryString(b & 0xFF); // Maschera per convertire byte non firmati
                        // Aggiungi zeri iniziali se la rappresentazione binaria è inferiore a 8 bit
                        while (binary.length() < 8) {
                            binary = "0" + binary;
                        }
                        // Aggiungi la rappresentazione binaria al StringBuilder
                        binaryStringBuilder.append(binary).append(" ");
                    }
                    plyContent.add(binaryStringBuilder.toString());
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public List<String> getPlyContent() {
        return plyContent;
    }
}