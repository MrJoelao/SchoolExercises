package compagniaaerea;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

// Definizione della classe CompagniaAereaManager che implementa l'interfaccia Serializable
public class CompagniaAereaManager implements Serializable {

    private static final long serialVersionUID = 1; // Numero di versione per la serializzazione
    private ArrayList<Flight> flights; // ArrayList dei voli
    private ArrayList<Ticket> tickets; // ArrayList dei biglietti
    private String FILENAME; // Nome del file per il salvataggio dei dati

    // Costruttore della classe che accetta il nome del file come parametro
    public CompagniaAereaManager(String filename) {
        this.FILENAME = filename; // Inizializza il nome del file
        this.flights = new ArrayList<>(); // Inizializza la lista dei voli come un nuovo ArrayList
        this.tickets = new ArrayList<>(); // Inizializza la lista dei biglietti come un nuovo ArrayList
        loadData(); // Carica i dati al momento dell'inizializzazione
    }

    // Funzione per stampare un messaggio di avviso
    private void printMessage(String message) {
        System.out.println("[CAM] " + message);
    }

    // Funzione per stampare un messaggio di errore
    private void printErrorMessage(String errorMessage) {
        System.err.println("[CAM] Errore: " + errorMessage);
    }

    // Metodo per restituire la lista degli aerei
    public ArrayList<Flight> getFlights() {
        printMessage("Recupero della lista degli aerei in corso..."); // Stampa un messaggio di avviso
        return flights; // Restituisce la lista degli aerei
    }

    // Metodo per restituire la lista dei biglietti
    public ArrayList<Ticket> getTickets() {
        printMessage("Recupero della lista dei biglietti in corso..."); // Stampa un messaggio di avviso
        return tickets; // Restituisce la lista dei biglietti
    }

    // Metodo per ottenere un volo dato il codice del volo
    public Flight getFlight(String flightCode) {
        printMessage("Ricerca del volo: " + flightCode + " in corso...");

        for (Flight flight : flights) { // Itera attraverso la lista dei voli
            if (flight.getFlightCode().equals(flightCode)) { // Controlla se il codice del volo corrente corrisponde al codice specificato
                printMessage("Volo trovato");
                return flight; // Restituisce il volo se trovato
            }
        }
        printErrorMessage("Volo " + flightCode + " non trovato.");
        return null; // Se non troviamo il volo, restituiamo null
    }

    // Metodo per acquistare un biglietto
    public Ticket addTicket(String flightCode, int seatNumber, String username, String cognome, String sesso, boolean chooseRandomSeatIfOccupied) {
        printMessage("Acquisto del ticket in corso...");

        Flight flight = getFlight(flightCode); // Ottiene il volo associato al codice specificato
        
        if (flight != null) { // Se il volo esiste
            if (userHasTicketForFlight(username, flightCode)) {
                printErrorMessage("L'utente ha disponibile un biglietto per questo volo.");
                return null; // Restituisce null se l'utente ha già un biglietto per questo volo
            }

            if (isSeatOccupied(flight, seatNumber) || seatNumber > flight.getNSeats()) {
                if (chooseRandomSeatIfOccupied) {
                    seatNumber = chooseRandomAvailableSeat(flight);
                    if(seatNumber < 1){
                        printErrorMessage("Il posto " + seatNumber + " sul volo " + flightCode + " non disponibile.");
                        return null; // Restituisce null se il posto è già occupato e il flag non è impostato
                    }
                    printErrorMessage("Posto non disponibile, impostato automaticamente: " + seatNumber + " sul volo " + flightCode);
                } else {
                    printErrorMessage("Il posto " + seatNumber + " sul volo " + flightCode + " non disponibile.");
                    return null; // Restituisce null se il posto è già occupato e il flag non è impostato
                }
            }

            Passenger passenger = new Passenger(username, cognome, sesso);
            Ticket ticket = new Ticket(flight, passenger, seatNumber);
            tickets.add(ticket);

            saveData();

            printMessage("Acquisto del ticket avvenuto con successo");

            return ticket;
        } else {
            printErrorMessage("Si è verificato un errore nell'acquisto del ticket. Volo: " + flightCode + " non trovato.");
            return null; // Se non troviamo il volo, non possiamo vendere il biglietto
        }
    }

