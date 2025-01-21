// Aspettiamo che il DOM sia completamente caricato
document.addEventListener('DOMContentLoaded', function() {
    // Elementi del DOM
    const timerDisplay = document.getElementById('timer');

    // Variabili per il cronometro
    let startTime = 0;      // Tempo di inizio in millisecondi
    let elapsedTime = 0;    // Tempo trascorso
    let intervalId = null;  // ID del setInterval
    let isRunning = false;  // Stato del cronometro

    // Funzione per formattare il tempo
    function formatTime(milliseconds) {
        const totalSeconds = Math.floor(milliseconds / 1000);
        const hours = String(Math.floor(totalSeconds / 3600)).padStart(2, '0');
        const minutes = String(Math.floor((totalSeconds % 3600) / 60)).padStart(2, '0');
        const seconds = String(totalSeconds % 60).padStart(2, '0');
        return `${hours}:${minutes}:${seconds}`;
    }

    // Funzione per aggiornare il display
    function updateDisplay() {
        timerDisplay.textContent = formatTime(elapsedTime);
    }

    // Rendiamo le funzioni disponibili globalmente
    window.startTimer = function() {
        if (isRunning) return;
        isRunning = true;
        startTime = Date.now() - elapsedTime;
        intervalId = setInterval(() => {
            elapsedTime = Date.now() - startTime;
            updateDisplay();
        }, 100);
    };

    window.pauseTimer = function() {
        if (!isRunning) return;
        isRunning = false;
        clearInterval(intervalId);
    };

    window.resetTimer = function() {
        isRunning = false;
        clearInterval(intervalId);
        elapsedTime = 0;
        updateDisplay();
    };

    // Inizializza il display
    updateDisplay();
});
