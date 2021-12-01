/*
 * Controller.h
 *
 *  Created on: 24 nov. 2021
 *      Author: F2019
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "Parser.h"

/**
 * @fn void menuOpciones(int*, int, int)
 * @brief Muestra el menu de opciones al usuario
 * @param opcion puntero a donde apunta la opcion que ingresa el usuario
 * @param min opcion minima
 * @param max opcion maxima
 */
void menuOpciones(int* opcion, int min, int max);

/**
 * @fn int Ctrl_cargarDatosArchivoLibro(char*, LinkedList*)
 * @brief Carga los datos desde el archivo de libros
 * @param path direccion del archivo
 * @param pList puntero que apunta a la direccion de memoria del array de linkedlist de libros
 * @return -1 si alguno de los parametros vino erroneo || 0 si no se pudo abrir el archivo || 1 si pudo cargar
 */
int Ctrl_cargarDatosArchivoLibro(char* path, int longitudPath, LinkedList* pList, int* banderaCargado);

/**
 * @fn int Ctrl_cargarDatosArchivoEditoriales(char*, LinkedList*)
 * @brief Carga los datos desde el archivo de editoriales
 * @param path direccion del archivo
 * @param pList puntero que apunta a la direccion de memoria del array de linkedlist de editoriales
 * @return -1 si alguno de los parametros vino erroneo || 0 si no se pudo abrir el archivo || 1 si pudo cargar
 */
int Ctrl_cargarDatosArchivoEditoriales(char* path, int longitudPath, LinkedList* pList, int* banderaCargado);

/**
 * @fn int Ctrl_ordenarPorAutor(LinkedList*, LinkedList*)
 * @brief Ordena y muestra la lista de libros en base a autores de forma ascendente
 * @param pList puntero que apunta a la direccion de memoria del array de linkedlist de libros
 * @param pList2 puntero que apunta a la direccion de memoria del array de linkedlist de editoriales
 * @return -1 si alguno de los parametros vino erroneo || 0 si la lista esta vacia ||
 * 			-2 si al funcion ll_sort no pudo ordenar || 1 si se pudo ordenar
 */
int Ctrl_ordenarPorAutor(LinkedList* pList, LinkedList* pList2);

/**
 * @fn int Ctrl_ImprimirLibros(LinkedList*, LinkedList*)
 * @brief Imprime la lista de libros
 * @param pList puntero que apunta a la direccion de memoria del array de linkedlist de libros
 * @param pList2 puntero que apunta a la direccion de memoria del array de linkedlist de editoriales
 * @return -1 si alguno de los parametros vino erroneo || 0 si la lista esta vacia || 1 si pudo mostrar
 */
int Ctrl_ImprimirLibros(LinkedList* pList, LinkedList* pList2);

/**
 * @fn int Ctrl_FiltrarEditorialMinotauro(LinkedList*, LinkedList*)
 * @brief Filtra y crea una lista de los libros que tienen al editorial MINOTAURO
 * @param pList1 puntero que apunta a la direccion de memoria del array de linkedlist de libros
 * @param pList2 puntero que apunta a la direccion de memoria del array de linkedlist de editoriales
 * @return -1 si alguno de los parametros vino erroneo || 0 si la lista esta vacia ||
 * 			-2 si al funcion ll_filter no pudo filtrar || 1 si se pudo filtrar
 */
int Ctrl_FiltrarEditorialMinotauro(LinkedList* pList1, LinkedList* pList2);

/**
 * @fn int Ctrl_Descuento(LinkedList*, LinkedList*)
 * @brief calcula y crea el archivo mapeado donde van a ir todos los librso con descuento
 * @param pList1 puntero que apunta a la direccion de memoria del array de linkedlist de libros
 * @param pList2 puntero que apunta a la direccion de memoria del array de linkedlist de editoriales
 * @return -1 si alguno de los parametros vino en 0 || 0 si la lista esta vacia || 1 si pudo crear archivo
 */
int Ctrl_Descuento(LinkedList* pList1, LinkedList* pList2);

/**
 * @fn int Ctrl_librosQueCuestanMasDe500(LinkedList*)
 * @brief retorna si el libro analizado cuesta mas de $500
 * @param pList puntero que apunta a la direccion de memoria del array de linkedlist de libros
 * @return 1 si cuesta mas de $500 || 0 si no
 */
int Ctrl_librosQueCuestanMasDe500(LinkedList* pList);

/**
 * @fn int Ctrl_sumarPreciosPearson(LinkedList*)
 * @brief retorna el precio del libro
 * @param pList puntero que apunta a la direccion de memoria del array de linkedlist de libros
 * @return precio del libro si es editorial (...) || 0 si no
 */
int Ctrl_sumarPreciosPearson(LinkedList* pList);
#endif /* CONTROLLER_H_ */
