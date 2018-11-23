 
#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

 #include "municipios_menu.h"
 
/**
 * Es la estructura que tiene un depa
 */
struct departamento { 
    
    //nombre 
    char nombre[255]; 
    //es cero si se elimina
    int estado;
};


/**
 * Metodos
 */
departamento *d_crear(char *nombre, int estado);


#endif /* DEPARTAMENTO_H */

