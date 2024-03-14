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
    private char[][] tabella;
    private char giocatore_corrente;
    public TrisClass() {
        tabella = new char[3][3];
        giocatore_corrente = 'X'; 
        inizializza();
    }
    private void inizializza() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                tabella[i][j] = '-';
            }
        }
    }
    private void Switch_giocatore() {
        giocatore_corrente = (giocatore_corrente == 'X') ? 'O' : 'X';
    }
    public void Muovi(int row, int col) {
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && tabella[row][col] == '-') {
            tabella[row][col] = giocatore_corrente;
            Switch_giocatore();
        }
    }
    public char getGiocatore_corrente() {
        return giocatore_corrente;
    }
    
    
    
    
    
    
    
    
    
    
    
    
}
