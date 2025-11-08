#pragma once
#include <string>
#include <vector>
#include "Manager.h"
#include "../EntidadesH/Paciente.h"


class ManagerPaciente : public Manager<Paciente>{

    public:
        ManagerPaciente(const std::string& nombreArchivo);
        std::vector<Paciente> ordenarPorApellido();
        Paciente buscarPorDNI(int dni);
        std::vector<Paciente> buscarPorApellido(std::string apellido);
        std::vector<Paciente> buscarPorObraSocial(int idObraSocial);

};
