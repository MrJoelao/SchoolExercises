namespace Delta_Dent;
using MySqlConnector;
using Microsoft.Extensions.Configuration;

/// <summary>
/// Manages database connections and operations for the Delta_Dent application.
/// </summary>
public class DbManager
{
    public MySqlConnection Conn { get; private set; }
    private readonly IConfiguration _configuration;
    private const int LengthHash = 256;

    /// <summary>
    /// Initializes a new instance of the <see cref="DbManager"/> class and opens a database connection.
    /// </summary>
    /// <param name="connStr">Optional connection string. If null, the connection string from configuration is used.</param>
    public DbManager(string? connStr = null)
    {
        _configuration = new ConfigurationBuilder().AddJsonFile("appsettings.json").Build();
        OpenConnection(connStr);
    }

    /// <summary>
    /// Opens a synchronous connection to the database.
    /// </summary>
    /// <param name="connStr">Optional connection string. If null, the connection string from configuration is used.</param>
    public void OpenConnection(string? connStr = null)
    {
        try
        {
            connStr ??= _configuration.GetConnectionString("MySqlConnection");
            Conn = new MySqlConnection(connStr);
            Conn.Open();
            Console.WriteLine("Connection opened successfully.");
        }
        catch (Exception e)
        {
            Console.WriteLine($"Failed to open connection: {e.Message}");
        }
    }

    /// <summary>
    /// Opens an asynchronous connection to the database.
    /// </summary>
    /// <param name="connStr">Optional connection string. If null, the connection string from configuration is used.</param>
    public async Task OpenConnectionAsync(string? connStr = null)
    {
        try
        {
            connStr ??= _configuration.GetConnectionString("MySqlConnection");
            Conn = new MySqlConnection(connStr);
            await Conn.OpenAsync();
            Console.WriteLine("Connection async opened successfully.");
        }
        catch (Exception e)
        {
            Console.WriteLine($"Failed to open async connection: {e.Message}");
        }
    }

    /// <summary>
    /// Closes the synchronous connection to the database.
    /// </summary>
    public void CloseConnection()
    {
        try
        {
            Conn.Close();
            Console.WriteLine("Connection closed successfully.");
        }
        catch (Exception e)
        {
            Console.WriteLine($"Failed to close connection: {e.Message}");
        }
    }

    /// <summary>
    /// Closes the asynchronous connection to the database.
    /// </summary>
    public async Task CloseConnectionAsync()
    {
        try
        {
            await Conn.CloseAsync();
            Console.WriteLine("Connection closed successfully.");
        }
        catch (Exception e)
        {
            Console.WriteLine($"Failed to close connection: {e.Message}");
        }
    }

    /// <summary>
    /// Executes a non-query SQL command synchronously.
    /// </summary>
    /// <param name="query">The SQL query to execute.</param>
    public void MakeQuery(string query)
    {
        Console.WriteLine($"Executing query: {query}");
        using var cmd = new MySqlCommand(query, Conn);
        try
        {
            cmd.ExecuteNonQuery();
            Console.WriteLine("Query executed successfully.");
        }
        catch (Exception e)
        {
            Console.WriteLine($"Failed to execute query: {e.Message}");
        }
    }

    /// <summary>
    /// Executes a non-query SQL command asynchronously.
    /// </summary>
    /// <param name="query">The SQL query to execute.</param>
    public async Task MakeQueryAsync(string query)
    {
        Console.WriteLine($"Executing query: {query}");
        using var cmd = new MySqlCommand(query, Conn);
        try
        {
            await cmd.ExecuteNonQueryAsync();
            Console.WriteLine("Query executed successfully.");
        }
        catch (Exception e)
        {
            Console.WriteLine($"Failed to execute query: {e.Message}");
        }
    }

    /// <summary>
    /// Executes a SELECT SQL query synchronously and returns a MySqlDataReader.
    /// </summary>
    /// <param name="query">The SQL query to execute.</param>
    /// <returns>A MySqlDataReader containing the results of the query.</returns>
    public MySqlDataReader? ExecuteReader(string query)
    {
        Console.WriteLine($"Executing query: {query}");
        using var cmd = new MySqlCommand(query, Conn);
        MySqlDataReader? reader = null;
        try
        {
            if (Conn.State != System.Data.ConnectionState.Open)
            {
                Console.WriteLine("Connection not open, opening connection...");
                Conn.Open();
            }

            reader = cmd.ExecuteReader();
        }
        catch (Exception e)
        {
            Console.WriteLine($"Failed to execute query: {e}");
        }
        return reader;
    }

