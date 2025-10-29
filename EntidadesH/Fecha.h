#pragma once

#pragma once
class Fecha {
private:
    int _dia, _mes, _anio;
public:
    Fecha();
    Fecha(int d,int m,int a);
    int  getDia()  const;
    int  getMes()  const;
    int  getAnio() const;
    void setDia(int d);
    void setMes(int m);
    void setAnio(int a);
    bool crearFecha(int dia, int mes, int anio);


};
