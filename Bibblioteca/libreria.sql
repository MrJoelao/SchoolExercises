DROP DATABASE IF EXISTS Libreria;
CREATE DATABASE Libreria;
USE Libreria;

CREATE TABLE IF NOT EXISTS libri(
idLibro INT NOT NULL,
TitoloLibro VARCHAR(100),
CasaEditrice VARCHAR(100),
Autore VARCHAR(100),
Info VARCHAR(100),
PRIMARY KEY (idLibro) 
);

CREATE TABLE IF NOT EXISTS utenti(
idUtente INT NOT NULL,
Nominativo VARCHAR(100),
Indirizzo VARCHAR(100),
Telefono VARCHAR(100),
AltriDati VARCHAR(100),
PRIMARY KEY (idUtente)
);

CREATE TABLE IF NOT EXISTS prestiti(
idPrestito INT NOT NULL,
DataPrestiti DATE,
DataRestituzione DATE,
CodUtente INT NOT NULL,
CodLibro INT NOT NULL,
PRIMARY KEY (idPrestito),
FOREIGN KEY (CodUtente) REFERENCES utenti(idUtente),
FOREIGN KEY (CodLIbro) REFERENCES libri(idLibro)
);

INSERT INTO libri (idLibro, TitoloLibro, CasaEditrice, Autore, Info) VALUES
(1, 'Il mistero della lampada magica', 'Editrice Fantastica', 'Dina Lampa', 'Un’avventura sorprendente!'),
(2, 'Dario e le piantine parlanti', 'Casa Editrice Verde', 'Dario Lampa', 'Un libro per i piccoli giardinieri.'),
(3, 'Calen e il tesoro di cioccolato', 'Choco Libri', 'Dario Calen', 'Una dolce avventura.'),
(4, 'Pino Pomodoro e il segreto della salsa', 'Editore Gastronomico', 'Pino Pomodoro', 'Ricette e storie.'),
(5, 'Gina Galletto e le uova misteriose', 'Allevamenti Felici', 'Gina Galletto', 'Un racconto da non perdere.'),
(6, 'La magica avventura di Olga Pasticcino', 'Dolci Sogni', 'Olga Pasticcino', 'Una storia da gustare.'),
(7, 'Felicità Caffè: Ricette e sogni', 'Editore Felice', 'Felicità Caffè', 'Per gli amanti del caffè.'),
(8, 'Sabrina Spaghetti e il grande concorso di pasta', 'Pasta Editore', 'Sabrina Spaghetti', 'Una sfida culinaria.'),
(9, 'Luca Limoncello e la festa estiva', 'Editore Sole', 'Luca Limoncello', 'Festeggia con noi!'),
(10, 'Nino Nutella: La guida alla dolcezza', 'Libri Golosi', 'Nino Nutella', 'Una dolce lettura.');

INSERT INTO utenti (idUtente, Nominativo, Indirizzo, Telefono, AltriDati) VALUES
(1, 'Dina Lampa', 'Via della Luce 1', '0123456789', 'Amante delle lampade.'),
(2, 'Dario Lampa', 'Corso della Magia 2', '0234567890', 'Esperto di illusioni.'),
(3, 'Dario Calen', 'Piazza del Sole 3', '0345678901', 'Collezionista di calendari.'),
(4, 'Pino Pomodoro', 'Via degli Ortaggi 4', '0456789012', 'Chef di fama.'),
(5, 'Gina Galletto', 'Strada delle Frittate 5', '0567890123', 'Amante delle galline.'),
(6, 'Olga Pasticcino', 'Via dei Dolci 6', '0678901234', 'Pasticciera professionista.'),
(7, 'Felicità Caffè', 'Viale dei Caffè 7', '0789012345', 'Barista creativa.'),
(8, 'Sabrina Spaghetti', 'Via della Pasta 8', '0890123456', 'Appassionata di cucina.'),
(9, 'Luca Limoncello', 'Piazza delle Feste 9', '0901234567', 'Festaiolo esperto.'),
(10, 'Nino Nutella', 'Corso dei Dolci 10', '1012345678', 'Goloso incallito.');

INSERT INTO prestiti (idPrestito, DataPrestiti, DataRestituzione, CodUtente, CodLIbro) VALUES
(1, '2024-09-01', '2024-09-15', 1, 1),
(2, '2024-09-02', '2024-09-16', 2, 2),
(3, '2024-09-03', '2024-09-17', 3, 3),
(4, '2024-09-03', '2024-09-21', 3, 4),
(5, '2024-09-05', '2024-09-19', 5, 5),
(6, '2024-09-06', '2024-09-20', 6, 6),
(7, '2024-09-07', '2024-09-21', 7, 7),
(8, '2024-09-06', '2024-09-20', 3, 6),
(10, '2024-09-10', '2024-09-24', 10, 10);

SELECT 
    prestiti.idPrestito,
    prestiti.DataPrestiti,
    prestiti.DataRestituzione,
    utenti.Nominativo,
    libri.TitoloLibro
FROM 
    prestiti
INNER JOIN 
    utenti ON prestiti.CodUtente = utenti.idUtente
INNER JOIN 
    libri ON prestiti.CodLIbro = libri.idLibro;
