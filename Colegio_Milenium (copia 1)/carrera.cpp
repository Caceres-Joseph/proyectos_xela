 
#include "carrera.h"

 /**
  * 
  * @param nombre
  * @param precio
  * @return Retorna una estructura de tipo carrera
  */
c_carrera *crearCarrera(int idCarrera , char *nombre, double precio, int estado){
     
    c_carrera *nuevaCarera=new c_carrera;
    strcpy(nuevaCarera->nombre, nombre);
    nuevaCarera->precio=precio;
    //estado activo
    nuevaCarera->estado=estado;
    nuevaCarera->idCarrera=idCarrera;
    //escribiendo
    
    return nuevaCarera;
}

 
 