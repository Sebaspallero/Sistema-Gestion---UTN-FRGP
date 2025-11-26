#pragma once
#include "Menu.h"
#include "../ServicioH/ServicioReporte.h"

class MenuReporte : public Menu {
    private:
        ServicioReporte servicioReporte;

    public:
        MenuReporte();
        void ejecutar();
};
