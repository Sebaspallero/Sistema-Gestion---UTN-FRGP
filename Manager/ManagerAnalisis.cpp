#include "../ManagerH/ManagerAnalisis.h"
#include "../ServicioH/ServicioCategoria.h"
#include "../ManagerH/ManagerCategoria.h"
#include <iostream>
//Constructor
ManagerAnalisis::ManagerAnalisis(const std::string& nombreArchivo): Manager<Analisis>(nombreArchivo) {}

//ORDENAR POR CATEGORIA
std::vector<Analisis> ManagerAnalisis::ordenarPorCategoria() {
    std::vector<Analisis> lista = leerTodos();
    for (int i = 0; i < (int)lista.size() - 1; i++) {
        for (int j = i + 1; j < (int)lista.size(); j++) {
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
std::vector<Analisis> ManagerAnalisis::buscarPorNombre(std::string nombre) {
    std::vector<Analisis> lista = leerTodos();
    std::vector<Analisis> listaPorNombre = {};

    for (int i = 0; i < (int)lista.size(); i++) {
        if (lista[i].getNombre() == nombre){
                listaPorNombre.push_back(lista[i]);
        }
    }
    return listaPorNombre;}

//BUSCAR POR CATEGORIA
std::vector<Analisis> ManagerAnalisis::buscarPorCategoria(int idCategoria,bool& encontro) {
    std::vector<Analisis> lista = leerTodos();
    std::vector<Analisis> resultado;

    for (int i = 0; i < (int)lista.size(); i++) {
        if (lista[i].getIdCategoria() == idCategoria){
            encontro = true;
            resultado.push_back(lista[i]);
        }
    }
    return resultado;
}


void ManagerAnalisis::listarAnalisis(std::vector<Analisis> lista){
    ManagerCategoria managerCategoria("categorias.dat");
    bool encontro;
    if (lista.empty()){
        std::cout << "No hay análisis para mostrar."<<std::endl;
        return;
    }

    std::cout << "=== LISTA DE ANALISIS ==="<<std::endl;
    for (int i = 0; i < (int)lista.size(); i++){
        std::cout << "ID: " << lista[i].getId()
                  << " | Categoria: " << managerCategoria.buscarPorId(lista[i].getIdCategoria(),encontro)
                  << " | Nombre: " << lista[i].getNombre()
                  << " | Valor: $" << lista[i].getValor()
                  <<std::endl;
    }

}

