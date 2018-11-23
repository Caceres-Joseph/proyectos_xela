 

#include "seccion.h"



/**
 * Retorna una estructura con los datos iddicados
 * @param nombre
 * @param estado
 * @return 
 */
seccion *s_crear(char *nombre,int idCarrera,int estado){
     
    seccion *nuevo=new seccion;
    
    strcpy(nuevo->nombre, nombre);
    nuevo->estado=estado;
    nuevo->idCarrera=idCarrera;
    
    return nuevo;
}