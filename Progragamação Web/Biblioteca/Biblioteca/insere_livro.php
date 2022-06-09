<?php

  try {

    require("conectaBD.php");

    if (empty($_POST["titulo_livro"]) || empty($_POST["nome_autor"])) {
      header("Location: form_livro.php?empty=true");
      exit;
    }

    $ID_autor;
    $codigo_prateleira;
    $titulo = $_POST["titulo_livro"];
    $autor = $_POST["nome_autor"];
    $codigo_secao = $_POST["codigo_secao"];

    // Verifica se o livro já foi cadastrado //
    $select_livro = $mysqli_connection->query("SELECT codigo_livro FROM Livro
                                               WHERE titulo_livro = '$titulo' AND nome_autor = '$autor'");

    // Se o livro ja estiver cadastrado, retorna para o form //
    if ($select_livro->num_rows > 0) {
      header("Location: form_livro.php?inserido=true");
      exit;
    }

    // Verifica se o autor já está cadastrado no banco de dados //
    $select_autor = $mysqli_connection->query("SELECT id_autor, nome_autor FROM Autor
                                               WHERE nome_autor = '$autor'");

    // Autor ja cadastrado //
    if ($select_autor->num_rows > 0) {
      $dados_autor = $select_autor->fetch_assoc();
      $ID_autor = $dados_autor["id_autor"];
    }
    else {
      // Cadastra novo autor no banco de dados //
      $novo_autor = $mysqli_connection->prepare("INSERT INTO Autor(nome_autor) VALUES(?);");
      $novo_autor->bind_param("s", $autor);
      $novo_autor->execute();
      $ID_autor = $novo_autor->insert_id;
    }

    // Define uma prateleira para o livro cadastrado //
    $select_prateleira = $mysqli_connection->query("SELECT codigo_prateleira, total_livros
                                                    FROM Prateleira WHERE codigo_secao = $codigo_secao;");

    /*
      Essa parte do código serve para verificar se tem lugar disponível para inserir
      o novo livro. Cada seção tem duas prateleiras, sendo que cada uma tem espaço
      para armazenar até 50 livros. Caso a primeira prateleira esteja lotada, o livro
      é armazenado na segunda.
    */
    $bool_prateleira = false;
    while ($prateleira = $select_prateleira->fetch_assoc()) {
      $total = $prateleira["total_livros"];
      if ($total < 50) {
        $codigo_prateleira = $prateleira["codigo_prateleira"];
        $total += 1;
        $bool_prateleira = true;
        break; // livro armazenado em uma das prateleiras
      }
    }
    $select_prateleira->free_result();

    if ($bool_prateleira = false) { // sem espaço na secao
      header("Location: form_livro.php?lotada=true");
      exit;
    } else {
      $update_prateleira = $mysqli_connection->query("UPDATE Prateleira SET total_livros = $total
                                                      WHERE codigo_prateleira = $codigo_prateleira;");

      $insere_livro = $mysqli_connection->prepare("INSERT INTO Livro(titulo_livro,nome_autor,
      id_autor,codigo_prateleira,codigo_secao) VALUES(?,?,?,?,?);");

      $insere_livro->bind_param("ssiii", $titulo, $autor, $ID_autor, $codigo_prateleira, $codigo_secao);
      $insere_livro->execute();

    }

    $mysqli_connection->close();

    // Retorna para a página de formulário //
    header("Location: form_livro.php?sucesso=true");

  } catch(Exception $e) {
    echo $e->getMessage();
  }

?>
