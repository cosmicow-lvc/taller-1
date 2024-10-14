#pragma once
#ifndef LIBRO_H
#define LIBRO_H
#include "MaterialBibliografico.h"
#include <fstream> 

class Libro: public MaterialBibliografico{
    private:
    std::string fechaPublicacion, resumen;
    public:
    Libro() = default;
    Libro(std::string nombre, std::string isbn, std::string autor, std::string fechaPublicacion, std::string resumen);
    void mostrarInformacion() override;
    void guardarEstado(std::fstream &arch) override;
    void cargarEstado(std::fstream &arch) override;
    ~Libro() override;
};
#endif