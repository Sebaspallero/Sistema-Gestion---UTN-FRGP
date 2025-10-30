#pragma once
#include "Fecha.h"

class Resultado{
    private:
        int _idResultado;
        int _idTurno;
        char _descripcion [100];
        Fecha _fecha;
        bool _estado;

    public:
        int getIDResultado() const;
        int getIDTurno() const;
        std::string getDescripcion() const;
        Fecha getFecha() const;
        bool getEstado() const;

        void setIDResultado(int idResultado);
        void setIDTurno(int idTurno);
        void setDescripcion(std::string& descripcion);
        void setFecha(Fecha fecha);
        void setEstado(bool estado);
};
