/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package TrisPackage;

import javax.swing.JButton;
import javax.swing.JOptionPane;

/**
 *
 * @author joels
 */
public class TrisGui extends javax.swing.JFrame {
    private static final int WELCOME_PAGE = 0;
    private static final int MODE_PAGE = 1;
    private static final int GAME_PAGE = 2;
    private static final int SETTINGS_PAGE = 3;
    private char vincitore;
    private TrisClass trisPvP;
    /**
     * Creates new form TrisGui
     */
    public TrisGui() {
        initComponents();
        trisPvP=new TrisClass();
        
        //metto il pannello principale di welcome
        selectPanel(WELCOME_PAGE);
        
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        gamePage = new javax.swing.JPanel();
        buttonBox9 = new javax.swing.JButton();
        buttonBox8 = new javax.swing.JButton();
        buttonBox7 = new javax.swing.JButton();
        buttonBox6 = new javax.swing.JButton();
        buttonBox5 = new javax.swing.JButton();
        buttonBox4 = new javax.swing.JButton();
        buttonBox3 = new javax.swing.JButton();
        buttonBox2 = new javax.swing.JButton();
        buttonBox1 = new javax.swing.JButton();
        gameBackground = new javax.swing.JLabel();
        welcomePage = new javax.swing.JPanel();
        continueButton = new javax.swing.JButton();
        settingsButton = new javax.swing.JButton();
        welcomeBackground = new javax.swing.JLabel();
        modePage = new javax.swing.JPanel();
        AIPage = new javax.swing.JPanel();
        jButton2 = new javax.swing.JButton();
        jButton1 = new javax.swing.JButton();
        jLabel1 = new javax.swing.JLabel();
        AIbackground = new javax.swing.JLabel();
        chooseMode = new javax.swing.JLabel();
        AIButton = new javax.swing.JButton();
        friendButton = new javax.swing.JButton();
        modeBackground = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setMaximumSize(new java.awt.Dimension(450, 800));
        setMinimumSize(new java.awt.Dimension(450, 800));
        getContentPane().setLayout(new javax.swing.OverlayLayout(getContentPane()));

        gamePage.setMaximumSize(new java.awt.Dimension(450, 800));
        gamePage.setMinimumSize(new java.awt.Dimension(450, 800));
        gamePage.setPreferredSize(new java.awt.Dimension(450, 800));
        gamePage.setLayout(null);

        buttonBox9.setContentAreaFilled(false);
        buttonBox9.setMaximumSize(new java.awt.Dimension(112, 112));
        buttonBox9.setMinimumSize(new java.awt.Dimension(112, 112));
        buttonBox9.setPreferredSize(new java.awt.Dimension(112, 112));
        buttonBox9.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buttonBox9ActionPerformed(evt);
            }
        });
        gamePage.add(buttonBox9);
        buttonBox9.setBounds(300, 470, 112, 112);

        buttonBox8.setContentAreaFilled(false);
        buttonBox8.setMaximumSize(new java.awt.Dimension(112, 112));
        buttonBox8.setMinimumSize(new java.awt.Dimension(112, 112));
        buttonBox8.setPreferredSize(new java.awt.Dimension(112, 112));
        buttonBox8.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buttonBox8ActionPerformed(evt);
            }
        });
        gamePage.add(buttonBox8);
        buttonBox8.setBounds(170, 470, 112, 112);

        buttonBox7.setContentAreaFilled(false);
        buttonBox7.setMaximumSize(new java.awt.Dimension(112, 112));
        buttonBox7.setMinimumSize(new java.awt.Dimension(112, 112));
        buttonBox7.setPreferredSize(new java.awt.Dimension(112, 112));
        buttonBox7.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buttonBox7ActionPerformed(evt);
            }
        });
        gamePage.add(buttonBox7);
        buttonBox7.setBounds(40, 470, 112, 112);

        buttonBox6.setContentAreaFilled(false);
        buttonBox6.setMaximumSize(new java.awt.Dimension(112, 112));
        buttonBox6.setMinimumSize(new java.awt.Dimension(112, 112));
        buttonBox6.setPreferredSize(new java.awt.Dimension(112, 112));
        buttonBox6.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buttonBox6ActionPerformed(evt);
            }
        });
        gamePage.add(buttonBox6);
        buttonBox6.setBounds(300, 350, 112, 112);

        buttonBox5.setContentAreaFilled(false);
        buttonBox5.setMaximumSize(new java.awt.Dimension(112, 112));
        buttonBox5.setMinimumSize(new java.awt.Dimension(112, 112));
        buttonBox5.setPreferredSize(new java.awt.Dimension(112, 112));
        buttonBox5.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buttonBox5ActionPerformed(evt);
            }
        });
        gamePage.add(buttonBox5);
        buttonBox5.setBounds(170, 350, 112, 112);

        buttonBox4.setContentAreaFilled(false);
        buttonBox4.setMaximumSize(new java.awt.Dimension(112, 112));
        buttonBox4.setMinimumSize(new java.awt.Dimension(112, 112));
        buttonBox4.setPreferredSize(new java.awt.Dimension(112, 112));
        buttonBox4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buttonBox4ActionPerformed(evt);
            }
        });
        gamePage.add(buttonBox4);
        buttonBox4.setBounds(40, 350, 112, 112);

        buttonBox3.setContentAreaFilled(false);
        buttonBox3.setMaximumSize(new java.awt.Dimension(112, 112));
        buttonBox3.setMinimumSize(new java.awt.Dimension(112, 112));
        buttonBox3.setPreferredSize(new java.awt.Dimension(112, 112));
        buttonBox3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buttonBox3ActionPerformed(evt);
            }
        });
        gamePage.add(buttonBox3);
        buttonBox3.setBounds(300, 230, 112, 112);

        buttonBox2.setContentAreaFilled(false);
        buttonBox2.setMaximumSize(new java.awt.Dimension(112, 112));
        buttonBox2.setMinimumSize(new java.awt.Dimension(112, 112));
        buttonBox2.setPreferredSize(new java.awt.Dimension(112, 112));
        buttonBox2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buttonBox2ActionPerformed(evt);
            }
        });
        gamePage.add(buttonBox2);
        buttonBox2.setBounds(170, 230, 112, 112);

        buttonBox1.setContentAreaFilled(false);
        buttonBox1.setMaximumSize(new java.awt.Dimension(112, 112));
        buttonBox1.setMinimumSize(new java.awt.Dimension(112, 112));
        buttonBox1.setPreferredSize(new java.awt.Dimension(112, 112));
        buttonBox1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buttonBox1ActionPerformed(evt);
            }
        });
        gamePage.add(buttonBox1);
        buttonBox1.setBounds(40, 230, 112, 112);

        gameBackground.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/gameBackground.png"))); // NOI18N
        gamePage.add(gameBackground);
        gameBackground.setBounds(0, 0, 450, 800);

        getContentPane().add(gamePage);

        welcomePage.setMaximumSize(new java.awt.Dimension(450, 800));
        welcomePage.setMinimumSize(new java.awt.Dimension(450, 800));
        welcomePage.setPreferredSize(new java.awt.Dimension(450, 800));
        welcomePage.setLayout(null);

        continueButton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/continueButton.png"))); // NOI18N
        continueButton.setContentAreaFilled(false);
        continueButton.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/continueButtonP.png"))); // NOI18N
        continueButton.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/continueButtonR.png"))); // NOI18N
        continueButton.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/continueButtonRP.png"))); // NOI18N
        continueButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                continueButtonActionPerformed(evt);
            }
        });
        welcomePage.add(continueButton);
        continueButton.setBounds(150, 610, 130, 60);

        settingsButton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/settingsButton.png"))); // NOI18N
        settingsButton.setContentAreaFilled(false);
        settingsButton.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/settingsButtonR.png"))); // NOI18N
        settingsButton.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/settingsButtonRP.png"))); // NOI18N
        settingsButton.setSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/settingsButtonP.png"))); // NOI18N
        settingsButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                settingsButtonActionPerformed(evt);
            }
        });
        welcomePage.add(settingsButton);
        settingsButton.setBounds(200, 680, 40, 40);

        welcomeBackground.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/welcomeBackground.png"))); // NOI18N
        welcomePage.add(welcomeBackground);
        welcomeBackground.setBounds(0, 0, 450, 800);

        getContentPane().add(welcomePage);

        modePage.setLayout(null);

        AIPage.setOpaque(false);
        AIPage.setLayout(null);

        jButton2.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/teamBlueButton.png"))); // NOI18N
        jButton2.setContentAreaFilled(false);
        jButton2.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/teamBlueButtonP.png"))); // NOI18N
        jButton2.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/teamBlueButtonR.png"))); // NOI18N
        jButton2.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/teamBlueButtonRP.png"))); // NOI18N
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });
        AIPage.add(jButton2);
        jButton2.setBounds(132, 470, 190, 60);

        jButton1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/teamRedButton.png"))); // NOI18N
        jButton1.setContentAreaFilled(false);
        jButton1.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/teamRedButtonP.png"))); // NOI18N
        jButton1.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/teamRedButtonR.png"))); // NOI18N
        jButton1.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/teamRedButtonRP.png"))); // NOI18N
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });
        AIPage.add(jButton1);
        jButton1.setBounds(132, 330, 190, 60);

        jLabel1.setFont(new java.awt.Font("Segoe UI", 1, 16)); // NOI18N
        jLabel1.setForeground(new java.awt.Color(255, 255, 255));
        jLabel1.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel1.setText("OR");
        AIPage.add(jLabel1);
        jLabel1.setBounds(52, 376, 347, 100);

        AIbackground.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        AIbackground.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/modeAIPanel.png"))); // NOI18N
        AIbackground.setPreferredSize(new java.awt.Dimension(0, 0));
        AIPage.add(AIbackground);
        AIbackground.setBounds(0, 0, 450, 800);

        modePage.add(AIPage);
        AIPage.setBounds(0, 0, 450, 800);

        chooseMode.setFont(new java.awt.Font("Segoe UI", 1, 20)); // NOI18N
        chooseMode.setForeground(new java.awt.Color(255, 255, 255));
        chooseMode.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        chooseMode.setText("Choose your play mode:");
        modePage.add(chooseMode);
        chooseMode.setBounds(110, 480, 240, 30);

        AIButton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/AIButton.png"))); // NOI18N
        AIButton.setContentAreaFilled(false);
        AIButton.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        AIButton.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/AIButtonP.png"))); // NOI18N
        AIButton.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/AIButtonR.png"))); // NOI18N
        AIButton.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/AIButtonRP.png"))); // NOI18N
        AIButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                AIButtonActionPerformed(evt);
            }
        });
        modePage.add(AIButton);
        AIButton.setBounds(160, 520, 130, 60);

        friendButton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/friendButton.png"))); // NOI18N
        friendButton.setContentAreaFilled(false);
        friendButton.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/friendButtonP.png"))); // NOI18N
        friendButton.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/friendButtonR.png"))); // NOI18N
        friendButton.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/friendButtonRP.png"))); // NOI18N
        friendButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                friendButtonActionPerformed(evt);
            }
        });
        modePage.add(friendButton);
        friendButton.setBounds(160, 580, 130, 60);

        modeBackground.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/modeBackground.png"))); // NOI18N
        modePage.add(modeBackground);
        modeBackground.setBounds(0, 0, 450, 800);

        getContentPane().add(modePage);

        pack();
    }// </editor-fold>//GEN-END:initComponents
    public void playerMove(int row,int col, JButton button){
        int result = trisPvP.Muovi(row, col);
        String type;
        if (result >= 0) {
            if(result > 0){
                type = "O";
            } else {
                type = "X";
            }
            
            button.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/icon" + type + ".png")));
            
            } else {
                 JOptionPane.showMessageDialog(this, "Mossa non valida!", "Avviso", JOptionPane.WARNING_MESSAGE);
        }
        
        if(trisPvP.checkWinner()){
            vincitore=trisPvP.getGiocatore_corrente();
            
            //temporaneo
            JOptionPane.showMessageDialog(this, "vittoria", "Avviso", JOptionPane.WARNING_MESSAGE); 
            
            //winPanel();
        }
    }
    
    //reset pulsanti
    public void resetButtos(){
        buttonBox1.setIcon(null);
        buttonBox2.setIcon(null);
        buttonBox3.setIcon(null);
        buttonBox4.setIcon(null);
        buttonBox5.setIcon(null);
        buttonBox6.setIcon(null);
        buttonBox7.setIcon(null);
        buttonBox8.setIcon(null);
        buttonBox9.setIcon(null);
    }
    
    // Metodo per selezionare il pannello da visualizzare
    /*Le costanti sono in alto ma: WELCOME_PAGE è la schermata principale, GAME_PAGE è quella con la griglia del gioco e 
    altre che non ho ancora messo*/
    
    public void selectPanel(int choice) {
        System.out.println("[TG] Pannello caricato: " + choice);

        // Imposta tutti i pannelli su false
        gamePage.setVisible(false);
        welcomePage.setVisible(false);
        modePage.setVisible(false);
        
        // Attiva il pannello scelto
        switch (choice) {
            case WELCOME_PAGE:
                welcomePage.setVisible(true);
                break;
            case MODE_PAGE:
                modePage.setVisible(true);
                AIPage.setVisible(false);
                break;
            case GAME_PAGE:
                gamePage.setVisible(true);
                break;
            case SETTINGS_PAGE:
                break;
                        
            default:
                welcomePage.setVisible(true); //gestisco l'eccezione riportando l'utente alla schermata principale
                System.err.println("[TG] Errore: scelta del pannello non valida"); //in caso 
                break;
        }
    }
    
    private void buttonBox1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buttonBox1ActionPerformed
        playerMove(0,0, buttonBox1);
    }//GEN-LAST:event_buttonBox1ActionPerformed

    private void buttonBox2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buttonBox2ActionPerformed
        playerMove(0,1, buttonBox2);
    }//GEN-LAST:event_buttonBox2ActionPerformed

    private void buttonBox3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buttonBox3ActionPerformed
        playerMove(0,2, buttonBox3);
    }//GEN-LAST:event_buttonBox3ActionPerformed

    private void buttonBox4ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buttonBox4ActionPerformed
        playerMove(1,0, buttonBox4);
    }//GEN-LAST:event_buttonBox4ActionPerformed

    private void buttonBox5ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buttonBox5ActionPerformed
        playerMove(1,1, buttonBox5);
    }//GEN-LAST:event_buttonBox5ActionPerformed

    private void buttonBox6ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buttonBox6ActionPerformed
        playerMove(1,2, buttonBox6);
    }//GEN-LAST:event_buttonBox6ActionPerformed

    private void buttonBox7ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buttonBox7ActionPerformed
        playerMove(2,0, buttonBox7);
    }//GEN-LAST:event_buttonBox7ActionPerformed

    private void buttonBox8ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buttonBox8ActionPerformed
        playerMove(2,1, buttonBox8);
    }//GEN-LAST:event_buttonBox8ActionPerformed

    private void buttonBox9ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buttonBox9ActionPerformed
        playerMove(2,2, buttonBox9);
    }//GEN-LAST:event_buttonBox9ActionPerformed

    private void continueButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_continueButtonActionPerformed
        selectPanel(MODE_PAGE);
    }//GEN-LAST:event_continueButtonActionPerformed

    private void settingsButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_settingsButtonActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_settingsButtonActionPerformed

    private void AIButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_AIButtonActionPerformed
        AIPage.setVisible(true);
    }//GEN-LAST:event_AIButtonActionPerformed

    private void friendButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_friendButtonActionPerformed
        selectPanel(GAME_PAGE);
    }//GEN-LAST:event_friendButtonActionPerformed

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        selectPanel(GAME_PAGE);
    }//GEN-LAST:event_jButton1ActionPerformed

    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton2ActionPerformed
        selectPanel(GAME_PAGE);
    }//GEN-LAST:event_jButton2ActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(TrisGui.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(TrisGui.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(TrisGui.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(TrisGui.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new TrisGui().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton AIButton;
    private javax.swing.JPanel AIPage;
    private javax.swing.JLabel AIbackground;
    private javax.swing.JButton buttonBox1;
    private javax.swing.JButton buttonBox2;
    private javax.swing.JButton buttonBox3;
    private javax.swing.JButton buttonBox4;
    private javax.swing.JButton buttonBox5;
    private javax.swing.JButton buttonBox6;
    private javax.swing.JButton buttonBox7;
    private javax.swing.JButton buttonBox8;
    private javax.swing.JButton buttonBox9;
    private javax.swing.JLabel chooseMode;
    private javax.swing.JButton continueButton;
    private javax.swing.JButton friendButton;
    private javax.swing.JLabel gameBackground;
    private javax.swing.JPanel gamePage;
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel modeBackground;
    private javax.swing.JPanel modePage;
    private javax.swing.JButton settingsButton;
    private javax.swing.JLabel welcomeBackground;
    private javax.swing.JPanel welcomePage;
    // End of variables declaration//GEN-END:variables
}
