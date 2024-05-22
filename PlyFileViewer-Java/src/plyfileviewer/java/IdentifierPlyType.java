package plyfileviewer.java;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class IdentifierPlyType {
    public static final int ASCII = 0; // Costante per gestire i file ASCII
    public static final int BINARY = 1; // Costante per gestire i file binari
    public static final int INVALID = -1; // Costante per gestire i file non validi
    public static final int EXCEPTION = -2; // Costante per gestire le eccezioni

    // Metodo per identificare il tipo di file PLY (ASCII o binario)
    public static int identifyPlyType(String filePath) {
        try {
            BufferedReader reader = new BufferedReader(new FileReader(filePath)); // Apriamo il file in lettura
            String firstLine = reader.readLine(); // Leggiamo la prima riga
            reader.close(); // Chiudiamo il BufferedReader

            if (firstLine != null && firstLine.trim().equalsIgnoreCase("ply")) {
                BufferedReader secondLineReader = new BufferedReader(new FileReader(filePath)); // Riapriamo il file
                secondLineReader.readLine(); // Saltiamo la prima riga
                String secondLine = secondLineReader.readLine(); // Leggiamo la seconda riga
                secondLineReader.close(); // Chiudiamo il BufferedReader

                if (secondLine != null && secondLine.trim().equalsIgnoreCase("format ascii")) {
                    return ASCII; // Il file è nel formato ASCII
                } else {
                    return BINARY; // Il file è nel formato binario
                }
            } else {
                return INVALID; // Il file non è un file PLY valido
            }
        } catch (IOException e) {
            System.err.println("Exception: " + e.getMessage());
            return EXCEPTION; // Gestione dell'eccezione
        }
    }
}

