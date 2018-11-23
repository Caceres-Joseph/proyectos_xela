 
#ifndef PERSONA_H
#define PERSONA_H

 

#include "func.h" 


/**
 * Es la estructura que tiene una persona
 */
struct persona {
    
    //datos del alumno
    char nombre[255];
    char apellido[255]; 
    int edad;
    int codigo;
    int telefono;
 
         
    int idDepartamento;
    int idMunicipio;
    
    //es cero si se elimina
    int estado;
};

/**
 * Metodos
 */
persona *p_crear(
        char *nombre,
        char *apellido,  
        int edad,
        int codigo,
        int telefono,
        
        int idDepartamento,
        int idMunicipio,
        int estado
        );


#endif /* PERSONA_H */