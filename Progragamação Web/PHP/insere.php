<?php
	// conecta BD
	require("conectaBD.php");
	
	//$_POST["nome"]; Usar forms
	
	$nome = "Nome" . rand(0,999);
	$descricao = "Descricao" . rand(0,999);
	
	$stmt = $mysqli_connection->prepare("INSERT INTO CATEGORIA(nome,descricao) VALUES(?,?);");
	
	// s	string
	// i	inteiro
	// d	double
	// b	blob
	
	$stmt->bind_param("ss", $nome, $descricao); // passando os parametros 
	
	$stmt->execute();  // executando
	
	$newID = $stmt->insert_id;
	echo "ID inserido com sucesso = " . $newID;
	
	$mysqli_connection->close();

?>
