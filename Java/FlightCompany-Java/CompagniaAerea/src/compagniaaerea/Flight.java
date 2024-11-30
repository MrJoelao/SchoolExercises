package compagniaaerea;
import java.io.Serializable;

/**
 *
 * @author joels
 */
public class Flight implements Serializable{
    private String flightCode;
    private String source;
    private String destination;
    private String takeOff;
    private int nSeats;

    public Flight(String flightCode, String source, String destination, String takeOff, int nSeats) {
        this.flightCode = flightCode;
        this.source = source;
        this.destination = destination;
        this.takeOff = takeOff;
        this.nSeats = nSeats;
    }

    public String getFlightCode() {
        return flightCode;
    }

    public String getSource() {
        return source;
    }

    public String getDestination() {
        return destination;
    }

    public String getTakeOff() {
        return takeOff;
    }

    public int getNSeats() {
        return nSeats;
    }

    public void setFlightCode(String flightCode) {
        this.flightCode = flightCode;
    }

    public void setSource(String source) {
        this.source = source;
    }

    public void setDestination(String destination) {
        this.destination = destination;
    }

    public void setTakeOff(String takeOff) {
        this.takeOff = takeOff;
    }

    public void setNSeats(int nSeats) {
        this.nSeats = nSeats;
    }
}
