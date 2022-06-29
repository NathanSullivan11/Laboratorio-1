/*
 * ingreso_de_datos.c
 *
 *  Created on: 4 abr. 2022
 *      Author: DESKTOP
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float get_FlotantePositivo(char * mensaje, char * mensajeError)
{
	float flotanteIngresado;
	printf("%s", mensaje);
	scanf("%f", &flotanteIngresado);
	while(flotanteIngresado < 1)
	{
		printf("%s\n", mensajeError);
		printf("%s", mensaje);
		scanf("%f", &flotanteIngresado);
	}

	return flotanteIngresado;
}

int get_Entero(char * mensaje)
{
	int enteroIngresado;

	printf(mensaje);
	fflush(stdin);
	scanf("%d", &enteroIngresado);

	return enteroIngresado;
}

int get_EnteroPositivo(char * mensaje, char * mensajeError)
{
	int enteroIngresado;

	printf(mensaje);
	fflush(stdin);
	scanf("%d", &enteroIngresado);
	while(enteroIngresado < 1)
	{
		printf("%s\n", mensajeError);
		printf("%s", mensaje);
		scanf("%d", &enteroIngresado);
	}

	return enteroIngresado;
}

void get_String(char * mensaje, char* cadena){

	printf(mensaje);
	fflush(stdin);
	scanf("%[^\n]", cadena);

}

char get_Char(char * mensaje){

	char caracter;
	printf(mensaje);
	fflush(stdin);
	scanf("%c", &caracter);
	return caracter;
}
