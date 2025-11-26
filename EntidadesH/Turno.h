#pragma once
#include "FechaHora.h"

class Turno{
    private:
        int _id;
        int _idPaciente;
        int _idBioquimico;
        int _idAnalisis;
        int _idSala;
        FechaHora _fechaTurno;
        bool _asistio;
        bool _estado;

    public:
       Turno();
       Turno(int id, int idPaciente, int idBioquimico, int idAnalisis, int idSala, FechaHora fechaTurno, bool asistio);

       int getId() const;
       int getIDPaciente() const;
       int getIDBioquimico() const;
       int getIDAnalisis() const;
       int getIDSala() const;
       FechaHora getFechaTurno() const;
       bool getAsistio() const;
       bool getEstado() const;

       void setId(int idTurno);
       void setIDPaciente(int idPaciente);
       void setIDBioquimico(int idBioquimico);
       void setIDAnalisis(int idAnalisis);
       void setIDSala(int idSala);
       void setFechaTurno(FechaHora fechaTurno);
       void setAsistio(bool asistio);
       void setEstado(bool estado);
};
