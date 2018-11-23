 

#ifndef MUNICIPIO_H
#define MUNICIPIO_H

 

#include "personas_menu.h"


/**
 * Es la estructura que tiene un municipio
 */
struct municipio {
    //nombre de la carrera
    char nombre[255];
    int idDepartamento;
    //es cero si se elimina
    int estado;
};


/**
 * Metodos
 */
municipio *m_crear(char *nombre,int idDepartamento ,int estado);


#endif /* MUNICIPIO_H */

