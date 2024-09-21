#include <iostream>
#include "Usuario.h"

Usuario::Usuario(std::string nombre, std::string id) {
    this->nombre = nombre;
    this->id = id;
};
void Usuario::prestarMaterial(MaterialBibliografico* material) {
    for (int i = 0; i < 5; i++) {
        if (materialesPrestados[i] == nullptr) {
            materialesPrestados[i] = material;
            std::cout << "Prestamo exitoso" << std::endl;
            return;
        }
    }
    std::cout << "Prestamo fallido, maximo de prestamos alcanzado" << std::endl;
};

MaterialBibliografico* Usuario::devolverMaterial(std::string nombre) {
    for (int i = 0; i < 5; i++) {
        if (materialesPrestados[i] != nullptr) {
            
        }
    }

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