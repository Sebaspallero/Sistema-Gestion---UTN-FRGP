#include "../ManagerH/ManagerBioquimico.h"
#include <iostream>

//Constructor
ManagerBioquimico::ManagerBioquimico(const std::string& nombreArchivo): Manager<Bioquimico>(nombreArchivo) {}

//ORDENAR POR APELLIDO - BURBUJA
std::vector<Bioquimico> ManagerBioquimico::ordenarPorApellido() {
    std::vector<Bioquimico> lista = leerTodos();
    for (int i = 0; i < (int)lista.size() - 1; i++) {
        for (int j = i + 1; j < (int)lista.size(); j++) {
            if (lista[i].getApellido() > lista[j].getApellido()) {
                Bioquimico aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }
    return lista;
}

//ORDENAR POR LEGAJO - BURBUJA
std::vector<Bioquimico> ManagerBioquimico::ordenarPorLegajo() {
    std::vector<Bioquimico> lista = leerTodos();
    for (int i = 0; i < (int)lista.size() - 1; i++) {
        for (int j = i + 1; j < (int)lista.size(); j++) {
            if (lista[i].getMatricula() > lista[j].getMatricula()) {
                Bioquimico aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }
    return lista;
}


Bioquimico ManagerBioquimico::buscarPorMatricula(int matricula,bool& encontro){
std::vector<Bioquimico> lista = leerTodos();
for(int i = 0;(int)i<lista.size();i++){
    if(lista[i].getMatricula()== matricula){
        encontro = true;
        return lista[i];
    }
}
    return Bioquimico();
}
