/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "InterfaceClienteServidorModulos.h"


void
autorizar_usuarios_1(char *host)
{
	CLIENT *clnt;
	nodo_turno  *result_1;
	char * identificacion;

#ifndef	DEBUG
	clnt = clnt_create (host, autorizar_usuarios, autorizar_usuarios_version, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	identificacion = (char*)malloc(50*sizeof(char));

	printf("======== Sistema para la generacion de turnos ========");
	printf("\nDigite la identificacion: ");
	scanf("%s", identificacion);
	result_1 = generarturno_1(&identificacion, clnt);
	if (result_1 == (nodo_turno *) NULL) {
		clnt_perror (clnt, "call failed");
	}else{
		printf("\n ==== Datos generados por el sistema =====");
		printf("\nNumero de identificacion: %s", (*result_1).identificacionUsuario);
		printf("\nNumero de turno: %d", (*result_1).numeroTurno);
		printf("\nCantidad de usuarios en la fila virtual: %d", (*result_1).cantidadUsuariosFilaVirtual);
		printf("\n");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	autorizar_usuarios_1 (host);
exit (0);
}
