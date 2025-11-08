#include "../ManagerH/ManagerTurno.h"
#include <iostream>

// Constructor
ManagerTurno::ManagerTurno(std::string nombreArchivo) : Manager<Turno>(nombreArchivo) {}

// ORDENAR POR FECHA
std::vector<Turno> ManagerTurno::ordenarPorFecha() {
    std::vector<Turno> lista = leerTodos();
    for (int i = 0; i < lista.size() - 1; i++) {
        for (int j = i + 1; j < lista.size(); j++) {
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

    for (int i = 0; i < lista.size(); i++) {
        FechaHora fechaHora = lista[i].getFechaTurno();
        if (fechaHora.getDia() == dia && fechaHora.getMes() == mes && fechaHora.getAnio() == anio) {
            resultado.push_back(lista[i]);
        }
    }
    return resultado;
}

// BUSCAR POR PACIENTE -> ACA HAY QUE PRIMERO EN EL MENU USAR EL METODO DEL MANAGER PACIENTE PARA BUSCAR EL PACIENTE POR DNI Y LUEGO PASARLE EL ID DE ESE RESULTADO A ESTA FUNCION
std::vector<Turno> ManagerTurno::buscarPorPaciente(int idPaciente) {
    std::vector<Turno> lista = leerTodos();
    std::vector<Turno> resultado;

    for (int i = 0; i < lista.size(); i++) {
        if (lista[i].getIDPaciente() == idPaciente) {
            resultado.push_back(lista[i]);
        }
    }
    return resultado;
}

// BUSCAR POR BIOQUIMICO -> ACA HAY QUE PRIMERO EN EL MENU USAR EL METODO DEL MANAGER BIOQUIMICO PARA BUSCAR EL PACIENTE POR DNI Y LUEGO PASARLE EL ID DE ESE RESULTADO A ESTA FUNCION
std::vector<Turno> ManagerTurno::buscarPorBioquimico(int idBioquimico) {
    std::vector<Turno> lista = leerTodos();
    std::vector<Turno> resultado;

    for (int i = 0; i < lista.size(); i++) {
        if (lista[i].getIDBioquimico() == idBioquimico) {
            resultado.push_back(lista[i]);
        }
    }
    return resultado;
}

// CREAR TURNO - TAMBIEN HAY QUE LLAMAR A LOS OTROS METODOS DE LOS MANAGERS PARA OBETENER LOS IDS CORRESPONDIENTES
bool ManagerTurno::crearTurno(int idPaciente, int idBioquimico, int idAnalisis, int idSala, int minuto, int hora, int dia, int mes, int anio) {
    FechaHora fechaTurno(dia, mes, anio, hora, minuto);

    std::vector<Turno> lista = leerTodos();

    for(int i = 0; i < lista.size(); i++){
        if(lista[i].getFechaTurno().esIgual(fechaTurno) && lista[i].getIDSala() == idSala){
            std::cout << "Ya hay un turno asignado en esa fecha, hora y sala.\n";
            return false;
        }
    }

    int id = obtenerNuevoId();
    Turno turno(id, idPaciente, idBioquimico, idAnalisis, idSala, fechaTurno, false);
    return guardar(turno);
}

// MODIFICAR TURNO - TAMBIEN HAY QUE LLAMAR A LOS OTROS METODOS DE LOS MANAGERS PARA OBETENER LOS IDS CORRESPONDIENTES
bool ManagerTurno::modificarTurno(int idPaciente, int idBioquimico, int idAnalisis, int idSala, int minuto, int hora, int dia, int mes, int anio, bool asistio, int idTurno) {
    int posicion = buscar(idTurno);
    if (posicion == -1){
        return false;
    }

    FechaHora fechaTurno(dia, mes, anio, hora, minuto);

    std::vector<Turno> lista = leerTodos();
    for (int i = 0; i < lista.size(); i++) {
        if (lista[i].getId() != idTurno &&
            lista[i].getFechaTurno().esIgual(fechaTurno) &&
            lista[i].getIDSala() == idSala) {
            std::cout << "Ya hay un turno asignado en esa fecha, hora y sala.\n";
            return false;
        }
    }

    Turno turno = leer(posicion);

    turno.setIDPaciente(idPaciente);
    turno.setIDBioquimico(idBioquimico);
    turno.setIDAnalisis(idAnalisis);
    turno.setIDSala(idSala);
    turno.setFechaTurno(fechaTurno);
    turno.setAsistio(asistio);

    return modificar(turno, posicion);
}

// CONFIRMAR TURNO
bool ManagerTurno::confirmarTurno(int idTurno) {
    int posicion = buscar(idTurno);
    if (posicion == -1){
        return false;
    }
    Turno turno = leer(posicion);

    turno.setEstado(true);
    return modificar(turno, posicion);
}
