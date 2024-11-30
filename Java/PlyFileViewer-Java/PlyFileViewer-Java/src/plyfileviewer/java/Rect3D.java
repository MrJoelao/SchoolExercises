package plyfileviewer.java;

import javafx.geometry.Bounds;
import java.util.ArrayList;

public class Rect3D {
    public double MinX, MinY, MinZ, MaxX, MaxY, MaxZ;

    // Costruttore con parametri specifici
    public Rect3D(double minX, double minY, double minZ, double maxX, double maxY, double maxZ) {
        MinX = minX;
        MinY = minY;
        MinZ = minZ;
        MaxX = maxX;
        MaxY = maxY;
        MaxZ = maxZ;
    }

    // Costruttore senza parametri
    public Rect3D() {
        MinX = 0;
        MinY = 0;
        MinZ = 0;
        MaxX = 0;
        MaxY = 0;
        MaxZ = 0;
    }

    // Costruttore con un ArrayList di Bounds
    public Rect3D(ArrayList<Bounds> B) {
        MinX = Double.MAX_VALUE;
        MinY = Double.MAX_VALUE;
        MinZ = Double.MAX_VALUE;
        MaxX = Double.MIN_VALUE;
        MaxY = Double.MIN_VALUE;
        MaxZ = Double.MIN_VALUE;

        // Calcola i valori minimo e massimo per ogni asse
        for (Bounds b : B) {
            MinX = Math.min(MinX, b.getMinX());
            MinY = Math.min(MinY, b.getMinY());
            MinZ = Math.min(MinZ, b.getMinZ());
            MaxX = Math.max(MaxX, b.getMaxX());
            MaxY = Math.max(MaxY, b.getMaxY());
            MaxZ = Math.max(MaxZ, b.getMaxZ());
        }
    }

    // Costruttore con un singolo Bounds
    public Rect3D(Bounds b) {
        MinX = 0;
        MinY = 0;
        MinZ = 0;
        MaxX = 0;
        MaxY = 0;
        MaxZ = 0;

        // Calcola i valori minimo e massimo per ogni asse
        MinX = Math.min(MinX, b.getMinX());
        MinY = Math.min(MinY, b.getMinY());
        MinZ = Math.min(MinZ, b.getMinZ());
        MaxX = Math.max(MaxX, b.getMaxX());
        MaxY = Math.max(MaxY, b.getMaxY());
        MaxZ = Math.max(MaxZ, b.getMaxZ());
    }
}