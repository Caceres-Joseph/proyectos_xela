 
#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "func.h" 


/**
 * Es la estructura que tiene un estudiante
 */
struct estudiante {
    
    //datos del alumno
    char nombre[255];
    char apellido[255];
    char sexo[255];
    char direccion[255];
    int edad;
    int codigo;
    int telefono;

    int aprobado=-1;
         
    int idCarrera;
    int idSeccion;
    
    //es cero si se elimina
    int estado;
};

/**
 * Metodos
 */
estudiante *e_crear(
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


#endif /* ESTUDIANTE_H */

