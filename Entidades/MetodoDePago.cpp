#include "../EntidadesH/MetodoDePago.h"
#include <iostream>
#include <cstring>

    //Constructores
    MetodoDePago::MetodoDePago() {
        _id = 0;
        std::strncpy(_nombre, "Sin Nombre", sizeof(_nombre) - 1);
        _nombre[sizeof(_nombre) - 1] = '\0';
        _estado = true;
    }

    MetodoDePago::MetodoDePago(int id, std::string nombre) {
        _id = id;
        std::strncpy(_nombre, nombre.c_str(), sizeof(_nombre) - 1);
        _nombre[sizeof(_nombre) - 1] = '\0';
        _estado = true;
    }

    //Getters
    int MetodoDePago::getId() const{
        return _id;
    }

    std::string MetodoDePago::getNombre() const{
        return std::string (_nombre);
    }

    bool MetodoDePago::getEstado() const{
        return _estado;
    }

    //Setters
    void MetodoDePago::setId(int idMetodoPago){
        _id = idMetodoPago;
    }

    void MetodoDePago::setNombre(std::string& nombre){
        std::strncpy(_nombre, nombre.c_str(), sizeof(_nombre) - 1);
        _nombre[sizeof(_nombre) - 1] = '\0';
    }

    void MetodoDePago::setEstado(bool estado){
        _estado = estado;
    }