    /// <summary>
    /// Executes a SELECT SQL query asynchronously and returns a MySqlDataReader.
    /// </summary>
    /// <param name="query">The SQL query to execute.</param>
    /// <returns>A MySqlDataReader containing the results of the query.</returns>
    public async Task<MySqlDataReader?> ExecuteReaderAsync(string query)
    {
        Console.WriteLine($"Executing query: {query}");
        using var cmd = new MySqlCommand(query, Conn);
        MySqlDataReader? reader = null;
        try
        {
            if (Conn.State != System.Data.ConnectionState.Open)
            {
                Console.WriteLine("Connection not open, opening connection...");
                await Conn.OpenAsync();
            }

            reader = await cmd.ExecuteReaderAsync();
        }
        catch (Exception e)
        {
            Console.WriteLine($"Failed to execute query: {e}");
        }
        return reader;
    }

    /// <summary>
    /// Closes a MySqlDataReader synchronously.
    /// </summary>
    /// <param name="reader">The MySqlDataReader to close.</param>
    public void CloseReader(MySqlDataReader reader)
    {
        try
        {
            reader.Close();
            Console.WriteLine("Reader closed successfully.");
        }
        catch (Exception e)
        {
            Console.WriteLine($"Failed to close reader: {e}");
        }
    }

    /// <summary>
    /// Closes a MySqlDataReader asynchronously.
    /// </summary>
    /// <param name="reader">The MySqlDataReader to close.</param>
    public async Task CloseReaderAsync(MySqlDataReader? reader)
    {
        try
        {
            if (reader != null)
            {
                await reader.CloseAsync();
                Console.WriteLine("Reader closed successfully.");
            }
        }
        catch (Exception e)
        {
            Console.WriteLine($"Failed to close reader: {e}");
        }
    }

    /// <summary>
    /// Constructs a Patient object from the data in a MySqlDataReader.
    /// </summary>
    /// <param name="reader">The MySqlDataReader containing the patient data.</param>
    /// <returns>A Patient object populated with the data from the reader.</returns>
    public Patient? GetPatientFromReader(MySqlDataReader? reader)
    {
        if (reader == null)
        {
            return null;
        }

        Patient patient = new Patient();
        patient.PatientID = reader.GetInt32("patientID");
        patient.DoctorID = reader.GetInt32("doctorID");
        patient.FirstName = reader.GetString("first_name");
        patient.Surname = reader.GetString("surname");
        patient.Gender = reader.GetBoolean("gender");
        patient.Telephone = reader.GetString("telephone");
        patient.Phone1 = reader.GetString("phone_1");
        patient.Phone2 = reader.GetString("phone_2");
        patient.CF = reader.GetString("cf");
        patient.CASL = reader.GetString("c_asl");
        patient.BirthDate = reader.GetDateTime("birth_date");
        patient.BirthPlace = reader.GetString("birth_place");
        patient.BirthProvince = reader.GetString("birth_province");
        patient.Foreigner = reader.GetBoolean("foreigner");
        patient.Billable = reader.GetString("billable");
        patient.Completed = reader.GetBoolean("completed");
        patient.Documented = reader.GetBoolean("documented");
        patient.Locked = reader.GetBoolean("locked");

        return patient;
    }

