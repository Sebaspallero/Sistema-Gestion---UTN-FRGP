/**
#pragma once
#include "..ManagerH/ManagerTurno.h"

class ServicioTurno{
    private:
        ManagerTurno managerTurno;

    public:
        ServicioTurno();

        bool crearTurno();
        bool modificarTurno();
        bool eliminarTurno();
        void listarTurnos();
        void buscarPorFecha();
        void buscarPorPaciente();
        void buscarPorBioquimico();
        void confirmarTurno();
        std::vector<Turno> ordenarPorFecha();
};

*/
