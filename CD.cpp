//
// Created by smora on 25/09/2023.
//

#include "CD.h"


 void CD::mostrarCanciones() const{
    for (const Cancion &cancion: nombresCanciones) {
        cout << cancion.nombreCancion << " || " << cancion.nombreArtista << " || " << cancion.duracion << endl;
    }
}

