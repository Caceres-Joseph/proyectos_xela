 

#ifndef PERSONAS_H
#define PERSONAS_H

#include "persona.h"

void ps_menu_crear();
void ps_insertar(
        char *nombre,
        char *apellido,  
        int edad,
        int codigo,
        int telefono,
        
        int idDepartamento,
        int idMunicipio,
        int estado
        );
void ps_menu_mostrar();
void ps_menu_modificar();
void ps_menu_eliminar();

//funciones
void ps_mlista();
void ps_lstEncabezado();

//lectura y escritura del archivo
void ps_leer(); 
void ps_escribir(
        char *nombre,
        char *apellido,  
        int edad,
        int codigo,
        int telefono,
        
        int idDepartamento,
        int idMunicipio,
        int estado
        );
void ps_actualizar_archivo();

//arreglo  
extern persona *ps_lista[500];

//indica cual es la ultima posicion libre del arreglo 
extern int ps_indice;
 

//funcioen extras
void ps_buscar();
void ps_listaGeneral(); 
void ps_listaGeneralDepartamento(int idDepartamento);
 
extern string ps_nombreArchivo;

#endif /* PERSONAS_H */

