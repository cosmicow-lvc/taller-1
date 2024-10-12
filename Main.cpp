#include "Objetos/MaterialBibliografico.h"
#include "Objetos/Libro.h"
#include "Objetos/Revista.h"
#include "Objetos/Usuario.h"
#include <iostream>
#include <fstream>

void leerMateriales(MaterialBibliografico* materiales[100]) {
    std::fstream arch("materiales.txt");
    std::string linea;
    int cont = 0;
    while (getline(arch, linea)) {
        std::string tipo = linea.substr(0, linea.find(';'));
        if (tipo == "L") {
            materiales[cont] = new Libro();
        } else if (tipo == "R") {
            materiales[cont] = new Revista();
        }
        cont++;
    }
    arch.close();
}

void escribirMateriales(MaterialBibliografico* materiales[100]){
    
}

void insertarMaterial(MaterialBibliografico* biblioteca[100], MaterialBibliografico* material) {
    if (material == nullptr) {
        return;
    }
    for (int i = 0; i < 100; i++) {
        if (biblioteca[i] == nullptr) {
            biblioteca[i] = material;
            std::cout << "Material agregado correctamente" << std::endl;
            return;
        }
    }
    std::cout << "No queda espacio en la biblioteca" << std::endl;
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
    std::cout << "Nombre: \n>";
    std::cin >> nombre;
    std::cout << "ISBN: \n>";
    std::cin >> isbn;
    std::cout << "Autor: \n>";
    std::cin >> autor;
    std::cout << "Revista (R) o Libro (L)?";
    std::cin >> tipo;
    if (tipo == "R") {
        std::string nPublicacion, mesPublicacion;
        std::cout << "Numero de publicacion: \n>";
        std::cin >> nPublicacion;
        std::cout << "Mes de publicacion: \n>";
        std::cin >> mesPublicacion;
        aux = new Revista(nombre, isbn, autor, nPublicacion, mesPublicacion);
    } else if (tipo == "L") {
        std::string fechaPublicacion, resumen;
        std::cout << "Fecha de publicacion: \n>";
        std::cin >> fechaPublicacion;
        std::cout << "Resumen del libro: \n>";
        std::cin >> resumen;
        aux = new Libro(nombre, isbn, autor, fechaPublicacion, resumen);
    } else {
        std::cout << "Criterio no reconocido" << std::endl;
    }
    insertarMaterial(biblioteca, aux);
    if (aux == nullptr) {
        std::cout << "No se pudo agregar el material" << std::endl;
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
    std::cout << "Ingrese el ID del usuario: \n>";
    std::cin >> id;
    Usuario* user = buscarUsuario(id, usuarios);
    if (user != nullptr) {
        std::string criterio, palabra;
        std::cout << "Quiere buscar el material por Titulo (T) o por Autor (A)?";
        std::cin >> criterio;
        std::cout << "Ingrese la busqueda:";
        std::cin >> palabra;
        MaterialBibliografico* aux = buscarMaterial(palabra, criterio, biblioteca);
        if (aux != nullptr) {
            user -> prestarMaterial(aux);
        } else {
            std::cout << "Material no encontrado" << std::endl;
        }
    } else {
        std::cout << "Usuario no encontrado" << std::endl;
    }
}

void devolverMaterial(Usuario* usuarios[5]) {
    std::string id;
    std::cout << "Ingrese el ID del usuario: \n>";
    std::cin >> id;
    Usuario* user = buscarUsuario(id, usuarios);
    if (user != nullptr) {
        std::string criterio, palabra;
        std::cout << "Quiere buscar por nombre (N) o por ISBN (I):";
        std::cin >> criterio;
        std::cout << "Ingrese la busqueda";
        std::cin >> palabra;
        user -> devolverMaterial(palabra, criterio);
        return;
    }
    std::cout << "No se encontro el usuario" << std::endl;
}

int main() {
    MaterialBibliografico* libreria[100];
    Usuario* usuarios[5];
    leerMateriales(libreria);
    int opcion = -1;
    while (opcion != 0) {
        std::cout << "1. Agregar un libro\n2. Mostrar materiales\n3. Prestar material\n4. Devolver material\n5. Agregar usuario\n6. Eliminar usuario\n0. Cerrar el programa" << std::endl;
        std::cout << "Selecciona una opcion\n> ";
        std::cin >> opcion;
        switch (opcion) {
            case 0: std::cout << "Cerrando programa" << std::endl;
                break;
            case 1: agregarMaterial(libreria);
                break;
            case 2: mostrarMateriales(libreria);
                break;
            case 3: prestarMaterial(libreria, usuarios);
                break;
            case 4: devolverMaterial(usuarios);
                break;
            default: std::cout << "Opcion no reconocida" << std::endl;
                break;

        }
    }
    
    escribirMateriales(libreria);
    return 0;
};