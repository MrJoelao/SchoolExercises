using Bogus;
using Delta_Dent;
using MySql.Data.MySqlClient;

class DBPopulator
{
    public void Populator(bool FlagDoctor = false, bool FlagPatient = false, bool FlagVisit = false, bool FlagRecords = false)
    {
        // Istanziare il gestore del database
        var dbManager = new DbManager(
            server: "The-J-Computer",
            user: "user",
            password: "admin",
            database: "deltadentdb",
            port: "3306"
        );

        // Generazione dei dati casuali usando Bogus
        var faker = new Faker();

        // Riempimento della tabella DOCTOR
        for (int i = 0; i < 100 && FlagDoctor; i++)
        {
            string firstName = faker.Name.FirstName();
            string surname = faker.Name.LastName();
            bool gender = faker.PickRandom(true, false);
            DateTime birthDate = faker.Date.Past(50, DateTime.Now.AddYears(-20));
            string email = faker.Internet.Email();
            string password = faker.Internet.Password();
            string telephone = faker.Phone.PhoneNumber("##########");
            string phone1 = faker.Phone.PhoneNumber("##########");
            string phone2 = faker.Phone.PhoneNumber("##########");
            string address = faker.Address.StreetAddress();

            string query = @"
                INSERT INTO DOCTOR (first_name, surname, gender, birth_date, email, password, telephone, phone_1, phone_2, address) 
                VALUES (@firstName, @surname, @gender, @birthDate, @Email, @Password, @Telephone, @Phone1, @Phone2, @Address)
            ";
            MySqlCommand cmd = new MySqlCommand(query, dbManager.Conn);
            cmd.Parameters.AddWithValue("@firstName", firstName);
            cmd.Parameters.AddWithValue("@surname", surname);
            cmd.Parameters.AddWithValue("@gender", gender);
            cmd.Parameters.AddWithValue("@birthDate", birthDate);
            cmd.Parameters.AddWithValue("@Email", email);
            cmd.Parameters.AddWithValue("@Password", password);
            cmd.Parameters.AddWithValue("@Telephone", telephone);
            cmd.Parameters.AddWithValue("@Phone1", phone1);
            cmd.Parameters.AddWithValue("@Phone2", phone2);
            cmd.Parameters.AddWithValue("@Address", address);

            cmd.ExecuteNonQuery();
        }

        // Riempimento della tabella PATIENT
        for (int i = 0; i < 200 && FlagPatient; i++)
        {
            int doctorID = 1; //faker.Random.Int(1, 100);
            string firstName = faker.Name.FirstName();
            string surname = faker.Name.LastName();
            bool gender = faker.PickRandom(true, false);
            string telephone = faker.Phone.PhoneNumber("##########");
            string phone1 = faker.Phone.PhoneNumber("##########");
            string phone2 = faker.Phone.PhoneNumber("##########");
            string cf = faker.Random.AlphaNumeric(16).ToUpper();
            string c_asl = faker.Random.AlphaNumeric(5).ToUpper();
            DateTime birthDate = faker.Date.Past(50, DateTime.Now.AddYears(-20));
            string birthPlace = faker.Address.City();
            string birthProvince = faker.Address.StateAbbr();
            bool foreigner = faker.PickRandom(true, false);
            string billable = "NO MANNAGGIA";
            bool completed = faker.PickRandom(true, false);
            bool documented = faker.PickRandom(true, false);
            bool locked = faker.PickRandom(true, false);

            string query = @"
                INSERT INTO PATIENT (doctorID, first_name, surname, gender, telephone, phone_1, phone_2, cf, c_asl, birth_date, birth_place, birth_province, foreigner, billable, completed, documented, locked) 
                VALUES (@doctorID, @firstName, @surname, @gender, @Telephone, @Phone1, @Phone2, @CF, @C_ASL, @BirthDate, @BirthPlace, @BirthProvince, @Foreigner, @Billable, @Completed, @Documented, @Locked)
            ";
            MySqlCommand cmd = new MySqlCommand(query, dbManager.Conn);
            cmd.Parameters.AddWithValue("@doctorID", doctorID);
            cmd.Parameters.AddWithValue("@firstName", firstName);
            cmd.Parameters.AddWithValue("@surname", surname);
            cmd.Parameters.AddWithValue("@gender", gender);
            cmd.Parameters.AddWithValue("@Telephone", telephone);
            cmd.Parameters.AddWithValue("@Phone1", phone1);
            cmd.Parameters.AddWithValue("@Phone2", phone2);
            cmd.Parameters.AddWithValue("@CF", cf);
            cmd.Parameters.AddWithValue("@C_ASL", c_asl);
            cmd.Parameters.AddWithValue("@BirthDate", birthDate);
            cmd.Parameters.AddWithValue("@BirthPlace", birthPlace);
            cmd.Parameters.AddWithValue("@BirthProvince", birthProvince);
            cmd.Parameters.AddWithValue("@Foreigner", foreigner);
            cmd.Parameters.AddWithValue("@Billable", billable);
            cmd.Parameters.AddWithValue("@Completed", completed);
            cmd.Parameters.AddWithValue("@Documented", documented);
            cmd.Parameters.AddWithValue("@Locked", locked);

            cmd.ExecuteNonQuery();
        }

        // Riempimento della tabella VISIT
        for (int i = 0; i < 5000 && FlagVisit; i++)
        {
            int patientID = faker.Random.Int(1, 1000);

            // Verifica se il patientID esiste nella tabella PATIENT
            bool patientExists = CheckIfPatientExists(patientID, dbManager);

            if (!patientExists)
            {
                Console.WriteLine($"Attenzione: patientID {patientID} non esiste nella tabella PATIENT. Skipping visit insertion.");
                continue; // Salta l'inserimento di questa visita
            }

            // Continua con l'inserimento nella tabella VISIT
            int doctorID = faker.Random.Int(1, 100);
            int creator = faker.Random.Int(1, 100);
            DateTime date = faker.Date.Past(2);
            string diagnosis = faker.Lorem.Sentence();
            string performedTherapy = faker.Lorem.Sentence();
            string prescribedTherapy = faker.Lorem.Sentence();
            DateTime lastModified = faker.Date.Recent();
            string hygiene = faker.Lorem.Word();
            double revenue = faker.Random.Double(50, 500);
            double advance = faker.Random.Double(0, 100);

            string query = @"
                INSERT INTO VISIT (patientID, doctorID, date, diagnosis, performed_therapy, prescribed_therapy, creator, last_modified, hygiene, revenue, advance) 
                VALUES (@patientID, @doctorID, @Date, @Diagnosis, @PerformedTherapy, @PrescribedTherapy, @Creator, @LastModified, @Hygiene, @Revenue, @Advance)
            ";
            MySqlCommand cmd = new MySqlCommand(query, dbManager.Conn);
            cmd.Parameters.AddWithValue("@patientID", patientID);
            cmd.Parameters.AddWithValue("@doctorID", doctorID);
            cmd.Parameters.AddWithValue("@Date", date);
            cmd.Parameters.AddWithValue("@Diagnosis", diagnosis);
            cmd.Parameters.AddWithValue("@PerformedTherapy", performedTherapy);
            cmd.Parameters.AddWithValue("@PrescribedTherapy", prescribedTherapy);
            cmd.Parameters.AddWithValue("@Creator", creator);
            cmd.Parameters.AddWithValue("@LastModified", lastModified);
            cmd.Parameters.AddWithValue("@Hygiene", hygiene);
            cmd.Parameters.AddWithValue("@Revenue", revenue);
            cmd.Parameters.AddWithValue("@Advance", advance);

            cmd.ExecuteNonQuery();
        }

        // Riempimento della tabella RECORDS
        for (int i = 0; i < 1000 && FlagRecords; i++)
        {
            int patientID = faker.Random.Int(1, 1000);

            string query = @"
                INSERT INTO RECORDS (patientID) 
                VALUES (@patientID)
            ";
            MySqlCommand cmd = new MySqlCommand(query, dbManager.Conn);
            cmd.Parameters.AddWithValue("@patientID", patientID);

            cmd.ExecuteNonQuery();
        }

        // Chiusura della connessione
        dbManager.CloseConnection();
        Console.WriteLine("Dati inseriti con successo!");
    }
    
    private bool CheckIfPatientExists(int patientID, DbManager dbManager)
    {
        string query = "SELECT COUNT(*) FROM PATIENT WHERE patientID = @patientID";
        MySqlCommand cmd = new MySqlCommand(query, dbManager.Conn);
        cmd.Parameters.AddWithValue("@patientID", patientID);

        // Esegui la query per contare le righe corrispondenti
        int count = Convert.ToInt32(cmd.ExecuteScalar());

        // Se count è maggiore di zero, il patientID esiste
        return count > 0;
    }

}
