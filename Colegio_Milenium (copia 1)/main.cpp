 
   
#include "carrera_menu.h"
#include "seccion_menu.h"  
#include "estudiantes_menu.h"

void cargandoArchivos(){
    c_leer();
    ss_leer();
    es_leer();
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
    cout << "* COLEGIO << MILENUM >>        *"<<endl;
    cout << "********************************"<<endl;


    cout << "+----------------------+"<<endl;
    cout << "| MENU PRINCIPAL       |"<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Seleccione una opción por favor."<<endl<<endl;

    cout << "0. Salir."<<endl;
    cout << "1. Carreras."<<endl;
    cout << "2. Secciones"<<endl;
    cout << "3. Estudiantes"<<endl<<endl<<endl<<endl<<endl<<endl;


    cin >> opcionSeleccionada;


    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        c_menu();
        return;
    }

    switch (opcionSeleccionada)
    {
    case 0:
        return;
    case 1:
        //despliega el menu de las carreras
        c_menu();
        break;
    case 2:
        cm_menu_seccion();
        break;
    case 3:
        
        cm_menu_estudiante();
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

