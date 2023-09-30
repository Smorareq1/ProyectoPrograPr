//
// Created by smora on 25/09/2023.
//

#include "CD.h"


 void CD::mostrarCanciones() const{
     int i = 1;
    for (const Cancion &cancion: nombresCanciones) {
        cout << i << ") " << cancion.nombreCancion << " || " << cancion.nombreArtista << " || " << cancion.duracion << endl;
        i++;
    }
}
