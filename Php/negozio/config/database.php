<?php
/*
 * File di configurazione per la connessione al database MySQL
 * Contiene le costanti necessarie per stabilire una connessione
 * e una funzione per ottenere la connessione
 */

define('DB_HOST', 'localhost');     // L'host del database, solitamente localhost per sviluppo locale
define('DB_USER', 'root');         // Username per accedere al database
define('DB_PASS', '');             // Password per accedere al database
define('DB_NAME', 'negozio');      // Nome del database che abbiamo creato

function getConnessione() {
    $conn = new mysqli(DB_HOST, DB_USER, DB_PASS, DB_NAME);

    if ($conn->connect_error) {
        // In caso di errore, terminiamo lo script
        die("Connessione fallita: " . $conn->connect_error);
    }
    
    return $conn;
}
?>
