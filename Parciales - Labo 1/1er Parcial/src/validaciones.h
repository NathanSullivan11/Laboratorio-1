/*
 * validaciones.h
 *
 *  Created on: 19 abr. 2022
 *      Author: DESKTOP
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_


/**
 * @brief Recibe una cadena y valida si supera el maximo de caracteres permitidos
 * @param mensaje Se imprimira en caso de que supere el máximo de caracteres
 * @param cadena Es la cadena de caracteres a validar
 * @param tamanio Tamaó maximo de caracteres
 */
void validarString(char* mensaje, char* cadena, int tamanio);
/**
 * @brief Valida un entero dentro de un rango de enteros.
 * @param mensaje Se imprimira en caso de que el entero no se encuentro dentro del rango
 * @param enteroValidar Es el numero entero a validar
 * @param minimo Es el entero minimo del rango
 * @param maximo Es el entero maximo del rango
 * @return Devuelve el entero validado
 */
int validarEnterosMaxMin(char* mensaje, int enteroValidar, int maximo, int minimo);
/**
 * @brief Valida un caracter dentro de un rango de caracteres.
 * @param mensaje Se imprimira en caso de que el entero no se encuentro dentro del rango
 * @param caracter Es el caracter a validar
 * @param minimo Es el entero minimo del rango
 * @param maximo  Es el entero maximo del rango
 * @return Devuelve el caracter validado
 */
char validarCharMaxMin(char* mensaje, char caracter, char minimo, char maximo);
/**
 * @brief Valida un caracter, dentro de un rango de 2 caracteres
 * @param mensaje Se imprimira en caso de que el caracter no sea
 * @param caracter Es el caracter a validar
 * @param opcion1 Primera opcion del rango a validar
 * @param opcion2 Segunda opcion del rango a validar
 * @return Devuelve el caracter validado
 */
char validarCharDosOpciones(char* mensaje, char caracter, char opcion1, char opcion2);
#endif /* VALIDACIONES_H_ */
