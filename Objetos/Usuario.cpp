#include <iostream>
#include "Usuario.h"

Usuario::Usuario(std::string nombre, std::string id) {
    this->nombre = nombre;
    this->id = id;
};

void Usuario::prestarMaterial(MaterialBibliografico* material) {
    if (material -> getPrestado()) {
        std::cout << "Material ya prestado" << std::endl;
        return;
    }
    for (int i = 0; i < 5; i++) {
        if (materialesPrestados[i] == nullptr) {
            materialesPrestados[i] = material;
            material -> setPrestado(true);
            std::cout << "Prestamo exitoso" << std::endl;
            return;
        }
    }
    std::cout << "Prestamo fallido, maximo de prestamos alcanzado" << std::endl;
};

void Usuario::devolverMaterial(std::string palabra, std::string criterio) {
    if (criterio == "N") {
        for (int i = 0; i < 5; i++) {
            if (materialesPrestados[i] != nullptr) {
                if (materialesPrestados[i] -> getNombre() == palabra) {
                    materialesPrestados[i] -> setPrestado(false);
                    materialesPrestados[i] = nullptr;
                    std::cout << "Devolucion exitosa" << std::endl;
                    return;
                }
            }
        }
    }
    if (criterio == "I") {
        for (int i = 0; i < 5; i++) {
            if (materialesPrestados[i] != nullptr) {
                if (materialesPrestados[i] -> getIsbn() == palabra) {
                    materialesPrestados[i] -> setPrestado(false);
                    materialesPrestados[i] = nullptr;
                    std::cout << "Devolucion exitosa" << std::endl;
                    return;
                }
            }
        }
    }
    std::cout << "Devolucion fallida, material no encontrado" << std::endl;
};

void Usuario::mostrarMaterialesPrestados() {
    for (int i = 0; i < 5; i++) {
        std::cout << "================================" << std::endl;
        if (materialesPrestados[i] != nullptr) {
            materialesPrestados[i]->mostrarInformacion();
            std::cout << "================================" << std::endl;
        }
    }
    std::cout << "Fin del comunicado" << std::endl;
    std::cout << "==================================" << std::endl;
};

//Getters y setters

std::string Usuario::getNombre() {
    return nombre;
}

void Usuario::setNombre(std::string nombre) {
    this -> nombre = nombre;
}

std::string Usuario::getId() {
    return id;
}

void Usuario::setId(std::string id) {
    this -> id = id;
}