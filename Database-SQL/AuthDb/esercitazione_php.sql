/*
PHP connessione DB, sessioni, cookies
1
Esercitazione PHP: Creazione di un sistema di login con gestione di cookie e sessioni
Creare un'applicazione PHP che consenta agli utenti di:
1. Registrarsi salvando le credenziali in un database.
2. Effettuare il login utilizzando email e password, con gestione della sessione.
3. Ricordare l'accesso tramite un cookie (opzione "Ricordami").
1. Preparazione del database
Creare un database chiamato esercitazione_php con una tabella utenti:
CREATE DATABASE esercitazione_php;
USE esercitazione_php;
CREATE TABLE utenti (
id INT AUTO_INCREMENT PRIMARY KEY,
email VARCHAR(255) NOT NULL UNIQUE,
password VARCHAR(255) NOT NULL,
nome VARCHAR(100) NOT NULL
);

2. Struttura dei file
Creare i seguenti file:
1. config.php: Per la connessione al database.
2. register.php: Per la registrazione degli utenti.
3. login.php: Per il login e la gestione delle sessioni/cookie.
4. dashboard.php: Pagina protetta accessibile solo agli utenti autenticati.
5. logout.php: Per terminare sessioni e cookie.
3. Connessione al database (config.php) Inserire il codice per effettuare la connessione al DB
4. Registrazione (register.php) Implementare il form di registrazione e la logica per salvare gli utenti.
5. Login con sessioni e cookie (login.php) Creare un file per autenticare gli utenti e gestire le sessioni/cookie.
6. Dashboard protetta (dashboard.php) Creare una pagina protetta per gli utenti autenticati.
7. Logout (logout.php) Terminare sessioni e cookie.
*/

CREATE DATABASE esercitazione_php;
USE esercitazione_php;
CREATE TABLE utenti (
id INT AUTO_INCREMENT PRIMARY KEY,
email VARCHAR(255) NOT NULL UNIQUE,
password VARCHAR(255) NOT NULL,
nome VARCHAR(100) NOT NULL
);
