/*
 ============================================================================
 Name        : Laboratorio_2doPARCIAL.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "gets.h"
#include "computer.h"

int main(void) {
	setbuf(stdout, NULL);

	LinkedList* listaComputadoras;
	LinkedList* listaComputadorasMapeada;
	listaComputadoras = ll_newLinkedList();
	int opcion;
	int banderaMap = 0;
	char path[50];
	do{
		opcion = computer_menuInt("1. Leer archivo .csv\n2. Ordenar lista por cuotas descendentemente\n3. Imprimir por pantalla la lista\n4. Mapear lista\n5. Generar archivo mapeado.csv\n6. Salir\n", 1, 6);
		switch(opcion)
		{
		case 1: // Leer archivo
			get_String("Archivo a abrir: ", path, 50);
			if(!computer_LeerArchivo(path, listaComputadoras))
			{
				printf("\nSE LEYO EXITOSAMENTE");
			}
			break;
		case 2: // Ordenar lista
			if(!ll_isEmpty(listaComputadoras))
			{
				if(!computer_ordenarLista(listaComputadoras))
				{
					printf("\nSE ORDENO EXITOSAMENTE");
				}
			}
			else
			{
				printf("\n==========\nLista vacia\n==========\n");
			}
			break;
		case 3: // Imprimir por pantalla
			if(!ll_isEmpty(listaComputadoras))
			{
				if(!computer_imprimirPorPantalla(listaComputadoras))
				{
					printf("\nSE IMPRIMIO EXITOSAMENTE");

				}
				else
				{
					printf("\n NO SE PUDO IMPRIMIR");
				}
			}
			else
			{
				printf("\n==========\nLista vacia\n==========\n");
			}
			break;
		case 4:
			if(!ll_isEmpty(listaComputadoras))
			{
				listaComputadorasMapeada = computer_map(listaComputadoras);
				if(listaComputadorasMapeada != NULL)
				{
					printf("\nSE MAPEO EXITOSAMENTE");
					banderaMap = 1;
				}
			}
			else
			{
				printf("\n==========\nLista vacia\n==========\n");
			}
			break;
		case 5:
			if(banderaMap == 1)
			{
				if(!computer_guardarEnArchivoTxt("mapeado.csv",listaComputadorasMapeada))
				{
					printf("\nSE GENERO EL ARCHIVO EXITOSAMENTE");

				}
				else
				{
					printf("\n NO SE PUDO IGENERAR EL ARCHIVO");
				}
			}
			else
			{
				printf("\n PRIMERO DEBE MAPEAR LA LISTA");
			}
			break;
		case 6:
			printf("\n========================\nSaliste del sistema\n========================\n");
			break;

		}
		printf("\n");

	}while(opcion != 6);

	ll_deleteLinkedList(listaComputadoras);
	ll_deleteLinkedList(listaComputadorasMapeada);
	return 0;
}

