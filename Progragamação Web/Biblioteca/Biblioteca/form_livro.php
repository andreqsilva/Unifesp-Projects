<!DOCTYPE html>
<html lang="pt-br">
  <head>
    <title>Cadastrar Livros</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" type="text/css" href="estilos.css">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Open+Sans:wght@300;400;600;700;800&display=swap" rel="stylesheet">
    <link rel="stylesheet" href="estilo.css">

  </head>
  <body>
    <div class="corpo">

      <?php include "body/cabecalho.php" ?>

      <main>
        <div id="form-livro">
          <h2 align="center">Cadastrar Livro</h2>
          <form method="post" action="insere_livro.php">

            <label>Titulo do livro
              <input name="titulo_livro" type="text" placeholder="Informe o titulo do livro" />
            </label>

            <label>Nome do autor
              <input name="nome_autor" type="text" placeholder="Informe o nome do autor" />
            </label>

            <label for="codigo_secao">Genero</label>
              <select name="codigo_secao" id="codigo_secao">
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

            <button type="submit">Cadastrar</button>

          </form>
        </div>

        <?php
          if (isset($_GET["empty"])) {
            echo "<script type='text/javascript'>alert('Insira todas as informacoes do livro');</script>";
          }
  				if (isset($_GET["inserido"])) {
  					echo "<script type='text/javascript'>alert('Livro ja cadastrado');</script>";
  				}
  				if (isset($_GET["lotada"])){
  						echo "<script type='text/javascript'>alert('Essa secao esta lotada');</script>";
  				}
          if (isset($_GET["sucesso"])) {
            echo "<script type='text/javascript'>alert('Livro cadastrado com sucesso');</script>";
          }
        ?>

      </main>

      <?php include "body/rodape.php" ?>
    </div>
  </body>
</html>
