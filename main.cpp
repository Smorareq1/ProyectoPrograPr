#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include "CD.h"
#include <unordered_set>

using namespace std;

namespace fs = std::filesystem;

void leerArchivo(string &rutaArchivo) {

    for (auto& entrada : fs::directory_iterator(rutaArchivo)) {
        if (entrada.is_regular_file() && entrada.path().extension() == ".txt") {
            ifstream archivo(entrada.path());
            if (archivo) {
                cout << "Contenido de " << entrada.path().filename() << ":\n";
                string linea;
                unordered_set<string> canciones; // Usaremos un conjunto para verificar canciones repetidas

                while (getline(archivo, linea)) {
                    if (linea.empty()) {
                        cout << "Línea vacía" << endl;
                    } else {
                        cout << linea << endl;

                        // Verificar si es una canción repetida
                        if (canciones.find(linea) != canciones.end()) {
                            cout << "Cancion repetida: " << linea << endl;
                        } else {
                            canciones.insert(linea);
                        }
                    }
                }

                if (canciones.empty()) {
                    cout << "El archivo no contiene canciones." << endl;
                }

                archivo.close();
                cout << "\n";
            } else {
                cerr << "No se pudo abrir el archivo: " << entrada.path().filename() << endl;
            }
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
