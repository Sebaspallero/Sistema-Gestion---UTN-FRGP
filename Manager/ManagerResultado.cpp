#include "../ManagerH/ManagerResultado.h"
#include "../EntidadesH/Resultado.h"
#include "../EntidadesH/Fecha.h"
#include <iostream>
#include <string>

/// Constructor
///ManagerResultado::ManagerResultado(std::string nombreArchivo) : Manager<Resultado>(nombreArchivo) {}


///BUSCAR POR PACIENTE ---> Falta implementar.


//CREAR RESULTADO
bool ManagerResultado::crearResultado(int idTurno, std::string descripcion, int dia, int mes, int anio) {
    int id = obtenerNuevoId();
    Fecha fechaCarga(dia, mes, anio);

    Resultado resultado (id, idTurno, descripcion, fechaCarga);

    return guardar(resultado);
}


//MODIFICAR RESULTADO
bool ManagerResultado::modificarResultado(int idTurno, std::string descripcion, int dia, int mes, int anio, int id) {
    int posicion;
    posicion = buscar(id);
    if (posicion == -1) {
        return false;
    }

    Resultado resultado = leer(posicion);
    Fecha fechaCarga(dia, mes, anio);

    resultado.setIDTurno(idTurno);
    resultado.setDescripcion(descripcion);
    resultado.setFecha(fechaCarga);

    return modificar(resultado, posicion);
}
