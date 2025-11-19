#pragma once
#include "Menu.h"
#include "../ServicioH/ServicioFactura.h"

class MenuFactura : public Menu {
    private:
        ServicioFactura servicioFactura;

    public:
        MenuFactura();
        void ejecutar();
};
