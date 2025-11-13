#pragma once
#include "../ManagerH/ManagerAnalisis.h"
class ServicioAnalisis{
    private:
        ManagerAnalisis _managerAnalisis;

    public:
        ServicioAnalisis();

        bool crearAnalisis();
        bool modificarAnalisis();
        bool eliminarAnalisis();
        void listarAnalisisActivos();
        void buscarPorCategoria();
        void listarPorNombre();
        void ordenarPorCategoria();
};
