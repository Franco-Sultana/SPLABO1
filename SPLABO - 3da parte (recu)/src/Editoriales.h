/*
 * Editoriales.h
 *
 *  Created on: 24 nov. 2021
 *      Author: F2019
 */

#ifndef EDITORIALES_H_
#define EDITORIALES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int id;
	char nombre[30];
}eEditorial;

/**
 * @fn eEditorial eEditorial_newParametros*(char*, char*)
 * @brief Contructor parametrizado de editorial
 * @param id Id que se va a asignar a la editorial creada
 * @param nombre nombre que se va a asignar a la editorial creada
 * @return auxiliar de editorial cargado con todos los datos
 */
eEditorial* eEditorial_newParametros(char* id, char* nombre);

/**
 * @fn int eEditorial_setId(eEditorial*, int)
 * @brief setea el id a la editorial
 * @param this Puntero a direccion de memoria donde apunta la editorial
 * @param id id que se va a settear a la editorial
 * @return  0 si no pudo setear || 1 si pudo
 */
int eEditorial_setId(eEditorial* this, int id);
/**
 * @fn int eEditorial_getId(eEditorial*, int*)
 * @brief obtiene el id a la editorial
 * @param this Puntero a direccion de memoria donde apunta la editorial
 * @param id puntero a direccion de memoria donde apunta el id que se quiere obtener
 * @return 0 si no pudo obtener el dato || 1 si pudo
 */
int eEditorial_getId(eEditorial* this, int* id);

/**
 * @fn int eEditorial_setNombre(eEditorial*, char*)
 * @brief setea el nombre a la editorial
 * @param this Puntero a direccion de memoria donde apunta la editorial
 * @param nombre puntero a direccion de memoria donde apunta el nombre que se quiere setear
 * @return  0 si no pudo setear || 1 si pudo
 */
int eEditorial_setNombre(eEditorial* this, char* nombre);
/**
 * @fn int eEditorial_getNombre(eEditorial*, char*)
 * @brief obtiene el nombre a la editorial
 * @param this Puntero a direccion de memoria donde apunta la editorial
 * @param nombre puntero a direccion de memoria donde apunta el nombre que se quiere obtener
 * @return 0 si no pudo obtener el dato || 1 si pudo
 */
int eEditorial_getNombre(eEditorial* this, char* nombre);

#endif /* EDITORIALES_H_ */
