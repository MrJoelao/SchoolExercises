namespace Delta_Dent;
using MySqlConnector;
using Microsoft.Extensions.Configuration;

public class DbManager
{
    public MySqlConnection Conn { get; private set; }
    private readonly IConfiguration _configuration = new ConfigurationBuilder().AddJsonFile("appsettings.json").Build();
    private int _lengthHash = 256;
    
    public DbManager(string connStr = null)
    {
        Console.WriteLine("Attempting to open connection...");
        OpenConnection(connStr);
    }
    
    public void OpenConnection(string connStr = null)
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
    
    public async Task OpenConnectionAsync(string connStr = null)
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
            Console.WriteLine("Failed to open async connection:" + e.Message);
        }
        
    }
    
    public void CloseConnection()
    {
        try
        {
            Conn.Close();
            Console.WriteLine("Connection closed successfully.");
        }
        catch (Exception e)
        {
            Console.WriteLine($"Failed to close connection:" + e.Message);
        }
    }
    
    public async Task CloseConnectionAsync()
    {
        try
        {
            await Conn.CloseAsync();
            Console.WriteLine("Connection closed successfully.");
        }
        catch (Exception e)
        {
            Console.WriteLine($"Failed to close connection:" + e.Message);
        }
    }
    
    //Metodo per eseguire una query
    public void MakeQuery(string query)
    {
        Console.WriteLine($"Executing query: {query}");
        MySqlCommand cmd = new MySqlCommand(query, Conn);
        try
        {
            cmd.ExecuteNonQuery();
            Console.WriteLine("Query executed successfully.");
        }
        catch (Exception e)
        {
            Console.WriteLine($"Failed to execute query:" + e.Message);
        }
    }
    
    public async Task MakeQueryAsync(string query)
    {
        Console.WriteLine($"Executing query: {query}");
        MySqlCommand cmd = new MySqlCommand(query, Conn);
        try
        {
            await cmd.ExecuteNonQueryAsync();
            Console.WriteLine("Query executed successfully.");
        }
        catch (Exception e)
        {
            Console.WriteLine($"Failed to execute query:" + e.Message);
        }
    }
    
    
    
    // Metodo per eseguire una query di tipo SELECT
    public MySqlDataReader ExecuteReader(string query)
    {
        Console.WriteLine($"Executing query: {query}");
        MySqlCommand cmd = new MySqlCommand(query, Conn);
        MySqlDataReader reader = null;
        try
        {
            // Apri la connessione se non è già aperta
            if (Conn.State != System.Data.ConnectionState.Open)
            {
                Console.WriteLine("Connection not open, opening connection...");
                Conn.OpenAsync();
            }
            
            reader = cmd.ExecuteReader();
        }
        catch (Exception e)
        {
            Console.WriteLine("Failed to execute query:" + e);
        }
        return reader;
    }
    
    // Metodo per eseguire una query di tipo SELECT
    public async Task<MySqlDataReader> ExecuteReaderAsync(string query)
    {
        Console.WriteLine($"Executing query: {query}");
        MySqlCommand cmd = new MySqlCommand(query, Conn);
        MySqlDataReader reader = null;
        try
        {
            // Apri la connessione se non è già aperta
            if (Conn.State != System.Data.ConnectionState.Open)
            {
                Console.WriteLine("Connection not open, opening connection...");
                await Conn.OpenAsync();
            }
            
             reader = await cmd.ExecuteReaderAsync();
        }
        catch (Exception e)
        {
            Console.WriteLine("Failed to execute query:" + e);
        }
        return reader;
    }
    
    // Metodo per chiudere il reader
    public void CloseReader(MySqlDataReader reader)
    {
        try
        {
            reader.Close();
            Console.WriteLine("Reader closed successfully.");
        }
        catch (Exception e)
        {
            Console.WriteLine("Failed to close reader:" + e);
        }
    }
    
    public async Task CloseReaderAsync(MySqlDataReader reader)
    {
        try
        {
            await reader.CloseAsync();
            Console.WriteLine("Reader closed successfully.");
        }
        catch (Exception e)
        {
            Console.WriteLine("Failed to close reader:" + e);
        }
    }

    public async Task<bool> RegisterDoctorQuery(string name, string surname, string email, string password)
    {
        // Query parametrizzata per evitare SQL injection
        var registerDoctorQuery = $"INSERT INTO DOCTOR (first_name, surname, email, password) " +
                                  $"VALUES (@name, @surname, @email, SHA2(@password, {_lengthHash}))";

        try
        {
            // Apro la connessione al database
            await OpenConnectionAsync();
            using (var command = new MySqlCommand(registerDoctorQuery, Conn))
            {
                // Aggiungo i parametri alla query
                command.Parameters.AddWithValue("@name", name);
                command.Parameters.AddWithValue("@surname", surname);
                command.Parameters.AddWithValue("@email", email);
                command.Parameters.AddWithValue("@password", password);

                // Eseguo la query
                await command.ExecuteNonQueryAsync();

                Console.WriteLine("Doctor registered successfully.");
            }
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

    // Funzione per verificare se un dottore è già presente nel DB in base all'email
    public async Task<bool> CheckDoctorExistAsync(string email)
    {
        // Query parametrizzata per evitare SQL injection
        var checkExistQuery = "SELECT email FROM DOCTOR WHERE email=@Email";

        try
        {
            // Apro la connessione al database
            await OpenConnectionAsync();

            // Creo il comando con la query e la connessione
            using (var command = new MySqlCommand(checkExistQuery, Conn))
            {
                // Aggiungo il parametro alla query
                command.Parameters.AddWithValue("@Email", email);

                // Eseguo il comando e ottengo il lettore
                using (var reader = await command.ExecuteReaderAsync())
                {
                    // Se c'è da leggere, allora l'email è presente nel database
                    if (reader.Read())
                    {
                        Console.WriteLine("Doctor already exists.");
                        return true;
                    }
                }
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
    
    //Funzione che controlla se la password di un medico è uguale a quella passatagli
    public async Task<bool> CheckDoctorCredentialsAsync(string email, string password)
    {
        // Query parametrizzata per evitare SQL injection
        var query = "SELECT COUNT(*) FROM DOCTOR WHERE email = @Email AND password = SHA2(@Password, @LengthHash)";

        try
        {
            // Apro la connessione al database
            await OpenConnectionAsync();

            // Creo il comando con la query e la connessione
            using (var command = new MySqlCommand(query, Conn))
            {
                // Aggiungo i parametri alla query
                command.Parameters.AddWithValue("@Email", email);
                command.Parameters.AddWithValue("@Password", password);
                command.Parameters.AddWithValue("@LengthHash", _lengthHash);

                // Eseguo il comando e ottengo il numero di righe che corrispondono
                var result = (long)await command.ExecuteScalarAsync();

                // Chiudo la connessione
                await CloseConnectionAsync();

                // Se il risultato è maggiore di 0, la password è corretta
                return result > 0;
            }
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

    public async Task<int?> GetDoctorIdAsync(string email)
    {
        // Query parametrizzata per evitare SQL injection
        string query = "SELECT doctorID FROM DOCTOR WHERE email = @Email";

        try
        {
            // Apro la connessione al database
            await OpenConnectionAsync();

            // Creo il comando con la query e la connessione
            using (var command = new MySqlCommand(query, Conn))
            {
                // Aggiungo il parametro alla query
                command.Parameters.AddWithValue("@Email", email);

                // Eseguo il comando e ottengo il lettore
                using (var reader = await command.ExecuteReaderAsync())
                {
                    if (reader.Read())
                    {
                        // Ottengo il valore del campo "doctorID"
                        int doctorID = reader.GetInt32("doctorID");

                        // Chiudo la connessione
                        await CloseConnectionAsync();

                        // Ritorno il valore ottenuto
                        return doctorID;
                    }
                }
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

}