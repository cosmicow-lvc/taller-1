#include "MaterialBibliografico.cpp"
#include <iostream>

class Revista: public MaterialBibliografico {
    public:
    string numeroPublicacion, mesPublicacion;
    void mostrarInformacion() {cout << "Numero de publicacion: " + numeroPublicacion + "\nMes de publicacion: " + mesPublicacion << endl;}
};