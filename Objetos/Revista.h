#pragma once
#include <iostream>
#include "MaterialBibliografico.h"

class Revista: public MaterialBibliografico {
    private:
    std::string numeroPublicacion, mesPublicacion;
    public:
    Revista() = default;
    Revista(std::string nombre, std::string isbn, std::string autor, std::string numeroPublicacion, std::string mesPublicacion);
    void mostrarInformacion() override;
    ~Revista() override;
};