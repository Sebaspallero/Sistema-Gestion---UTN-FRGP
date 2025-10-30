#pragma once
#include "Fecha.h"

class Factura{
    private:
        int _idFactura;
        int _idPaciente;
        int _idAnalisis;
        int _idMetodoPago;
        float _costoFinal;
        Fecha _fechaPago;
        bool _estado;

    public:
        int getIDFactura() const;
        int getIDPaciente() const;
        int getIDAnalisis() const;
        int getIDMetodoPago() const;
        float getCostoFinal() const;
        Fecha getFechaPago() const;
        bool getEstado() const;

        void setIDFactura(int idFactura);
        void setIDPaciente(int idPaciente);
        void setIDAnalisis(int idAnalisis);
        void setIDMetodoPago(int IdMetodoPago);
        void setCostoFinal(float costoFinal);
        void setFechaPago(Fecha fechaPago);
        void setEstado(bool estado);
};
