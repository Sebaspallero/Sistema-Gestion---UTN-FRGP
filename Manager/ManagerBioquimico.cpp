#include "../ManagerH/ManagerBioquimico.h"
#include <iostream>

//Constructor
ManagerBioquimico::ManagerBioquimico(std::string nombreArchivo): Manager<Bioquimico>(nombreArchivo) {}


//ORDENAR POR APELLIDO - BURBUJA
std::vector<Bioquimico> ManagerBioquimico::ordenarPorApellido() {
    std::vector<Bioquimico> lista = leerTodos();
    for (int i = 0; i < lista.size() - 1; i++) {
        for (int j = i + 1; j < lista.size(); j++) {
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
    for (int i = 0; i < lista.size() - 1; i++) {
        for (int j = i + 1; j < lista.size(); j++) {
            if (lista[i].getMatricula() > lista[j].getMatricula()) {
                Bioquimico aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }
    return lista;
}

//CREAR BIOQUIMICO
bool ManagerBioquimico::crearBioquimico(std::string nombre, std::string apellido, int dia, int mes, int anio, int dni, std::string email, int matricula) {
    int id = obtenerNuevoId();
    Fecha fechaNacimiento(dia, mes, anio);
    Bioquimico bioquimico(id, nombre, apellido, fechaNacimiento, dni, email, matricula);
    return guardar(bioquimico);
}

bool ManagerBioquimico::modificarBioquimico(std::string nombre, std::string apellido, int dia, int mes, int anio, int dni, std::string email, int matricula, int id) {
    int posicion;
    posicion = buscar(id);
    if (posicion == -1) {
        return false;
    }

    Bioquimico bioquimico = leer(posicion);
    Fecha fechaNacimiento(dia, mes, anio);

    bioquimico.setNombre(nombre);
    bioquimico.setApellido(apellido);
    bioquimico.setFechaNacimiento(fechaNacimiento);
    bioquimico.setEmail(email);
    bioquimico.setMatricula(matricula);

    return modificar(bioquimico, posicion);
}
