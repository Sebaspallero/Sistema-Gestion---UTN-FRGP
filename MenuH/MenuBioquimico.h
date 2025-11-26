#pragma once
#include "Menu.h"
#include "../ServicioH/ServicioBioquimico.h"

class MenuBioquimico : public Menu {
    private:
        ServicioBioquimico servicioBioquimico;

    public:
        MenuBioquimico();
        void ejecutar();
};
