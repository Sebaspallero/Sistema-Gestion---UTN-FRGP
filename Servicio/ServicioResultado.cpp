#include "../ServicioH/ServicioResultado.h"
#include "../ServicioH/ServiciosUtilidades.h"
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

//CREAR RESULTADO
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

    servicioTurno.listarTurnos(turnosAsistencia);
    //VALIDACION ID TURNO
    while (true) {
        cout << "Ingrese ID del turno asociado (0 para salir): ";
        if (cin >> idTurno) {
            if(idTurno == 0) return;
            if (idTurno > 0) {
                if (existeResultadoParaTurno(idTurno)) {
                    cout << "Ese turno YA TIENE un resultado cargado.\n";
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
                        cout << "El turno no existe o el paciente NO registro asistencia.\n";
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
    system("cls");
    //DESCRIPCION
    do {
        cout << "Ingrese descripcion del resultado (0 para salir): ";
        getline(cin, descripcion);
        if(descripcion == "0"){return;};
        if (descripcion.empty()) cout << "La descripcion no puede estar vacia.\n";
    } while (descripcion.empty());

    //FECHA
    Fecha fechaResultado = pedirFecha("Ingrese nueva fecha:", 2022, 2025);
    if (fechaResultado.getAnio() == 0) return;

    Resultado resultado(id, idTurno, descripcion, fechaResultado);

    if(managerResultado.guardar(resultado)){
        cout << "Resultado creado con exito!\n";
    } else {
        cout << "Error al guardar el resultado.\n";
    }
}

//TRAER TODOS LOS RESULTADO
vector<Resultado> ServicioResultado::obtenerResultado() {
    return managerResultado.leerTodos();
}

//LISTAR RESULTADOS
void ServicioResultado::listarResultados(const vector<Resultado>& lista) {
    system("cls");
    if (lista.empty()) {
        cout << "No hay resultados registrados.\n";
        return;
    }

    cout << "\n-- LISTADO DE RESULTADOS --\n";
    for (int i = 0; i < lista.size(); i++) {
        Resultado r = lista[i];

        cout << "ID: " << r.getId()
             << " | ID Turno: " << r.getIDTurno()
             << " | Descripcion: " << r.getDescripcion()
             << " | Fecha: " << r.getFecha().toString()
             << "\n";
    }
}

//MODIFICAR RESULTADO
void ServicioResultado::modificarResultado() {
    system("cls");
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
    system("cls");
    Resultado resultado = managerResultado.leer(pos);

    string descripcion;

    cout << "\n-- MODIFICANDO DATOS (Presione ENTER en textos para mantener el actual, 0 para salir) --\n";

    // DESCRIPCION
    cout << "Descripcion actual: " << resultado.getDescripcion() << "\n";
    cout << "Nueva descripcion: ";
    getline(cin, descripcion);
    if(descripcion == "0"){
        return;
    };
    if (descripcion.empty()) descripcion = resultado.getDescripcion();

    // FECHA
    cout << "\n-- Reingrese la fecha del resultado (0 para salir) --\n";

    cout << "\n-- Fecha de resultado actual: "
     << resultado.getFecha().toString() << "\n";

    Fecha fechaResultado = pedirFecha("Ingrese nueva fecha:", 1900, 2025);
    if(fechaResultado.getAnio() == 0) return;

    resultado.setDescripcion(descripcion);
    resultado.setFecha(fechaResultado);

    if(managerResultado.modificar(resultado, pos)){
        cout << "Resultado modificado con exito!\n";
    } else {
        cout << "Error al modificar el resultado.\n";
    }
}

//ELIMINAR RESULTADO
void ServicioResultado::eliminarResultado() {
    system("cls");
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
    int posicion = managerResultado.buscar(id);
    if (posicion == -1){
        cout << "No se encontro un resultado con ese ID. " << endl;
        return;
    }
    // Confirmación
    cout << "Esta seguro que desea eliminar el resultado con ID " << id << "? (S/N): ";
    char confirma;
    cin >> confirma;

    if (confirma != 'S' && confirma != 's') {
        cout << "Operacion cancelada. No se elimino el resultado.\n";
        return;
    }

    if (managerResultado.eliminar(id)) {
        cout << "Resultado eliminado correctamente.\n";
    } else {
        cout << "No se encontro un resultado con ese ID.\n";
    }
}

//BUSCAR x PACIENTE
void ServicioResultado::buscarPorPaciente() {
    system("cls");
    int id;
    while(true) {
        cout << "Ingrese ID del paciente (0 para cancelar): ";
        cin >> id;
        if (cin.fail()) {
            cout << "Error: Ingrese un numero.\n";
            limpiarBuffer();
            continue;
        }
        if(id == 0) return;
        break;
    }

    vector<Resultado> lista = managerResultado.buscarPorPaciente(id);

    if (lista.empty()) {
        cout << "No se encontraron resultados para el paciente ID " << id << ".\n";
    } else {
        listarResultados(lista);
    }
}

