#include <iostream>
#include "../ManagerH/ManagerObraSocial.h"
ManagerObraSocial::ManagerObraSocial(const std::string& nombreArchivo):Manager<ObraSocial>(nombreArchivo){}

ObraSocial ManagerObraSocial::buscarPorNombre(std::string& nombre){
    std::vector<ObraSocial> obrasSociales = leerTodos();
    for(int i = 0; i < (int)obrasSociales.size();i++){
        if(obrasSociales[i].getNombre() == nombre){
            return obrasSociales[i];
        }
    }
    return ObraSocial();
}
