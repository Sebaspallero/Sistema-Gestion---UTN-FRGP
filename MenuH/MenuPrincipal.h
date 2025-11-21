#pragma once
#include "Menu.h"
#include "MenuAnalisis.h"
#include "MenuBioquimico.h"
#include "MenuCategoria.h"
#include "MenuFactura.h"
#include "MenuMetodoDePago.h"
#include "MenuObraSocial.h"
#include "MenuPaciente.h"
#include "MenuResultado.h"
#include "MenuSala.h"
#include "MenuTurno.h"
#include "MenuReporte.h"

class MenuPrincipal : public Menu {
    private:
        MenuSala menuSala;
        MenuObraSocial menuObraSocial;
        MenuPaciente menuPaciente;
        MenuBioquimico menuBioquimico;
        MenuAnalisis menuAnalisis;
        MenuMetodoDePago menuMetodoDePago;
        MenuCategoria menuCategoria;
        MenuFactura menuFactura;
        MenuResultado menuResultado;
        MenuTurno menuTurno;
        MenuReporte menuReporte;

    public:
        MenuPrincipal();
        void ejecutar();
};
