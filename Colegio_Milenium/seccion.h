 

#ifndef SECCION_H
#define SECCION_H

#include "estudiantes_menu.h"


/**
 * Es la estructura que tiene una seccion
 */
struct seccion {
    //nombre de la carrera
    char nombre[255];
    int idCarrera;
    //es cero si se elimina
    int estado;
};


/**
 * Metodos
 */
seccion *s_crear(char *nombre,int idCarrera ,int estado);



#endif /* SECCION_H */

