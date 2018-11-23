 
#include "productos_menu.h"

 
void dm_menu()
{

    //limpiando la pantalla
    cout << string( 100, '\n' );


    //Para guardar la opcion que seleccionó
    int opcionSeleccionada=0;


    cout << "+----------------------+"<<endl;
    cout << "| Productos            |"<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Seleccione una opción por favor."<<endl<<endl;

    cout << "0. Salir."<<endl;
    cout << "1. Lista general de productos."<<endl;
    cout << "2. Crear un nuevo producto."<<endl;
    cout << "3. Modificar un producto."<<endl;
    cout << "4. Eliminar un producto."<<endl<<endl;
    
     
    cout << "5. Listado de productos más vendidos"<<endl;
    cout << "6. Listado de productos existentes"<<endl;
    cout << "7. Buscar producto por codigo"<<endl<<endl<<endl<<endl<<endl<<endl;
    
    
    cin >> opcionSeleccionada;


    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        dm_menu();
        return;
    }

    switch (opcionSeleccionada)
    {
    case 0:
        return;
    case 1:
        ds_menu_mostrar(); 
        break;
    case 2:  
        ds_menu_crear(); 
        break;
    case 3:
        
         if(!ds_indice==0){
             ds_menu_modificar();
        }else{
            cout<<"No hay productos registradas"<<endl;
        } 
        break;
    case 4:
        
         if(!ds_indice==0){
             ds_menu_eliminar();
        }else{
            cout<<"No hay productos registradas"<<endl;
        } 
        break;
    case 5:
        
         if(!ds_indice==0){
             ds_productosMasVendidos();
        }else{
            cout<<"No hay productos registradas"<<endl;
        } 
        break;
    case 6:
        
         if(!ds_indice==0){
             ds_productosExistentes();
        }else{
            cout<<"No hay productos registradas"<<endl;
        } 
        break;
    case 7:
        
         if(!ds_indice==0){
             ds_buscar();
        }else{
            cout<<"No hay productos registradas"<<endl;
        } 
        break;
    default:
        cout<<"Opcion incorrecta"<<endl; 
        break;
    }

    cualquierTecla();
    dm_menu();
 }
