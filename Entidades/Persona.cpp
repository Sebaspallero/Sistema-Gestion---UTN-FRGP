#include <iostream>
#include "../EntidadesH/Persona.h"

int Persona::getID() const{return _id;};
std::string Persona::getNombre() const{return std::string(_nombre);};
std::string Persona::getApellido() const{return std::string(_apellido);};
Fecha Persona::getFechaNacimiento() const{return _fechaNacimiento;};
int Persona::getDNI() const{return _dni;};
std::string Persona::getEmail() const{return std::string(_email);};
bool Persona::getEstado() const{return _estado;};
void Persona::setID(int id){};
void Persona::setNombre(std::string& nombre){};
void Persona::setApellido(std::string& apellido){};
void Persona::setFechaNacimiento(Fecha fecha){};
void Persona::setDNI(int dni){};
void Persona::setEmail(std::string& email){};
void Persona::setEstado (bool estado){};
