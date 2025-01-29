<!DOCTYPE html>
<html>
<head>
    <title>Test Cookie</title>
</head>
<body>
    <?php
    // Verifica se il cookie esiste
    if(isset($_COOKIE["test_cookie"])) {
        echo "Il cookie impostato!<br>";
        echo "Valore del cookie: " . $_COOKIE["test_cookie"];
    } else {
        echo "Il cookie non impostato.";
    }
    ?>

    <p>
        <!-- Imposta un cookie di esempio -->
        <a href="<?php echo $_SERVER['PHP_SELF']; ?>?set=true">Imposta Cookie</a>
    </p>

    <p>
        <!-- Link per eliminare il cookie -->
        <a href="<?php echo $_SERVER['PHP_SELF']; ?>?delete=true">Elimina Cookie</a>
    </p>

    <?php
    // Gestione eliminazione cookie
    if(isset($_GET['delete'])) {
        setcookie("test_cookie", "", time() - 3600);
        echo "<script>window.location.href = '" . $_SERVER['PHP_SELF'] . "';</script>";
    }
    if(isset($_GET['set'])) {
        setcookie("provaCookie", "prova", time() + 3600);
    }
    ?>
</body>
</html>
