#include "../ManagerH/ManagerResultado.h"
#include "../EntidadesH/Resultado.h"
#include "../EntidadesH/Fecha.h"
#include "../ManagerH/ManagerPaciente.h"
#include "../ManagerH/ManagerTurno.h"
#include <iostream>
#include <string>
#include <vector>

/// Constructor
ManagerResultado::ManagerResultado(const std::string& nombreArchivo) : Manager<Resultado>(nombreArchivo) {}

std::vector<Resultado> ManagerResultado::buscarPorPaciente(int idPaciente) {
    std::vector<Resultado> resultados;
    ManagerTurno managerTurnos("turnos.dat"); // Creamos un manager para leer turnos

    //Traer todos los turnos del paciente
    std::vector<Turno> listaTurnos = managerTurnos.buscarPorPaciente(idPaciente);

    //Si no hay turnos, devolvemos el vector vacío
    if (listaTurnos.size() == 0) {
        return resultados;
    }

    //Leemos todos los resultados guardados
    std::vector<Resultado> listaResultados = leerTodos();

    //Recorremos todos los resultados
    for (int i = 0; i < (int)listaResultados.size(); i++) {

        // Verificamos que esté activo
        if (listaResultados[i].getEstado() == false) {
            continue;
        }

        // Recorremos todos los turnos de ese paciente
        for (int j = 0; j < (int)listaTurnos.size(); j++) {

            // Si el resultado pertenece a alguno de esos turnos, lo agregamos
            if (listaResultados[i].getIDTurno() == listaTurnos[j].getId()) {
                resultados.push_back(listaResultados[i]);
                break; // salimos del for interno, ya encontramos su turno
            }
        }
    }

    return resultados;
}
