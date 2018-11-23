  
#ifndef MUNICIPIOS_H
#define MUNICIPIOS_H

#include "municipio.h"

//Para seccioens
void ms_menu_crear();
void ms_insertar(char *nombre, int idDepartamento, int estado);
void ms_menu_mostrar();
void ms_menu_modificar();
void ms_menu_eliminar();

//funciones
void ms_mlista();
municipio ms_getItem(int indice);


//lectura y escritura del archivo
void ms_leer(); 
void ms_escribir(char *nombre, int idDepartamento, int estado);
void ms_actualizar_archivo();

//arreglo de municipios 
extern municipio *ms_lista[500];

//indica cual es la ultima posicion libre del arreglo 
extern int ms_indice;

//de donde pertenece
extern int ms_indice_departamento;

extern string ms_nombreArchivo;



//para parsona
void ms_menu_persona();

 
 

#endif /* MUNICIPIOS_H */

