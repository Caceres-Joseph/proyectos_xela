 

#include "clientes_menu.h"
 
 

/**
 * Menu de opciones  
 */

void pm_menu()
{ 
    //limpiando la pantalla
    cout << string( 100, '\n' );


    //Para guardar la opcion que seleccionó
    int opcionSeleccionada=0;


    cout << "+----------------------+"<<endl;
    cout << "| Clientes             |"<<endl;
    cout << "+----------------------+"<<endl<<endl;
     
    cout << "0. Salir."<<endl;
    cout << "1. Mostrar clientes"<<endl;
    cout << "2. Crear un nuevo cliente."<<endl;
    cout << "3. Modificar una cliente."<<endl;
    cout << "4. Eliminar un cliente"<<endl<<endl;
    cout << "5. Lista de clientes potenciales"<<endl<<endl<<endl<<endl<<endl<<endl;
    
    
    cin >> opcionSeleccionada;
 
    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        pm_menu();
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
    case 5:
        if(!ps_indice==0){
            ps_clientesPotenciales(); 
        }else{
            cout<<"No hay personas"<<endl;
        }
        break;
    default:
        cout<<"Opcion incorrecta"<<endl;

        break;
    }

    cualquierTecla();
    pm_menu(); 
}



/**
 * Despliega un menu para las ventas
 */

void pm_menu_venta()
{
    
    //limpiando la pantalla
    cout << string( 100, '\n' );


    //Para guardar la opcion que seleccionó
    int opcionSeleccionada=0;
 
    cout << "+----------------------+"<<endl;
    cout << "| Venta                |"<<endl;
    cout << "+----------------------+"<<endl<<endl;

    cout << "0. Salir."<<endl;
    cout << "1. Seleccionar cliente"<<endl<<endl<<endl<<endl<<endl;
    
    cin >> opcionSeleccionada;

    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        pm_menu_venta();
        return;
    }
     
    switch (opcionSeleccionada)
    {
    case 0:
        return;
    case 1:
        if(!ps_indice==0){
             ps_menu_venta();
        }else{
            cout<<"No hay clientes"<<endl;
        }
        break;
    default:
        cout<<"Opcion incorrecta"<<endl; 
        break;
    }

    cualquierTecla();
    pm_menu_venta();

}
 
