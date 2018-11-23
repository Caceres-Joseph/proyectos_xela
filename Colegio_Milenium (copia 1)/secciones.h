 
#ifndef SECCIONES_H
#define SECCIONES_H


#include "seccion.h"

//Para seccioens
void ss_menu_crear();
void ss_insertar(char *nombre, int carrera, int estado);
void ss_menu_mostrar();
void ss_menu_modificar();
void ss_menu_eliminar();

//funciones
void ss_mlista();
seccion ss_getItem(int indice);


//lectura y escritura del archivo
void ss_leer(); 
void ss_escribir(char *nombre, int carrera, int estado);
void ss_actualizar_archivo();

//arreglo de carreras 
extern seccion *ss_lista[500];

//indica cual es la ultima posicion libre del arreglo 
extern int ss_indice;

//de donde pertenece
extern int ss_indice_carrera;

extern string ss_nombreArchivo;



//para el estudiante
void ss_menu_estudiante();


#endif /* SECCIONES_H */

