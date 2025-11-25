#pragma once
#include "Manager.h"
#include "../EntidadesH/Bioquimico.h"
#include <vector>
#include <string>

class ManagerBioquimico : public Manager<Bioquimico> {
public:
    ManagerBioquimico(const std::string& nombreArchivo);

    std::vector<Bioquimico> ordenarPorApellido();
    std::vector<Bioquimico> ordenarPorLegajo();
    Bioquimico buscarPorMatricula(int matricula,bool& encontro);
};
