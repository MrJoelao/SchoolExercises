package compagniaaerea;
import java.io.Serializable;

/**
 *
 * @author joels
 */
public class Ticket implements Serializable{
    private Flight flight;
    private Passenger passenger;
    private int seatNumber;

    public Ticket(Flight flight, Passenger passenger, int seatNumber) {
        this.flight = flight;
        this.passenger = passenger;
        this.seatNumber = seatNumber;
    }

    public Flight getFlight() {
        return flight;
    }

    public Passenger getPassenger() {
        return passenger;
    }

    public int getSeatNumber() {
        return seatNumber;
    }

    public void setFlight(Flight flight) {
        this.flight = flight;
    }

    public void setPassenger(Passenger passenger) {
        this.passenger = passenger;
    }

    public void setSeatNumber(int seatNumber) {
        this.seatNumber = seatNumber;
    }

}