    // Metodo per verificare se l'utente ha già un biglietto per un determinato volo
    private boolean userHasTicketForFlight(String username, String flightCode) {
        for (Ticket ticket : tickets) {
            if (ticket.getPassenger().getName().equals(username) && ticket.getFlight().getFlightCode().equals(flightCode)) {
                return true; // Restituisce true se l'utente ha già un biglietto per questo volo
            }
        }
        return false; // Restituisce false se l'utente non ha un biglietto per questo volo
    }

    // Metodo per scegliere un posto casuale tra quelli disponibili
    private int chooseRandomAvailableSeat(Flight flight) {
        List<Integer> availableSeats = new ArrayList<>();
        for (int i = 1; i <= flight.getNSeats(); i++) {
            if (!isSeatOccupied(flight, i)) {
                availableSeats.add(i);
            }
        }
        if (availableSeats.isEmpty()) {
            printErrorMessage("Non ci sono posti disponibili sul volo " + flight.getFlightCode() + ".");
            return -1; // Restituisce -1 se non ci sono posti disponibili
        }
        Random random = new Random();
        return availableSeats.get(random.nextInt(availableSeats.size())); // Restituisce un posto casuale tra quelli disponibili
    }

    // Metodo per verificare se un posto è già occupato
    private boolean isSeatOccupied(Flight flight, int seatNumber) {
        for (Ticket ticket : tickets) {
            if (ticket.getFlight().equals(flight) && ticket.getSeatNumber() == seatNumber) {
                return true; // Restituisce true se il posto è già occupato
            }
        }
        return false; // Restituisce false se il posto non è occupato
    }

    // Metodo per cancellare un biglietto
    public boolean cancelTicket(Ticket ticket) {
        printMessage("Cancellazione del ticket in corso..."); // Stampa un messaggio di avviso
        try {
            printMessage("Cancellazione del ticket avvenuta con successo."); // Stampa un messaggio di conferma
            return tickets.remove(ticket); // Rimuove il biglietto dalla lista dei biglietti e restituisce true se la rimozione ha avuto successo
        } catch (Exception e) {
            printErrorMessage("Errore durante la cancellazione del ticket: " + e.getMessage()); // Stampa un messaggio di errore in caso di eccezione
            return false; // Restituisce false se si è verificato un errore durante la cancellazione
        }
    }

    // Metodo per ottenere i biglietti di un determinato utente
    public ArrayList<Ticket> getUserTickets(String username) {
        printMessage("Ricerca dei ticket per: " + username + " in corso..."); // Stampa un messaggio di avviso
        ArrayList<Ticket> userTickets = new ArrayList<>(); // Crea una nuova lista di biglietti per l'utente specificato
        for (Ticket ticket : tickets) { // Itera attraverso la lista dei biglietti
            if (ticket.getPassenger().getName().equals(username)) { // Controlla se il nome del passeggero corrente corrisponde all'utente specificato
                userTickets.add(ticket); // Aggiunge il biglietto alla lista degli utenti
            }
        }
        return userTickets; // Restituisce la lista dei biglietti dell'utente specificato
    }

    // Metodo per ottenere i passeggeri di un determinato volo
    public ArrayList<Passenger> getPassengersOnFlight(String flightCode) {
        printMessage("Calcolando i passeggeri del volo: " + flightCode + " in corso..."); // Stampa un messaggio di avviso
        Flight flight = getFlight(flightCode); // Ottiene il volo associato al codice specificato
        ArrayList<Passenger> passengersOnFlight = new ArrayList<>(); // Crea una nuova lista di passeggeri per il volo specificato
        if (flight != null) { // Se il volo esiste
            for (Ticket ticket : tickets) { // Itera attraverso la lista dei biglietti
                if (ticket.getFlight().getFlightCode().equals(flightCode)) { // Controlla se il codice del volo del biglietto corrente corrisponde al codice del volo specificato
                    passengersOnFlight.add(ticket.getPassenger()); // Aggiunge il passeggero alla lista dei passeggeri del volo
                }
            }
        }
        return passengersOnFlight; // Restituisce la lista dei passeggeri del volo specificato
    }

    // Metodo per ottenere i posti disponibili su un determinato volo
    public int getAvailableSeats(String flightCode) {
        printMessage("Calcolando i posti disponibili del volo: " + flightCode + " in corso..."); // Stampa un messaggio di avviso
        Flight flight = getFlight(flightCode); // Ottiene il volo associato al codice specificato
        if (flight != null) { // Se il volo esiste
            List<Passenger> passengers = getPassengersOnFlight(flightCode); // Ottiene i passeggeri del volo specificato
            printMessage("Calcolo avvenuto con successo."); // Stampa un messaggio di avviso
            return flight.getNSeats() - passengers.size(); // Restituisce il numero di posti disponibili sul volo
        } else {
            printErrorMessage("Si è verificato un errore nel calcolo di posti disponibili del volo: " + flightCode + ", volo non trovato."); // Stampa un messaggio di errore
            return -1; // Se non troviamo il volo, restituiamo -1 per indicare un errore
        }
    }

