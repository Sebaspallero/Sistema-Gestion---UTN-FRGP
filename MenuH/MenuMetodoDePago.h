#pragma once
#include "Menu.h"
#include "../ServicioH/ServicioMetodoDePago.h"

class MenuMetodoDePago : public Menu {
    private:
        ServicioMetodoDePago servicioMetodoDePago;

    public:
        MenuMetodoDePago();
        void ejecutar();
};
