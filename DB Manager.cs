namespace Delta_Dent;
using MySql.Data.MySqlClient;

public class DbManager
{
    public MySqlConnection Conn;
    
    public DbManager(string server = "The-J-Computer", string user = "user", string password = "admin", string database = "deltadentdb", string port = "3306")
    {
        Console.WriteLine("Attempting to open connection...");
        OpenConnection(server, user, password, database, port);
    }
    
    public void OpenConnection(string server, string user, string password, string database, string port)
    {
        string connStr = $"server={server};user={user};database={database};port={port};password={password}";
        Conn = new MySqlConnection(connStr);
        Conn.Open(); 
        Console.WriteLine("Connection opened successfully.");
    }
    
    public void CloseConnection()
    {
        Conn.Close();
        Console.WriteLine("Connection closed successfully.");
    }
    
    //Metodo per eseguire una query
    public MySqlCommand MakeQuery(string query)
    {
        Console.WriteLine($"Executing query: {query}");
        MySqlCommand cmd = new MySqlCommand(query, Conn);
        cmd.ExecuteNonQuery();
        Console.WriteLine("Query executed successfully.");

        return cmd;
    }
    
    // Metodo per eseguire una query di tipo SELECT
    public MySqlDataReader ExecuteReader(string query)
    {
        Console.WriteLine($"Executing query: {query}");
        MySqlCommand cmd = new MySqlCommand(query, Conn);
        MySqlDataReader reader = cmd.ExecuteReader();
        return reader;
    }
    
    // Metodo per chiudere il reader
    public void CloseReader(MySqlDataReader reader)
    {
        reader.Close();
        Console.WriteLine("Reader closed successfully.");
    }
}