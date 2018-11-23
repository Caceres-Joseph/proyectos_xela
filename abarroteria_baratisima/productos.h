 
#ifndef PRODUCTOS_H
#define PRODUCTOS_H

 #include "producto.h"

//Para depas
void ds_menu_crear();
void ds_menu_mostrar();
void ds_menu_modificar();
void ds_menu_eliminar();

//funciones
void ds_mlista();

//lectura y escritura del archivo
void ds_leer(); 
void ds_escribir(char *nombre,
        int codigo,
        double precio,
        int stock,
        int numVentas,
        int estado);

void ds_insertar(char *nombre,
        int codigo,
        double precio,
        int stock,
        int numVentas,
        int estado);

void ds_actualizar_archivo();

//arreglo de carreras 
extern producto *ds_lista[500];

//indica cual es la ultima posicion libre del arreglo 
extern int ds_indice;




//para las ventas

void ds_menu_venta(int idCliente);

//de donde pertenece
extern int ds_indice_cliente;


//otras opciones
void ds_productosMasVendidos();
void ds_productosExistentes();
void ds_buscar();

#endif /* PRODUCTOS_H */

