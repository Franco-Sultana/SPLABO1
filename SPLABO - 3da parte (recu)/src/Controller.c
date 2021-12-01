/*
 * Controller.c
 *
 *  Created on: 24 nov. 2021
 *      Author: F2019
 */
#include "Controller.h"
void menuOpciones(int* opcion, int min, int max)
{
	printf("\n------------------------------ MENU PRINCIPAL -------------------------------\n"
		     " 0. Salir\n"
		     " 1. Cargar datos de libros desde archivo de texto\n"
		     " 2. Cargar datos de editoriales desde archivo de texto \n"
		     " 3. Ordenar lista por autor (A - Z)\n"
		     " 4. Imprimir datos de libros\n"
		     " 5. Fitrar libros de editorial MINOTAURO\n"
		     " 6. Generar archivo \"mapeado.csv\"\n"
		     " 7. Determinar cuántos libros cuestan mas de $500\n"
		     " 8. Determinar la sumatoria de precios de los libros de la editorial PEARSON\n"
		     "-----------------------------------------------------------------------------\n");
	utn_getEntero(opcion, "Ingrese una opcion: ", "(!)Opcion invalida. ", min, max);
}

int Ctrl_cargarDatosArchivoLibro(char* path, int longitudPath, LinkedList* pList, int* banderaCargado)
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
			retorno = -2;
			utn_getTexto(path, "Ingrese archivo del cual quiere cargar datos: ", "(!)Archivo invalido. ", longitudPath);
			if(strcmp(path, "Editoriales.csv") != 0)
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

	}
	return retorno;
}

int Ctrl_cargarDatosArchivoEditoriales(char* path, int longitudPath, LinkedList* pList, int* banderaCargado)
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
			retorno = -2;
			utn_getTexto(path, "Ingrese archivo del cual quiere cargar datos: ", "(!)Archivo invalido. ", longitudPath);
			if(strcmp(path, "Libros.csv") != 0)
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


int Ctrl_Descuento(LinkedList* pList1, LinkedList* pList2)
{
	int retorno = -1;
	LinkedList* listaAux;
	FILE* pFileDescuento;
	eLibro* libro;
	int id;
	char titulo[80];
	char autor[30];
	int precio;
	int idEditorial;

	char idStr[5];
	char precioStr[10];
	char idEditorialStr[5];

	if(pList1 != NULL && pList2 != NULL)
	{
		retorno = 0;
		if(!ll_isEmpty(pList1) && !ll_isEmpty(pList2))
		{
			pFileDescuento = fopen("mapeado.csv", "w");
			retorno = -2;
			if(pFileDescuento != NULL)
			{
				listaAux = ll_map(pList1, descuentoPlaneta);
				if(listaAux != NULL)
				{
					printf("\n\t\t\t\t\t\t\t\t  LIBROS CON DESCUENTO APLICADO:\n");
					Ctrl_ImprimirLibros(listaAux, pList2);
					fprintf(pFileDescuento, "id;titulo;autor;precio;idEditorial\n");
					for(int i = 0; i<ll_len(listaAux); i++)
					{
						libro = ll_get(listaAux, i);
						if(libro != NULL)
						{
							retorno = 1;
							eLibro_getId(libro, &id);
							eLibro_getTitulo(libro, titulo);
							eLibro_getAutor(libro, autor);
							eLibro_getPrecio(libro, &precio);
							eLibro_getIdEditorial(libro,& idEditorial);

							sprintf(idStr, "%d", id);
							sprintf(precioStr, "%d", precio);
							sprintf(idEditorialStr, "%d", idEditorial);

							fprintf(pFileDescuento, "%s;%s;%s;%s;%s\n",idStr, titulo, autor, precioStr, idEditorialStr);
						}
					}
				}
			}
			pclose(pFileDescuento);
		}

	}
	return retorno;
}

int Ctrl_librosQueCuestanMasDe500(LinkedList* pList)
{
	int retorno = -1;
	if(pList != NULL)
	{
		retorno = 0;
		if(!ll_isEmpty(pList))
		{
			if(ll_count(pList, 500, eLibro_retornarLibroMas500) != -1)
			{
				retorno = 1;
				printf("Los libros que cuestan mas de $500 son: %d", ll_count(pList, 500, eLibro_retornarLibroMas500));
			}
		}
	}
	return retorno;
}

int Ctrl_sumarPrecios(LinkedList* pList)
{
	int retorno = -1;
	if(pList != NULL)
	{
		retorno = 0;
		if(!ll_isEmpty(pList))
		{
			if(ll_count(pList, 3, eLibro_retornarPrecio) != -1)
			{
				retorno = 1;
				printf("La sumatoria de precios de editorial PEARSON es: $%d", ll_count(pList,3, eLibro_retornarPrecio));
			}
		}
	}
	return retorno;
}

