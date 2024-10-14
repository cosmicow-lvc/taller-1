#pragma once
#ifndef USUARIO_H
#define USUARIO_H
#include "MaterialBibliografico.h"
#include <fstream> 
#include <sstream> 

class Usuario{
    private:
    std::string nombre, id;
    MaterialBibliografico* materialesPrestados[5]{};
    public:
    Usuario(std::string nombre, std::string id);
    void prestarMaterial(MaterialBibliografico* material);
    void devolverMaterial(std::string palabra, std::string criterio);
    void mostrarMaterialesPrestados();
    void mostrarInformacionUsuario();
    void guardarEstado(std::fstream &arch);
    static Usuario* cargarLinea(const std::string linea);
    std::string getNombre();
    void setNombre(std::string nombre);
    std::string getId();
    void setId(std::string id);
};
#endif