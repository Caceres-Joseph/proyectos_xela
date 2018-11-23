 
#include "producto.h"
  /**
  * 
  * @param nombre
  * @param estado
  * @return Retorna una estructura de tipo 
  */
producto *d_crear(char *nombre,
        int codigo,
        double precio,
        int stock,
        int numVentas,
        int estado)
{
     
    producto *nuevo=new producto;
    strcpy(nuevo->nombre, nombre); 
    nuevo->codigo=codigo;
    nuevo->precio=precio;
    nuevo->stock=stock;
    nuevo->numVentas=numVentas;
    //estado activo
    nuevo->estado=estado;

    return nuevo;
}

 