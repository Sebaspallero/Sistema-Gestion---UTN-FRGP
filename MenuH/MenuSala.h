#pragma once
#include "Menu.h"
#include "../ManagerH/ManagerSala.h"

class MenuSala : public Menu {
private:
    ManagerSala manager;
public:
    MenuSala();
    void ejecutar();
};
