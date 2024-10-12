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

//Getters y setters

std::string MaterialBibliografico::getNombre() {
    return nombre;
}

void MaterialBibliografico::setNombre(std::string nombre) {
    this -> nombre = nombre;
}

std::string MaterialBibliografico::getIsbn() {
    return isbn;
}

void MaterialBibliografico::setIsbn(std::string isbn) {
    this -> isbn = isbn;
}

std::string MaterialBibliografico::getAutor() {
    return autor;
}

void MaterialBibliografico::setAutor(std::string autor) {
    this -> autor = autor;
}

bool MaterialBibliografico::getPrestado() {
    return prestado;
}

void MaterialBibliografico::setPrestado(bool prestado) {
    this -> prestado = prestado;
}