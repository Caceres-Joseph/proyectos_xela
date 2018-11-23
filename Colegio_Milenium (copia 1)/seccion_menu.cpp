 

#include "seccion_menu.h"

#include "carreras.h"

/**
 * Variables
 */
int sm_indice_carrera=-1;
 
/**
 * Menu de opciones para la seccion
 */
void sm_menu(int indice){
    sm_indice_carrera=indice;
    
    //limpiando la pantalla
    cout << string( 100, '\n' );


    //Para guardar la opcion que seleccionó
    int opcionSeleccionada=0;



    cout << "+----------------------+"<<endl;
    cout << "| Secciones            |"<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Carrera: "<<c_getCarrera(sm_indice_carrera).nombre<<endl<<endl;

    cout << "0. Salir."<<endl;
    cout << "1. Mostrar secciones."<<endl;
    cout << "2. Crear una nueva seccion."<<endl;
    cout << "3. Modificar una seccion."<<endl;
    cout << "4. Eliminar una seccion."<<endl<<endl<<endl<<endl<<endl<<endl;
    cin >> opcionSeleccionada;


    
    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        sm_menu(indice);
        return;
    }

    
    
    switch (opcionSeleccionada)
    {
    case 0:
        return;
    case 1:
        ss_menu_mostrar();
        break;
    case 2:
        ss_menu_crear(); 
        break;
    case 3:
        if(!ss_indice==0){
            ss_menu_modificar(); 
        }else{
            cout<<"No hay secciones"<<endl;
        }

        break;
    case 4:
        if(!ss_indice==0){
            ss_menu_eliminar(); 
        }else{
            cout<<"No hay secciones"<<endl;
        } 
        break;
    default:
        cout<<"Opcion incorrecta"<<endl;

        break;
    }

    cualquierTecla();
    sm_menu(indice);


}

void sm_menu_estudiante(int indice)
{
    sm_indice_carrera=indice;
    
    //limpiando la pantalla
    cout << string( 100, '\n' );


    //Para guardar la opcion que seleccionó
    int opcionSeleccionada=0;



    cout << "+----------------------+"<<endl;
    cout << "| Estudiante           | "<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Carrera: "<<c_getCarrera(sm_indice_carrera).nombre<<endl<<endl;
    cout << " Seleccione una opción por favor."<<endl<<endl;

    cout << "0. Salir."<<endl;
    cout << "1. Seleccionar una seccion"<<endl<<endl<<endl<<endl<<endl<<endl;

    cin >> opcionSeleccionada;

    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        sm_menu_estudiante(indice);
        return;
    }
 
    switch (opcionSeleccionada)
    {
    case 0:
        return;
    case 1:
        
        if(!ss_indice==0){
            ss_menu_estudiante(); 
        }else{
            cout<<"No hay secciones"<<endl;
        }  
        break;
    default:
        cout<<"Opcion incorrecta"<<endl;

        break;
    }
    
    cualquierTecla();
    sm_menu_estudiante(indice); 
}