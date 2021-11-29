/*
 ============================================================================
 	 	 	 	 	    SEGUNDO PARCIAL LABORATORIO
					      Franco Sultana  Div "C"
 ============================================================================
 */


#include "Controller.h"

int main(void)
{
	setbuf(stdout, NULL);
	LinkedList* listaLibros = ll_newLinkedList();
	LinkedList* listaEditoriales = ll_newLinkedList();
	LinkedList* nueva;
	int banderaLibro = 0;
	int banderaEditorial = 0;
	int opcion;

	do
	{
		menuOpciones(&opcion, 0, 6);
		switch(opcion)
		{
		case 0:
			system("cls");
			if(utn_getRespuestaSiNo("Desea salir?"))
			{
				printf("\n\t\t\t Saliendo...");
				ll_deleteLinkedList(listaLibros);
				ll_deleteLinkedList(listaEditoriales);
				opcion = -1;
			}
			else
			{
				printf("\n\t(X)Se cancelo la salida.\n");
			}
		break;
		case 1:
			system("cls");
			switch(Ctrl_cargarDatosArchivoLibro("Libros.csv", listaLibros, &banderaLibro))
			{
			case -1:
				printf("\n\t(!!)Ocurrio un error inesperado\n");
			break;
			case 0:
				printf("\n\t(!)No se pudo abrir el archivo\n");
			break;
			case 1:
			printf("\n\tLos datos se cargaron correctamente\n");
			break;
			}
		break;
		case 2:
			system("cls");
			switch(Ctrl_cargarDatosArchivoEditoriales("Editoriales.csv", listaEditoriales, &banderaEditorial))
			{
			case -1:
				printf("\n\t(!!)Ocurrio un error inesperado\n");
			break;
			case 0:
				printf("\n\t(!)No se pudo abrir el archivo\n");
			break;
			case 1:
				printf("\n\tLos datos se cargaron correctamente\n");
			break;
			}
		break;
		case 3:
			system("cls");
			switch(Ctrl_ordenarPorAutor(listaLibros, listaEditoriales))
			{
			case -2:
				printf("\t\n(!)Ocurrio un error al ordenar\n");
			break;
			case -1:
				printf("\n\t(!!)Ocurrio un error inesperado\n");
			break;
			case 0:
				printf("\n\t(0)Asegurese de cargar los datos de ambos archivos (Libros.csv, Editoriales.csv)\n");
			break;
			}
		break;
		case 4:
			system("cls");
			switch(Ctrl_ImprimirLibros(listaLibros, listaEditoriales))
			{
			case -1:
				printf("\n\t(!!)Ocurrio un error inesperado\n");
			break;
			case 0:
				printf("\n\t(0)Asegurese de cargar los datos de ambos archivos (Libros.csv, Editoriales.csv)\n");
			break;
			}
		break;
		case 5:
			system("cls");
			switch(Ctrl_FiltrarEditorialMinotauro(listaLibros, listaEditoriales))
			{
			case -1:
				printf("\n\t(!!)Ocurrio un error inesperado\n");
			break;
			case 0:
				printf("\n\t(!)Asegurese de cargar los datos de ambos archivos (Libros.csv, Editoriales.csv)\n");
			break;
			case -2:
				printf("\n(0)Ocurrio un problema al crear la lista\n");
			break;
			}
		break;
		case 6:
			//NO LLEGUE :(
			ll_map(listaLibros, descuentoPlaneta);
			break;
		}
	}while(opcion != -1);
	return EXIT_SUCCESS;
}
