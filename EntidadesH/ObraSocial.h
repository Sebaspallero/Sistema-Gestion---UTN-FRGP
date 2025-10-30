#pragma once
#include <cstring>

class ObraSocial{
    private:
        int _idObraSocial;
        char _nombre [30];
        int _descuento;
        bool _estado;

    public:
        int getIDObraSocial() const;
        std::string getNombre() const;
        int getDescuento() const;
        bool getEstado() const;

        void setIDObraSocial(int idObraSocial);
        void setNombre(std::string& nombre);
        void setDescuento(int descuento);
        void setEstado(bool estado);
};
