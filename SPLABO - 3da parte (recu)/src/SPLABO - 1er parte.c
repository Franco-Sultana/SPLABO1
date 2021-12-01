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
	int banderaLibro = 0;
	int banderaEditorial = 0;
	int opcion;
	char pathLibros[30];
	char pathEditorial[30];

	do
	{
		menuOpciones(&opcion, 0, 8);
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

			switch(Ctrl_cargarDatosArchivoLibro(pathLibros, sizeof(pathLibros), listaLibros, &banderaLibro))
			{
			case -2:
				printf("\n\t(X)No se acepta se archivo por pertenecer a los datos de editoriales.\n");
			break;
			case -1:
				printf("\n\t(!!)Ocurrio un error inesperado\n");
			break;
			case 0:
				printf("\n\t(!)Archivo no encontrado\n");
			break;
			case 1:
			printf("\n\tLos datos se cargaron correctamente\n");
			break;
			}
		break;
		case 2:
			system("cls");
			switch(Ctrl_cargarDatosArchivoEditoriales(pathEditorial, sizeof(pathEditorial), listaEditoriales, &banderaEditorial))
			{
			case -2:
				printf("\n\t(X)No se acepta se archivo por pertenecer a los datos de libros.\n");
			break;
			case -1:
				printf("\n\t(!!)Ocurrio un error inesperado\n");
			break;
			case 0:
				printf("\n\t(!)Archivo no encontrado\n");
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
				printf("\n\t(0)Ocurrio un problema al crear la lista\n");
			break;
			}
		break;
		case 6:
			system("cls");
			switch(Ctrl_Descuento(listaLibros, listaEditoriales))
			{
			case -2:
				printf("(!)\n\tOcurrio un error al abrir los archivos\n");
			break;
			case -1:
				printf("(!!)\n\tOcurrio un error inesperado\n");
			break;
			case 0:
				printf("\n\t(!)Asegurese de cargar los datos de ambos archivos (Libros.csv, Editoriales.csv)\n");
			break;
			case 1:
				printf("\n\tArchivo \"mapeado.csv\" creado con exito con estos datos\n");
			break;
			}
		break;
		case 7:
			system("cls");
			switch(Ctrl_librosQueCuestanMasDe500(listaLibros), 500)
			{
			case -1:
				printf("(!!)\n\tOcurrio un error inesperado\n");
			break;
			case 0:
				printf("\n\t(!)Asegurese de cargar los datos del archivo de libros (Libros.csv)\n");
			break;
			}
		break;
		case 8:
			system("cls");
			switch(Ctrl_sumarPrecios(listaLibros), 3)
			{
			case -1:
				printf("(!!)\n\tOcurrio un error inesperado\n");
			break;
			case 0:
				printf("\n\t(!)Asegurese de cargar los datos del archivo de libros (Libros.csv)\n");
			break;
			}
		break;
		}
	}while(opcion != -1);
	return EXIT_SUCCESS;
}
