namespace Delta_Dent;

public class Doctor
{
    private string firstName { get; set; }
    private string surname { get; set; }
    private bool gender { get; set; }
    private DateTime birthDate { get; set; }
    private string email { get; set; }
    private string password { get; set; }
    private string telephone { get; set; }
    private string address { get; set; }

    public Doctor(string firstName, string surname, bool gender, DateTime birthDate, string email, string password, string telephone, string address)
    {
        this.firstName = firstName;
        this.surname = surname;
        this.birthDate = birthDate;
        this.email = email;
        this.password = password;
        this.telephone = telephone;
        this.address = address;
    }
}