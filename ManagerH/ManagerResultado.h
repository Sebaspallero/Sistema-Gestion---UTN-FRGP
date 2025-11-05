#pragma once
#include "Manager.h"
#include "../EntidadesH/Resultado.h"
#include <vector>
#include <string>

class ManagerResultado : public Manager <Resultado>{
public:
    ManagerResultado(std::string nombreArchivo);

    std::vector <Resultado> buscarPorPaciente(int idPaciente);
    bool crearResultado(int idTurno, std::string descripcion, int dia, int mes, int anio);
    bool modificarResultado(int idTurno, std::string descripcion, int dia, int mes, int anio, int id);
};
