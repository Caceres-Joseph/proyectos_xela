/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   carrera.h
 * Author: joseph
 *
 * Created on 20 de noviembre de 2018, 06:47 PM
 */

#ifndef CARRERA_H
#define CARRERA_H

#include "seccion_menu.h"



/**
 * Es la estructura que tiene una carrera
 */
struct c_carrera {
    //idCarrera
    int idCarrera;
    //nombre de la carrera
    char nombre[255];
    //precio de la carrera
    double precio;
    //es cero si se elimina
    int estado;
};


/**
 * Metodos
 */
c_carrera *crearCarrera(int idCarrera, char *nombre, double precio, int estado);



#endif /* CARRERA_H */

