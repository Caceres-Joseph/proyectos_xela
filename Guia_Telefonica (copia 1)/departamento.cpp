 

#include "departamento.h"

 
 /**
  * 
  * @param nombre
  * @param estado
  * @return Retorna una estructura de tipo depa
  */
departamento *d_crear(char *nombre, int estado){
     
    departamento *nuevo=new departamento;
    strcpy(nuevo->nombre, nombre); 
    //estado activo
    nuevo->estado=estado;

    return nuevo;
}

 