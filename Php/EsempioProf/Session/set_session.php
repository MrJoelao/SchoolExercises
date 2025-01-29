<?php
// Avvia la sessione
session_start();

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $name = htmlspecialchars($_POST['name']); // Prevenzione XSS
	$surname = htmlspecialchars($_POST['surname']); // Prevenzione XSS
    $_SESSION['user_name'] = $name; // Salva il nome nella sessione
	$_SESSION['user_surname'] = $surname; // Salva il nome nella sessione
    header('Location: read_session.php'); // Reindirizza per leggere la sessione
    exit();
}
?>

<!DOCTYPE html>
<html lang="it">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Imposta Sessione</title>
</head>
<body>
    <h1>Benvenuto!</h1>
    <form method="POST" action="">
        <label for="name">Inserisci il tuo nome:</label>
        <input type="text" id="name" name="name" required>
		<br><br>
		<label for="name">Inserisci il tuo cognome:</label>
        <input type="text" id="surname" name="surname" required>
        <button type="submit">Salva</button>
    </form>
</body>
</html>
