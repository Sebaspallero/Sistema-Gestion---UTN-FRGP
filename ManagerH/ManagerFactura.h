#pragma once
#include "Manager.h"
#include "../EntidadesH/Factura.h"
#include "../EntidadesH/Fecha.h"
#include <vector>
#include <string>

class ManagerFactura : public Manager<Factura> {
public:
    ManagerFactura(const std::string& nombreArchivo);

    std::vector<Factura> ordenarPorFechaDePago();
    std::vector<Factura> buscarPorMetodoDePago(int idMetodoDePago);
    std::vector<Factura> buscarPorFecha(Fecha fecha);
    std::vector<Factura> buscarPorPacienteID(int idPaciente);
    bool existeFacturaParaTurno(int idTurno);
};
