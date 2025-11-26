#pragma once
#include "../ManagerH/ManagerCategoria.h"
#include <vector>

class ServicioCategoria{
    private:
        ManagerCategoria _managerCategoria;

    public:
        ServicioCategoria();

        void crearCategoria();
        void modificarCategoria();
        void eliminarCategoria();
        std::vector<Categoria> obtenerCategorias();
        void listarCategorias(const std::vector<Categoria>& categorias);
        void buscarPorNombre();
        std::string buscarPorId(int id);
};
