DROP DATABASE IF EXISTS negozio;
CREATE DATABASE negozio;
USE negozio;

CREATE TABLE utenti (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(50),
    email VARCHAR(100)
);

CREATE TABLE prodotti (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(100)
);

CREATE TABLE ordini (
    id          INT PRIMARY KEY AUTO_INCREMENT,
    id_utente   INT,
    id_prodotto INT,
    data_ordine DATE,
    FOREIGN KEY (id_utente) REFERENCES utenti (id),
    FOREIGN KEY (id_prodotto) REFERENCES prodotti (id)
);