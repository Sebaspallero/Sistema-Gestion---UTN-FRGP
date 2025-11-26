#include "../EntidadesH/Analisis.h"
#include <iostream>
#include <cstring>

    //Cobtructores
    Analisis::Analisis() {
        _id = 0;
        std::strncpy(_nombre, "Sin Nombre", sizeof(_nombre) - 1);
        _nombre[sizeof(_nombre) - 1] = '\0';
        _idCategoria = 0;
        _valor = 0.0f;
        _estado = true;
    }

    Analisis::Analisis(int id, std::string nombre, int idCategoria, float valor) {
        _id = id;
        std::strncpy(_nombre, nombre.c_str(), sizeof(_nombre) - 1);
        _nombre[sizeof(_nombre) - 1] = '\0';
        _idCategoria = idCategoria;
        _valor = valor;
        _estado = true;
    }


    //Getters
    int Analisis::getId() const{
        return _id;
    }

    std::string Analisis::getNombre() const{
        return std::string(_nombre);
    }

    int Analisis::getIdCategoria() const{
        return _idCategoria;
    }

    float Analisis::getValor() const{
        return _valor; //esta asociado con valor
    }

    bool Analisis::getEstado() const{
        return _estado;
    }

    //Setters
    void Analisis::setId(int idAnalisis){
        _id = idAnalisis;
    }

    void Analisis::setNombre(std::string& nombre){
    strncpy(_nombre,nombre.c_str(),sizeof(_nombre)-1);
    _nombre[sizeof(_nombre) - 1] = '\0';}

    void Analisis::setIdCategoria(int idCategoria){
        _idCategoria = idCategoria;
    }

    void Analisis::setValor(float valor){
        _valor = valor; //esta asociado con valor
    }

    void Analisis::setEstado(bool estado){
        _estado = estado;
    }
