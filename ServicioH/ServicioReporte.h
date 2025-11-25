#pragma once
#include "ServicioFactura.h"
#include "ServicioTurno.h"
#include "ServicioAnalisis.h"
#include "ServicioPaciente.h"
#include "ServicioObraSocial.h"
#include "ServicioMetodoDePago.h"
#include <vector>
#include <iostream>
#include <limits>

class ServicioReporte {
private:
    ServicioFactura _servicioFactura;
    ServicioTurno _servicioTurno;
    ServicioAnalisis _servicioAnalisis;
    ServicioPaciente _servicioPaciente;
    ServicioObraSocial _servicioObraSocial;
    ServicioMetodoDePago _servicioMetodoDePago;

    void limpiarBuffer() const;

public:
    ServicioReporte();

    void reporteRecaudacionMensual();
    void reporteCantidadPorAnalisis();
    void reporteRecaudacionPorMetodoPago();
    void reporteTurnosPorObraSocial();
    void reporteAsistenciaTurnos();
    void reporteFacturasPorObraSocial();
    void reporteRankingMetodoPago();
};