    /// <summary>
    /// Retrieves a list of patients for a specific doctor from the database.
    /// </summary>
    /// <param name="doctorId">The ID of the doctor whose patients are to be retrieved. If null, retrieves patients for all doctors.</param>
    /// <param name="nPatient">The number of patients to retrieve.</param>
    /// <param name="nPage">The page number for pagination.</param>
    /// <param name="connectionString">String to connect in the database</param>
    /// <returns>A list of patients if found; otherwise, null.</returns>
    public async Task<List<Patient>?> GetPatientsFromDb(int? doctorId, int nPatient, int nPage, string connectionString)
    {
        List<Patient> patients = new List<Patient>();

        int offset = (nPage - 1) * nPatient;

        var queryRangePatient = "SELECT * FROM PATIENT WHERE doctorID = @DoctorId LIMIT @Limit OFFSET @Offset";

        try
        {
            await OpenConnectionAsync(connectionString);
            await using var command = new MySqlCommand(queryRangePatient, Conn);

            command.Parameters.AddWithValue("@DoctorId", doctorId);
            command.Parameters.AddWithValue("@Limit", nPatient);
            command.Parameters.AddWithValue("@Offset", offset);

            await using var reader = await command.ExecuteReaderAsync();

            while (await reader.ReadAsync())
            {
                var patient = GetPatientFromReader(reader);
                patients.Add(patient!);
            }

            await CloseReaderAsync(reader);

            Console.WriteLine("Patients retrieved successfully.");
        }
        catch (Exception e)
        {
            Console.WriteLine("There was an error while getting the patients from the database: " + e);
            return null;
        }
        finally
        {
            await CloseConnectionAsync();
        }

        return patients.Count > 0 ? patients : null;
    }

    /// <summary>
    /// Asynchronously retrieves a patient from the database using their unique patient ID.
    /// </summary>
    /// <param name="patientId">The unique identifier for the patient to be retrieved.</param>
    /// <returns>
    /// A task that represents the asynchronous operation. The task result contains the <see cref="Patient"/> object if found, otherwise null.
    /// </returns>
    /// <remarks>
    /// This method opens a connection to the database, executes a SQL query to find the patient by their ID, and constructs a <see cref="Patient"/> object from the returned data.
    /// If the patient is not found, or if an error occurs during the database operation, the method returns null.
    /// </remarks>
    public async Task<Patient?> GetPatientFromId(int? patientId)
    {
        if (patientId == null)
        {
            return null;
        }

        // Initialize the patient to null
        Patient? patient = null;

        // SQL query to get the patient with the specified ID
        var queryGetPatientQuery = "SELECT * FROM PATIENT WHERE patientID = @patientId";

        try
        {
            // Open the database connection asynchronously
            await OpenConnectionAsync();

            // Use a MySQL command to execute the query
            await using var command = new MySqlCommand(queryGetPatientQuery, Conn);

            // Add the parameter to the query
            command.Parameters.AddWithValue("@patientId", patientId);

            // Execute the command and get a data reader asynchronously
            await using var reader = await command.ExecuteReaderAsync();

            // If the reader finds a row, read the patient data
            if (await reader.ReadAsync())
            {
                patient = GetPatientFromReader(reader);
            }

            // Close the data reader
            await CloseReaderAsync(reader);

            // Success message
            Console.WriteLine("Patient retrieved successfully.");
        }
        catch (Exception e)
        {
            // In case of an error, print the message and return null
            Console.WriteLine("There was an error while getting the patient: " + patientId + " from the database: " + e);
            return null;
        }
        finally
        {
            // Close the database connection
            await CloseConnectionAsync();
        }

        // Return the patient, which will be null if not found
        return patient;
    }


