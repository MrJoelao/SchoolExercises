/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
import java.util.Scanner;

public class TrisMinimax {
    private static final char EMPTY = '-';
    private static final char PLAYER_X = 'X';
    private static final char PLAYER_O = 'O';
    private static final int BOARD_SIZE = 3;

    private static char[][] board = new char[BOARD_SIZE][BOARD_SIZE];
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        inizializzaTabellone();
        stampaTabellone();

        while (!giocoFinito()) {
            mossaGiocatore();
            if (giocoFinito()) break;
            mossaComputer();
            stampaTabellone();
        }

        char vincitore = determinaVincitore();
        if (vincitore != EMPTY) {
            System.out.println("Il vincitore è: " + vincitore);
        } else {
            System.out.println("La partita è finita in pareggio.");
        }
    }

    private static void inizializzaTabellone() {
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                board[i][j] = EMPTY;
            }
        }
    }

    private static void stampaTabellone() {
        System.out.println("-------------");
        for (int i = 0; i < BOARD_SIZE; i++) {
            System.out.print("| ");
            for (int j = 0; j < BOARD_SIZE; j++) {
                System.out.print(board[i][j] + " | ");
            }
            System.out.println();
            System.out.println("-------------");
        }
    }

    private static boolean giocoFinito() {
        return determinaVincitore() != EMPTY || tabellonePieno();
    }

    private static boolean tabellonePieno() {
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == EMPTY) {
                    return false;
                }
            }
        }
        return true;
    }

    private static char determinaVincitore() {
        for (int i = 0; i < BOARD_SIZE; i++) {
            // Controlla le righe
            if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
                return board[i][0];
            }
            // Controlla le colonne
            if (board[0][i] != EMPTY && board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
                return board[0][i];
            }
        }
        // Controlla le diagonali
        if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
            return board[0][0];
        }
        if (board[0][2] != EMPTY && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
            return board[0][2];
        }
        return EMPTY;
    }

    private static void mossaGiocatore() {
        int riga, colonna;
        do {
            System.out.print("Inserisci la riga (0-2): ");
            riga = scanner.nextInt();
            System.out.print("Inserisci la colonna (0-2): ");
            colonna = scanner.nextInt();
        } while (!mossaValida(riga, colonna));

        board[riga][colonna] = PLAYER_X;
        stampaTabellone();
    }

    private static boolean mossaValida(int riga, int colonna) {
        return riga >= 0 && riga < BOARD_SIZE && colonna >= 0 && colonna < BOARD_SIZE && board[riga][colonna] == EMPTY;
    }

    private static void mossaComputer() {
        int[] mossa = ottieniMossaMinimax();
        board[mossa[0]][mossa[1]] = PLAYER_O;
        System.out.println("Il computer ha giocato in riga: " + mossa[0] + ", colonna: " + mossa[1]);
    }

    private static int[] ottieniMossaMinimax() {
        int[] mossa = { -1, -1 };
        int migliorValore = Integer.MIN_VALUE;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER_O;
                    int valoreMossa = minimax(false);
                    board[i][j] = EMPTY;
                    if (valoreMossa > migliorValore) {
                        migliorValore = valoreMossa;
                        mossa[0] = i;
                        mossa[1] = j;
                    }
                }
            }
        }
        return mossa;
    }

    private static int minimax(boolean isMaximizing) {
        char vincitore = determinaVincitore();
        if (vincitore != EMPTY) {
            return vincitore == PLAYER_O ? 1 : -1;
        }
        if (tabellonePieno()) {
            return 0;
        }

        if (isMaximizing) {
            int migliorValore = Integer.MIN_VALUE;
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    if (board[i][j] == EMPTY) {
                        board[i][j] = PLAYER_O;
                        migliorValore = Math.max(migliorValore, minimax(false));
                        board[i][j] = EMPTY;
                    }
                }
            }
            return migliorValore;
        } else {
            int migliorValore = Integer.MAX_VALUE;
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    if (board[i][j] == EMPTY) {
                        board[i][j] = PLAYER_X;
                        migliorValore = Math.min(migliorValore, minimax(true));
                        board[i][j] = EMPTY;
                    }
                }
            }
            return migliorValore;
        }
    }
}
