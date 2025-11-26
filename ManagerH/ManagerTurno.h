#pragma once
#include "Manager.h"
#include "../EntidadesH/Turno.h"
#include <vector>
#include <string>

class ManagerTurno : public Manager<Turno> {
public:
    ManagerTurno(const std::string& nombreArchivo);

    std::vector<Turno> ordenarPorFecha();
    std::vector<Turno> buscarPorFecha(int dia, int mes, int anio);
    std::vector<Turno> buscarPorPaciente(int idPaciente);
    std::vector<Turno> buscarPorBioquimico(int idBioquimico);
    std::vector<Turno> buscarPorAsistencia();

};
