#include "Objetos/MaterialBibliografico.h"
#include "Objetos/Libro.h"
#include "Objetos/Revista.h"
#include "Objetos/Usuario.h"
#include <iostream>
#include <fstream>
using namespace std;

void insertarMaterial(MaterialBibliografico* biblioteca[100], MaterialBibliografico* material) {
    if (material == nullptr) {
        return;
    }
    for (int i = 0; i < 100; i++) {
        if (biblioteca[i] == nullptr) {
            biblioteca[i] = material;
            cout << "Material agregado correctamente" << endl;
            return;
        }
    }
    cout << "No queda espacio en la biblioteca" << endl;
};

MaterialBibliografico* buscarMaterial(std::string palabra, std::string criterio, MaterialBibliografico* biblioteca[100]) {
    if (criterio == "A") {
        for (int i = 0; i < 100; i++) {
            if (biblioteca[i] != nullptr) {
                if (biblioteca[i]->getAutor() == palabra) {
                    return biblioteca[i];
                }
            }
        }
    }
    if (criterio == "T") {
        for (int i = 0; i < 100; i++) {
            if (biblioteca[i] != nullptr) {
                if (biblioteca[i]->getNombre() == palabra) {
                    return biblioteca[i];
                }
            }
        }
    }
    return nullptr;
}

Usuario* buscarUsuario(std::string id, Usuario* usuarios[5]) {
    for (int i = 0; i < 5; i++) {
        if (usuarios[i] != nullptr) {
            if (usuarios[i]->getId() == id) {
                return usuarios[i];
            }
        }
    }
    return nullptr;
}

void agregarMaterial(MaterialBibliografico* biblioteca[100]) {
    MaterialBibliografico* aux = nullptr;
    std::string nombre, isbn, autor, tipo;
    cout << "Nombre: \n>";
    cin >> nombre;
    cout << "ISBN: \n>";
    cin >> isbn;
    cout << "Autor: \n>";
    cin >> autor;
    cout << "Revista (R) o Libro (L)?";
    cin >> tipo;
    if (tipo == "R") {
        std::string nPublicacion, mesPublicacion;
        cout << "Numero de publicacion: \n>";
        cin >> nPublicacion;
        cout << "Mes de publicacion: \n>";
        cin >> mesPublicacion;
        aux = new Revista(nombre, isbn, autor, nPublicacion, mesPublicacion);
    } else if (tipo == "L") {
        std::string fechaPublicacion, resumen;
        cout << "Fecha de publicacion: \n>";
        cin >> fechaPublicacion;
        cout << "Resumen del libro: \n>";
        cin >> resumen;
        aux = new Libro(nombre, isbn, autor, fechaPublicacion, resumen);
    } else {
        cout << "Criterio no reconocido" << endl;
    }
    insertarMaterial(biblioteca, aux);
    if (aux == nullptr) {
        cout << "No se pudo agregar el material" << endl;
    }
};

void mostrarMateriales(MaterialBibliografico* biblioteca[100]) {
    for (int i = 0; i < 100; i++) {
        if (biblioteca[i] != nullptr) {
            biblioteca[i]->mostrarInformacion();
        }
    }
};

void prestarMaterial(MaterialBibliografico* biblioteca[100], Usuario* usuarios[5]) {
    std::string id;
    cout << "Ingrese el ID del usuario: \n>";
    cin >> id;
    Usuario* user = buscarUsuario(id, usuarios);
    if (user != nullptr) {
        std::string criterio, palabra;
        cout << "Quiere buscar el material por Titulo (T) o por Autor (A)?";
        cin >> criterio;
        cout << "Ingrese la busqueda:";
        cin >> palabra;
        MaterialBibliografico* aux = buscarMaterial(palabra, criterio, biblioteca);
        if (aux != nullptr) {
            user -> prestarMaterial(aux);
        } else {
            cout << "Material no encontrado" << endl;
        }
    } else {
        cout << "Usuario no encontrado" << endl;
    }
}

void devolverMaterial(Usuario* usuarios[5]) {
    std::string id;
    cout << "Ingrese el ID del usuario: \n>";
    cin >> id;
    Usuario* user = buscarUsuario(id, usuarios);
    if (user != nullptr) {
        std::string criterio, palabra;
        cout << "Quiere buscar por nombre (N) o por ISBN (I):";
        cin >> criterio;
        cout << "Ingrese la busqueda";
        cin >> palabra;
        user -> devolverMaterial(palabra, criterio);
        return;
    }
    cout << "No se encontro el usuario" << endl;
}

int main() {
    MaterialBibliografico* libreria[100];
    Libro* papelucho = new Libro("Papelucho", "ASDASDS", "Marta","1-1-24", "pEPDSPDASDPSA");
    libreria[0] = papelucho;
    Usuario* usuarios[5];
    Usuario* cabroql = new Usuario("alo", "asd");
    usuarios[0] = cabroql;
    int opcion = -1;
    while (opcion != 0) {
        cout << "1. Agregar un libro\n2. Mostrar materiales\n3. Prestar material\n4. Devolver material\n5. Agregar usuario\n6. Eliminar usuario\n0. Cerrar el programa" << endl;
        cout << "Selecciona una opcion\n> ";
        cin >> opcion;
        switch (opcion) {
            case 0: cout << "Cerrando programa" << endl;
                break;
            case 1: agregarMaterial(libreria);
                break;
            case 2: mostrarMateriales(libreria);
                break;
            case 3: prestarMaterial(libreria, usuarios);
                break;
            case 4: devolverMaterial(usuarios);
                break;
            default: cout << "Opcion no reconocida" << endl;
                break;

        }
    }
    
    return 0;
};