package compagniaaerea;

/**
 *
 * @author joels
 */

public class MainTestCAM {

    public static void main(String[] args) {
         // Creazione di una compagnia aerea
        CompagniaAereaManager compagnia = new CompagniaAereaManager("company_data.dat");

        // Aggiunta di alcuni voli
        compagnia.addFlight(new Flight("FA123", "Roma", "Milano", "2024-03-05 10:00", 150));
        compagnia.addFlight(new Flight("FB456", "Milano", "Parigi", "2024-03-06 12:00", 200));
        compagnia.addFlight(new Flight("FC789", "Napoli", "Barcellona", "2024-03-07 14:30", 180));
        compagnia.addFlight(new Flight("FD012", "Venezia", "Londra", "2024-03-08 16:15", 220));
        compagnia.addFlight(new Flight("FE345", "Atene", "Amsterdam", "2024-03-09 18:45", 190));
        compagnia.addFlight(new Flight("FF678", "Berlino", "Madrid", "2024-03-10 20:30", 210));
        compagnia.addFlight(new Flight("FG901", "Zurigo", "Stoccolma", "2024-03-11 22:15", 170));
        compagnia.addFlight(new Flight("FH234", "Lisbona", "Dublino", "2024-03-12 09:30", 200));
        compagnia.addFlight(new Flight("FI567", "Vienna", "Varsavia", "2024-03-13 11:45", 180));
        compagnia.addFlight(new Flight("FJ890", "Budapest", "Praga", "2024-03-14 13:00", 190));
        compagnia.addFlight(new Flight("FK123", "Bruxelles", "Ginevra", "2024-03-15 15:15", 210));
        compagnia.addFlight(new Flight("FL456", "Oslo", "Helsinki", "2024-03-16 17:30", 170));

        // Aggiunta di biglietti di persone diverse
        compagnia.addTicket("FA123", 2, "Laura", "Bianchi", "F", false);
        compagnia.addTicket("FB456", 1, "Luca", "Verdi", "M", true);
        compagnia.addTicket("FC789", 3, "Giulia", "Rossi", "F", false);
        compagnia.addTicket("FD012", 4, "Marco", "Gialli", "M", true);
        compagnia.addTicket("FE345", 5, "Elena", "Neri", "F", false);
        compagnia.addTicket("FF678", 6, "Andrea", "Blu", "M", true);
        compagnia.addTicket("FG901", 7, "Valentina", "Arancioni", "F", false);
        compagnia.addTicket("FH234", 8, "Davide", "Viola", "M", true);
        compagnia.addTicket("FI567", 9, "Sara", "Rosa", "F", false);
        compagnia.addTicket("FJ890", 10, "Matteo", "Azzurri", "M", true);

        // Salvataggio e caricamento dei dati
        compagnia.saveData();
        compagnia.loadData();

    }
}
