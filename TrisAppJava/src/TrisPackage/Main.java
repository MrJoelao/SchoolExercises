/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package TrisPackage;
/*
import java.util.Scanner;
*/
/**
 *
 * @author ricpi
 */
/*
public class Main {
    public static void main(String[] args) {
        TrisMinimax trisGame = new TrisMinimax();
        trisGame.initializeBoard();
        trisGame.printBoard();

        // Esempio di gioco alternato tra giocatore e computer
        while (trisGame.checkWinner() == TrisMinimax.EMPTY) {
            // Turno del giocatore
            int row, column;
            do {
                System.out.println("Giocatore X, inserisci la tua mossa (riga e colonna separate da uno spazio):");
                row = getPlayerInput("Riga: ");
                column = getPlayerInput("Colonna: ");
            } while (!trisGame.playerMove(row, column));

            trisGame.printBoard();
            
            // Controlla se il giocatore ha vinto
            char winner = trisGame.checkWinner();
            if (winner != TrisMinimax.EMPTY) {
                printResult(winner);
                break;
            }

            // Turno del computer
            int[] computerMove = trisGame.computerMove();
            System.out.println("Il computer ha giocato in riga: " + computerMove[0] + ", colonna: " + computerMove[1]);
            trisGame.printBoard();

            // Controlla se il computer ha vinto
            winner = trisGame.checkWinner();
            if (winner != TrisMinimax.EMPTY) {
                printResult(winner);
                break;
            }
        }
    }

    // Metodo di utilità per ottenere l'input del giocatore
    private static int getPlayerInput(String prompt) {
        Scanner scanner = new Scanner(System.in);
        System.out.print(prompt);
        return scanner.nextInt();
    }

    // Metodo di utilità per stampare il risultato del gioco
    private static void printResult(char winner) {
        if (winner == TrisMinimax.PLAYER_X) {
            System.out.println("Il giocatore X ha vinto!");
        } else if (winner == TrisMinimax.PLAYER_O) {
            System.out.println("Il computer ha vinto!");
        } else {
            System.out.println("La partita è finita in pareggio.");
        }
    }
}
*/
