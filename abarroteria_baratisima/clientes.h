 
#ifndef CLIENTES_H
#define CLIENTES_H

#include "cliente.h"

void ps_menu_crear();
void ps_insertar(
        char *nombre,
        char *apellido,  
        char *direccion,
        
        int edad,
        int codigo,
        int telefono,
        
        int numCompras, 
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
        char *direccion,
        
        int edad,
        int codigo,
        int telefono,
        
        int numCompras, 
        int estado
        );
void ps_actualizar_archivo();

//arreglo  
extern cliente *ps_lista[500];

//indica cual es la ultima posicion libre del arreglo 
extern int ps_indice;
 

//funcioen extras
void ps_buscar();
void ps_listaGeneral(); 
void ps_listaGeneralDepartamento(int idDepartamento);
 
extern string ps_nombreArchivo;


void ps_menu_venta();


//obteniendo puntero

//obteniendo seccion
cliente *ps_getItem(int indice);



void ps_clientesPotenciales();


#endif /* CLIENTES_H */

