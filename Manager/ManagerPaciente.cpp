#include "../ManagerH/ManagerPaciente.h"
#include <iostream>

//Constructor
ManagerPaciente::ManagerPaciente(const std::string& nombreArchivo) : Manager<Paciente>(nombreArchivo){}


//ORDENAR POR APELLIDO
std::vector<Paciente> ManagerPaciente::ordenarPorApellido() {
    std::vector<Paciente> lista = leerTodos();

    //Ordenamiento burbuja -> Comparamos un registro con otro y vemos cual es mas grande
    for (int i = 0; i < (int)lista.size() - 1; i++) {
        for (int j = i + 1; j < (int)lista.size(); j++) {
            std::string ap1 = lista[i].getApellido();
            std::string ap2 = lista[j].getApellido();
            if (ap1 > ap2) {
                Paciente aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }

    return lista;
}


//BUSCAR POR DNI
Paciente ManagerPaciente::buscarPorDNI(int dni) {
    std::vector<Paciente> lista = leerTodos();

    for (int i = 0; i < (int)lista.size(); i++) {
        if (lista[i].getDNI() == dni) {
            return lista[i];
        }
    }

    return Paciente(); // si no lo encuentra, devuelve vacío y en el menu gestionar con los atributos del constructor vacio (id = 0) mensaje de error
}

//BUSCAR POR APELLIDO
std::vector<Paciente> ManagerPaciente::buscarPorApellido(std::string apellido) {
    std::vector<Paciente> lista = leerTodos();
    std::vector<Paciente> resultados;

    for (int i = 0; i < (int)lista.size(); i++) {
        if (lista[i].getApellido() == apellido) {
            resultados.push_back(lista[i]); //Metemos el registro que encontramos al final del vector de resultado
        }
    }

    return resultados;
}

//BUSCAR POR OBRA SOCIAL
std::vector<Paciente> ManagerPaciente::buscarPorObraSocial(int idObraSocial) {
    std::vector<Paciente> lista = leerTodos();
    std::vector<Paciente> resultados;

    for (int i = 0; i < (int)lista.size(); i++) {
        if (lista[i].getCodigoObraSocial() == idObraSocial) {
            resultados.push_back(lista[i]); //Igual que arriba nada mas que por obra social -> reutilizar logica para toda busqueda con int
        }
    }

    return resultados;
}
