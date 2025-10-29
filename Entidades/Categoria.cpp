#include <iostream>
#include "../EntidadesH/Categoria.h"
#include <cstring>

int Categoria::getIDCategoria() const{};
std::string Categoria::getNombre() const{return std::string(_nombre);};
bool Categoria::getEstado() const{};
void Categoria::setIDCategoria(int idCategoria){}
void Categoria::setNombre(std::string& nombre){
strncpy(_nombre,nombre.c_str(),sizeof(_nombre)-1);
_nombre[sizeof(_nombre) - 1] = '\0';};
void Categoria::setEstado(bool estado){};
