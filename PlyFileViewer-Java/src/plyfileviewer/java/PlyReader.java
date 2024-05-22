package plyfileviewer.java;

import java.io.IOException;
import java.util.List;

// Classe astratta PlyReader
public abstract class PlyReader {
    protected List<String> plyContent;

    // Metodo astratto per ottenere il contenuto del file PLY
    public abstract List<String> getPlyContent();
}