    // Metodo per verificare se un volo esiste già nella lista dei voli
    public boolean checkFlightExistence(String flightCode) {
        printMessage("Verifica esistenza del volo: " + flightCode + " in corso...");

        for (Flight flight : flights) { // Itera attraverso la lista dei voli
            if (flight.getFlightCode().equals(flightCode)) { // Controlla se il codice del volo corrente corrisponde al codice specificato
                printMessage("Volo presente nella lista.");
                return true; // Restituisce true se il volo esiste già
            }
        }

        printErrorMessage("Il volo non esiste nella lista.");
        return false; // Restituisce false se il volo non esiste nella lista
    }

    // Metodo per aggiungere un volo
    public boolean addFlight(Flight flight) {
        String flightCode = flight.getFlightCode();

        if (!checkFlightExistence(flightCode)) { // Verifica se il volo esiste già
            flights.add(flight); // Aggiunge il volo alla lista dei voli
            saveData(); //salvo le modifiche
            printMessage("Volo aggiunto con successo.");
            
            return true;
        } else {
            printErrorMessage("Impossibile aggiungere il volo. Il volo " + flightCode + " esiste nella lista.");
            return false;
        }
    }

    // Metodo per rimuovere i ticket associati a un determinato volo
    public void removeTicketsForFlight(String flightCode) {
        printMessage("Rimozione dei ticket associati al volo: " + flightCode + " in corso..."); // Stampa un messaggio di avviso
        List<Ticket> ticketsToRemove = new ArrayList<>(); // Crea una nuova lista per i ticket da rimuovere

        for (Ticket ticket : tickets) { // Itera attraverso la lista dei ticket
            if (ticket.getFlight().getFlightCode().equals(flightCode)) { // Controlla se il volo associato al ticket corrente corrisponde al volo specificato
                ticketsToRemove.add(ticket); // Aggiunge il ticket alla lista dei ticket da rimuovere
            }
        }

        if (!ticketsToRemove.isEmpty()) { // Se la lista dei ticket da rimuovere non è vuota
            tickets.removeAll(ticketsToRemove); // Rimuove tutti i ticket dalla lista dei ticket
            saveData(); // Salva le modifiche
            printMessage("Ticket associati al volo " + flightCode + " rimossi con successo."); // Stampa un messaggio di conferma
        } else {
            printErrorMessage("Non ci sono ticket associati al volo " + flightCode + ". Nessuna azione eseguita."); // Stampa un messaggio di avviso
        }
    }

    // Metodo per cancellare un volo e i ticket associati
    public boolean cancelFlight(String flightCode) {
        printMessage("Cancellazione del volo: " + flightCode + " in corso..."); // Stampa un messaggio di avviso

        Flight flightToRemove = getFlight(flightCode); // Ottiene il volo da rimuovere

        if (flightToRemove != null) { // Se il volo da rimuovere è diverso da null

            // Rimuove tutti i ticket associati al volo prima di eliminare il volo stesso
            removeTicketsForFlight(flightCode);

            flights.remove(flightToRemove); // Rimuove il volo dalla lista dei voli
            saveData(); // Salva le modifiche
            printMessage("Volo: " + flightCode + " cancellato correttamente insieme ai ticket associati."); // Stampa un messaggio di conferma

            return true; // Restituisce true in caso di successo
        } else {

            printErrorMessage("Si è verificato un errore nella cancellazione del volo: " + flightCode + ", volo non trovato."); // Stampa un messaggio di errore

            return false; // Restituisce false in caso di errore
        }
    }
    
    // Metodo per ottenere il numero totale di posti su un determinato volo
    public int getTotalSeats(String flightCode) {
        printMessage("Calcolando i posti totali del volo: " + flightCode + " in corso..."); // Stampa un messaggio di avviso
        Flight flight = getFlight(flightCode); // Ottiene il volo associato al codice specificato
        if (flight != null) { // Se il volo esiste
            printMessage("Calcolo avvenuto con successo."); // Stampa un messaggio di avviso
            return flight.getNSeats(); // Restituisce il numero totale di posti sul volo
        } else {
            printErrorMessage("Si è verificato un errore nel calcolo di posti totali del volo: " + flightCode + ", volo non trovato."); // Stampa un messaggio di errore
            return -1; // Se non troviamo il volo, restituiamo -1 per indicare un errore
        }
    }


