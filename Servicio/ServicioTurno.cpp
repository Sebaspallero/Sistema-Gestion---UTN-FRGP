#include "../ServicioH/ServicioTurno.h"
#include "../ServicioH/ServiciosUtilidades.h"
#include <iostream>
#include <limits>
using namespace std;

//CONSTRUCTOR
ServicioTurno::ServicioTurno() :
    managerTurno("turnos.dat"),
    servicioAnalisis(),
    servicioSala(),
    servicioPaciente(),
    servicioBioquimico(){}

//VALIDAR SI LA FECHA ESTA OCUPADA
bool ServicioTurno::fechaOcupada(const FechaHora& nuevaFechaHora, int idSala, int idBioquimico) {
    std::vector<Turno> turnos = obtenerTurnos();

    for (int i = 0; i < (int)turnos.size(); i++) {
        Turno t = turnos[i];
        if (t.getFechaTurno().esIgual(nuevaFechaHora)) {
            if (t.getIDSala() == idSala) {
                return true;
            }
            if (t.getIDBioquimico() == idBioquimico) {
                return true;
            }
        }
    }
    return false;
}


void ServicioTurno::limpiarBuffer() const {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//HELPERS DE NOMBRES PARA LISTA
std::string ServicioTurno::nombrePacientePorId(int id, const vector<Paciente>& lista) {
    for (int i = 0; i < (int)lista.size(); i++) {
        if (lista[i].getId() == id) {
            return lista[i].getNombre() + " " + lista[i].getApellido();
        }
    }
    return "Desconocido";
}

std::string ServicioTurno::nombreBioquimicoPorId(int id, const vector<Bioquimico>& lista) {
    for (int i = 0; i < (int)lista.size(); i++) {
        if (lista[i].getId() == id) {
            return lista[i].getNombre() + " " + lista[i].getApellido();
        }
    }
    return "Desconocido";
}

std::string ServicioTurno::nombreAnalisisPorId(int id, const vector<Analisis>& lista) {
    for (int i = 0; i < (int)lista.size(); i++) {
        if (lista[i].getId() == id) {
            return lista[i].getNombre();
        }
    }
    return "Desconocido";
}

std::string ServicioTurno::nombreSalaPorId(int id, const vector<Sala>& lista) {
    for (int i = 0; i < (int)lista.size(); i++) {
        if (lista[i].getId() == id) {
            return lista[i].getNombre();
        }
    }
    return "Desconocido";
}

//CREAR TURNO
void ServicioTurno::crearTurno() {
    system("cls");
    cout << "\n-- CREAR TURNO --\n";

    vector<Paciente> pacientes = servicioPaciente.obtenerPacientes();
    vector<Bioquimico> bioquimicos = servicioBioquimico.obtenerBioquimicos();
    vector<Analisis> analisis = servicioAnalisis.obtenerAnalisis();
    vector<Sala> salas = servicioSala.obtenerSalas();
    vector<Turno> turnos = obtenerTurnos();

    // VALIDAR QUE SE PUEDA CREAR TURNO
    if (bioquimicos.empty() || analisis.empty() || salas.empty()) {
        system("cls");
        cout << "Debe existir al menos 1 bioquimico, analisis y/o sala.\n";
        return;
    }

    int id = managerTurno.obtenerNuevoId();
    int idPaciente, idBioquimico, idAnalisis, idSala;
    int dia, mes, anio, hora, minutos;

    //SELECCIONAR PACIENTE
    servicioPaciente.listarPacientes(pacientes);

    while (true) {
        idPaciente = pedirEntero("\nIngrese ID del Paciente (0 para salir, -1 para registrar NUEVO):");

        // OPCIÓN SALIR
        if (idPaciente == 0) {
            system("cls");
            return;
        }

        // OPCIÓN CREAR NUEVO PACIENTE
        if (idPaciente == -1) {
            limpiarBuffer();
            servicioPaciente.crearPaciente();

            pacientes = servicioPaciente.obtenerPacientes();

            system("cls");
            cout << "\n-- CREAR TURNO --\n";
            servicioPaciente.listarPacientes(pacientes);
            continue; // Volvemos al inicio del while para que ingrese el ID nuevo
        }

        // VALIDAR SI EL ID EXISTE
        bool encontrado = false;
        for (int i = 0; i < (int)pacientes.size(); i++) {
            if (pacientes[i].getId() == idPaciente) {
                encontrado = true;
                break;
            }
        }

        if (encontrado) {
            break;
        } else {
            cout << "ID no encontrado. Intente nuevamente o ingrese -1 para crearlo.\n";
        }
    }
    system("cls");
    //SELECCIONAR BIOQUIMICO
    servicioBioquimico.listarBioquimicos(bioquimicos);
    cout << "Ingrese ID del Bioquimico (0 para finalizar).\n";

    while (true) {
        cout << "ID bioquimico: ";
        cin >> idBioquimico;

        if (cin.fail()) {
            cout << "Error: Debe ingresar un numero.\n";
            limpiarBuffer();
            continue;
        }

        if (idBioquimico == 0) {
            system("cls");
            return;
        }

        bool encontrado = false;
        for (int i = 0; i < (int)bioquimicos.size(); i++) {
            if (bioquimicos[i].getId() == idBioquimico) {
                encontrado = true;
                break;
            }
        }

        if (encontrado) {
            break;
        } else {
            cout << "ID no encontrado. Intente nuevamente.\n";
        }
    }
    system("cls");
    //SELECCIONAR ANALISIS
    servicioAnalisis.listarAnalisis(analisis);
    cout << "Ingrese ID del Analisis (0 para finalizar).\n";

    while (true) {
        cout << "ID analisis: ";
        cin >> idAnalisis;

        if (cin.fail()) {
            cout << "Error: Debe ingresar un numero.\n";
            limpiarBuffer();
            continue;
        }

        if (idAnalisis == 0) {
            system("cls");
            return;
        }

        bool encontrado = false;
        for (int i = 0; i < (int)analisis.size(); i++) {
            if (analisis[i].getId() == idAnalisis) {
                encontrado = true;
                break;
            }
        }

        if (encontrado) {
            break;
        } else {
            cout << "ID no encontrado. Intente nuevamente.\n";
        }
    }
    system("cls");
    //SELECCIONAR SALA
    servicioSala.listarSalas(salas);
    cout << "Ingrese ID de la Sala (0 para finalizar).\n";

    while (true) {
        cout << "ID sala: ";
        cin >> idSala;

        if (cin.fail()) {
            cout << "Error: Debe ingresar un numero.\n";
            limpiarBuffer();
            continue;
        }

        if (idSala == 0) {
            system("cls");
            return;
        }

        bool encontrado = false;
        for (int i = 0; i < (int)salas.size(); i++) {
            if (salas[i].getId() == idSala) {
                encontrado = true;
                break;
            }
        }

        if (encontrado) {
            break;
        } else {
            cout << "ID no encontrado. Intente nuevamente.\n";
        }
    }
    system("cls");
    //SELECCIONAR FECHA Y HORA
    FechaHora fecha;
    while (true) {
        fecha = pedirFechaHora("Ingrese la fecha y hora del turno", 2024, 2030);

        if (fecha.getAnio() == 0) {
            system("cls");
            return;
        }

        // VALIDAR SI ESTA OCUPADO
        if (!fechaOcupada(fecha, idSala, idBioquimico)) {
            break; // OK
        }

        cout << "La SALA o el BIOQUIMICO ya tienen un turno en esa fecha/hora.\n";
        cout << "Ingrese otro horario.\n";
        listarTurnos(turnos);
    }

    //GUARDAR
    Turno turno(id, idPaciente, idBioquimico, idAnalisis, idSala, fecha, false);

    if (managerTurno.guardar(turno)) {
        cout << "Turno creado con exito.\n";
    } else {
        cout << "Error al crear el turno.\n";
    }
}

//OBTENER LISTA DE TURNOS
std::vector<Turno> ServicioTurno::obtenerTurnos() {
    return managerTurno.leerTodos();
}

//OBTENER LISTA DE TURNOS CON ASISTENCIA
std::vector <Turno>ServicioTurno::obtenerTurnosConAsistencia(){
    return managerTurno.buscarPorAsistencia();
}


//IMPRIMIR LISTA DE TURNOS
void ServicioTurno::listarTurnos(const std::vector<Turno>& turnos) {
    system("cls");
    if (turnos.empty()) {
        cout << "No hay turnos registrados.\n";
        return;
    }

    vector<Paciente> listaPacientes = servicioPaciente.obtenerPacientes();
    vector<Bioquimico> listaBioquimicos = servicioBioquimico.obtenerBioquimicos();
    vector<Analisis> listaAnalisis = servicioAnalisis.obtenerAnalisis();
    vector<Sala> listaSalas = servicioSala.obtenerSalas();
    // -----------------------------------------------------------

    cout << "\n-- LISTADO DE TURNOS --\n";

    for (int i = 0; i < turnos.size(); i++) {
        Turno t = turnos[i];
        FechaHora f = t.getFechaTurno();

        cout << "ID: " << t.getId() << endl;
        cout << " Paciente: " << nombrePacientePorId(t.getIDPaciente(), listaPacientes) << endl;
        cout << " Bioquimico: " << nombreBioquimicoPorId(t.getIDBioquimico(), listaBioquimicos) << endl;
        cout << " Analisis: " << nombreAnalisisPorId(t.getIDAnalisis(), listaAnalisis) << endl;
        cout << " Sala: " << nombreSalaPorId(t.getIDSala(), listaSalas) << endl;
        cout << " Fecha: " << f.toString() << endl;
        cout << " Asistio: " << (t.getAsistio() ? "Si" : "No") << endl;
        cout << "-------------------------" << endl;
    }
}

//ELIMINAR TURNO
void ServicioTurno::eliminarTurno() {
    system("cls");
    vector<Turno> lista = obtenerTurnos();

    if (lista.empty()) {
        cout << "No hay turnos para eliminar.\n";
        return;
    }

    listarTurnos(lista);

    int id;
    while (true) {
        cout << "\nIngrese ID del turno a eliminar (0 para cancelar): ";
        cin >> id;

        if (cin.fail()) {
            cout << "Error: Debe ingresar un numero.\n";
            limpiarBuffer();
            continue;
        }

        if (id == 0) return;
        break;
    }

    // Confirmación
    cout << "Esta seguro que desea eliminar el turno con ID " << id << "? (S/N): ";
    char confirma;
    cin >> confirma;
    if (confirma != 'S' && confirma != 's') {
        cout << "Operacion cancelada. No se elimino el turno.\n";
        return;
    }

    bool eliminado = managerTurno.eliminar(id);

    if (eliminado) {
        cout << "Turno eliminado correctamente.\n";
    } else {
        cout << "No se encontro un turno con ese ID.\n";
    }
}

//MODIFICAR TURNO
void ServicioTurno::modificarTurno() {
    system("cls");
    vector<Turno> lista = obtenerTurnos();

    if (lista.empty()) {
        cout << "No hay turnos para modificar.\n";
        return;
    }

    listarTurnos(lista);

    int id;
    int pos;

    //BUSCAR TURNO
    while (true) {
        cout << "\nIngrese ID del turno a reprogramar (0 para salir): ";
        cin >> id;

        if (cin.fail()) {
            cout << "Error: Debe ingresar un numero.\n";
            limpiarBuffer();
            continue;
        }

        if (id == 0) return;

        pos = managerTurno.buscar(id);
        if (pos != -1) {
            break;
        } else {
            cout << "No existe un turno con ese ID. Intente nuevamente.\n";
        }
    }
    system("cls");
    Turno turno = managerTurno.leer(pos);
    FechaHora fechaActual = turno.getFechaTurno();

    cout << "\n-- REPROGRAMANDO TURNO\n";
    cout << "Fecha Actual: " << fechaActual.toString() << endl;

    //INGRESAR NUEVA FECHA
    FechaHora nuevaFecha;

    while (true) {
        nuevaFecha = pedirFechaHora("Ingrese la fecha y hora del turno", 2024, 2030);

        if (nuevaFecha.getAnio() == 0) {
            system("cls");
            return;
        }

        // VALIDAR SI ESTA OCUPADO
        if (!fechaOcupada(nuevaFecha, turno.getIDSala(), turno.getIDBioquimico())) {
            break; // OK
        }

        cout << "La SALA o el BIOQUIMICO ya tienen un turno en esa fecha/hora.\n";
        cout << "Ingrese otro horario.\n";
        listarTurnos(lista);
    }

    //GUARDAR
    turno.setFechaTurno(nuevaFecha);

    if (managerTurno.modificar(turno, pos)) {
        cout << "Turno reprogramado con exito.\n";
    } else {
        cout << "Error al guardar la modificacion.\n";
    }
}

//BUSCAR TURNO POR FECHA
void ServicioTurno::buscarPorFecha() {
    system("cls");

    cout << "\n-- BUSCAR POR FECHA --\n";

    Fecha fecha = pedirFecha("Ingrese la fecha del turno a buscar:", 2022, 2030);

    if (fecha.getAnio() == 0) {
        system("cls");
        return;
    }

    vector<Turno> resultado = managerTurno.buscarPorFecha(
        fecha.getDia(),
        fecha.getMes(),
        fecha.getAnio()
    );

    if (resultado.empty()) {
        cout << "No hay turnos en esa fecha.\n";
        return;
    }

    cout << "\nResultados encontrados:\n";
    for (int i = 0; i < resultado.size(); i++) {
        Turno t = resultado[i];
        FechaHora f = t.getFechaTurno();
        cout << "ID: " << t.getId()
             << " | Paciente ID: " << t.getIDPaciente()
             << " | Bioquimico ID: " << t.getIDBioquimico()
             << " | Fecha: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio()
             << " " << f.getHora() << ":" << f.getMinutos()
             << "\n";
    }
}

//BUSCAR TURNO POR PACIENTE
void ServicioTurno::buscarPorPaciente() {
    system("cls");
    vector<Paciente> pacientes = servicioPaciente.obtenerPacientes();

    if (pacientes.empty()){
        cout << "No hay pacientes registrados.\n";
        return;
    }

    servicioPaciente.listarPacientes(pacientes);

    int id;
    while(true) {
        cout << "Ingrese ID del paciente a buscar (0 para salir): ";
        cin >> id;
        if (cin.fail()) {
            cout << "Debe ser un numero.\n";
            limpiarBuffer();
            continue;
        }
        if(id == 0) return;
        break;
    }

    vector<Turno> resultado = managerTurno.buscarPorPaciente(id);

    if (resultado.empty()) {
        cout << "No hay turnos para ese paciente.\n";
        return;
    }

    for (int i = 0; i < resultado.size(); i++) {
        Turno t = resultado[i];
        FechaHora f = t.getFechaTurno();
        cout << "ID Turno: " << t.getId()
             << " | Fecha: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio()
             << " " << f.getHora() << ":" << f.getMinutos()
             << "\n";
    }
}

//BUSCAR TURNO POR BIOQUIMICO
void ServicioTurno::buscarPorBioquimico() {
    system("cls");
    vector<Bioquimico> lista = servicioBioquimico.obtenerBioquimicos();
    if (lista.empty()) {
        cout << "No hay bioquimicos registrados.\n";
        return;
    }

    servicioBioquimico.listarBioquimicos(lista);

    int id;
    while(true) {
        cout << "Ingrese ID del bioquimico a buscar (0 para salir): ";
        cin >> id;
        if (cin.fail()) {
            cout << "Debe ser un numero.\n";
            limpiarBuffer();
            continue;
        }
        if(id == 0) return;
        break;
    }

    vector<Turno> resultado = managerTurno.buscarPorBioquimico(id);

    if (resultado.empty()) {
        cout << "No hay turnos para ese bioquimico.\n";
        return;
    }

    for (int i = 0; i < resultado.size(); i++) {
        Turno t = resultado[i];
        FechaHora f = t.getFechaTurno();
        cout << "ID Turno: " << t.getId()
             << " | Fecha: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio()
             << " " << f.getHora() << ":" << f.getMinutos()
             << "\n";
    }
}

//CONFIRMAR TURNO
void ServicioTurno::confirmarTurno() {
    system("cls");
    std::vector<Turno> turnos = obtenerTurnos();

    if (turnos.empty()) {
        cout << "No hay turnos para confirmar.\n";
        return;
    }

    listarTurnos(turnos);

    int id;
    while(true) {
        cout << "\nIngrese ID del turno a confirmar (0 para salir): ";
        cin >> id;
        if (cin.fail()) {
            cout << "Debe ser un numero.\n";
            limpiarBuffer();
            continue;
        }
        if (id == 0) return;
        break;
    }

    int pos = managerTurno.buscar(id);
    if (pos == -1) {
        cout << "No existe un turno con ese ID.\n";
        return;
    }

    Turno t = managerTurno.leer(pos);
    t.setAsistio(true);

    if (managerTurno.modificar(t, pos)) {
        cout << "Turno confirmado correctamente.\n";
    } else {
        cout << "Error al confirmar turno.\n";
    }
}

//ORDENAR TURNO POR FECHA
void ServicioTurno::ordenarPorFecha() {
    system("cls");
    cout << "\n-- TURNOS ORDENADOS POR FECHA (DESCENDENTE) --\n";

    vector<Turno> lista = managerTurno.ordenarPorFecha();

    for (int i = 0; i < lista.size(); i++) {
        Turno t = lista[i];
        FechaHora f = t.getFechaTurno();
        cout << "ID: " << t.getId()
             << " | Paciente: " << t.getIDPaciente()
             << " | Fecha: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio()
             << " " << f.getHora() << ":" << f.getMinutos()
             << "\n";
    }
}



