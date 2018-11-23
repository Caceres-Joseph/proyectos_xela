 
#ifndef DEPARTAMENTOS_H
#define DEPARTAMENTOS_H

#include "departamento.h"

//Para depas
void ds_menu_crear();
void ds_insertar(char *nombre,int estado);
void ds_menu_mostrar();
void ds_menu_modificar();
void ds_menu_eliminar();

//funciones
void ds_mlista();

//lectura y escritura del archivo
void ds_leer(); 
void ds_escribir(char *nombre, int estado);
void ds_insertar(char *nombre, int estado);

void ds_actualizar_archivo();

//arreglo de carreras 
extern departamento *ds_lista[500];

//indica cual es la ultima posicion libre del arreglo 
extern int ds_indice;



//Para la seccion y alumnos
void ds_menu_municipio();
void ds_menu_persona();


//obteniendo seccion
departamento ds_getItem(int indice);

extern string ds_nombreArchivo;

#endif /* DEPARTAMENTOS_H */

