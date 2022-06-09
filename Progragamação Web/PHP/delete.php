<?php 

	require("conectaBD.php");
	
	$id = $_GET["id"];
	$stmt = $mysqli_connection->prepare("DELETE FROM CATEGORIA WHERE
	id_categoria = ?;");
	$stmt->bind_param("i", $id);
	$stmt->execute();
	if ($stmt) {
		echo "Deletado com sucesso.";
	} else {
		echo "ERROR.";
	}
	
	$mysqli_connection->close();
?>
