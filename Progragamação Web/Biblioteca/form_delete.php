<html>
  <head>
    <title>Remover livros</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" type="text/css" href="estilos.css">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Open+Sans:wght@300;400;600;700;800&display=swap" rel="stylesheet">

  </head>
  <body>

    <div class="corpo">

      <?php include "body/cabecalho.php" ?>

      <main>
        <div id="form-livro">
          <h2 align="center">Remover Livro</h2>
          <form method="post" action="delete.php">

            <label>Titulo do livro
              <input name="titulo_livro" type="text" placeholder="Informe o titulo do livro" />
            </label>

            <label>Nome do autor
              <input name="nome_autor" type="text" placeholder="Informe o nome do autor" />
            </label>


            <label>Numero da prateleira
              <input name="num_prateleira" type="number" placeholder="Informe o numero da prateleira" />
            </label>

            <button type="submit">Remover</button>

          </form>
        </div>

        <?php
  				if (isset($_GET["erro"])) {
  					echo "<script type='text/javascript'>alert('Livro nao encontrado');</script>";
  				}
  				if (isset($_GET["deletado"])){
  						echo "<script type='text/javascript'>alert('Livro removido com sucesso');</script>";
  				}
        ?>

      </main>

      <?php include "body/rodape.php" ?>
    </div>
  </body>
</html>
