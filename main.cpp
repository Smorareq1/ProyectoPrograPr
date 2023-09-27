#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <unordered_set>
#include <list>
#include <cstdlib>
#include "CD.h"

using namespace std;
void leerCancion(string linea) {

}
void leerArchivo(string& rutaArchivo) {

    list<CD> listaDeCD;

    for (auto& entrada : std::filesystem::directory_iterator(rutaArchivo)) {
        if (entrada.is_regular_file() && entrada.path().extension() == ".txt") {
            ifstream archivo(entrada.path());
            if (archivo) {
                //Almacena en una variable la ruta del archivo.
                string nombre = entrada.path().filename().string();
                //Busca donde se encuentra la extensión .txt del nombre del archivo y la almacena en una variable.
                int id = nombre.find(".txt");
                //Elimina el .txt del archivo
                nombre.erase(id, 4);
                cout << "Contenido de " << entrada.path().filename() << ":\n";
                string linea;
                unordered_set<string> canciones;
                list<Cancion> listaDeCanciones;
                while (getline(archivo, linea)) {
                    if (linea.empty()) { //PREGUNTAR termina programa
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
                            Cancion* cancion = new Cancion();
                            canciones.insert(linea);
                            //Busca donde aparece '||' por primera vez.
                            auto p1 = linea.find('||');
                            //Busca donde aparece '||' luego de p1 + 2 caracteres (p1 almacena el primer |).
                            auto p2 = linea.find('||', p1 + 2);
                            if (p1 != string::npos && p2 != string::npos) {
                                //'Recorta' el nombre de la canción desde 0 (inicio) hasta donde encuentra la primer llave (p1).
                                cancion->nombreCancion = linea.substr(0, p1);
                                //'Recorta' el nombre del artista desde p1+2 hasta p2-p1-2 y lo almacena.
                                cancion->nombreArtista = linea.substr(p1 + 2, p2 - p1 - 2);
                                cancion->duracion = linea.substr(p2 + 2);
                                cancion->CD = nombre;
                                listaDeCanciones.push_back(*cancion);
                            }
                        }
                    }
                }

                if (canciones.empty()) {
                    cout << "El archivo no contiene canciones." << endl;
                }
                auto cantidadCancionesUnicas = canciones.size();
                cout << "\nCantidad de canciones unicas encontradas: " << cantidadCancionesUnicas << endl;

                //Crea el objeto
                CD* cd = new CD(nombre, cantidadCancionesUnicas, listaDeCanciones);

                //Lo añade a la lista de CDs.
                listaDeCD.push_back(*cd);

                archivo.close(); //Pasar al siguiente achivo XDD
                cout << "\n";
            }
            else { //PREGUNTAR termina programa
                cout << "No se pudo abrir el archivo: " << entrada.path().filename() << endl;
            }
        }
    }
    //Para imprimir XDXDXDXDXD
    for (const CD& disco : listaDeCD) {
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
        break;
    default:
        break;
    }

}

int main() {
    menuInicio();

    return 0;
}