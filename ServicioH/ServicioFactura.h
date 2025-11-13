/**
#pragma once
#include "..ManagerH/ManagerFactura.h"

class ServicioFactura{
    private:
        ManagerFactura managerFactura;

    public:
        ServicioFactura();

        bool crearFactura();
        bool modificarFactura();
        bool eliminarFactura();
        void listarFacturas();
        void buscarPorMetodoDePago();
        void buscarPorFecha();
        void buscarPorPaciente();
        std::vector <Factura> ordenarPorFechaDePago();
};

*/
