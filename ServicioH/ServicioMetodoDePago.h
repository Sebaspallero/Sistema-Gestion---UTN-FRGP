#pragma once
#include "../ManagerH/ManagerMetodoPago.h"
#include "../EntidadesH/MetodoDePago.h"
#include <vector>
#include <string>

class ServicioMetodoDePago {
    private:
        ManagerMetodoDePago managerMetodoDePago;
        void limpiarBuffer() const;

    public:
        ServicioMetodoDePago();

        void crearMetodoDePago();
        void modificarMetodoDePago();
        void eliminarMetodoDePago();
        void listarMetodosDePago();
        std::vector<MetodoDePago> obtenerMetodosDePago();
        void listarMetodosDePago(const std::vector<MetodoDePago>& metodosDePago);
};
