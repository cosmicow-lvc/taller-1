#include "MaterialBibliografico.cpp"
#include <iostream>
using namespace std;

class Usuario{
    public:
    string nombre, id;
    MaterialBibliografico* materialesPrestados = new MaterialBibliografico[5];
    void mostrarMaterial() {;}
    void devolverMaterial() {;}
    void mostrarMaterialesPrestados() {;}
};