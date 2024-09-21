#include <iostream>
#include "Libro.h"

Libro::Libro(std::string nombre, std::string isbn, std::string autor, std::string fechaPublicacion, std::string resumen)
    : MaterialBibliografico(nombre, isbn, autor) {
    this -> fechaPublicacion = fechaPublicacion;
    this ->resumen = resumen;
}
void Libro::mostrarInformacion() {
    MaterialBibliografico::mostrarInformacion();
    std::cout << "Fecha de publicacion: " + fechaPublicacion + "\nResumen: " + resumen<< std::endl;
}

Libro::~Libro() {
    std::cout << "xd1" << std::endl;
}
