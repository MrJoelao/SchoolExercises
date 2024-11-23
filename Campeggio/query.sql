USE campeggio;

/* 1. Elenco delle piazzole occupate da almeno un cliente */
SELECT id, nome FROM piazzola WHERE piazzola.id IN(SELECT idpiazzola FROM elementi);

/* 2. Elenco delle piazzole adatte a un gruppo di 7 amici in tenda */
SELECT id, nome, posti FROM piazzola WHERE posti > 6 AND idtipo = 1;

/* 3. Elenco dei clienti che occupano la piazzola al massimo consentito */
SELECT * FROM cliente
    INNER JOIN contratto ON cliente.id = contratto.idcliente
    INNER JOIN elementi ON contratto.id = elementi.idcontratto
    INNER JOIN piazzola ON elementi.idpiazzola = piazzola.id
         WHERE contratto.adulti + contratto.ridotti >= piazzola.posti

/* 4. ELenco di tutte le componenti del contratto */


/* 5. Query che estrae i contratti per i quali il campo Finito non è coerente */
