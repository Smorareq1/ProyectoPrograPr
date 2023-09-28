#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <unordered_set>
#include <list>

#include "CD.h"

using namespace std;


void menuInicio();
void leerCancion(string linea) {

}
void limpiarArchivos() {

}
void salirDelPrograma(){
        exit(0);
}

void leerArchivo(string& rutaArchivo) {
    list<CD>* listaDeCD = new list<CD>;
    unordered_set<string> nombresArchivosProcesados; // Para llevar un registro de los nombres de archivo ya procesados

    for (auto& entrada : std::filesystem::directory_iterator(rutaArchivo)) {
        if (entrada.is_regular_file() && entrada.path().extension() == ".txt") {
            ifstream archivo(entrada.path());
            if (archivo) {
                string nombre = entrada.path().filename().string();
                int id = nombre.find(".txt");
                nombre.erase(id, 4);

                // Verificar si ya hemos mostrado el nombre del archivo
                if (nombresArchivosProcesados.find(nombre) == nombresArchivosProcesados.end()) {
                    nombresArchivosProcesados.insert(nombre);
                    /*cout << "Contenido de " << entrada.path().filename() << ":\n";*/
                }

                string linea;
                unordered_set<string> canciones;
                list<Cancion> listaDeCanciones;
                while (getline(archivo, linea)) {
                    if (linea.empty()) {
                        cout << "Linea vacia encontrada, el formato de texto no es valido (CD corrupto)" << endl;
                        return;
                    }
                    else {
                        /*cout << linea << endl;*/
                        if (canciones.find(linea) != canciones.end()) {
                            cout << "Cancion repetida en " << nombre << ": " << linea << endl;
                        }
                        else {
                            Cancion cancion;
                            canciones.insert(linea);
                            auto p1 = linea.find("||");
                            auto p2 = linea.find("||", p1 + 2);
                            if (p1 != string::npos && p2 != string::npos) {
                                cancion.nombreCancion = linea.substr(0, p1);
                                cancion.nombreArtista = linea.substr(p1 + 2, p2 - p1 - 2);
                                cancion.duracion = linea.substr(p2 + 2);
                                cancion.CD = nombre;
                                listaDeCanciones.push_back(cancion);
                            }
                        }
                    }
                }

                if (canciones.empty()) {
                    cout << "El archivo no contiene canciones." << endl;
                }

                auto cantidadCancionesUnicas = canciones.size();
                cout << "\nCantidad de canciones unicas encontradas: " << cantidadCancionesUnicas << endl;

                CD cd(nombre, cantidadCancionesUnicas, listaDeCanciones);
                listaDeCD->push_back(cd);

                archivo.close();
                cout << "\n";
            }
            else {
                cout << "No se pudo abrir el archivo: " << entrada.path().filename() << endl;
            }
        }
    }

    //Para imprimir
    for (const CD& disco : *listaDeCD) {
        cout << "Nombre del CD: " << disco.nombreCD << endl;
        cout << "Cantidad de canciones: " << disco.numeroCanciones << endl;
        cout << "Canciones: " << endl;
        for (const Cancion& cancion : disco.nombresCanciones) {
            cout << "Nombre de la cancion: " << cancion.nombreCancion << endl;
            cout << "Nombre del artista: " << cancion.nombreArtista << endl;
            cout << "Duracion: " << cancion.duracion << endl;
            cout << "Disco que la contiene: " << cancion.CD << endl;
        }
    }
    menuInicio();
}
void ruta() {

    //Pedir directorio princial
    string rutaArchivo;
    cout << "Ingrese la ruta de la carpeta con los discos" << endl;
    cin.ignore();
    getline(cin, rutaArchivo);

    //Funciones
    leerArchivo(rutaArchivo);

}

void menuInicio() {
    int opcion = 0;
    cout << "Opciones: " << endl;
    cout << "1) Importar Carpeta" << endl;
    cout << "2) Reproductor de musica" << endl;
    cout << "3) Borrar CDs" << endl;
    cout << "4) Salir" << endl;

    cout << "Ingrese la opcion que desea consultar: ";
    cin >> opcion;

    switch (opcion) {
    case 1:
        ruta();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        salirDelPrograma();
        break;
    default:
        menuInicio();
        break;
    }

}
int main() {
    list<CD>* listaDeCD = nullptr;
    menuInicio(); //Ya
    delete listaDeCD;
    return 0;
}