#pragma once
#include "Manager.h"
#include "../EntidadesH/Analisis.h"
#include <vector>
#include <string>

class ManagerAnalisis : public Manager<Analisis> {
public:
    ManagerAnalisis(std::string nombreArchivo);

    std::vector<Analisis> ordenarPorCategoria();
    Analisis buscarPorNombre(std::string nombre);
    std::vector<Analisis> buscarPorCategoria(int idCategoria);

    bool crearAnalisis(std::string nombre, int idCategoria, float valor);
    bool modificarAnalisis(std::string nombre, int idCategoria, float valor, int id);
};
