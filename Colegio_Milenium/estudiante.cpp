 

#include "estudiante.h"

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
        )
 {
     
    estudiante *nuevo=new estudiante;
     
    strcpy(nuevo->nombre, nombre);//copia la cadena
    strcpy(nuevo->apellido, apellido);
    strcpy(nuevo->sexo, sexo);
    strcpy(nuevo->direccion, direccion);
    
    nuevo->edad=edad;
    nuevo->codigo=codigo;
    nuevo->telefono=telefono;
    nuevo->aprobado=aprobado;

    nuevo->idCarrera=idCarrera;
    nuevo->idSeccion=idSeccion;
    nuevo->estado=estado;
 
 }