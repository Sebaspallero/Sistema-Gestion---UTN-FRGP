#include <iostream>
#include "../EntidadesH/Categoria.h"
#include <cstring>

int Categoria::getIDCategoria() const{return _idCategoria;};
std::string Categoria::getNombre() const{return std::string(_nombre);};
bool Categoria::getEstado() const{return _estado;};
void Categoria::setIDCategoria(int idCategoria){}
void Categoria::setNombre(std::string& nombre){
strncpy(_nombre,nombre.c_str(),sizeof(_nombre)-1);
_nombre[sizeof(_nombre) - 1] = '\0';};
void Categoria::setEstado(bool estado){};
