#pragma once
#include <iostream>

class MaterialBibliografico {
private:
    std::string nombre, isbn, autor;
    bool prestado;
public:
    MaterialBibliografico() = default;
    MaterialBibliografico(std::string nombre, std::string isbn, std::string autor);
    virtual void mostrarInformacion();
    virtual ~MaterialBibliografico();
    //Getters y setters
    std::string getNombre();
    void setNombre(std::string nombre);
    std::string getIsbn();
    void setIsbn(std::string isbn);
    std::string getAutor();
    void setAutor(std::string autor);
    bool getPrestado();
    void setPrestado(bool prestado);
};