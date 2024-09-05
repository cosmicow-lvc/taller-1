#include <iostream>
using namespace std;

class MaterialBibliografico{
    public:
    string nombre, isbn, autor;
    bool prestado;
    virtual void mostrarInformacion() {cout << "Nombre: " + nombre + "\nISBN: " + isbn + "\nAutor: " + autor << endl;}
};