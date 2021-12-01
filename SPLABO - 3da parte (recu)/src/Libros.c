/*
 * Libros.c
 *
 *  Created on: 24 nov. 2021
 *      Author: F2019
 */

#include "Libros.h"

eLibro* eLibro_newParametros(char* id, char* titulo, char* autor, char* precio, char* idEditorial)
{
	eLibro* auxLibro = NULL;
	if(id != NULL && titulo != NULL && autor != NULL && precio != NULL && idEditorial != NULL)
	{
		auxLibro = (eLibro*)malloc(sizeof(eLibro));
		if(auxLibro != NULL)
		{
			eLibro_setId(auxLibro, atoi(id));
			eLibro_setTitulo(auxLibro, titulo);
			eLibro_setAutor(auxLibro, autor);
			eLibro_setPrecio(auxLibro, atoi(precio));
			eLibro_setIdEditorial(auxLibro, atoi(idEditorial));
		}
	}
	return auxLibro;
}


int eLibro_setId(eLibro* this, int id)
{
	int retorno = 0;
	if(this != NULL && id > 0)
	{
		retorno = 1;
		this->id = id;
	}
	return retorno;
}
int eLibro_getId(eLibro* this, int* id)
{
	int retorno = 0;
	if(this != NULL && id != NULL)
	{
		retorno = 1;
		*id = this->id;
	}
	return retorno;
}

int eLibro_setTitulo(eLibro* this, char* titulo)
{
	int retorno = 0;
	if(this != NULL && titulo != NULL)
	{
		retorno = 1;
		strcpy(this->titulo, titulo);
	}
	return retorno;
}
int eLibro_getTitulo(eLibro* this, char* titulo)
{
	int retorno = 0;
	if(this != NULL && titulo != NULL)
	{
		retorno = 1;
		strcpy(titulo, this->titulo);
	}
	return retorno;
}

int eLibro_setAutor(eLibro* this, char* autor)
{
	int retorno = 0;
	if(this != NULL && autor != NULL)
	{
		retorno = 1;
		strcpy(this->autor, autor);
	}
	return retorno;
}
int eLibro_getAutor(eLibro* this, char* autor)
{
	int retorno = 0;
	if(this != NULL && autor != NULL)
	{
		retorno = 1;
		strcpy(autor, this->autor);
	}
	return retorno;
}

int eLibro_setPrecio(eLibro* this, int precio)
{
	int retorno = 0;
	if(this != NULL && precio > 0 && precio < 15000)
	{
		retorno = 1;
		this->precio = precio;
	}
	return retorno;
}
int eLibro_getPrecio(eLibro* this, int* precio)
{
	int retorno = 0;
	if(this != NULL && precio != NULL)
	{
		retorno = 1;
		*precio = this->precio;
	}
	return retorno;
}

int eLibro_setIdEditorial(eLibro* this, int idEditorial)
{
	int retorno = 0;
	if(this != NULL && idEditorial > 0 && idEditorial < 7)
	{
		retorno = 1;
		this->idEditorial = idEditorial;
	}
	return retorno;
}
int eLibro_getIdEditorial(eLibro* this, int* idEditorial)
{
	int retorno = 0;
	if(this != NULL && idEditorial != NULL)
	{
		retorno = 1;
		*idEditorial = this->idEditorial;
	}
	return retorno;
}

void eLibro_titulo()
{
	printf("\n| %-5s | %-70s | %-30s | %-10s | %-25s\n--------------------------------"
			"---------------------------------------------------------------------"
			"---------------------------------------\n", "ID", "TITULO", "AUTOR", "PRECIO", "EDITORIAL");
}

int eLibro_mostrarUnLibro(eLibro* this, char* nombreEditorial)
{
	int retorno = 0;
	int id;
	char titulo[80];
	char autor[30];
	int precio;
	if(this != NULL)
	{
		retorno = 1;
		eLibro_getId(this, &id);
		eLibro_getTitulo(this, titulo);
		eLibro_getAutor(this, autor);
		eLibro_getPrecio(this, &precio);
		printf("| %-5d | %-70s | %-30s | $%-9d | %-25s\n", id, titulo, autor, precio, nombreEditorial);
	}
	return retorno;
}

int eLibro_retornarCriterioOrdenamiento(void* param1, void* param2)
{
	int retorno = 0;
	char autor1[30];
	char autor2[30];
	eLibro* libro1 = (eLibro*)param1;
	eLibro* libro2 = (eLibro*)param2;
	eLibro_getAutor(libro1, autor1);
	eLibro_getAutor(libro2, autor2);
	if(libro1 != NULL && libro2 != NULL)
	{
		retorno = strcmp(autor1, autor2);
	}
	return retorno;
}

int eLibro_filtrarEditorialMinotauro(void* element)
{
	int retorno = 0;
	int idEditorial;
	eLibro* libro = (eLibro*)element;
	if(libro != NULL)
	{
		eLibro_getIdEditorial(libro, &idEditorial);
		if(idEditorial == 4)
		{
			retorno = 1;
		}
	}
	return retorno;
}


int descuentoPlaneta(void* pElement)
{
	int retorno = 0;
	eLibro* libro = (eLibro*)pElement;

	int idEditorial;
	int precio;
	int precioDescuento;
	if(libro != NULL)
	{
		eLibro_getIdEditorial(libro, &idEditorial);
		eLibro_getPrecio(libro, &precio);
		if(precio > 299 && idEditorial == 1)
		{
			precioDescuento = precio - (precio * 0.20);

			eLibro_setPrecio(libro, precioDescuento);
			retorno = 1;
		}
		if(precio < 201 && idEditorial == 2)
		{
			precioDescuento = precio - (precio * 0.10);
			eLibro_setPrecio(libro, precioDescuento);
			retorno = 1;
		}
	}
	return retorno;
}

int eLibro_retornarLibroMas500(void* pElement, int entero)
{
	int retorno = 0;
	eLibro* libro = (eLibro*)pElement;
	int precio;
	if(libro != NULL)
	{
		eLibro_getPrecio(libro, &precio);
		if(precio > entero)
		{
			retorno = 1;
		}
	}
	return retorno;
}

int eLibro_retornarPrecio(void* pElement, int entero)
{
	int retorno = 0;
	eLibro* libro = (eLibro*)pElement;
	int precio;
	int idEditorial;
	if(libro != NULL)
	{
		eLibro_getIdEditorial(libro, &idEditorial);
		if(idEditorial == entero)
		{
			eLibro_getPrecio(libro, &precio);
			retorno = precio;
		}
	}
	return retorno;
}