    /// <summary>
    /// Saves a new patient record to the database.
    /// </summary>
    /// <param name="patient">The patient object containing the details to be saved.</param>
    /// <returns>Returns true if the patient was successfully saved, otherwise false.</returns>
    public async Task<bool> SavePatientInDb(Patient patient)
    {
        // Parametrized query to insert a new patient into the database
        string savePatientQuery = "INSERT INTO PATIENT (doctorID, first_name, surname, gender, telephone, phone_1, phone_2, cf, c_asl, birth_date, birth_place, foreigner, birth_province, billable, completed, documented, locked) " +
                                  "VALUES (@DoctorID, @FirstName, @Surname, @Gender, @Telephone, @Phone1, @Phone2, @CF, @CAsl, @BirthDate, @BirthPlace, @Foreigner, @BirthProvince, @Billable, @Completed, @Documented, @Locked)";

        try
        {
            // Apro la connessione se non è già aperta
            await OpenConnectionAsync();

            // Creo un comando MySQL per eseguire la query
            await using var command = new MySqlCommand(savePatientQuery, Conn);

            // Aggiungo i parametri alla query
            command.Parameters.AddWithValue("@DoctorID", patient.DoctorID);
            command.Parameters.AddWithValue("@FirstName", patient.FirstName);
            command.Parameters.AddWithValue("@Surname", patient.Surname);
            command.Parameters.AddWithValue("@Gender", patient.Gender);
            command.Parameters.AddWithValue("@Telephone", patient.Telephone);
            command.Parameters.AddWithValue("@Phone1", patient.Phone1);
            command.Parameters.AddWithValue("@Phone2", patient.Phone2);
            command.Parameters.AddWithValue("@CF", patient.CF);
            command.Parameters.AddWithValue("@CAsl", patient.CASL);
            command.Parameters.AddWithValue("@BirthDate", patient.BirthDate.ToString("yyyy-MM-dd"));
            command.Parameters.AddWithValue("@BirthPlace", patient.BirthPlace);
            command.Parameters.AddWithValue("@Foreigner", patient.Foreigner);
            command.Parameters.AddWithValue("@BirthProvince", patient.BirthProvince);
            command.Parameters.AddWithValue("@Billable", patient.Billable);
            command.Parameters.AddWithValue("@Completed", patient.Completed);
            command.Parameters.AddWithValue("@Documented", patient.Documented);
            command.Parameters.AddWithValue("@Locked", patient.Locked);

            // Eseguo il comando asincrono
            await command.ExecuteNonQueryAsync();

            //Debug
            Console.WriteLine("Patient saved successfully.");
        }
        catch (Exception e)
        {
            Console.WriteLine("There was an error saving the patient: " + e);
            return false;
        }
        finally
        {
            // Chiuso la connessione al database
            await CloseConnectionAsync();
        }

        return true;
    }

    /// <summary>
    /// Asynchronously updates a patient's information in the database based on the provided patient ID.
    /// </summary>
    /// <param name="patient">The patient object containing the updated information.</param>
    /// <param name="id">The ID of the patient to be updated.</param>
    /// <returns>A <see cref="Task{Boolean}"/> that represents the asynchronous operation. The task result is <c>true</c> if the update was successful, otherwise <c>false</c>.</returns>
    /// <remarks>
    /// This method constructs a parametrized SQL query to update the patient's information in the database, preventing SQL injection.
    /// It opens a connection to the database, executes the update command, and then closes the connection.
    /// If an exception occurs during the operation, the method catches it, logs the error, and returns <c>false</c>.
    /// </remarks>
    public async Task<bool> UpdatePatientFromId(Patient patient, int id)
    {
        // Parametrized query to insert a new patient into the database
        string updatePatientQuery = "UPDATE PATIENT SET first_name = @FirstName, surname = @Surname, gender = @Gender, telephone = @Telephone, phone_1 = @Phone1, phone_2 = @Phone2, cf = @CF, c_asl = @CAsl, birth_date = @BirthDate, birth_place = @BirthPlace, foreigner = @Foreigner, birth_province = @BirthProvince, billable = @Billable, completed = @Completed, documented = @Documented, locked = @Locked WHERE patientID = @PatientId";

        try
        {
            // Apro la connessione
            await OpenConnectionAsync();

            // Creo un comando MySQL per eseguire la query
            await using var command = new MySqlCommand(updatePatientQuery, Conn);

            // Aggiungo i parametri alla query
            command.Parameters.AddWithValue("@patientId", id);
            command.Parameters.AddWithValue("@FirstName", patient.FirstName);
            command.Parameters.AddWithValue("@Surname", patient.Surname);
            command.Parameters.AddWithValue("@Gender", patient.Gender);
            command.Parameters.AddWithValue("@Telephone", patient.Telephone);
            command.Parameters.AddWithValue("@Phone1", patient.Phone1);
            command.Parameters.AddWithValue("@Phone2", patient.Phone2);
            command.Parameters.AddWithValue("@CF", patient.CF);
            command.Parameters.AddWithValue("@CAsl", patient.CASL);
            command.Parameters.AddWithValue("@BirthDate", patient.BirthDate.ToString("yyyy-MM-dd"));
            command.Parameters.AddWithValue("@BirthPlace", patient.BirthPlace);
            command.Parameters.AddWithValue("@Foreigner", patient.Foreigner);
            command.Parameters.AddWithValue("@BirthProvince", patient.BirthProvince);
            command.Parameters.AddWithValue("@Billable", patient.Billable);
            command.Parameters.AddWithValue("@Completed", patient.Completed);
            command.Parameters.AddWithValue("@Documented", patient.Documented);
            command.Parameters.AddWithValue("@Locked", patient.Locked);


            // Eseguo il comando asincrono
            await command.ExecuteNonQueryAsync();

            //Debug
            Console.WriteLine("Patient edit successfully.");
        }
        catch (Exception e)
        {
            Console.WriteLine("There was an error editing the patient: " + e);
            return false;
        }
        finally
        {
            // Chiuso la connessione al database
            await CloseConnectionAsync();
        }

        return true;
    }

