#include "../EntidadesH/Fecha.h"
#include <iostream>

    //Constructores
    Fecha::Fecha(){};
    Fecha::Fecha(int dia,int mes,int anio): _dia(dia), _mes(mes), _anio(anio) {}

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

    bool Fecha::crearFecha(int dia, int mes, int anio){};
