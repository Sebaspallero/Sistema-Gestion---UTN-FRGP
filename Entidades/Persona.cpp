#include "../EntidadesH/Persona.h"
#include "../EntidadesH/Fecha.h"
#include <iostream>
#include <cstring>

    //Getters
    int Persona::getID() const{
        return _id;
    }

    std::string Persona::getNombre() const{
        return std::string(_nombre);
    }

    std::string Persona::getApellido() const{
        return std::string(_apellido);
    }

    Fecha Persona::getFechaNacimiento() const{
        return _fechaNacimiento;
    }

    int Persona::getDNI() const{
        return _dni;
    }

    std::string Persona::getEmail() const{
        return std::string(_email);
    }

    bool Persona::getEstado() const{
        return _estado;
    }

    //Setters
    void Persona::setID(int id){
        _id = id;
    }

    void Persona::setNombre(std::string& nombre){
        std::strncpy(_nombre, nombre.c_str(), sizeof(_nombre) - 1);
        _nombre[sizeof(_nombre) - 1] = '\0';
    }

    void Persona::setApellido(std::string& apellido){
        std::strncpy(_apellido, apellido.c_str(), sizeof(_apellido) - 1);
        _apellido[sizeof(_apellido) - 1] = '\0';
    }

    void Persona::setFechaNacimiento(Fecha fechaNacimiento){
        _fechaNacimiento = fechaNacimiento;
    }

    void Persona::setDNI(int dni){
        _dni = dni;
    }

    void Persona::setEmail(std::string& email){
        std::strncpy(_email, email.c_str(), sizeof(_email) - 1);
        _email[sizeof(_email) - 1] = '\0';
    }

    void Persona::setEstado (bool estado){
        _estado = estado;
    }
