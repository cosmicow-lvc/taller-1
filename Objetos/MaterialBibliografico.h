#pragma once
#include <iostream>

class MaterialBibliografico {
private:
    std::string nombre, isbn, autor;
    bool prestado;
public:
    MaterialBibliografico() = default;
    MaterialBibliografico(std::string nombre, std::string isbn, std::string autor);
    virtual void mostrarInformacion();
    virtual ~MaterialBibliografico();
};