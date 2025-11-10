#pragma once
#include "../ManagerH/ManagerPaciente.h"
#include "../ServicioH/ServicioObraSocial.h"
#include "../EntidadesH/Paciente.h"
#include "../EntidadesH/Fecha.h"
#include <vector>

class ServicioPaciente {
    private:
        ManagerPaciente managerPaciente;
        ServicioObraSocial servicioObraSocial;

        void limpiarBuffer() const;

    public:
        ServicioPaciente();

        void crearPaciente();
        std::vector<Paciente> listarPacientes();
        void eliminarPaciente();
        void modificarPaciente();
        void buscarPacientePorDNI();
        void buscarPacientePorApellido();
        std::vector<Paciente> ordenarPacientesPorApellido();
};
