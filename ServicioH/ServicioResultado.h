#pragma once
#include "../ManagerH/ManagerResultado.h"
#include "ServicioPaciente.h"
#include "ServicioTurno.h"

class ServicioResultado{
    private:
        ManagerResultado managerResultado;
        ServicioPaciente servicioPaciente;
        ServicioTurno servicioTurno;
        void limpiarBuffer() const;

        bool existeResultadoParaTurno(int idTurno);

    public:
        ServicioResultado();

        void crearResultado();
        void modificarResultado();
        void eliminarResultado();
        void listarResultados(const std::vector<Resultado>& resultados);
        std::vector<Resultado> obtenerResultado();
        void buscarPorPaciente();
};
