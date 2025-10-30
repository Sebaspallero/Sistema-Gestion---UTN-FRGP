#include "../EntidadesH/Turno.h"
#include "../EntidadesH/FechaHora.h"

    // Getters
    int Turno :: getIDTurno() const{
        return _idTurno;
    }

    int Turno::getIDPaciente() const{
        return _idPaciente;
    }

    int Turno::getIDBioquimico() const{
        return _idBioquimico;
    }

    int Turno::getIDAnalisis() const{
        return _idAnalisis;
    }

    int Turno::getIDSala() const{
        return _idSala;
    }

    FechaHora Turno::getFechaTurno() const{
        return _fechaTurno;
    }

    bool Turno::getAsistio() const{
        return _asistio;
    }

    bool Turno::setEstado() const{
        return _estado;
    }

    // Setters
    void Turno::setIDTurno(int idTurno){
        _idTurno = idTurno;
    }

    void Turno::setIDPaciente(int idPaciente){
        _idPaciente = idPaciente;
    }

    void Turno::setIDBioquimico(int idBioquimico){
        _idBioquimico = idBioquimico;
    }

    void Turno::setIDAnalisis(int idAnalisis){
        _idAnalisis = idAnalisis;
    }

    void Turno::setIDSala(int idSala){
        _idSala = idSala;
    }

    void setFechaTurno(FechaHora fechaTurno){
        _fechaTurno = fechaTurno;
    }

    void setAsistio(bool asistio){
        _asistio = asistio;
    }

    void setEstado(bool estado){
        _estado = estado;
    }
