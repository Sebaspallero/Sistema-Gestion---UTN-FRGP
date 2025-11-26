#include "../EntidadesH/Turno.h"
#include "../EntidadesH/FechaHora.h"


    //constructores

    Turno::Turno() {
        _id = 0;
        _idPaciente = 0;
        _idBioquimico = 0;
        _idAnalisis = 0;
        _idSala = 0;
        _fechaTurno = FechaHora();
        _asistio = false;
        _estado = true;
    }

    Turno::Turno(int id, int idPaciente, int idBioquimico, int idAnalisis, int idSala, FechaHora fechaTurno, bool asistio) {
        _id = id;
        _idPaciente = idPaciente;
        _idBioquimico = idBioquimico;
        _idAnalisis = idAnalisis;
        _idSala = idSala;
        _fechaTurno = fechaTurno;
        _asistio = asistio;
        _estado = true;
    }

    // Getters
    int Turno :: getId() const{
        return _id;
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

    bool Turno::getEstado() const{
        return _estado;
    }

    // Setters
    void Turno::setId(int idTurno){
        _id = idTurno;
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

    void Turno::setFechaTurno(FechaHora fechaTurno){
        _fechaTurno = fechaTurno;
    }

    void Turno::setAsistio(bool asistio){
        _asistio = asistio;
    }

    void Turno::setEstado(bool estado){
        _estado = estado;
    }
