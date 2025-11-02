#pragma once
#include "Persona.h"
#include <cstring>

class Paciente : public Persona{
    private:
        char _telefono [15];
        int _codigoObraSocial;

    public:
        Paciente();
        Paciente(int id, std::string nombre, std::string apellido, Fecha fechaNacimiento, int dni, std::string email, std::string telefono, int codigoObraSocial);

        std::string getTelefono() const;
        int getCodigoObraSocial() const;

        void setTelefono(const std::string& telefono);
        void setCodigoObraSocial(int codigoObraSocial);
};
