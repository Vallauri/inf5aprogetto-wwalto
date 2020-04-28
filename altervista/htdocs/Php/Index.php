<!DOCTYPE html>
<html>

<head lang="it">
    <meta charset="UTF-8">
    <title>Tabella dati</title>
    <script src="JQuery/jquery-3.3.1.js"></script>
    <script src="../Jquery/JqueryPhp.js"></script>
    <link rel="stylesheet" type="text/css" href="../Css/StylePhp.css" />
</head>

<body>
    <?php
    $codGenere = 1;
    require("connection.php");
    echo ("<form>");
    $sql = "SELECT * FROM Dati";
    require("Query.php");
    //echo("<select id = 'lstGeneri' name = 'lstGeneri'>");
    /*while($record=$res->fetch_assoc())
        {
            $idDato=$record["idDato"];
            $dataOraAcquisizione=$record["dataOraAcquisizione"];
            $temperatura=$record["temperatura"];
            $umidita=$record["umiditaPerc"];
            $luminosita=$record["lumiosita"];
            $lvlAcqua=$record["lvlAcqua"];
            $umiditaTerreno=$record["umiditaTerrenoPerc"];
            $percorso=$record["percorsoImg"];
            /*$idGen = $record["idGenere"];
            $desc = $record["descGenere"];
            echo("<option value = '$idGen'>$desc</option>");*/
    //}
    /*echo("</select>");
        echo("<br>");*/
    echo ("<br><table style='border:1px solid black'>");
    echo ("<tr style='border:1px solid black'>");
    echo ("<td style='border:1px solid black'>idDato</td><td style='border:1px solid black'>dataOraAcquisizione</td><td style='border:1px solid black'>temperatura</td><td style='border:1px solid black'>umiditàPercentuale</td><td style='border:1px solid black'>luminosità</td><td style='border:1px solid black'>livelloAcqua</td>
        <td style='border:1px solid black'>umiditàTerrenoPercentuale</td><td style='border:1px solid black'>percorsoImg</td><td style='border:1px solid black'>StatoPompa</td><td style='border:1px solid black'>Stato Led</td><td style='border:1px solid black'>Stato Ventola</td>");
    echo ("</tr>");
    $sql = "SELECT * FROM Dati";
    require("Query.php");
    while ($record = $res->fetch_assoc()) 
    {
        echo ("<tr style='border:1px solid black'>");
        $idDato = $record["idDato"];
        echo ("<td style='border:1px solid black'>$idDato</td>");
        $dataOraAcquisizione = $record["dataOraAcquisizione"];
        echo ("<td style='border:1px solid black'>$dataOraAcquisizione</td>");
        $temperatura = $record["temperatura"];
        echo ("<td style='border:1px solid black'>$temperatura</td>");
        $umidita = $record["umiditaPerc"];
        echo ("<td style='border:1px solid black'>$umidita</td>");
        $luminosita = $record["luminosita"];
        echo ("<td style='border:1px solid black'>$luminosita</td>");
        $lvlAcqua = $record["lvlAcqua"];
        echo ("<td style='border:1px solid black'>$lvlAcqua</td>");
        $umiditaTerreno = $record["umiditaTerrenoPerc"];
        echo ("<td style='border:1px solid black'>$umiditaTerreno</td>");
        $percorso = $record["percorsoImg"];
        echo ("<td style='border:1px solid black'>$percorso</td>");
        $statoPompa = $record["statoPompa"];
        echo ("<td style='border:1px solid black'>$statoPompa</td>");
        $statoLed = $record["statoLed"];
        echo ("<td style='border:1px solid black'>$statoLed</td>");
        $statoVentola = $record["statoVentola"];
        echo ("<td style='border:1px solid black'>$statoVentola</td>");
        echo ("</tr>");
        /*
                echo("<tr>");
                $idLibro = $record["idLibro"];
                echo("<td>$idLibro</td>");
                $titoloLibro = $record["titoloLibro"];
                echo("<td>$titoloLibro</td>");
                $AnnoPubLibro = $record["AnnoPubLibro"];
                echo("<td>$AnnoPubLibro</td>");
                echo("</tr>");*/
    }
    echo ("</table>");
    echo ("</form>");
    $con->close();
    ?>
</body>