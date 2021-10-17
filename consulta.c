#include <stdio.h>
#include<mysql.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
	MYSQL *conn;
	int err;
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	char username[20];
	char consulta[150];
	conn=mysql_init(NULL);
	if(conn==NULL){
		printf("error al crear la conexion: %u %s\n", mysql_errno(conn), mysql_error(conn));
		exit(1);
	}
	conn=mysql_real_connect(conn, "localhost","root","mysql","group3",0,NULL,0);
	if(conn==NULL){
		printf("error al inicializar la conexion: %u %s\n", mysql_errno(conn), mysql_error(conn));
		exit(1);
	}
	printf("Dame el username del jugador que quieras saber el tiempo de juego\n");
	scanf("%s",username);
	strcpy(consulta,"SELECT SUM(participacion.crono) FROM (jugador,participacion) WHERE jugador.username='");
	strcat(consulta,username);
	strcat(consulta,"' AND jugador.id=participacion.id_J");
	
	err=mysql_query(conn,consulta);
	if(err!=0){
		printf("Error al consultar datos de la base %u %s\n", mysql_errno(conn),mysql_error(conn));
		exit(1);
	}
	
	resultado=mysql_store_result(conn);
	row=mysql_fetch_row(resultado);
	if(row==NULL || row[0]==NULL)
		printf("No existe un jugador con ese username\n");
	else
		printf("Tiempo total jugado por %s es: %s", username, row[0]);
	mysql_close(conn);
	exit(0);
	
	return 0;
}

