#include <iostream>
#include "../EntidadesH/Persona.h"

int Persona::getID() const{};
std::string Persona::getNombre() const{};
std::string Persona::getApellido() const{};
Fecha Persona::getFechaNacimiento() const{};
int Persona::getDNI() const{};
std::string Persona::getEmail() const{};
bool Persona::getEstado() const{};
void Persona::setID(int id){};
void Persona::setNombre(std::string& nombre){};
void Persona::setApellido(std::string& apellido){};
void Persona::setFechaNacimiento(Fecha fecha){};
void Persona::setDNI(int dni){};
void Persona::setEmail(std::string& email){};
void Persona::setEstado (bool estado){};
