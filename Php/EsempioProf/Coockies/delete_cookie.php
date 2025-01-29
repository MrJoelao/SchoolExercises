<?php
setcookie('user_name', '', time() - 3600); // Scadenza retrodatata
setcookie('user_surname', '', time() - 3600); // Scadenza retrodatata

header('Location: set_cookie.php'); // Reindirizza alla pagina iniziale
exit();
?>
