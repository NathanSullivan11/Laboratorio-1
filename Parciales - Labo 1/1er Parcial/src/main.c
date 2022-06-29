/*
 ============================================================================
 Name        : main.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcionesABM.h"
#include "ingreso_de_datos.h"

#define CANT 10
#define DISCOGRAFICAS 3
#define ARTISTAS 4
#define TIPO_ARTISTAS 2
#define PAISES 5

int main(void){

	setbuf(stdout, NULL);

	eAlbum albumes[CANT];
	eDiscografica discograficas[DISCOGRAFICAS];
	eArtista artistas[ARTISTAS];
	eTipoArtista tipoArtista[TIPO_ARTISTAS];
	ePais paises[PAISES];

	char opciones[128];
	int opcion, bandera, id;
	id = 1;
	bandera = 0;

	inicializarAlbumes(albumes, CANT);

	//Funcion para hacer pruebas y no tener que ingresar los albumes manualmente
	id = hardcodearAlbumes(albumes, id, 4);
	bandera = 1;

	hardcodearArtistas(artistas, ARTISTAS);
	hardcodearTipoDeArtistas(tipoArtista, TIPO_ARTISTAS);
	hardcodearDiscograficas(discograficas, DISCOGRAFICAS);
	hardcodearPaises(paises, PAISES);

	do
		{
			sprintf(opciones, "MENU\n1. Altas\n2. Modificar\n3. Baja\n4. Informar:\n5. Listar\n6. SALIR");
			opcion = menu(opciones, 1, 6);
			switch(opcion)
			{
				case 1:   // Alta
					if(alta(albumes, CANT, id, artistas, ARTISTAS, tipoArtista, TIPO_ARTISTAS, discograficas, DISCOGRAFICAS, paises, PAISES) == 0)
					{
						bandera = 1;
						id++;
					}
					else
					{
						printf("\n================\nLISTA LLENA\n================\n");
					}
				break;
				case 2:   // Modificar
					if(bandera == 1)
					{
						modificar(albumes, CANT, paises, PAISES);
					}
					else
					{
						printf("\n==============================================\nNo hay datos cargados en el sistema\n==============================================\n");
					}
				break;
				case 3:
					if(bandera == 1)
					{
						baja(albumes, CANT);
					}
					else
					{
						printf("\n==============================================\nNo hay datos cargados en el sistema\n==============================================\n");
					}
				break;
				case 4:   // Informar
					if(bandera == 1)
					{
						informar(albumes, CANT);
					}
					else
					{
						printf("\n==============================================\nNo hay datos cargados en el sistema\n==============================================\n");
					}
				break;
				case 5:   // Listar
					if(bandera == 1)
					{
						listar(albumes, CANT, artistas, ARTISTAS, tipoArtista, TIPO_ARTISTAS, discograficas, DISCOGRAFICAS, paises, PAISES);
					}
					else
					{
						printf("\n==============================================\nNo hay datos cargados en el sistema\n==============================================\n");
					}
				break;
				case 6:
					printf("\n====================\nSaliste exitosamente\n====================\n");
				break;
			}
			printf("\n");

		}while(opcion != 6);

	return 0;
}


