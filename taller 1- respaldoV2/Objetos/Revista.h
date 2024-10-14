#pragma once
#ifndef REVISTA_H
#define REVISTA_H
#include "MaterialBibliografico.h"
#include <fstream> 

class Revista: public MaterialBibliografico {
    private:
    std::string numeroPublicacion, mesPublicacion;
    public:
    Revista() = default;
    Revista(std::string nombre, std::string isbn, std::string autor, std::string numeroPublicacion, std::string mesPublicacion);
    void mostrarInformacion() override;
    void guardarEstado(std::fstream &arch) override;
    void cargarEstado(std::fstream &arch) override;
    ~Revista() override;
};
#endif