package compagniaaerea;

import java.awt.Color;
import java.awt.Cursor;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.net.URL;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import javax.swing.GroupLayout;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;
import javax.swing.JToggleButton;
import javax.swing.SwingConstants;
import javax.swing.Timer;
import javax.swing.WindowConstants;
import org.netbeans.lib.awtextra.AbsoluteConstraints;
import org.netbeans.lib.awtextra.AbsoluteLayout;

/**
 *
 * @author joels
 */
public class CompagniaAereaGUI extends javax.swing.JFrame {

    //<editor-fold defaultstate="collapsed" desc=" Costanti ">
    // Costanti per i nomi dei file e delle risorse predefinite
    private static final String FILENAME_LM = "credentials.dat";
    private static final String DEFAULT_USERNAME = "admin";
    private static final String DEFAULT_PASSWORD = "admin";
    private static final boolean DEFAULT_TYPE = false;

    // Costanti per le schermate del programma
    private static final int MAIN = 0;
    private static final int LOGIN = 1;
    private static final int MENU = 2;
    private static final int CAS_TICKET_BOARDING = 0;
    private static final int CAS_MANAGE_TICKETS = 1;
    private static final int CAS_MANAGE_FLIGHT = 2;
    private static final int CAS_SETTINGS = 3;

    // Costanti per i codici d'errore della password
    private static final int PASSWORD_SECURE = 0;
    private static final int PASSWORD_TOO_SHORT = 1;
    private static final int MISSING_UPPERCASE = 2;
    private static final int MISSING_LOWERCASE = 3;
    private static final int MISSING_NUMBER = 4;
    private static final int MISSING_SPECIAL_CHARACTER = 5;
    private static final int USERNAME_USED = 6;

    // Costanti per i messaggi d'errore
    public static final String ERROR_MESSAGE = "Errore";
    public static final String ERROR_PASSWORD_TOO_SHORT = "<html><p align=\"center\">La password deve contenere almeno <b>8 caratteri</b>.</p></html>";
    public static final String ERROR_MISSING_UPPERCASE = "<html><p align=\"center\">La password deve contenere almeno una <b>lettera maiuscola</b>.</p></html>";
    public static final String ERROR_MISSING_LOWERCASE = "<html><p align=\"center\">La password deve contenere almeno una <b>lettera minuscola</b>.</p></html>";
    public static final String ERROR_MISSING_NUMBER = "<html><p align=\"center\">La password deve contenere <br>almeno un <b>numero</b>.</p></html>";
    public static final String ERROR_MISSING_SPECIAL_CHARACTER = "<html><p align=\"center\">La password deve contenere almeno un <b>carattere speciale</b>.</p></html>";
    public static final String ERROR_UNKNOWN = "<html><p align=\"center\"><b>Errore sconosciuto</b> nella validazione della password.</p></html>";
    public static final String ERROR_USERNAME_USED = "<html><p align=\"center\"><Username<b> già in uso.</b></p></html>";
    private static final String ERROR_WRONG_CREDENTIALS = "<html>Username o Password <b>sbagliati</b>.</html>";

    // Costanti per i messaggi di successo
    public static final String MESSAGE_PASSWORD_SECURE = "<html>Password <b>inserita</b> con successo.</html>";
    public static final String MESSAGE_RIGHT_CREDENTIALS = "<html>Combinazione <b>trovata</b>.</html>";
    public static final String SUCCESS_MESSAGE = "Successo";

    // Costanti per gli sfondi
    public static final String ERROR_BACKGROUND = "error_message.png";
    public static final String SUCCESS_BACKGROUND = "success_message.png";

    // Costanti per il timer
    public static final int TIMER_MESSAGE = 1600;

    // Costanti per gli effetti sonori
    public static final String ERROR_SOUND = "error.wav";
    public static final String SUCCESS_SOUND = "success.wav";
    //</editor-fold>

    // Variabili flag
    public boolean admin_flag = false;
    public boolean login_flag = false;
    public boolean runningAnimation = false;

    public String username = "";

    CompagniaAereaSchermataGUI caschermataGUI;
    LoginManager loginManager;

    public CompagniaAereaGUI() {
        initComponents();

        selectPannel(MAIN); //imposto la schermata di benvenuto, uitle per bypassare il login per debug
        popUp_pannel.setVisible(false); //metto il messaggio d'errore come invisibile

        // Inizializzazione del CAS, LM e CAM
        caschermataGUI = new CompagniaAereaSchermataGUI();
        loginManager = new LoginManager(FILENAME_LM, DEFAULT_USERNAME, DEFAULT_PASSWORD, DEFAULT_TYPE);

        // Passo questa istanza a CAS
        caschermataGUI.setOldFrame(this);
        caschermataGUI.setLoginManager(loginManager);
    }

