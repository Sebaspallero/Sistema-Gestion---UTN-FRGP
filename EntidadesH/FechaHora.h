#pragma once
#include "Fecha.h"

class FechaHora : public Fecha{
    private:
        int _hora;
        int _minutos;

    public:
        FechaHora();
        FechaHora(int d, int m, int a, int h, int min);

        int getHora() const;
        int getMinutos() const;

        void setHora(int hora);
        void setMinutos(int minutos);

        std::string toString() const;
        bool esIgual(const FechaHora& otra) const;
        bool esAnterior(const FechaHora& otra) const;
};
