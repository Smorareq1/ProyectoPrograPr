//
// Created by smora on 25/09/2023.
//

#ifndef PROYECTOPROGRAPR_CD_H
#define PROYECTOPROGRAPR_CD_H

#include <string>
#include<iostream>
#include <list>
#include "Cancion.h"

class CD {
public:
    string nombreDeCD;
    int cantCancion;
    list<Cancion> Canciones;

    CD(){

    } //Constructor vacio

};


#endif //PROYECTOPROGRAPR_CD_H
