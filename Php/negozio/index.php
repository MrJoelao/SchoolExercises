<!DOCTYPE html>
<html lang="it">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Gestione Negozio</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 20px;
            display: flex;
            flex-direction: column;
            align-items: center;
            min-height: 100vh;
        }
        .container {
            text-align: center;
            max-width: 800px;
            width: 100%;
        }
        .menu {
            margin-top: 20px;
        }
        .menu a {
            display: inline-block;
            padding: 10px 20px;
            margin: 5px;
            background-color: #007bff;
            color: white;
            text-decoration: none;
            border-radius: 5px;
        }
        .menu a:hover {
            background-color: #0056b3;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Gestione Negozio</h1>
        
        <div class="menu">
            <h2>Gestione Utenti</h2>
            <a href="utenti/lista.php">Lista Utenti</a>
            <a href="utenti/inserisci.php">Nuovo Utente</a>
        </div>

        <div class="menu">
            <h2>Gestione Prodotti</h2>
            <a href="prodotti/lista.php">Lista Prodotti</a>
            <a href="prodotti/inserisci.php">Nuovo Prodotto</a>
        </div>
    </div>
</body>
</html>
