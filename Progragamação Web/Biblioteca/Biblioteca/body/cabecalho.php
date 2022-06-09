<?php

  require("conectaBD.php");

  // Se a variável SESSION não tiver sido inicialiada, starta //
  if (!isset($_SESSION)) {
    session_start();
  }

  try {

    $id_usuario = $_SESSION["usuario_logado"];
    $select = $mysqli_connection->query("SELECT nome_usuario FROM Usuario
                                         WHERE id_usuario=$id_usuario");

    $dados_usuario = $select->fetch_assoc();
    $nome_usuario = $dados_usuario["nome_usuario"];

    $select->free_result();
    $mysqli_connection->close();

  } catch(Exception $e) {
    echo getMessage($e->getMessage());
  }
  
?>
<div id="login">
<header>
  <fieldset>
    <legend>Conectado</legend>
    <p> Bem-vindo, <strong> <?= $nome_usuario ?> </strong>
  </fieldset>

  <nav id="link">
    <ul>
    <li> <a href="index.php">Tela Inicial</a> </li>

      <li> <a href="form_livro.php">Cadastrar Livro</a> </li>
      <li> <a href="form_delete.php">Remover Livro</a> </li>
      <li> <a href="index.php?sair=true">Sair</a> </li>

    </ul>
  </nav>
  <br>
  <center>
  <div id="search-form">
    <form method="post" action="filtrar.php">
      <label> 
        <input name="titulo_livro" type="text" placeholder="Titulo do livro"/>
      </label>

      <label>
        <input name="nome_autor" type="text" placeholder="Nome do autor"/>
      </label>

      <label>
          <select name="codigo_secao" id="codigo_secao">
            <option value="0">Genero</option>
            <option value="1">Literatura Brasileira</option>
            <option value="2">Literatura Estrangeira</option>
            <option value="3">Romance</option>
            <option value="4">Ficcao Cientifica</option>
            <option value="5">Suspense</option>
            <option value="6">Biografia</option>
            <option value="7">Poesia</option>
            <option value="8">Matematica</option>
            <option value="9">Computacao</option>
            <option value="10">Biologia</option>
          </select>
      </label>

      <button type="submit">Filtrar</button>

    </form>
  </div>
  </center>
</header>
</div>
<br>
