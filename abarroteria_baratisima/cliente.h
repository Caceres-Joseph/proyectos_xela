 
#ifndef CLIENTE_H
#define CLIENTE_H
 
#include "func.h" 

/**
 * Es la estructura que tiene un cliente
 */
struct cliente {
    
    //datos del alumno
    char nombre[255];
    char apellido[255]; 
    char direccion[255];
    
    int edad;
    int codigo;
    int telefono;
 
    int numCompras; 
    
    //es cero si se elimina
    int estado;
};

/**
 * Metodos
 */
cliente *c_crear(
        char *nombre,
        char *apellido,  
        char *direccion,
        
        int edad,
        int codigo,
        int telefono,
        
        int numCompras, 
        int estado
        );
 
#endif /* CLIENTE_H */

