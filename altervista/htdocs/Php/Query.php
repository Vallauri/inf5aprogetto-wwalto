<?php
$res = $con->query($sql);
/*
1.Errore sintassi query($res è NULL)
2.Res ESISTE, ma è vuoto perchè la query non ha restituito NULLA
*/
if(!$res)
{
	$con->close();//Chiusura connessione
	$codErrore = $con->errno;//Uso delle variabili intermedie, così posso usare le variabili dentro la stringa
	$msgErrore = $con->error;
	die("Errore Esecuzione Query: [$codErrore] $msgErrore");
}

//Se supero la if significa che il RECORDSET esiste
//$data = mysqli_fetch_all($res, MYSQLI_ASSOC);//Questa riga prende il record set e lo restituisce come vettore enumerativo di record, restituisce già un json
?>