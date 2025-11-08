#pragma once
#include "Manager.h"
#include "../EntidadesH/ObraSocial.h"

class ManagerObraSocial : public Manager<ObraSocial>{
public:
    ManagerObraSocial(std::string& nombreArchivo);
    ObraSocial buscarPorNombre(std::string& nombre);
    bool crearObraSocial(std::string& nombre, float descuento);
    bool modificarObraSocial(std::string& nombre, float descuento, int id);
};
