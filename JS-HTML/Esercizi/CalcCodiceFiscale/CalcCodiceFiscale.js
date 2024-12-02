var nome;
var cognome;
var dataNascita;
var sesso;
var luogoNascita;

document.addEventListener('DOMContentLoaded', function() {
    const form = document.getElementById('codiceFiscaleForm');
    const risultatoDiv = document.getElementById('risultato');
    const codiceFiscaleOutput = document.getElementById('codiceFiscale');

    form.addEventListener('submit', function(e) {
        e.preventDefault();
        
        // Prendi i valori dal form
        nome = document.getElementById('nome').value.trim();
        cognome = document.getElementById('cognome').value.trim();
        dataNascita = document.getElementById('dataNascita').value;
        sesso = document.getElementById('sesso').value;
        luogoNascita = document.getElementById('luogoNascita').value.trim();

        // Calcola il codice fiscale
        const risultato = calcolaCodiceFiscale();

        if (risultato.valid) {
            // Mostra il risultato
            risultatoDiv.style.display = 'block';
            codiceFiscaleOutput.textContent = risultato.codiceFiscale;
        } else {
            // Mostra l'errore
            alert(risultato.message);
            risultatoDiv.style.display = 'none';
        }
    });
});

function calcolaCodiceFiscale() {
    checkInput()

    // Controllo validità input
    let checkResult = checkInput();
    if (!checkResult.valid) {
        return checkResult;
    }

    // Calcolo codice cognome (prime 3 consonanti o vocali se non bastano)
    let consonantiCognome = cognome.toUpperCase().replace(/[^BCDFGHJKLMNPQRSTVWXYZ]/g, '');
    let vocaliCognome = cognome.toUpperCase().replace(/[^AEIOU]/g, '');
    let codiceCognome = (consonantiCognome + vocaliCognome + 'XXX').substring(0, 3);

    // Calcolo codice nome (prime 3 consonanti o vocali se non bastano)
    let consonantiNome = nome.toUpperCase().replace(/[^BCDFGHJKLMNPQRSTVWXYZ]/g, '');
    let vocaliNome = nome.toUpperCase().replace(/[^AEIOU]/g, '');
    let codiceNome = '';
    if (consonantiNome.length > 3) {
        codiceNome = consonantiNome[0] + consonantiNome[2] + consonantiNome[3];
    } else {
        codiceNome = (consonantiNome + vocaliNome + 'XXX').substring(0, 3);
    }

    // Calcolo codice anno (ultime 2 cifre)
    let data = new Date(dataNascita);
    let anno = data.getFullYear().toString().slice(-2);

    // Calcolo codice mese
    const codiciMesi = 'ABCDEHLMPRST';
    let mese = codiciMesi[data.getMonth()];

    // Calcolo codice giorno
    let giorno = data.getDate();
    if (sesso === 'F') {
        giorno += 40;
    }
    let codiceGiorno = giorno.toString().padStart(2, '0');

    // Calcolo codice comune (simulato - in realtà dovrebbe essere preso da una tabella)
    let codiceComune = 'H501'; // Roma come esempio

    // Calcolo carattere di controllo
    let codiceParziale = codiceCognome + codiceNome + anno + mese + codiceGiorno + codiceComune;
    let carattereControllo = calcolaCarattereControllo(codiceParziale);

    return {
        valid: true,
        codiceFiscale: codiceParziale + carattereControllo
    };

    function calcolaCarattereControllo(codice) {
        const caratteriDispari = {
            '0': 1, '1': 0, '2': 5, '3': 7, '4': 9, '5': 13, '6': 15, '7': 17, '8': 19,
            '9': 21, 'A': 1, 'B': 0, 'C': 5, 'D': 7, 'E': 9, 'F': 13, 'G': 15, 'H': 17,
            'I': 19, 'J': 21, 'K': 2, 'L': 4, 'M': 18, 'N': 20, 'O': 11, 'P': 3, 'Q': 6,
            'R': 8, 'S': 12, 'T': 14, 'U': 16, 'V': 10, 'W': 22, 'X': 25, 'Y': 24, 'Z': 23
        };
        const caratteriPari = {
            '0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8,
            '9': 9, 'A': 0, 'B': 1, 'C': 2, 'D': 3, 'E': 4, 'F': 5, 'G': 6, 'H': 7,
            'I': 8, 'J': 9, 'K': 10, 'L': 11, 'M': 12, 'N': 13, 'O': 14, 'P': 15, 'Q': 16,
            'R': 17, 'S': 18, 'T': 19, 'U': 20, 'V': 21, 'W': 22, 'X': 23, 'Y': 24, 'Z': 25
        };
        const caratteriResto = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';

        let somma = 0;
        for (let i = 0; i < codice.length; i++) {
            if ((i + 1) % 2 === 0) {
                somma += caratteriPari[codice[i]];
            } else {
                somma += caratteriDispari[codice[i]];
            }
        }
        return caratteriResto[somma % 26];
    }
}

function checkInput() {
    // Controllo nome
    if (!nome || nome.trim() === '') {
        return { valid: false, message: 'Il nome è obbligatorio' };
    }
    if (!/^[a-zA-Z\s]*$/.test(nome)) {
        return { valid: false, message: 'Il nome può contenere solo lettere e spazi' };
    }

    // Controllo cognome 
    if (!cognome || cognome.trim() === '') {
        return { valid: false, message: 'Il cognome è obbligatorio' };
    }
    if (!/^[a-zA-Z\s]*$/.test(cognome)) {
        return { valid: false, message: 'Il cognome può contenere solo lettere e spazi' };
    }

    // Controllo data di nascita
    if (!dataNascita) {
        return { valid: false, message: 'La data di nascita è obbligatoria' };
    }
    let data = new Date(dataNascita);
    if (isNaN(data.getTime())) {
        return { valid: false, message: 'Data di nascita non valida' };
    }
    if (data > new Date()) {
        return { valid: false, message: 'La data di nascita non può essere nel futuro' };
    }

    // Controllo sesso
    if (!sesso) {
        return { valid: false, message: 'Il sesso è obbligatorio' };
    }
    if (sesso !== 'M' && sesso !== 'F') {
        return { valid: false, message: 'Il sesso deve essere M o F' };
    }

    // Controllo luogo di nascita
    if (!luogoNascita || luogoNascita.trim() === '') {
        return { valid: false, message: 'Il luogo di nascita è obbligatorio' };
    }
    if (!/^[a-zA-Z\s]*$/.test(luogoNascita)) {
        return { valid: false, message: 'Il luogo di nascita può contenere solo lettere e spazi' };
    }

    return { valid: true };
}