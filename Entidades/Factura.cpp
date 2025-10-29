#include <iostream>
#include "../EntidadesH/Factura.h"

int Factura::getIDFactura()const{return _idFactura;};
int Factura::getIDPaciente()const{return _idPaciente;}
int Factura::getIDAnalisis()const{return _idAnalisis;};
int Factura::getIDMetodoPago()const{return _idMetodoPago;};
float Factura::getCostoFinal()const{return _costoFinal;};
Fecha Factura::getFechaPago()const{ return _fechaPago;};
bool Factura::getEstado()const{return _estado;};
void Factura::setIDFactura(int factura){};
void Factura::setIDPaciente(int paciente){};
void Factura::setIDAnalisis(int idAnalisis){};
void Factura::setIDMetodoPago(int IdPago){};
void Factura::setCostoFinal(float costoFinal){};
void Factura::setFechaPago(Fecha fechaPago){};
void Factura::setEstado(bool estado){};
