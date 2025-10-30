#include "../EntidadesH/ObraSocial.h"
#include <iostream>
#include <cstring>

    //Getters
    int ObraSocial::getIDObraSocial() const{
        return _idObraSocial;
    }

    std::string ObraSocial::getNombre() const{
        return std::string (_nombre);
    }

    int ObraSocial::getDescuento() const{
        return _descuento;
    }

    bool ObraSocial::getEstado() const{
        return _estado;
    }

    //Setters
    void ObraSocial::setIDObraSocial(int idObraSocial){
        _idObraSocial = idObraSocial;
    }

    void ObraSocial::setNombre(std::string& nombre){
        std::strncpy(_nombre, nombre.c_str(), sizeof(_nombre) - 1);
        _nombre[sizeof(_nombre) - 1] = '\0';
    }

    void ObraSocial::setDescuento(int descuento){
        _descuento = descuento;
    }

    void ObraSocial::setEstado(bool estado){
        _estado = estado;
    }
