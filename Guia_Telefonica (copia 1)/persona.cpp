 

#include "persona.h"
 
 persona *p_crear(
        char *nombre,
        char *apellido,  
        int edad,
        int codigo,
        int telefono,
        
        int idDepartamento,
        int idMunicipio,
        int estado
        )
 {
     
    persona *nuevo=new persona;
     
    strcpy(nuevo->nombre, nombre);//copia la cadena
    strcpy(nuevo->apellido, apellido); 
    
    nuevo->edad=edad;
    nuevo->codigo=codigo;
    nuevo->telefono=telefono; 

    nuevo->idDepartamento=idDepartamento;
    nuevo->idMunicipio=idMunicipio;
    nuevo->estado=estado;
 
 }