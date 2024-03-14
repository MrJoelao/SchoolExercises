/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package TrisPackage;

import javax.swing.ImageIcon;
import javax.swing.JButton;

/**
 *
 * @author joels
 */
public class TrisClass {
    //prova di push, prova numero due, numero tre, quatro
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
    
    
    
    
    
    
    
    
    
    
    
    
}
