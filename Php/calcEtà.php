<!DOCTYPE html>
<html lang="it">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Calcolo Età</title>
</head>
<body>
    <h1>Calcola la tua età</h1>
    
    <form method="POST" action="">
        <label for="dataNascita">Data di nascita:</label>
        <input type="date" id="dataNascita" name="dataNascita" required>
        <button type="submit">Calcola</button>
    </form>

    <?php
        if ($_SERVER["REQUEST_METHOD"] == "POST") {
            $dataNascita = new DateTime($_POST["dataNascita"]);
            $oggi = new DateTime();
            $differenza = $oggi->diff($dataNascita);
            $eta = $differenza->y;
            
            echo "<p>La tua età è: $eta anni</p>";
        }
    ?>
</body>
</html>
