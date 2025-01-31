<?php
require 'config.php';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $email = $_POST['email'];
    $password = password_hash($_POST['password'], PASSWORD_DEFAULT);
    $nome = $_POST['nome'];

    $stmt = $pdo->prepare('INSERT INTO utenti (email, password, nome) VALUES (?, ?, ?)');
    try {
        $stmt->execute([$email, $password, $nome]);
        echo "Registrazione completata con successo!";
    } catch (PDOException $e) {
        echo "Errore durante la registrazione: " . $e->getMessage();
    }
}
?>

<form method="post">
    <input type="text" name="nome" placeholder="Nome" required>
    <input type="email" name="email" placeholder="Email" required>
    <input type="password" name="password" placeholder="Password" required>
    <button type="submit">Registrati</button>
</form>
