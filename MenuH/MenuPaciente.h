#pragma once
#include "Menu.h"
#include "../ServicioH/ServicioPaciente.h"

class MenuPaciente : public Menu {
    private:
        ServicioPaciente servicioPaciente;

    public:
        MenuPaciente();
        void ejecutar();
};
