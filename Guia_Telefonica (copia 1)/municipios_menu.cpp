 
#include "municipios_menu.h"
 
#include "departamentos.h"

/**
 * Variables
 */
int mm_indice_departamento=-1;
 
/**
 * Menu de opciones 
 */
void mm_menu(int indice){
    mm_indice_departamento=indice;
    
    //limpiando la pantalla
    cout << string( 100, '\n' );


    //Para guardar la opcion que seleccionó
    int opcionSeleccionada=0;
 
    cout << "+----------------------+"<<endl;
    cout << "| Municipios           |"<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Departamento: "<<ds_getItem(mm_indice_departamento).nombre<<endl<<endl;

    
    cout << "0. Salir."<<endl;
    cout << "1. Mostrar municipios."<<endl;
    cout << "2. Crear un nuevo municipio."<<endl;
    cout << "3. Modificar un municipio."<<endl;
    cout << "4. Eliminar un municipio."<<endl<<endl<<endl<<endl<<endl<<endl;
    cin >> opcionSeleccionada;


    
    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        mm_menu(indice);
        return;
    }

    
    
    switch (opcionSeleccionada)
    {
    case 0:
        return;
    case 1:
        ms_menu_mostrar();
        break;
    case 2:
        ms_menu_crear(); 
        break;
    case 3:
        if(!ms_indice==0){
            ms_menu_modificar(); 
        }else{
            cout<<"No hay municipios"<<endl;
        }

        break;
    case 4:
        if(!ms_indice==0){
            ms_menu_eliminar(); 
        }else{
            cout<<"No hay municipios"<<endl;
        } 
        break;
    default:
        cout<<"Opcion incorrecta"<<endl; 
        break;
    }

    cualquierTecla();
    mm_menu(indice);


}

void mm_menu_persona(int indice)
{
    mm_indice_departamento=indice;
    
    //limpiando la pantalla
    cout << string( 100, '\n' );


    //Para guardar la opcion que seleccionó
    int opcionSeleccionada=0;



    cout << "+----------------------+"<<endl;
    cout << "| Persona              | "<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Departamento: "<<ds_getItem(mm_indice_departamento).nombre<<endl<<endl;
    cout << " Seleccione una opción por favor."<<endl<<endl;

    
    cout << "0. Salir."<<endl;
    cout << "1. Seleccionar un municipio"<<endl;
    cout << "2. Lista de personas de: "<<ds_getItem(mm_indice_departamento).nombre<<endl<<endl<<endl<<endl<<endl<<endl;

    
    
    cin >> opcionSeleccionada;

    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        mm_menu_persona(indice);
        return;
    }
 
    switch (opcionSeleccionada)
    {
    case 0:
        return;
    case 1:
        
        if(!ms_indice==0){
            ms_menu_persona(); 
        }else{
            cout<<"No hay secciones"<<endl;
        }  
        break;
        
    case 2:
        
        if(!ms_indice==0){
            ps_listaGeneralDepartamento(mm_indice_departamento);
        }else{
            cout<<"No hay secciones"<<endl;
        }  
        break;
    default:
        cout<<"Opcion incorrecta"<<endl;

        break;
    }
    
    cualquierTecla();
    mm_menu_persona(indice); 
}