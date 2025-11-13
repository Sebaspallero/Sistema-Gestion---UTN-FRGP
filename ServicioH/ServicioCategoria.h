#pragma once
#include "../ManagerH/ManagerCategoria.h"
#include <vector>

class ServicioCategoria{
    private:
        ManagerCategoria _managerCategoria;

    public:
        ServicioCategoria();

        bool crearCategoria();
        bool modificarCategoria();
        bool eliminarCategoria();
        void listarCategoriasActivas();
        void buscarPorNombre();
        std::vector<Categoria> obtenerCategoriasActivas();
};
