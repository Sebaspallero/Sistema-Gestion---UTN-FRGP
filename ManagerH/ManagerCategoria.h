#pragma once
#include "Manager.h"
#include "../EntidadesH/Categoria.h"
#include <vector>
#include <string>

class ManagerCategoria : public Manager<Categoria> {
public:
    ManagerCategoria(const std::string& nombreArchivo);

    Categoria buscarPorNombre(std::string nombre);
    bool crearCategoria(std::string nombre);
    bool modificarCategoria(std::string nombre, int id);
};
