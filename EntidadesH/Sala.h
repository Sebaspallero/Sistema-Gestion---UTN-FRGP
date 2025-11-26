#pragma once
#include <string>

class Sala {
    private:
        int _id;
        char _nombre[20];
        int _piso;
        bool _disponible;
        bool _estado;

    public:
        Sala();
        Sala(int id, std::string& nombre, int piso, bool disponible);

        int getId() const;
        std::string getNombre() const;
        int getPiso() const;
        bool isDisponible() const;
        bool getEstado() const;

        void setId(int idSala);
        void setNombre(std::string& nombre);
        void setPiso(int piso);
        void setDisponible(bool disponible);
        void setEstado(bool estado);
};
