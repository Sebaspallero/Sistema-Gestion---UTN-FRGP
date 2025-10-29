#pragma once
#include "Fecha.h"
class Factura{
private:
    int _idFactura;
    int _idPaciente;
    int _idAnalisis;
    int _idMetodoPago;
    float _costoFinal;
    Fecha _fechaPago;
    bool _estado;
public:

    int getIDFactura()const;
    int getIDPaciente()const;
    int getIDAnalisis()const;
    int getIDMetodoPago()const;
    float getCostoFinal()const;
    Fecha getFechaPago()const;
    bool getEstado()const;
    void setIDFactura(int factura);
    void setIDPaciente(int paciente);
    void setIDAnalisis(int idAnalisis);
    void setIDMetodoPago(int IdPago);
    void setCostoFinal(float costoFinal);
    void setFechaPago(Fecha fechaPago);
    void setEstado(bool estado);
};
