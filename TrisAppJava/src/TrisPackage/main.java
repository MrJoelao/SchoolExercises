/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package TrisPackage;

/**
 *
 * @author joels,ricpi,NicMuso,AlePini
 */
import java.util.Scanner;

public class main {
    public static void main(String[] args) {
        TrisClass trisGame = new TrisClass();
        Scanner scanner = new Scanner(System.in);

        // Simulazione di un gioco del Tris da terminale
        while (!trisGame.checkWinner()) {
            // Stampa la griglia di gioco
            stampaGriglia(trisGame);

            // Richiedi le coordinate del movimento
            System.out.println("Giocatore " + trisGame.getGiocatore_corrente() + ", inserisci la tua mossa (riga colonna): ");
            int riga = scanner.nextInt();
            int colonna = scanner.nextInt();

            // Esegui il movimento
            if (trisGame.Muovi(riga, colonna)>=0) {
                System.out.println("Mossa valida.");
            } else {
                System.out.println("Mossa non valida, riprova.");
            }
        }

        // Una volta che c'è un vincitore, stampa la griglia di gioco finale
        stampaGriglia(trisGame);
        char vincitore = trisGame.getGiocatore_corrente() == 'X' ? 'O' : 'X';
        System.out.println("Il giocatore " + vincitore + " ha vinto!");

        scanner.close();
    }

    // Metodo per stampare la griglia di gioco
    public static void stampaGriglia(TrisClass trisGame) {
        char[][] tabella = trisGame.getTabella();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(tabella[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }
}
