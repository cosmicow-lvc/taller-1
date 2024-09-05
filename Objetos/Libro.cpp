#include "MaterialBibliografico.cpp";
#include <iostream>

class Libro: public MaterialBibliografico{
    public:
    string fechaPublicacion, resumen;
    void mostrarInformacion() {cout << "Fecha de publicacion: " + fechaPublicacion + "\nResumen: " + resumen<< endl;}
};