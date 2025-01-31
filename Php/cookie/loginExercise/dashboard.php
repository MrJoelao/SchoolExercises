<?php
session_start();
require 'config.php';

if (!isset($_SESSION['user_id'])) {
    if (isset($_COOKIE['remember_me'])) {
        $cookie_data = base64_decode($_COOKIE['remember_me']);
        list($user_id, $email) = explode(':', $cookie_data);
        
        $stmt = $pdo->prepare('SELECT * FROM utenti WHERE id = ? AND email = ?');
        $stmt->execute([$user_id, $email]);
        $user = $stmt->fetch();
        
        if ($user) {
            $_SESSION['user_id'] = $user['id'];
        } else {
            header('Location: login.php');
            exit();
        }
    } else {
        header('Location: login.php');
        exit();
    }
}

$stmt = $pdo->prepare('SELECT nome FROM utenti WHERE id = ?');
$stmt->execute([$_SESSION['user_id']]);
$user = $stmt->fetch();
?>

<h1>Benvenuto, <?php echo htmlspecialchars($user['nome']); ?>!</h1>
<a href="logout.php">Logout</a>
