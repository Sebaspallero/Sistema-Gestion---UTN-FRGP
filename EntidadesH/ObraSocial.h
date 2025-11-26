#pragma once
#include <cstring>
#include <string>

class ObraSocial{
    private:
        int _id;
        char _nombre [30];
        float _descuento;
        bool _estado;

    public:
        ObraSocial();
        ObraSocial(int id, std::string nombre, float descuento);

        int getId() const;
        std::string getNombre() const;
        float getDescuento() const;
        bool getEstado() const;

        void setId(int idObraSocial);
        void setNombre(std::string& nombre);
        void setDescuento(float descuento);
        void setEstado(bool estado);
};
