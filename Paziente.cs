using System.IO;

public class Paziente
{
    private string nome, cognome, luogo_nascita, provincia, codice_fiscale, codice_asl, categoria, medico, professione;
    private string[] indirizzi;
    private bool estero, controllo_validità, sesso; //true=uomo

    public Paziente(string inome, string icognome, string iluogoNascita, string iprovincia, string icodiceFiscale,
        string icodiceAsl, string icategoria, string imedico, string iprofessione, string[] iindirizzi, bool iestero,
        bool icontrolloValidità, bool isesso)
    {
        nome = inome;
        cognome = icognome;
        luogo_nascita = iluogoNascita;
        provincia = iprovincia;
        codice_fiscale = icodiceFiscale;
        codice_asl = icodiceAsl;
        categoria = icategoria;
        medico = imedico;
        professione = iprofessione;
        indirizzi = iindirizzi;
        estero = iestero;
        controllo_validità = icontrolloValidità;
        sesso = isesso;
    }
    
    public Paziente()
    {
        
    }

    public string getNome()
    {
        return nome;
    }
    
    public string getCognome()
    {
        return cognome;
    }
    
    public string getLuogoNascita()
    {
        return luogo_nascita;
    }
    
    public string getProvincia()
    {
        return provincia;
    }
    
    public string getCodiceFiscale()
    {
        return codice_fiscale;
    }
    
    public string getCodiceASL()
    {
        return codice_asl;
    }
    
    public string getCategoria()
    {
        return categoria;
    }
    
    public string getMedico()
    {
        return medico;
    }
    
    public string getProfessione()
    {
        return professione;
    }
    
    public string[] getIndirizzi()
    {
        return (string[]) indirizzi.Clone();
    }
    
    public bool getEstero()
    {
        return estero;
    }
    
    public bool getControlloValidita()
    {
        return controllo_validità;
    }
    
    public bool getSesso()
    {
        return sesso;
    }

    /// <summary>
    /// Carica da un file contenente una raccolta di dati di un paziente un nuovo paziente
    /// ogni riga del file contiene un attributo del paziente
    /// </summary>
    /// <param name="nome_file">Il file da cui caricare</param>
    /// <returns>Un paziente nuovo</returns>
    public static Paziente caricaPaziente(string nome_file)
    {
        //Console.WriteLine("funzione");
        string testo = File.ReadAllText(nome_file);
        Console.WriteLine(testo);

        return null;
    }
    
}