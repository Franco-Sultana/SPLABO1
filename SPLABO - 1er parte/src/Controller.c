/*
 * Controller.c
 *
 *  Created on: 24 nov. 2021
 *      Author: F2019
 */
#include "Controller.h"
void menuOpciones(int* opcion, int min, int max)
{
	printf("\n--------------------- MENU PRINCIPAL ---------------------\n"
		     " 0. Salir\n"
		     " 1. Cargar datos desde archivo de texto \"Libros.csv\"\n"
		     " 2. Cargar datos desde archivo de texto \"Editoriales.csv\"\n"
		     " 3. Ordenar lista por autor (A - Z)\n"
		     " 4. Imprimir datos de libros\n"
		     " 5. Fitrar libros de editorial MINOTAURO\n"
		     "----------------------------------------------------------\n");
	utn_getEntero(opcion, "Ingrese una opcion: ", "(!)Opcion invalida. ", min, max);
}

int Ctrl_cargarDatosArchivoLibro(char* path, LinkedList* pList, int* banderaCargado)
{
	int retorno = -1;
	FILE* pFileLibros;
	if(path != NULL && pList != NULL)
	{
		retorno = 0;
		if(*banderaCargado == 1)
		{
			if(utn_getRespuestaSiNo("La lista de libros ya fue cargada previamente, desea continuar?"))
			{
				*banderaCargado = 0;
				ll_clear(pList);
			}
		}
		if(*banderaCargado == 0)
		{
			pFileLibros = fopen(path, "r");
			if(pFileLibros != NULL)
			{
				if(parser_librosDesdeTexto(pFileLibros, pList) == 1)
				{
					retorno = 1;
					*banderaCargado = 1;
				}
				fclose(pFileLibros);
			}
		}
	}
	return retorno;
}

int Ctrl_cargarDatosArchivoEditoriales(char* path, LinkedList* pList, int* banderaCargado)
{
	int retorno = -1;
	FILE*  pFileEditoriales;
	if(path != NULL && pList != NULL)
	{
		retorno = 0;
		if(*banderaCargado == 1)
		{
			if(utn_getRespuestaSiNo("La lista de editoriales ya fue cargada previamente, desea continuar?"))
			{
				*banderaCargado = 0;
				ll_clear(pList);
			}
		}
		if(*banderaCargado == 0)
		{
			pFileEditoriales = fopen(path, "r");
			if(pFileEditoriales != NULL)
			{
				if(parser_editorialesDesdeTexto(pFileEditoriales, pList))
				{
					retorno = 1;
					*banderaCargado = 1;
				}
			}
			fclose(pFileEditoriales);
		}
	}
	return retorno;
}

int Ctrl_ordenarPorAutor(LinkedList* pList, LinkedList* pList2)
{
	int retorno = -1;
	LinkedList* listaOrdenada = ll_newLinkedList();
	if(pList != NULL)
	{
		retorno = 0;
		listaOrdenada = ll_clone(pList);
		if(!ll_isEmpty(pList) && !ll_isEmpty(pList2))
		{
			retorno = -2;
			printf("\n\t\t\t\t\t\t\t\t\t  LISTA ORDENADA:\n");
			if(ll_sort(listaOrdenada, eLibro_retornarCriterioOrdenamiento, 1) == 0)
			{
				retorno = 1;
				Ctrl_ImprimirLibros(listaOrdenada, pList2);
			}
		}
		ll_deleteLinkedList(listaOrdenada);
	}
	return retorno;
}

int Ctrl_ImprimirLibros(LinkedList* pList, LinkedList* pList2)
{
	int retorno = -1;
	eLibro* libro;
	eEditorial* editorial;
	int idEditorialFromLibro;
	int idEditorial;
	char nombreEditorial[20];
	if(pList != NULL)
	{
		retorno = 0;
		if(!ll_isEmpty(pList) && !ll_isEmpty(pList2))
		{
			eLibro_titulo();
			for(int i = 0; i<ll_len(pList); i++)
			{
				for(int j = 0; j<ll_len(pList2); j++)
				{
					libro = ll_get(pList, i);
					editorial = ll_get(pList2, j);
					eLibro_getIdEditorial(libro, &idEditorialFromLibro);
					eEditorial_getId(editorial, &idEditorial);
					if(idEditorial == idEditorialFromLibro)
					{
						retorno = 1;
						eEditorial_getNombre(editorial, nombreEditorial);
						eLibro_mostrarUnLibro(libro, nombreEditorial);
					}
				}
			}
		}
	}
	return retorno;
}

int Ctrl_FiltrarEditorialMinotauro(LinkedList* pList1, LinkedList* pList2)
{
	int retorno = -1;
	LinkedList* listaMinotauro;
	if(pList1 != NULL && pList2 != NULL)
	{
		retorno = 0;
		if(!ll_isEmpty(pList1) && !ll_isEmpty(pList2))
		{
			retorno = -2;
			printf("\n\t\t\t\t\t\t\t\t  FILTRO: EDITORIAL MINOTAURO\n");
			listaMinotauro = ll_filter(pList1, eLibro_filtrarEditorialMinotauro);
			if(listaMinotauro != NULL)
			{
				retorno = 1;
				Ctrl_ImprimirLibros(listaMinotauro, pList2);
				ll_deleteLinkedList(listaMinotauro);
			}

		}
	}
	return retorno;
}

