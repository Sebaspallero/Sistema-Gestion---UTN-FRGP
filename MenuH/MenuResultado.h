#pragma once
#include "Menu.h"
#include "../ServicioH/ServicioResultado.h"

class MenuResultado : public Menu {
    private:
        ServicioResultado servicioResultado;

    public:
        MenuResultado();
        void ejecutar();
};