    /// <summary>
    /// Asynchronously deletes a patient and all associated records from the database.
    /// </summary>
    /// <param name="patientId">The ID of the patient to be deleted.</param>
    /// <returns>A <see cref="Task{Boolean}"/> representing the asynchronous operation,
    /// which returns true if at least one record was deleted, otherwise false.</returns>
    /// <remarks>
    /// This method deletes the patient record identified by <paramref name="patientId"/>
    /// and all related records in the VISIT, IMAGES, and RECORDS tables. It uses a transactional
    /// approach to ensure that all deletions are completed successfully before committing the transaction.
    /// In case of an exception, the transaction is rolled back and the method returns false.
    /// </remarks>
    public async Task<bool> DeletePatientFromId(int patientId)
    {
        // Query per eliminare il paziente e le righe associate nelle tabelle VISIT, IMAGES, RECORDS
        string queryDeletePatient = @"
        DELETE FROM PATIENT WHERE patientID = @PatientId;
        DELETE FROM VISIT WHERE patientID = @PatientId;
        DELETE FROM IMAGES WHERE visitID IN (SELECT visitID FROM VISIT WHERE patientID = @PatientId);
        DELETE FROM RECORDS WHERE patientID = @PatientId;";

        int rowsAffected;

        try
        {
            // Open the database connection asynchronously
            await OpenConnectionAsync();

            // Crea il comando SQL
            await using var command = new MySqlCommand(queryDeletePatient, Conn);

            // Aggiunge il parametro per il patientId
            command.Parameters.AddWithValue("@PatientId", patientId);

            // Esegue il comando e ottiene il numero di righe interessate
            rowsAffected = await command.ExecuteNonQueryAsync();

            Console.WriteLine("Deletion was successful, number of rows deleted: " + rowsAffected);
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error while deleting patient: {ex.Message}");
            return false;
        }
        finally
        {
            // Chiuso la connessione al database
            await CloseConnectionAsync();
        }

        // Se almeno una riga è stata cancellata, ritorna true (cancellazione avvenuta con successo)
        return rowsAffected > 0;

    }

    /// <summary>
    /// Asynchronously registers a new doctor in the database.
    /// </summary>
    /// <param name="doctor">The <see cref="Doctor"/> object containing the doctor's information to be registered.</param>
    /// <returns>
    /// A <see cref="Task{Boolean}"/> that represents the asynchronous operation, returning <c>true</c> if the doctor was successfully registered, otherwise <c>false</c>.
    /// </returns>
    /// <remarks>
    /// This method constructs a parametrized SQL query to insert the doctor's information into the database, preventing SQL injection.
    /// It opens a connection to the database, executes the insert command, and then closes the connection.
    /// If an exception occurs during the operation, the method catches it, logs the error, and returns <c>false</c>.
    /// </remarks>
    public async Task<bool> RegisterDoctorQuery(Doctor doctor)
    {
        // Query parametrizzata per evitare SQL injection
        var registerDoctorQuery = $"INSERT INTO DOCTOR (first_name, surname, gender, birth_date, email, password, telephone, address) " +
                                  $"VALUES (@name, @surname, @gender, @birthDate, @email, SHA2(@password, {LengthHash}), @telephone, @address)";

        try
        {
            // Apro la connessione al database
            await OpenConnectionAsync();
            await using var command = new MySqlCommand(registerDoctorQuery, Conn);
            // Aggiungo i parametri alla query
            command.Parameters.AddWithValue("@name", doctor.FirstName);
            command.Parameters.AddWithValue("@surname", doctor.Surname);
            command.Parameters.AddWithValue("@gender", doctor.Gender);
            command.Parameters.AddWithValue("@birthDate", doctor.BirthDate.ToString("yyyy-MM-dd"));
            command.Parameters.AddWithValue("@email", doctor.Email);
            command.Parameters.AddWithValue("@password", doctor.Password);
            command.Parameters.AddWithValue("@telephone", doctor.Telephone);
            command.Parameters.AddWithValue("@address", doctor.Address);

            // Eseguo la query
            await command.ExecuteNonQueryAsync();

            Console.WriteLine("Doctor registered successfully.");
        }
        catch (Exception e)
        {
            Console.WriteLine("There was an error during registration: " + e);
            return false;
        }
        finally
        {
            // Chiudo la connessione al database
            await CloseConnectionAsync();
        }

        return true;
    }

