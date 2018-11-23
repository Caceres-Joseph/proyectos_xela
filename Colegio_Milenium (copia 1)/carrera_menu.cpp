/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   carrera_menu.cpp
 * Author: joseph
 * 
 * Created on 20 de noviembre de 2018, 07:10 PM
 */

#include "carrera_menu.h"

 
void c_menu()
{

    //limpiando la pantalla
    cout << string( 100, '\n' );


    //Para guardar la opcion que seleccionó
    int opcionSeleccionada=0;

    cout << "+----------------------+"<<endl;
    cout << "| Carreras             |"<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Seleccione una opción por favor."<<endl<<endl;

    cout << "0. Salir."<<endl;
    cout << "1. Mostrar las carreras."<<endl;
    cout << "2. Crear una nueva carrera."<<endl;
    cout << "3. Modificar una carrera."<<endl;
    cout << "4. Eliminar una carrera."<<endl<<endl<<endl<<endl<<endl<<endl;
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
        c_menu_mostrarCarreras();
        break;
    case 2:  
        c_menu_crearCarrera();
        break;
    case 3:
        c_menu_modificarCarrera(); 
        break;
    case 4:
        c_menu_eliminarCarrera();
        break;
    default:
        cout<<"Opcion incorrecta"<<endl; 
        break;
    }

    cualquierTecla();
    c_menu();
 }

/**
 * Despliega un menu para la seccion
 */

void cm_menu_seccion()
{
    
    //limpiando la pantalla
    cout << string( 100, '\n' );


    //Para guardar la opcion que seleccionó
    int opcionSeleccionada=0;
 
    cout << "+----------------------+"<<endl;
    cout << "| Secciones            |"<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Seleccione una opción por favor."<<endl<<endl;

    cout << "0. Salir."<<endl;
    cout << "1. Seleccionar una carrera"<<endl<<endl<<endl<<endl<<endl<<endl;

    cin >> opcionSeleccionada;

    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        cm_menu_seccion();
        return;
    }
     
    switch (opcionSeleccionada)
    {
    case 0:
        return;
    case 1:
         if(!c_listaCarreraIndice==0){
             c_menu_seccion();
        }else{
            cout<<"No hay carreras registradas"<<endl;
        }
        break;
    default:
        cout<<"Opcion incorrecta"<<endl; 
        break;
    }

    cualquierTecla();
    cm_menu_seccion();

}

/**
 * Menu para estudiantes
 */
void cm_menu_estudiante()
{
    
    //limpiando la pantalla
    cout << string( 100, '\n' );


    //Para guardar la opcion que seleccionó
    int opcionSeleccionada=0;
 
    cout << "+----------------------+"<<endl;
    cout << "| Estudiante           | "<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Seleccione una opción por favor."<<endl<<endl;

    cout << "0. Salir."<<endl;
    cout << "1. Seleccionar una carrera"<<endl<<endl; 
    cout << "-----------------------------"<<endl;
    cout << "2. Buscar estudiante por codigo"<<endl;
    cout << "3. Lista general de estudiantes por carreras"<<endl;
    cout << "4. Lista general de estudiantes aprobados por carrera y seccion"<<endl;
    cout << "5. Lista general de estudiantes reprobados por carrera y seccion"<<endl;
    cout << "6. Cantidad de estudiantes por cada sección en carrera"<<endl;
    cout << "7. Total general de ingresos mensuales por carrera y secciones"<<endl<<endl<<endl<<endl<<endl;

    cin >> opcionSeleccionada;


    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        cm_menu_estudiante();
        return;
    }

    switch (opcionSeleccionada)
    {
    case 0:
        return;
    case 1:
         
        if(!c_listaCarreraIndice==0){
            c_menu_estudiante(); 
        }else{
            cout<<"No hay carreras registradas"<<endl;
        }
        break;
    case 2:
        if(!es_indice==0){
            es_buscar();
        }else{
            cout<<"No hay estudiantes registrados"<<endl;
        }
        break;

    case 3:
        if(!es_indice==0){
            es_listaGeneral();
        }else{
            cout<<"No hay estudiantes registrados"<<endl;
        }
        break;
    case 4:
        if(!es_indice==0){
            es_listaGeneralAprobados(); 
        }else{
            cout<<"No hay estudiantes registrados"<<endl;
        }
        break;
    case 5:
        if(!es_indice==0){
            es_listaGeneralNoAprobados();
        }else{
            cout<<"No hay estudiantes registrados"<<endl;
        }
        break;
    case 6:
        if(!es_indice==0){
            es_cantidad();
        }else{
            cout<<"No hay estudiantes registrados"<<endl;
        }
        break;
    case 7:
        if(!es_indice==0){
            es_cuota();
        }else{
            cout<<"No hay estudiantes registrados"<<endl;
        }
        break;
    default:
        cout<<"Opcion incorrecta"<<endl; 
        break;
    }
    
    cualquierTecla();
    cm_menu_estudiante();
}

