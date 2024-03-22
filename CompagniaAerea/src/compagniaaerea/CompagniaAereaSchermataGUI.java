package compagniaaerea;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.util.ArrayList;
import java.util.List;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JOptionPane;
import javax.swing.JTable;
import javax.swing.Timer;
import javax.swing.table.DefaultTableModel;

/**
 *
 * @author joels
 */
public class CompagniaAereaSchermataGUI extends javax.swing.JFrame {
    //<editor-fold defaultstate="collapsed" desc=" Costanti ">
    // Costanti per CAS (Computer Assisted Security):
    private static final int CAS_TICKET_BOARDING = 0;
    private static final int CAS_MANAGE_TICKETS = 1;
    private static final int CAS_MANAGE_FLIGHT = 2;
    private static final int CAS_SETTINGS = 3;

    // Costanti per la selezione dei pannelli:
    private static final int MAIN = 0;
    private static final int LOGIN = 1;
    private static final int MENU = 2;

    // Costanti per i titoli dei messaggi:
    private static final String DELETE_CREDENTIALS_TITLE = "Conferma Eliminazione";
    private static final String DELETE_CREDENTIALS_MESSAGE = "Sei sicuro di volerle eliminare? Questo azione portera' la chiusura forzata dell'app";
    private static final String ERROR_EDIT_IMAGE = "edit_error.png";
    private static final String ERROR_ADD_IMAGE = "add_error.png";
    private static final String ERROR_SEARCH_IMAGE = "search_error.png";
    private static final String ERROR_DELETE_USER_IMAGE = "delete_user_error.png";
    private static final String ERROR_DELETE_IMAGE = "delete_error_settings.png";

    // Altre costanti:
    private static final int TIMER_ERROR = 1000;
    public static final String ERROR_SOUND = "error.wav";
    private static final String FILENAME_CAM = "company_data.dat"; // Costante per il nome del file

    //</editor-fold>

    //variabili
    private CompagniaAereaGUI compagniaAereaGUI;
    private CompagniaAereaManager compagnia;
    private LoginManager loginManager;
    
    //flag
    private boolean runningAnimation = false; // Flag per controllare se un'animazione è già in corso
    public boolean adminButtonFlag = false;

    public CompagniaAereaSchermataGUI() {
        initComponents();

        compagnia = new CompagniaAereaManager(FILENAME_CAM);

        compagnia.loadData();

        //this.setSize(858, 790); // non so perchè ma così è l'unico modo per farlo aprire con la giusta grandezza. 
        //mettendo valori sotto a quelli messi da me si rompe la grandezza, perchè? boh. (dovrebbe essere 845x753) 
        //edit: boh adesso va senza mettere la strana grandezza, non so che dire (sto impazzendo) ma lo lascio qui che non si sa mai
    }

    public void setLoginManager(LoginManager loginManager) {
        this.loginManager = loginManager;
    }

    public void refreshFlightTable(JTable table, boolean flagSeats) {
        DefaultTableModel model = (DefaultTableModel) table.getModel(); // Ottiene il modello della tabella

        // Rimuove tutte le righe esistenti dalla tabella
        while (model.getRowCount() > 0) {
            model.removeRow(0);
        }

        // Ottiene la lista degli aerei dalla compagnia aerea
        ArrayList<Flight> flights = compagnia.getFlights();

        // Verifica se la lista degli aerei è vuota
        if (flights.isEmpty()) {
            System.out.println("[CAS] Lista degli aerei vuota. Nessuna riga aggiunta alla tabella.");
            return; // Esci dal metodo se la lista degli aerei è vuota
        }

        // Itera attraverso la lista degli aerei e aggiunge le informazioni di ciascun aereo alla tabella
        for (Flight flight : flights) {

            // Ottiene il numero di posti rimanenti per questo volo se il flag è attivo.
            int Seats = flagSeats ? compagnia.getAvailableSeats(flight.getFlightCode()) : flight.getNSeats();
            model.addRow(new Object[]{flight.getFlightCode(), flight.getSource(), flight.getDestination(), flight.getTakeOff(), Seats});
        }
    }

    public void refreshTicketTable(JTable table) {
        DefaultTableModel model = (DefaultTableModel) table.getModel(); // Ottiene il modello della tabella

        // Rimuove tutte le righe esistenti dalla tabella
        while (model.getRowCount() > 0) {
            model.removeRow(0);
        }

        // Ottiene la lista dei biglietti dalla compagnia aerea
        ArrayList<Ticket> tickets = compagnia.getUserTickets(compagniaAereaGUI.getUsername());

        // Verifica se la lista dei biglietti è vuota
        if (tickets.isEmpty()) {
            System.out.println("[CAM] Lista dei biglietti vuota. Nessuna riga aggiunta alla tabella.");
            return; // Esci dal metodo se la lista dei biglietti è vuota
        }

        // Itera attraverso la lista dei biglietti e aggiunge le informazioni di ciascun biglietto alla tabella
        for (Ticket ticket : tickets) {
            model.addRow(new Object[]{ticket.getFlight().getFlightCode(), ticket.getPassenger().getName(), ticket.getPassenger().getSurname(), ticket.getPassenger().getSex(), ticket.getSeatNumber()});
        }
    }

    // Metodo per aggiornare la tabella delle credenziali
    public void refreshCredentialsTable(JTable table) {
        DefaultTableModel model = (DefaultTableModel) table.getModel(); // Ottiene il modello della tabella

        // Rimuove tutte le righe esistenti dalla tabella
        while (model.getRowCount() > 0) {
            model.removeRow(0);
        }

        // Ottiene la lista delle credenziali dall'istanza di LoginManager specificata
        ArrayList<LoginManager.Credentials> credentialsList = loginManager.getCredentialsList();

        // Verifica se la lista delle credenziali è vuota
        if (credentialsList.isEmpty()) {
            System.out.println("[CAS] Lista delle credenziali vuota. Nessuna riga aggiunta alla tabella.");
            return; // Esci dal metodo se la lista delle credenziali è vuota
        }

        // Itera attraverso la lista delle credenziali e aggiunge le informazioni di ciascuna credenziale alla tabella
        for (LoginManager.Credentials credentials : credentialsList) {
            model.addRow(new Object[]{credentials.getUsername(), credentials.getPassword(), credentials.getTipologia()});
        }
    }
    
    public void refreshAllTicketsTable(JTable table) {
        DefaultTableModel model = (DefaultTableModel) table.getModel(); // Ottiene il modello della tabella

        // Rimuove tutte le righe esistenti dalla tabella
        while (model.getRowCount() > 0) {
            model.removeRow(0);
        }

        // Ottiene la lista dei biglietti dalla compagnia aerea
        ArrayList<Ticket> tickets = compagnia.getTickets();

        // Verifica se la lista dei biglietti è vuota
        if (tickets.isEmpty()) {
            System.out.println("[CAS] Lista dei biglietti vuota. Nessuna riga aggiunta alla tabella.");
            return; // Esci dal metodo se la lista dei biglietti è vuota
        }

        // Itera attraverso la lista dei biglietti e aggiunge le informazioni di ciascun biglietto alla tabella
        for (Ticket ticket : tickets) {
            Flight flight = ticket.getFlight();
            Passenger passenger = ticket.getPassenger();
            model.addRow(new Object[]{flight.getFlightCode(), passenger.getName(), ticket.getSeatNumber(), flight.getSource(), flight.getDestination(), flight.getTakeOff()});
        }
    }


    //in modo che la scelta dei pannelli sia più semplice ed eviti di riscrivere codice
    public void selectPannel(int choice) {
        System.out.println("[CAS] Pannello caricato: " + choice);
        this.setVisible(true); //cosi è visibile se vengo la gui normale

        // Imposta tutti i pannelli su false
        t_boarding_pannel.setVisible(false);
        manage_tickets_pannel.setVisible(false);
        flight_listing_pannel.setVisible(false);
        settings_pannel.setVisible(false);

        // Attiva il pannello scelto
        switch (choice) {
            case CAS_TICKET_BOARDING:
                refreshFlightTable(table_flight_tb, true);
                refreshTicketTable(ticket_list);
                name_textfield.setText(compagniaAereaGUI.getUsername());
                t_boarding_pannel.setVisible(true);
                break;
            case CAS_MANAGE_TICKETS:
                refreshAllTicketsTable(tickets_table);
                manage_tickets_pannel.setVisible(true);
                break;
            case CAS_MANAGE_FLIGHT:
                add_button.setEnabled(compagniaAereaGUI.isAdmin());
                edit_button.setEnabled(compagniaAereaGUI.isAdmin());
                delete_flight_button.setEnabled(compagniaAereaGUI.isAdmin());
                refreshFlightTable(table_flight, false);
                flight_listing_pannel.setVisible(true);
                break;
            case CAS_SETTINGS:
                refreshCredentialsTable(admin_table);
                settings_pannel.setVisible(true);
                break;
            default:
                System.err.println("[CAS] Errore: scelta del pannello non valida");
                break;
        }
    }

