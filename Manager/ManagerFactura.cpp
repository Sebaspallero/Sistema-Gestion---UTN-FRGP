#include "../ManagerH/ManagerFactura.h"

// Constructor
ManagerFactura::ManagerFactura(const std::string& nombreArchivo) : Manager<Factura>(nombreArchivo) {}

// ORDENAR POR FECHA DE PAGO
std::vector<Factura> ManagerFactura::ordenarPorFechaDePago() {
    std::vector<Factura> lista = leerTodos();
    for (int i = 0; i < (int)lista.size() - 1; i++) {
        for (int j = i + 1; j < (int)lista.size(); j++) {
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

    for (int i = 0; i < (int)lista.size(); i++) {
        if (lista[i].getIdMetodoPago() == idMetodoDePago) {
            resultado.push_back(lista[i]);
        }
    }
    return resultado;
}

// BUSCAR POR FECHA
std::vector<Factura> ManagerFactura::buscarPorFecha(Fecha fecha) {
    std::vector<Factura> lista = leerTodos();
    std::vector<Factura> resultado;

    for (int i = 0; i < (int)lista.size(); i++) {
        Fecha f = lista[i].getFechaPago();
        if (f.esIgual(fecha)) {
            resultado.push_back(lista[i]);
        }
    }
    return resultado;
}

// BUSCAR POR PACIENTE - PEDIR EN EL MENU EL DNI DEL PACIENTE Y CON EL MANAGER DE PACIENTE BUSCAR POR DNI EL PACIENTE Y SACAR EL ID
std::vector<Factura> ManagerFactura::buscarPorPacienteID(int idPaciente) {
    std::vector<Factura> lista = leerTodos();
    std::vector<Factura> resultado;

    for (int i = 0; i < (int)lista.size(); i++) {
        if (lista[i].getIdPaciente() == idPaciente) {
            resultado.push_back(lista[i]);
        }
    }
    return resultado;
}

bool ManagerFactura::existeFacturaParaTurno(int idTurno) {
    std::vector<Factura> todas = leerTodos();
    for (int i = 0; i < (int)todas.size(); i++) {
        if (todas[i].getIdTurno() == idTurno) {
            return true;
        }
    }
    return false;
}
