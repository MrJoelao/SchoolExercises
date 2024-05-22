package plyfileviewer.java;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

// Classe per leggere file PLY in formato ASCII
class PlyReaderAscii extends PlyReader {

    @Override
    public void readPlyFile(String filePath) throws IOException {
        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                plyContent.add(line);
            }
        }
    }
}