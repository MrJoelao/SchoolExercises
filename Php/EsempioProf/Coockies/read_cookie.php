<?php
$user_name = $_COOKIE['user_name'] ?? null;
$user_surname = $_COOKIE['user_surname'] ?? null;
?>

<!DOCTYPE html>
<html lang="it">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Leggi Cookie</title>
</head>
<body>
    <?php if ($user_name): ?>
        <h1>Ciao, <?= htmlspecialchars($user_name) ?> <?= htmlspecialchars($user_surname) ?>!</h1>
        <p>Siamo felici di vederti di nuovo.</p>
        <a href="delete_cookie.php">Elimina il cookie</a>
    <?php else: ?>
        <h1>Non hai ancora impostato un nome!</h1>
        <a href="set_cookie.php">Imposta il tuo nome</a>
    <?php endif; ?>
</body>
</html>
