#include "../EntidadesH/Persona.h"
#include "../EntidadesH/Fecha.h"
#include <iostream>
#include <cstring>

    //Constructores
    Persona::Persona() {
        _id = 0;
        std::strncpy(_nombre, "Sin Nombre", sizeof(_nombre) - 1);
        _nombre[sizeof(_nombre) - 1] = '\0';
        std::strncpy(_apellido, "Sin Apellido", sizeof(_apellido) - 1);
        _apellido[sizeof(_apellido) - 1] = '\0';
        _fechaNacimiento = Fecha();
        _dni = 0;
        std::strncpy(_email, "sinemail@ejemplo.com", sizeof(_email) - 1);
        _email[sizeof(_email) - 1] = '\0';
        _estado = true;
    }

    Persona::Persona(int id, std::string nombre, std::string apellido, Fecha fechaNacimiento, int dni, std::string email) {
        _id = id;
        std::strncpy(_nombre, nombre.c_str(), sizeof(_nombre) - 1);
        _nombre[sizeof(_nombre) - 1] = '\0';
        std::strncpy(_apellido, apellido.c_str(), sizeof(_apellido) - 1);
        _apellido[sizeof(_apellido) - 1] = '\0';
        _fechaNacimiento = fechaNacimiento;
        _dni = dni;
        std::strncpy(_email, email.c_str(), sizeof(_email) - 1);
        _email[sizeof(_email) - 1] = '\0';
        _estado = true;
    }

    //Getters
    int Persona::getId() const{
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
    void Persona::setId(int id){
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
