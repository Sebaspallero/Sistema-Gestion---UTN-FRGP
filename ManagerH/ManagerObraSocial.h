#pragma once
#include "Manager.h"
#include "../EntidadesH/ObraSocial.h"

class ManagerObraSocial : public Manager<ObraSocial>{
public:
    ManagerObraSocial(const std::string&nombreArchivo);
    ObraSocial buscarPorNombre(std::string& nombre);
};
