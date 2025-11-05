#include "../EntidadesH/Sala.h"
#include <iostream>
#include <cstring>

    //Constructores
    Sala :: Sala(){
        _id = 0;
        std::strncpy(_nombre, "Sin Nombre", sizeof(_nombre) - 1);
        _nombre[sizeof(_nombre) - 1] = '\0';
        _piso = 0;
        _disponible = false;
        _estado = true;
    }

    Sala :: Sala(int id, std::string& nombre, int piso, bool disponible){
        _id = id;
         std::strncpy(_nombre, nombre.c_str(), sizeof(_nombre) - 1);
         _nombre[sizeof(_nombre) - 1] = '\0';
        _piso = piso;
        _disponible = disponible;
        _estado = true;
    }

    // Getters
    int Sala :: getId() const{
        return _id;
    }

    std::string Sala :: getNombre() const{
        return std::string(_nombre);
    }

    int Sala :: getPiso() const{
        return _piso;
    }

    bool Sala :: isDisponible() const{
        return _disponible;
    }

    bool Sala :: getEstado() const {
        return _estado;
    }

    // Setters
    void Sala :: setNombre(std::string& nombre){
        std::strncpy(_nombre, nombre.c_str(), sizeof(_nombre) - 1);
        _nombre[sizeof(_nombre) - 1] = '\0';
    }

    void Sala :: setPiso(int piso){
        _piso = piso;
    }

    void Sala :: setDisponible(bool disponible){
        _disponible = disponible;
    }

    void Sala :: setId(int id) {
        _id = id;
    }

    void Sala :: setEstado(bool estado) {
        _estado = estado;
    }
