/*
 * computer.h
 *
 *  Created on: 29 jun. 2022
 *      Author: DESKTOP
 */

#ifndef COMPUTER_H_
#define COMPUTER_H_
#define TAM_DESCRIPCION 100

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

typedef struct{

	int id;
	char descripcion[TAM_DESCRIPCION];
	float precio;
	int idTipo;
	int cuotas;
	float precioCuota;
}eComputer;


//// CONSTRUCTOR ////
/**
 * Reserva memoria de manera dinamica para un puntero del tipo eComputer
 * @return eComputer*
 */
void* computer_new(void);
/**
 * Recibe cada atributo de una computadora en string, y lo crea si todos los datos son válidos
 * @param char* id
 * @param char* descripcion
 * @param char* precio
 * @param char* idTipo
 * @param char* cuotas
 * @return eComputer* si salio ok. NULL si hubo error
 */
eComputer* computer_newParametrosTxt(char* id, char* descripcion,char* precio, char* idTipo, char* cuotas);

//// DESTRUCTOR ////
/**
 * Libera una computadora de memoria
 * @param eComputer* this
 * @return int 1 si salio ok. -1 si hubo error
 */
int computer_delete(eComputer* this);

/************** ****************************************************************************/
/**************                 SETTERS Y GETTERS                 **************************/
/************** ****************************************************************************/

/**
 * Obtiene el id de una computadora
 * @param eComputer* this
 * @param int id
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int computer_getId(eComputer* this, int* id);
/**
 * Obtiene la descripcion de una computadora
 * @param eComputer* this
 * @param char* descripcion
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int computer_getDescripcion(eComputer* this, char* name);
/**
 * Obtiene el idTipo de una computadora
 * @param eComputer* this
 * @param int* idTipo
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int computer_getIdTipo(eComputer* this, int* idTipo);
/**
 * Obtiene el idTipo de una computadora en modo string
 * @param eComputer* this
 * @param int idTipo
 * @param char* tipo
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int computer_getIdTipoTxt(eComputer* this, int idTipo, char* tipo);
/**
 * Obtiene el precio de una computadora
 * @param eComputer* this
 * @param float* precio
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int computer_getPrecio(eComputer* this, float* precio);
/**
 * Obtiene las cuotas de una computadora
 * @param this
 * @param int* cuotas
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int computer_getCuotas(eComputer* this, int* cuotas);
/**
 * Obtiene el precio por cuota de una computadora
 * @param this
 * @param float* precioCuota
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int computer_getPrecioCuota(eComputer* this, float* precioCuota);
///////////////////   SETTER   ///////////////////////
/**
 * Le asigna un id a una computadora
 * @param eComputer* this
 * @param id
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int computer_setId(eComputer* this, int id);
/**
 * Le asigna un id a una computadora recibido como string
 * @param eComputer* this
 * @param id
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int computer_setIdTxt(eComputer* this, char* id);
/**
 * Le asigna un precio a una computadora
 * @param eComputer* this
 * @param id
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int computer_setPrecio(eComputer* this, float precio);
/**
 * Le asigna un precio a una computadora recibido como string
 * @param eComputer* this
 * @param precio
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int computer_setPrecioTxt(eComputer* this, char* precio);
/**
 * Le asigna las cuotas a una computadora recibido como string
 * @param eComputer* this
 * @param cuotas
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int computer_setCuotasTxt(eComputer* this, char* cuotas);
/**
 * Le asigna una descripcion a una computadora
 * @param eComputer* this
 * @param descripcion
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int computer_setDescripcion(eComputer* this, char* descripcion);
/**
 *  Le asigna un idTipo a una computadora
 * @param eComputer* this
 * @param idTipo
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int computer_setIdTipo(eComputer* this, int idTipo);
/**
 *  Le asigna un idTipo a una computadora recibido como string
 * @param eComputer* this
 * @param idTipo
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int computer_setIdTipoTxt(eComputer* this, char* idTipo);
/**
 * Le asigna el valor del precio de la cuota a una computadora
 * @param eComputer* this
 * @param precioCuota
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int computer_setPrecioCuota(eComputer* this, float precioCuota);
//// MENU ////
/**
 * Imprime un menu numerico y pide el ingreso de una opcion
 * @param char options
 * @param int min Primera opcion del menu
 * @param int max Ultima opcion del menu
 * @return int Devuelve la opcion ingresada
 */
int computer_menuInt(char options[], int min, int max);

//// PARSER ////
/**
 * Parsea los datos de las computadoras desde el archivo data.csv (modo texto).
 * @param pFile FILE*
 * @param listaComputadoras LinkedList*
 * @return int -1 si error. (cantidad de computadoras cargadas) si salio todo OK
 */
int parser_ComputerFromText(FILE* pFile, LinkedList* listaComputadoras);
//// PUNTO 1 ////
/**
 * Lee un archivo recibido como parametros y lo carga en una lista
 * @param path
 * @param listaComputer
 * @return Devuelve 0 si salio ok. -1 si hubo error
 */

int computer_LeerArchivo(char* path , LinkedList* listaComputer);
///// PUNTO 2 ////
/**
 * Ordena la lista de computadoras por el numero de cuotas
 * @param listaComputadoras
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int computer_ordenarLista(LinkedList* listaComputadoras);
/**
 * Compara el numero de cuotas de 2 computadoras
 * @param void* e1
 * @param void* e2
 * @return (1) si e1 > e2. (-1) si e1 < e2. (0) si e1 = e2
 */
int computer_compararPorCuotas(void* compu1, void* compu2);

//// PUNTO 3 ////
/**
 * Imprime la lista completa de computadoras
 * @param listaComputadoras
 * @return Devuelve 0 si salio ok. -1 si hubo error
 */
int computer_imprimirPorPantalla(LinkedList* listaComputadoras);
/**
 * Imprime una sola computadora
 * @param listaComputadoras
 * @param this
 * @return Devuelve 0 si salio ok. -1 si hubo error
 */
int computer_imprimirUno(LinkedList* listaComputadoras, eComputer* this);
//// PUNTO 4 ////
/**
 * Mapea la lista de computadoras
 * @param listaComputadoras
 * @return Devuelve una nueva lista si se pudo mapear. (NULL) si hubo error
 */
LinkedList* computer_map(LinkedList* listaComputadoras);
/**
 * Mapea un 1 elemento agregandole el campo del valor por cuota
 * @param elemento
 * @return 1 si salio ok. (-1) si hubo error
 */
int computer_mapearPorCuotas(void* elemento);
/// PUNTO 5 ///
/**
 * Escribe en un archivo (recibido como parametro) una lista de computadoras
 * @param path
 * @param listaComputadoras
 * @return Devuelve 0 si salio ok. -1 si hubo error
 */
int computer_guardarEnArchivoTxt(char* path , LinkedList* listaComputadoras);


#endif /* COMPUTER_H_ */
