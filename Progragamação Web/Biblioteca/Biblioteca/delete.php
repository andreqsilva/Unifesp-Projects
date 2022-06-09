<?php

  try {

    require("conectaBD.php");

    $titulo = $_POST["titulo_livro"];
    $autor = $_POST["nome_autor"];
    $prateleira = $_POST["num_prateleira"];

    // Verifica se o livro esta cadastrado //
    $select_livro = $mysqli_connection->query("SELECT codigo_livro FROM Livro WHERE titulo_livro = '$titulo'
                                               AND codigo_prateleira = $prateleira AND nome_autor = '$autor'");

    // Livro encontrado //
    if ($select_livro->num_rows > 0) {
      $livro = $select_livro->fetch_assoc();
      $codigo = $livro["codigo_livro"];

      $delete = $mysqli_connection->prepare("DELETE FROM Livro WHERE codigo_livro = ?");
  	  $delete->bind_param("i", $codigo);
  	  $delete->execute();

      // Decrementa o total de livros da prateleira //
      $update_prateleira = $mysqli_connection->query("UPDATE Prateleira SET total_livros = total_livros - 1
                                                      WHERE codigo_prateleira = $prateleira");
    }
    else { // Livro não encontrado //
      header("Location: form_delete.php?erro=true");
      exit;
    }

    $mysqli_connection->close();

    header("Location: form_delete.php?deletado=true");

  } catch (Exception $e) {
    echo $e->getMessage();
  }

?>
