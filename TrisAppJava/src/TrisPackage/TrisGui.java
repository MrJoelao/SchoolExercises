/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package TrisPackage;

import java.net.URL;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import javax.swing.JButton;
import javax.swing.JPanel;
import java.util.Timer;
import java.util.TimerTask;
import javax.swing.JLabel;

/**
 *
 * @author joels
 */
public class TrisGui extends javax.swing.JFrame {
    //<editor-fold defaultstate="collapsed" desc=" Costanti ">
    private static final int WELCOME_PAGE = 0;
    private static final int LOGIN_PAGE = 1;
    private static final int MODE_PAGE = 2;
    private static final int CHOOSE_TEAM_PAGE = 3;
    private static final int GAME_PAGE = 4;
    private static final int SETTINGS_PAGE = 5;
    
    private static final String FILENAME_LM = "credentials.dat";
    private static final String DEFAULT_USERNAME = "admin";
    private static final String DEFAULT_PASSWORD = "admin";
    private static final boolean DEFAULT_TYPE = false;
    
    // Costanti per i codici d'errore della password
    private static final int PASSWORD_SECURE = 0;
    private static final int PASSWORD_TOO_SHORT = 1;
    private static final int MISSING_UPPERCASE = 2;
    private static final int MISSING_LOWERCASE = 3;
    private static final int MISSING_NUMBER = 4;
    private static final int MISSING_SPECIAL_CHARACTER = 5;
    private static final int USERNAME_USED = 6;
    
    // Costanti per i messaggi di successo
    public static final String MESSAGE_PASSWORD_SECURE = "<html>Password <b>inserita</b> con successo.</html>";
    public static final String MESSAGE_RIGHT_CREDENTIALS = "<html>Combinazione <b>trovata</b>.</html>";
    public static final String SUCCESS_MESSAGE = "Successo";
    
    // Costanti per i messaggi d'errore
    public static final String ERROR_MESSAGE = "Errore";
    public static final String ERROR_PASSWORD_TOO_SHORT = "<html><p align=\"center\">La password deve contenere almeno <b>8 caratteri</b>.</p></html>";
    public static final String ERROR_MISSING_UPPERCASE = "<html><p align=\"center\">La password deve contenere almeno una <b>lettera maiuscola</b>.</p></html>";
    public static final String ERROR_MISSING_LOWERCASE = "<html><p align=\"center\">La password deve contenere almeno una <b>lettera minuscola</b>.</p></html>";
    public static final String ERROR_MISSING_NUMBER = "<html><p align=\"center\">La password deve contenere <br>almeno un <b>numero</b>.</p></html>";
    public static final String ERROR_MISSING_SPECIAL_CHARACTER = "<html><p align=\"center\">La password deve contenere almeno un <b>carattere speciale</b>.</p></html>";
    public static final String ERROR_UNKNOWN = "<html><p align=\"center\"><b>Password già presente</b> usane una diversa.</p></html>";
    public static final String ERROR_USERNAME_USED = "<html><p align=\"center\"><Username<b> già in uso.</b></p></html>";
    private static final String ERROR_WRONG_CREDENTIALS = "<html>Username o Password <b>sbagliati</b>.</html>";
    
    // Costanti per il timer
    public static final int TIMER_MESSAGE = 1600;
    
    //Costanti immagini
    public static final String ERROR_IMAGE = "errorPopUp.png";
    public static final String SUCCESS_IMAGE = "successPopUp.png";
    
    // Costanti per gli effetti sonori
    public static final String ERROR_SOUND = "error.wav";
    public static final String SUCCESS_SOUND = "success.wav";
    
    // Costanti per i codici dei temi
    private static final int THEME_0 = 0;
    private static final int THEME_1 = 1;
    private static final int THEME_2 = 2;
    private static final int THEME_3 = 3;
    private static final int THEME_4 = 4;
    private static final int THEME_5 = 5;
    private static final int THEME_6 = 6;
    private static final int THEME_7 = 7;

    
    //</editor-fold>
    
    //<editor-fold defaultstate="collapsed" desc=" To-Do List">
    /*To-Do:
     * Bug logico: non è gestito il caso del pareggio dalla classe 1v1 del tris, non avendo modo di saperlo se si verifica si rimane bloccati.
     * bug logico: quando si verica un messaggio di vincita o d'errore è comunque possibile premere i tasti dietro, creando così 
     *             un susseguirsi d'errori. importante perchè così si permette di vincere più volte andando a sporcare il punteggio.
     * Mancata implementazione grafica: sfocatura dietro al pulsante della freccia mancante per problemi ad implmentarla, da 
     *                                  implementare singolarmente.
     * Mancata implementazione grafica: nessuna possibilità per la scelta dei temi. WORKING IN PROGRESS... 
     * Mancata implementazione: il punteggio non è stato ancora implementato e associato all'username. (punteggio, salvataggio su file e 
     *                          associazione del punteggio con l'username).
     * Mancata implementazione: sezione classifica non disponibile.
     * Mancata implementazione: sezione di diverse difficoltà user vs AI non disponibile.
     * Mancata implementazione grafica: sezione di scelta grafica di diverse difficoltà user vs AI non disponibile.
     * Mancata implementazione: sezione delle impostazioni non disponibile.
     * Mancata implementazione: sezione d'aiuto per l'utente tramie tasto "i" di informazioni non disonibile.
     * Mancata implementazione: manca completamente l'implementazione con il gioco tramite user vs AI. classi minmax non implementabile.
     * Mancata implementazione grafica: manca un bottone nella chooseTeamPage per tornare indietro, e uno simile o per mettere in pausa nella gamePage.
     * Mancata implementazione grafica: pulsante per la chiusura dei popUp non interactable.
     * 
     * Completati:
     * Redesign grafico: cambiata l'icona per passare ad altre pagine con una freccia, la scritta precedemte era poco leggibile. ✅
     * Redesign grafico: intero design rivisto, sistemate imperfezioni grafiche. ✅
     * Redesign grafico: messaggi di vincita completamente ridisegnati. ✅
     * Redesign grafico: messaggio d'errore ridisegnato. ✅
     * Redesign grafico: sfondi cambiati garantendo continuità con il colore tra le pagine. ✅
     * Redesign grafico: "X" e "O" leggeremente riviste aggiungendo delle migliorie grafice. effetto di sfocatura aggiunto. ✅
     * Implementazione grafica: aggiunti effetti di sfocatura e ombre quando compare un messaggio. ✅
     * Mancata implementazione: scelta del team non funzionante: costruttore della classe tris 1v1 modificata leggermente per permetterlo, 
     *                          modifica dei pulsanti in radio buttons, aggiunta di un gruppo di bottoni e di una variabile flag per la 
     *                          scelta del team. ✅
     * Mancata implementazione: . ✅
     * Mancata implementazione grafica: implementato il messaggio grafico di parità, manca l'associazione con il codice. ✅
     * Mancata implementazione: Implementato il comparto audio per errori/sucesso. ✅
     * Mancata implementazione: Implementato il comparto grafico pergli avvisi per il login. ✅
     * Mancata implementazione: classe login non viene usata dalla classe. ✅
     * Implementazione codice: aggiunto un timer nella funzione selectPanel() permettendo così di far vedere eventuali messaggi 
     *                         prima di cambiare pannello, inserire il tempo d'attesa in ms.
     * Bug logico: 1v1 non funzionante graficamente, crea un eccezzione nel prendere l'immagini di "X" e "O". ✅
     * Bug logico: errore nella funzione personalizedMessage dove creava un'eccezione quando prendeva le immagini per i messaggi 
     *             personalizate per il tipo d'erroe. ✅
     * Bug logico: tasto di chiusra della x del pop up della parità non funzionante. ✅
     * Bug logico: login non funzionante creando un'eccezione quando si prova a registarsi, questo per un'implementazione non corretta della
     *             classe login manager. ✅
     * Bug grafico: Il messaggio d'errore nell'aggiunta della password non ha la grandezza del fon giusta. ✅
     * Bug grafico: Immagine della "X" nel pannello di gioco ha un effettto di sfocatura dietro di se che però risulta tagliato. ✅
     * Bug grafico: Immagine della freccia premuta ha un'ombra diversa risultando uno spostamento quando viene premuta. ✅
     * */
    //</editor-fold>
    
