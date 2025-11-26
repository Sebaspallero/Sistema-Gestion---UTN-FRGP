#pragma once
#include "../ManagerH/ManagerPaciente.h"
#include "../ServicioH/ServicioObraSocial.h"
#include "../EntidadesH/Paciente.h"
#include "../EntidadesH/Fecha.h"
#include <vector>
#include <string>

class ServicioPaciente {
    private:
        ManagerPaciente managerPaciente;
        ServicioObraSocial servicioObraSocial;
        void limpiarBuffer() const;
        bool existeDNI(int dni);
        std::string nombreObraPorId(int id, const std::vector<ObraSocial>& lista);

    public:
        ServicioPaciente();

        void crearPaciente();
        std::vector<Paciente> obtenerPacientes();
        void listarPacientes(const std::vector<Paciente>& pacientes);
        void eliminarPaciente();
        void modificarPaciente();
        void buscarPacientePorDNI();
        void buscarPacientePorApellido();
        void ordenarPacientesPorApellido();
        bool buscarPorId(int id, Paciente &paciente);
};
