/*
 * Editoriales.c
 *
 *  Created on: 24 nov. 2021
 *      Author: F2019
 */

#include "Editoriales.h"

eEditorial* eEditorial_newParametros(char* id, char* nombre)
{
	eEditorial* auxEditorial = NULL;
	if(id != NULL && nombre != NULL)
	{
		auxEditorial = (eEditorial*)malloc(sizeof(eEditorial));
		if(auxEditorial != NULL)
		{
			eEditorial_setId(auxEditorial, atoi(id));
			eEditorial_setNombre(auxEditorial, nombre);
		}
	}
	return auxEditorial;
}

int eEditorial_setId(eEditorial* this, int id)
{
	int retorno = 0;
	if(this != NULL && id > 0)
	{
		retorno = 1;
		this->id = id;
	}
	return retorno;
}
int eEditorial_getId(eEditorial* this, int* id)
{
	int retorno = 0;
	if(this != NULL && id != NULL)
	{
		retorno = 1;
		*id = this->id;
	}
	return retorno;
}

int eEditorial_setNombre(eEditorial* this, char* nombre)
{
	int retorno = 0;
	if(this != NULL && nombre != NULL)
	{
		retorno = 1;
		strcpy(this->nombre, nombre);
	}
	return retorno;
}
int eEditorial_getNombre(eEditorial* this, char* nombre)
{
	int retorno = 0;
	if(this != NULL && nombre != NULL)
	{
		retorno = 1;
		strcpy(nombre, this->nombre);
	}
	return retorno;
}
