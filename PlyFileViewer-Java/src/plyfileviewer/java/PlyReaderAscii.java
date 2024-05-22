package plyfileviewer.java;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class PlyReaderAscii {

    private List<String> plyContent;

    public PlyReaderAscii(String filePath) {
        plyContent = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                plyContent.add(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public List<String> getPlyContent() {
        return plyContent;
    }
}