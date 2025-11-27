#pragma once
#include "../ManagerH/ManagerFactura.h"
#include "ServicioPaciente.h"
#include "ServicioAnalisis.h"
#include "ServicioMetodoDePago.h"
#include "ServicioTurno.h"
#include "ServicioObraSocial.h"
#include <vector>
#include <string>

class ServicioFactura{
    private:
        ManagerFactura managerFactura;
        ServicioAnalisis servicioAnalisis;
        ServicioPaciente servicioPaciente;
        ServicioMetodoDePago servicioMetodoDePago;
        ServicioTurno servicioTurno;
        ServicioObraSocial servicioObraSocial;

        std::string nombrePacientePorId(int id, const std::vector<Paciente>& lista);
        std::string nombreMetodoDePagoPorId(int id, const std::vector<MetodoDePago>& lista);
        std::string nombreAnalisisPorId(int id, const std::vector<Analisis>& lista);

        void limpiarBuffer() const;

        bool existeFacturaParaTurno(int idTurno);
        float calcularMontoConDescuento(int idPaciente, int idAnalisis, const std::vector<Paciente>& listaPacientes, const std::vector<Analisis>& listaAnalisis,const std::vector<ObraSocial>& listaOS);

    public:
        ServicioFactura();

        void crearFactura();
        void modificarFactura();
        void eliminarFactura();
        std::vector<Factura> obtenerFacturas();
        void listarFacturas(const std::vector<Factura>& facturas);
        void buscarPorMetodoDePago();
        void buscarPorFecha();
        void buscarPorPaciente();
        void ordenarPorFechaDePago();
};
