#pragma once
#include "Menu.h"
#include "../ServicioH/ServicioSala.h"

class MenuSala : public Menu {
    private:
        ServicioSala servicioSala;

    public:
        MenuSala();
        void ejecutar();
};
