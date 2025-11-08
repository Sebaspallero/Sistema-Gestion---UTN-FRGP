#include "../ManagerH/ManagerAnalisis.h"

//Constructor
ManagerAnalisis::ManagerAnalisis(std::string nombreArchivo): Manager<Analisis>(nombreArchivo) {}

//ORDENAR POR CATEGORIA
std::vector<Analisis> ManagerAnalisis::ordenarPorCategoria() {
    std::vector<Analisis> lista = leerTodos();
    for (int i = 0; i < lista.size() - 1; i++) {
        for (int j = i + 1; j < lista.size(); j++) {
            if (lista[i].getIdCategoria() > lista[j].getIdCategoria()) {
                Analisis aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }
    return lista;
}

//BUSACR POR NOMBRE
Analisis ManagerAnalisis::buscarPorNombre(std::string nombre) {
    std::vector<Analisis> lista = leerTodos();
    for (int i = 0; i < lista.size(); i++) {
        if (lista[i].getNombre() == nombre){
            return lista[i];
        }
    }
    return Analisis();}

//BUSCAR POR CATEGORIA
std::vector<Analisis> ManagerAnalisis::buscarPorCategoria(int idCategoria) {
    std::vector<Analisis> lista = leerTodos();
    std::vector<Analisis> resultado;

    for (int i = 0; i < lista.size(); i++) {
        if (lista[i].getIdCategoria() == idCategoria){
            resultado.push_back(lista[i]);
        }
    }
    return resultado;
}

//CREAR ANALISIS
bool ManagerAnalisis::crearAnalisis(std::string nombre, int idCategoria, float valor) {
    int id = obtenerNuevoId();
    Analisis analisis(id, nombre, idCategoria, valor);
    return guardar(analisis);
}

//MODIFICAR ANALISIS
bool ManagerAnalisis::modificarAnalisis(std::string nombre, int idCategoria, float valor, int id) {
    int posicion;
    posicion = buscar(id);
    if (posicion == -1) {
        return false;
    }

    Analisis analisis = leer(posicion);
    analisis.setNombre(nombre);
    analisis.setIdCategoria(idCategoria);
    analisis.setValor(valor);
    return modificar(analisis, posicion);
}
