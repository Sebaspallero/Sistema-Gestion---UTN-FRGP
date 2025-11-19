#pragma once
#include "../ManagerH/ManagerResultado.h"
#include "ServicioPaciente.h"
#include "ServicioTurno.h"

class ServicioResultado{
    private:
        ManagerResultado managerResultado;
        ServicioTurno servicioTurno;
        ServicioPaciente servicioPaciente;
        void limpiarBuffer() const;

        bool validarFechaResultado(int dia, int mes, int anio);
        bool existeResultadoParaTurno(int idTurno);

    public:
        ServicioResultado();

        bool crearResultado();
        bool modificarResultado();
        bool eliminarResultado();
        void listarResultados(const std::vector<Resultado>& resultados);
        std::vector<Resultado> obtenerResultado();
        void buscarPorPaciente();
};
