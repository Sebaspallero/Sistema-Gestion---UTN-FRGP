#include "../EntidadesH/FechaHora.h"
#include <string>
#include <sstream>
#include <iomanip>

// Constructores
FechaHora::FechaHora() : Fecha() {
    _hora = 0;
    _minutos = 0;
}

FechaHora::FechaHora(int d, int m, int a, int hora, int minutos) : Fecha(d, m, a) {
    _hora = hora;
    _minutos = minutos;
}

// Getters
int FechaHora::getHora() const { return _hora; }
int FechaHora::getMinutos() const { return _minutos; }

// Setters
void FechaHora::setHora(int hora) { _hora = hora; }
void FechaHora::setMinutos(int minutos) { _minutos = minutos; }


std::string FechaHora::toString() const {
    std::ostringstream oss;

    oss << Fecha::toString() << " ";

    // Hora con 2 dígitos
    oss << std::setw(2) << std::setfill('0') << _hora
        << ":"
        // Minutos con 2 dígitos
        << std::setw(2) << std::setfill('0') << _minutos;

    return oss.str();
}

bool FechaHora::esIgual(const FechaHora& otraFecha) const {
    return Fecha::esIgual(otraFecha) &&
           _hora == otraFecha._hora &&
           _minutos == otraFecha._minutos;
}

bool FechaHora::esAnterior(const FechaHora& otraFecha) const {
    if (Fecha::esAnterior(otraFecha)) return true;
    if (Fecha::esIgual(otraFecha)) {
        if (_hora != otraFecha._hora) return _hora < otraFecha._hora;
        return _minutos < otraFecha._minutos;
    }
    return false;
}

