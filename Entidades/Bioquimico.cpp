#include <iostream>
#include <cstring>
#include "../EntidadesH/Bioquimico.h"

std::string Bioquimico::getMatricula() const{return std::string(_matricula);};
void Bioquimico::setMatricula(std::string& matricula){
strncpy(_matricula,matricula.c_str(),sizeof(_matricula)-1);
_matricula[sizeof(_matricula) - 1] = '\0';
};
