package compagniaaerea;
import java.io.Serializable;

/**
 *
 * @author joels
 */ 
public class Passenger implements Serializable{
    private String name;
    private String surname;
    private String sex;

    public Passenger(String name, String surname, String sex) {
        this.name = name;
        this.surname = surname;
        this.sex = sex;
    }

    public String getName() {
        return name;
    }

    public String getSurname() {
        return surname;
    }

    public String getSex() {
        return sex;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public void setSex(String sex) {
        this.sex = sex;
    }
}
