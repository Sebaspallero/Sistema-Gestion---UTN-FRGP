#include <iostream>
#include "../EntidadesH/Fecha.h"

Fecha::Fecha(){};
Fecha::Fecha(int d,int m,int a): _dia(d), _mes(m), _anio(a) {}
int  Fecha::getDia()  const { return _dia; }
int  Fecha::getMes()  const { return _mes; }
int  Fecha::getAnio() const { return _anio; }
void Fecha::setDia(int d)   { _dia = d; }
void Fecha::setMes(int m)   { _mes = m; }
void Fecha::setAnio(int a)  { _anio = a; }
bool Fecha::crearFecha(int dia, int mes, int anio){};
