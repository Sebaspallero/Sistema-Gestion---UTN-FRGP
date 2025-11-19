#include "../ServicioH/ServicioResultado.h"
#include <iostream>
#include <limits>
using namespace std;

ServicioResultado::ServicioResultado() : managerResultado("resultados.dat"),servicioPaciente(), servicioTurno() {}

bool ServicioResultado::validarFechaResultado(int dia, int mes, int anio) {
    if (anio <= 2000) return false;
    if (mes < 1 || mes > 12) return false;
    if (dia < 1 || dia > 31) return false;
    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) return false;
    if (mes == 2 && dia > 29) return false;
    return true;
}

void ServicioResultado::limpiarBuffer() const {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool ServicioResultado::existeResultadoParaTurno(int idTurno) {
    vector<Resultado> todos = managerResultado.leerTodos();
    for (int i = 0; i < todos.size(); i++) {
        if (todos[i].getIDTurno() == idTurno) {
            return true;
        }
    }
    return false;
}


bool ServicioResultado::crearResultado() {
    cout << "\n-- CREAR RESULTADO --\n";

    int id = managerResultado.obtenerNuevoId();
    int idTurno;
    string descripcion;
    int dia, mes, anio;

    cout << "Ingrese ID del turno: ";
    cin >> idTurno;

    cout << "Ingrese descripción: ";
    cin.ignore();
    getline(cin, descripcion);

    cout << "Ingrese día: ";
    cin >> dia;
    cout << "Ingrese mes: ";
    cin >> mes;
    cout << "Ingrese año: ";
    cin >> anio;

    Resultado r(id, idTurno, descripcion, Fecha(dia, mes, anio));

    return managerResultado.guardar(r);
}


vector<Resultado> ServicioResultado::obtenerResultado() {
    return managerResultado.leerTodos();
}

void ServicioResultado::listarResultados(const vector<Resultado>& lista) {
    if (lista.empty()) {
        cout << "No hay resultados registrados.\n";
        return;
    }

    cout << "\n-- LISTADO DE RESULTADOS --\n";
    for (int i = 0; i < lista.size(); i++) {
        Resultado r = lista[i];

        cout << "ID: " << r.getId()
             << " | ID Turno: " << r.getIDTurno()
             << " | Descripción: " << r.getDescripcion()
             << " | Fecha: " << r.getFecha().toString()
             << "\n";
    }
}

bool ServicioResultado::modificarResultado() {
    vector<Resultado> lista = obtenerResultado();

    if (lista.empty()) {
        cout << "No hay resultados para modificar.\n";
        return false;
    }

    listarResultados(lista);

    cout << "\nIngrese ID del resultado a modificar: ";
    int id;
    cin >> id;

    int pos = managerResultado.buscar(id);
    if (pos == -1) {
        cout << "No existe resultado con ese ID.\n";
        return false;
    }

    Resultado r = managerResultado.leer(pos);

    string descripcion;
    int dia, mes, anio;

    cout << "Nueva descripción: ";
    cin.ignore();
    getline(cin, descripcion);

    cout << "Nueva fecha - día: ";
    cin >> dia;
    cout << "Mes: ";
    cin >> mes;
    cout << "Año: ";
    cin >> anio;

    r.setDescripcion(descripcion);
    r.setFecha(Fecha(dia, mes, anio));

    return managerResultado.modificar(r, pos);
}

bool ServicioResultado::eliminarResultado() {
    vector<Resultado> lista = obtenerResultado();

    if (lista.empty()) {
        cout << "No hay resultados para eliminar.\n";
        return false;
    }

    listarResultados(lista);

    cout << "\nIngrese ID del resultado a eliminar: ";
    int id;
    cin >> id;

    return managerResultado.eliminar(id);
}

void ServicioResultado::buscarPorPaciente() {
    cout << "Ingrese ID del paciente: ";
    int id;
    cin >> id;

    vector<Resultado> lista = managerResultado.buscarPorPaciente(id);

    listarResultados(lista);
}

