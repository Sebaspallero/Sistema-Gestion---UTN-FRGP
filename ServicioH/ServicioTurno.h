#pragma once
#include "../ManagerH/ManagerTurno.h"
#include "ServicioAnalisis.h"
#include "ServicioPaciente.h"
#include "ServicioBioquimico.h"
#include "ServicioSala.h"

class ServicioTurno{
    private:
        ManagerTurno managerTurno;
        ServicioAnalisis servicioAnalisis;
        ServicioSala servicioSala;
        ServicioPaciente servicioPaciente;
        ServicioBioquimico servicioBioquimico;

        bool fechaOcupada(const FechaHora& nuevaFechaHora, int idSala, int idBioquimico);

        std::string nombrePacientePorId(int id, const std::vector<Paciente>& lista);
        std::string nombreBioquimicoPorId(int id, const std::vector<Bioquimico>& lista);
        std::string nombreAnalisisPorId(int id, const std::vector<Analisis>& lista);
        std::string nombreSalaPorId(int id, const std::vector<Sala>& lista);

        void limpiarBuffer() const;

    public:
        ServicioTurno();

        void crearTurno();
        void modificarTurno();
        void eliminarTurno();
        std::vector <Turno> obtenerTurnos();
        std::vector <Turno> obtenerTurnosConAsistencia();
        void listarTurnos(const std::vector<Turno>& turnos);
        void buscarPorFecha();
        void buscarPorPaciente();
        void buscarPorBioquimico();
        void confirmarTurno();
        void ordenarPorFecha();
};
