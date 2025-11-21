#pragma once
#include "Manager.h"
#include "../EntidadesH/Analisis.h"
#include <vector>
#include <string>

class ManagerAnalisis : public Manager<Analisis> {
public:
    ManagerAnalisis(const std::string&nombreArchivo);

    std::vector<Analisis> ordenarPorCategoria();
    std::vector<Analisis> buscarPorNombre(std::string nombre);
    std::vector<Analisis> buscarPorCategoria(int idCategoria,bool& encontro);
    void listarAnalisis(std::vector<Analisis> lista);

};

