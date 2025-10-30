#pragma once
#include "Fecha.h"
#include <cstring>

class Persona{
    private:
        int _id;
        char _nombre[30];
        char _apellido[30];
        Fecha _fechaNacimiento;
        int _dni;
        char _email[40];
        bool _estado;

    public:
        int getID() const;
        std::string getNombre() const;
        std::string getApellido() const;
        Fecha getFechaNacimiento() const;
        int getDNI() const;
        std::string getEmail() const;
        bool getEstado() const;

        void setID(int id);
        void setNombre(std::string& nombre);
        void setApellido(std::string& apellido);
        void setFechaNacimiento(Fecha fechaNacimiento);
        void setDNI(int dni);
        void setEmail(std::string& email);
        void setEstado (bool estado);
};
