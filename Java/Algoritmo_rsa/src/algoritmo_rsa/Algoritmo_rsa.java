/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package algoritmo_rsa;

import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author joelao
 */
public class Algoritmo_rsa {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        try {
            System.out.println("=== Dimostrazione Algoritmo RSA ===\n");
            
            GestoreRSA gestore = new GestoreRSA();
            System.out.println("1. GENERAZIONE DELLE CHIAVI");
            System.out.println("---------------------------");
            gestore.generaChiavi();
            
            System.out.println("\n2. CRITTOGRAFIA");
            System.out.println("---------------");
            System.out.println("Inserisci un messaggio breve da crittografare:");
            String messaggio = scanner.nextLine();
            
            BigInteger messaggioCrittografato = gestore.crittografa(messaggio);
            System.out.println("Messaggio crittografato: " + messaggioCrittografato);
            
            System.out.println("\n3. DECRITTOGRAFIA");
            System.out.println("----------------");
            String messaggioDecrittografato = gestore.decrittografa(messaggioCrittografato);
            System.out.println("Messaggio decrittografato: " + messaggioDecrittografato);
            
        } catch (Exception e) {
            System.err.println("Errore: " + e.getMessage());
        } finally {
            scanner.close();
        }
    }
    
}
