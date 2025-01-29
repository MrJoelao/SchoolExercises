<?php
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $name = htmlspecialchars($_POST['name']); // Prevenzione XSS
    $surname = htmlspecialchars($_POST['surname']); // Prevenzione XSS
	setcookie('user_name', $name, time() + 3600); // Cookie valido per 1 ora	
    setcookie('user_surname', $surname, time() + 3600); // Cookie valido per 1 ora
    header('Location: read_cookie.php'); // Reindirizza per leggere il cookie
    exit();
}
?>

<!DOCTYPE html>
<html lang="it">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Imposta Cookie</title>
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
