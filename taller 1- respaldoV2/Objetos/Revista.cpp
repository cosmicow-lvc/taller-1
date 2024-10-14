#include "Revista.h"

Revista::Revista(std::string nombre, std::string isbn, std::string autor, std::string numeroPublicacion, std::string mesPublicacion)
    :MaterialBibliografico(nombre, isbn, autor) {
    this-> numeroPublicacion = numeroPublicacion;
    this-> mesPublicacion = mesPublicacion;
}

void Revista::mostrarInformacion(){
    MaterialBibliografico::mostrarInformacion();
    std::cout << "Numero de publicacion: " + numeroPublicacion + "\nMes de publicacion: " + mesPublicacion << std::endl;
}

void Revista::guardarEstado(std::fstream &arch) {
    arch << "R;" 
         << getNombre() << ";"  // Usar getters para acceder a los atributos
         << getIsbn() << ";" 
         << getAutor() << ";" 
         << getPrestado() << ";"  // Asegúrate de usar prestado
         << numeroPublicacion << ";" 
         << mesPublicacion << "\n";
}

void Revista::cargarEstado(std::fstream &arch) {
    MaterialBibliografico::cargarEstado(arch);
    getline(arch, numeroPublicacion, ';');
    getline(arch, mesPublicacion);  // Asumiendo que el mes de publicación no tiene delimitadores
}

Revista::~Revista() {
    std::cout << "xd" << std::endl;
}