#pragma once
#include "Fecha.h"

class Factura{
    private:
        int _id;
        int _idPaciente;
        int _idAnalisis;
        int _idMetodoPago;
        int _idTurno;
        float _costoFinal;
        Fecha _fechaPago;
        bool _estado;

    public:
        Factura();
        Factura(int id, int idPaciente, int idAnalisis, int idMetodoPago, int idTurno, float costoFinal, Fecha fechaPago);

        int getId() const;
        int getIdPaciente() const;
        int getIdAnalisis() const;
        int getIdMetodoPago() const;
        int getIdTurno() const;
        float getCostoFinal() const;
        Fecha getFechaPago() const;
        bool getEstado() const;

        void setId(int idFactura);
        void setIdPaciente(int idPaciente);
        void setIdAnalisis(int idAnalisis);
        void setIdMetodoPago(int IdMetodoPago);
        void setIdTurno(int idTurno);
        void setCostoFinal(float costoFinal);
        void setFechaPago(Fecha fechaPago);
        void setEstado(bool estado);
};
