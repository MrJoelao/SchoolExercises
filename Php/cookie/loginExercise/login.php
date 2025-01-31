<?php
require 'config.php';
session_start();

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $email = $_POST['email'];
    $password = $_POST['password'];
    $remember = isset($_POST['remember']);

    $stmt = $pdo->prepare('SELECT * FROM utenti WHERE email = ?');
    $stmt->execute([$email]);
    $user = $stmt->fetch();

    if ($user && password_verify($password, $user['password'])) {
        $_SESSION['user_id'] = $user['id'];
        
        if ($remember) {
            $cookie_value = base64_encode($user['id'] . ':' . $user['email']);
            setcookie('remember_me', $cookie_value, time() + (86400 * 30), "/");
        }
        
        header('Location: dashboard.php');
        exit();
    } else {
        echo "Credenziali non valide";
    }
}
?>

<form method="post">
    <input type="email" name="email" placeholder="Email" required>
    <input type="password" name="password" placeholder="Password" required>
    <label>
        <input type="checkbox" name="remember"> Ricordami
    </label>
    <button type="submit">Login</button>
</form>
