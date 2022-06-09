<?php 

	require("conectaBD.php");
	
	$results = $mysqli_connection->query("SELECT id_categoria, nome, descricao 
	FROM CATEGORIA ORDER BY id_categoria ASC");
	
	echo "<table border=1>";
		
		echo '<tr>';
		echo '	<td> <br> ID </br> </td>';
		echo '	<td> <br> NOME </br> </td>';
		echo '	<td> <br> IDESCRICAO </br> </td>';
		echo '</tr>';
		
		while ($row = $results->fetch_assoc()) {  // captura linha a linha
			echo '<tr>';
			echo '	<td>' . $row["id_categoria"] . '</td>';
			echo '	<td>' . $row["nome"] . '</td>';
			echo '	<td>' . $row["descricao"] . '</td>';
			echo '</tr>';
		}
	echo "</table>";
	
	$mysqli_connection->close();  // encerra conexão
	$results->free(); // libera a variável

?>
