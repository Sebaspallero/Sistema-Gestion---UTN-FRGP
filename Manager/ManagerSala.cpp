#include <iostream>
#include "../ManagerH/ManagerSala.h"
#include "../EntidadesH/Sala.h"


ManagerSala::ManagerSala(const std::string& nombreArchivo) : Manager<Sala>(nombreArchivo){}


Sala ManagerSala::buscarPorNombre(const std::string& nombre) {
    std::vector<Sala> lista = leerTodos();

    for (int i = 0; i < (int)lista.size(); i++) {
        if (lista[i].getNombre() == nombre) {
            return lista[i];
        }
    }

    return Sala();
}
