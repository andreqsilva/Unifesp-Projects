<?php

  session_start(); // Inicia a SESSION

  require("conectaBD.php");

  // Verifica se a variável SESSION["usuario_logado"] está definida //
  if (!isset($_SESSION["usuario_logado"])) {
    header("Location: login/login.php");
  }

  // Verifica se a variável GET["sair"] está definida //
  if (isset($_GET["sair"])) {
    unset($_SESSION["usuario_logado"]); // Destrói a váriavel de sessão
    header("Location: login/login.php"); // Volta para a página de login
  }

?>

<html>
  <head>
    <title>Biblioteca Online</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" type="text/css" href="estilos.css">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Open+Sans:wght@300;400;600;700;800&display=swap" rel="stylesheet">

    <style>
      #customers td, th {
        border: 1px solid #ddd;
        padding: 8px;
      }

      #customers th {
        padding: 10px;
        text-align: left;
        background-color: #8533ff;
        color: white;
      }

      tr:hover {background-color: #b3b3cc;}

    </style>

  </head>
  <body>
    <div class="corpo">

      <?php include "body/cabecalho.php"  ?>

      <main>

        <?php

          require("conectaBD.php");

          $select_livro = $mysqli_connection->query("SELECT titulo_livro, nome_autor,
                                                            codigo_secao, codigo_prateleira FROM Livro;");
          $select_secao = $mysqli_connection->query("SELECT genero_secao FROM Secao;");

          $generos = array();
          while ($row = $select_secao->fetch_assoc()) {
            $generos[] = $row["genero_secao"];
          }

          $total_livros = $select_livro->num_rows;

          echo "<table id='customers' width='100%'>";
          echo '<tr>';
          echo '	<th> <br> Titulo </br> </th>';
          echo '	<th> <br> Autor </br> </th>';
          echo '	<th> <br> Genero </br> </th>';
          echo '	<th> <br> Prateleira </br> </th>';
          echo '</tr>';

          while ($row = $select_livro->fetch_assoc()) {  // captura linha a linha
            echo '<tr>';
            echo '	<td>' . $row["titulo_livro"] . '</td>';
            echo '	<td>' . $row["nome_autor"] . '</td>';
            echo '	<td>' . $generos[$row["codigo_secao"] - 1] . '</td>';
            echo '	<td>' . $row["codigo_prateleira"] . '</td>';
            echo '</tr>';

          }
          echo "</table>";

          echo "<br>Livros encontrados: " . $total_livros;

          $mysqli_connection->close();  // encerra conexão
          $select_livro->free_result(); // libera a variável
          $select_secao->free_result();

        ?>

      </main>

      <?php include "body/rodape.php"  ?>

    </div>
  </body>
</html>