    // Metodo per modificare un volo
    public boolean modifyFlight(String flightCode, String newSource, String newDestination, String newTakeOff, int newNSeats) {
        printMessage("Modificando volo: " + flightCode + " in corso..." + newNSeats); // Stampa un messaggio di avviso

        Flight flightToModify = getFlight(flightCode); // Imposta il volo da modificare come il volo corrente

        if (flightToModify != null) { // Se il volo da modificare è diverso da null

            flightToModify.setSource(newSource); // Imposta la nuova origine del volo
            flightToModify.setDestination(newDestination); // Imposta la nuova destinazione del volo
            flightToModify.setTakeOff(newTakeOff); // Imposta il nuovo orario di decollo del volo
            
            
            flightToModify.setNSeats(newNSeats); // Imposta il nuovo numero di posti disponibili sul volo

            saveData();//salvo i cambiamenti

            printMessage("Volo: " + flightCode + " modificato correttamente."); // Stampa un messaggio di conferma
            return true; // Restituisce true in caso di successo
        } else {
            printErrorMessage("Si è verificato un errore nella modifica del volo: " + flightCode + ", volo non trovato."); // Stampa un messaggio di errore
            return false; // Restituisce false in caso di errore
        }
    }

    // Metodo per ottenere un ticket dato l'username e il codice del volo
    public Ticket getTicketByUsernameAndFlightCode(String username, String flightCode) {
        printMessage("Ricerca del ticket per l'utente: " + username + " e il volo: " + flightCode + " in corso..."); // Stampa un messaggio di avviso

        for (Ticket ticket : tickets) { // Itera attraverso la lista dei biglietti
            if (ticket.getPassenger().getName().equals(username) && ticket.getFlight().getFlightCode().equals(flightCode)) { // Controlla se il biglietto corrente corrisponde all'utente e al volo specificati
                printMessage("Ticket trovato."); // Stampa un messaggio di conferma
                return ticket; // Restituisce il biglietto se trovato
            }
        }

        printErrorMessage("Ticket non trovato per l'utente: " + username + " e il volo: " + flightCode); // Stampa un messaggio di errore
        return null; // Restituisce null se il ticket non è stato trovato
    }

    // Metodo per modificare un ticket dato l'username e il codice del volo
    public boolean modifyTicket(String username, String flightCode, String newSurname, String newSex, int newSeatNumber, boolean chooseRandomSeatIfOccupied) {
        printMessage("Modifica del ticket in corso..."); // Stampa un messaggio di avviso
        
        for (Ticket ticket : tickets) { // Itera attraverso la lista dei biglietti
            if (ticket.getPassenger().getName().equals(username) && ticket.getFlight().getFlightCode().equals(flightCode)) { // Controlla se il biglietto corrente corrisponde all'utente e al volo specificati
                Passenger passenger = ticket.getPassenger(); // Ottiene il passeggero dal biglietto
                passenger.setSurname(newSurname); // Imposta il nuovo cognome del passeggero
                passenger.setSex(newSex); // Imposta il nuovo sesso del passeggero
                
                if (isSeatOccupied(getFlight(flightCode), newSeatNumber) || newSeatNumber > getFlight(flightCode).getNSeats()) {
                    if (chooseRandomSeatIfOccupied) {
                        newSeatNumber = chooseRandomAvailableSeat(getFlight(flightCode));
                        if(newSeatNumber < 1){
                            printErrorMessage("Il posto " + newSeatNumber + " sul volo " + flightCode + " non disponibile.");
                            return false; // Restituisce null se il posto è già occupato e il flag non è impostato
                        }
                        printErrorMessage("Posto non disponibile, impostato automaticamente: " + newSeatNumber + " sul volo " + flightCode);
                    } else {
                        printErrorMessage("Il posto " + newSeatNumber + " sul volo " + flightCode + " non disponibile.");
                        return false; // Restituisce null se il posto è già occupato e il flag non è impostato
                    }
                }
                
                ticket.setSeatNumber(newSeatNumber); // Imposta il nuovo numero di posto sul biglietto
                saveData(); //salvo le modifiche
                printMessage("Ticket modificato con successo."); // Stampa un messaggio di conferma
                return true; // Restituisce true in caso di successo
            }
        }

        printErrorMessage("Ticket non trovato per l'utente: " + username + " e il volo: " + flightCode); // Stampa un messaggio di errore
        return false; // Restituisce false se il ticket non è stato trovato
    }