    public void setOldFrame(CompagniaAereaGUI oldFrame) {
        this.compagniaAereaGUI = oldFrame; // Conserva l'istanza di CompagniaAereaGUI
    }

    public void backCA(int choise) { //meno codice da riscrivere
        System.out.println("[CAS] Caricando pannello: " + choise);
        this.setVisible(false);
        compagniaAereaGUI.selectPannel(choise);
    }

    public void errorButtonAnimation(JButton button, String errorIcon, int duration, String sound, boolean flagLoop) {
        System.out.println("[CAS] Animazione iniziata.");

        if (runningAnimation) {
            System.out.println("[CAS] Animazione in corso. Ignorando richiesta...");
            return; // Ignora la richiesta se un'animazione è già in corso
        }

        // Imposta il flag per indicare che un'animazione è in corso
        runningAnimation = true;

        // Salva le icone originali del pulsante
        ImageIcon originalIcon = (ImageIcon) button.getDisabledIcon();

        // Esegui il suono
        compagniaAereaGUI.play(sound, flagLoop);

        button.setDisabledIcon(new ImageIcon(getClass().getResource("/photo/" + errorIcon)));
        button.setEnabled(false);

        // Crea un timer per ripristinare l'icona originale dopo la durata specificata
        Timer timer = new Timer(duration, new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                // Ripristina l'icona originale del pulsante
                button.setDisabledIcon(originalIcon);
                button.setEnabled(true);
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

    public void setValuesFlight(String flightCode) {
        Flight selectedFlight = compagnia.getFlight(flightCode);

        // Popola i textfield con i dati del volo
        flight_code_textfield.setText(selectedFlight.getFlightCode());
        source_textfield.setText(selectedFlight.getSource());
        destination_textfield.setText(selectedFlight.getDestination());
        takeoff_textfield.setText(selectedFlight.getTakeOff());
        seats_textfield.setText(String.valueOf(compagnia.getTotalSeats(flightCode)));
    }

    public void setValuesTicket(String username, String flightCode) {
        // Ottiene il ticket corrispondente all'username e al codice di volo specificati
        Ticket selectedTicket = compagnia.getTicketByUsernameAndFlightCode(username, flightCode);

        // Popola i campi di testo con i dati del ticket
        flight_code_textfield_tb.setText(selectedTicket.getFlight().getFlightCode());
        name_textfield.setText(selectedTicket.getPassenger().getName());
        surname_textfield.setText(selectedTicket.getPassenger().getSurname());
        sex_textfield.setText(selectedTicket.getPassenger().getSex());
        seats_textfield1.setText(String.valueOf(selectedTicket.getSeatNumber()));
    }

    public void setValuesCredentials(String username) {
        // Ottiene le credenziali corrispondenti all'username
        LoginManager.Credentials selectedCredentials = loginManager.getCredentialsByUsername(username);

        // Popola i textfield con i dati delle credenziali
        old_username_textfield.setText(selectedCredentials.getUsername());
        password_textfield.setText(selectedCredentials.getPassword());

        // Verifica il tipo di utente e seleziona il radio button corrispondente
        if (selectedCredentials.getTipologia()) {
            admin_true.setSelected(true);
            admin_false.setSelected(false);
        } else {
            admin_true.setSelected(false);
            admin_false.setSelected(true);
        }
    }

    // Metodo per verificare i dati del nuovo volo
    private boolean touchFlightData(String flightCode, String source, String destination, String takeOff, String seatsText, JTable table, boolean addFlag) {
        // Verifica se il codice volo è vuoto o nullo
        if (flightCode == null || flightCode.trim().isEmpty()) {
            System.err.println("[CAS] Errore: Il campo codice vuoto.");
            return false;
        }

        // Trasforma il codice volo in maiuscolo per rendere la ricerca non case sensitive
        flightCode = flightCode.toUpperCase();

        // Verifica se la sorgente è vuota o nulla
        if (source == null || source.trim().isEmpty()) {
            System.err.println("[CAS] Errore: Il campo sorgente vuoto.");
            return false;
        }

        // Verifica se la destinazione è vuota o nulla
        if (destination == null || destination.trim().isEmpty()) {
            System.err.println("[CAS] Errore: Il campo destinazione vuoto.");
            return false;
        }

        // Verifica se l'orario di decollo è vuoto o nullo
        if (takeOff == null || takeOff.trim().isEmpty()) {
            System.err.println("[CAS] Errore: Il campo orario decollo vuoto.");
            return false;
        }

        int seats = 0;

        try {
            // Verifica se il campo dei posti è vuoto o nullo, se sì imposta il numero di posti a 0
            seats = seatsText.isEmpty() || Integer.parseInt(seatsText) < 0 ? 0 : Integer.parseInt(seatsText);
        } catch (NumberFormatException e) {
            System.err.println("[CAS] Errore: lettera non convertibile in numero, impostato zero di default.");
        }

        // Verifica l'esistenza del codice volo solo se il flag è true
        if (addFlag) {
            // Verifica se il codice volo esiste già nella lista dei voli
            if (compagnia.checkFlightExistence(flightCode)) {
                System.err.println("[CAS] Errore: codice volo esistente.");
                return false;
            } else {
                if(!compagnia.addFlight(new Flight(flightCode, source, destination, takeOff, seats))) return false;
            }
        } else {
            if(!compagnia.modifyFlight(flightCode, source, destination, takeOff, seats)) return false;
        }

        refreshFlightTable(table, false);

        return true; // Restituisce true se tutti i dati sono validi
    }

    // Metodo per verificare i dati del nuovo biglietto
    private boolean touchTicketData(String flightCode, String username, String cognome, String sesso, String seatText, JTable table, boolean addFlag) {
        // Verifica se il codice volo è vuoto o nullo
        if (flightCode == null || flightCode.trim().isEmpty()) {
            System.err.println("[CAS] Errore: Il campo codice volo vuoto.");
            return false;
        }

        // Trasforma il codice volo in maiuscolo per rendere la ricerca non case sensitive
        flightCode = flightCode.toUpperCase();

        try {
            // Verifica se il numero di posti è minore di zero o nullo
            if (seatText.isEmpty() || Integer.parseInt(seatText) < 0) {
                System.err.println("[CAS] Errore: Il numero di posti non può essere zero o negativo.");
                return false;
            }
        } catch (NumberFormatException e) {
            System.err.println("[CAS] Errore: lettera non convertibile in numero.");
            return false;
        }

        // Verifica se l'username è vuoto o nullo
        if (username == null || username.trim().isEmpty()) {
            System.err.println("[CAS] Errore: Il campo username vuoto.");
            return false;
        }

        // Verifica se il cognome è vuoto o nullo
        if (cognome == null || cognome.trim().isEmpty()) {
            System.err.println("[CAS] Errore: Il campo cognome vuoto.");
            return false;
        }

        // Verifica se il sesso è vuoto o nullo
        if (sesso == null || sesso.trim().isEmpty()) {
            System.err.println("[CAS] Errore: Il campo sesso vuoto.");
            return false;
        }

        // Verifica l'esistenza del codice volo solo se il flag è true
        if (compagnia.checkFlightExistence(flightCode)) {
            // Verifica se il codice volo esiste già nella lista dei voli
            if (addFlag) {
                if(compagnia.addTicket(flightCode, Integer.parseInt(seatText), username, cognome, sesso, true) == null) return false; // Aggiungi un nuovo biglietto
            } else {
                if(!compagnia.modifyTicket(username, flightCode, cognome, sesso, Integer.parseInt(seatText), true)) return false; // Modifica il biglietto esistente
            }
        } else {
            System.err.println("[CAS] Errore: codice volo non esistente.");
            return false;

        }

        refreshTicketTable(table);
        return true; // Restituisce true se tutti i dati sono validi
    }

    private boolean touchCredentialData(String username, String newUsername, String password, boolean type, JTable table, boolean addFlag) {
        // Verifica se l'username è vuoto o nullo
        if (username == null || username.trim().isEmpty()) {
            System.err.println("[CAS] Errore: Il campo username vuoto.");
            return false;
        }

        // Verifica se il nuovo username è vuoto o nullo e se lo è rimette quello vecchio
        if (newUsername == null && !addFlag || newUsername.trim().isEmpty() && !addFlag) {
            newUsername = username;
        }

        // Verifica se la password è vuota o nullo
        if (password == null || password.trim().isEmpty()) {
            System.err.println("[CAS] Errore: Il campo password vuoto.");
            return false;
        }

        // Verifica l'esistenza dell'username solo se il flag è true
        if (loginManager.isUsernameExists(username) && addFlag) {
            System.err.println("[CAS] Errore: Username esistente.");
            return false;
        }

        // Aggiunta o modifica delle credenziali
        if (addFlag) {
            if(!loginManager.addCredentials(username, password, type)) return false; // Aggiungi nuove credenziali
        } else {
            if(!loginManager.updateCredentials(username, newUsername, password, type)) return false; // Modifica le credenziali esistenti
        }

        refreshCredentialsTable(table);
        return true; // Restituisce true se tutti i dati sono validi
    }

    // Metodo per eliminare un file dato il suo nome
    public boolean deleteFile(String filename) {
        File file = new File(filename); // Crea un oggetto File con il nome del file specificato

        if (file.exists()) { // Verifica se il file esiste
            if (file.delete()) { // Elimina il file
                System.out.println("[CAS] Il file " + filename + " eliminato con successo.");
                return true; // Restituisce true se il file è stato eliminato con successo
            } else {
                System.err.println("[CAS] Errore durante l'eliminazione del file " + filename + ".");
                return false; // Restituisce false se si verifica un errore durante l'eliminazione del file
            }

        } else {
            System.err.println("[CAS] Il file " + filename + " non esiste.");
            return false; // Restituisce false se il file non esiste
        }
    }

    public static int showConfirmationDialog(String title, String message, int optionType) {
        // Tipo di messaggio nel popup (QUESTION_MESSAGE per domanda)
        int messageType = JOptionPane.QUESTION_MESSAGE;

        // Visualizza il popup di conferma e ottiene la risposta dell'utente
        int response = JOptionPane.showConfirmDialog(null, message, title, optionType, messageType);

        // Restituisce la risposta dell'utente
        return response;
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        admin_flag = new javax.swing.ButtonGroup();
        t_boarding_pannel = new javax.swing.JPanel();
        scroll_pannel1 = new javax.swing.JScrollPane();
        table_flight_tb = new javax.swing.JTable();
        scroll_pannel2 = new javax.swing.JScrollPane();
        ticket_list = new javax.swing.JTable();
        back_button_tb = new javax.swing.JButton();
        add_button_tb = new javax.swing.JButton();
        edit_button_tb = new javax.swing.JButton();
        delete_ticket = new javax.swing.JButton();
        seats_tb_label = new javax.swing.JLabel();
        flight_code_label1 = new javax.swing.JLabel();
        name_label = new javax.swing.JLabel();
        surname_label = new javax.swing.JLabel();
        sex_label = new javax.swing.JLabel();
        tickets_title_label = new javax.swing.JLabel();
        ticket_boarding_label = new javax.swing.JLabel();
        flight_title_label = new javax.swing.JLabel();
        seats_textfield1 = new javax.swing.JTextField();
        flight_code_textfield_tb = new javax.swing.JTextField();
        name_textfield = new javax.swing.JTextField();
        surname_textfield = new javax.swing.JTextField();
        sex_textfield = new javax.swing.JTextField();
        background_tb = new javax.swing.JLabel();
        manage_tickets_pannel = new javax.swing.JPanel();
        scroll_pannel3 = new javax.swing.JScrollPane();
        tickets_table = new javax.swing.JTable();
        tickets_label = new javax.swing.JLabel();
        delete_ticket_mt = new javax.swing.JButton();
        back_button_mt = new javax.swing.JButton();
        background_mt = new javax.swing.JLabel();
        flight_listing_pannel = new javax.swing.JPanel();
        seats_label = new javax.swing.JLabel();
        flight_code_label = new javax.swing.JLabel();
        source_label = new javax.swing.JLabel();
        destination_label = new javax.swing.JLabel();
        takeoff_label = new javax.swing.JLabel();
        manage_flight_label = new javax.swing.JLabel();
        scroll_pannel = new javax.swing.JScrollPane();
        table_flight = new javax.swing.JTable();
        search_button = new javax.swing.JButton();
        seats_textfield = new javax.swing.JTextField();
        flight_code_textfield = new javax.swing.JTextField();
        source_textfield = new javax.swing.JTextField();
        takeoff_textfield = new javax.swing.JTextField();
        destination_textfield = new javax.swing.JTextField();
        delete_flight_button = new javax.swing.JButton();
        back_button_ma = new javax.swing.JButton();
        edit_button = new javax.swing.JButton();
        add_button = new javax.swing.JButton();
        manage_flight_background = new javax.swing.JLabel();
        settings_pannel = new javax.swing.JPanel();
        admin_settings_label = new javax.swing.JLabel();
        settings_label = new javax.swing.JLabel();
        new_username_settings_label = new javax.swing.JLabel();
        old_username_settings_label = new javax.swing.JLabel();
        password_settings_label = new javax.swing.JLabel();
        admin_false = new javax.swing.JRadioButton();
        admin_true = new javax.swing.JRadioButton();
        search_settings_button = new javax.swing.JButton();
        old_username_textfield = new javax.swing.JTextField();
        new_username_textfield = new javax.swing.JTextField();
        password_textfield = new javax.swing.JTextField();
        jScrollPane1 = new javax.swing.JScrollPane();
        admin_table = new javax.swing.JTable();
        add_user_button = new javax.swing.JButton();
        edit_user_button = new javax.swing.JButton();
        back_button_s = new javax.swing.JButton();
        delete_data_button = new javax.swing.JButton();
        delete_credentials_button = new javax.swing.JButton();
        delete_user_button = new javax.swing.JButton();
        background_s = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowClosing(java.awt.event.WindowEvent evt) {
                formWindowClosing(evt);
            }
        });

        t_boarding_pannel.setLayout(null);

        scroll_pannel1.setBackground(new java.awt.Color(237, 237, 237));
        scroll_pannel1.setBorder(null);
        scroll_pannel1.setHorizontalScrollBarPolicy(javax.swing.ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);
        scroll_pannel1.setToolTipText("");
        scroll_pannel1.setAutoscrolls(true);
        scroll_pannel1.setFont(new java.awt.Font("Courier New", 0, 12)); // NOI18N
        scroll_pannel1.setOpaque(false);

        table_flight_tb.setAutoCreateRowSorter(true);
        table_flight_tb.setBackground(new java.awt.Color(237, 237, 237));
        table_flight_tb.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "Flight Code", "Source", "Destination", "Take Off", "N° Seats Left"
            }
        ) {
            Class[] types = new Class [] {
                java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.Integer.class
            };
            boolean[] canEdit = new boolean [] {
                false, false, false, false, false
            };

            public Class getColumnClass(int columnIndex) {
                return types [columnIndex];
            }

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        table_flight_tb.setAutoscrolls(false);
        table_flight_tb.setGridColor(new java.awt.Color(237, 237, 237));
        table_flight_tb.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                table_flight_tbMouseClicked(evt);
            }
        });
        scroll_pannel1.setViewportView(table_flight_tb);

        t_boarding_pannel.add(scroll_pannel1);
        scroll_pannel1.setBounds(270, 490, 518, 190);

        scroll_pannel2.setBackground(new java.awt.Color(237, 237, 237));
        scroll_pannel2.setBorder(null);
        scroll_pannel2.setHorizontalScrollBarPolicy(javax.swing.ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);
        scroll_pannel2.setToolTipText("");
        scroll_pannel2.setAutoscrolls(true);
        scroll_pannel2.setFont(new java.awt.Font("Courier New", 0, 12)); // NOI18N
        scroll_pannel2.setOpaque(false);

        ticket_list.setAutoCreateRowSorter(true);
        ticket_list.setBackground(new java.awt.Color(237, 237, 237));
        ticket_list.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "Flight Code", "Name", "Surname", "Sex", "N° Seats"
            }
        ) {
            Class[] types = new Class [] {
                java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.Integer.class
            };
            boolean[] canEdit = new boolean [] {
                false, false, false, false, false
            };

            public Class getColumnClass(int columnIndex) {
                return types [columnIndex];
            }

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        ticket_list.setAutoscrolls(false);
        ticket_list.setGridColor(new java.awt.Color(237, 237, 237));
        ticket_list.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                ticket_listMouseClicked(evt);
            }
        });
        scroll_pannel2.setViewportView(ticket_list);

        t_boarding_pannel.add(scroll_pannel2);
        scroll_pannel2.setBounds(270, 230, 518, 190);

        back_button_tb.setIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/return_button.png"))); // NOI18N
        back_button_tb.setContentAreaFilled(false);
        back_button_tb.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        back_button_tb.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/return_button_P.png"))); // NOI18N
        back_button_tb.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/return_button_B.png"))); // NOI18N
        back_button_tb.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/return_button_BP.png"))); // NOI18N
        back_button_tb.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                back_button_tbActionPerformed(evt);
            }
        });
        t_boarding_pannel.add(back_button_tb);
        back_button_tb.setBounds(20, 52, 50, 60);

        add_button_tb.setIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/add_button.png"))); // NOI18N
        add_button_tb.setContentAreaFilled(false);
        add_button_tb.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        add_button_tb.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/add_button_P.png"))); // NOI18N
        add_button_tb.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/add_button_B.png"))); // NOI18N
        add_button_tb.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/add_button_BP.png"))); // NOI18N
        add_button_tb.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                add_button_tbActionPerformed(evt);
            }
        });
        t_boarding_pannel.add(add_button_tb);
        add_button_tb.setBounds(110, 160, 50, 60);

        edit_button_tb.setIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/edit_button.png"))); // NOI18N
        edit_button_tb.setContentAreaFilled(false);
        edit_button_tb.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        edit_button_tb.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/edit_button_P.png"))); // NOI18N
        edit_button_tb.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/edit_button_B.png"))); // NOI18N
        edit_button_tb.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/edit_button_BP.png"))); // NOI18N
        edit_button_tb.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                edit_button_tbActionPerformed(evt);
            }
        });
        t_boarding_pannel.add(edit_button_tb);
        edit_button_tb.setBounds(50, 670, 60, 60);

        delete_ticket.setIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/delete_button_settings.png"))); // NOI18N
        delete_ticket.setContentAreaFilled(false);
        delete_ticket.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/delete_button_settings_P.png"))); // NOI18N
        delete_ticket.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/delete_button_settings_B.png"))); // NOI18N
        delete_ticket.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/delete_button_settings_BP.png"))); // NOI18N
        delete_ticket.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                delete_ticketActionPerformed(evt);
            }
        });
        t_boarding_pannel.add(delete_ticket);
        delete_ticket.setBounds(150, 670, 50, 60);

        seats_tb_label.setFont(new java.awt.Font("Courier New", 1, 18)); // NOI18N
        seats_tb_label.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        seats_tb_label.setText("Seat");
        t_boarding_pannel.add(seats_tb_label);
        seats_tb_label.setBounds(43, 556, 181, 50);

        flight_code_label1.setFont(new java.awt.Font("Courier New", 1, 18)); // NOI18N
        flight_code_label1.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        flight_code_label1.setText("Flight Code");
        t_boarding_pannel.add(flight_code_label1);
        flight_code_label1.setBounds(43, 213, 181, 50);

        name_label.setFont(new java.awt.Font("Courier New", 1, 18)); // NOI18N
        name_label.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        name_label.setText("Name");
        t_boarding_pannel.add(name_label);
        name_label.setBounds(43, 300, 181, 50);

        surname_label.setFont(new java.awt.Font("Courier New", 1, 18)); // NOI18N
        surname_label.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        surname_label.setText("Surname");
        t_boarding_pannel.add(surname_label);
        surname_label.setBounds(43, 385, 181, 50);

        sex_label.setFont(new java.awt.Font("Courier New", 1, 18)); // NOI18N
        sex_label.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        sex_label.setText("Sex");
        t_boarding_pannel.add(sex_label);
        sex_label.setBounds(43, 470, 181, 50);

        tickets_title_label.setFont(new java.awt.Font("Courier New", 1, 36)); // NOI18N
        tickets_title_label.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        tickets_title_label.setText("Flights");
        t_boarding_pannel.add(tickets_title_label);
        tickets_title_label.setBounds(430, 440, 170, 40);

        ticket_boarding_label.setFont(new java.awt.Font("Courier New", 1, 36)); // NOI18N
        ticket_boarding_label.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        ticket_boarding_label.setText("Tickets Boarding");
        t_boarding_pannel.add(ticket_boarding_label);
        ticket_boarding_label.setBounds(230, 60, 385, 50);

        flight_title_label.setFont(new java.awt.Font("Courier New", 1, 36)); // NOI18N
        flight_title_label.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        flight_title_label.setText("Tickets");
        t_boarding_pannel.add(flight_title_label);
        flight_title_label.setBounds(430, 180, 170, 40);

        seats_textfield1.setBackground(new java.awt.Color(232, 231, 231));
        seats_textfield1.setFont(new java.awt.Font("Courier New", 0, 12)); // NOI18N
        seats_textfield1.setBorder(null);
        t_boarding_pannel.add(seats_textfield1);
        seats_textfield1.setBounds(58, 595, 152, 22);

        flight_code_textfield_tb.setBackground(new java.awt.Color(232, 231, 231));
        flight_code_textfield_tb.setFont(new java.awt.Font("Courier New", 0, 12)); // NOI18N
        flight_code_textfield_tb.setBorder(null);
        flight_code_textfield_tb.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                flight_code_textfield_tbActionPerformed(evt);
            }
        });
        t_boarding_pannel.add(flight_code_textfield_tb);
        flight_code_textfield_tb.setBounds(58, 255, 152, 22);

        name_textfield.setEditable(false);
        name_textfield.setBackground(new java.awt.Color(232, 231, 231));
        name_textfield.setFont(new java.awt.Font("Courier New", 0, 12)); // NOI18N
        name_textfield.setBorder(null);
        name_textfield.addComponentListener(new java.awt.event.ComponentAdapter() {
            public void componentShown(java.awt.event.ComponentEvent evt) {
                name_textfieldComponentShown(evt);
            }
        });
        name_textfield.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                name_textfieldActionPerformed(evt);
            }
        });
        t_boarding_pannel.add(name_textfield);
        name_textfield.setBounds(58, 340, 152, 22);

        surname_textfield.setBackground(new java.awt.Color(232, 231, 231));
        surname_textfield.setFont(new java.awt.Font("Courier New", 0, 12)); // NOI18N
        surname_textfield.setBorder(null);
        t_boarding_pannel.add(surname_textfield);
        surname_textfield.setBounds(58, 425, 152, 22);

        sex_textfield.setBackground(new java.awt.Color(232, 231, 231));
        sex_textfield.setFont(new java.awt.Font("Courier New", 0, 12)); // NOI18N
        sex_textfield.setBorder(null);
        sex_textfield.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                sex_textfieldActionPerformed(evt);
            }
        });
        t_boarding_pannel.add(sex_textfield);
        sex_textfield.setBounds(58, 510, 152, 22);

        background_tb.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
        background_tb.setIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/ticket_boarding_background.png"))); // NOI18N
        t_boarding_pannel.add(background_tb);
        background_tb.setBounds(0, 0, 845, 753);

        manage_tickets_pannel.setLayout(null);

        scroll_pannel3.setBackground(new java.awt.Color(237, 237, 237));
        scroll_pannel3.setBorder(null);
        scroll_pannel3.setHorizontalScrollBarPolicy(javax.swing.ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);
        scroll_pannel3.setToolTipText("");
        scroll_pannel3.setAutoscrolls(true);
        scroll_pannel3.setFont(new java.awt.Font("Courier New", 0, 12)); // NOI18N
        scroll_pannel3.setOpaque(false);

        tickets_table.setAutoCreateRowSorter(true);
        tickets_table.setBackground(new java.awt.Color(237, 237, 237));
        tickets_table.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "Flight Code", "Name", "Seat", "Source", "Destination", "Take Off"
            }
        ) {
            Class[] types = new Class [] {
                java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.Object.class, java.lang.Object.class
            };
            boolean[] canEdit = new boolean [] {
                false, false, false, false, false, false
            };

            public Class getColumnClass(int columnIndex) {
                return types [columnIndex];
            }

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        tickets_table.setAutoscrolls(false);
        tickets_table.setGridColor(new java.awt.Color(237, 237, 237));
        tickets_table.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                tickets_tableMouseClicked(evt);
            }
        });
        scroll_pannel3.setViewportView(tickets_table);

        manage_tickets_pannel.add(scroll_pannel3);
        scroll_pannel3.setBounds(192, 176, 612, 514);

        tickets_label.setFont(new java.awt.Font("Courier New", 1, 36)); // NOI18N
        tickets_label.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        tickets_label.setText("Tickets Manager");
        manage_tickets_pannel.add(tickets_label);
        tickets_label.setBounds(230, 60, 385, 50);

        delete_ticket_mt.setIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/delete_button_settings.png"))); // NOI18N
        delete_ticket_mt.setContentAreaFilled(false);
        delete_ticket_mt.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/delete_button_settings_P.png"))); // NOI18N
        delete_ticket_mt.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/delete_button_settings_B.png"))); // NOI18N
        delete_ticket_mt.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/delete_button_settings_BP.png"))); // NOI18N
        delete_ticket_mt.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                delete_ticket_mtActionPerformed(evt);
            }
        });
        manage_tickets_pannel.add(delete_ticket_mt);
        delete_ticket_mt.setBounds(75, 440, 50, 60);

        back_button_mt.setIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/return_button.png"))); // NOI18N
        back_button_mt.setContentAreaFilled(false);
        back_button_mt.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        back_button_mt.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/return_button_P.png"))); // NOI18N
        back_button_mt.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/return_button_B.png"))); // NOI18N
        back_button_mt.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/return_button_BP.png"))); // NOI18N
        back_button_mt.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                back_button_mtActionPerformed(evt);
            }
        });
        manage_tickets_pannel.add(back_button_mt);
        back_button_mt.setBounds(20, 50, 50, 60);

        background_mt.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
        background_mt.setIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/tickets_manager_background.png"))); // NOI18N
        manage_tickets_pannel.add(background_mt);
        background_mt.setBounds(0, 0, 845, 753);

        flight_listing_pannel.setAlignmentX(0.0F);
        flight_listing_pannel.setAlignmentY(0.0F);
        flight_listing_pannel.setLayout(null);

        seats_label.setFont(new java.awt.Font("Courier New", 1, 18)); // NOI18N
        seats_label.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        seats_label.setText("N° Seats");
        flight_listing_pannel.add(seats_label);
        seats_label.setBounds(43, 556, 181, 50);

        flight_code_label.setFont(new java.awt.Font("Courier New", 1, 18)); // NOI18N
        flight_code_label.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        flight_code_label.setText("Flight Code");
        flight_listing_pannel.add(flight_code_label);
        flight_code_label.setBounds(43, 213, 181, 50);

        source_label.setFont(new java.awt.Font("Courier New", 1, 18)); // NOI18N
        source_label.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        source_label.setText("Source");
        flight_listing_pannel.add(source_label);
        source_label.setBounds(43, 300, 181, 50);

        destination_label.setFont(new java.awt.Font("Courier New", 1, 18)); // NOI18N
        destination_label.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        destination_label.setText("Destination");
        flight_listing_pannel.add(destination_label);
        destination_label.setBounds(43, 385, 181, 50);

        takeoff_label.setFont(new java.awt.Font("Courier New", 1, 18)); // NOI18N
        takeoff_label.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        takeoff_label.setText("Take Off");
        flight_listing_pannel.add(takeoff_label);
        takeoff_label.setBounds(43, 470, 181, 50);

        manage_flight_label.setFont(new java.awt.Font("Courier New", 1, 36)); // NOI18N
        manage_flight_label.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        manage_flight_label.setText("Manage Flight");
        flight_listing_pannel.add(manage_flight_label);
        manage_flight_label.setBounds(230, 60, 385, 50);

        scroll_pannel.setBackground(new java.awt.Color(237, 237, 237));
        scroll_pannel.setBorder(null);
        scroll_pannel.setHorizontalScrollBarPolicy(javax.swing.ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);
        scroll_pannel.setToolTipText("");
        scroll_pannel.setAutoscrolls(true);
        scroll_pannel.setFont(new java.awt.Font("Courier New", 0, 12)); // NOI18N
        scroll_pannel.setOpaque(false);

        table_flight.setAutoCreateRowSorter(true);
        table_flight.setBackground(new java.awt.Color(237, 237, 237));
        table_flight.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "Flight Code", "Source", "Destination", "Take Off", "N° Seats"
            }
        ) {
            Class[] types = new Class [] {
                java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.Integer.class
            };
            boolean[] canEdit = new boolean [] {
                false, false, false, false, false
            };

            public Class getColumnClass(int columnIndex) {
                return types [columnIndex];
            }

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        table_flight.setAutoscrolls(false);
        table_flight.setGridColor(new java.awt.Color(237, 237, 237));
        table_flight.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                table_flightMouseClicked(evt);
            }
        });
        scroll_pannel.setViewportView(table_flight);

        flight_listing_pannel.add(scroll_pannel);
        scroll_pannel.setBounds(240, 153, 570, 563);

        search_button.setIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/search_button.png"))); // NOI18N
        search_button.setContentAreaFilled(false);
        search_button.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        search_button.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/search_button_P.png"))); // NOI18N
        search_button.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/search_button_B.png"))); // NOI18N
        search_button.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/search_button_BP.png"))); // NOI18N
        search_button.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                search_buttonActionPerformed(evt);
            }
        });
        flight_listing_pannel.add(search_button);
        search_button.setBounds(187, 247, 30, 40);

        seats_textfield.setBackground(new java.awt.Color(232, 231, 231));
        seats_textfield.setFont(new java.awt.Font("Courier New", 0, 12)); // NOI18N
        seats_textfield.setBorder(null);
        flight_listing_pannel.add(seats_textfield);
        seats_textfield.setBounds(58, 595, 152, 22);

        flight_code_textfield.setBackground(new java.awt.Color(232, 231, 231));
        flight_code_textfield.setFont(new java.awt.Font("Courier New", 0, 12)); // NOI18N
        flight_code_textfield.setBorder(null);
        flight_code_textfield.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                flight_code_textfieldActionPerformed(evt);
            }
        });
        flight_listing_pannel.add(flight_code_textfield);
        flight_code_textfield.setBounds(58, 255, 152, 22);

        source_textfield.setBackground(new java.awt.Color(232, 231, 231));
        source_textfield.setFont(new java.awt.Font("Courier New", 0, 12)); // NOI18N
        source_textfield.setBorder(null);
        flight_listing_pannel.add(source_textfield);
        source_textfield.setBounds(58, 340, 152, 22);

        takeoff_textfield.setBackground(new java.awt.Color(232, 231, 231));
        takeoff_textfield.setFont(new java.awt.Font("Courier New", 0, 12)); // NOI18N
        takeoff_textfield.setBorder(null);
        flight_listing_pannel.add(takeoff_textfield);
        takeoff_textfield.setBounds(58, 510, 152, 22);

        destination_textfield.setBackground(new java.awt.Color(232, 231, 231));
        destination_textfield.setFont(new java.awt.Font("Courier New", 0, 12)); // NOI18N
        destination_textfield.setBorder(null);
        flight_listing_pannel.add(destination_textfield);
        destination_textfield.setBounds(58, 425, 152, 22);

        delete_flight_button.setIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/delete_button.png"))); // NOI18N
        delete_flight_button.setContentAreaFilled(false);
        delete_flight_button.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        delete_flight_button.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/delete_button_P.png"))); // NOI18N
        delete_flight_button.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/delete_button_B.png"))); // NOI18N
        delete_flight_button.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/delete_button_BP.png"))); // NOI18N
        delete_flight_button.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                delete_flight_buttonActionPerformed(evt);
            }
        });
        flight_listing_pannel.add(delete_flight_button);
        delete_flight_button.setBounds(100, 665, 130, 70);

        back_button_ma.setIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/return_button.png"))); // NOI18N
        back_button_ma.setContentAreaFilled(false);
        back_button_ma.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        back_button_ma.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/return_button_P.png"))); // NOI18N
        back_button_ma.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/return_button_B.png"))); // NOI18N
        back_button_ma.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/return_button_BP.png"))); // NOI18N
        back_button_ma.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                back_button_maActionPerformed(evt);
            }
        });
        flight_listing_pannel.add(back_button_ma);
        back_button_ma.setBounds(29, 51, 50, 60);

        edit_button.setIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/edit_button.png"))); // NOI18N
        edit_button.setContentAreaFilled(false);
        edit_button.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        edit_button.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/edit_button_P.png"))); // NOI18N
        edit_button.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/edit_button_B.png"))); // NOI18N
        edit_button.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/edit_button_BP.png"))); // NOI18N
        edit_button.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                edit_buttonActionPerformed(evt);
            }
        });
        flight_listing_pannel.add(edit_button);
        edit_button.setBounds(35, 668, 60, 60);

        add_button.setIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/add_button.png"))); // NOI18N
        add_button.setContentAreaFilled(false);
        add_button.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        add_button.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/add_button_P.png"))); // NOI18N
        add_button.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/add_button_B.png"))); // NOI18N
        add_button.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/add_button_BP.png"))); // NOI18N
        add_button.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                add_buttonActionPerformed(evt);
            }
        });
        flight_listing_pannel.add(add_button);
        add_button.setBounds(110, 160, 50, 60);

        manage_flight_background.setBackground(new java.awt.Color(237, 237, 237));
        manage_flight_background.setFont(new java.awt.Font("Courier New", 0, 12)); // NOI18N
        manage_flight_background.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        manage_flight_background.setIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/manage_flight_photo.png"))); // NOI18N
        manage_flight_background.setAlignmentY(0.0F);
        flight_listing_pannel.add(manage_flight_background);
        manage_flight_background.setBounds(0, 0, 845, 753);

        settings_pannel.setLayout(null);

        admin_settings_label.setFont(new java.awt.Font("Courier New", 1, 20)); // NOI18N
        admin_settings_label.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        admin_settings_label.setText("Admin");
        settings_pannel.add(admin_settings_label);
        admin_settings_label.setBounds(160, 390, 180, 30);

        settings_label.setFont(new java.awt.Font("Courier New", 1, 36)); // NOI18N
        settings_label.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        settings_label.setText("Settings");
        settings_pannel.add(settings_label);
        settings_label.setBounds(230, 60, 385, 50);

        new_username_settings_label.setFont(new java.awt.Font("Courier New", 1, 20)); // NOI18N
        new_username_settings_label.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        new_username_settings_label.setText("New Username");
        settings_pannel.add(new_username_settings_label);
        new_username_settings_label.setBounds(160, 270, 180, 20);

        old_username_settings_label.setFont(new java.awt.Font("Courier New", 1, 20)); // NOI18N
        old_username_settings_label.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        old_username_settings_label.setText("Username");
        settings_pannel.add(old_username_settings_label);
        old_username_settings_label.setBounds(160, 200, 180, 20);

        password_settings_label.setFont(new java.awt.Font("Courier New", 1, 20)); // NOI18N
        password_settings_label.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        password_settings_label.setText("Password");
        settings_pannel.add(password_settings_label);
        password_settings_label.setBounds(160, 337, 180, 23);

        admin_flag.add(admin_false);
        admin_false.setIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/admin_false.png"))); // NOI18N
        admin_false.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/admin_false_P.png"))); // NOI18N
        admin_false.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/admin_false_B.png"))); // NOI18N
        admin_false.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/admin_false_BP.png"))); // NOI18N
        admin_false.setSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/admin_false_P.png"))); // NOI18N
        admin_false.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                admin_falseActionPerformed(evt);
            }
        });
        settings_pannel.add(admin_false);
        admin_false.setBounds(250, 420, 80, 40);

        admin_flag.add(admin_true);
        admin_true.setIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/admin_true.png"))); // NOI18N
        admin_true.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/admin_true_P.png"))); // NOI18N
        admin_true.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/admin_true_B.png"))); // NOI18N
        admin_true.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/admin_true_BP.png"))); // NOI18N
        admin_true.setSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/admin_true_P.png"))); // NOI18N
        admin_true.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                admin_trueActionPerformed(evt);
            }
        });
        settings_pannel.add(admin_true);
        admin_true.setBounds(160, 420, 80, 40);

        search_settings_button.setIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/search_button_settings.png"))); // NOI18N
        search_settings_button.setContentAreaFilled(false);
        search_settings_button.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/search_button_settings_P.png"))); // NOI18N
        search_settings_button.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/search_button_settings_B.png"))); // NOI18N
        search_settings_button.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/search_button_settings_BP.png"))); // NOI18N
        search_settings_button.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                search_settings_buttonActionPerformed(evt);
            }
        });
        settings_pannel.add(search_settings_button);
        search_settings_button.setBounds(295, 218, 40, 40);

        old_username_textfield.setBackground(new java.awt.Color(232, 231, 231));
        old_username_textfield.setFont(new java.awt.Font("Courier New", 0, 12)); // NOI18N
        old_username_textfield.setBorder(null);
        old_username_textfield.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                old_username_textfieldActionPerformed(evt);
            }
        });
        settings_pannel.add(old_username_textfield);
        old_username_textfield.setBounds(173, 222, 130, 22);

        new_username_textfield.setBackground(new java.awt.Color(232, 231, 231));
        new_username_textfield.setFont(new java.awt.Font("Courier New", 0, 12)); // NOI18N
        new_username_textfield.setBorder(null);
        new_username_textfield.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                new_username_textfieldActionPerformed(evt);
            }
        });
        settings_pannel.add(new_username_textfield);
        new_username_textfield.setBounds(173, 292, 152, 22);

        password_textfield.setBackground(new java.awt.Color(232, 231, 231));
        password_textfield.setFont(new java.awt.Font("Courier New", 0, 12)); // NOI18N
        password_textfield.setBorder(null);
        password_textfield.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                password_textfieldActionPerformed(evt);
            }
        });
        settings_pannel.add(password_textfield);
        password_textfield.setBounds(173, 362, 152, 22);

        jScrollPane1.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                jScrollPane1MouseClicked(evt);
            }
        });

        admin_table.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null},
                {null, null, null},
                {null, null, null},
                {null, null, null}
            },
            new String [] {
                "Username", "Password", "Admin"
            }
        ) {
            Class[] types = new Class [] {
                java.lang.Object.class, java.lang.Object.class, java.lang.Boolean.class
            };
            boolean[] canEdit = new boolean [] {
                false, false, false
            };

            public Class getColumnClass(int columnIndex) {
                return types [columnIndex];
            }

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        admin_table.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                admin_tableMouseClicked(evt);
            }
        });
        jScrollPane1.setViewportView(admin_table);

        settings_pannel.add(jScrollPane1);
        jScrollPane1.setBounds(380, 190, 367, 243);

        add_user_button.setIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/add_button_settings.png"))); // NOI18N
        add_user_button.setContentAreaFilled(false);
        add_user_button.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/add_button_settings_P.png"))); // NOI18N
        add_user_button.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/add_button_settings_B.png"))); // NOI18N
        add_user_button.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/add_button_settings_BP.png"))); // NOI18N
        add_user_button.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                add_user_buttonActionPerformed(evt);
            }
        });
        settings_pannel.add(add_user_button);
        add_user_button.setBounds(220, 130, 50, 60);

        edit_user_button.setIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/edit_button_settings.png"))); // NOI18N
        edit_user_button.setContentAreaFilled(false);
        edit_user_button.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/edit_button_settings_P.png"))); // NOI18N
        edit_user_button.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/edit_button_settings_B.png"))); // NOI18N
        edit_user_button.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/edit_button_settings_BP.png"))); // NOI18N
        edit_user_button.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                edit_user_buttonActionPerformed(evt);
            }
        });
        settings_pannel.add(edit_user_button);
        edit_user_button.setBounds(80, 250, 50, 60);

        back_button_s.setIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/return_button.png"))); // NOI18N
        back_button_s.setContentAreaFilled(false);
        back_button_s.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        back_button_s.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/return_button_P.png"))); // NOI18N
        back_button_s.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/return_button_B.png"))); // NOI18N
        back_button_s.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/return_button_BP.png"))); // NOI18N
        back_button_s.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                back_button_sActionPerformed(evt);
            }
        });
        settings_pannel.add(back_button_s);
        back_button_s.setBounds(29, 51, 50, 60);

        delete_data_button.setIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/delete_button_settings.png"))); // NOI18N
        delete_data_button.setContentAreaFilled(false);
        delete_data_button.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/delete_button_settings_P.png"))); // NOI18N
        delete_data_button.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/delete_button_settings_B.png"))); // NOI18N
        delete_data_button.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/delete_button_settings_BP.png"))); // NOI18N
        delete_data_button.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                delete_data_buttonActionPerformed(evt);
            }
        });
        settings_pannel.add(delete_data_button);
        delete_data_button.setBounds(410, 620, 50, 60);

        delete_credentials_button.setIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/delete_button_settings.png"))); // NOI18N
        delete_credentials_button.setContentAreaFilled(false);
        delete_credentials_button.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/delete_button_settings_P.png"))); // NOI18N
        delete_credentials_button.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/delete_button_settings_B.png"))); // NOI18N
        delete_credentials_button.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/delete_button_settings_BP.png"))); // NOI18N
        delete_credentials_button.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                delete_credentials_buttonActionPerformed(evt);
            }
        });
        settings_pannel.add(delete_credentials_button);
        delete_credentials_button.setBounds(410, 550, 50, 60);

        delete_user_button.setIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/delete_user.png"))); // NOI18N
        delete_user_button.setContentAreaFilled(false);
        delete_user_button.setPressedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/delete_user_P.png"))); // NOI18N
        delete_user_button.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/delete_user_B.png"))); // NOI18N
        delete_user_button.setRolloverSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/delete_user_BP.png"))); // NOI18N
        delete_user_button.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                delete_user_buttonActionPerformed(evt);
            }
        });
        settings_pannel.add(delete_user_button);
        delete_user_button.setBounds(80, 330, 50, 60);

        background_s.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
        background_s.setIcon(new javax.swing.ImageIcon(getClass().getResource("/photo/settings_background.png"))); // NOI18N
        settings_pannel.add(background_s);
        background_s.setBounds(0, 0, 845, 753);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(flight_listing_pannel, javax.swing.GroupLayout.DEFAULT_SIZE, 845, Short.MAX_VALUE)
            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(layout.createSequentialGroup()
                    .addGap(0, 0, Short.MAX_VALUE)
                    .addComponent(settings_pannel, javax.swing.GroupLayout.PREFERRED_SIZE, 845, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGap(0, 0, Short.MAX_VALUE)))
            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(layout.createSequentialGroup()
                    .addGap(0, 0, Short.MAX_VALUE)
                    .addComponent(t_boarding_pannel, javax.swing.GroupLayout.PREFERRED_SIZE, 845, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGap(0, 0, Short.MAX_VALUE)))
            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(layout.createSequentialGroup()
                    .addGap(0, 0, Short.MAX_VALUE)
                    .addComponent(manage_tickets_pannel, javax.swing.GroupLayout.PREFERRED_SIZE, 845, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGap(0, 0, Short.MAX_VALUE)))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(flight_listing_pannel, javax.swing.GroupLayout.DEFAULT_SIZE, 753, Short.MAX_VALUE)
            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(layout.createSequentialGroup()
                    .addGap(0, 0, Short.MAX_VALUE)
                    .addComponent(settings_pannel, javax.swing.GroupLayout.PREFERRED_SIZE, 753, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGap(0, 0, Short.MAX_VALUE)))
            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(layout.createSequentialGroup()
                    .addGap(0, 0, Short.MAX_VALUE)
                    .addComponent(t_boarding_pannel, javax.swing.GroupLayout.PREFERRED_SIZE, 753, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGap(0, 0, Short.MAX_VALUE)))
            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(layout.createSequentialGroup()
                    .addGap(0, 0, Short.MAX_VALUE)
                    .addComponent(manage_tickets_pannel, javax.swing.GroupLayout.PREFERRED_SIZE, 753, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGap(0, 0, Short.MAX_VALUE)))
        );

        getAccessibleContext().setAccessibleDescription("");

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void delete_flight_buttonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_delete_flight_buttonActionPerformed
        int row = table_flight.getSelectedRow(); // Ottiene l'indice della riga selezionata
        if (row != -1) { // Verifica se una riga è stata effettivamente selezionata
            //cancello il volo selezionato
            compagnia.cancelFlight((String) table_flight.getValueAt(row, 0));
            // Aggiorno la tabella degli aerei
            refreshFlightTable(table_flight, false);
        }
    }//GEN-LAST:event_delete_flight_buttonActionPerformed

    private void back_button_maActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_back_button_maActionPerformed
        backCA(MENU);
    }//GEN-LAST:event_back_button_maActionPerformed

    private void search_buttonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_search_buttonActionPerformed
        setValuesFlight(flight_code_textfield.getText().toUpperCase());

    }//GEN-LAST:event_search_buttonActionPerformed

    private void edit_buttonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_edit_buttonActionPerformed
        // Prendo, verifico e modifico il volo
        if (!touchFlightData(flight_code_textfield.getText(), source_textfield.getText(), destination_textfield.getText(), takeoff_textfield.getText(), seats_textfield.getText(), table_flight, false)) {
            errorButtonAnimation(edit_button, ERROR_EDIT_IMAGE, TIMER_ERROR, ERROR_SOUND, false);
        }
    }//GEN-LAST:event_edit_buttonActionPerformed

    private void flight_code_textfieldActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_flight_code_textfieldActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_flight_code_textfieldActionPerformed

    private void back_button_sActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_back_button_sActionPerformed
        backCA(MENU);
    }//GEN-LAST:event_back_button_sActionPerformed

    private void back_button_tbActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_back_button_tbActionPerformed
        backCA(MENU);
    }//GEN-LAST:event_back_button_tbActionPerformed

    private void back_button_mtActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_back_button_mtActionPerformed
        backCA(MENU);
    }//GEN-LAST:event_back_button_mtActionPerformed

    private void formWindowClosing(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_formWindowClosing
        backCA(MENU);
    }//GEN-LAST:event_formWindowClosing

    private void table_flightMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_table_flightMouseClicked
        int row = table_flight.getSelectedRow(); // Ottiene l'indice della riga selezionata
        if (row != -1) { // Verifica se una riga è stata effettivamente selezionata
            setValuesFlight((String) table_flight.getValueAt(row, 0));
        }
    }//GEN-LAST:event_table_flightMouseClicked

    private void add_buttonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_add_buttonActionPerformed
        // Prendo, verifico e aggiungo il volo
        if (!touchFlightData(flight_code_textfield.getText(), source_textfield.getText(), destination_textfield.getText(), takeoff_textfield.getText(), seats_textfield.getText(), table_flight, true)) {
            errorButtonAnimation(add_button, ERROR_ADD_IMAGE, TIMER_ERROR, ERROR_SOUND, false);
        }
    }//GEN-LAST:event_add_buttonActionPerformed

    private void old_username_textfieldActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_old_username_textfieldActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_old_username_textfieldActionPerformed

    private void password_textfieldActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_password_textfieldActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_password_textfieldActionPerformed

    private void flight_code_textfield_tbActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_flight_code_textfield_tbActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_flight_code_textfield_tbActionPerformed

    private void edit_button_tbActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_edit_button_tbActionPerformed
        if (!touchTicketData(flight_code_textfield_tb.getText(), compagniaAereaGUI.getUsername(), surname_textfield.getText(), sex_textfield.getText(), seats_textfield1.getText(), ticket_list, false)) {
            errorButtonAnimation(edit_button_tb, ERROR_EDIT_IMAGE, TIMER_ERROR, ERROR_SOUND, false);
        }
    }//GEN-LAST:event_edit_button_tbActionPerformed

    private void add_button_tbActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_add_button_tbActionPerformed
        if (!touchTicketData(flight_code_textfield_tb.getText(), compagniaAereaGUI.getUsername(), surname_textfield.getText(), sex_textfield.getText().toUpperCase(), seats_textfield1.getText(), ticket_list, true)) {
            errorButtonAnimation(add_button_tb, ERROR_ADD_IMAGE, TIMER_ERROR, ERROR_SOUND, false);
        }

    }//GEN-LAST:event_add_button_tbActionPerformed

    private void table_flight_tbMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_table_flight_tbMouseClicked
        int row = table_flight_tb.getSelectedRow(); // Ottiene l'indice della riga selezionata
        if (row != -1) { // Verifica se una riga è stata effettivamente selezionata
            flight_code_textfield_tb.setText((String) table_flight_tb.getValueAt(row, 0));
        }
    }//GEN-LAST:event_table_flight_tbMouseClicked

    private void ticket_listMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_ticket_listMouseClicked
        int row = ticket_list.getSelectedRow(); // Ottiene l'indice della riga selezionata
        if (row != -1) { // Verifica se una riga è stata effettivamente selezionata
            setValuesTicket(compagniaAereaGUI.getUsername(), (String) ticket_list.getValueAt(row, 0));
        }
    }//GEN-LAST:event_ticket_listMouseClicked

    private void name_textfieldActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_name_textfieldActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_name_textfieldActionPerformed

    private void name_textfieldComponentShown(java.awt.event.ComponentEvent evt) {//GEN-FIRST:event_name_textfieldComponentShown

    }//GEN-LAST:event_name_textfieldComponentShown

    private void delete_credentials_buttonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_delete_credentials_buttonActionPerformed
        int response = showConfirmationDialog(DELETE_CREDENTIALS_TITLE, DELETE_CREDENTIALS_MESSAGE, JOptionPane.YES_NO_OPTION);

        // Ora puoi controllare la risposta dell'utente
        if (response == JOptionPane.YES_OPTION) {
            deleteFile(CompagniaAereaGUI.getFILENAME_LM());
            // Chiudi il programma
            System.exit(0);
        }
    }//GEN-LAST:event_delete_credentials_buttonActionPerformed

    private void delete_data_buttonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_delete_data_buttonActionPerformed
        int response = showConfirmationDialog(DELETE_CREDENTIALS_TITLE, DELETE_CREDENTIALS_MESSAGE, JOptionPane.YES_NO_OPTION);

        // Ora puoi controllare la risposta dell'utente
        if (response == JOptionPane.YES_OPTION) {
            deleteFile(FILENAME_CAM);
            // Chiudi il programma
            System.exit(0);
        }
    }//GEN-LAST:event_delete_data_buttonActionPerformed

    private void delete_user_buttonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_delete_user_buttonActionPerformed
        int row = admin_table.getSelectedRow(); // Ottiene l'indice della riga selezionata
        if (row != -1 && row != 0) { // Verifica se una riga è stata effettivamente selezionata
            // Ottiene l'username dalla tabella
            String username = (String) admin_table.getValueAt(row, 0);

            // Rimuove le credenziali corrispondenti all'username
            loginManager.removeCredentials(username);
            compagniaAereaGUI.setLoginManager(loginManager);

            // Aggiorna la tabella delle credenziali
            refreshCredentialsTable(admin_table);
        } else {
            errorButtonAnimation(delete_user_button, ERROR_DELETE_USER_IMAGE, TIMER_ERROR, ERROR_SOUND, false);
        }
    }//GEN-LAST:event_delete_user_buttonActionPerformed

    private void delete_ticketActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_delete_ticketActionPerformed
        int row = ticket_list.getSelectedRow(); // Ottiene l'indice della riga selezionata
        if (row != -1) { // Verifica se una riga è stata effettivamente selezionata
            // Ottiene l'username dalla tabella
            String flightCode = (String) ticket_list.getValueAt(row, 0);

            compagnia.deleteTicket(compagniaAereaGUI.getUsername(), flightCode);

            // Aggiorna la tabella delle credenziali
            refreshTicketTable(ticket_list);
        } else {
            errorButtonAnimation(delete_ticket, ERROR_DELETE_IMAGE, TIMER_ERROR, ERROR_SOUND, false);
        }
    }//GEN-LAST:event_delete_ticketActionPerformed

    private void edit_user_buttonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_edit_user_buttonActionPerformed
        if (!touchCredentialData(old_username_textfield.getText(), new_username_textfield.getText(), password_textfield.getText(), adminButtonFlag, admin_table, false)) {
            errorButtonAnimation(edit_user_button, ERROR_EDIT_IMAGE, TIMER_ERROR, ERROR_SOUND, false);
        } else {
            compagniaAereaGUI.setLoginManager(loginManager);
        }
    }//GEN-LAST:event_edit_user_buttonActionPerformed

    private void new_username_textfieldActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_new_username_textfieldActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_new_username_textfieldActionPerformed

    private void add_user_buttonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_add_user_buttonActionPerformed
        if (!touchCredentialData(old_username_textfield.getText(), "", password_textfield.getText(), adminButtonFlag, admin_table, true)) {
            errorButtonAnimation(add_user_button, ERROR_ADD_IMAGE, TIMER_ERROR, ERROR_SOUND, false);
        } else {
            compagniaAereaGUI.setLoginManager(loginManager);
        }
        // TODO add your handling code here: addCredentials(String username, String password, boolean type)
    }//GEN-LAST:event_add_user_buttonActionPerformed

    private void admin_trueActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_admin_trueActionPerformed
        adminButtonFlag = true;
    }//GEN-LAST:event_admin_trueActionPerformed

    private void admin_falseActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_admin_falseActionPerformed
        adminButtonFlag = false;
    }//GEN-LAST:event_admin_falseActionPerformed

    private void jScrollPane1MouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jScrollPane1MouseClicked
        // TODO add your handling code here:
    }//GEN-LAST:event_jScrollPane1MouseClicked

    private void admin_tableMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_admin_tableMouseClicked
        int row = admin_table.getSelectedRow(); // Ottiene l'indice della riga selezionata
        if (row != -1) { // Verifica se una riga è stata effettivamente selezionata
            setValuesCredentials((String) admin_table.getValueAt(row, 0));
        }
    }//GEN-LAST:event_admin_tableMouseClicked

    private void delete_ticket_mtActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_delete_ticket_mtActionPerformed
        int row = tickets_table.getSelectedRow(); // Ottiene l'indice della riga selezionata
        if (row != -1) { // Verifica se una riga è stata effettivamente selezionata
            // Ottiene l'username e flight code dalla tabella
            String flightCode = (String) tickets_table.getValueAt(row, 0);
            String username = (String) tickets_table.getValueAt(row, 1);

            compagnia.deleteTicket(username, flightCode);

            // Aggiorna la tabella dei biglietti
            refreshAllTicketsTable(tickets_table);
        } else {
            errorButtonAnimation(delete_ticket, ERROR_DELETE_IMAGE, TIMER_ERROR, ERROR_SOUND, false);
        }
    }//GEN-LAST:event_delete_ticket_mtActionPerformed

    private void tickets_tableMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_tickets_tableMouseClicked
        // TODO add your handling code here:
    }//GEN-LAST:event_tickets_tableMouseClicked

    private void search_settings_buttonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_search_settings_buttonActionPerformed
        setValuesCredentials(old_username_textfield.getText());
    }//GEN-LAST:event_search_settings_buttonActionPerformed

    private void sex_textfieldActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_sex_textfieldActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_sex_textfieldActionPerformed

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
                if ("Windows".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(CompagniaAereaSchermataGUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(CompagniaAereaSchermataGUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(CompagniaAereaSchermataGUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(CompagniaAereaSchermataGUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new CompagniaAereaSchermataGUI().setVisible(true);
            }
        });
    }

    //<editor-fold defaultstate="collapsed" desc=" Variables declaration - do not modify  ">
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton add_button;
    private javax.swing.JButton add_button_tb;
    private javax.swing.JButton add_user_button;
    private javax.swing.JRadioButton admin_false;
    private javax.swing.ButtonGroup admin_flag;
    private javax.swing.JLabel admin_settings_label;
    private javax.swing.JTable admin_table;
    private javax.swing.JRadioButton admin_true;
    private javax.swing.JButton back_button_ma;
    private javax.swing.JButton back_button_mt;
    private javax.swing.JButton back_button_s;
    private javax.swing.JButton back_button_tb;
    private javax.swing.JLabel background_mt;
    private javax.swing.JLabel background_s;
    private javax.swing.JLabel background_tb;
    private javax.swing.JButton delete_credentials_button;
    private javax.swing.JButton delete_data_button;
    private javax.swing.JButton delete_flight_button;
    private javax.swing.JButton delete_ticket;
    private javax.swing.JButton delete_ticket_mt;
    private javax.swing.JButton delete_user_button;
    private javax.swing.JLabel destination_label;
    private javax.swing.JTextField destination_textfield;
    private javax.swing.JButton edit_button;
    private javax.swing.JButton edit_button_tb;
    private javax.swing.JButton edit_user_button;
    private javax.swing.JLabel flight_code_label;
    private javax.swing.JLabel flight_code_label1;
    private javax.swing.JTextField flight_code_textfield;
    private javax.swing.JTextField flight_code_textfield_tb;
    private javax.swing.JPanel flight_listing_pannel;
    private javax.swing.JLabel flight_title_label;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JLabel manage_flight_background;
    private javax.swing.JLabel manage_flight_label;
    private javax.swing.JPanel manage_tickets_pannel;
    private javax.swing.JLabel name_label;
    private javax.swing.JTextField name_textfield;
    private javax.swing.JLabel new_username_settings_label;
    private javax.swing.JTextField new_username_textfield;
    private javax.swing.JLabel old_username_settings_label;
    private javax.swing.JTextField old_username_textfield;
    private javax.swing.JLabel password_settings_label;
    private javax.swing.JTextField password_textfield;
    private javax.swing.JScrollPane scroll_pannel;
    private javax.swing.JScrollPane scroll_pannel1;
    private javax.swing.JScrollPane scroll_pannel2;
    private javax.swing.JScrollPane scroll_pannel3;
    private javax.swing.JButton search_button;
    private javax.swing.JButton search_settings_button;
    private javax.swing.JLabel seats_label;
    private javax.swing.JLabel seats_tb_label;
    private javax.swing.JTextField seats_textfield;
    private javax.swing.JTextField seats_textfield1;
    private javax.swing.JLabel settings_label;
    private javax.swing.JPanel settings_pannel;
    private javax.swing.JLabel sex_label;
    private javax.swing.JTextField sex_textfield;
    private javax.swing.JLabel source_label;
    private javax.swing.JTextField source_textfield;
    private javax.swing.JLabel surname_label;
    private javax.swing.JTextField surname_textfield;
    private javax.swing.JPanel t_boarding_pannel;
    private javax.swing.JTable table_flight;
    private javax.swing.JTable table_flight_tb;
    private javax.swing.JLabel takeoff_label;
    private javax.swing.JTextField takeoff_textfield;
    private javax.swing.JLabel ticket_boarding_label;
    private javax.swing.JTable ticket_list;
    private javax.swing.JLabel tickets_label;
    private javax.swing.JTable tickets_table;
    private javax.swing.JLabel tickets_title_label;
    // End of variables declaration//GEN-END:variables
    //</editor-fold>
}
