#pragma once
#include <cstring>
#include <string>

class Fecha{
    private:
        int _dia, _mes, _anio;

    public:
        Fecha();
        Fecha(int d,int m,int a);

        int  getDia() const;
        int  getMes() const;
        int  getAnio() const;

        void setDia(int dia);
        void setMes(int mes);
        void setAnio(int anio);

        std::string toString() const;
        bool esIgual(const Fecha& otraFecha) const;
        bool esAnterior(const Fecha& otra) const;
};