    // Metodo per salvare i dati su file
    public void saveData() {
        printMessage("Salvataggio dei dati in corso..."); // Stampa un messaggio di avviso

        try (ObjectOutputStream outputStream = new ObjectOutputStream(new FileOutputStream(FILENAME))) {

            outputStream.writeObject(flights); // Scrive la lista dei voli sul file
            outputStream.writeObject(tickets); // Scrive la lista dei biglietti sul file

            printMessage("Dati salvati correttamente."); // Stampa un messaggio di conferma
        } catch (IOException e) {

            printErrorMessage("Errore durante il salvataggio dei dati: " + e.getMessage()); // Stampa un messaggio di errore
            e.printStackTrace(); // Stampa lo stack trace dell'eccezione
        }
    }

    // Metodo per caricare i dati da file
    public void loadData() {
        printMessage("Caricamento dei dati in corso..."); // Stampa un messaggio di avviso

        File file = new File(FILENAME); // Crea un oggetto File con il nome del file

        if (file.length() == 0) { // Controlla se la dimensione del file è zero (vuoto)

            printMessage("Contenuto del file vuoto. Caricamento saltato."); // Stampa un messaggio di avviso
            return; // Esci dal metodo senza fare nulla se il file è vuoto
        }
        try (ObjectInputStream inputStream = new ObjectInputStream(new FileInputStream(file))) {

            flights = (ArrayList<Flight>) inputStream.readObject(); // Legge la lista dei voli dal file
            tickets = (ArrayList<Ticket>) inputStream.readObject(); // Legge la lista dei biglietti dal file

            printMessage("Dati caricati correttamente."); // Stampa un messaggio di conferma
        } catch (FileNotFoundException e) {

            printErrorMessage("Il file non esiste. Creazione del file..."); // Stampa un messaggio di errore
            createEmptyFile(); // Crea un nuovo file vuoto se quello specificato non viene trovato

        } catch (IOException | ClassNotFoundException e) {

            printErrorMessage("Errore durante il caricamento dei dati: " + e.getMessage()); // Stampa un messaggio di errore
            e.printStackTrace(); // Stampa lo stack trace dell'eccezione
        }
    }

    // Metodo per eliminare un ticket dato l'username e il codice del volo
    public boolean deleteTicket(String username, String flightCode) {
        printErrorMessage("Eliminazione del ticket in corso..."); // Stampa un messaggio di avviso

        for (Ticket ticket : tickets) { // Itera attraverso la lista dei biglietti
            if (ticket.getPassenger().getName().equals(username) && ticket.getFlight().getFlightCode().equals(flightCode)) { // Controlla se il biglietto corrente corrisponde all'utente e al volo specificati
                if (tickets.remove(ticket)) { // Rimuove il biglietto dalla lista dei biglietti
                    saveData(); //salvo la modifica
                    printErrorMessage("Ticket eliminato con successo."); // Stampa un messaggio di conferma
                    return true; // Restituisce true se il ticket è stato eliminato con successo
                } else {
                    printErrorMessage("Errore durante l'eliminazione del ticket."); // Stampa un messaggio di errore
                    return false; // Restituisce false se si verifica un errore durante l'eliminazione del ticket
                }
            }
        }

        printErrorMessage("Ticket non trovato per l'utente: " + username + " e il volo: " + flightCode); // Stampa un messaggio di errore
        return false; // Restituisce false se il ticket non è stato trovato
    }

    // Metodo per creare un nuovo file vuoto
    private void createEmptyFile() {
        printErrorMessage("Creazione del file in corso..."); // Stampa un messaggio di avviso
        try {
            // Crea un nuovo file vuoto
            File file = new File(FILENAME); // Crea un oggetto File con il nome specificato
            file.createNewFile();

            printErrorMessage("Nuovo file creato: " + FILENAME); // Stampa un messaggio di conferma
        } catch (IOException e) {
            printErrorMessage("Errore durante la creazione del file vuoto: " + e.getMessage()); // Stampa un messaggio di errore
            e.printStackTrace(); // Stampa lo stack trace dell'eccezione
        }
    }
}
