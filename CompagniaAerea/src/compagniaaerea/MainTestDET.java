package compagniaaerea;

/**
 *
 * @author joels
 */

public class MainTestDET {
    public static void main(String[] args) {
        // Percorso del file da criptare/decryptare
        String inputFile = "credentials.txt";

        // Cripta il file 
        System.out.println("Criptazione del file...");
        DeEncryptTool.encryptFile(inputFile, "@!&eaDoV7WhQfQGm");

        // Decripta il file
        //System.out.println("Decriptazione del file...");
        //DeEncryptTool.decryptFile(inputFile, "@!&eaDoV7WhQfQGm";
    }
}

