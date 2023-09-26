#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include "CD.h"
#include <unordered_set>

using namespace std;


void leerArchivo(string &rutaArchivo) {

    for (auto& entrada : std::filesystem::directory_iterator(rutaArchivo)) {
        if (entrada.is_regular_file() && entrada.path().extension() == ".txt") {
            ifstream archivo(entrada.path());
            if (archivo) {
                cout << "Contenido de " << entrada.path().filename() << ":\n";
                string linea;
                unordered_set<string> canciones;

                while (getline(archivo, linea)) {

                    if (linea.empty()) { //////////////////////////////////////////////////////////////////////////////
                        cout << "Linea vacia encontrada, el formato de texto no es valido (CD corrupto)" << endl;
                        return;
                    }

                    else {
                        cout << linea << endl;

                        // Verificar si es una canción repetida
                        if (canciones.find(linea) != canciones.end()) {
                            cout << "Cancion repetida: " << linea << endl;
                        }
                        else {
                            canciones.insert(linea);
                        }
                    }
                }

                if (canciones.empty()) {
                    cout << "El archivo no contiene canciones." << endl;
                }

                auto cantidadCancionesUnicas = canciones.size();
                cout << "\nCantidad de canciones unicas encontradas: " << cantidadCancionesUnicas << endl;

                archivo.close(); //Pasar al siguiente achivo XDD
                cout << "\n";
            }
            else { //PREGUNTAR termina programa
                cout << "No se pudo abrir el archivo: " << entrada.path().filename() << endl;
            }
        }
    }

}
void ruta() {

    //Pedir directorio princial
    string rutaArchivo;
    cout << "Ingrese la ruta de la carpeta con los discos" << endl;
    fflush(stdin);
    getline(cin, rutaArchivo);

    //Funciones
    leerArchivo(rutaArchivo);

}
int main() {
    //Pedir datos
    ruta();


    return 0;
}
