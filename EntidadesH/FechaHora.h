#pragma once
#include "Fecha.h"

class FechaHora : public Fecha{
    private:
        int _hora;
        int _minutos;

    public:
        int getHora() const;
        int getMinutos() const;

        void setHora(int hora);
        void setMinutos(int minutos);

        bool crearFechaTurno(int dia, int, mes, int anio, int hora, int minutos);
};
