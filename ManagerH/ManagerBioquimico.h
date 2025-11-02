#pragma once
#include "Manager.h"
#include "../EntidadesH/Bioquimico.h"
#include <vector>
#include <string>

class ManagerBioquimico : public Manager<Bioquimico> {
public:
    ManagerBioquimico(std::string nombreArchivo);

    std::vector<Bioquimico> ordenarPorApellido();
    std::vector<Bioquimico> ordenarPorLegajo();
    bool crearBioquimico(std::string nombre, std::string apellido,
                         int dia, int mes, int anio, int dni, std::string email, int matricula);
    bool modificarBioquimico(std::string nombre, std::string apellido,
                             int dia, int mes, int anio, int dni, std::string email, int matricula, int id);
};
