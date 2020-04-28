CREATE TABLE IF NOT EXISTS Dati
(
    idDato INT NOT NULL AUTO_INCREMENT,
    dataOraAcquisizione DATETIME NOT NULL,
    temperatura INT NOT NULL,
    umiditaPerc INT NOT NULL,
    luminosita INT NOT NULL,
    lvlAcqua INT NOT NULL,
    umiditaTerrenoPerc INT NOT NULL,
    percorsoImg VARCHAR(80) NOT NULL,
    statoPompa CHAR(1) NOT NULL,
    statoLed CHAR(1) NOT NULL,
    statoVentola CHAR(1) NOT NULL,
    PRIMARY KEY (idDato)
);
ALTER TABLE Dati AUTO_INCREMENT=0;

CREATE TABLE IF NOT EXISTS insAndroid
(
    idDato INT NOT NULL AUTO_INCREMENT,
    dataOraAcquisizione DATETIME NOT NULL,
    temperatura INT NOT NULL,
    umiditaPerc INT NOT NULL,
    luminosita INT NOT NULL,
    lvlAcqua INT NOT NULL,
    umiditaTerrenoPerc INT NOT NULL,
    percorsoImg VARCHAR(80) NOT NULL,
    PRIMARY KEY (idDato)
);
ALTER TABLE insAndroid AUTO_INCREMENT=0;
