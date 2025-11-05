#include "../ManagerH/ManagerMetodoPago.h"
#include "../EntidadesH/MetodoDePago.h"

// Constructor
ManagerMetodoDePago::ManagerMetodoDePago(std::string nombreArchivo) : Manager<MetodoDePago>(nombreArchivo) {}


//CREAR METODO DE PAGO
bool ManagerMetodoDePago::crearMetodoDePago(std::string nombre) {
    int id = obtenerNuevoId();
    MetodoDePago metodoPago (id, nombre);
    return guardar(metodoPago);
}


//MODIFICAR CATEGORIA
bool ManagerMetodoDePago::modificarMetodoDePago(std::string nombre, int id) {
    int posicion;
    posicion = buscar(id);
    if (posicion == -1) {
        return false;
    }

    MetodoDePago metodoPago = leer(posicion);
    metodoPago.setNombre(nombre);

    return modificar(metodoPago, posicion);
}
