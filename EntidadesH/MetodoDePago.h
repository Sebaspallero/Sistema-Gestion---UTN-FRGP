# pragma once
#include <cstring>
#include <string>

class MetodoDePago{
    private:
        int _id;
        char _nombre [30];
        bool _estado;

    public:
        MetodoDePago();
        MetodoDePago(int id, std::string nombre);

        int getId() const;
        std::string getNombre() const;
        bool getEstado() const;

        void setId(int idMetodoPago);
        void setNombre(std::string& nombre);
        void setEstado(bool estado);
};
