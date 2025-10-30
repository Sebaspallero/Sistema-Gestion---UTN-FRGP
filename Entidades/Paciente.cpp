#include "../EntidadesH/Paciente.h"
#include <iostream>
#include <cstring>

    //Getters

    std::string Paciente::getTelefono() const{
        return std::string(_telefono);
    }

    int Paciente::getCodigoObraSocial() const{
        return _codigoObraSocial;
    }

    //Setters
    void Paciente::setTelefono(std::string& telefono){
    strncpy(_telefono,telefono.c_str(),sizeof(_telefono)-1);
    _telefono[sizeof(_telefono) - 1] = '\0';
    }

    void Paciente::setCodigoObraSocial(int codigoObraSocial){
        _codigoObraSocial = codigoObraSocial;
    }
