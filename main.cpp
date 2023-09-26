#include <iostream>
#include <fstream>
#include <string>
#include "CD.h"

using namespace std;

void ruta() {
    string rutaArchivo;
    cout << "Ingrese la ruta de la carpeta con los discos" << endl;
    fflush(stdin);
    getline(cin, rutaArchivo);
    cout << rutaArchivo << endl;
}
int main() {
    ruta();
    return 0;
}
