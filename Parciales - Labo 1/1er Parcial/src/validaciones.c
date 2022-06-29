/*
 * validaciones.c
 *
 *  Created on: 19 abr. 2022
 *      Author: DESKTOP
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void validarString(char* mensaje, char* cadena, int tamanio){

	while(strlen(cadena) > tamanio || cadena == NULL || strlen(cadena) < 1)
	{
		printf(mensaje);
		fflush(stdin);
		scanf("%[^\n]", cadena);
	}

}

int validarEnterosMaxMin(char* mensaje, int enteroValidar, int minimo, int maximo){

	while(enteroValidar > maximo || enteroValidar < minimo)
	{
		printf(mensaje);
		scanf("%d", &enteroValidar);
	}
	return enteroValidar;
}

char validarCharMaxMin(char* mensaje, char caracter, char minimo, char maximo){

	while(!isalpha(caracter)) {
	    printf("Lo que ingreso no es un caracter: ");
	    fflush(stdin);
	    scanf("%c", &caracter);
	}
	caracter = toupper(caracter);

	while(caracter > maximo || caracter < minimo)
	{
		printf("Ingrese una letra (entre %c - %c", minimo, maximo);
		fflush(stdin);
		scanf("%c", &caracter);
	}

	return caracter;
}

char validarCharDosOpciones(char* mensaje, char caracter, char opcion1, char opcion2){

	while(!isalpha(caracter))
	{
		printf("Lo que ingreso no es un caracter: ");
		fflush(stdin);
		scanf("%c", &caracter);
	}
	caracter = toupper(caracter);
	while(caracter != opcion1 && caracter != opcion2)
	{
		printf(mensaje);
		fflush(stdin);
		scanf("%c", &caracter);
	}
	return caracter;

}
