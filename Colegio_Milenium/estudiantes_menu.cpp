 

#include "estudiantes_menu.h"
 
#include "carreras.h"
#include "secciones.h"
/**
 * Variables
 */
int em_indice_carrera=-1;
int em_indice_seccion=-1;

/**
 * Menu de opciones para la seccion
 */

void em_menu(int idCarrera, int idSeccion)
{
    em_indice_carrera=idCarrera;
    em_indice_seccion=idSeccion;
    
    //limpiando la pantalla
    cout << string( 100, '\n' );


    //Para guardar la opcion que seleccionó
    int opcionSeleccionada=0;


    cout << "+----------------------+"<<endl;
    cout << "| Estudiantes          |"<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Carrera: "<<c_getCarrera(em_indice_carrera).nombre<<endl;
    cout << "| Seccion: "<<ss_getItem(em_indice_seccion).nombre<<endl<<endl;

    cout << "0. Salir."<<endl;
    cout << "1. Mostrar estudiantes de la sección: "<<ss_getItem(em_indice_seccion).nombre<<endl;
    cout << "2. Crear un nuevo estudiantes."<<endl;
    cout << "3. Modificar un estudiante."<<endl;
    cout << "4. Eliminar un estudiante"<<endl<<endl<<endl<<endl<<endl<<endl;
 
    cin >> opcionSeleccionada;
 
    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        em_menu(idCarrera,idSeccion);
        return;
    }

    
    
    switch (opcionSeleccionada)
    {
    case 0:
        return;
    case 1:
        es_menu_mostrar(); 
        break;
    case 2:
        es_menu_crear(); 
        break;
    case 3:
        if(!es_indice==0){
            es_menu_modificar(); 
        }else{
            cout<<"No hay estudiantes"<<endl;
        }

        break;
    case 4:
        if(!es_indice==0){
            es_menu_eliminar(); 
        }else{
            cout<<"No hay estudiantes"<<endl;
        }
        break;
    default:
        cout<<"Opcion incorrecta"<<endl;

        break;
    }

    cualquierTecla();
    em_menu(idCarrera,idSeccion);


}

 