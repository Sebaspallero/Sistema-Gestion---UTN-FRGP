#include <iostream>
#include "../ManagerH/ManagerSala.h"
#include "../EntidadesH/Sala.h"


ManagerSala::ManagerSala(std::string nombreArchivo) : Manager<Sala>(nombreArchivo){}


 Sala ManagerSala::buscarPorNombre(const std::string& nombre) {
    std::vector<Sala> lista = leerTodos();

    for (int i = 0; i < lista.size(); i++) {
        if (lista[i].getNombre() == nombre) {
            return lista[i];
        }
    }

    return Sala();
}

bool ManagerSala :: crearSala(std::string& nombre, int piso){
        int id = obtenerNuevoId();
        Sala sala(id, nombre, piso, true);
        return guardar(sala);
}

bool ManagerSala :: modificarSala(std::string& nombre, int piso, bool disponible, int id){
        int posicion;
        posicion = buscar(id);
        if (posicion == -1) {
            return false;
        }

        Sala sala = leer(posicion);

        sala.setNombre(nombre);
        sala.setPiso(piso);
        sala.setDisponible(disponible);

        return modificar(sala, posicion);

}
