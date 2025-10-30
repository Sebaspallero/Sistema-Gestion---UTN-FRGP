# pragma once
#include <cstring>

class MetodoDePago{
    private:
        int _idMetodoPago;
        char _nombre [30];
        bool _estado;

    public:
        int getIDMetodoPago() const;
        std::string getNombre() const;
        bool getEstado() const;

        void setIDMetodoPago(int idMetodoPago);
        void setNombre(std::string& nombre);
        void setEstado(bool estado);
};
