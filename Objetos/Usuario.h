#pragma once
#include <iostream>
#include "MaterialBibliografico.h"

class Usuario{
    private:
    std::string nombre, id;
    MaterialBibliografico* materialesPrestados;
    public:
    Usuario();
    void mostrarMaterial();
    void devolverMaterial();
    void mostrarMaterialesPrestados();
};