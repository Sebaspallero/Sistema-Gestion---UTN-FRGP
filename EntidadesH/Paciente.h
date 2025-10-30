#pragma once
#include "Persona.h"
#include <cstring>

class Paciente : public Persona{
    private:
        char _telefono [15];
        int _codigoObraSocial;

    public:
        std::string getTelefono() const;
        int getCodigoObraSocial() const;

        void setTelefono(std::string telefono);
        void setCodigoObraSocial(int codigoObraSocial);
};
