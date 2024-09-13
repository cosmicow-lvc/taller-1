#include "Objetos/MaterialBibliografico.h"
#include "Objetos/Libro.h"
#include "Objetos/Revista.h"
#include "Objetos/Usuario.h"
#include <iostream>
using namespace std;


int main(){
    MaterialBibliografico* arrayMB[50];

    int opcion = -1;
    while (opcion != 0) {
        cout << "1. Agregar un libro\n2.Mostrar material\n3.Buscar material\n4.Prestar material\n5. Devolver material\n6. Gestión de usuarios" << endl;
        cout << "Selecciona una opcion\n>";
        cin >> opcion;
        switch (opcion) {
            case 0: break;

        }
    }

    for (int i = 0; i < 1; i++) {
        delete arrayMB[i];
    }

    return 0;
}