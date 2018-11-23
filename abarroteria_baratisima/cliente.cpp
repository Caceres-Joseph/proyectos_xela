 

#include "cliente.h"

 
cliente *c_crear(
        char *nombre,
        char *apellido,  
        char *direccion,
        
        int edad,
        int codigo,
        int telefono,
        
        int numCompras, 
        int estado
        )
{
     
    cliente *nuevo=new cliente;
     
    strcpy(nuevo->nombre, nombre);//copia la cadena
    strcpy(nuevo->apellido, apellido); 
    strcpy(nuevo->direccion, direccion); 
    
    nuevo->edad=edad;
    nuevo->codigo=codigo;
    nuevo->telefono=telefono; 

    nuevo->numCompras=numCompras; 
    nuevo->estado=estado;
 
 }