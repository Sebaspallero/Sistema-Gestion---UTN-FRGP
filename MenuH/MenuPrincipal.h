#pragma once
#include "Menu.h"
#include "MenuSala.h"
#include "MenuObraSocial.h"
#include "MenuPaciente.h"
#include "MenuBioquimico.h"

class MenuPrincipal : public Menu {
private:
    MenuSala menuSala;
    MenuObraSocial menuObraSocial;
    MenuPaciente menuPaciente;
    MenuBioquimico menuBioquimico;
    //AGREGAR EL RESTO DE LOS MENUS CUANDO LOS CREEN
public:
    MenuPrincipal();
    void ejecutar();
};
