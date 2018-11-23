 

#include "municipio.h"

 
/**
 * Retorna una estructura con los datos indicados
 * @param nombre
 * @param estado
 * @return 
 */
municipio *m_crear(char *nombre,int idDepartamento,int estado){
     
    municipio *nuevo=new municipio;
    
    strcpy(nuevo->nombre, nombre);
    nuevo->estado=estado;
    nuevo->idDepartamento=idDepartamento;
    
    return nuevo;
}