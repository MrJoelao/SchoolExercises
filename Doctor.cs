namespace Delta_Dent;

public class Doctor
{
    public string FirstName { get; set; }
    public string Surname { get; set; }
    public bool Gender { get; set; }
    public DateTime BirthDate { get; set; }
    public string Email { get; set; }
    public string Password { get; set; }
    public string Telephone { get; set; }
    public string Address { get; set; }
    public int DoctorId { get; set; }

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
    /// <param name="DoctorID">The address of the doctor.</param>
    public Doctor(string firstName, string surname, bool gender, DateTime birthDate, string email, string password,
            string telephone, string address)
    {
        FirstName = firstName;
        Surname = surname;
        Gender = gender;
        BirthDate = birthDate;
        Email = email;
        Password = password;
        Telephone = telephone;
        Address = address;
    }

    public Doctor()
    {

    }

    /// <summary>
    /// Checks the validity of the doctor's input fields. 
    /// If the password change flag is true, it also checks the password.
    /// </summary>
    /// <param name="flagCheckPassword">Indicates if the password should be checked.</param>
    /// <returns>Returns true if all inputs are valid, otherwise false.</returns>
    public bool CheckInputs(bool flagCheckPassword)
    {
        // Verifica campi obbligatori
        if (string.IsNullOrEmpty(FirstName) ||
            string.IsNullOrEmpty(Surname) ||
            string.IsNullOrEmpty(Email) ||
            string.IsNullOrEmpty(Telephone) ||
            string.IsNullOrEmpty(Address) ||
            BirthDate < DateTime.MinValue ||
            BirthDate > DateTime.MaxValue ||
            (Gender != true && Gender != false))
        {
            return false; // Restituisce false se uno dei campi obbligatori non è valido
        }

        // Verifica la password solo se il flag è true
        if (flagCheckPassword && string.IsNullOrEmpty(Password))
        {
            return false; // Restituisce false se il flag è true e la password è vuota
        }

        return true; // Restituisce true se tutti i campi sono validi
    }

}