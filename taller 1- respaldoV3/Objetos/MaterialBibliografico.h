#pragma once
#ifndef MATERIALBIBLIOGRAFICO_H
#define MATERIALBIBLIOGRAFICO_H
#include <iostream>
#include <fstream>

class MaterialBibliografico {
private:
    std::string nombre, isbn, autor;
    bool prestado;
public:
    MaterialBibliografico() = default;
    MaterialBibliografico(std::string nombre, std::string isbn, std::string autor);
    virtual void mostrarInformacion();
    virtual ~MaterialBibliografico();
    virtual void guardarEstado(std::fstream &arch);
    virtual void cargarEstado(std::fstream &arch);
    std::string getNombre();
    void setNombre(std::string nombre);
    std::string getIsbn();
    void setIsbn(std::string isbn);
    std::string getAutor();
    void setAutor(std::string autor);
    bool getPrestado();
    void setPrestado(bool prestado);
};
#endif