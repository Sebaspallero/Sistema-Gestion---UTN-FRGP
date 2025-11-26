#include "../EntidadesH/Resultado.h"
#include "../EntidadesH/Fecha.h"
#include <iostream>
#include <cstring>

    //Constructores

    Resultado::Resultado() {
        _id = 0;
        _idTurno = 0;
        std::strncpy(_descripcion, "Sin descripción", sizeof(_descripcion) - 1);
        _descripcion[sizeof(_descripcion) - 1] = '\0';
        _fecha = Fecha();
        _estado = true;
    }

    Resultado::Resultado(int id, int idTurno, std::string descripcion, Fecha fecha) {
        _id = id;
        _idTurno = idTurno;
        std::strncpy(_descripcion, descripcion.c_str(), sizeof(_descripcion) - 1);
        _descripcion[sizeof(_descripcion) - 1] = '\0';
        _fecha = fecha;
        _estado = true;
    }

    //Getters
    int Resultado::getId() const{
        return _id;
    }

    int Resultado::getIDTurno() const{
        return _idTurno;
    }

    std::string Resultado::getDescripcion() const{
        return std::string(_descripcion);
    }

    Fecha Resultado::getFecha() const{
        return _fecha;
    }

    bool Resultado::getEstado() const{
        return _estado;
    }

    //Setters
    void Resultado::setId(int idResultado){
        _id = idResultado;
    }

    void Resultado::setIDTurno(int idTurno){
        _idTurno = idTurno;
    }

    void Resultado::setDescripcion(std::string& descripcion){
        std::strncpy(_descripcion, descripcion.c_str(), sizeof(_descripcion) - 1);
        _descripcion[sizeof(_descripcion) - 1] = '\0';
    }

    void Resultado::setFecha(Fecha fecha){
        _fecha = fecha;
    }

    void Resultado::setEstado(bool estado){
        _estado = estado;
    }
