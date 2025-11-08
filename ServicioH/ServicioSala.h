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
    std::vector <Sala> listarSalas();
    void eliminarSala();
    void buscarSalaPorNombre();
};
