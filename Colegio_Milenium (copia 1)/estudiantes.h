 

#ifndef ESTUDIANTES_H
#define ESTUDIANTES_H

 

#include "estudiante.h"

//Para seccioens
void es_menu_crear();
void es_insertar(
        char *nombre,
        char *apellido,
        char *sexo,
        char *direccion,
        int edad,
        int codigo,
        int telefono,
        int aprobado,
        int idCarrera,
        int idSeccion,
        int estado
        );
void es_menu_mostrar();
void es_menu_modificar();
void es_menu_eliminar();

//funciones
void es_mlista();
void es_lstEncabezado();

//lectura y escritura del archivo
void es_leer(); 
void es_escribir(
        char *nombre,
        char *apellido,
        char *sexo,
        char *direccion,
        int edad,
        int codigo,
        int telefono,
        int aprobado,
        int idCarrera,
        int idSeccion,
        int estado
        );
void es_actualizar_archivo();

//arreglo  
extern estudiante *es_lista[500];

//indica cual es la ultima posicion libre del arreglo 
extern int es_indice;
 

//funcioen extras

void es_buscar();
void es_listaGeneral();
void es_listaGeneralAprobados();
void es_listaGeneralNoAprobados();
void es_cantidad();
void es_cuota();

extern string es_nombreArchivo;
#endif /* ESTUDIANTES_H */

