#pragma once
#include "Manager.h"
#include "../EntidadesH/Factura.h"
#include <vector>
#include <string>

class ManagerFactura : public Manager<Factura> {
public:
    ManagerFactura(const std::string& nombreArchivo);

    std::vector<Factura> ordenarPorFechaDePago();
    std::vector<Factura> buscarPorMetodoDePago(int idMetodoDePago);
    std::vector<Factura> buscarPorFecha(int dia, int mes, int anio);
    std::vector<Factura> buscarPorPacienteID(int idPaciente);

    bool crearFactura(int idPaciente, int idAnalisis, int idMetodoDePago, float costoFinal, int dia, int mes, int anio);
    bool modificarFactura(int idPaciente, int idAnalisis, int idMetodoDePago, float costoFinal, int dia, int mes, int anio, int idFactura);
};
