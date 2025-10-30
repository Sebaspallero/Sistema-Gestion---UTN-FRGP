#pragma once
#include <string>

class Sala {
    private:
        int _idSala;
        char _nombre[20];
        int _piso;
        bool _disponible;
        bool _estado;

    public:
        Sala();
        Sala(int id, std::string& nombre, int piso, bool disponible);

        int getIDSala() const;
        std::string getNombre() const;
        int getPiso() const;
        bool getDisponible() const;
        bool getEstado() const;

        void setIDSala(int idSala);
        void setNombre(std::string& nombre);
        void setPiso(int piso);
        void setDisponible(bool disponible);
        void setEstado(bool estado);
};
