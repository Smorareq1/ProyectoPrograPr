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
    string nombreCD;
    size_t numeroCanciones;
    list<Cancion> nombresCanciones;

    //Funciones
     void mostrarCanciones() const;

    CD(){

    }

    CD(string &nombreDelCD , size_t numeroDeCanciones, list<Cancion> nombresDeLasCanciones){
        this ->nombreCD = nombreDelCD;
        this ->numeroCanciones = numeroDeCanciones;
        this ->nombresCanciones = nombresDeLasCanciones;

    }

};


#endif //PROYECTOPROGRAPR_CD_H
