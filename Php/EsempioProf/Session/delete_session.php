<?php
// Avvia la sessione
session_start();

// Elimina tutte le variabili di sessione
session_unset();

// Distruggi la sessione
session_destroy();

// Reindirizza alla pagina di impostazione della sessione
header('Location: set_session.php');
exit();
?>
