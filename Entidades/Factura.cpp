#include "../EntidadesH/Factura.h"
#include <iostream>

    //Contructores
    Factura::Factura() {
        _id = 0;
        _idPaciente = 0;
        _idAnalisis = 0;
        _idMetodoPago = 0;
        _idTurno = 0;
        _costoFinal = 0.0f;
        _fechaPago = Fecha();
        _estado = true;
    }

    Factura::Factura(int id, int idPaciente, int idAnalisis, int idMetodoPago, int idTurno, float costoFinal, Fecha fechaPago) {
        _id = id;
        _idPaciente = idPaciente;
        _idAnalisis = idAnalisis;
        _idMetodoPago = idMetodoPago;
        _idTurno = idTurno;
        _costoFinal = costoFinal;
        _fechaPago = fechaPago;
        _estado = true;
    }

    //Getters
    int Factura::getId()const{
        return _id;
    }

    int Factura::getIdPaciente()const{
        return _idPaciente;
    }

    int Factura::getIdAnalisis()const{
        return _idAnalisis;
    }

    int Factura::getIdMetodoPago()const{
        return _idMetodoPago;
    }

    int Factura::getIdTurno()const{
        return _idTurno;
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
    void Factura::setId(int idFactura){
        _id = idFactura;
    }

    void Factura::setIdPaciente(int idPaciente){
        _idPaciente = idPaciente;
    }

    void Factura::setIdAnalisis(int idAnalisis){
        _idAnalisis = idAnalisis;
    }

    void Factura::setIdMetodoPago(int idMetodoPago){
        _idMetodoPago = idMetodoPago;
    }

    void Factura::setIdTurno(int idTurno){
        _idTurno = idTurno;
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
