#include "../ManagerH/ManagerCategoria.h"
#include "../EntidadesH/Categoria.h"

// Constructor
ManagerCategoria::ManagerCategoria(std::string nombreArchivo) : Manager<Categoria>(nombreArchivo) {}


//BUSCAR POR NOMBRE
Categoria ManagerCategoria::buscarPorNombre(std::string nombre) {
    std::vector<Categoria> lista = leerTodos();
    for (int i = 0; i < lista.size(); i++) {
        if (lista[i].getNombre() == nombre){
            return lista[i];
        }
    }
    return Categoria();
}


//CREAR CATEGORÍA
bool ManagerCategoria::crearCategoria(std::string nombre) {
    int id = obtenerNuevoId();
    Categoria categoria (id, nombre);
    return guardar(categoria);
}


//MODIFICAR CATEGORIA
bool ManagerCategoria::modificarCategoria(std::string nombre, int id) {
    int posicion;
    posicion = buscar(id);
    if (posicion == -1) {
        return false;
    }

    Categoria categoria = leer(posicion);
    categoria.setNombre(nombre);

    return modificar(categoria, posicion);
}