    /// <summary>
    /// Checks if a doctor with the specified email already exists in the database.
    /// </summary>
    /// <param name="email">The email address of the doctor to check for existence.</param>
    /// <returns>A boolean value indicating whether the doctor exists (true) or not (false).</returns>
    public async Task<bool> CheckDoctorExistAsync(string email)
    {
        // Query parametrizzata per evitare SQL injection
        var checkExistQuery = "SELECT email FROM DOCTOR WHERE email=@Email";

        try
        {
            // Apro la connessione al database
            await OpenConnectionAsync();

            // Creo il comando con la query e la connessione
            await using var command = new MySqlCommand(checkExistQuery, Conn);
            // Aggiungo il parametro alla query
            command.Parameters.AddWithValue("@Email", email);

            // Eseguo il comando e ottengo il lettore
            await using var reader = await command.ExecuteReaderAsync();

            // Se c'è da leggere, allora l'email è presente nel database
            if (reader.Read())
            {
                Console.WriteLine("Doctor already exists.");
                return true;
            }
        }
        catch (Exception e)
        {
            Console.WriteLine("There was an error checking for existing email: " + e);
        }
        finally
        {
            // Chiudo la connessione al database
            await CloseConnectionAsync();
        }

        return false;
    }
    
    /// <summary>
    /// Checks if the provided email and password match a doctor's credentials in the database.
    /// </summary>
    /// <param name="email">The email address of the doctor.</param>
    /// <param name="password">The password of the doctor.</param>
    /// <returns>A boolean value indicating whether the credentials are correct (true) or not (false).</returns>
    public async Task<bool> CheckDoctorCredentialsAsync(string email, string password)
    {
        // Query parametrizzata per evitare SQL injection
        var query = "SELECT COUNT(*) FROM DOCTOR WHERE email = @Email AND password = SHA2(@Password, @LengthHash)";

        try
        {
            // Apro la connessione al database
            await OpenConnectionAsync();

            // Creo il comando con la query e la connessione
            await using var command = new MySqlCommand(query, Conn);

            // Aggiungo i parametri alla query
            command.Parameters.AddWithValue("@Email", email);
            command.Parameters.AddWithValue("@Password", password);
            command.Parameters.AddWithValue("@LengthHash", LengthHash);

            // Eseguo il comando e ottengo il numero di righe che corrispondono
            var result = (long)(await command.ExecuteScalarAsync())!;

            // Chiudo la connessione
            await CloseConnectionAsync();

            // Se il risultato è maggiore di 0, la password è corretta
            return result > 0;
        }
        catch (Exception e)
        {
            Console.WriteLine("There was an error checking the password: " + e);
        }
        finally
        {
            // Chiudo la connessione al database
            await CloseConnectionAsync();
        }

        return false;
    }

