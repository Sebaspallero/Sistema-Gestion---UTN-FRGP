#include <iostream>
#include "../EntidadesH/Analisis.h"
#include <cstring>

int Analisis::getIDAnalisis() const{return _idAnalisis;}
std::string Analisis::getNombre() const{return std::string(_nombre);}
int Analisis::getIDCategoria() const{return _idCategoria;}
float Analisis::getValor() const{return _valor;}  //esta asociado con valor
bool Analisis::getEstado() const{return _estado;}
void Analisis::setIDAnalisis(int idAnalisis){}

void Analisis::setNombre(std::string& nombre){
strncpy(_nombre,nombre.c_str(),sizeof(_nombre)-1);
_nombre[sizeof(_nombre) - 1] = '\0';}

void Analisis::setIDCategoria(int idCategoria){}
void Analisis::setValor(float valor){}  //esta asociado con valor
void Analisis::setEstado(bool estado){}
