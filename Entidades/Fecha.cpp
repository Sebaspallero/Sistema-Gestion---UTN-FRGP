#include "../EntidadesH/Fecha.h"
#include <iostream>
#include <string>

    //Constructores
    Fecha::Fecha() {
        _dia = 0;
        _mes = 0;
        _anio = 0;
    }

    Fecha::Fecha(int d, int m, int a) {
        _dia = d;
        _mes = m;
        _anio = a;
    }

    //Getters
    int Fecha::getDia() const{
        return _dia;
    }

    int Fecha::getMes() const{
        return _mes;
    }

    int Fecha::getAnio()const{
        return _anio;
    }

    //Setters
    void Fecha::setDia(int dia){
        _dia = dia;
    }

    void Fecha::setMes(int mes){
         _mes = mes;
    }

    void Fecha::setAnio(int anio){
    _anio = anio;
    }

    std::string Fecha:: toString() const {
        return std::to_string(_dia) + "/" + std::to_string(_mes) + "/" + std::to_string(_anio);
    }

    bool Fecha:: esIgual(const Fecha& otraFecha) const {
        return _dia == otraFecha._dia && _mes == otraFecha._mes && _anio == otraFecha._anio;
    }

    bool Fecha:: esAnterior(const Fecha& otraFecha) const {
        if (_anio != otraFecha._anio) return _anio < otraFecha._anio;
        if (_mes != otraFecha._mes) return _mes < otraFecha._mes;
        return _dia < otraFecha._dia;
    }
