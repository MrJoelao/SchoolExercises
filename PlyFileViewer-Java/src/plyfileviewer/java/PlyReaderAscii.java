package plyfileviewer.java;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class PlyReaderAscii {


    public PlyReaderAscii(String filePath) {
        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                byte[] bytes = line.getBytes();
                if (line.startsWith("ply") || line.startsWith("format") || line.startsWith("element")
                        || line.startsWith("property") || line.startsWith("end_header")) {
                    System.out.println(line);
                } else if (!line.startsWith("comment")) {
                    // Converte ogni byte in una rappresentazione ASCII
                    for (byte b : bytes) {
                        System.out.print(b + "\n");
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
