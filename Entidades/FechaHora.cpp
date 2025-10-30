#include "../EntidadesH/FechaHora.h"
#include <iostream>
#include <cstring>

    //Getters
    int getHora() const{
        return _hora;
    }
    int getMinutos() const{
        return _minutos;
    }

    //Setters
    void setHora(int hora){
        _hora = hora;
    }
    void setMinutos(int minutos){
        _minutos = minutos;
    }

    bool crearFechaTurno(int dia, int, mes, int anio, int hora, int minutos);
