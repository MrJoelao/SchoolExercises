using System.IO;

public class Paziente
{
    private string nome { get; set; }
    private string cognome { get; set; }
    private string luogo_nascita { get; set; }
    private string provincia { get; set; }
    private string codice_fiscale { get; set; }
    private string codice_asl { get; set; }
    private string categoria { get; set; }
    private string medico { get; set; }
    private string professione { get; set; }
    private string[] indirizzi { get; set; }
    private DateTime data_nascita { get; set; }
    private bool estero { get; set; }
    private bool controllo_validità { get; set; }
    private bool sesso { get; set; } //true=uomo

    public Paziente(string nome, string cognome, string luogoNascita, string provincia, string codiceFiscale, string codiceAsl, string categoria, string medico, string professione, string[] indirizzi, DateTime dataNascita, bool estero, bool controlloValidità, bool sesso)
    {
        this.nome = nome;
        this.cognome = cognome;
        luogo_nascita = luogoNascita;
        this.provincia = provincia;
        codice_fiscale = codiceFiscale;
        codice_asl = codiceAsl;
        this.categoria = categoria;
        this.medico = medico;
        this.professione = professione;
        this.indirizzi = indirizzi;
        data_nascita = dataNascita;
        this.estero = estero;
        controllo_validità = controlloValidità;
        this.sesso = sesso;
    }

    public Paziente()
    {
    }

    public new string ToString()
    {
        return nome + cognome + data_nascita;
    }
}