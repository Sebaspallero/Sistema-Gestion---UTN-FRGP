#include "../EntidadesH/Paciente.h"
#include <iostream>
#include <cstring>
#include <string>

    //Constructores
    Paciente::Paciente() : Persona() {
        std::strncpy(_telefono, "Sin Teléfono", sizeof(_telefono) - 1);
        _telefono[sizeof(_telefono) - 1] = '\0';
        _codigoObraSocial = 0;
    }

    Paciente::Paciente(int id, std::string nombre, std::string apellido, Fecha fechaNacimiento, int dni, std::string email, std::string telefono, int codigoObraSocial)
    : Persona(id, nombre, apellido, fechaNacimiento, dni, email) {
        std::strncpy(_telefono, telefono.c_str(), sizeof(_telefono) - 1);
        _telefono[sizeof(_telefono) - 1] = '\0';
        _codigoObraSocial = codigoObraSocial;
    }

    //Getters
    std::string Paciente::getTelefono() const{
        return std::string(_telefono);
    }

    int Paciente::getCodigoObraSocial() const{
        return _codigoObraSocial;
    }

    //Setters
    void Paciente::setTelefono(const std::string& telefono){
        strncpy(_telefono,telefono.c_str(),sizeof(_telefono)-1);
        _telefono[sizeof(_telefono) - 1] = '\0';
    }

    void Paciente::setCodigoObraSocial(int codigoObraSocial){
        _codigoObraSocial = codigoObraSocial;
    }
