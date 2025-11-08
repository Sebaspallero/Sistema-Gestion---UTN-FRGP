#pragma once
#include "../ManagerH/ManagerObraSocial.h"
#include "../EntidadesH/ObraSocial.h"
#include <vector>
#include <string>

class ServicioObraSocial {
private:
    ManagerObraSocial managerObraSocial;
    void limpiarBuffer() const;

public:
    ServicioObraSocial();
    void crearObraSocial();
    std::vector<ObraSocial> listarObrasSociales();
    void eliminarObraSocial();
    void modificarObraSocial();
    void buscarObraSocialPorNombre();
};
