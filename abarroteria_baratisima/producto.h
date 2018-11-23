 

#ifndef PRODUCTO_H
#define PRODUCTO_H

 
#include "func.h"
/**
 * Es la estructura que tiene un depa
 */
struct producto { 
    
    //nombre 
    char nombre[255]; 
    //codigo
    int codigo;
    //precio
    double precio;
    //stock
    int stock;
    //Ventas
    int numVentas;
     
    //es cero si se elimina
    int estado;
};


/**
 * Metodos
 */
producto *d_crear(char *nombre,
        int codigo,
        double precio,
        int stock,
        int numVentas,
        int estado);




#endif /* PRODUCTO_H */

