#pragma once
#include "../ManagerH/ManagerAnalisis.h"
#include "ServicioCategoria.h"

class ServicioAnalisis{
    private:
        ManagerAnalisis _managerAnalisis;
        ServicioCategoria _servicioCategoria;

    public:
        ServicioAnalisis();

        void crearAnalisis();
        void modificarAnalisis();
        void eliminarAnalisis();
        std::vector<Analisis> obtenerAnalisis();
        void listarAnalisis(const std::vector<Analisis>& analisis);
        void buscarPorCategoria();
        void listarPorNombre();
        void ordenarPorCategoria();
};
