DROP DATABASE IF EXISTS group3;
CREATE DATABASE project;

USE project;

CREATE TABLE partida(
	id INT PRIMARY KEY NOT NULL,
	fecha INT NOT NULL,
	hora INT NOT NULL,--En minutos
	campo VARCHAR(20)
)ENGINE=InnoDB;

CREATE TABLE jugador(
	id INT PRIMARY KEY NOT NULL,
	username VARCHAR(20),
	skin VARCHAR(20)
)ENGINE=InnoDB;

CREATE TABLE participacion(
	id_J INT,
	id_P INT,
	crono INT NOT NULL,
	posicion INT NOT NULL,
	FOREING KEY (id_J) REFERENCES jugador(id),
	FOREING KEY (id_P) REFERENCES partida(id),
)ENGINE=InnoDB;

--Insertar valores6

INSERT INTO partida VALUES(1,120521,1022,'azul');
INSERT INTO partida VALUES(2,140521,922,'azul');
INSERT INTO jugador VALUES(1,'victorino','mario');
INSERT INTO jugador VALUES(2,'polete04','luigi');
INSERT INTO participacion VALUES(1,1,45,1);
INSERT INTO participacion VALUES(2,1,50,2);
INSERT INTO participacion VALUES(1,2,63,2);
INSERT INTO participacion VALUES(2,2,47,1);--hola



