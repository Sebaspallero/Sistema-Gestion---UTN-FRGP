#pragma once
#include "Manager.h"
#include "../EntidadesH/Turno.h"
#include <vector>
#include <string>

class ManagerTurno : public Manager<Turno> {
public:
    ManagerTurno(std::string nombreArchivo);

    std::vector<Turno> ordenarPorFecha();
    std::vector<Turno> buscarPorFecha(int dia, int mes, int anio);
    std::vector<Turno> buscarPorPaciente(int idPaciente);
    std::vector<Turno> buscarPorBioquimico(int idBioquimico);


    bool crearTurno(int idPaciente, int idBioquimico, int idAnalisis, int idSala, int minuto, int hora, int dia, int mes, int anio);
    bool modificarTurno(int idPaciente, int idBioquimico, int idAnalisis, int idSala, int minuto, int hora, int dia, int mes, int anio, bool asistio, int idTurno);
    bool confirmarTurno(int idTurno);
};
