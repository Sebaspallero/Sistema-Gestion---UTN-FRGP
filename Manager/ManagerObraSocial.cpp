#include <iostream>
#include "../ManagerH/ManagerObraSocial.h"
ManagerObraSocial::ManagerObraSocial(std::string& nombreArchivo):Manager<ObraSocial>(nombreArchivo){}

ObraSocial ManagerObraSocial::buscarPorNombre(std::string& nombre){
    std::vector<ObraSocial> obrasSociales = leerTodos();
    for(int i = 0;i<obrasSociales.size();i++){
        if(obrasSociales[i].getNombre() == nombre){
            return obrasSociales[i];
        }
    }
    return ObraSocial();
}

bool ManagerObraSocial::crearObraSocial(std::string& nombre, float descuento){
    int id = obtenerNuevoId();
    ObraSocial obraSocial (id,nombre,descuento);
    return guardar(obraSocial);
}
bool ManagerObraSocial::modificarObraSocial(std::string& nombre, float descuento, int id){
    int posicion;
    posicion = buscar(id);
    if (posicion == -1) {
        return false;
    }
    ObraSocial obra_social = leer(posicion);
    obra_social.setNombre(nombre);
    obra_social.setDescuento(descuento);

    return modificar(obra_social,posicion);
}
