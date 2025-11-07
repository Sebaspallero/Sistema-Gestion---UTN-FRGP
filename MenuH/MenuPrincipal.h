#pragma once
#include "Menu.h"
#include "MenuSala.h"

class MenuPrincipal : public Menu {
private:
    MenuSala menuSala;
    //AGREGAR EL RESTO DE LOS MENUS CUANDO LOS CREEN
public:
    MenuPrincipal();
    void ejecutar();
};