    // Metodo per verificare se l'utente è loggato
    public boolean isLoginFlag() {
        return login_flag; // il flag indica se l'utente è loggato o meno
    }

    public boolean isAdmin() {
        return admin_flag;
    }

    // Metodo per ottenere il nome utente
    public String getUsername() {
        return username;
    }

    // Metodo per ottenere il nome del file delle credenziali
    public static String getFILENAME_LM() {
        return FILENAME_LM;
    }

    // Metodo per impostare il Login Manager
    public void setLoginManager(LoginManager loginManager) {
        this.loginManager = loginManager; // Imposta il gestore delle credenziali
    }

    // Metodo per mostrare un messaggio personalizzato:
    /*Il background è il nome della foto per lo sfondo, message è il messaggio stampato sulla GUI, il textcolor è il colore del titolo, 
      sound è il nome del suono da trasmettere e flagLoop è un flag che serve se si vuole che il suono venga ripetuto all'infinito*/
    public void personalizedMessage(String background, String message, Color textColor, String sound, boolean flagLoop) {
        popUp_background.setIcon(new ImageIcon(getClass().getResource("/photo/" + background)));
        popUp_title.setText(message);
        popUp_title.setForeground(textColor);
        play(sound, flagLoop);
    }

    // Metodo per mostrare un pop-up con un messaggio
    /*in pannel bisogna inserire il pannelo da far vedere, delay è la durata del popUp a schermo, message è il messaggio stampa a schermo
    nella GUI, errorFlag identifica se è un messaggio d'errore e no*/
    public void messagePopUp(JPanel pannel, int duration, boolean flagLoop, String message, boolean errorFlag) {
        System.out.println("[CA] Animazione iniziata.");

        if (runningAnimation) {
            System.out.println("[CA] Animazione in corso. Ignorando richiesta...");
            return; // Ignora la richiesta se un'animazione è già in corso
        }

        // Imposta il flag per indicare che un'animazione è in corso
        runningAnimation = true;

        if (errorFlag) {
            personalizedMessage(ERROR_BACKGROUND, ERROR_MESSAGE, Color.RED, ERROR_SOUND, flagLoop);
        } else {
            personalizedMessage(SUCCESS_BACKGROUND, SUCCESS_MESSAGE, Color.GREEN, SUCCESS_SOUND, flagLoop);
        }

        popUp_message.setText(message);

        pannel.setVisible(true);

        Timer timer = new Timer(duration, new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                pannel.setVisible(false);
                // Imposta il flag per indicare che l'animazione è stata completata
                runningAnimation = false;
            }
        });

        /* Senza timer.setRepeats(false);, il timer continuerebbe a scattare ogni volta che viene premuto il pulsante, 
        causando un accumulo di timer che si eseguivano simultaneamente, accorciando così la durata effettiva dell'
        animazione ad ogni pressione del pulsante.*/
        timer.setRepeats(false);
        timer.start();
    }

    // Metodo per riprodurre un suono
    /*in path si inserisce il nome del file wav, bisogna metterlo nella cartella "fsx_effect", e il flag loop è se vogliamo che il suono si ripeta all'infinito,
      utile per musiche di sottofondo*/
    public static void play(String path, boolean loop) { //usate il tipo WAV, metodo non mio tengo a precisare. (convertitore: https://convertio.co/it/mp3-wav/ )
        try {
            URL url = CompagniaAereaGUI.class.getResource("/fsx_effect/" + path);
            if (url != null) {
                AudioInputStream audioInput = AudioSystem.getAudioInputStream(url);
                Clip clip = AudioSystem.getClip();
                clip.open(audioInput);
                clip.start();
                if (loop) {
                    clip.loop(Clip.LOOP_CONTINUOUSLY);
                }
            } else {
                System.err.println("[CA] Errore: file audio non esistente");
            }
        } catch (Exception e) {
            System.err.println("[CA] Errore nella riproduzione audio");
        }
    }

    // Metodo per selezionare il pannello da visualizzare
    /*Le costanti sono in alto ma: MAIN è la schermata principale, LOGIN.. quella di login e MENU è la dashboard. piuttosto semplice*/
    public void selectPannel(int choice) {
        System.out.println("[CA] Pannello caricato: " + choice);
        this.setVisible(true); //cosi è visibile se vengo dal CAS

        // Imposta tutti i pannelli su false
        main_pannel.setVisible(false);
        login_pannel.setVisible(false);
        menu_pannel.setVisible(false);

        // Attiva il pannello scelto
        switch (choice) {
            case MAIN:
                main_pannel.setVisible(true);
                break;
            case LOGIN:
                login_pannel.setVisible(true);
                break;
            case MENU:
                menu_pannel.setVisible(true);
                username_label.setText(username);
                break;
            default:
                main_pannel.setVisible(true); //gestisco l'eccezione riportando l'utente alla schermata principale
                System.err.println("[CA] Errore: scelta del pannello non valida"); //in caso 
                break;
        }
    }

    // Metodo per gestire la selezione del pannello CAS
    /* il metodo in se per se mi serve per non ripetere codice, serve per passare da un jFrame all'altro.
      choise è il pannello d'uscita del istanza CAS  e il flag e se vogliamo rendere invisibile o meno attuale istanza. */
    public void pannelCAS(int choise, boolean flag) {
        System.out.println("[CA] Caricando il pannello: " + choise);
        caschermataGUI.selectPannel(choise);
        this.setVisible(flag);
    }

    // Metodo per impostare il tipo di utente (admin o user)
    private void setTypeUser(boolean isAdmin) {
        System.out.println("[CA] Tipologia utente admin: " + isAdmin + ".");

        admin_flag = isAdmin;
        settings_button.setEnabled(isAdmin);
        ticket_canc_button.setEnabled(isAdmin);

        String userType = isAdmin ? "admin" : "user";
        user_type_icon.setIcon(new ImageIcon(getClass().getResource("/photo/" + userType + "_icon.png")));
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
                System.err.println("[CA] Codice errore sconosciuto: " + errorCode);
                break;
        }
        return errorMessage;
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        login_pannel = new JPanel();
        arrow_button_login = new JToggleButton();
        register_button = new JButton();
        popUp_pannel = new JPanel();
        popUp_message = new JLabel();
        popUp_title = new JLabel();
        popUp_background = new JLabel();
        companyName_label = new JLabel();
        login_label = new JLabel();
        username_textfield = new JTextField();
        password_textfield = new JPasswordField();
        login_photo = new JLabel();
        main_pannel = new JPanel();
        welcome_label = new JLabel();
        arrow_button_main = new JToggleButton();
        main_photo = new JLabel();
        menu_pannel = new JPanel();
        ticket_boarding_button = new JButton();
        ticket_canc_button = new JButton();
        settings_button = new JButton();
        log_out_button1 = new JButton();
        manage_flight_button = new JButton();
        user_type_icon = new JLabel();
        username_label = new JLabel();
        LO_label = new JLabel();
        S_label = new JLabel();
        TB_label = new JLabel();
        MP_label1 = new JLabel();
        TC_label2 = new JLabel();
        dashboard_label = new JLabel();
        menu_photo = new JLabel();

        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setTitle(" Joel AirLine");
        setIconImages(null);
        setMinimumSize(new Dimension(420, 753));
        setResizable(false);

        login_pannel.setMaximumSize(new Dimension(420, 753));
        login_pannel.setMinimumSize(new Dimension(420, 753));
        login_pannel.setName(""); // NOI18N
        login_pannel.setRequestFocusEnabled(false);
        login_pannel.setLayout(null);

        arrow_button_login.setForeground(new Color(255, 255, 255));
        arrow_button_login.setIcon(new ImageIcon(getClass().getResource("/photo/arrow.png"))); // NOI18N
        arrow_button_login.setAutoscrolls(true);
        arrow_button_login.setContentAreaFilled(false);
        arrow_button_login.setCursor(new Cursor(Cursor.HAND_CURSOR));
        arrow_button_login.setHorizontalTextPosition(SwingConstants.CENTER);
        arrow_button_login.setPressedIcon(new ImageIcon(getClass().getResource("/photo/arrow_p.png"))); // NOI18N
        arrow_button_login.setRolloverIcon(new ImageIcon(getClass().getResource("/photo/arrow_r.png"))); // NOI18N
        arrow_button_login.setRolloverSelectedIcon(new ImageIcon(getClass().getResource("/photo/arrow_pr.png"))); // NOI18N
        arrow_button_login.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                arrow_button_loginActionPerformed(evt);
            }
        });
        login_pannel.add(arrow_button_login);
        arrow_button_login.setBounds(70, 600, 170, 80);

        register_button.setIcon(new ImageIcon(getClass().getResource("/photo/signup_button.png"))); // NOI18N
        register_button.setContentAreaFilled(false);
        register_button.setHorizontalTextPosition(SwingConstants.CENTER);
        register_button.setPressedIcon(new ImageIcon(getClass().getResource("/photo/signup_button_p.png"))); // NOI18N
        register_button.setSelectedIcon(new ImageIcon(getClass().getResource("/photo/signup_button_r.png"))); // NOI18N
        register_button.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                register_buttonActionPerformed(evt);
            }
        });
        login_pannel.add(register_button);
        register_button.setBounds(250, 600, 98, 80);

        popUp_pannel.setOpaque(false);
        popUp_pannel.setLayout(new AbsoluteLayout());

        popUp_message.setFont(new Font("Courier New", 0, 18)); // NOI18N
        popUp_message.setHorizontalAlignment(SwingConstants.CENTER);
        popUp_message.setText("*messaggio d'errore*");
        popUp_pannel.add(popUp_message, new AbsoluteConstraints(15, 124, 361, -1));

        popUp_title.setFont(new Font("Courier New", 1, 30)); // NOI18N
        popUp_title.setForeground(new Color(255, 0, 0));
        popUp_title.setHorizontalAlignment(SwingConstants.CENTER);
        popUp_title.setText("Errore");
        popUp_pannel.add(popUp_title, new AbsoluteConstraints(15, 95, 361, -1));

        popUp_background.setHorizontalAlignment(SwingConstants.CENTER);
        popUp_background.setIcon(new ImageIcon(getClass().getResource("/photo/error_message.png"))); // NOI18N
        popUp_pannel.add(popUp_background, new AbsoluteConstraints(0, 0, -1, 240));

        login_pannel.add(popUp_pannel);
        popUp_pannel.setBounds(14, 285, 391, 240);

        companyName_label.setFont(new Font("Courier New", 1, 36)); // NOI18N
        companyName_label.setHorizontalAlignment(SwingConstants.CENTER);
        companyName_label.setText("Royal Airlines");
        login_pannel.add(companyName_label);
        companyName_label.setBounds(60, 210, 340, 60);

        login_label.setFont(new Font("Courier New", 0, 36)); // NOI18N
        login_label.setHorizontalAlignment(SwingConstants.CENTER);
        login_label.setText("Login");
        login_pannel.add(login_label);
        login_label.setBounds(20, 280, 380, 60);

        username_textfield.setBackground(new Color(232, 231, 231));
        username_textfield.setFont(new Font("Courier New", 0, 14)); // NOI18N
        username_textfield.setHorizontalAlignment(JTextField.LEFT);
        username_textfield.setText("Username");
        username_textfield.setBorder(null);
        username_textfield.setSelectedTextColor(new Color(0, 0, 0));
        username_textfield.setSelectionColor(new Color(0, 153, 102));
        username_textfield.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                username_textfieldActionPerformed(evt);
            }
        });
        login_pannel.add(username_textfield);
        username_textfield.setBounds(120, 370, 250, 30);

        password_textfield.setBackground(new Color(232, 231, 231));
        password_textfield.setFont(new Font("Segoe UI", 0, 14)); // NOI18N
        password_textfield.setText("Password");
        password_textfield.setBorder(null);
        password_textfield.setEchoChar('\u25cf');
        password_textfield.setName(""); // NOI18N
        password_textfield.setSelectionColor(new Color(0, 102, 102));
        login_pannel.add(password_textfield);
        password_textfield.setBounds(120, 437, 250, 30);

        login_photo.setHorizontalAlignment(SwingConstants.CENTER);
        login_photo.setIcon(new ImageIcon(getClass().getResource("/photo/login_page.png"))); // NOI18N
        login_pannel.add(login_photo);
        login_photo.setBounds(0, 0, 420, 753);

        main_pannel.setMaximumSize(new Dimension(420, 753));
        main_pannel.setMinimumSize(new Dimension(420, 753));
        main_pannel.setName(""); // NOI18N
        main_pannel.setPreferredSize(new Dimension(420, 753));
        main_pannel.setLayout(null);

        welcome_label.setFont(new Font("Courier New", 0, 36)); // NOI18N
        welcome_label.setHorizontalAlignment(SwingConstants.CENTER);
        welcome_label.setText("<html> <p align=\"center\"> Welcome to <br> <b>Royal Airline</b> </p) </html>");
        main_pannel.add(welcome_label);
        welcome_label.setBounds(0, 320, 420, 170);

        arrow_button_main.setForeground(new Color(255, 255, 255));
        arrow_button_main.setIcon(new ImageIcon(getClass().getResource("/photo/arrow.png"))); // NOI18N
        arrow_button_main.setAutoscrolls(true);
        arrow_button_main.setContentAreaFilled(false);
        arrow_button_main.setCursor(new Cursor(Cursor.HAND_CURSOR));
        arrow_button_main.setHorizontalTextPosition(SwingConstants.CENTER);
        arrow_button_main.setRolloverIcon(new ImageIcon(getClass().getResource("/photo/arrow_r.png"))); // NOI18N
        arrow_button_main.setRolloverSelectedIcon(new ImageIcon(getClass().getResource("/photo/arrow_pr.png"))); // NOI18N
        arrow_button_main.setSelectedIcon(new ImageIcon(getClass().getResource("/photo/arrow_p.png"))); // NOI18N
        arrow_button_main.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                arrow_button_mainActionPerformed(evt);
            }
        });
        main_pannel.add(arrow_button_main);
        arrow_button_main.setBounds(130, 610, 170, 80);

        main_photo.setHorizontalAlignment(SwingConstants.CENTER);
        main_photo.setIcon(new ImageIcon(getClass().getResource("/photo/main.png"))); // NOI18N
        main_pannel.add(main_photo);
        main_photo.setBounds(0, 0, 420, 753);

        menu_pannel.setMaximumSize(new Dimension(420, 753));
        menu_pannel.setMinimumSize(new Dimension(420, 753));
        menu_pannel.setLayout(null);

        ticket_boarding_button.setIcon(new ImageIcon(getClass().getResource("/photo/plane-ticket.png"))); // NOI18N
        ticket_boarding_button.setContentAreaFilled(false);
        ticket_boarding_button.setCursor(new Cursor(Cursor.HAND_CURSOR));
        ticket_boarding_button.setMaximumSize(new Dimension(50, 50));
        ticket_boarding_button.setMinimumSize(new Dimension(50, 50));
        ticket_boarding_button.setPreferredSize(new Dimension(50, 50));
        ticket_boarding_button.setPressedIcon(new ImageIcon(getClass().getResource("/photo/plane-ticket_P.png"))); // NOI18N
        ticket_boarding_button.setRolloverIcon(new ImageIcon(getClass().getResource("/photo/plane-ticket_B.png"))); // NOI18N
        ticket_boarding_button.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                ticket_boarding_buttonActionPerformed(evt);
            }
        });
        menu_pannel.add(ticket_boarding_button);
        ticket_boarding_button.setBounds(15, 250, 75, 55);

        ticket_canc_button.setIcon(new ImageIcon(getClass().getResource("/photo/manage_tickets.png"))); // NOI18N
        ticket_canc_button.setContentAreaFilled(false);
        ticket_canc_button.setCursor(new Cursor(Cursor.HAND_CURSOR));
        ticket_canc_button.setDisabledIcon(new ImageIcon(getClass().getResource("/photo/manage_tickets_D.png"))); // NOI18N
        ticket_canc_button.setPressedIcon(new ImageIcon(getClass().getResource("/photo/manage_tickets_P.png"))); // NOI18N
        ticket_canc_button.setRolloverIcon(new ImageIcon(getClass().getResource("/photo/manage_tickets_B.png"))); // NOI18N
        ticket_canc_button.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                ticket_canc_buttonActionPerformed(evt);
            }
        });
        menu_pannel.add(ticket_canc_button);
        ticket_canc_button.setBounds(15, 405, 75, 50);

        settings_button.setIcon(new ImageIcon(getClass().getResource("/photo/setting_icon.png"))); // NOI18N
        settings_button.setContentAreaFilled(false);
        settings_button.setCursor(new Cursor(Cursor.HAND_CURSOR));
        settings_button.setDisabledIcon(new ImageIcon(getClass().getResource("/photo/setting_icon_D.png"))); // NOI18N
        settings_button.setHorizontalTextPosition(SwingConstants.CENTER);
        settings_button.setPressedIcon(new ImageIcon(getClass().getResource("/photo/setting_icon_P.png"))); // NOI18N
        settings_button.setRolloverIcon(new ImageIcon(getClass().getResource("/photo/setting_icon_B.png"))); // NOI18N
        settings_button.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                settings_buttonActionPerformed(evt);
            }
        });
        menu_pannel.add(settings_button);
        settings_button.setBounds(15, 470, 75, 60);

        log_out_button1.setIcon(new ImageIcon(getClass().getResource("/photo/remove.png"))); // NOI18N
        log_out_button1.setContentAreaFilled(false);
        log_out_button1.setCursor(new Cursor(Cursor.HAND_CURSOR));
        log_out_button1.setHorizontalTextPosition(SwingConstants.CENTER);
        log_out_button1.setPressedIcon(new ImageIcon(getClass().getResource("/photo/remove_P.png"))); // NOI18N
        log_out_button1.setRolloverIcon(new ImageIcon(getClass().getResource("/photo/remove_B.png"))); // NOI18N
        log_out_button1.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                log_out_button1ActionPerformed(evt);
            }
        });
        menu_pannel.add(log_out_button1);
        log_out_button1.setBounds(15, 550, 75, 60);

        manage_flight_button.setIcon(new ImageIcon(getClass().getResource("/photo/booking.png"))); // NOI18N
        manage_flight_button.setContentAreaFilled(false);
        manage_flight_button.setCursor(new Cursor(Cursor.HAND_CURSOR));
        manage_flight_button.setPressedIcon(new ImageIcon(getClass().getResource("/photo/booking_P.png"))); // NOI18N
        manage_flight_button.setRolloverIcon(new ImageIcon(getClass().getResource("/photo/booking_B.png"))); // NOI18N
        manage_flight_button.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                manage_flight_buttonActionPerformed(evt);
            }
        });
        menu_pannel.add(manage_flight_button);
        manage_flight_button.setBounds(25, 320, 60, 50);

        user_type_icon.setIcon(new ImageIcon(getClass().getResource("/photo/user_icon.png"))); // NOI18N
        user_type_icon.setText("user_type_icon");
        menu_pannel.add(user_type_icon);
        user_type_icon.setBounds(100, 130, 50, 50);

        username_label.setFont(new Font("Courier New", 0, 30)); // NOI18N
        username_label.setHorizontalAlignment(SwingConstants.CENTER);
        username_label.setText("Username");
        menu_pannel.add(username_label);
        username_label.setBounds(130, 120, 220, 60);

        LO_label.setBackground(new Color(204, 0, 0));
        LO_label.setFont(new Font("Courier New", 1, 30)); // NOI18N
        LO_label.setForeground(new Color(204, 0, 0));
        LO_label.setHorizontalAlignment(SwingConstants.CENTER);
        LO_label.setText("Log Out");
        menu_pannel.add(LO_label);
        LO_label.setBounds(100, 560, 140, 30);

        S_label.setBackground(new Color(204, 0, 0));
        S_label.setFont(new Font("Courier New", 0, 30)); // NOI18N
        S_label.setHorizontalAlignment(SwingConstants.CENTER);
        S_label.setText("Settings");
        menu_pannel.add(S_label);
        S_label.setBounds(100, 480, 155, 30);

        TB_label.setFont(new Font("Courier New", 0, 30)); // NOI18N
        TB_label.setHorizontalAlignment(SwingConstants.CENTER);
        TB_label.setText("T. Boarding");
        menu_pannel.add(TB_label);
        TB_label.setBounds(100, 240, 220, 60);

        MP_label1.setFont(new Font("Courier New", 0, 30)); // NOI18N
        MP_label1.setHorizontalAlignment(SwingConstants.CENTER);
        MP_label1.setText("Flight Listing");
        menu_pannel.add(MP_label1);
        MP_label1.setBounds(100, 320, 260, 60);

        TC_label2.setFont(new Font("Courier New", 0, 30)); // NOI18N
        TC_label2.setHorizontalAlignment(SwingConstants.CENTER);
        TC_label2.setText("Manage Tickets");
        menu_pannel.add(TC_label2);
        TC_label2.setBounds(100, 400, 270, 60);

        dashboard_label.setFont(new Font("Courier New", 1, 36)); // NOI18N
        dashboard_label.setHorizontalAlignment(SwingConstants.CENTER);
        dashboard_label.setText("Dashbord");
        menu_pannel.add(dashboard_label);
        dashboard_label.setBounds(40, 50, 350, 70);

        menu_photo.setHorizontalAlignment(SwingConstants.CENTER);
        menu_photo.setIcon(new ImageIcon(getClass().getResource("/photo/menu.png"))); // NOI18N
        menu_pannel.add(menu_photo);
        menu_photo.setBounds(0, 0, 420, 753);

        GroupLayout layout = new GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(layout.createParallelGroup(GroupLayout.Alignment.LEADING)
            .addGap(0, 420, Short.MAX_VALUE)
            .addGroup(layout.createParallelGroup(GroupLayout.Alignment.LEADING)
                .addGroup(layout.createSequentialGroup()
                    .addGap(0, 0, Short.MAX_VALUE)
                    .addComponent(menu_pannel, GroupLayout.PREFERRED_SIZE, 420, GroupLayout.PREFERRED_SIZE)
                    .addGap(0, 0, Short.MAX_VALUE)))
            .addGroup(layout.createParallelGroup(GroupLayout.Alignment.LEADING)
                .addGroup(layout.createSequentialGroup()
                    .addGap(0, 0, Short.MAX_VALUE)
                    .addComponent(main_pannel, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE)
                    .addGap(0, 0, Short.MAX_VALUE)))
            .addGroup(layout.createParallelGroup(GroupLayout.Alignment.LEADING)
                .addGroup(layout.createSequentialGroup()
                    .addGap(0, 0, Short.MAX_VALUE)
                    .addComponent(login_pannel, GroupLayout.PREFERRED_SIZE, 420, GroupLayout.PREFERRED_SIZE)
                    .addGap(0, 0, Short.MAX_VALUE)))
        );
        layout.setVerticalGroup(layout.createParallelGroup(GroupLayout.Alignment.LEADING)
            .addGap(0, 753, Short.MAX_VALUE)
            .addGroup(layout.createParallelGroup(GroupLayout.Alignment.LEADING)
                .addGroup(layout.createSequentialGroup()
                    .addGap(0, 0, Short.MAX_VALUE)
                    .addComponent(menu_pannel, GroupLayout.PREFERRED_SIZE, 753, GroupLayout.PREFERRED_SIZE)
                    .addGap(0, 0, Short.MAX_VALUE)))
            .addGroup(layout.createParallelGroup(GroupLayout.Alignment.LEADING)
                .addGroup(layout.createSequentialGroup()
                    .addGap(0, 0, Short.MAX_VALUE)
                    .addComponent(main_pannel, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE)
                    .addGap(0, 0, Short.MAX_VALUE)))
            .addGroup(layout.createParallelGroup(GroupLayout.Alignment.LEADING)
                .addGroup(layout.createSequentialGroup()
                    .addGap(0, 0, Short.MAX_VALUE)
                    .addComponent(login_pannel, GroupLayout.PREFERRED_SIZE, 753, GroupLayout.PREFERRED_SIZE)
                    .addGap(0, 0, Short.MAX_VALUE)))
        );

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void arrow_button_loginActionPerformed(ActionEvent evt) {//GEN-FIRST:event_arrow_button_loginActionPerformed
        // Ottieni l'username e la password inseriti dall'utente
        String enteredUsername = username_textfield.getText();
        String enteredPassword = password_textfield.getText();

        // Verifica se le credenziali sono valide utilizzando il gestore del login
        boolean credentialsValid = loginManager.checkCredentials(enteredUsername, enteredPassword);

        // Se le credenziali sono valide
        if (credentialsValid) {
            // Visualizza una notifica di credenziali corrette
            messagePopUp(popUp_pannel, TIMER_MESSAGE, false, MESSAGE_RIGHT_CREDENTIALS, false);

            // Imposta il tipo di utente (admin o user)
            setTypeUser(loginManager.isAdmin(enteredUsername));

            // Avvia un timer per selezionare il pannello della dashboard dopo un breve ritardo
            Timer timerSelectPannel = new Timer(TIMER_MESSAGE, new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    selectPannel(2); // passo alla dashboard
                    ((Timer) e.getSource()).stop();
                }
            });
            timerSelectPannel.start();

            // Memorizza l'username dell'utente corrente
            username = enteredUsername;

            // Reimposta i campi di inserimento dell'username e della password ai valori predefiniti
            username_textfield.setText("Username");
            password_textfield.setText("Password");

            // Imposta il flag di login su true
            login_flag = true;

        } else {
            // Se le credenziali non sono valide, visualizza un messaggio di errore
            messagePopUp(popUp_pannel, TIMER_MESSAGE, false, ERROR_WRONG_CREDENTIALS, true);

            // Imposta il flag di login su false
            login_flag = false;
        }

    }//GEN-LAST:event_arrow_button_loginActionPerformed

    private void username_textfieldActionPerformed(ActionEvent evt) {//GEN-FIRST:event_username_textfieldActionPerformed

    }//GEN-LAST:event_username_textfieldActionPerformed

    private void ticket_canc_buttonActionPerformed(ActionEvent evt) {//GEN-FIRST:event_ticket_canc_buttonActionPerformed
        pannelCAS(CAS_MANAGE_TICKETS, false);
    }//GEN-LAST:event_ticket_canc_buttonActionPerformed

    private void arrow_button_mainActionPerformed(ActionEvent evt) {//GEN-FIRST:event_arrow_button_mainActionPerformed
        selectPannel(LOGIN);
    }//GEN-LAST:event_arrow_button_mainActionPerformed

    private void settings_buttonActionPerformed(ActionEvent evt) {//GEN-FIRST:event_settings_buttonActionPerformed
        pannelCAS(CAS_SETTINGS, false);
    }//GEN-LAST:event_settings_buttonActionPerformed

    private void manage_flight_buttonActionPerformed(ActionEvent evt) {//GEN-FIRST:event_manage_flight_buttonActionPerformed
        pannelCAS(CAS_MANAGE_FLIGHT, false);
    }//GEN-LAST:event_manage_flight_buttonActionPerformed

    private void log_out_button1ActionPerformed(ActionEvent evt) {//GEN-FIRST:event_log_out_button1ActionPerformed
        selectPannel(LOGIN);
    }//GEN-LAST:event_log_out_button1ActionPerformed

    private void ticket_boarding_buttonActionPerformed(ActionEvent evt) {//GEN-FIRST:event_ticket_boarding_buttonActionPerformed
        pannelCAS(CAS_TICKET_BOARDING, false);
    }//GEN-LAST:event_ticket_boarding_buttonActionPerformed

    private void register_buttonActionPerformed(ActionEvent evt) {//GEN-FIRST:event_register_buttonActionPerformed
        // Ottiene l'username inserito dall'utente
        String enteredUsername = username_textfield.getText();
        // Ottiene la password inserita dall'utente
        String enteredPassword = password_textfield.getText();

        // Verifica la sicurezza della password
        int passwordSecure = loginManager.isPasswordSecure(enteredPassword);
        // Ottiene il messaggio di errore relativo alla sicurezza della password
        String errorMessage = displayPasswordErrorMessage(passwordSecure);

        // Verifica se la password non è sicura o se l'username esiste già nel sistema
        if (passwordSecure != PASSWORD_SECURE || loginManager.isUsernameExists(enteredUsername)) {
            // Visualizza il messaggio di errore relativo alla password
            displayPasswordErrorMessage(passwordSecure);
            // Visualizza una finestra pop-up con il messaggio di errore
            messagePopUp(popUp_pannel, TIMER_MESSAGE, false, errorMessage, true);
        } else {
            // Aggiunge le credenziali all'utente nel sistema
            loginManager.addCredentials(enteredUsername, enteredPassword, false);
            // Visualizza un messaggio di conferma
            messagePopUp(popUp_pannel, TIMER_MESSAGE, false, MESSAGE_PASSWORD_SECURE, false);
        }    
    }//GEN-LAST:event_register_buttonActionPerformed

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
            java.util.logging.Logger.getLogger(CompagniaAereaGUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(CompagniaAereaGUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(CompagniaAereaGUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(CompagniaAereaGUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>
        //</editor-fold>
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new CompagniaAereaGUI().setVisible(true);
            }
        });
    }

    //<editor-fold defaultstate="collapsed" desc=" Variables declaration - do not modify  ">
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private JLabel LO_label;
    private JLabel MP_label1;
    private JLabel S_label;
    private JLabel TB_label;
    private JLabel TC_label2;
    private JToggleButton arrow_button_login;
    private JToggleButton arrow_button_main;
    private JLabel companyName_label;
    private JLabel dashboard_label;
    private JButton log_out_button1;
    private JLabel login_label;
    private JPanel login_pannel;
    private JLabel login_photo;
    private JPanel main_pannel;
    private JLabel main_photo;
    private JButton manage_flight_button;
    private JPanel menu_pannel;
    private JLabel menu_photo;
    private JPasswordField password_textfield;
    private JLabel popUp_background;
    private JLabel popUp_message;
    private JPanel popUp_pannel;
    private JLabel popUp_title;
    private JButton register_button;
    private JButton settings_button;
    private JButton ticket_boarding_button;
    private JButton ticket_canc_button;
    private JLabel user_type_icon;
    private JLabel username_label;
    private JTextField username_textfield;
    private JLabel welcome_label;
    // End of variables declaration//GEN-END:variables
    //</editor-fold>
}
