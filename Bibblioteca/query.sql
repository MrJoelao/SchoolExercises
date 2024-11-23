Use Libreria;
SHOW TABLES;

-- 1. SeleziONa tutti gli utenti --
SELECT * FROM libri;

-- 2. SeleziONa tutti gli libri --
SELECT * FROM utenti;

-- 3. SeleziONa tutti gli prestiti --
SELECT * FROM prestiti;

-- 4 . Lista dei libri prestati ad un utente specifico--
SELECT idUtente, Nominativo, idLIbro, TitoloLibro 
FROM utenti 
INNER JOIN prestiti ON idUtente = CodUtente 
INNER JOIN libri ON CodLibro = idLibro 
WHERE CodUtente = 3;

-- 5. CONta dei libri prestati --
SELECT COUNT(*) FROM prestiti;

-- 6. Utenti che hanno preso in prestito un libro --
SELECT DISTINCT idUtente, Nominativo, TitoloLibro, CasaEditrice 
FROM utenti 
INNER JOIN prestiti ON idUtente = prestiti.CodUtente 
INNER JOIN libri ON CodLibro = idLibro;

-- 7. Libri che nON sONo mai stati prestati --
SELECT idLibro, TitoloLibro, CasaEditrice 
FROM libri 
LEFT JOIN prestiti ON idLibro = CodLibro WHERE CodLIbro IS NULL;

-- 8. Numero di prestiti per ogni utente --
SELECT Nominativo, COUNT(*) AS NumeroPrestiti 
FROM prestiti 
INNER JOIN utenti ON CodUtente = IdUtente 
GROUP BY Nominativo;
	
-- 9. Trova i libri prestati più di una volta --
SELECT CodLibro, COUNT(*) AS NumeroPrestiti 
FROM prestiti 
GROUP BY CodLibro HAVING COUNT(*) > 1;

-- 10. Trova gli utenti che nON hanno mai preso in prestito libri --
SELECT * FROM utenti
WHERE idUtente NOT IN (SELECT CodUtente FROM prestiti);

-- 11. Trova i libri prestati nell’ultimo mese --
SELECT DISTINCT TitoloLibro, CodLibro
FROM prestiti
INNER JOIN libri ON idLibro = CodLibro
WHERE DataPrestiti >= DATE_SUB(CURDATE(), INTERVAL 1 MONTH);

-- 12. Trova il prestito più recente --
SELECT * FROM prestiti
INNER JOIN libri ON idLibro = CodLibro
INNER JOIN utenti ON idUtente = CodUtente
ORDER BY DataPrestiti DESC
LIMIT 1;

-- 13.Trova il numero totale di utenti --
SELECT COUNT(*) AS TotaleUtenti FROM utenti;

-- 14. Trova il numero totale di libri --
SELECT COUNT(*) AS TotaleLibri FROM libri;

-- 15. Trova il numero totale di prestiti per ogni libro --
SELECT TitoloLibro, CodLibro, COUNT(*) AS TotalePrestiti
FROM prestiti
INNER JOIN libri ON idLibro = CodLibro
GROUP BY CodLibro;


-- 16. Trova i libri prestati da un utente specifico in un determinato periodo --
SELECT CodLibro, TitoloLibro
FROM prestiti
INNER JOIN libri ON idLibro = CodLibro
WHERE CodUtente = 10 AND DataPrestiti BETWEEN DATE('2023-02-01') AND DATE('2023-08-01');


-- 17. Trova gli utenti che hanno preso in prestito più di 5 libri --
SELECT Nominativo, CodUtente, COUNT(*) AS NumeroPrestiti
FROM prestiti
INNER JOIN utenti  idUtente = CodUtente
GROUP BY CodUtente
HAVING COUNT(*) > 5; 

-- 18. Trova i libri più popolari (prestati più volte) --
SELECT TitoloLibro, CodLibro, COUNT(*) AS NumeroPrestiti
FROM prestiti
INNER JOIN libri ON idLibro = CodLibro
GROUP BY CodLibro
ORDER BY NumeroPrestiti DESC;

-- 19. Trova i prestiti effettuati in un determinato anno --
SELECT * FROM prestiti
WHERE YEAR(DataPrestiti) = 2024;

-- 20, Trova gli utenti cON il maggior numero di prestiti --
SELECT Nominativo, CodUtente, COUNT(*) AS NumeroPrestiti
FROM prestiti
INNER JOIN utenti ON idUtente = CodUtente
GROUP BY CodUtente
ORDER BY NumeroPrestiti DESC;




