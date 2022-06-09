<!DOCTYPE html>
<html lang="pt-br">
<head>
	<title>LOGIN</title>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<link rel="stylesheet" type="text/css" href="../estilos.css">
	<link rel="preconnect" href="https://fonts.googleapis.com">
	<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
	<link href="https://fonts.googleapis.com/css2?family=Open+Sans:wght@300;400;600;700;800&display=swap" rel="stylesheet">

	<style>
		a:link, a:visited {
			background-color: #e6ccff;
			color: black;
			padding: 5px;
			border-radius: 4px;
			text-decoration: none;
			display: inline-block;
		}
	</style>

</head>
<body>
	<div class="corpo">
		<div id="login">
		<header>

			<fieldset>
		    <legend>Desconectado</legend>
					<p>Conecte-se ao Library Online</p>
		  </fieldset>
			<br>

		</header>
		<main>
				<form method="post" action="autentificador.php">

					<label>Usuario:
						<input name="user" type="text"/>
					</label>

	        <label>Senha:
	          <input name="pass" type="password"/>
	        </label>

					<button type="submit">Entrar</button>

				</form>
			</div>
      <?php
        if ($_GET["falhou"]) {
          echo "<script type='text/javascript'>alert('Usuario ou senha incorretos');</script>";
        }
      ?>
      <br>
      <a href="../cadastro/form_cadastro.php">Criar conta</a>

		</main>

	</div>
</body>
<footer>

  <hr/>
  <center>
    <img src="../body/unifesp.png" alt="Unifesp" width="160" alig="middle">
  </center>

</footer>
</html>
