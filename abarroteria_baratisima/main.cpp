   
#include "clientes_menu.h"
#include "productos_menu.h"

void cargandoArchivos(){ 
    ps_leer();
    ds_leer();
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



    cout << "**********************************"<<endl;
    cout << "* ABARROTERIA <<LA BARATISIMA>>  *"<<endl;
    cout << "**********************************"<<endl;


    cout << "+----------------------+"<<endl;
    cout << "| MENU PRINCIPAL       |"<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Seleccione una opción por favor."<<endl<<endl;

    cout << "0. Salir."<<endl;
    cout << "1. Productos."<<endl;
    cout << "2. Clientes"<<endl;
    cout << "3. Realizar Venta"<<endl<<endl<<endl<<endl<<endl<<endl;

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
        pm_menu();
        break;
    case 3:
        pm_menu_venta();
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

