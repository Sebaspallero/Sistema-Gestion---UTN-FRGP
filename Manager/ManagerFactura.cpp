#include "../ManagerH/ManagerFactura.h"

// Constructor
ManagerFactura::ManagerFactura(const std::string& nombreArchivo) : Manager<Factura>(nombreArchivo) {}

// ORDENAR POR FECHA DE PAGO
std::vector<Factura> ManagerFactura::ordenarPorFechaDePago() {
    std::vector<Factura> lista = leerTodos();
    for (int i = 0; i < lista.size() - 1; i++) {
        for (int j = i + 1; j < lista.size(); j++) {
            if (lista[j].getFechaPago().esAnterior(lista[i].getFechaPago())) {
                Factura aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }
    return lista;
}

// BUSCAR POR MÉTODO DE PAGO
std::vector<Factura> ManagerFactura::buscarPorMetodoDePago(int idMetodoDePago) {
    std::vector<Factura> lista = leerTodos();
    std::vector<Factura> resultado;

    for (int i = 0; i < lista.size(); i++) {
        if (lista[i].getIdMetodoPago() == idMetodoDePago) {
            resultado.push_back(lista[i]);
        }
    }
    return resultado;
}

// BUSCAR POR FECHA
std::vector<Factura> ManagerFactura::buscarPorFecha(int dia, int mes, int anio) {
    std::vector<Factura> lista = leerTodos();
    std::vector<Factura> resultado;

    for (int i = 0; i < lista.size(); i++) {
        Fecha f = lista[i].getFechaPago();
        if (f.getDia() == dia && f.getMes() == mes && f.getAnio() == anio) {
            resultado.push_back(lista[i]);
        }
    }
    return resultado;
}

// BUSCAR POR PACIENTE - PEDIR EN EL MENU EL DNI DEL PACIENTE Y CON EL MANAGER DE PACIENTE BUSCAR POR DNI EL PACIENTE Y SACAR EL ID
std::vector<Factura> ManagerFactura::buscarPorPacienteID(int idPaciente) {
    std::vector<Factura> lista = leerTodos();
    std::vector<Factura> resultado;

    for (int i = 0; i < lista.size(); i++) {
        if (lista[i].getIdPaciente() == idPaciente) {
            resultado.push_back(lista[i]);
        }
    }
    return resultado;
}

// CREAR FACTURA
bool ManagerFactura::crearFactura(int idPaciente, int idAnalisis, int idMetodoDePago, float costoFinal, int dia, int mes, int anio) {
    int id = obtenerNuevoId();
    Fecha fechaPago(dia, mes, anio);
    Factura factura(id, idPaciente, idAnalisis, idMetodoDePago, costoFinal, fechaPago);
    return guardar(factura);
}

// MODIFICAR FACTURA
bool ManagerFactura::modificarFactura(int idPaciente, int idAnalisis, int idMetodoDePago, float costoFinal, int dia, int mes, int anio, int idFactura) {
    int posicion = buscar(idFactura);
    if (posicion == -1) {
        return false;
    }

    Factura factura = leer(posicion);
    Fecha fechaPago(dia, mes, anio);

    factura.setIdPaciente(idPaciente);
    factura.setIdAnalisis(idAnalisis);
    factura.setIdMetodoPago(idMetodoDePago);
    factura.setCostoFinal(costoFinal);
    factura.setFechaPago(fechaPago);

    return modificar(factura, posicion);
}
