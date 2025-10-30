#include "../EntidadesH/Resultado.h"
#include "../EntidadesH/Fecha.h"
#include <iostream>
#include <cstring>

    //Getters
    int Resultado::getIDResultado() const{
        return _idResultado;
    }

    int Resultado::getIDTurno() const{
        return _idTurno;
    }

    std::string Resultado::getDescripcion() const{
        return std::string(_descripcion);
    }

    Fecha Resultado::getFecha(){
        return _fecha;
    }

    bool Resultado::getEstado(){
        return _estado;
    }

    //Setters
    void Resultado::setIDResultado(int idResultado){
        _idResultado = idResultado
    }

    void Resultado::setIDTurno(int idTurno){
        _idTurno = idTurno;
    }

    void Resultado::setDescripcion(set::string& descripcion){
        std::strncpy(_descripcion, descripcion.c_str(), sizeof(_descripcion) - 1);
        _descripcion[sizeof(_descripcion) - 1] = '\0';
    }

    void Resultado::getFecha(Fecha fecha){
        _fecha = fecha;
    }

    void Resultado::setEstado(bool estado){
        _estado = estado;
    }
