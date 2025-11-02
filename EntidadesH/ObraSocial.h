#pragma once
#include <cstring>
#include <string>

class ObraSocial{
    private:
        int _id;
        char _nombre [30];
        int _descuento;
        bool _estado;

    public:
        ObraSocial();
        ObraSocial(int id, std::string nombre, int descuento);

        int getId() const;
        std::string getNombre() const;
        int getDescuento() const;
        bool getEstado() const;

        void setId(int idObraSocial);
        void setNombre(std::string& nombre);
        void setDescuento(int descuento);
        void setEstado(bool estado);
};
