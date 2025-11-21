#include "../ServicioH/ServicioResultado.h"
#include <iostream>
#include <limits>
using namespace std;

ServicioResultado::ServicioResultado() : managerResultado("resultados.dat"),servicioPaciente(), servicioTurno() {}

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


void ServicioResultado::crearResultado() {
    system("cls");
    cout << "\n-- CREAR RESULTADO --\n";

    std::vector<Turno> turnosAsistencia = servicioTurno.obtenerTurnosConAsistencia();
    if (turnosAsistencia.empty()) {
        cout << "No hay turnos con asistencia registrada pendientes de resultado.\n";
        cout << "(Recuerde que el paciente debe tener la asistencia confirmada primero).\n";
        return;
    }

    int id = managerResultado.obtenerNuevoId();
    int idTurno;
    string descripcion;
    int dia, mes, anio;


    //VALIDACION ID TURNO
    while (true) {
        cout << "Ingrese ID del turno asociado: ";
        if (cin >> idTurno) {
            if (idTurno > 0) {
                if (existeResultadoParaTurno(idTurno)) {
                    cout << "Error: Ese turno YA TIENE un resultado cargado.\n";
                } else {
                    bool turnoValido = false;
                    for (int i = 0; i < turnosAsistencia.size(); i++) {
                        if (turnosAsistencia[i].getId() == idTurno) {
                            turnoValido = true;
                            break;
                        }
                    }
                    if (turnoValido) {
                        limpiarBuffer(); // Exito
                        break;
                    } else {
                        cout << "Error: El turno no existe o el paciente NO registro asistencia.\n";
                        cout << "Solo se pueden cargar resultados a turnos con asistencia 'SI'.\n";
                    }
                }
            } else {
                cout << "El ID del turno debe ser positivo.\n";
            }
        } else {
            cout << "Error: Debe ingresar un numero.\n";
            limpiarBuffer();
        }
    }

    //DESCRIPCION
    do {
        cout << "Ingrese descripcion del resultado: ";
        getline(cin, descripcion);
        if (descripcion.empty()) cout << "La descripcion no puede estar vacia.\n";
    } while (descripcion.empty());

    //FECHA

    //DIA
    while (true) {
        cout << "Ingrese dia (1-31): ";
        if (cin >> dia && dia >= 1 && dia <= 31){
            break;
        }
        cout << "Dia invalido.\n";
        limpiarBuffer();
    }

    //MES
    while (true) {
        cout << "Ingrese mes (1-12): ";
        if (cin >> mes && mes >= 1 && mes <= 12){
            break;
        }
        cout << "Mes invalido.\n";
        limpiarBuffer();
    }

    //ANIO
    while (true) {
        cout << "Ingrese anio (2000-2025): ";
        if (cin >> anio && anio >= 2000 && anio <= 2025){
            break;
        }
        cout << "Anio invalido.\n";
        limpiarBuffer();
    }


    Resultado resultado(id, idTurno, descripcion, Fecha(dia, mes, anio));

    if(managerResultado.guardar(resultado)){
        cout << "Resultado creado con exito!\n";
    } else {
        cout << "Error al guardar el resultado.\n";
    }
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

//MODIFICAR RESULTADO
void ServicioResultado::modificarResultado() {
    vector<Resultado> lista = obtenerResultado();

    if (lista.empty()) {
        cout << "No hay resultados para modificar.\n";
        return;
    }

    listarResultados(lista);

    int id;
    int pos = -1;

    // SELECCION ID
    while (true) {
        cout << "\nIngrese ID del resultado a modificar (0 para salir): ";
        if (cin >> id) {
            if (id == 0) return;
            pos = managerResultado.buscar(id);
            if (pos != -1) {
                limpiarBuffer();
                break;
            }
            cout << "No existe resultado con ese ID.\n";
        } else {
            cout << "Error: Debe ingresar un numero.\n";
            limpiarBuffer();
        }
    }

    Resultado resultado = managerResultado.leer(pos);

    string descripcion;
    int dia, mes, anio;

    cout << "\n-- MODIFICANDO DATOS (Presione ENTER en textos para mantener el actual) --\n";

    // DESCRIPCION
    cout << "Descripcion actual: " << resultado.getDescripcion() << "\n";
    cout << "Nueva descripcion: ";
    getline(cin, descripcion);
    if (descripcion.empty()) descripcion = resultado.getDescripcion();

    // FECHA
    cout << "\n-- Reingrese la fecha del resultado --\n";

    //DIA
    while (true) {
        cout << "Nuevo dia (" << resultado.getFecha().getDia() << "): ";
        if (cin >> dia && dia >= 1 && dia <= 31){
            break;
        }
        cout << "Dia invalido.\n";
        limpiarBuffer();
    }

    //MES
    while (true) {
        cout << "Nuevo mes (" << resultado.getFecha().getMes() << "): ";
        if (cin >> mes && mes >= 1 && mes <= 12){
            break;
        }
        cout << "Mes invalido.\n";
        limpiarBuffer();
    }

    //ANIO
    while (true) {
        cout << "Nuevo anio (" << resultado.getFecha().getAnio() << "): ";
        if (cin >> anio && anio >= 2000 && anio <= 2025){
             break;
        }
        cout << "Anio invalido.\n";
        limpiarBuffer();
    }

    resultado.setDescripcion(descripcion);
    resultado.setFecha(Fecha(dia, mes, anio));

    if(managerResultado.modificar(resultado, pos)){
        cout << "Resultado modificado con exito!\n";
    } else {
        cout << "Error al modificar el resultado.\n";
    }
}

void ServicioResultado::eliminarResultado() {
    vector<Resultado> lista = obtenerResultado();

    if (lista.empty()) {
        cout << "No hay resultados para eliminar.\n";
        return;
    }

    listarResultados(lista);

    int id;
    while (true) {
        cout << "\nIngrese ID del resultado a eliminar (0 para cancelar): ";
        if (cin >> id) {
            limpiarBuffer();
            break;
        } else {
            cout << "Error: Debe ingresar un numero.\n";
            limpiarBuffer();
        }
    }

    if (id == 0) return;

    if (managerResultado.eliminar(id)) {
        cout << "Resultado eliminado correctamente.\n";
    } else {
        cout << "No se encontro un resultado con ese ID.\n";
    }
}

void ServicioResultado::buscarPorPaciente() {
    int id;
    while(true) {
        cout << "Ingrese ID del paciente: ";
        if (cin >> id) {
            limpiarBuffer();
            break;
        } else {
            cout << "Error: Numero invalido.\n";
            limpiarBuffer();
        }
    }

    vector<Resultado> lista = managerResultado.buscarPorPaciente(id);

    if (lista.empty()) {
        cout << "No se encontraron resultados para el paciente ID " << id << ".\n";
    } else {
        listarResultados(lista);
    }
}

