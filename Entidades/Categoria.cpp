#include "../EntidadesH/Categoria.h"
#include <cstring>
#include <iostream>

    //Constructores
    Categoria::Categoria() {
        _id = 0;
        std::strncpy(_nombre, "Sin Nombre", sizeof(_nombre) - 1);
        _nombre[sizeof(_nombre) - 1] = '\0';
        _estado = true;
    }

    Categoria::Categoria(int id, std::string nombre) {
        _id = id;
        std::strncpy(_nombre, nombre.c_str(), sizeof(_nombre) - 1);
        _nombre[sizeof(_nombre) - 1] = '\0';
        _estado = true;
    }

    //Getters
    int Categoria::getId() const{
        return _id;
    }

    std::string Categoria::getNombre() const{
        return std::string(_nombre);
    }

    bool Categoria::getEstado() const{
        return _estado;
    }

    //Setters
    void Categoria::setId(int idCategoria){
        _id = idCategoria;
    }

    void Categoria::setNombre(std::string& nombre){
        strncpy(_nombre,nombre.c_str(),sizeof(_nombre)-1);
        _nombre[sizeof(_nombre) - 1] = '\0';
    }

    void Categoria::setEstado(bool estado){
            _estado = estado;
    }
