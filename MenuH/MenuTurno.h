#pragma once
#include "Menu.h"
#include "../ServicioH/ServicioTurno.h"

class MenuTurno : public Menu {
    private:
        ServicioTurno servicioTurno;

    public:
        MenuTurno();
        void ejecutar();
};
