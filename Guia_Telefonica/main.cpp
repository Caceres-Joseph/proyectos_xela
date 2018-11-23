
   
#include "departamentos_menu.h"
#include "municipios_menu.h"  
//#include "personas_menu.h"

void cargandoArchivos(){
    ds_leer();
    ms_leer();
//    ps_leer();
    
}


/**
 * Muestra el menú principal
 */
void menu_principal()
{

    //limpiando la pantalla
    cout << string( 100, '\n' );


    //Para guardar la opcion que seleccionó
    int opcionSeleccionada=0;



    cout << "********************************"<<endl;
    cout << "* GUIA TELEFONICA              *"<<endl;
    cout << "********************************"<<endl;


    cout << "+----------------------+"<<endl;
    cout << "| MENU PRINCIPAL       |"<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Seleccione una opción por favor."<<endl<<endl;

    
    cout << "0. Salir."<<endl;
    cout << "1. Departamentos."<<endl;
    cout << "2. Municipios"<<endl;
    cout << "3. Personas"<<endl<<endl<<endl<<endl<<endl<<endl;

    cin >> opcionSeleccionada;


    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        menu_principal();
        return;
    }

    switch (opcionSeleccionada)
    {
    case 0:
        return;
    case 1:
        
        dm_menu();
        break;
    case 2:
        dm_menu_municipio();
        break;
    case 3:
//        dm_menu_persona(); 
        break;
    default:
        cout<<"Opcion incorrecta"<<endl;
        break;
    }
 
    cualquierTecla();
    menu_principal();
 }

 
int main(int argc, char** argv) {

    //cargando los archivos
    cargandoArchivos();
    menu_principal(); 
    return 0;
}

