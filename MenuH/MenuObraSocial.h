#pragma once
#include "Menu.h"
#include "../ServicioH/ServicioObraSocial.h"

class MenuObraSocial : public Menu {
    private:
        ServicioObraSocial servicioObraSocial;

    public:
        MenuObraSocial();
        void ejecutar();
};
