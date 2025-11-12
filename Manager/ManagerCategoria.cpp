#include "../ManagerH/ManagerCategoria.h"
#include "../EntidadesH/Categoria.h"

// Constructor
ManagerCategoria::ManagerCategoria(const std::string& nombreArchivo) : Manager<Categoria>(nombreArchivo) {}



//BUSCAR POR NOMBRE
Categoria ManagerCategoria::buscarPorNombre(std::string nombre,bool& encontro) {
    std::vector<Categoria> lista = leerTodos();
    for (int i = 0; i < lista.size(); i++) {
        if (lista[i].getNombre() == nombre){
            encontro = true;
            return lista[i];

        }
    }
    return Categoria();
}






