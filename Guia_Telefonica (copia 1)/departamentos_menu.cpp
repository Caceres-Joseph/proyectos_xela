 

#include "departamentos_menu.h"

 
void dm_menu()
{

    //limpiando la pantalla
    cout << string( 100, '\n' );


    //Para guardar la opcion que seleccionó
    int opcionSeleccionada=0;


    cout << "+----------------------+"<<endl;
    cout << "| Departamentos        |"<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Seleccione una opción por favor."<<endl<<endl;

    cout << "0. Salir."<<endl;
    cout << "1. Mostrar departamentos."<<endl;
    cout << "2. Crear un nuevo departamento."<<endl;
    cout << "3. Modificar un departamento."<<endl;
    cout << "4. Eliminar un departamento."<<endl<<endl<<endl<<endl<<endl<<endl;
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
            cout<<"No hay departamentos registradas"<<endl;
        } 
        break;
    case 4:
        
         if(!ds_indice==0){
             ds_menu_eliminar();
        }else{
            cout<<"No hay departamentos registradas"<<endl;
        } 
        break;
    default:
        cout<<"Opcion incorrecta"<<endl; 
        break;
    }

    cualquierTecla();
    dm_menu();
 }

/**
 * Despliega un menu 
 */

void dm_menu_municipio()
{
    
    //limpiando la pantalla
    cout << string( 100, '\n' );


    //Para guardar la opcion que seleccionó
    int opcionSeleccionada=0;
 
    cout << "+----------------------+"<<endl;
    cout << "| Municipios           |"<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Seleccione una opción por favor."<<endl<<endl;

    cout << "0. Salir."<<endl;
    cout << "1. Seleccionar un departamento"<<endl<<endl<<endl<<endl<<endl<<endl;

    cin >> opcionSeleccionada;

    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        dm_menu_municipio();
        return;
    }
     
    switch (opcionSeleccionada)
    {
    case 0:
        return;
    case 1:
         if(!ds_indice==0){
             ds_menu_municipio();
        }else{
            cout<<"No hay carreras registradas"<<endl;
        }
        break;
    default:
        cout<<"Opcion incorrecta"<<endl; 
        break;
    }

    cualquierTecla();
    dm_menu_municipio();

}

/**
 * Menu para estudiantes
 */
void dm_menu_persona()
{
    
    //limpiando la pantalla
    cout << string( 100, '\n' );


    //Para guardar la opcion que seleccionó
    int opcionSeleccionada=0;
 
    cout << "+----------------------+"<<endl;
    cout << "| Persona              | "<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Seleccione una opción por favor."<<endl<<endl;

    cout << "0. Salir."<<endl;
    cout << "1. Seleccionar un departamento"<<endl;
    cout << "2. Lista general de personas"<<endl;
    cout << "3. Buscar persona por codigo"<<endl<<endl<<endl<<endl<<endl<<endl;
    
    cin >> opcionSeleccionada;


    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        dm_menu_persona();
        return;
    }

    switch (opcionSeleccionada)
    {
    case 0:
        return;
    case 1:
         
        if(!ds_indice==0){
            ds_menu_persona(); 
        }else{
            cout<<"No hay carreras registradas"<<endl;
        }
        break; 
    case 2:
        
        if(!ds_indice==0){
            ps_listaGeneral(); 
        }else{
            cout<<"No hay carreras registradas"<<endl;
        }
        break;
    case 3: 
        if(!ds_indice==0){
            ps_buscar(); 
        }else{
            cout<<"No hay carreras registradas"<<endl;
        }
        break;
    default:
        cout<<"Opcion incorrecta"<<endl; 
        break;
    }
    
    cualquierTecla();
    dm_menu_persona();
}

