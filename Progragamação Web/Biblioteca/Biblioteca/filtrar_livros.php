<html>
  <head>
    <title>Filtrar</title>
  </head>
  <body>

    <?php include "body/cabecalho.php" ?>

    <main>
      <form method="post" action="filtrar.php">

        <label>Titulo:
          <input name="titulo_livro" type="text"/>
        </label>

        <label>Autor:
          <input name="nome_autor" type="text">
        </label>

        <label>Genero:
            <select name="codigo_secao" id="codigo_secao">
              <option value="0">Selecionar</option>
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
    </main>

    <?php include "body/rodape.php" ?>

  </body>
</html>
