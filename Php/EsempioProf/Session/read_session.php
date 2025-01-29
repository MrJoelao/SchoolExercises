<?php
// Avvia la sessione
session_start();
$user_name = $_SESSION['user_name'] ?? null; // Recupera il nome dalla sessione
$user_surname = $_SESSION['user_surname'] ?? null; // Recupera il nome dalla sessione
?>

<!DOCTYPE html>
<html lang="it">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Leggi Sessione</title>
</head>
<body>
    <?php if ($user_name): ?>
        <h1>Ciao, <?= htmlspecialchars($user_name) ?> <?= htmlspecialchars($user_surname) ?>!</h1>
        <p>Siamo felici di vederti di nuovo.</p>
        <a href="delete_session.php">Elimina la sessione</a>
    <?php else: ?>
        <h1>Non hai ancora impostato un nome!</h1>
        <a href="set_session.php">Imposta il tuo nome</a>
    <?php endif; ?>
</body>
</html>
