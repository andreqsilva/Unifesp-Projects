<?php

  try {

    $mysqli_connection = new MySQLi("localhost", 348715, 123456, 348715);

    if ($mysqli_connection->connect_error) {
      throw new Exception("Desconectado. ERROR ", $mysqli_connection->connect_error);
    }

  } catch(Exception $e) {
    echo $e->getMessage();
  }
