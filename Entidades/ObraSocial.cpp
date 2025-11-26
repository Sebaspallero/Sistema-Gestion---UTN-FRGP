#include "../EntidadesH/ObraSocial.h"
#include <iostream>
#include <cstring>

    //Constructores
    ObraSocial::ObraSocial() {
        _id = 0;
        std::strncpy(_nombre, "Sin Nombre", sizeof(_nombre) - 1);
        _nombre[sizeof(_nombre) - 1] = '\0';
        _descuento = 0;
        _estado = true;
    }

    ObraSocial::ObraSocial(int id, std::string nombre, float descuento) {
        _id = id;
        std::strncpy(_nombre, nombre.c_str(), sizeof(_nombre) - 1);
        _nombre[sizeof(_nombre) - 1] = '\0';
        _descuento = descuento;
        _estado = true;
    }

    //Getters
    int ObraSocial::getId() const{
        return _id;
    }

    std::string ObraSocial::getNombre() const{
        return std::string (_nombre);
    }

    float ObraSocial::getDescuento() const{
        return _descuento;
    }

    bool ObraSocial::getEstado() const{
        return _estado;
    }

    //Setters
    void ObraSocial::setId(int idObraSocial){
        _id = idObraSocial;
    }

    void ObraSocial::setNombre(std::string& nombre){
        std::strncpy(_nombre, nombre.c_str(), sizeof(_nombre) - 1);
        _nombre[sizeof(_nombre) - 1] = '\0';
    }

    void ObraSocial::setDescuento(float descuento){
        _descuento = descuento;
    }

    void ObraSocial::setEstado(bool estado){
        _estado = estado;
    }
