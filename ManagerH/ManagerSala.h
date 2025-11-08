#pragma once
#include "Manager.h"
#include <string>
#include <vector>
#include "../EntidadesH/Sala.h"

class ManagerSala : public Manager<Sala>{

    public:
        ManagerSala(const std::string& nombreArchivo);

        Sala buscarPorNombre(const std::string& nombre);
};
