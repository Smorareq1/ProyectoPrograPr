#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include "CD.h"

using namespace std;

void leerArchivo(string &rutaArchivo) {
    for (auto& p : filesystem::directory_iterator(rutaArchivo)) {
        if (p.is_regular_file() && p.path().extension() == ".txt") {
            ifstream archivo(p.path());
            if (archivo) {
                cout << "Contenido de " << p.path().filename() << ":\n";
                string linea;
                while (getline(archivo, linea)) {
                   if (linea == "") {
                        cout << "El archivo se encuentra vacío" << endl;
                   }
                   cout << linea << endl;
                }
            archivo.close();
            }
        }
        else if(p.path().extension() != ".txt") {
            cout << "El archivo " << p.path().filename() << " no tiene formato valido. " << endl;
        }
    }
}
void ruta() {
    string rutaArchivo;
    cout << "Ingrese la ruta de la carpeta con los discos" << endl;
    fflush(stdin);
    getline(cin, rutaArchivo);
    leerArchivo(rutaArchivo);
}
int main() {
    ruta();
    return 0;
}