    //Variabili flag
    private char flagTeam = 'x'; //scelta del team
    private boolean flagAI = false; //1 vs 1 / 1 vs AI
    private int difficulty = 3;
    char playerSymbol = 'X';
    
    private char vincitore;
    private String username;
    private String username2;
   
    
    //istanze
    private TrisNormal trisPvP;
    private TrisAI trisAI;
    private LoginManager loginManager;
    /**
     * Creates new form TrisGui
     */
    public TrisGui() {
        initComponents();
        
        //istanzio login manager con le impostazioni predefinite
        loginManager = new LoginManager(FILENAME_LM, DEFAULT_USERNAME, DEFAULT_PASSWORD, DEFAULT_TYPE);
        
        
        //metto il pannello principale di welcome
        selectPanel(WELCOME_PAGE,0);
        
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        teamButtons = new javax.swing.ButtonGroup();
        themeButtons = new javax.swing.ButtonGroup();
        settingsPage = new javax.swing.JPanel();
        theme0Buttton = new javax.swing.JRadioButton();
        theme1Buttton = new javax.swing.JRadioButton();
        theme2Buttton = new javax.swing.JRadioButton();
        theme3Buttton = new javax.swing.JRadioButton();
        theme4Buttton = new javax.swing.JRadioButton();
        theme5Buttton = new javax.swing.JRadioButton();
        theme6Buttton = new javax.swing.JRadioButton();
        theme7Buttton = new javax.swing.JRadioButton();
        deleteButton = new javax.swing.JButton();
        cancelSettingsButton = new javax.swing.JButton();
        backgroundMenu = new javax.swing.JLabel();
        welcomePage = new javax.swing.JPanel();
        continueButton = new javax.swing.JButton();
        settingsButton = new javax.swing.JButton();
        welcomeBackground = new javax.swing.JLabel();
        difficultyPage = new javax.swing.JPanel();
        loginPage = new javax.swing.JPanel();
        popUpPanel = new javax.swing.JPanel();
        popUpCancelButton = new javax.swing.JButton();
        popUpMessage = new javax.swing.JLabel();
        popUpTitle = new javax.swing.JLabel();
        popUpBackground = new javax.swing.JLabel();
        usernameTextField = new javax.swing.JTextField();
        passwordField = new javax.swing.JPasswordField();
        continueButton2 = new javax.swing.JButton();
        orText1 = new javax.swing.JLabel();
        addButton = new javax.swing.JButton();
        loginBackground = new javax.swing.JLabel();
        modePage = new javax.swing.JPanel();
        chooseMode = new javax.swing.JLabel();
        AIButton = new javax.swing.JButton();
        friendButton = new javax.swing.JButton();
        modeBackground = new javax.swing.JLabel();
        chooseTeamPage = new javax.swing.JPanel();
        teamRedButton = new javax.swing.JRadioButton();
        teamBlueButton = new javax.swing.JRadioButton();
        orText = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        continueButton1 = new javax.swing.JButton();
        chooseTeamBackground = new javax.swing.JLabel();
        gamePage = new javax.swing.JPanel();
        redWinPopUp = new javax.swing.JPanel();
        cancelButton2 = new javax.swing.JButton();
        jLabel4 = new javax.swing.JLabel();
        redWinBackground = new javax.swing.JLabel();
        errorPopUp = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        cancelButton1 = new javax.swing.JButton();
        errorMessageBackground = new javax.swing.JLabel();
        tiePopUp = new javax.swing.JPanel();
        cancelButton3 = new javax.swing.JButton();
        jLabel6 = new javax.swing.JLabel();
        tieBackground = new javax.swing.JLabel();
        blueWinPopUp = new javax.swing.JPanel();
        jLabel5 = new javax.swing.JLabel();
        cancelButton = new javax.swing.JButton();
        blueWinBackground = new javax.swing.JLabel();
        buttonBox9 = new javax.swing.JButton();
        buttonBox8 = new javax.swing.JButton();
        buttonBox7 = new javax.swing.JButton();
        buttonBox6 = new javax.swing.JButton();
        buttonBox5 = new javax.swing.JButton();
        buttonBox4 = new javax.swing.JButton();
        buttonBox3 = new javax.swing.JButton();
        buttonBox2 = new javax.swing.JButton();
        buttonBox1 = new javax.swing.JButton();
        backButton = new javax.swing.JButton();
        bluePointTextField = new javax.swing.JLabel();
        redPointTextField = new javax.swing.JLabel();
        gameBackground = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setMinimumSize(new java.awt.Dimension(450, 800));
        getContentPane().setLayout(new javax.swing.OverlayLayout(getContentPane()));

        settingsPage.setOpaque(false);
        settingsPage.setLayout(null);

        themeButtons.add(theme0Buttton);
        theme0Buttton.setContentAreaFilled(false);
        theme0Buttton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/theme0Button.png"))); // NOI18N
        theme0Buttton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                theme0ButttonActionPerformed(evt);
            }
        });
        settingsPage.add(theme0Buttton);
        theme0Buttton.setBounds(50, 236, 80, 80);

        themeButtons.add(theme1Buttton);
        theme1Buttton.setContentAreaFilled(false);
        theme1Buttton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/theme1Button.png"))); // NOI18N
        theme1Buttton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                theme1ButttonActionPerformed(evt);
            }
        });
        settingsPage.add(theme1Buttton);
        theme1Buttton.setBounds(140, 236, 80, 80);

        themeButtons.add(theme2Buttton);
        theme2Buttton.setContentAreaFilled(false);
        theme2Buttton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/theme2Button.png"))); // NOI18N
        theme2Buttton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                theme2ButttonActionPerformed(evt);
            }
        });
        settingsPage.add(theme2Buttton);
        theme2Buttton.setBounds(230, 236, 80, 80);

        themeButtons.add(theme3Buttton);
        theme3Buttton.setContentAreaFilled(false);
        theme3Buttton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/theme3Button.png"))); // NOI18N
        theme3Buttton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                theme3ButttonActionPerformed(evt);
            }
        });
        settingsPage.add(theme3Buttton);
        theme3Buttton.setBounds(320, 236, 80, 80);

        themeButtons.add(theme4Buttton);
        theme4Buttton.setContentAreaFilled(false);
        theme4Buttton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/theme5Button.png"))); // NOI18N
        theme4Buttton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                theme4ButttonActionPerformed(evt);
            }
        });
        settingsPage.add(theme4Buttton);
        theme4Buttton.setBounds(140, 322, 80, 80);

        themeButtons.add(theme5Buttton);
        theme5Buttton.setContentAreaFilled(false);
        theme5Buttton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/theme6Button.png"))); // NOI18N
        theme5Buttton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                theme5ButttonActionPerformed(evt);
            }
        });
        settingsPage.add(theme5Buttton);
        theme5Buttton.setBounds(230, 322, 80, 80);

        themeButtons.add(theme6Buttton);
        theme6Buttton.setContentAreaFilled(false);
        theme6Buttton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/theme7Button.png"))); // NOI18N
        theme6Buttton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                theme6ButttonActionPerformed(evt);
            }
        });
        settingsPage.add(theme6Buttton);
        theme6Buttton.setBounds(320, 322, 80, 80);

        themeButtons.add(theme7Buttton);
        theme7Buttton.setContentAreaFilled(false);
        theme7Buttton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/theme4Button.png"))); // NOI18N
        theme7Buttton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                theme7ButttonActionPerformed(evt);
            }
        });
        settingsPage.add(theme7Buttton);
        theme7Buttton.setBounds(50, 322, 80, 80);

        deleteButton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/deleteButton.png"))); // NOI18N
        deleteButton.setVerticalAlignment(javax.swing.SwingConstants.TOP);
        deleteButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                deleteButtonActionPerformed(evt);
            }
        });
        settingsPage.add(deleteButton);
        deleteButton.setBounds(120, 530, 30, 30);

        cancelSettingsButton.setContentAreaFilled(false);
        cancelSettingsButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cancelSettingsButtonActionPerformed(evt);
            }
        });
        settingsPage.add(cancelSettingsButton);
        cancelSettingsButton.setBounds(342, 13, 30, 30);

        backgroundMenu.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/settingsPage.png"))); // NOI18N
        backgroundMenu.setText("jLabel7");
        settingsPage.add(backgroundMenu);
        backgroundMenu.setBounds(0, 0, 450, 800);

        getContentPane().add(settingsPage);

        welcomePage.setMaximumSize(new java.awt.Dimension(450, 800));
        welcomePage.setMinimumSize(new java.awt.Dimension(450, 800));
        welcomePage.setPreferredSize(new java.awt.Dimension(450, 800));
        welcomePage.setLayout(null);

        continueButton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/continueButton.png"))); // NOI18N
        continueButton.setContentAreaFilled(false);
        continueButton.setDisabledIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/continueButton.png"))); // NOI18N
        continueButton.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/continueButtonP.png"))); // NOI18N
        continueButton.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/continueButtonR.png"))); // NOI18N
        continueButton.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/continueButtonRP.png"))); // NOI18N
        continueButton.addComponentListener(new java.awt.event.ComponentAdapter() {
            public void componentShown(java.awt.event.ComponentEvent evt) {
                settingsHandler(evt);
            }
        });
        continueButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                continueButtonActionPerformed(evt);
            }
        });
        welcomePage.add(continueButton);
        continueButton.setBounds(180, 650, 100, 50);

        settingsButton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/settingsButton.png"))); // NOI18N
        settingsButton.setContentAreaFilled(false);
        settingsButton.setDisabledIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/settingsButton.png"))); // NOI18N
        settingsButton.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/settingsButtonP.png"))); // NOI18N
        settingsButton.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/settingsButtonR.png"))); // NOI18N
        settingsButton.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/settingsButtonRP.png"))); // NOI18N
        settingsButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                settingsButtonActionPerformed(evt);
            }
        });
        welcomePage.add(settingsButton);
        settingsButton.setBounds(210, 730, 40, 40);

        welcomeBackground.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/welcomePage0.png"))); // NOI18N
        welcomePage.add(welcomeBackground);
        welcomeBackground.setBounds(0, 0, 450, 800);

        getContentPane().add(welcomePage);
        getContentPane().add(difficultyPage);

        loginPage.setLayout(null);

        popUpPanel.setOpaque(false);
        popUpPanel.setLayout(null);

        popUpCancelButton.setContentAreaFilled(false);
        popUpCancelButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                popUpCancelButtonActionPerformed(evt);
            }
        });
        popUpPanel.add(popUpCancelButton);
        popUpCancelButton.setBounds(358, 279, 30, 30);

        popUpMessage.setFont(new java.awt.Font("Segoe UI", 0, 17)); // NOI18N
        popUpMessage.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        popUpMessage.setText("***********");
        popUpMessage.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        popUpPanel.add(popUpMessage);
        popUpMessage.setBounds(50, 360, 350, 120);

        popUpTitle.setFont(new java.awt.Font("Segoe UI", 1, 24)); // NOI18N
        popUpTitle.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        popUpTitle.setText("*");
        popUpTitle.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        popUpPanel.add(popUpTitle);
        popUpTitle.setBounds(52, 290, 346, 60);

        popUpBackground.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        popUpBackground.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/errorPopUp.png"))); // NOI18N
        popUpPanel.add(popUpBackground);
        popUpBackground.setBounds(0, 0, 450, 800);

        loginPage.add(popUpPanel);
        popUpPanel.setBounds(0, 0, 450, 800);

        usernameTextField.setText("Username");
        usernameTextField.setBorder(null);
        loginPage.add(usernameTextField);
        usernameTextField.setBounds(160, 339, 190, 30);

        passwordField.setText("Password");
        passwordField.setBorder(null);
        passwordField.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                passwordFieldActionPerformed(evt);
            }
        });
        loginPage.add(passwordField);
        passwordField.setBounds(160, 414, 190, 30);

        continueButton2.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/continueButton.png"))); // NOI18N
        continueButton2.setContentAreaFilled(false);
        continueButton2.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/continueButtonP.png"))); // NOI18N
        continueButton2.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/continueButtonR.png"))); // NOI18N
        continueButton2.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/continueButtonRP.png"))); // NOI18N
        continueButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                continueButton2ActionPerformed(evt);
            }
        });
        loginPage.add(continueButton2);
        continueButton2.setBounds(180, 650, 100, 50);

        orText1.setFont(new java.awt.Font("Segoe UI", 1, 23)); // NOI18N
        orText1.setForeground(new java.awt.Color(255, 255, 255));
        orText1.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        orText1.setText("Login");
        loginPage.add(orText1);
        orText1.setBounds(50, 270, 348, 50);

        addButton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/addButton.png"))); // NOI18N
        addButton.setContentAreaFilled(false);
        addButton.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/addButtonP.png"))); // NOI18N
        addButton.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/addButtonR.png"))); // NOI18N
        addButton.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/addButtonRP.png"))); // NOI18N
        addButton.setVerticalAlignment(javax.swing.SwingConstants.TOP);
        addButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                addButtonActionPerformed(evt);
            }
        });
        loginPage.add(addButton);
        addButton.setBounds(180, 470, 85, 40);

        loginBackground.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        loginBackground.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/loginPage0.png"))); // NOI18N
        loginPage.add(loginBackground);
        loginBackground.setBounds(0, 0, 450, 800);

        getContentPane().add(loginPage);

        modePage.setLayout(null);

        chooseMode.setFont(new java.awt.Font("Segoe UI", 1, 20)); // NOI18N
        chooseMode.setForeground(new java.awt.Color(255, 255, 255));
        chooseMode.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        chooseMode.setText("Choose your play mode:");
        modePage.add(chooseMode);
        chooseMode.setBounds(110, 510, 240, 30);

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
        AIButton.setBounds(160, 560, 130, 60);

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
        friendButton.setBounds(160, 620, 130, 60);

        modeBackground.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/playModePage0.png"))); // NOI18N
        modePage.add(modeBackground);
        modeBackground.setBounds(0, 0, 450, 800);

        getContentPane().add(modePage);

        chooseTeamPage.setOpaque(false);
        chooseTeamPage.setLayout(null);

        teamButtons.add(teamRedButton);
        teamRedButton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/teamRedButton.png"))); // NOI18N
        teamRedButton.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/teamRedButtonP.png"))); // NOI18N
        teamRedButton.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/teamRedButtonR.png"))); // NOI18N
        teamRedButton.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/teamRedButtonRP.png"))); // NOI18N
        teamRedButton.setSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/teamRedButtonP.png"))); // NOI18N
        teamRedButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                teamRedButtonActionPerformed(evt);
            }
        });
        chooseTeamPage.add(teamRedButton);
        teamRedButton.setBounds(150, 350, 170, 60);

        teamButtons.add(teamBlueButton);
        teamBlueButton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/teamBlueButton.png"))); // NOI18N
        teamBlueButton.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/teamBlueButtonP.png"))); // NOI18N
        teamBlueButton.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/teamBlueButtonR.png"))); // NOI18N
        teamBlueButton.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/teamBlueButtonRP.png"))); // NOI18N
        teamBlueButton.setSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/teamBlueButtonP.png"))); // NOI18N
        teamBlueButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                teamBlueButtonActionPerformed(evt);
            }
        });
        chooseTeamPage.add(teamBlueButton);
        teamBlueButton.setBounds(150, 438, 160, 60);

        orText.setFont(new java.awt.Font("Segoe UI", 1, 18)); // NOI18N
        orText.setForeground(new java.awt.Color(255, 255, 255));
        orText.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        orText.setText("OR");
        chooseTeamPage.add(orText);
        orText.setBounds(60, 370, 340, 100);

        jLabel3.setFont(new java.awt.Font("Segoe UI", 1, 25)); // NOI18N
        jLabel3.setForeground(new java.awt.Color(255, 255, 255));
        jLabel3.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel3.setText("Choose your team!");
        chooseTeamPage.add(jLabel3);
        jLabel3.setBounds(60, 280, 340, 34);

        continueButton1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/continueButton.png"))); // NOI18N
        continueButton1.setContentAreaFilled(false);
        continueButton1.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/continueButtonP.png"))); // NOI18N
        continueButton1.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/continueButtonR.png"))); // NOI18N
        continueButton1.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/continueButtonRP.png"))); // NOI18N
        continueButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                continueButton1ActionPerformed(evt);
            }
        });
        chooseTeamPage.add(continueButton1);
        continueButton1.setBounds(180, 605, 100, 50);

        chooseTeamBackground.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        chooseTeamBackground.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/chooseTeamPage0.png"))); // NOI18N
        chooseTeamPage.add(chooseTeamBackground);
        chooseTeamBackground.setBounds(0, 0, 450, 800);

        getContentPane().add(chooseTeamPage);

        gamePage.setMaximumSize(new java.awt.Dimension(450, 800));
        gamePage.setMinimumSize(new java.awt.Dimension(450, 800));
        gamePage.setPreferredSize(new java.awt.Dimension(450, 800));
        gamePage.setLayout(null);

        redWinPopUp.setOpaque(false);
        redWinPopUp.setLayout(null);

        cancelButton2.setContentAreaFilled(false);
        cancelButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cancelButton2ActionPerformed(evt);
            }
        });
        redWinPopUp.add(cancelButton2);
        cancelButton2.setBounds(368, 281, 30, 30);

        jLabel4.setFont(new java.awt.Font("Segoe UI", 1, 18)); // NOI18N
        jLabel4.setForeground(new java.awt.Color(255, 255, 255));
        jLabel4.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel4.setText("Team Red Win!");
        redWinPopUp.add(jLabel4);
        jLabel4.setBounds(70, 330, 310, 25);

        redWinBackground.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/redWin.png"))); // NOI18N
        redWinPopUp.add(redWinBackground);
        redWinBackground.setBounds(0, 0, 450, 800);

        gamePage.add(redWinPopUp);
        redWinPopUp.setBounds(0, 0, 450, 800);

        errorPopUp.setOpaque(false);
        errorPopUp.setLayout(null);

        jLabel1.setFont(new java.awt.Font("Segoe UI", 1, 23)); // NOI18N
        jLabel1.setForeground(new java.awt.Color(255, 255, 255));
        jLabel1.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel1.setText("Invalid move");
        errorPopUp.add(jLabel1);
        jLabel1.setBounds(50, 370, 350, 31);

        jLabel2.setFont(new java.awt.Font("Segoe UI", 0, 17)); // NOI18N
        jLabel2.setForeground(new java.awt.Color(255, 255, 255));
        jLabel2.setText("Error: move chosen invalid, try again by choosing another box.");
        errorPopUp.add(jLabel2);
        jLabel2.setBounds(70, 420, 310, 30);

        cancelButton1.setContentAreaFilled(false);
        cancelButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cancelButton1ActionPerformed(evt);
            }
        });
        errorPopUp.add(cancelButton1);
        cancelButton1.setBounds(354, 340, 30, 30);

        errorMessageBackground.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/errorMessage.png"))); // NOI18N
        errorPopUp.add(errorMessageBackground);
        errorMessageBackground.setBounds(0, 0, 450, 800);

        gamePage.add(errorPopUp);
        errorPopUp.setBounds(0, 0, 450, 800);

        tiePopUp.setOpaque(false);
        tiePopUp.setLayout(null);

        cancelButton3.setContentAreaFilled(false);
        cancelButton3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cancelButton3ActionPerformed(evt);
            }
        });
        tiePopUp.add(cancelButton3);
        cancelButton3.setBounds(368, 282, 30, 30);

        jLabel6.setFont(new java.awt.Font("Segoe UI", 1, 23)); // NOI18N
        jLabel6.setForeground(new java.awt.Color(255, 255, 255));
        jLabel6.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel6.setText("TIE!");
        tiePopUp.add(jLabel6);
        jLabel6.setBounds(70, 330, 310, 31);

        tieBackground.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/tiePage.png"))); // NOI18N
        tiePopUp.add(tieBackground);
        tieBackground.setBounds(0, 0, 450, 800);

        gamePage.add(tiePopUp);
        tiePopUp.setBounds(0, 0, 450, 800);

        blueWinPopUp.setOpaque(false);
        blueWinPopUp.setLayout(null);

        jLabel5.setFont(new java.awt.Font("Segoe UI", 1, 18)); // NOI18N
        jLabel5.setForeground(new java.awt.Color(255, 255, 255));
        jLabel5.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel5.setText("Team Blue win!");
        blueWinPopUp.add(jLabel5);
        jLabel5.setBounds(70, 330, 310, 25);

        cancelButton.setContentAreaFilled(false);
        cancelButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cancelButtonActionPerformed(evt);
            }
        });
        blueWinPopUp.add(cancelButton);
        cancelButton.setBounds(368, 281, 30, 30);

        blueWinBackground.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/blueWin.png"))); // NOI18N
        blueWinPopUp.add(blueWinBackground);
        blueWinBackground.setBounds(0, 0, 450, 800);

        gamePage.add(blueWinPopUp);
        blueWinPopUp.setBounds(0, 0, 450, 800);

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
        buttonBox9.setBounds(300, 460, 112, 112);

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
        buttonBox8.setBounds(170, 460, 112, 112);

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
        buttonBox7.setBounds(40, 460, 112, 112);

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
        buttonBox6.setBounds(300, 340, 112, 112);

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
        buttonBox5.setBounds(170, 340, 112, 112);

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
        buttonBox4.setBounds(40, 340, 112, 112);

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
        buttonBox3.setBounds(300, 220, 112, 112);

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
        buttonBox2.setBounds(170, 220, 112, 112);

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
        buttonBox1.setBounds(40, 220, 112, 112);

        backButton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/backButton.png"))); // NOI18N
        backButton.setContentAreaFilled(false);
        backButton.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/backButtonP.png"))); // NOI18N
        backButton.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/backButtonR.png"))); // NOI18N
        backButton.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/backButtonRP.png"))); // NOI18N
        backButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                backButtonActionPerformed(evt);
            }
        });
        gamePage.add(backButton);
        backButton.setBounds(180, 660, 100, 60);

        bluePointTextField.setFont(new java.awt.Font("Segoe UI", 1, 35)); // NOI18N
        bluePointTextField.setForeground(new java.awt.Color(255, 255, 255));
        bluePointTextField.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        bluePointTextField.setText("0");
        gamePage.add(bluePointTextField);
        bluePointTextField.setBounds(176, 116, 30, 40);

        redPointTextField.setFont(new java.awt.Font("Segoe UI", 1, 35)); // NOI18N
        redPointTextField.setForeground(new java.awt.Color(255, 255, 255));
        redPointTextField.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        redPointTextField.setText("0");
        gamePage.add(redPointTextField);
        redPointTextField.setBounds(243, 116, 30, 40);

        gameBackground.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/gamePage0.png"))); // NOI18N
        gamePage.add(gameBackground);
        gameBackground.setBounds(0, 0, 450, 800);

        getContentPane().add(gamePage);

        pack();
    }// </editor-fold>//GEN-END:initComponents
    public boolean move(int row,int col, JButton button){
        int result;
        
        if(flagAI){
            
            
            if(!trisAI.playerMove(row, col)){
                errorPopUp.setVisible(true); //messaggio d'errore se percaso la mossa non risulta valida
            } else {
                button.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/icon" + playerSymbol + ".png")));
            }
            
            trisAI.printBoard();
            
            if(winPopUp(trisAI.checkWinner())){ return true;}
            
            int[] computerMove = trisAI.computerMove();
            setIconAtPosition(computerMove[0], computerMove[1]); 
            
            trisAI.printBoard();
            
            if(winPopUp(trisAI.checkWinner())){ return true;}
            
        } else {
            result = trisPvP.move(row, col);
            String type;


            if (result >= 0) {
                if(result > 0){
                    type = "O";
                } else {
                    type = "X";
                }
                
                 button.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/icon" + type + ".png")));
                
            } else {
                errorPopUp.setVisible(true);
            }
            if(winPopUp(trisPvP.checkWinner())){ return true;}
        }
        return false;
    }
    
    public boolean winPopUp(int result){
        boolean flag = true;
        switch(result){
            case 1 -> redWinPopUp.setVisible(true);
            case 0 -> blueWinPopUp.setVisible(true);
            case -1 -> tiePopUp.setVisible(true);
            default -> {
                flag = false;
                }
            }
        return flag;
    }
    
    public void setIconAtPosition(int row, int col) {
        char computerSymbol = (playerSymbol == 'X') ? 'O' : 'X'; // Determina il simbolo del computer  
        
        String iconPath = "/Icons/icon" + computerSymbol + ".png";
        javax.swing.ImageIcon icon = new javax.swing.ImageIcon(getClass().getResource(iconPath));

        switch (row) {
            case 0:
                switch (col) {
                    case 0:
                        buttonBox1.setIcon(icon);
                        break;
                    case 1:
                        buttonBox2.setIcon(icon);
                        break;
                    case 2:
                        buttonBox3.setIcon(icon);
                        break;
                    default:
                        System.err.println("[TG] Colonna non valida.");
                }
                break;
            case 1:
                switch (col) {
                    case 0:
                        buttonBox4.setIcon(icon);
                        break;
                    case 1:
                        buttonBox5.setIcon(icon);
                        break;
                    case 2:
                        buttonBox6.setIcon(icon);
                        break;
                    default:
                        System.err.println("[TG] Colonna non valida.");
                }
                break;
            case 2:
                switch (col) {
                    case 0:
                        buttonBox7.setIcon(icon);
                        break;
                    case 1:
                        buttonBox8.setIcon(icon);
                        break;
                    case 2:
                        buttonBox9.setIcon(icon);
                        break;
                    default:
                        System.err.println("[TG] Colonna non valida.");
                }
                break;
            default:
                System.err.println("[TG] Riga non valida.");
        }
    }


    
    // Metodo per riprodurre un suono
    /*in path si inserisce il nome del file wav, bisogna metterlo nella cartella "fsx_effect", e il flag loop è se vogliamo che il suono si ripeta all'infinito,
      utile per musiche di sottofondo*/
    public static void play(String path, boolean loop) { //usate il tipo WAV, metodo non mio tengo a precisare. (convertitore: https://convertio.co/it/mp3-wav/ )
        try {
            URL url = TrisGui.class.getResource("/fsx/" + path);
            if (url != null) {
                AudioInputStream audioInput = AudioSystem.getAudioInputStream(url);
                Clip clip = AudioSystem.getClip();
                clip.open(audioInput);
                clip.start();
                if (loop) {
                    clip.loop(Clip.LOOP_CONTINUOUSLY);
                }
            } else {
                System.err.println("[TG] Errore: file audio non esistente");
            }
        } catch (Exception e) {
            System.err.println("[TG] Errore nella riproduzione audio");
        }
    }
    
    // Metodo per visualizzare il messaggio di errore della password
    public String displayPasswordErrorMessage(int errorCode) {
        String errorMessage;
        switch (errorCode) {
            case PASSWORD_TOO_SHORT:
                errorMessage = ERROR_PASSWORD_TOO_SHORT;
                break;
            case MISSING_UPPERCASE:
                errorMessage = ERROR_MISSING_UPPERCASE;
                break;
            case MISSING_LOWERCASE:
                errorMessage = ERROR_MISSING_LOWERCASE;
                break;
            case MISSING_NUMBER:
                errorMessage = ERROR_MISSING_NUMBER;
                break;
            case MISSING_SPECIAL_CHARACTER:
                errorMessage = ERROR_MISSING_SPECIAL_CHARACTER;
                break;
            case USERNAME_USED:
                errorMessage = ERROR_USERNAME_USED;
                break;     
            default:
                errorMessage = ERROR_UNKNOWN;
                System.err.println("[TG] Codice errore sconosciuto: " + errorCode);
                break;
        }
        return errorMessage;
    }
    
    // Metodo per mostrare un messaggio personalizzato:
    /*Il background è il nome della foto per lo sfondo, message è il messaggio stampato sulla GUI, il textcolor è il colore del titolo, 
      sound è il nome del suono da trasmettere e flagLoop è un flag che serve se si vuole che il suono venga ripetuto all'infinito*/
    public void personalizedMessage(JPanel panel, JLabel titleLabel, JLabel messageLabel, JLabel backgroundLabel, String background, String title, String message, String sound) {
        backgroundLabel.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/"+ background)));
        titleLabel.setText(title);
        messageLabel.setText(message);
        play(sound, false);
    }
    
    public void messagePopUp(JPanel panel, JLabel titleLabel, JLabel messageLabel, JLabel backgroundLabel, boolean flagError, String message){
        panel.setVisible(true);
        
        if (flagError) {
            personalizedMessage(panel, titleLabel, messageLabel, backgroundLabel, ERROR_IMAGE, ERROR_MESSAGE, message, ERROR_SOUND);
        } else {
            personalizedMessage(panel, titleLabel, messageLabel, backgroundLabel,SUCCESS_IMAGE, SUCCESS_MESSAGE, message, SUCCESS_SOUND);
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
    public void selectPanel(int choice, int delayInMs) {
        System.out.println("[TG] Pannello in caricamento");
        // Attiva il pannello scelto dopo un ritardo
        Timer timer = new Timer();
        timer.schedule(new TimerTask() {
            @Override
            public void run() {
                System.out.println("[TG] Pannello caricato: " + choice);

                // Imposta tutti i pannelli su false
                welcomePage.setVisible(false);
                loginPage.setVisible(false);
                modePage.setVisible(false);
                chooseTeamPage.setVisible(false);
                gamePage.setVisible(false);
                tiePopUp.setVisible(false);
                settingsPage.setVisible(false);
                difficultyPage.setVisible(false);
                
                switch (choice) {
                    case WELCOME_PAGE:
                        welcomePage.setEnabled(false);
                        welcomePage.setVisible(true);
                        continueButton.setEnabled(true);
                        settingsButton.setEnabled(true);
                        break;
                    case LOGIN_PAGE:
                        loginPage.setVisible(true);
                        popUpPanel.setVisible(false);
                        break;
                    case MODE_PAGE:
                        modePage.setVisible(true);
                        break;
                    case CHOOSE_TEAM_PAGE:
                        chooseTeamPage.setVisible(true);
                        break;
                    case GAME_PAGE:
                        if(flagAI){
                            trisAI = new TrisAI(playerSymbol, difficulty);
                        }else{
                            trisPvP = new TrisNormal(flagTeam);                            
                        }
                        
                        
                        resetButtos();

                        errorPopUp.setVisible(false);
                        redWinPopUp.setVisible(false);
                        blueWinPopUp.setVisible(false);
                        gamePage.setVisible(true);
                        break; 
                    case SETTINGS_PAGE:
                        settingsPage.setVisible(true);
                        welcomePage.setVisible(true);
                        continueButton.setEnabled(false);
                        settingsButton.setEnabled(false);
                        break;

                    default:
                        welcomePage.setVisible(true); //gestisco l'eccezione riportando l'utente alla schermata principale
                        System.err.println("[TG] Errore: scelta del pannello non valida"); //in caso 
                        break;
                }
            }
        }, delayInMs);
    }

    public void chageTheme(int numTheme){
        welcomeBackground.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/welcomePage" + numTheme + ".png")));
        loginBackground.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/loginPage" + numTheme + ".png")));
        modeBackground.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/playModePage" + numTheme + ".png")));
        chooseTeamBackground.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/chooseTeamPage" + numTheme + ".png")));
        gameBackground.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Icons/gamePage" + numTheme + ".png")));
        selectPanel(SETTINGS_PAGE, 0);
    }
    
    private void buttonBox1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buttonBox1ActionPerformed
        move(0,0, buttonBox1);
    }//GEN-LAST:event_buttonBox1ActionPerformed

    private void buttonBox2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buttonBox2ActionPerformed
        move(0,1, buttonBox2);
    }//GEN-LAST:event_buttonBox2ActionPerformed

    private void buttonBox3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buttonBox3ActionPerformed
        move(0,2, buttonBox3);
    }//GEN-LAST:event_buttonBox3ActionPerformed

    private void buttonBox4ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buttonBox4ActionPerformed
        move(1,0, buttonBox4);
    }//GEN-LAST:event_buttonBox4ActionPerformed

    private void buttonBox5ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buttonBox5ActionPerformed
        move(1,1, buttonBox5);
    }//GEN-LAST:event_buttonBox5ActionPerformed

    private void buttonBox6ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buttonBox6ActionPerformed
        move(1,2, buttonBox6);
    }//GEN-LAST:event_buttonBox6ActionPerformed

    private void buttonBox7ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buttonBox7ActionPerformed
        move(2,0, buttonBox7);
    }//GEN-LAST:event_buttonBox7ActionPerformed

    private void buttonBox8ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buttonBox8ActionPerformed
        move(2,1, buttonBox8);
    }//GEN-LAST:event_buttonBox8ActionPerformed

    private void buttonBox9ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buttonBox9ActionPerformed
        move(2,2, buttonBox9);
    }//GEN-LAST:event_buttonBox9ActionPerformed

    private void continueButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_continueButtonActionPerformed
        selectPanel(LOGIN_PAGE,0);
    }//GEN-LAST:event_continueButtonActionPerformed

    private void settingsButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_settingsButtonActionPerformed
        selectPanel(SETTINGS_PAGE,0);
    }//GEN-LAST:event_settingsButtonActionPerformed

    private void AIButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_AIButtonActionPerformed
        selectPanel(CHOOSE_TEAM_PAGE,0);
        flagAI = true;
    }//GEN-LAST:event_AIButtonActionPerformed

    private void friendButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_friendButtonActionPerformed
        selectPanel(CHOOSE_TEAM_PAGE,0);
        flagAI = false;
    }//GEN-LAST:event_friendButtonActionPerformed

    private void continueButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_continueButton1ActionPerformed
        selectPanel(GAME_PAGE,0);
    }//GEN-LAST:event_continueButton1ActionPerformed

    private void cancelButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cancelButtonActionPerformed
        // TODO add your handling code here:
        blueWinPopUp.setVisible(false);
    }//GEN-LAST:event_cancelButtonActionPerformed

    private void cancelButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cancelButton1ActionPerformed
        // TODO add your handling code here:
        errorPopUp.setVisible(false);
    }//GEN-LAST:event_cancelButton1ActionPerformed

    private void cancelButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cancelButton2ActionPerformed
        // TODO add your handling code here:
        redWinPopUp.setVisible(false);
    }//GEN-LAST:event_cancelButton2ActionPerformed
    private void continueButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_continueButton2ActionPerformed
        // Ottieni l'username e la password inseriti dall'utente
        String enteredUsername = usernameTextField.getText();
        String enteredPassword = passwordField.getText();

        // Verifica se le credenziali sono valide utilizzando il gestore del login
        boolean credentialsValid = loginManager.checkCredentials(enteredUsername, enteredPassword);

        // Se le credenziali sono valide
        if (credentialsValid) {
            // Visualizza una notifica di credenziali corrette
            messagePopUp(popUpPanel, popUpTitle, popUpMessage, popUpBackground, false, MESSAGE_RIGHT_CREDENTIALS);

            // Passo alla scheda successiva
            selectPanel(MODE_PAGE,TIMER_MESSAGE);

            // Memorizza l'username dell'utente corrente
            username = enteredUsername;

        } else {
            // Se le credenziali non sono valide, visualizza un messaggio di errore
            messagePopUp(popUpPanel, popUpTitle, popUpMessage, popUpBackground, true, ERROR_WRONG_CREDENTIALS);
        }
    }//GEN-LAST:event_continueButton2ActionPerformed

    private void passwordFieldActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_passwordFieldActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_passwordFieldActionPerformed

    private void addButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_addButtonActionPerformed
        // Ottieni l'username e la password inseriti dall'utente
        String enteredUsername = usernameTextField.getText();
        String enteredPassword = passwordField.getText();

        // Verifica la sicurezza della password
        int passwordSecure = loginManager.isPasswordSecure(enteredPassword);
        // Ottiene il messaggio di errore relativo alla sicurezza della password
        String errorMessage = displayPasswordErrorMessage(passwordSecure);

        // Verifica se la password non è sicura o se l'username esiste già nel sistema
        if (passwordSecure != PASSWORD_SECURE || loginManager.isUsernameExists(enteredUsername)) {
            
            // Visualizza il messaggio di errore relativo alla password
            displayPasswordErrorMessage(passwordSecure);
            // Visualizza una finestra pop-up con il messaggio di errore
            messagePopUp(popUpPanel, popUpTitle, popUpMessage, popUpBackground, true, errorMessage);
            
        } else {
            // Aggiunge le credenziali all'utente nel sistema
            loginManager.addCredentials(enteredUsername, enteredPassword, false);
            // Visualizza un messaggio di conferma
            messagePopUp(popUpPanel, popUpTitle, popUpMessage, popUpBackground, false, MESSAGE_PASSWORD_SECURE);
            
            // Passo alla scheda successiva
            selectPanel(MODE_PAGE,TIMER_MESSAGE);
        }    
    }//GEN-LAST:event_addButtonActionPerformed

    private void backButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_backButtonActionPerformed
        // TODO add your handling code here:
        selectPanel(CHOOSE_TEAM_PAGE,0);
    }//GEN-LAST:event_backButtonActionPerformed

    private void teamRedButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_teamRedButtonActionPerformed
        // TODO add your handling code here:
        System.out.println("[TG] Team scelto: " + flagTeam);
        flagTeam = 'X';
    }//GEN-LAST:event_teamRedButtonActionPerformed

    private void teamBlueButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_teamBlueButtonActionPerformed
        // TODO add your handling code here:
        System.out.println("[TG] Team scelto: " + flagTeam);
        flagTeam = 'O';
    }//GEN-LAST:event_teamBlueButtonActionPerformed

    private void popUpCancelButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_popUpCancelButtonActionPerformed
        popUpPanel.setVisible(false);
    }//GEN-LAST:event_popUpCancelButtonActionPerformed

    private void cancelButton3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cancelButton3ActionPerformed
        tiePopUp.setVisible(false);
    }//GEN-LAST:event_cancelButton3ActionPerformed

    private void cancelSettingsButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cancelSettingsButtonActionPerformed
        selectPanel(WELCOME_PAGE, 0);
    }//GEN-LAST:event_cancelSettingsButtonActionPerformed

    private void settingsHandler(java.awt.event.ComponentEvent evt) {//GEN-FIRST:event_settingsHandler
        // TODO add your handling code here:
    }//GEN-LAST:event_settingsHandler

    private void theme0ButttonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_theme0ButttonActionPerformed
        chageTheme(THEME_0);
    }//GEN-LAST:event_theme0ButttonActionPerformed

    private void theme1ButttonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_theme1ButttonActionPerformed
        chageTheme(THEME_1);
    }//GEN-LAST:event_theme1ButttonActionPerformed

    private void theme2ButttonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_theme2ButttonActionPerformed
        chageTheme(THEME_2);
    }//GEN-LAST:event_theme2ButttonActionPerformed

    private void theme3ButttonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_theme3ButttonActionPerformed
        chageTheme(THEME_3);
    }//GEN-LAST:event_theme3ButttonActionPerformed

    private void theme4ButttonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_theme4ButttonActionPerformed
        chageTheme(THEME_4);
    }//GEN-LAST:event_theme4ButttonActionPerformed

    private void theme5ButttonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_theme5ButttonActionPerformed
        chageTheme(THEME_5);
    }//GEN-LAST:event_theme5ButttonActionPerformed

    private void theme6ButttonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_theme6ButttonActionPerformed
        chageTheme(THEME_6);
    }//GEN-LAST:event_theme6ButttonActionPerformed

    private void theme7ButttonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_theme7ButttonActionPerformed
        chageTheme(THEME_7);
    }//GEN-LAST:event_theme7ButttonActionPerformed

    private void deleteButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_deleteButtonActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_deleteButtonActionPerformed

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
    
    //<editor-fold defaultstate="collapsed" desc=" Variabili autogenerate ">
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton AIButton;
    private javax.swing.JButton addButton;
    private javax.swing.JButton backButton;
    private javax.swing.JLabel backgroundMenu;
    private javax.swing.JLabel bluePointTextField;
    private javax.swing.JLabel blueWinBackground;
    private javax.swing.JPanel blueWinPopUp;
    private javax.swing.JButton buttonBox1;
    private javax.swing.JButton buttonBox2;
    private javax.swing.JButton buttonBox3;
    private javax.swing.JButton buttonBox4;
    private javax.swing.JButton buttonBox5;
    private javax.swing.JButton buttonBox6;
    private javax.swing.JButton buttonBox7;
    private javax.swing.JButton buttonBox8;
    private javax.swing.JButton buttonBox9;
    private javax.swing.JButton cancelButton;
    private javax.swing.JButton cancelButton1;
    private javax.swing.JButton cancelButton2;
    private javax.swing.JButton cancelButton3;
    private javax.swing.JButton cancelSettingsButton;
    private javax.swing.JLabel chooseMode;
    private javax.swing.JLabel chooseTeamBackground;
    private javax.swing.JPanel chooseTeamPage;
    private javax.swing.JButton continueButton;
    private javax.swing.JButton continueButton1;
    private javax.swing.JButton continueButton2;
    private javax.swing.JButton deleteButton;
    private javax.swing.JPanel difficultyPage;
    private javax.swing.JLabel errorMessageBackground;
    private javax.swing.JPanel errorPopUp;
    private javax.swing.JButton friendButton;
    private javax.swing.JLabel gameBackground;
    private javax.swing.JPanel gamePage;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel loginBackground;
    private javax.swing.JPanel loginPage;
    private javax.swing.JLabel modeBackground;
    private javax.swing.JPanel modePage;
    private javax.swing.JLabel orText;
    private javax.swing.JLabel orText1;
    private javax.swing.JPasswordField passwordField;
    private javax.swing.JLabel popUpBackground;
    private javax.swing.JButton popUpCancelButton;
    private javax.swing.JLabel popUpMessage;
    private javax.swing.JPanel popUpPanel;
    private javax.swing.JLabel popUpTitle;
    private javax.swing.JLabel redPointTextField;
    private javax.swing.JLabel redWinBackground;
    private javax.swing.JPanel redWinPopUp;
    private javax.swing.JButton settingsButton;
    private javax.swing.JPanel settingsPage;
    private javax.swing.JRadioButton teamBlueButton;
    private javax.swing.ButtonGroup teamButtons;
    private javax.swing.JRadioButton teamRedButton;
    private javax.swing.JRadioButton theme0Buttton;
    private javax.swing.JRadioButton theme1Buttton;
    private javax.swing.JRadioButton theme2Buttton;
    private javax.swing.JRadioButton theme3Buttton;
    private javax.swing.JRadioButton theme4Buttton;
    private javax.swing.JRadioButton theme5Buttton;
    private javax.swing.JRadioButton theme6Buttton;
    private javax.swing.JRadioButton theme7Buttton;
    private javax.swing.ButtonGroup themeButtons;
    private javax.swing.JLabel tieBackground;
    private javax.swing.JPanel tiePopUp;
    private javax.swing.JTextField usernameTextField;
    private javax.swing.JLabel welcomeBackground;
    private javax.swing.JPanel welcomePage;
    // End of variables declaration//GEN-END:variables
    //</editor-fold>
}
