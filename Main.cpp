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
        }
    }
};

MaterialBibliografico* buscarMaterial(std::string palabra, std::string criterio, MaterialBibliografico* biblioteca[100]) {
    if (criterio == "autor") {
        for (int i = 0; i < 100; i++) {
            if (biblioteca[i] != nullptr) {
                if (biblioteca[i]->getAutor() == palabra) {
                    return biblioteca[i];
                }
            }
        }
    }
    if (criterio == "titulo") {
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
    }
    if (tipo == "L") {
        std::string fechaPublicacion, resumen;
        cout << "Fecha de publicacion: \n>";
        cin >> fechaPublicacion;
        cout << "Resumen del libro: \n>";
        cin >> resumen;
        aux = new Libro(nombre, isbn, autor, fechaPublicacion, resumen);
    }
    insertarMaterial(biblioteca, aux);
};

void mostrarMateriales(MaterialBibliografico* biblioteca[100]) {
    for (int i = 0; i < 100; i++) {
        if (biblioteca[i] != nullptr) {
            biblioteca[i]->mostrarInformacion();
        }
    }
};

void prestarMaterial(MaterialBibliografico* biblioteca[100]) {

}

int main(){
    MaterialBibliografico* libreria[100];
    int numeroMaterial = 0;
    int opcion = -1;
    while (opcion != 0) {
        cout << "1. Agregar un libro\n2. Mostrar materiales\n3. Prestar material\n4. Devolver material\n6. Gestion de usuarios\n0. Cerrar el programa" << endl;
        cout << "Selecciona una opcion\n> ";
        cin >> opcion;
        switch (opcion) {
            case 0: cout << "Cerrando programa" << endl;
                break;
            case 1: agregarMaterial(libreria);
                break;
            case 2: mostrarMateriales(libreria);
                break;
            case 3: prestarMaterial(libreria);
                break;
            default: cout << "Opcion no reconocida" << endl;
                break;

        }
    }
    
    return 0;
};