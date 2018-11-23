/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   carreras.h
 * Author: joseph
 *
 * Created on 20 de noviembre de 2018, 07:06 PM
 */

#ifndef CARRERAS_H
#define CARRERAS_H

#include "carrera.h"


//Para carreras
void c_menu_crearCarrera();
void c_insertar(char *nombre, double precio, int estado);
void c_menu_mostrarCarreras();
void c_menu_modificarCarrera();
void c_menu_eliminarCarrera();

//funciones
void c_mlistaCarreras();

//lectura y escritura del archivo
void c_leer(); 
void c_escribir(char *nombre, double precio, int estado);
void c_actualizar_archivo();

//arreglo de carreras 
extern c_carrera *c_listaCarreras[500];

//indica cual es la ultima posicion libre del arreglo 
extern int c_listaCarreraIndice;



//Para la seccion y alumnos
void c_menu_seccion();
void c_menu_estudiante();


//obteniendo la carrera 
c_carrera c_getCarrera(int indice);

#endif /* CARRERAS_H */

