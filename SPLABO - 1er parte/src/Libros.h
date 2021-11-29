/*
 * Libros.h
 *
 *  Created on: 24 nov. 2021
 *      Author: F2019
 */

#ifndef LIBROS_H_
#define LIBROS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int id;
	char titulo[70];
	char autor[30];
	int precio;
	int idEditorial;
}eLibro;

/**
 * @fn eLibro eLibro_newParametros*(char*, char*, char*, char*, char*)
 * @brief Contructor parametrizado de libros
 * @param id id que se va a asignar al libro creado
 * @param titulo titulo que se va a asignar al libro creado
 * @param autor autor que se va a asignar al libro creado
 * @param precio precio que se va a asignar al libro creado
 * @param idEditorial id de editorial que se va a asignar al libro creado
 * @return auxiliar de libro cargado con todos los datos
 */
eLibro* eLibro_newParametros(char* id, char* titulo, char* autor, char* precio, char* idEditorial);

/**
 * @fn int eLibro_setId(eLibro*, int)
 * @brief setea el id al libro
 * @param this puntero a direccion de memoria donde apunta el libro
 * @param id id que se va a setear
 * @return 0 si no pudo setear || 1 si pudo
 */
int eLibro_setId(eLibro* this, int id);
/**
 * @fn int eLibro_setId(eLibro*, int)
 * @brief obtiene el id del libro
 * @param this puntero a direccion de memoria donde apunta el libro
 * @param id puntero a direccion de memoria donde apunta el id que se quiere obtener
 * @return 0 si no pudo obtener || 1 si pudo
 */
int eLibro_getId(eLibro* this, int* id);

/**
 * @fn int eLibro_setTitulo(eLibro*, char*)
 * @brief setea el titulo al libro
 * @param this puntero a direccion de memoria donde apunta el libro
 * @param titulo puntero a direccion de memoria donde apunta el titulo que se quiere setear
 * @return 0 si no pudo setear || 1 si pudo
 */
int eLibro_setTitulo(eLibro* this, char* titulo);
/**
 * @fn int eLibro_getTitulo(eLibro*, char*)
 * @brief obtiene el titulo del libro
 * @param this puntero a direccion de memoria donde apunta el libro
 * @param titulo puntero a direccion de memoria donde apunta el titulo que se quiere obtener
 * @return 0 si no pudo obtener || 1 si pudo
 */
int eLibro_getTitulo(eLibro* this, char* titulo);

/**
 * @fn int eLibro_setAutor(eLibro*, char*)
 * @brief setea el autor del libro
 * @param this puntero a direccion de memoria donde apunta el libro
 * @param autor puntero a direccion de memoria donde apunta el autor que se quiere setear
 * @return 0 si no pudo setear || 1 si pudo
 */
int eLibro_setAutor(eLibro* this, char* autor);
/**
 * @fn int eLibro_getAutor(eLibro*, char*)
 * @brief obtiene el autor del libro
 * @param this puntero a direccion de memoria donde apunta el libro
 * @param autor puntero a direccion de memoria donde apunta el autor que se quiere obtener
 * @return 0 si no pudo obtener || 1 si pudo
 */
int eLibro_getAutor(eLibro* this, char* autor);

/**
 * @fn int eLibro_setPrecio(eLibro*, int)
 * @brief setea el precio al libro
 * @param this puntero a direccion de memoria donde apunta el libro
 * @param precio precio que se va a setear
 * @return 0 si no pudo setear || 1 si pudo
 */
int eLibro_setPrecio(eLibro* this, int precio);
/**
 * @fn int eLibro_getPrecio(eLibro*, int)
 * @brief obtiene el precio del libro
 * @param this puntero a direccion de memoria donde apunta el libro
 * @param precio puntero a direccion de memoria donde apunta el precio que se quiere obtener
 * @return 0 si no pudo obtener || 1 si pudo
 */
int eLibro_getPrecio(eLibro* this, int* precio);

/**
 * @fn int eLibro_setIdEditorial(eLibro*, int)
 * @brief setea el idEditorial al libro
 * @param this puntero a direccion de memoria donde apunta el libro
 * @param idEditorial idEditorial que se va a setear
 * @return 0 si no pudo obtener || 1 si pudo
 */
int eLibro_setIdEditorial(eLibro* this, int idEditorial);
/**
 * @fn int eLibro_getIdEditorial(eLibro*, int*)
 * @brief obtiene el idEditorial del libro
 * @param this puntero a direccion de memoria donde apunta el libro
 * @param idEditorial puntero a direccion de memoria donde apunta el idEditorial que se quiere obtener
 * @return 0 si no pudo obtener || 1 si pudo
 */
int eLibro_getIdEditorial(eLibro* this, int* idEditorial);

/**
 * @fn void eLibro_titulo()
 * @brief titulo/cabecera para mostrar libros
 */
void eLibro_titulo();

/**
 * @fn int eLibro_mostrarUnLibro(eLibro*, char*)
 * @brief muestra un libro con todos sus datos
 * @param this puntero a direccion de memoria donde apunta el libro
 * @param nombreEditorial nombre del editorial para no mostrar su id
 * @return 0 si no pudo mostrar || 1 si pudo
 */
int eLibro_mostrarUnLibro(eLibro* this, char* nombreEditorial);

/**
 * @fn int eLibro_retornarCriterioOrdenamiento(void*, void*)
 * @brief retorna si el elemnto es mayor, menor o igual al siguiente elemnto. Se pasa como parametro a ll_sort
 * @param param1 parametro 1 que se va a castear a eLibro*
 * @param param2 parametro 2 que se va a castear a eLibro*
 * @return retorna si el elemnto es mayor, menor o igual al siguiente elemnto
 */
int eLibro_retornarCriterioOrdenamiento(void* param1, void* param2);

/**
 * @fn int eLibro_filtrarEditorialMinotauro(void*)
 * @brief dice si un libro es de la editorial MINOTAURO o no
 * @param element elemento void que se casteará a libro
 * @return 0 si el libro no es de editorial MINOTAURO || 1 si lo es
 */
int eLibro_filtrarEditorialMinotauro(void* element);

int descuentoPlaneta(void* pElement);
#endif /* LIBROS_H_ */
