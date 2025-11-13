#pragma once
#include "Menu.h"
#include "../ServicioH/ServicioAnalisis.h"

class MenuAnalisis : public Menu{
    private:

        ServicioAnalisis _servicioAnalisis;
    public:
        MenuAnalisis();
        void ejecutar();
};
