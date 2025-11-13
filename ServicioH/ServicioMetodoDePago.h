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
        std::vector<MetodoDePago> listarMetodosDePago();
};
