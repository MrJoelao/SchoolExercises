using System.Data;
using MySql.Data.MySqlClient;

namespace Delta_Dent;

public class Paziente
{
    public string FirstName { get; set; }
    public string Surname { get; set; }
    public bool Gender { get; set; } // true = male, false = female
    public string Telephone { get; set; }
    public string Phone1 { get; set; }
    public string Phone2 { get; set; }
    public string CF { get; set; }
    public string CAsl { get; set; }
    public DateTime BirthDate { get; set; }
    public string BirthPlace { get; set; }
    public string BirthProvince { get; set; }
    public string Billable { get; set; }
    public bool Completed { get; set; }
    public bool Documented { get; set; }
    
    public bool Foreigner { get; set; }
    public bool Locked { get; set; }
    
    public int DoctorID { get; set; }

    // Costruttore con parametri
    public Paziente(string firstName, string surname, bool gender, string telephone, string phone1, string phone2,
        string cf, string cAsl, DateTime birthDate, string birthPlace, bool foreinger, string birthProvince, string billable,
        bool completed, bool documented, int doctorID, bool locked)
    {
        FirstName = firstName;
        Surname = surname;
        Gender = gender;
        Telephone = telephone;
        Phone1 = phone1;
        Phone2 = phone2;
        CF = cf;
        CAsl = cAsl;
        BirthDate = birthDate;
        BirthPlace = birthPlace;
        Foreigner = foreinger;
        BirthProvince = birthProvince;
        Billable = billable;
        Completed = completed;
        Documented = documented;
        DoctorID = doctorID;
        Locked = locked;
    }

    // Costruttore vuoto
    public Paziente()
    {
    }

    public void SaveInDB()
    {
        // Creo un'istanza di DbManager
        DbManager db = new DbManager(); // Uso i parametri di default impostati nel costruttore

        // Creo la query da eseguire
        string query = $"INSERT INTO PATIENT (doctorID, first_name, surname, gender, telephone, phone_1, phone_2, cf, c_asl, birth_date, birth_place, foreigner, birth_province, billable, completed, documented, locked) VALUES ('{DoctorID}', '{FirstName}', '{Surname}', {Gender}, '{Telephone}', '{Phone1}', '{Phone2}', '{CF}', '{CAsl}', '{BirthDate:yyyy-MM-dd}', '{BirthPlace}', {Foreigner}, '{BirthProvince}', '{Billable}', {Completed}, {Documented}, {Locked})";

        // Eseguo la query
        try
        {
            db.MakeQuery(query);
        }
        catch (Exception e)
        {
            Console.WriteLine("Errore durante l'inserimento del paziente: " + e.Message);
            throw;
        }
        
        db.CloseConnection();
    }

    public Paziente getFromDBReader(MySqlDataReader reader)
    {
        Paziente paziente = new Paziente();
        paziente.DoctorID = reader.GetInt32("doctorID");
        paziente.FirstName = reader.GetString("first_name");
        paziente.Surname = reader.GetString("surname");
        paziente.Gender = reader.GetBoolean("gender");
        paziente.Telephone = reader.GetString("telephone");
        paziente.Phone1 = reader.GetString("phone_1");
        paziente.Phone2 = reader.GetString("phone_2");
        paziente.CF = reader.GetString("cf");
        paziente.CAsl = reader.GetString("c_asl");
        paziente.BirthDate = reader.GetDateTime("birth_date");
        paziente.BirthPlace = reader.GetString("birth_place");
        paziente.BirthProvince = reader.GetString("birth_province");
        paziente.Foreigner = reader.GetBoolean("foreigner");
        paziente.Billable = reader.GetString("billable");
        paziente.Completed = reader.GetBoolean("completed");
        paziente.Documented = reader.GetBoolean("documented");
        paziente.Locked = reader.GetBoolean("locked");
        
        return paziente;
    }

    // Metodo ToString() per una rappresentazione leggibile dell'oggetto
    public override string ToString()
    {
        return $"{FirstName} {Surname}, Data di nascita: {BirthDate.ToShortDateString()}";
    }
}