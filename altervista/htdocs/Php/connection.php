
<?php
	$con = new mysqli("localhost","root","","myserra");
	if($con->connect_errno)
		die("Errore Connessione".$con->connect_errno." ". $con->connect_error);
	else
		$con->set_charset("UTF-8");//Così prendiamo anche i caratteri accentati dal Database
?>
