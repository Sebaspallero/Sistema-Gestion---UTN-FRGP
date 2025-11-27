#pragma once
#include "Manager.h"
#include "../EntidadesH/Resultado.h"
#include <vector>
#include <string>

class ManagerResultado : public Manager <Resultado>{
public:
    ManagerResultado(const std::string& nombreArchivo);

    std::vector <Resultado> buscarPorPaciente(int idPaciente);
};
