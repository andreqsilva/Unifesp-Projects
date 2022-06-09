<html>
<head>
  <title>Filtrar livros</title>
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
    <div class="nav-menu">
      <?php include "body/cabecalho.php" ?>
    </div>
    <main>

      <?php

        require("conectaBD.php");

        $titulo = $_POST["titulo_livro"];
        $autor = $_POST["nome_autor"];
        $codigo_secao = $_POST["codigo_secao"];

        // Nenhum filtro //
        $select_livro = $mysqli_connection->query("SELECT titulo_livro, nome_autor, codigo_secao,
                                                   codigo_prateleira FROM Livro");

        // Pesquisa por título //
        if (!empty($_POST["titulo_livro"]) && empty($_POST["nome_autor"]) && $codigo_secao == 0) {
          $select_livro = $mysqli_connection->query("SELECT titulo_livro, nome_autor, codigo_secao,
                                                     codigo_prateleira FROM Livro WHERE titulo_livro = '$titulo'");

        }
        // Pesquisa por Autor //
        else if (!empty($_POST["nome_autor"]) && empty($_POST["titulo_livro"]) && $codigo_secao == 0) {
          $select_livro = $mysqli_connection->query("SELECT titulo_livro, nome_autor, codigo_secao,
                                                     codigo_prateleira FROM Livro WHERE nome_autor = '$autor'");

        }
        // Pesquisa por Gênero //
        else if (empty($_POST["titulo_livro"]) && empty($_POST["nome_autor"]) && $codigo_secao != 0) {
          $select_livro = $mysqli_connection->query("SELECT titulo_livro, nome_autor, codigo_secao,
                                                     codigo_prateleira FROM Livro WHERE codigo_secao = $codigo_secao");

        }
        // Pesquisa por Titulo e Autor //
        else if (!empty($_POST["titulo_livro"]) && !empty($_POST["nome_autor"]) && $codigo_secao == 0) {
          $select_livro = $mysqli_connection->query("SELECT titulo_livro, nome_autor, codigo_secao, codigo_prateleira
                                                     FROM Livro WHERE titulo_livro = '$titulo' AND nome_autor = '$autor'");

        }
        // Pesquisa por Autor e Gênero //
        else if (!empty($_POST["nome_autor"]) && empty($_POST["titulo_livro"]) && $codigo_secao != 0) {
          $select_livro = $mysqli_connection->query("SELECT titulo_livro, nome_autor, codigo_secao, codigo_prateleira
                                                     FROM Livro WHERE nome_autor = '$autor' AND codigo_secao = $codigo_secao");
        }
        // Pesquisa por Titulo e Gênero //
        else if (!empty($_POST["titulo_livro"]) && empty($_POST["nome_autor"]) && $codigo_secao != 0) {
          $select_livro = $mysqli_connection->query("SELECT titulo_livro, nome_autor, codigo_secao, codigo_prateleira
                                                     FROM Livro WHERE titulo_livro = '$titulo' AND codigo_secao = $codigo_secao");
        }
        // Pesquisa por Titulo, Autor e Gênero //
        else if (!empty($_POST["titulo_livro"]) && !empty($_POST["nome_autor"]) && $codigo_secao != 0) {
          $select_livro = $mysqli_connection->query("SELECT titulo_livro, nome_autor, codigo_secao, codigo_prateleira
                                                     FROM Livro WHERE nome_autor = '$autor' AND codigo_secao = $codigo_secao
                                                                                            AND titulo_livro = '$titulo'");
        }

        $total_livros = $select_livro->num_rows;

        if ($total_livros > 0) {
          $select_secao = $mysqli_connection->query("SELECT genero_secao FROM Secao");

          $generos = array();
          while ($row = $select_secao->fetch_assoc()) {
            $generos[] = $row["genero_secao"];
          }

          echo "<table id='customers' width='100%'>";
          echo '<tr>';
          echo '	<th> Titulo </th>';
          echo '	<th> Autor </th>';
          echo '	<th> Genero </th>';
          echo '	<th> Prateleira </th>';
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
        }

        echo "<br>Livros encontrados: " . $total_livros;

      ?>

    </main>

    <?php include "body/rodape.php" ?>
  </div>
</body>
</html>
