<?php 


	$mysqli_connection = new MySQLi("localhost",348715,123456,348715); // host, bd, pws, user
	
	if ($mysqli_connection->connect_error) {
		echo "Desconectado. Erro: " . $mysqli_connection->connect_error;
	} else {
		echo "Conectado.";
	}


?>
