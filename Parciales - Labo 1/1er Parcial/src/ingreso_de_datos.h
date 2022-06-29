/*
 * ingreso_de_datos.h
 *
 *  Created on: 4 abr. 2022
 *      Author: DESKTOP
 */

#ifndef INGRESO_DE_DATOS_H_
#define INGRESO_DE_DATOS_H_
/**
 * @brief Pide un numero flotante positivos
 * @param mensaje Es el mensaje a mostrar al momento de pedir el numero
 * @param mensajeError Es el mensaje a mostrar en caso de que no sea positivo, muestro por pantalla este mensaje
 * @return Devuelve el flotante validado
 */
float get_FlotantePositivo(char * mensaje, char * mensajeError);
/**
 * @brief Pido un entero
 * @param mensaje Es el mensaje a mostrar al momento de pedir el entero
 * @return Devuelve el entero ingresado
 */
int get_Entero(char * mensaje);
/**
 * @brief Pide un entero y valida que sea mayor a 0
 * @param mensaje Es el mensaje a mostrar al momento de pedir el entero positivo
 * @param mensajeError Es el mensaje a mostrar en caso de que no sea positivo, muestro por pantalla este mensaje
 * @return Devuelve el entero validado
 */
int get_EnteroPositivo(char * mensaje, char * mensajeError);

/**
 * @brief Pide el ingreso de una cadena de caracteres y lo copia a la cadena recibida como parametro
 * @param mensaje Es el mensaje a mostrar al momento de pedir el string
 * @param cadena Es la cadena a la que se le copiara lo ingresado por teclado
 */
void get_String(char* mensaje, char* cadena);

/**
 * @brief Pide el ingreso de un solo caracter
 * @param mensaje Es el mensaje a mostrar al momento de pedir el caracter
 * @return Devuelve el caracter ingresado
 */
char get_Char(char * mensaje);

#endif /* INGRESO_DE_DATOS_H_ */
