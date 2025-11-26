#pragma once
#include "../ServicioH/ServicioCategoria.h"

class MenuCategoria : public Menu{
    private:
        ServicioCategoria _servicioCategoria;

    public:
        MenuCategoria();
        void ejecutar();
};
