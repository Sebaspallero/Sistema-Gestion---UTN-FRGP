#pragma once
#include "../ManagerH/ManagerSala.h"
#include "../EntidadesH/Sala.h"
#include <string>

class ServicioSala {
    private:
        ManagerSala managerSala;
        void limpiarBuffer() const;

    public:
        ServicioSala();

        void crearSala();
        void modificarSala();
        std::vector<Sala> obtenerSalas();
        void listarSalas(const std::vector<Sala>& salas);
        void eliminarSala();
        void buscarSalaPorNombre();
};
