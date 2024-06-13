﻿using System.IO;

public class Paziente
{
    private string nome, cognome, luogo_nascita, provincia, codice_fiscale, codice_asl, categoria, medico, professione;
    private string[] indirizzi;
    private DateTime data_nascita;
    private bool estero, controllo_validità, sesso; //true=uomo

    public Paziente(string inome, string icognome, string iluogoNascita, string iprovincia, string icodiceFiscale,
        string icodiceAsl, string icategoria, string imedico, string iprofessione, string[] iindirizzi, DateTime idataNascita, bool iestero,
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
        data_nascita = idataNascita;
        estero = iestero;
        controllo_validità = icontrolloValidità;
        sesso = isesso;
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
    
    public DateTime getDataNascita()
    {
        return data_nascita;
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
        Paziente nuovo;
        String testo;
        try
        {
            testo = File.ReadAllText(nome_file);
            //Console.WriteLine(testo);
        }
        catch (Exception e)
        {
            return null;
        }

        String[] parti = testo.Split('\n');
        /*foreach (String s in parti)
        {
            Console.WriteLine(s+'\n');
        }*/

        return null;
    }

    public new string ToString()
    {
        return nome + cognome+data_nascita;
    }
    
}