#include "../EntidadesH/Bioquimico.h"
#include <iostream>
#include <cstring>

    //Constructores
    Bioquimico::Bioquimico() : Persona() {
        _matricula = 0;
    }

    Bioquimico::Bioquimico(int id, std::string nombre, std::string apellido, Fecha fechaNacimiento, int dni, std::string email, int matricula)
    : Persona(id, nombre, apellido, fechaNacimiento, dni, email) {
        _matricula = matricula;
    }

    //Getters
    int Bioquimico::getMatricula() const{
        return _matricula;
    }

    //Setters
    void Bioquimico::setMatricula(int matricula){
        _matricula = matricula;
    }
