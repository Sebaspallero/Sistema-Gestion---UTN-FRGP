#pragma once
#include <cstring>
#include <iostream>
#include "Persona.h"

class Bioquimico : public Persona{
    private:
        int _matricula;

    public:
        int getMatricula() const;

        void setMatricula(int matricula);
};
