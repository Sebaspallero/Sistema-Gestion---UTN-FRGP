#pragma once
#include <cstring>
#include <iostream>
#include "Persona.h"

class Bioquimico : public Persona{
private:
    char _matricula [30];
public:
    std::string getMatricula() const;
    void setMatricula(std::string& matricula);
};
