namespace Delta_Dent;

public class Doctor
{
    public string firstName { get; set; }
    public string surname { get; set; }
    public bool gender { get; set; }
    public DateTime birthDate { get; set; }
    public string email { get; set; }
    public string password { get; set; }
    public string telephone { get; set; }
    public string address { get; set; }

    /// <summary>
    /// Initializes a new instance of the <see cref="Doctor"/> class with specified details.
    /// </summary>
    /// <param name="firstName">The first name of the doctor.</param>
    /// <param name="surname">The surname of the doctor.</param>
    /// <param name="gender">The gender of the doctor. True for male, false for female.</param>
    /// <param name="birthDate">The birth date of the doctor.</param>
    /// <param name="email">The email address of the doctor.</param>
    /// <param name="password">The password for the doctor's account.</param>
    /// <param name="telephone">The telephone number of the doctor.</param>
    /// <param name="address">The address of the doctor.</param>
    public Doctor(string firstName, string surname, bool gender, DateTime birthDate, string email, string password,
            string telephone, string address)
    {
        this.firstName = firstName;
        this.surname = surname;
        this.birthDate = birthDate;
        this.email = email;
        this.password = password;
        this.telephone = telephone;
        this.address = address;
    }

    public Doctor()
    {

    }

// Metodo per verificare i valori
    public bool AreValuesInvalid()
    {
        if (string.IsNullOrEmpty(firstName) ||
            string.IsNullOrEmpty(surname) ||
            string.IsNullOrEmpty(email) ||
            string.IsNullOrEmpty(password) ||
            string.IsNullOrEmpty(telephone) ||
            string.IsNullOrEmpty(address) ||
            birthDate < DateTime.MinValue ||
            birthDate > DateTime.MaxValue ||
            gender != true && gender != false)
        {
            return false; // Restituisce true se uno dei campi non è valido
        }

        return true; // Restituisce false se tutti i campi sono validi
    }
}