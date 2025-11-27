#include "../ServicioH/ServicioFactura.h"
#include "../ServicioH/ServiciosUtilidades.h"
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

ServicioFactura::ServicioFactura() : managerFactura("facturas.dat"),
                servicioPaciente(),
                servicioMetodoDePago(),
                servicioAnalisis(),
                servicioTurno(),
                servicioObraSocial() {}

//METODOS AUXILIARES
void ServicioFactura::limpiarBuffer() const {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

std::string ServicioFactura::nombrePacientePorId(int id, const vector<Paciente>& lista) {
    for (int i = 0; i < lista.size(); i++) {
        if (lista[i].getId() == id) {
            return lista[i].getNombre() + " " + lista[i].getApellido();
        }
    }
    return "Desconocido";
}

std::string ServicioFactura::nombreAnalisisPorId(int id, const vector<Analisis>& lista) {
    for (int i = 0; i < lista.size(); i++) {
        if (lista[i].getId() == id) {
            return lista[i].getNombre();
        }
    }
    return "Desconocido";
}

std::string ServicioFactura::nombreMetodoDePagoPorId(int id, const vector<MetodoDePago>& lista) {
    for (int i = 0; i < lista.size(); i++) {
        if (lista[i].getId() == id) {
            return lista[i].getNombre();
        }
    }
    return "Desconocido";
}

bool ServicioFactura::existeFacturaParaTurno(int idTurno) {
    vector<Factura> todas = managerFactura.leerTodos();

    for (int i = 0; i < todas.size(); i++) {
        if (todas[i].getIdTurno() == idTurno) {
            return true;
        }
    }
    return false;
}

float ServicioFactura::calcularMontoConDescuento(int idPaciente, int idAnalisis, const vector<Paciente>& listaPacientes, const vector<Analisis>& listaAnalisis,const vector<ObraSocial>& listaOS) {
    //BUSCAR VALOR DEL ANALISIS
    float valorBase = 0;
    for (int i = 0; i < listaAnalisis.size(); i++) {
        if (listaAnalisis[i].getId() == idAnalisis) {
            valorBase = listaAnalisis[i].getValor();
            break;
        }
    }

    //BUSCAR CODIGO DE OBRA SOCIAL DEL PACIENTE
    int codigoOS = -1;
    for (int i = 0; i < listaPacientes.size(); i++) {
        if (listaPacientes[i].getId() == idPaciente) {
            codigoOS = listaPacientes[i].getCodigoObraSocial();
            break;
        }
    }

    // BUSCAR PORCENTAJE DE DESCUENTO
    float porcentajeDescuento = 0;
    if (codigoOS > 0) {
        for (int i = 0; i < listaOS.size(); i++) {
            if (listaOS[i].getId() == codigoOS) {
                porcentajeDescuento = listaOS[i].getDescuento();
                break;
            }
        }
    }

    //CALCULO FINAL
    float descuento = valorBase * (porcentajeDescuento / 100.0f);
    return valorBase - descuento;
}

//CREAR FACTURA
void ServicioFactura::crearFactura() {
    system("cls");
    cout << "\n-- GENERAR FACTURA (SOLO TURNOS ASISTIDOS) --\n";

    //CARGA DE DATOS EN MEMORIA (UNA SOLA VEZ)
    vector<Turno> turnosConAsistencia = servicioTurno.obtenerTurnosConAsistencia();
    vector<Paciente> pacientes = servicioPaciente.obtenerPacientes();
    vector<Analisis> analisis = servicioAnalisis.obtenerAnalisis();
    vector<ObraSocial> obrasSociales = servicioObraSocial.obtenerObrasSociales();

    //FILTRAR TURNOS YA FACTURADOS
    vector<Turno> turnosFacturables;
    for (int i = 0; i < turnosConAsistencia.size(); i++) {
        if (!existeFacturaParaTurno(turnosConAsistencia[i].getId())) {
            turnosFacturables.push_back(turnosConAsistencia[i]);
        }
    }

    if (turnosFacturables.empty()) {
        cout << "No hay turnos pendientes de facturacion.\n";
        return;
    }

    //MOSTRAR TURNOS DISPONIBLES
    cout << "Turnos pendientes de cobro:\n";
    cout << "----------------------------------------------------------------\n";
    for (int i = 0; i < turnosFacturables.size(); i++) {
        Turno t = turnosFacturables[i];
        float montoEstimado = calcularMontoConDescuento(t.getIDPaciente(), t.getIDAnalisis(), pacientes, analisis, obrasSociales);

        cout << "ID Turno: " << t.getId()
             << " | Paciente: " << nombrePacientePorId(t.getIDPaciente(), pacientes)
             << " | Analisis: " << nombreAnalisisPorId(t.getIDAnalisis(), analisis)
             << " | A Cobrar: $" << montoEstimado
             << "\n";
    }

    //SELECCIONAR TURNO
    int idTurnoSeleccionado;
    Turno turnoSeleccionado;
    bool turnoValido = false;

    while (true) {
        cout << "\nIngrese ID del Turno a facturar (0 para salir): ";
        cin >> idTurnoSeleccionado;

        if (cin.fail()) {
            cout << "Error: Debe ingresar un numero.\n";
            limpiarBuffer();
            continue;
        }

        if (idTurnoSeleccionado == 0) return;

        // Validar que el ID este en la lista filtrada
        for (int i = 0; i < turnosFacturables.size(); i++) {
            if (turnosFacturables[i].getId() == idTurnoSeleccionado) {
                turnoSeleccionado = turnosFacturables[i];
                turnoValido = true;
                break;
            }
        }

        if (turnoValido) break;
        cout << "ID invalido o turno no disponible para facturar.\n";
    }
    system("cls");
    //CALCULAR MONTO REAL
    float montoFinal = calcularMontoConDescuento(turnoSeleccionado.getIDPaciente(), turnoSeleccionado.getIDAnalisis(), pacientes, analisis, obrasSociales);
    cout << "\n >> Monto Final a Pagar: $" << montoFinal << endl;

    //SELECCIONAR METODO DE PAGO
    vector<MetodoDePago> metodos = servicioMetodoDePago.obtenerMetodosDePago();
    servicioMetodoDePago.listarMetodosDePago(metodos);

    int idMetodo;
    while (true) {
        cout << "Seleccione ID Metodo de Pago (0 para cancelar): ";
        cin >> idMetodo;
        if (cin.fail()) { limpiarBuffer(); continue; }
        if(idMetodo == 0) return;

        bool existe = false;
        for(int i=0; i < metodos.size(); i++) {
            if(metodos[i].getId() == idMetodo) {
                existe = true;
                break;
            }
        }
        if (existe) break;
        cout << "Metodo inexistente.\n";
    }

    //FECHA DE PAGO
    Fecha fechaFactura = pedirFecha("Ingrese nueva fecha:", 2022, 2025);

    if (fechaFactura.getAnio() == 0) return;

    //GUARDAR FACTURA
    int nuevoIdFactura = managerFactura.obtenerNuevoId();

    Factura nuevaFactura(nuevoIdFactura,
                         turnoSeleccionado.getIDPaciente(),
                         turnoSeleccionado.getIDAnalisis(),
                         idMetodo,
                         turnoSeleccionado.getId(),
                         montoFinal,
                         fechaFactura);

    if (managerFactura.guardar(nuevaFactura)) {
        cout << "\nFactura generada correctamente.\n";
    } else {
        cout << "\nNo se pudo guardar la factura.\n";
    }
}

//OBTENER LISTA DE FACTURAS
std::vector<Factura> ServicioFactura::obtenerFacturas() {
    return managerFactura.leerTodos();
}

//LISTAR FACTURAS
void ServicioFactura::listarFacturas(const std::vector<Factura>& facturas) {
    system("cls");

    if (facturas.empty()) {
        cout << "No hay facturas registradas.\n";
        return;
    }

    vector<Paciente> listaPacientes = servicioPaciente.obtenerPacientes();
    vector<MetodoDePago> listaMetodos = servicioMetodoDePago.obtenerMetodosDePago();
    vector<Analisis> listaAnalisis = servicioAnalisis.obtenerAnalisis();

    cout << "\n-- LISTADO DE FACTURAS --\n";

    for (int i = 0; i < facturas.size(); i++) {
        Factura factura = facturas[i];

        cout << "ID: " << factura.getId() << endl;
        cout << " Paciente: " << nombrePacientePorId(factura.getIdPaciente(), listaPacientes) << endl;
        cout << " Analisis: " << nombreAnalisisPorId(factura.getIdAnalisis(), listaAnalisis) << endl;
        cout << " Método de pago: " << nombreMetodoDePagoPorId(factura.getIdMetodoPago(), listaMetodos) << endl;
        cout << " Costo final: $" << factura.getCostoFinal() << endl;
        cout << " Fecha de pago: " << factura.getFechaPago().toString() << endl;
        cout << "-------------------------" << endl;
    }
}

// MODIFICAR FACTURA
void ServicioFactura::modificarFactura() {
    system("cls");
    vector<Factura> lista = obtenerFacturas();
    if (lista.empty()) {
        cout << "No hay facturas para modificar.\n";
        return;
    }

    listarFacturas(lista);

    int id;
    int pos = -1;

    // VALIDACION DE ID
    while (true) {
        cout << "\nIngrese ID de factura a modificar (0 para cancelar): ";
        cin >> id;

        if (cin.fail()) {
            cout << "Error: Debe ingresar un numero.\n";
            limpiarBuffer();
            continue;
        }

        if (id == 0) return;

        pos = managerFactura.buscar(id);
        if (pos != -1) {
            break;
        } else {
            cout << "No existe factura con ese ID. Intente nuevamente.\n";
        }
    }
    system("cls");
    Factura factura = managerFactura.leer(pos);

    // MODIFICAR METODO DE PAGO
    int nuevoIdMetodo;
    vector<MetodoDePago> metodos = servicioMetodoDePago.obtenerMetodosDePago();
    servicioMetodoDePago.listarMetodosDePago(metodos);
    while(true) {
        cout << "Nuevo ID Metodo de Pago (0 para cancelar): ";
        cin >> nuevoIdMetodo;
        if(cin.fail()) { limpiarBuffer(); continue; }

        if(nuevoIdMetodo == 0) return;

        // Validar existencia
        bool existe = false;
        for(int i=0; i<metodos.size(); i++) {
            if(metodos[i].getId() == nuevoIdMetodo) existe=true;
        }

        if(existe) break;
        cout << "ID de metodo invalido.\n";
    }

    // GUARDAR CAMBIOS
    factura.setIdMetodoPago(nuevoIdMetodo);

    if (managerFactura.modificar(factura, pos)) {
        cout << "\n[EXITO] Factura modificada correctamente.\n";
    } else {
        cout << "\n[ERROR] No se pudo modificar la factura.\n";
    }
}

//ELIMINAR FACTURA
void ServicioFactura::eliminarFactura() {
    system("cls");
    vector<Factura> lista = obtenerFacturas();

    if (lista.empty()) {
        cout << "No hay facturas para eliminar.\n";
        return;
    }

    listarFacturas(lista);

    int id;
    while (true) {
        cout << "\nIngrese ID de factura a eliminar (0 para cancelar): ";
        cin >> id;

        if (cin.fail()) {
            cout << "Error: Debe ingresar un numero.\n";
            limpiarBuffer();
            continue;
        }

        if (id == 0) return;

        if (managerFactura.buscar(id) != -1) {
            break;
        } else {
            cout << "No se encontro factura con ese ID.\n";
        }
    }

    // Confirmación
    cout << "Esta seguro que desea eliminar la factura con ID " << id << "? (S/N): ";
    char confirma;
    cin >> confirma;
    if (confirma != 'S' && confirma != 's') {
        cout << "Operacion cancelada. No se elimino la factura.\n";
        return;
    }

    if (managerFactura.eliminar(id)) {
        cout << "Factura eliminada correctamente.\n";
    } else {
        cout << "Error al intentar eliminar la factura.\n";
    }
}

//BUSCAR x METODO DE PAGO
void ServicioFactura::buscarPorMetodoDePago() {
    system("cls");
    vector<MetodoDePago> metodos = servicioMetodoDePago.obtenerMetodosDePago();
    servicioMetodoDePago.listarMetodosDePago(metodos);

    int id;
    while(true) {
        cout << "Ingrese ID de metodo de pago a buscar (0 para salir): ";
        cin >> id;
        if (cin.fail()) {
            cout << "Error: Ingrese un numero valido.\n";
            limpiarBuffer();
            continue;
        }
        if(id == 0) return;
        break;
    }

    vector<Factura> lista = managerFactura.buscarPorMetodoDePago(id);
    if(lista.empty()) {
        cout << "No se encontraron facturas con ese metodo de pago.\n";
        return;
    }

    listarFacturas(lista);
}

//BUSCAR x FECHA
void ServicioFactura::buscarPorFecha() {
    system("cls");
    cout << "\n-- BUSQUEDA POR FECHA --\n";

    Fecha fechaFactura = pedirFecha("Ingrese nueva fecha:", 2022, 2025);
    if (fechaFactura.getAnio() == 0) return;

    vector<Factura> lista = managerFactura.buscarPorFecha(fechaFactura);
    if(lista.empty()) {
        cout << "No se encontraron facturas en esa fecha.\n";
        return;
    }

    listarFacturas(lista);
}

//BUSCAR x PACIENTE
void ServicioFactura::buscarPorPaciente() {
    system("cls");
    vector<Paciente> pacs = servicioPaciente.obtenerPacientes();
    servicioPaciente.listarPacientes(pacs);

    int id;
    while(true) {
        cout << "Ingrese ID del paciente a buscar: ";
        cin >> id;
        if(cin.fail()) {
            cout << "Error: Ingrese un numero.\n";
            limpiarBuffer();
            continue;
        }
        if(id == 0) return;
        break;
    }

    vector<Factura> lista = managerFactura.buscarPorPacienteID(id);
    if(lista.empty()) {
        cout << "No se encontraron facturas para ese paciente.\n";
        return;
    }

    listarFacturas(lista);
}

//ORDENAR x FECHA DE PAGO
void ServicioFactura::ordenarPorFechaDePago() {
    system("cls");
    vector<Factura> lista = managerFactura.ordenarPorFechaDePago();
    listarFacturas(lista);
}

