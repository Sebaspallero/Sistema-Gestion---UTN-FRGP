#pragma once
#include <cstring>
#include <iostream>
#include "Persona.h"

class Bioquimico : public Persona{
    private:
        int _matricula;

    public:
        Bioquimico();
        Bioquimico(int id, std::string nombre, std::string apellido, Fecha fechaNacimiento, int dni, std::string email, int matricula);

        int getMatricula() const;

        void setMatricula(int matricula);
};