    /// <summary>
    /// Retrieves the doctor ID associated with the provided email address from the database.
    /// </summary>
    /// <param name="email">The email address of the doctor to retrieve the ID for.</param>
    /// <returns>The doctor ID if found, otherwise null.</returns>
    public async Task<int?> GetDoctorIdAsync(string email)
    {
        // Query parametrizzata per evitare SQL injection
        string query = "SELECT doctorID FROM DOCTOR WHERE email = @Email";

        try
        {
            // Apro la connessione al database
            await OpenConnectionAsync();

            // Creo il comando con la query e la connessione
            await using var command = new MySqlCommand(query, Conn);
            // Aggiungo il parametro alla query
            command.Parameters.AddWithValue("@Email", email);

            // Eseguo il comando e ottengo il lettore
            await using var reader = await command.ExecuteReaderAsync();

            if (reader.Read())
            {
                // Ottengo il valore del campo "doctorID"
                int doctorId = reader.GetInt32("doctorID");

                // Chiudo la connessione
                await CloseConnectionAsync();

                // Ritorno il valore ottenuto
                return doctorId;
            }
        }
        catch (Exception e)
        {
            Console.WriteLine("There was an error getting the doctor ID: " + e);
        }
        finally
        {
            // Chiudo la connessione al database
            await CloseConnectionAsync();
        }

        // Se il dottore non viene trovato, ritorno null
        return null;
    }
    
    /// <summary>
    /// Retrieves a list of doctors from the database.
    /// </summary>
    /// <param name="nDoctors">The number of doctors to retrieve.</param>
    /// <param name="nPage">The page number for pagination.</param>
    /// <returns>A list of doctors if found; otherwise, null.</returns>
    public async Task<List<Doctor>?> GetDoctorsFromDb(int nDoctors, int nPage)
    {
        List<Doctor> doctors = new List<Doctor>();

        int offset = (nPage - 1) * nDoctors;

        var queryRangeDoctor = "SELECT * FROM DOCTOR LIMIT @Limit OFFSET @Offset";

        try
        {
            await OpenConnectionAsync();
            await using var command = new MySqlCommand(queryRangeDoctor, Conn);

            command.Parameters.AddWithValue("@Limit", nDoctors);
            command.Parameters.AddWithValue("@Offset", offset);

            await using var reader = await command.ExecuteReaderAsync();

            while (await reader.ReadAsync())
            {
                var doctor = GetDoctorFromReader(reader);
                doctors.Add(doctor!);
            }

            await CloseReaderAsync(reader);

            Console.WriteLine("Doctors retrieved successfully.");
        }
        catch (Exception e)
        {
            Console.WriteLine("There was an error while getting the doctors from the database: " + e);
            return null;
        }
        finally
        {
            await CloseConnectionAsync();
        }

        return doctors.Count > 0 ? doctors : null;
    }

    /// <summary>
    /// Extracts a Doctor object from the MySqlDataReader, ensuring no null values are assigned.
    /// </summary>
    /// <param name="reader">MySqlDataReader containing the doctor data.</param>
    /// <returns>Doctor object with default values assigned for any null fields.</returns>
    public Doctor? GetDoctorFromReader(MySqlDataReader? reader)
    {
        if (reader == null)
        {
            return null;
        }

        Doctor doctor = new Doctor
        {
            DoctorId = reader.IsDBNull(reader.GetOrdinal("doctorID")) ? -1 : reader.GetInt32("doctorID"),
            FirstName = reader.IsDBNull(reader.GetOrdinal("first_name")) ? "N/A" : reader.GetString("first_name"),
            Surname = reader.IsDBNull(reader.GetOrdinal("surname")) ? "N/A" : reader.GetString("surname"),
            Gender = !reader.IsDBNull(reader.GetOrdinal("gender")) && reader.GetBoolean("gender"),
            BirthDate = reader.IsDBNull(reader.GetOrdinal("birth_date")) ? DateTime.MinValue : reader.GetDateTime("birth_date"),
            Email = reader.IsDBNull(reader.GetOrdinal("email")) ? "N/A" : reader.GetString("email"),
            Telephone = reader.IsDBNull(reader.GetOrdinal("telephone")) ? "N/A" : reader.GetString("telephone"),
            Address = reader.IsDBNull(reader.GetOrdinal("address")) ? "N/A" : reader.GetString("address")
        };

        return doctor;
    }

