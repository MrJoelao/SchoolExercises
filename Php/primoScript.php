<!DOCTYPE html>
<html>
<head>
    <title>Form con PHP</title>
</head>
<body>
    <h1>Saluto personalizzato</h1>
    <form method="POST" action="">
        <label for="nome">Inserisci il tuo nome:</label>
        <input type="text" id="nome" name="nome" required>
        <button type="submit">Invia</button>
    </form>

    <?php
        if ($_SERVER["REQUEST_METHOD"] == "POST") {
            $nome = htmlspecialchars($_POST["nome"]);
            echo "<p>Ciao, $nome! Benvenuto nel mondo di PHP.</p>";
        }
    ?>
</body>
</html>