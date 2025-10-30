#include "../EntidadesH/MetodoDePago.h"
#include <iostream>
#include <cstring>

    //Getters
    int MetodoDePago::getIDMetodoPago() const{
        return _idMetodoPago;
    }

    std::string MetodoDePago::getNombre() const{
        return std::string (_nombre);
    }

    bool MetodoDePago::getEstado() const{
        return _estado;
    }

    //Setters
    void MetodoDePago::setIDMetodoPago(int idMetodoPago){
        _idMetodoPago = idMetodoPago;
    }

    void MetodoDePago::setNombre(std::string& nombre){
        std::strncpy(_nombre, nombre.c_str(), sizeof(_nombre) - 1);
        _nombre[sizeof(_nombre) - 1] = '\0';
    }

    void MetodoDePago::setEstado(bool estado){
        _estado = estado;
    }
