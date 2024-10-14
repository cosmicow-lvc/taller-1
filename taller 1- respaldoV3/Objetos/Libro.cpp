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

void Libro::guardarEstado(std::fstream &arch) {
    arch << "L;" 
         << getNombre() << ";"  
         << getIsbn() << ";" 
         << getAutor() << ";" 
         << getPrestado() << ";"  
         << fechaPublicacion << ";" 
         << resumen << "\n";
}

void Libro::cargarEstado(std::fstream &arch) {
    MaterialBibliografico::cargarEstado(arch);
    getline(arch, fechaPublicacion, ';');
    getline(arch, resumen);  
}

Libro::~Libro() {
    std::cout << "se destruye libro" << std::endl;
}