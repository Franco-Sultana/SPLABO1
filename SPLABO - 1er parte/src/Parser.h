/*
 * Parser.h
 *
 *  Created on: 24 nov. 2021
 *      Author: F2019
 */

#ifndef PARSER_H_
#define PARSER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "Libros.h"
#include "Editoriales.h"

/**
 * @fn int parser_librosDesdeTexto(FILE*, LinkedList*)
 * @brief parsea los datos de los libros desde archivos de texto
 * @param pFileLibros puntero a direccion de memoria donde apunta el puntero a file
 * @param this puntero a direccion de memoria donde apunta la linkedList de libros
 * @return 0 si no pudo parsear || 1 si pudo
 */
int parser_librosDesdeTexto(FILE* pFileLibros, LinkedList* this);

/**
 * @fn int parser_editorialesDesdeTexto(FILE*, LinkedList*)
 * @brief parsea los datos de los libros desde archivos de texto
 * @param pFileLibros puntero a direccion de memoria donde apunta el puntero a file
 * @param this puntero a direccion de memoria donde apunta la linkedList de libros
 * @return 0 si no pudo parsear || 1 si pudo
 */
int parser_editorialesDesdeTexto(FILE* pFileEditoriales, LinkedList* this);


#endif /* PARSER_H_ */
