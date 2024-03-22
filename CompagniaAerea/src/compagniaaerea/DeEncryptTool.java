package compagniaaerea;
import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;
import javax.crypto.*;
import javax.crypto.spec.SecretKeySpec;

/**
 *
 * @author joels
 */

// Classe per la crittografia e decrittografia dei file
public class DeEncryptTool {

    // Metodo per criptare un file
    public static void encryptFile(String inputFile, String aesKey) {
        try {
            System.out.println("DET: Criptando il file...");
            // Leggi il contenuto del file
            byte[] fileContent = Files.readAllBytes(Paths.get(inputFile));

            // Crea un cifrario AES
            Cipher cipher = Cipher.getInstance("AES");
            SecretKeySpec secretKey = new SecretKeySpec(aesKey.getBytes(), "AES");
            cipher.init(Cipher.ENCRYPT_MODE, secretKey);

            // Cripta il contenuto del file
            byte[] encryptedContent = cipher.doFinal(fileContent);

            // Sovrascrivi il file originale con il contenuto criptato
            FileOutputStream outputStream = new FileOutputStream(inputFile);
            outputStream.write(encryptedContent);
            outputStream.close();

            System.out.println("DET: File criptato con successo.");
        } catch (Exception e) {
            System.err.println("DET: Errore durante la criptazione del file: " + e.getMessage());
        }
    }

    public static void decryptFile(String inputFile, String aesKey) {
        try {
            System.out.println("DET: Decriptando il file...");
            // Leggi il contenuto del file criptato
            byte[] encryptedContent = Files.readAllBytes(Paths.get(inputFile));

            // Crea un cifrario AES
            Cipher cipher = Cipher.getInstance("AES");
            SecretKeySpec secretKey = new SecretKeySpec(aesKey.getBytes(), "AES");
            cipher.init(Cipher.DECRYPT_MODE, secretKey);

            // Decripta il contenuto del file
            byte[] decryptedContent = cipher.doFinal(encryptedContent);

            // Rimuovi il padding
            decryptedContent = removePadding(decryptedContent);

            // Sovrascrivi il file criptato con il contenuto decriptato
            FileOutputStream outputStream = new FileOutputStream(inputFile);
            outputStream.write(decryptedContent);
            outputStream.close();

            System.out.println("DET: File decriptato con successo.");
        } catch (Exception e) {
            System.err.println("DET: Errore durante la decriptazione del file: " + e.getMessage());
        }
    }

    // Metodo per rimuovere il padding dopo la decriptazione
    private static byte[] removePadding(byte[] decryptedContent) {
        int padLength = decryptedContent[decryptedContent.length - 1];
        return Arrays.copyOfRange(decryptedContent, 0, decryptedContent.length - padLength);
    }

}




