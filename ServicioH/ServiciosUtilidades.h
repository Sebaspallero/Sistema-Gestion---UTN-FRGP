#pragma once
#include <cstring>
#include <string>
#include "../EntidadesH/Fecha.h"

int pedirEntero(const std::string& mensaje);
char pedirChar(const std::string& mensaje);
char pedirCharSN(const std::string& mensaje);
float pedirFloat(const std::string &mensaje);
std::string pedirString(const std::string& mensaje);
Fecha pedirFecha(const std::string& mensaje, int anioMin, int anioMax);
bool validarFecha(int dia, int mes, int anio);
void limpiarBuffer();

