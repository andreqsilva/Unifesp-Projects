<?php 

	require("conectaBD.php");
	
	$nome = "UPDATE" . rand(0,999);
	$descricao = "ALGUMA COISA Desc" . date("h:i:sa");
	
	$id = $_GET["id"];
	
	$stmt = $mysqli_connection->prepare("UPDATE CATEGORIA SET nome = ?,
	descricao = ? WHERE id_categoria = ?;");
	
	$stmt->bind_param("ssi", $nome, $descricao, $id);
	$stmt->execute();
	if ($stmt) {
		echo "<br> Alterado com sucesso.";
	} else {
		echo "<br> ERROR.";
	}
	
	$mysqli_connection->close();

?>
