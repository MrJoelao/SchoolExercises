/**
 * CRONOMETRO - Implementazione JavaScript
 * 
 * Questo script implementa un cronometro con funzionalità di start, stop e reset.
 * Include anche gestione del tema chiaro/scuro e gestione degli errori.
 */

// ========== VARIABILI GLOBALI ==========
// Contatori per tenere traccia del tempo
let minutes = 0;        // Contatore dei minuti
let seconds = 0;        // Contatore dei secondi
let milliseconds = 0;   // Contatore dei millisecondi
let isRunning = false;  // Flag per lo stato del cronometro
let intervalId = null;  // ID dell'intervallo per l'aggiornamento del timer

// ========== RIFERIMENTI DOM ==========
// Elementi del display per mostrare il tempo
const minutesDisplay = document.getElementById('minutes');           // Display minuti
const secondsDisplay = document.getElementById('seconds');           // Display secondi
const millisecondsDisplay = document.getElementById('milliseconds'); // Display millisecondi
const timeDisplay = document.querySelector('.time-display');        // Container del display

// ========== FUNZIONI DI UTILITY ==========
/**
 * Formatta un numero aggiungendo uno zero iniziale se necessario
 * @param {number} number - Numero da formattare
 * @returns {string} Numero formattato con zero iniziale se < 10
 */
const formatNumber = (number) => number.toString().padStart(2, '0');

/**
 * Aggiorna il display del cronometro con i valori correnti
 */
const updateDisplay = () => {
    minutesDisplay.textContent = formatNumber(minutes);
    secondsDisplay.textContent = formatNumber(seconds);
    millisecondsDisplay.textContent = formatNumber(Math.floor(milliseconds / 10));
};

// ========== LOGICA DEL CRONOMETRO ==========
/**
 * Incrementa il tempo del cronometro
 * Gestisce il rollover di millisecondi -> secondi -> minuti
 */
const incrementTime = () => {
    milliseconds += 10;
    
    if (milliseconds === 1000) {  // Rollover millisecondi -> secondi
        milliseconds = 0;
        seconds++;
        
        if (seconds === 60) {     // Rollover secondi -> minuti
            seconds = 0;
            minutes++;
        }
    }
    
    updateDisplay();
};

// ========== CONTROLLI DEL CRONOMETRO ==========
/**
 * Avvia il cronometro
 * Imposta l'intervallo di aggiornamento e aggiunge la classe per l'animazione
 */
const startTimer = () => {
    if (!isRunning) {
        isRunning = true;
        timeDisplay.classList.add('running');
        intervalId = setInterval(incrementTime, 10); // Aggiorna ogni 10ms
    }
};

/**
 * Ferma il cronometro
 * Rimuove l'intervallo di aggiornamento e l'animazione
 */
const stopTimer = () => {
    if (isRunning) {
        isRunning = false;
        timeDisplay.classList.remove('running');
        clearInterval(intervalId);
    }
};

/**
 * Resetta il cronometro
 * Azzera tutti i contatori e aggiorna il display
 */
const resetTimer = () => {
    stopTimer();
    minutes = seconds = milliseconds = 0;
    updateDisplay();
};

// ========== GESTIONE TEMA ==========
/**
 * Gestisce il tema chiaro/scuro
 * Rileva la preferenza del sistema e applica il tema appropriato
 */
const handleTheme = () => {
    const isDarkMode = window.matchMedia('(prefers-color-scheme: dark)').matches;
    document.body.classList.toggle('dark-theme', isDarkMode);
};

// ========== GESTIONE VISIBILITÀ ==========
/**
 * Gestisce la visibilità della pagina
 * Ferma il cronometro quando la pagina non è visibile
 */
const handleVisibility = () => {
    if (document.hidden && isRunning) {
        stopTimer();
    }
};

// ========== INIZIALIZZAZIONE ==========
/**
 * Inizializza l'applicazione al caricamento della pagina
 * Configura i controlli e imposta i gestori degli eventi
 */
window.onload = () => {
    // Inizializza il display
    updateDisplay();
    
    // Configura i controlli
    const startBtn = document.getElementById('startBtn');
    const stopBtn = document.getElementById('stopBtn');
    const resetBtn = document.getElementById('resetBtn');
    
    // Assegna i gestori degli eventi ai pulsanti
    if (startBtn) startBtn.onclick = startTimer;
    if (stopBtn) stopBtn.onclick = stopTimer;
    if (resetBtn) resetBtn.onclick = resetTimer;
    
    // Configura gestori per tema e visibilità
    document.onvisibilitychange = handleVisibility;
    window.matchMedia('(prefers-color-scheme: dark)').onchange = handleTheme;
    
    // Imposta il tema iniziale
    handleTheme();
};

// ========== GESTIONE ERRORI ==========
/**
 * Gestore globale degli errori
 * Logga gli errori e ferma il cronometro in caso di problemi
 * @param {string} msg - Messaggio di errore
 * @param {string} url - URL dove si è verificato l'errore
 * @param {number} line - Numero di linea dell'errore
 */
window.onerror = (msg, url, line) => {
    console.error(`Errore: ${msg}\nURL: ${url}\nLinea: ${line}`);
    stopTimer(); // Ferma il timer per sicurezza
    return false;
};
