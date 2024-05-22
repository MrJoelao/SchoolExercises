package plyfileviewer.java;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class IdentifierPlyType {
    public static final int ASCII = 0; // Costante per gestire i file ASCII
    public static final int BINARY = 1; // Costante per gestire i file binari
    public static final int INVALID = -1; // Costante per gestire i file non validi
    public static final int EXCEPTION = -2; // Costante per gestire le eccezioni

    // Metodo per identificare il tipo di file PLY (ASCII o binario)
    public static int identifyPlyType(String filePath) {
        try {
            FileInputStream fileInputStream = new FileInputStream(filePath);
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(fileInputStream));

            // Leggiamo le prime righe del file per determinare il tipo
            String line;
            int lineCount = 0;
            boolean asciiHeaderFound = false;
            while ((line = bufferedReader.readLine()) != null && lineCount < 10) { // Leggiamo solo le prime 10 righe
                if (line.contains("binary")) {
                    return BINARY;
                } else if (line.contains("element") || line.contains("property")) {
                    asciiHeaderFound = true;
                }
                lineCount++;
            }

            // Se non abbiamo trovato "binary" nel file, ma abbiamo trovato parti del header ASCII, è ASCII
            if (asciiHeaderFound) {
                return ASCII;
            } else {
                return INVALID; // Se non corrisponde a nessuno dei due, è un file non valido
            }
        } catch (IOException e) {
            e.printStackTrace();
            return EXCEPTION; // Gestione dell'eccezione
        }
    }
}

