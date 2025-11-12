#pragma once
#include "Menu.h"
#include "MenuSala.h"
#include "MenuObraSocial.h"
#include "MenuPaciente.h"
#include "MenuBioquimico.h"
#include "MenuCategoria.h"
#include "MenuAnalisis.h"

class MenuPrincipal : public Menu {
private:
    MenuSala menuSala;
    MenuObraSocial menuObraSocial;
    MenuPaciente menuPaciente;
    MenuBioquimico menuBioquimico;
    MenuAnalisis menuAnalisis;
    //AGREGAR EL RESTO DE LOS MENUS CUANDO LOS CREEN
    MenuCategoria menuCategoria;
public:
    MenuPrincipal();
    void ejecutar();
};
