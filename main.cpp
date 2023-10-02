#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <unordered_set>
#include <list>
#include <queue>
#include <cstring>
#include <algorithm>

#include "CD.h"

using namespace std;
list<CD>* listaDeCD = new list<CD>;
queue<Cancion>* listaReproduccion = new queue<Cancion>;
queue<Cancion>* listaTemporal = new queue<Cancion>;

//Declrarar funciones futuras
void menuInicio();

//////////////////////////////////////////////////////////////////////////////////////////////////////
void agregarCancion() {
    int i = 1;
    for (auto it = listaDeCD->begin(); it != listaDeCD->end(); ++it) {
        cout << i << ") " << it->nombreCD << endl;
        ++i;
    }

    int opcionCD;
    cout << "Ingrese el numero correspondiente al CD que desea seleccionar: " << endl;
    cin >> opcionCD;

    if (opcionCD >= 1 && opcionCD <= listaDeCD->size()) {
        auto it = listaDeCD->begin();
        advance(it, opcionCD - 1);

        const CD& CDElegido = *it;
        cout << "Ingrese el numero correspondiente a la cancion que desea seleccionar: " << endl;
        int opcionCancion = 0;
        CDElegido.mostrarCanciones();
        cin >> opcionCancion;

        if (opcionCancion >= 1 && opcionCancion <= CDElegido.numeroCanciones) {
            auto it2 = (CDElegido.nombresCanciones).begin();
            advance(it2, opcionCancion - 1);

            const Cancion& CancionElegida = *it2;
            listaReproduccion->push(CancionElegida);
        }
        else {
            cout << "Opcion invalida. Por favor, seleccione un numero valido." << endl; //PENDIENTE
        }
    } else {
        cout << "Opcion invalida. Por favor, seleccione un numero valido." << endl;
    }

}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void ordenarNombreCancionAscendente(bool perma) { //NUEVO //Ascendente //Modificar cola orignal?
    queue<Cancion>* listaTemporal = listaReproduccion;
    vector<Cancion> vectorOrdenar;
    while (!listaTemporal->empty()) {
        vectorOrdenar.push_back(listaTemporal->front());
        listaTemporal->pop();
    }

    sort(vectorOrdenar.begin(), vectorOrdenar.end(), [](const Cancion& a, const Cancion& b) {
        string primerosDosCaracteresA = a.nombreCancion.substr(0, 4);
        string primerosDosCaracteresB = b.nombreCancion.substr(0, 4);
        return primerosDosCaracteresA < primerosDosCaracteresB;
        });

    // Copiar elementos ordenados de vuelta a la cola
    for (const auto& cancion : vectorOrdenar) {
        listaTemporal->push(cancion);
    }
    if (perma) {
        listaReproduccion = listaTemporal;
        while (!listaReproduccion->empty()) {
            cout << (listaReproduccion->front()).nombreCancion << " || " << (listaReproduccion->front()).nombreArtista << " || " << (listaReproduccion->front()).duracion << endl;
            listaReproduccion->pop();
        }
        return;
    }
    while (!listaTemporal->empty()) {
        cout << (listaTemporal->front()).nombreCancion << " || " << (listaTemporal->front()).nombreArtista << " || " << (listaTemporal->front()).duracion << endl;
        listaTemporal->pop();
    }
}
void ordenarNombreCancionDescendente(bool perma) {
    queue<Cancion>* listaTemporal = listaReproduccion;
    vector<Cancion> vectorOrdenar;
    while (!listaTemporal->empty()) {
        vectorOrdenar.push_back(listaTemporal->front());
        listaTemporal->pop();
    }

    sort(vectorOrdenar.begin(), vectorOrdenar.end(), [](const Cancion& a, const Cancion& b) {
        string primerosDosCaracteresA = a.nombreCancion.substr(0, 4);
        string primerosDosCaracteresB = b.nombreCancion.substr(0, 4);
        return primerosDosCaracteresA > primerosDosCaracteresB;
        });

    for (const auto& cancion : vectorOrdenar) {
        listaTemporal->push(cancion);
    }
    if (perma) {
        listaReproduccion = listaTemporal;
        while (!listaReproduccion->empty()) {
            cout << (listaReproduccion->front()).nombreCancion << " || " << (listaReproduccion->front()).nombreArtista << " || " << (listaReproduccion->front()).duracion << endl;
            listaReproduccion->pop();
        }
        return;
    }
    while (!listaTemporal->empty()) {
        cout << (listaTemporal->front()).nombreCancion << " || " << (listaTemporal->front()).nombreArtista << " || " << (listaTemporal->front()).duracion << endl;
        listaTemporal->pop();
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void ordenarNombreArtistaAscendente(bool perma) { //NUEVO //ASCENENTE
    queue<Cancion>* listaTemporal = listaReproduccion;
    vector<Cancion> vectorOrdenar;
    while (!listaTemporal->empty()) {
        vectorOrdenar.push_back(listaTemporal->front());
        listaTemporal->pop();
    }
    sort(vectorOrdenar.begin(), vectorOrdenar.end(), [](const Cancion& a, const Cancion& b) {
        string primerosDosCaracteresA = a.nombreArtista.substr(0, 4);
        string primerosDosCaracteresB = b.nombreArtista.substr(0, 4);
        return primerosDosCaracteresA < primerosDosCaracteresB;
        });

    for (const auto& cancion : vectorOrdenar) {
        listaTemporal->push(cancion);
    }
    if (perma) {
        listaReproduccion = listaTemporal;
        while (!listaReproduccion->empty()) {
            cout << (listaReproduccion->front()).nombreCancion << " || " << (listaReproduccion->front()).nombreArtista << " || " << (listaReproduccion->front()).duracion << endl;
            listaReproduccion->pop();
        }
        return;
    }
    while (!listaTemporal->empty()) {
        cout << (listaTemporal->front()).nombreCancion << " || " << (listaTemporal->front()).nombreArtista << " || " << (listaTemporal->front()).duracion << endl;
        listaTemporal->pop();
    }
}
void ordenarNombreArtistaDescendente(bool perma) {
    queue<Cancion>* listaTemporal = listaReproduccion;
    vector<Cancion> vectorOrdenar;
    while (!listaTemporal->empty()) {
        vectorOrdenar.push_back(listaTemporal->front());
        listaTemporal->pop();
    }
    sort(vectorOrdenar.begin(), vectorOrdenar.end(), [](const Cancion& a, const Cancion& b) {
        string primerosDosCaracteresA = a.nombreArtista.substr(0, 4);
        string primerosDosCaracteresB = b.nombreArtista.substr(0, 4);
        return primerosDosCaracteresA > primerosDosCaracteresB;
        });
    for (const auto& cancion : vectorOrdenar) {
        listaTemporal->push(cancion);
    }
    if (perma) {
        listaReproduccion = listaTemporal;
        while (!listaReproduccion->empty()) {
            cout << (listaReproduccion->front()).nombreCancion << " || " << (listaReproduccion->front()).nombreArtista << " || " << (listaReproduccion->front()).duracion << endl;
            listaReproduccion->pop();
        }
        return;
    }
    while (!listaTemporal->empty()) {
        cout << (listaTemporal->front()).nombreCancion << " || " << (listaTemporal->front()).nombreArtista << " || " << (listaTemporal->front()).duracion << endl;
        listaTemporal->pop();
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
int convertirADuracionEnSegundos(const string& duracionCancion) {
    size_t pos = duracionCancion.find(":");
    int minutos = stoi(duracionCancion.substr(0, pos));
    int segundos = stoi(duracionCancion.substr(pos + 1));
    return minutos * 60 + segundos;
}
void ordenarPorDuracionAscendente(bool perma) {// NUEVO // ASCENDENTE
    queue<Cancion>* listaTemporal = listaReproduccion;
    vector<Cancion> vectorOrdenar;
    while (!listaTemporal->empty()) {
        vectorOrdenar.push_back(listaTemporal->front());
        listaTemporal->pop();
    }

    sort(vectorOrdenar.begin(), vectorOrdenar.end(), [](const Cancion& a, const Cancion& b) {
        return convertirADuracionEnSegundos(a.duracion) < convertirADuracionEnSegundos(b.duracion);
        });

    for (const auto& cancion : vectorOrdenar) {
        listaTemporal->push(cancion);
    }
    if (perma) {
        listaReproduccion = listaTemporal;
        while (!listaReproduccion->empty()) {
            cout << (listaReproduccion->front()).nombreCancion << " || " << (listaReproduccion->front()).nombreArtista << " || " << (listaReproduccion->front()).duracion << endl;
            listaReproduccion->pop();
        }
        return;
    }
    while (!listaTemporal->empty()) {
        cout << (listaTemporal->front()).nombreCancion << " || " << (listaTemporal->front()).nombreArtista << " || " << (listaTemporal->front()).duracion << endl;
        listaTemporal->pop();
    }
}
void ordenarPorDuracionDescendente(bool perma) {
    queue<Cancion>* listaTemporal = listaReproduccion;
    vector<Cancion> vectorOrdenar;
    while (!listaTemporal->empty()) {
        vectorOrdenar.push_back(listaTemporal->front());
        listaTemporal->pop();
    }
    sort(vectorOrdenar.begin(), vectorOrdenar.end(), [](const Cancion& a, const Cancion& b) {
        return convertirADuracionEnSegundos(a.duracion) > convertirADuracionEnSegundos(b.duracion);
        });
    for (const auto& cancion : vectorOrdenar) {
        listaTemporal->push(cancion);
    }
    if (perma == true) {
        listaReproduccion = listaTemporal;
        while (!listaReproduccion->empty()) {
            cout << (listaReproduccion->front()).nombreCancion << " || " << (listaReproduccion->front()).nombreArtista << " || " << (listaReproduccion->front()).duracion << endl;
            listaReproduccion->pop();
        }
        return;
    }
    while (!listaTemporal->empty()) {
        cout << (listaTemporal->front()).nombreCancion << " || " << (listaTemporal->front()).nombreArtista << " || " << (listaTemporal->front()).duracion << endl;
        listaTemporal->pop();
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void ordenarOriginal() {
    queue<Cancion>* listaTemporal = listaReproduccion;
    cout << "Canciones en la lista de reproduccion" << endl;
    while (!listaTemporal->empty()) {
        cout << (listaTemporal->front()).nombreCancion << " || " << (listaTemporal->front()).nombreArtista << " || " << (listaTemporal->front()).duracion << endl;
        listaTemporal->pop();
    }
}
void ordenar(int orden, bool acdc, bool perm) {

    switch (orden) {
    case 1:
        ordenarOriginal();
        break;
    case 2:
        if (acdc) {
            ordenarNombreArtistaAscendente(perm);
        }
        else {
            ordenarNombreArtistaDescendente(perm);
        }
        break;
    case 3:
        if (acdc) {
            ordenarNombreCancionAscendente(perm);
        }
        else {
            ordenarNombreCancionDescendente(perm);
        }
        break;
    case 4:
        if (acdc) {
            ordenarPorDuracionAscendente(perm);
        }
        else {
            ordenarPorDuracionDescendente(perm);
        }
        break;
    default:
        cout << "Opcion invalida. Por favor, elija una opcion valida (1-4)." << endl;
        break;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void verLista() {
    int opcion1 = 0;
    cout << "¿Como desea visualizar la lista de reproducción?" << endl;
    cout << "1) Agregado originalmente" << endl;
    cout << "2) Nombre del artista" << endl;
    cout << "3) Nombre de la cancion" << endl;
    cout << "4) Duracion de la cancion" << endl;
    cout << "Ingrese la opcion que desea consultar: ";
    cin >> opcion1;
    ordenar(opcion1, true, false);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void limpiarArchivos() {
    listaDeCD->clear();
    //Agregar el clear de las colas
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void salirDelPrograma(){
        exit(0);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void leerArchivo(string& rutaArchivo) {
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
                    //Preguntar si cuando encuentre la linea vacía, tira el disco
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
                            auto p1 = linea.find("||");
                            auto p2 = linea.find("||", p1 + 2);
                            if (p1 != string::npos && p2 != string::npos) {
                                //Verifica si existe un tercer par
                                auto p3 = linea.find("||", p2 + 2);
                                if (p3 != string::npos) {
                                    //Preguntar si el formato de duración de canción también debe ser comprobado
                                    cout << "Formato de linea incorrecto en: " << nombre << endl;
                                }
                                else {
                                    cancion.nombreCancion = linea.substr(0, p1);
                                    cancion.nombreArtista = linea.substr(p1 + 2, p2 - p1 - 2);
                                    cancion.duracion = linea.substr(p2 + 2);
                                    cancion.CD = nombre;
                                    listaDeCanciones.push_back(cancion);
                                    canciones.insert(linea);
                                }
                            }
                        }
                    }
                }

                if (canciones.empty()) {
                    cout << "El archivo " << nombre << " no contiene canciones." << endl;
                }
                else {
                    auto cantidadCancionesUnicas = canciones.size();
                    cout << "\nCantidad de canciones unicas encontradas en " << nombre << ": " << cantidadCancionesUnicas << endl;

                    CD cd(nombre, cantidadCancionesUnicas, listaDeCanciones);
                    listaDeCD->push_back(cd);

                    archivo.close();
                    cout << "\n";
                }
            }
            else {
                //Preguntar si se debe terminar el programa
                cout << "No se pudo abrir el archivo: " << entrada.path().filename() << endl;
            }
        }
    }

    //Para imprimir
    /*for (const CD& disco : *listaDeCD) {
        cout << "Nombre del CD: " << disco.nombreCD << endl;
        cout << "Cantidad de canciones: " << disco.numeroCanciones << endl;
        cout << "Canciones: " << endl;
        for (const Cancion& cancion : disco.nombresCanciones) {
            cout << "Nombre de la cancion: " << cancion.nombreCancion << endl;
            cout << "Nombre del artista: " << cancion.nombreArtista << endl;
            cout << "Duracion: " << cancion.duracion << endl;
            cout << "Disco que la contiene: " << cancion.CD << endl;
        }
    }*/
    menuInicio();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void ruta() {

    //Pedir directorio princial
    string rutaArchivo;
    cout << "Ingrese la ruta de la carpeta con los discos" << endl;
    cin.ignore();
    getline(cin, rutaArchivo);

    //Funciones
    leerArchivo(rutaArchivo);

}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void menuReproductorMusica(){
    int opcion = 0;
    char entrada[100];
        cout << "Opciones: " << endl;
        cout << "1) Agregar Cancion" << endl;
        cout << "2) Ver cola de reproduccion" << endl;
        cout << "3) Ordenar" << endl;
        cout << "4) Reproduccion actual" << endl;
        cout << "5) Reproducir siguiente" << endl;
        cout << "6) Volver al menu de inicio" << endl;

        cout << "Ingrese la opcion que desea consultar: ";
        cin >> entrada;


        if (strlen(entrada) > 1 || !isdigit(entrada[0])) {
            cout << "Entrada invalida. Por favor, ingrese un número." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        opcion = atoi(entrada);


        switch (opcion) {
            case 1:
                agregarCancion();
                menuReproductorMusica();
                break;
            case 2:
                verLista();
                menuReproductorMusica(); //NUEVO
                break;
            case 3:

                break;
            case 4:

                break;
            case 5:
                break;
            case 6:
                break;
            default:
                cout << "Opcion invalida. Por favor, elija una opcion valida (1-6)." << endl;
                break;
        }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void menuInicio() {
    int opcion = 0;
    char entrada[100];
        cout << "Opciones: " << endl;
        cout << "1) Importar Carpeta" << endl;
        cout << "2) Reproductor de musica" << endl;
        cout << "3) Borrar CDs" << endl;
        cout << "4) Salir" << endl;

        cout << "Ingrese la opcion que desea consultar: ";
        cin >> entrada;
        if (strlen(entrada) > 1 || !isdigit(entrada[0])) {
            cout << "Entrada invalida. Por favor, ingrese un numero valido." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            menuInicio();
        }
        else {
            // Verificar si la entrada es un número válido
            opcion = atoi(entrada);
            switch (opcion) {
            case 1:
                limpiarArchivos();
                ruta();
                break;
            case 2:
                menuReproductorMusica();
                break;
            case 3:
                //Pendiente?
                limpiarArchivos();
                cout << "CDs limpiados correctamente." << endl;
                menuInicio();
                break;
            case 4:
                salirDelPrograma();
                break;
            default:
                cout << "Opcion invalida. Por favor, elija una opcion valida (1-4)." << endl;
                break;
            }
        }  
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
    list<CD>* listaDeCD = nullptr;
    queue<Cancion>* listaReproduccion = nullptr;
    queue<Cancion>* listaTemporal = nullptr;
    menuInicio();

    delete listaDeCD;
    delete listaReproduccion;
    delete listaTemporal;


    return 0;
}
