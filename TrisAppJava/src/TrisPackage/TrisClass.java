/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package TrisPackage;

import javax.swing.ImageIcon;
import javax.swing.JButton;

/**
 *
 * @author joels,ricpi,NicMuso,AlePini
 */
public class TrisClass {
    private char[][] board;
    private char currentPlayer;
     public TrisClass() {
        board = new char[3][3];
        currentPlayer = 'X'; // Inizia sempre con 'X'
        initializeBoard();
    }
     private void initializeBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = '-';
            }
        }
    }
    private void changePlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    public void makeMove(int row, int col) {
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == '-') {
            board[row][col] = currentPlayer;
            changePlayer();
        }
    }
    public char getCurrentPlayer() {
        return currentPlayer;
    }
    
    
    
    
    
    
    
    
    
    
    
    
}
