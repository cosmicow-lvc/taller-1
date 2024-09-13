#pragma once
#include <iostream>
#include "MaterialBibliografico.h"

class Libro: public MaterialBibliografico{
    private:
    std::string fechaPublicacion, resumen;
    public:
    Libro() = default;
    Libro(std::string nombre, std::string isbn, std::string autor, std::string fechaPublicacion, std::string resumen);
    void mostrarInformacion() override;
    ~Libro() override;
};