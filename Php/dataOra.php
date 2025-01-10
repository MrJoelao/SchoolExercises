<!DOCTYPE html>
<html lang="it">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Data e Ora</title>
</head>
<body>
    <h1>Benvenuto!</h1>
    
    <?php
        // Imposta il fuso orario per l'Italia
        date_default_timezone_set('Europe/Rome');
        
        // Ottieni la data e l'ora correnti
        $dataOra = new DateTime();
        
        // Formatta la data in italiano
        $data = $dataOra->format('d/m/Y');
        $ora = $dataOra->format('H:i:s');
        
        // Mostra la data e l'ora
        echo "<p>Oggi è il: $data</p>";
        echo "<p>Ora attuale: $ora</p>";
    ?>
</body>
</html>
