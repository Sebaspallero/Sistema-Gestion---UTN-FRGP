#include "../ManagerH/ManagerTurno.h"
#include <iostream>

// Constructor
ManagerTurno::ManagerTurno(const std::string& nombreArchivo) : Manager<Turno>(nombreArchivo) {}

// ORDENAR POR FECHA
std::vector<Turno> ManagerTurno::ordenarPorFecha() {
    std::vector<Turno> lista = leerTodos();
    for (int i = 0; i < (int)lista.size() - 1; i++) {
        for (int j = i + 1; j < (int)lista.size(); j++) {
            if (lista[i].getFechaTurno().esAnterior(lista[j].getFechaTurno())) {
                Turno aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }
    return lista;
}


// BUSCAR POR FECHA
std::vector<Turno> ManagerTurno::buscarPorFecha(int dia, int mes, int anio) {
    std::vector<Turno> lista = leerTodos();
    std::vector<Turno> resultado;

    for (int i = 0; i < (int)lista.size(); i++) {
        FechaHora fechaHora = lista[i].getFechaTurno();
        if (fechaHora.getDia() == dia && fechaHora.getMes() == mes && fechaHora.getAnio() == anio) {
            resultado.push_back(lista[i]);
        }
    }
    return resultado;
}

// BUSCAR POR PACIENTE
std::vector<Turno> ManagerTurno::buscarPorPaciente(int idPaciente) {
    std::vector<Turno> lista = leerTodos();
    std::vector<Turno> resultado;

    for (int i = 0; i < (int)lista.size(); i++) {
        if (lista[i].getIDPaciente() == idPaciente) {
            resultado.push_back(lista[i]);
        }
    }
    return resultado;
}

// BUSCAR POR BIOQUIMICO
std::vector<Turno> ManagerTurno::buscarPorBioquimico(int idBioquimico) {
    std::vector<Turno> lista = leerTodos();
    std::vector<Turno> resultado;

    for (int i = 0; i < (int)lista.size(); i++) {
        if (lista[i].getIDBioquimico() == idBioquimico) {
            resultado.push_back(lista[i]);
        }
    }
    return resultado;
}

//BUSCAR POR ASISTENCIA
std::vector<Turno> ManagerTurno::buscarPorAsistencia(){
    std::vector<Turno> lista = leerTodos();
    std::vector<Turno> resultado;

    for(int i = 0; i < (int)lista.size(); i++){
        if(lista[i].getAsistio() == true){
            resultado.push_back(lista[i]);
        }
    }

    return resultado;
}

