#include <iostream>
#include "MaterialBibliografico.h"

MaterialBibliografico::MaterialBibliografico(std::string nombre, std::string isbn, std::string autor) {
    this -> nombre = nombre;
    this -> isbn = isbn;
    this -> autor = autor;
    this -> prestado = false;
}

void MaterialBibliografico::mostrarInformacion(){
    std::cout << "Nombre: " + nombre + "\nISBN: " + isbn + "\nAutor: " + autor << std::endl;
}

MaterialBibliografico::~MaterialBibliografico() {
    std::cout << "xd" << std::endl;
}
