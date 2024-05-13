package plyfileviewer.java;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class PlyReaderBin {
    

    public PlyReaderBin(String filePath) {
        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                byte[] bytes = line.getBytes();
                StringBuilder binaryStringBuilder = new StringBuilder();
                if (line.startsWith("ply") || line.startsWith("format") || line.startsWith("element")
                        || line.startsWith("property") || line.startsWith("end_header")) {
                    System.out.println(line);
                } else if (!line.startsWith("comment")) {

                    // Converte ogni byte in una rappresentazione binaria e lo concatena
                    for (byte b : bytes) {
                        // Utilizza il metodo Integer.toBinaryString per convertire il byte in una
                        // stringa binaria
                        // Assicurati di trattare i byte come numeri non firmati per ottenere la
                        // rappresentazione corretta
                        String binary = Integer.toBinaryString(b & 0xFF); // Maschera per convertire byte non firmati
                        // Aggiungi zeri iniziali se la rappresentazione binaria è inferiore a 8 bit
                        while (binary.length() < 8) {
                            binary = "0" + binary;
                        }
                        // Aggiungi la rappresentazione binaria al StringBuilder
                        binaryStringBuilder.append(binary).append(" ");
                    }
                }
                System.out.println(binaryStringBuilder.toString());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}