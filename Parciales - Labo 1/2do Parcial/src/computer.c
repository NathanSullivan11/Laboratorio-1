/*
 * computer.c
 *
 *  Created on: 29 jun. 2022
 *      Author: DESKTOP
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "computer.h"
#include "LinkedList.h"
#include "gets.h"

//////// NEW ///////////

void* computer_new(void)
{
	return (void*) malloc(sizeof(eComputer));
}

eComputer* computer_newParametrosTxt(char* id, char* descripcion,char* precio, char* idTipo, char* cuotas){

	eComputer* this = NULL;
	this = computer_new();
	if(this != NULL)
	{
		if(computer_setDescripcion(this, descripcion) != 0 ||
			computer_setIdTxt(this, id) != 0 ||
			computer_setIdTipoTxt(this,  idTipo) != 0 ||
			computer_setPrecioTxt(this, precio) != 0||
			computer_setCuotasTxt(this, cuotas) != 0)
		{
			computer_delete(this);
			this = NULL;
		}


	}
	return this;
}
///////////// DELETE //////////
int computer_delete(eComputer* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = 0;
		free(this);
	}
	return retorno;
}


///////  GETTERS /////
int computer_getDescripcion(eComputer* this, char* name){
	int retorno = -1;

	if(this != NULL && name != NULL)
	{
		strcpy(name, this->descripcion);
		retorno = 0;
	}
	return retorno;
}
int computer_getId(eComputer* this, int* id){

	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}
int computer_getIdTipo(eComputer* this, int* idTipo){

	int retorno = -1;
	if(this != NULL && idTipo != NULL)
	{
		*idTipo = this->idTipo;
		retorno = 0;
	}

	return retorno;
}
int computer_getIdTipoTxt(eComputer* this, int idTipo, char* tipo){

	int retorno = -1;
	if(this != NULL && tipo != NULL)
	{
		retorno = 0;
		if(idTipo == 1)
		{
			strcpy(tipo, "DESKTOP");
		}
		else
		{
			if(idTipo == 2)
			{
				strcpy(tipo, "LAPTOP");
			}
			else
			{
				retorno = -1;
			}
		}

	}

	return retorno;
}

int computer_getPrecio(eComputer* this, float* precio){

	int retorno = -1;
	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}

	return retorno;
}
int computer_getCuotas(eComputer* this, int* cuotas){

	int retorno = -1;
	if(this != NULL && cuotas != NULL)
	{
		*cuotas = this->cuotas;
		retorno = 0;
	}

	return retorno;
}

///////// SETTERS ////////////

int computer_setId(eComputer* this, int id){

	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}

int computer_setIdTxt(eComputer* this, char* id){

	int retorno = -1;

	if(this != NULL && id != NULL && esNumerica(id))
	{
		this->id = atoi(id);
		retorno = 0;
	}
	return retorno;
}
int computer_setPrecio(eComputer* this, float precio){

	int retorno = -1;
	if(this != NULL && precio > -1)
	{
		this->precio = precio;
		retorno = 0;
	}

	return retorno;
}

int computer_setPrecioTxt(eComputer* this, char* precio){

	int retorno = -1;
	if(this != NULL && precio != NULL && esFlotante(precio))
	{
		this->precio = atof(precio);
		retorno = 0;
	}

	return retorno;
}

int computer_setDescripcion(eComputer* this, char* descripcion){
	int retorno = -1;

	if(this != NULL && descripcion != NULL)
	{
		strcpy(this->descripcion, descripcion);
		retorno = 0;
	}
	return retorno;
}

int computer_setIdTipo(eComputer* this, int idTipo){

	int retorno = -1;

	if(this != NULL && idTipo == 1 && idTipo == 2)
	{
		this->idTipo = idTipo;
		retorno = 0;
	}
	return retorno;
}

int computer_setIdTipoTxt(eComputer* this, char* idTipo){

	int retorno = -1;

	if(this != NULL && idTipo != NULL && esNumerica(idTipo))
	{
		this->idTipo = atoi(idTipo);
		retorno = 0;
	}
	return retorno;
}

int computer_setCuotasTxt(eComputer* this, char* cuotas){

	int retorno = -1;

	if(this != NULL && cuotas != NULL && esNumerica(cuotas))
	{
		this->cuotas = atoi(cuotas);
		retorno = 0;
	}
	return retorno;
}
int computer_setPrecioCuota(eComputer* this, float precioPorCuota)
{
	int retorno = -1;

	if(this != NULL && precioPorCuota > -1)
	{
		this->precioCuota = precioPorCuota;
		retorno = 0;
	}
	return retorno;
}

int computer_getPrecioCuota(eComputer* this, float* precioPorCuota)
{
	int retorno = -1;

	if(this != NULL && precioPorCuota != NULL)
	{
		*precioPorCuota = this->precioCuota;
		retorno = 0;
	}
	return retorno;
}

int computer_menuInt(char options[], int min, int max){

	int opcion;
	printf(options);
	get_Entero("Opción: ", &opcion);
	validarEnterosMaxMin("Ingrese una opción válida", &opcion, min, max);
	return opcion;
}
int computer_LeerArchivo(char* path , LinkedList* listaComputer)
{
	int retorno = -1;
	int pasajerosCargados;

	FILE* fpArchivo;
	if(path != NULL && listaComputer != NULL)
	{

		fpArchivo = fopen(path, "r");
		if(fpArchivo != NULL)
		{

			pasajerosCargados = parser_ComputerFromText(fpArchivo,listaComputer);
			printf("\nSe cargaron %d pasajeros", pasajerosCargados);
			retorno = 0;
		}
		fclose(fpArchivo);

	}
	return retorno;
}

int parser_ComputerFromText(FILE* pFile, LinkedList* lista){
	int retorno = -1;
	char bufferId[128];
	char bufferDescripcion[128];
	char bufferIdTipo[128];
	char bufferPrecio[128];
	char bufferCuotas[128];

	char buffer[128];
	int contador = 0;
	eComputer* auxComputadora;
	if(pFile != NULL && lista != NULL)
	{
		fscanf(pFile, "%[^\n]\n", buffer);
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferDescripcion, bufferPrecio, bufferIdTipo, bufferCuotas) == 5)
			{
				auxComputadora = computer_newParametrosTxt(bufferId, bufferDescripcion, bufferPrecio, bufferIdTipo, bufferCuotas);
				if(auxComputadora != NULL)
				{
					if(!ll_add(lista, auxComputadora))
					{
						contador++;
					}
				}
			}

		}while(!feof(pFile));
	}
	retorno = contador;
	return retorno;
}

int computer_imprimirPorPantalla(LinkedList* listaComputadoras){
	int retorno = -1;
	eComputer* auxComputadora;
	int len;
	int i;
	if(listaComputadoras != NULL)
	{
		printf("\n");
		printf("| Id    Descripcion                                                                                              Precio   Tipo        Cuotas  ");
		printf("\n");
		len = ll_len(listaComputadoras);
		for(i=0;i<len;i++)
		{
			auxComputadora = ll_get(listaComputadoras, i);
			if(auxComputadora != NULL)
			{
				computer_imprimirUno(listaComputadoras, auxComputadora);
			}
		}
		printf("\n");
		retorno = 0;
	}
	return retorno;
}


int computer_imprimirUno(LinkedList* listaComputadoras, eComputer* this){

	int retorno = -1;
	float bufferPrecio;
	char bufferDescripcion[128];
	char bufferTipo[128];
	int bufferCuotas;
	int bufferIdTipo;
	int bufferId;

	if(this != NULL)
	{
		computer_getId(this, &bufferId);
		computer_getDescripcion(this, bufferDescripcion);
		computer_getPrecio(this, &bufferPrecio);
		computer_getIdTipo(this, &bufferIdTipo);
		computer_getIdTipoTxt(this, bufferIdTipo, bufferTipo);
		computer_getCuotas(this, &bufferCuotas);

		printf("\n %-5d   %-100s   $%-10.2f   %-11s   %-5d  ", bufferId, bufferDescripcion ,bufferPrecio, bufferTipo, bufferCuotas);
	}
	return retorno;
}


int computer_ordenarLista(LinkedList* listaComputadoras)
{
	int retorno = -1;
	if(listaComputadoras != NULL)
	{
		if(!ll_sort(listaComputadoras, computer_compararPorCuotas, 0))
		{
			retorno = 0;
		}

	}
	return retorno;
}
int computer_compararPorCuotas(void* e1, void* e2)
{
	int retorno = -2;
	eComputer* computadora1;
	eComputer* computadora2;
	float precio1, precio2;

	if(e1 != NULL &&  e2 != NULL)
	{
		computadora1 = (eComputer*)e1;
		computadora2 = (eComputer*)e2;
		computer_getPrecio(computadora1, &precio1);
		computer_getPrecio(computadora2, &precio2);
		if(precio1 > precio2)
		{
			retorno = 1;
		}
		else
		{
			if(precio1 < precio2)
			{
				retorno = -1;
			}
			else
			{
				retorno = 0;
			}
		}
	}
	return retorno;


}

LinkedList* computer_map(LinkedList* listaComputadoras)
{
	LinkedList* nuevaLista = NULL;

	if(listaComputadoras != NULL)
	{
		nuevaLista = ll_map(listaComputadoras,computer_mapearPorCuotas);
	}
	return nuevaLista;
}

int computer_mapearPorCuotas(void* elemento)
{
	int retorno = -1;
	eComputer* computadora = NULL;
	int cuotas;
	float precio;
	float precioCuota;
	if(elemento != NULL)
	{
		computadora = (eComputer*) elemento;
		computer_getCuotas(computadora, &cuotas);
		computer_getPrecio(computadora, &precio);
		precioCuota = precio/cuotas;

		if(!computer_setPrecioCuota(computadora, precioCuota))
		{
			retorno = 1;
		}
	}
	return retorno;
}


int computer_guardarEnArchivoTxt(char* path , LinkedList* listaComputadoras)
{
	int retorno = -1;
	char bufferDescripcion[128];
	int bufferIdTipo;
	float bufferPrecio;
	float bufferPrecioPorCuota;
	int bufferCuotas;
	int bufferId;

	int len, i;
	FILE* fpArchivo;
	eComputer* auxComputadora;

	if(listaComputadoras != NULL && path != NULL)
	{
		fpArchivo = fopen(path, "w");
		if(fpArchivo != NULL)
		{
			len = ll_len(listaComputadoras);
			fprintf(fpArchivo, "id,descripcion,precio,idTipo,cuotas,valorcuota\n");
			for(i = 0; i < len; i++)
			{
				auxComputadora = (void*) ll_get(listaComputadoras, i);
				if(auxComputadora != NULL)
				{
					if(!computer_getId(auxComputadora, &bufferId) &&
						!computer_getDescripcion(auxComputadora, bufferDescripcion) &&
						!computer_getPrecio(auxComputadora, &bufferPrecio) &&
						!computer_getIdTipo(auxComputadora, &bufferIdTipo) &&
						!computer_getCuotas(auxComputadora, &bufferCuotas) &&
						!computer_getPrecioCuota(auxComputadora, &bufferPrecioPorCuota))
					{

						retorno = 0;
						fprintf(fpArchivo, "%d,%s,%.2f,%d,%d,%.2f\n", bufferId, bufferDescripcion, bufferPrecio, bufferIdTipo, bufferCuotas, bufferPrecioPorCuota);
					}
				}
			}
		}
		fclose(fpArchivo);

	}
	return retorno;
}


