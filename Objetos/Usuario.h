#pragma once
#include <iostream>
#include "MaterialBibliografico.h"

class Usuario{
    private:
    std::string nombre, id;
    MaterialBibliografico* materialesPrestados[5]{};
    public:
    Usuario(std::string nombre, std::string id);
    void prestarMaterial(MaterialBibliografico* material);
    void devolverMaterial(std::string palabra, std::string criterio);
    void mostrarMaterialesPrestados();
    //Getters y setters
    std::string getNombre();
    void setNombre(std::string nombre);
    std::string getId();
    void setId(std::string id);
};