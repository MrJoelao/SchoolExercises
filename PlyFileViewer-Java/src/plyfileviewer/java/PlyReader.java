package plyfileviewer.java;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

// Classe astratta PlyReader
abstract class PlyReader {
    protected List<String> plyContent;

    public PlyReader() {
        plyContent = new ArrayList<>();
    }

    // Metodo astratto che deve essere implementato nelle sottoclassi
    public abstract void readPlyFile(String filePath) throws IOException;

    // Metodo comune per ottenere il contenuto del file
    public List<String> getPlyContent() {
        return plyContent;
    }
}