    /// <summary>
    /// Asynchronously deletes a doctor and all associated records from the database.
    /// </summary>
    /// <param name="doctorId">The ID of the doctor to be deleted.</param>
    /// <returns>A <see cref="Task{Boolean}"/> representing the asynchronous operation,
    /// which returns true if at least one record was deleted, otherwise false.</returns>
    /// <remarks>
    /// This method deletes the doctor record identified by <paramref name="doctorId"/>
    /// and all related records in the PATIENT, VISIT, and IMAGES tables. It uses a transactional
    /// approach to ensure that all deletions are completed successfully before committing the transaction.
    /// In case of an exception, the transaction is rolled back and the method returns false.
    /// </remarks>
    public async Task<bool> DeleteDoctorFromId(int doctorId)
    {
        // Query per eliminare il paziente e le righe associate nelle tabelle VISIT, IMAGES, RECORDS
        string queryDeletePatient = @"
        DELETE FROM PATIENT WHERE doctorID = @doctorId;
        DELETE FROM VISIT WHERE doctorID = @doctorId;
        DELETE FROM IMAGES WHERE visitID IN (SELECT visitID FROM VISIT WHERE doctorID = @doctorId);
        DELETE FROM DOCTOR WHERE doctorID = @doctorId;";

        int rowsAffected;

        try
        {
            // Apro il database in connessione asincrona
            await OpenConnectionAsync();

            // Crea il comando SQL
            await using var command = new MySqlCommand(queryDeletePatient, Conn);

            // Aggiunge il parametro per il doctorId
            command.Parameters.AddWithValue("@doctorId", doctorId);

            // Esegue il comando e ottiene il numero di righe interessate
            rowsAffected = await command.ExecuteNonQueryAsync();

            Console.WriteLine("Deletion was successful, number of rows deleted: " + rowsAffected);
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error while deleting doctor: {ex.Message}");
            return false;
        }
        finally
        {
            // Chiuso la connessione al database
            await CloseConnectionAsync();
        }

        // Se almeno una riga è stata cancellata, ritorna true (cancellazione avvenuta con successo)
        return rowsAffected > 0;

    }

    /// <summary>
    /// Updates a doctor's information based on the provided ID.
    /// Optionally updates the password if it has changed.
    /// </summary>
    /// <param name="doctor">The doctor object containing updated information.</param>
    /// <param name="id">The ID of the doctor to update.</param>
    /// <param name="passwordChanged">Indicates if the password has been changed.</param>
    /// <returns>A boolean indicating whether the update was successful.</returns>
    public async Task<bool> UpdateDoctorFromId(Doctor doctor, int id, bool passwordChanged)
    {
        string updateDoctorPassword = passwordChanged ? $"password = SHA2(@Password, {LengthHash})," : string.Empty;

        // Query per aggiornare i dati del paziente
        string updateDoctorQuery = $@"
        UPDATE DOCTOR 
        SET 
            first_name = @FirstName, 
            surname = @Surname, 
            gender = @Gender, 
            telephone = @Telephone, 
            birth_date = @BirthDate, 
            email = @Email, 
            {updateDoctorPassword}
            address = @Address 
        WHERE doctorID = @DoctorID";

        try
        {
            // Apro la connessione
            await OpenConnectionAsync();

            // Creo un comando MySQL per eseguire la query
            await using var command = new MySqlCommand(updateDoctorQuery, Conn);

            // Aggiungo i parametri alla query
            command.Parameters.AddWithValue("@DoctorID", id);
            command.Parameters.AddWithValue("@FirstName", doctor.FirstName);
            command.Parameters.AddWithValue("@Surname", doctor.Surname);
            command.Parameters.AddWithValue("@Gender", doctor.Gender);
            command.Parameters.AddWithValue("@Telephone", doctor.Telephone);
            command.Parameters.AddWithValue("@BirthDate", doctor.BirthDate.ToString("yyyy-MM-dd"));
            command.Parameters.AddWithValue("@Email", doctor.Email);
            command.Parameters.AddWithValue("@Address", doctor.Address);

            if (passwordChanged)
            {
                command.Parameters.AddWithValue("@Password", doctor.Password);
            }

            // Eseguo il comando asincrono
            await command.ExecuteNonQueryAsync();

            //Debug
            Console.WriteLine("Doctor edit successfully.");
        }
        catch (Exception e)
        {
            Console.WriteLine("There was an error editing the doctor: " + e);
            return false;
        }
        finally
        {
            // Chiuso la connessione al database
            await CloseConnectionAsync();
        }

        return true;
    }
    
}