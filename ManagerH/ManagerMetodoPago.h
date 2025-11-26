#pragma once
#include "Manager.h"
#include "../EntidadesH/MetodoDePago.h"
#include <vector>
#include <string>

class ManagerMetodoDePago : public Manager<MetodoDePago> {
public:
    ManagerMetodoDePago(const std::string& nombreArchivo);
};
