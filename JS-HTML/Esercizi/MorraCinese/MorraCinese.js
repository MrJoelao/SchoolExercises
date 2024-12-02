// Definiamo le costanti per le mosse
const SASSO = 1;
const CARTA = 2;
const FORBICE = 3;

// Variabili per tenere il punteggio
let vittorie = 0;
let sconfitte = 0;
let pareggi = 0;

// Funzione che viene eseguita quando la pagina si carica
window.onload = function() {
    aggiornaPunteggio(); 
};

// Funzione principale del gioco
function gioca(sceltaGiocatore) {
    // Genera una scelta casuale per il computer (1, 2 o 3)
    let sceltaComputer = Math.floor(Math.random() * 3) + 1;
    
    // Stampiamo le scelte nella console per debug
    console.log('Tu hai scelto: ' + getNomeMossa(sceltaGiocatore));
    console.log('Il computer ha scelto: ' + getNomeMossa(sceltaComputer));

    // Controlliamo chi ha vinto
    controllaVincitore(sceltaGiocatore, sceltaComputer);
    
    // Aggiorniamo il punteggio mostrato
    aggiornaPunteggio();
}

// Funzione per controllare chi ha vinto
function controllaVincitore(sceltaGiocatore, sceltaComputer) {
    if (sceltaGiocatore === sceltaComputer) {
        // Pareggio
        pareggi++;
        mostraRisultato('pareggio', sceltaComputer);
    } else if (
        (sceltaGiocatore === SASSO && sceltaComputer === FORBICE) ||
        (sceltaGiocatore === CARTA && sceltaComputer === SASSO) ||
        (sceltaGiocatore === FORBICE && sceltaComputer === CARTA)
    ) {
        // Vittoria
        vittorie++;
        mostraRisultato('vittoria', sceltaComputer);
    } else {
        // Sconfitta
        sconfitte++;
        mostraRisultato('sconfitta', sceltaComputer);
    }
}

// Funzione per mostrare il popup del risultato
function mostraRisultato(risultato, sceltaComputer) {
    // Prendiamo il popup giusto
    let popup = document.getElementById(risultato);
    
    // Aggiorniamo il testo della scelta del computer
    let testoScelta = "Il computer ha scelto: " + getNomeMossa(sceltaComputer);
    document.getElementById('scelta-computer-' + risultato).textContent = testoScelta;
    
    // Mostriamo il popup
    popup.style.display = 'block';
    
    // Nascondiamo il popup dopo 2 secondi
    setTimeout(() => {
        popup.style.display = 'none';
    }, 2000);
}

// Funzione per convertire il numero della mossa in testo
function getNomeMossa(numero) {
    switch(numero) {
        case SASSO: return "Sasso";
        case CARTA: return "Carta";
        case FORBICE: return "Forbice";
        default: return "Mossa sconosciuta";
    }
}

// Funzione per aggiornare il punteggio mostrato
function aggiornaPunteggio() {
    document.getElementById("vittorie").innerHTML = '<i class="material-icons">workspace_premium</i> Vittorie: ' + vittorie;
    document.getElementById("sconfitte").innerHTML = '<i class="material-icons">close</i> Sconfitte: ' + sconfitte;
    document.getElementById("pareggi").innerHTML = '<i class="material-icons">drag_handle</i> Pareggi: ' + pareggi;
}

// Funzione per azzerare il punteggio
function azzeraPunteggio() {
    vittorie = 0;
    sconfitte = 0;
    pareggi = 0;
    aggiornaPunteggio();
}
