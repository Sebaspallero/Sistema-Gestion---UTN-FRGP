#include "../EntidadesH/Factura.h"
#include <iostream>

    //Getters
    int Factura::getIDFactura()const{
        return _idFactura;
    }

    int Factura::getIDPaciente()const{
        return _idPaciente;
    }

    int Factura::getIDAnalisis()const{
        return _idAnalisis;
    }

    int Factura::getIDMetodoPago()const{
        return _idMetodoPago;
    }

    float Factura::getCostoFinal()const{
        return _costoFinal;
    }

    Fecha Factura::getFechaPago()const{
        return _fechaPago;
    }

    bool Factura::getEstado()const{
        return _estado;
    }

    //Setters
    void Factura::setIDFactura(int idFactura){
        _idFactura = idFactura;
    }

    void Factura::setIDPaciente(int idPaciente){
        _idPaciente = idPaciente;
    }

    void Factura::setIDAnalisis(int idAnalisis){
        _idAnalisis = idAnalisis;
    }

    void Factura::setIDMetodoPago(int idMetodoPago){
        _idMetodoPago = idMetodoPago;
    }

    void Factura::setCostoFinal(float costoFinal){
        _costoFinal = costoFinal;
    }

    void Factura::setFechaPago(Fecha fechaPago){
        _fechaPago = fechaPago;
    }

    void Factura::setEstado(bool estado){
        _estado = estado;
    }
