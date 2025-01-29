<?php
// Imposta un cookie di esempio
setcookie("test_cookie", "valore_del_cookie", time() + 3600); // Cookie valido per 1 ora
?>

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
        <!-- Link per eliminare il cookie -->
        <a href="<?php echo $_SERVER['PHP_SELF']; ?>?delete=true">Elimina Cookie</a>
    </p>

    <?php
    // Gestione eliminazione cookie
    if(isset($_GET['delete'])) {
        setcookie("test_cookie", "", time() - 3600);
        echo "<script>window.location.href = '" . $_SERVER['PHP_SELF'] . "';</script>";
    }
    ?>
</body>
</html>
