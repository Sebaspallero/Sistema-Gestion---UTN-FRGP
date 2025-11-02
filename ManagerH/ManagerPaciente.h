#pragma once
#include <string>
#include <vector>
#include "Manager.h"
#include "../EntidadesH/Paciente.h"


class ManagerPaciente : public Manager<Paciente>{

    public:
        ManagerPaciente(std::string nombreArchivo);
        std::vector<Paciente> ordenarPorApellido();
        Paciente buscarPorDNI(int dni);
        std::vector<Paciente> buscarPorApellido(std::string apellido);
        std::vector<Paciente> buscarPorObraSocial(int idObraSocial);

        bool crearPaciente(std::string nombre, std::string apellido,
                       int dia, int mes, int anio,
                       int dni, std::string email,
                       std::string telefono, int codigoObraSocial);

        bool modificarPaciente(std::string nombre, std::string apellido,
                           int dia, int mes, int anio,
                           int dni, std::string email,
                           std::string telefono, int codigoObraSocial, int id);

};
