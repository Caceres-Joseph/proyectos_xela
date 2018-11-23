 
#include "personas_menu.h"

 
#include "departamentos.h"
#include "municipios.h"

/**
 * Variables
 */
int pm_indice_departamento=-1;
int pm_indice_municipio=-1;

/**
 * Menu de opciones  
 */

void pm_menu(int idDepartamento, int idMunicipio)
{
    pm_indice_departamento=idDepartamento;
    pm_indice_municipio=idMunicipio;
    
    //limpiando la pantalla
    cout << string( 100, '\n' );


    //Para guardar la opcion que seleccionó
    int opcionSeleccionada=0;


    cout << "+----------------------+"<<endl;
    cout << "| Personas             |"<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Departamento: "<<ds_getItem(pm_indice_departamento).nombre<<endl;
    cout << "| Municipio: "<<ms_getItem(pm_indice_municipio).nombre<<endl<<endl;

    cout << "0. Salir."<<endl;
    cout << "1. Mostrar personas"<<endl;
    cout << "2. Crear una nueva persona."<<endl;
    cout << "3. Modificar una persona."<<endl;
    cout << "4. Eliminar una persona"<<endl<<endl<<endl<<endl<<endl<<endl;

    cin >> opcionSeleccionada;
 
    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        pm_menu(idDepartamento,idMunicipio);
        return;
    }

    
    
    switch (opcionSeleccionada)
    {
    case 0:
        return;
    case 1:
        ps_menu_mostrar();
        break;
    case 2:
        ps_menu_crear(); 
        break;
    case 3:
        if(!ps_indice==0){
            ps_menu_modificar(); 
        }else{
            cout<<"No hay personas"<<endl;
        }

        break;
    case 4:
        if(!ps_indice==0){
            ps_menu_eliminar(); 
        }else{
            cout<<"No hay personas"<<endl;
        }
        break;
    default:
        cout<<"Opcion incorrecta"<<endl;

        break;
    }

    cualquierTecla();
    pm_menu(idDepartamento,idMunicipio);


}

 