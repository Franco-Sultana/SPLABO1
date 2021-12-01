/*
 * Parcer.c
 *
 *  Created on: 24 nov. 2021
 *      Author: F2019
 */
#include "Parser.h"

int parser_librosDesdeTexto(FILE* pFileLibros, LinkedList* this)
{
	int retorno = 0;
	eLibro* libro;
	char id[5];
	char titulo[70];
	char autor[30];
	char precio [6];
	char idEditorial[5];
	if(pFileLibros != NULL && this != NULL)
	{
		if(pFileLibros != NULL)
		{
			fscanf(pFileLibros, "%[^;];%[^;];%[^;];%[^;];%[^\n]\n", id, titulo, autor, precio, idEditorial);
			while(!feof(pFileLibros))
			{
				fscanf(pFileLibros, "%[^;];%[^;];%[^;];%[^;];%[^\n]\n", id, titulo, autor,
																		precio, idEditorial);
				libro = eLibro_newParametros(id, titulo, autor, precio, idEditorial);
				if(libro != NULL)
				{
					retorno = 1;
					ll_add(this, libro);
				}
			}
		}
	}
	return retorno;
}

int parser_editorialesDesdeTexto(FILE* pFileEditoriales, LinkedList* this)
{
	int retorno = 0;
	eEditorial* editorial;
	char id[5];
	char nombreEditorial[30];
	if(pFileEditoriales != NULL && this != NULL)
	{
		fscanf(pFileEditoriales, "%[^;];%[^\n]\n", id, nombreEditorial);
		while(!feof(pFileEditoriales))
		{
			fscanf(pFileEditoriales, "%[^;];%[^\n]\n", id, nombreEditorial);
			editorial = eEditorial_newParametros(id, nombreEditorial);
			if(editorial != NULL)
			{
				retorno = 1;
				ll_add(this, editorial);
			}
		}
	}
	return retorno;
}
