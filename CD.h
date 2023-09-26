//
// Created by smora on 25/09/2023.
//

#ifndef PROYECTOPROGRAPR_CD_H
#define PROYECTOPROGRAPR_CD_H

#include <string>
#include <iostream>
#include <list>
#include "Cancion.h"

using namespace std;

class CD {
public:
    string nombreCancion;
    int numeroCanciones;
    list<Cancion> nombresCanciones;

    CD(){}

};


#endif //PROYECTOPROGRAPR_CD_H
