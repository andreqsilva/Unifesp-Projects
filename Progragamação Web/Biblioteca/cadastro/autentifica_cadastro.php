<?php

  try {

    require("../conectaBD.php");

    $nome = $_POST["name"];
    $usuario = $_POST["user"];
    $senha = md5($_POST["pass"]); // Criptografa a senha

    $select = $mysqli_connection->query("SELECT id_usuario FROM Usuario
                                         WHERE login_usuario='$usuario';");

    // Cria novo usuário se não estiver no banco de dados //
    if ($select->num_rows == 0) {
      $novo_usuario = $mysqli_connection->prepare("INSERT INTO Usuario(nome_usuario, login_usuario,
                                                    senha_usuario) VALUES(?,?,?);");
      $novo_usuario->bind_param("sss", $nome, $usuario, $senha);
      $novo_usuario->execute();
      header("Location: form_cadastro.php?cadastro=true");
    }
    else { // Usuario ja cadastrado no banco de dados //
      header("Location: form_cadastro.php?falhou=true"); // Volta para o formulário
    }

    $select->free_result();
    $mysqli_connection->close();

  } catch(Exception $e) {
    echo $e->getMessage();
  }

?>
