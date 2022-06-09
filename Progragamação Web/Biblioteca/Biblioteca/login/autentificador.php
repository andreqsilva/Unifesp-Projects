<?php

  session_start();

  try {

    require("../conectaBD.php");

    $usuario = $_POST["user"];
    $senha = md5($_POST["pass"]);

    $select = $mysqli_connection->query("SELECT id_usuario FROM Usuario
                                         WHERE login_usuario='$usuario' AND senha_usuario='$senha'");

    // Verifica se usuario foi encontrado no banco de dados //
    if ($select->num_rows > 0) {
      $dados_usuario = $select->fetch_assoc();
      $_SESSION["usuario_logado"] = $dados_usuario["id_usuario"];
      header("Location: ../index.php");
    }
    else { // Usuario e senha não encontrados //
      header("Location: login.php?falhou=true"); // Volta para página de login
    }

    $select->free_result();
    $mysqli_connection->close();

  } catch(Exception $e) {
    echo $e->getMessage();
  }


?>
