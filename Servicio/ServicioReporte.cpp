#include "../ServicioH/ServicioReporte.h"
#include <iomanip>
using namespace std;

//CONSTRUCTOR
ServicioReporte::ServicioReporte() : _servicioFactura(), _servicioTurno(), _servicioAnalisis(),
      _servicioPaciente(), _servicioObraSocial(), _servicioMetodoDePago() {}

//METODOS AUXILIARES
void ServicioReporte::limpiarBuffer() const {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//Recaudación total de un mes específico
void ServicioReporte::reporteRecaudacionMensual() {
    system("cls");
    int mes, anio;
    cout << "\n--- REPORTE DE RECAUDACION MENSUAL ---\n";

    // Validacion de mes
    while(true){
        cout << "Ingrese mes (1-12): "; cin >> mes;
        if(cin.fail() || mes < 1 || mes > 12){
             cout << "Mes incorrecto." << endl;
             limpiarBuffer();
        } else {
            break;
        }
    }

    // Validacion de anio
    while(true){
        cout << "Ingrese anio (2000 - 2025): "; cin >> anio;
        if(cin.fail() || anio < 2000 || anio > 2025){
             cout << "Anio incorrecto." << endl;
             limpiarBuffer();
        } else {
            break;
        }
    }

    vector<Factura> facturas = _servicioFactura.obtenerFacturas();
    float recaudacionTotal = 0;
    int cantidadFacturas = 0;

    for (int i = 0; i < facturas.size(); i++) {
        if (facturas[i].getFechaPago().getMes() == mes &&
            facturas[i].getFechaPago().getAnio() == anio) {

            recaudacionTotal += facturas[i].getCostoFinal();
            cantidadFacturas++;
        }
    }

    cout << "\n---------------------------------------";
    cout << "\nPeriodo: " << mes << "/" << anio;
    cout << "\nFacturas emitidas: " << cantidadFacturas;
    cout << "\nRECAUDACION TOTAL: $" << recaudacionTotal;
    cout << "\n---------------------------------------\n";
}

//Cantidad de turnos de un analisis
void ServicioReporte::reporteCantidadPorAnalisis() {
    system("cls");
    cout << "\n--- CANTIDAD DE TURNOS POR TIPO DE ANALISIS ---\n";

    //Mostrar qué análisis existen para que el usuario elija
    vector<Analisis> listaAnalisis = _servicioAnalisis.obtenerAnalisis();
    _servicioAnalisis.listarAnalisis(listaAnalisis);

    int idBusco;
    cout << "\nIngrese el ID del analisis a consultar: ";
    cin >> idBusco;

    //Validar que existe el ID
    bool existe = false;
    string nombreAnalisis = "Desconocido";
    for(int i=0; i < (int)listaAnalisis.size(); i++){
        if(listaAnalisis[i].getId() == idBusco){
            existe = true;
            nombreAnalisis = listaAnalisis[i].getNombre();
            break;
        }
    }

    if(!existe){
        cout << "ID incorrecto. Volviendo al menu.\n";
        limpiarBuffer();
        return;
    }

    //Contar en turnos
    vector<Turno> turnos = _servicioTurno.obtenerTurnos();
    int contador = 0;

    for(int i = 0; i < turnos.size(); i++) {
        if(turnos[i].getIDAnalisis() == idBusco){
            contador++;
        }
    }

    cout << "\n---------------------------------------";
    cout << "\nAnalisis: " << nombreAnalisis;
    cout << "\nCantidad de veces realizado: " << contador;
    cout << "\n---------------------------------------\n";
}

// Recaudacion por metodo de pago
void ServicioReporte::reporteRecaudacionPorMetodoPago() {
    system("cls");
    cout << "\n--- RECAUDACION POR METODO DE PAGO ---\n";

    vector<Factura> facturas = _servicioFactura.obtenerFacturas();
    vector<MetodoDePago> metodos = _servicioMetodoDePago.obtenerMetodosDePago();

    cout << left << setw(25) << "Metodo de Pago"
         << " | "
         << right << setw(15) << "Recaudado" << "\n";

    cout << "------------------------------------------------------\n";

    for(int i = 0; i < (int)metodos.size(); i++) {

        int idMetodoActual = metodos[i].getId();
        string nombreMetodo = metodos[i].getNombre();
        float totalAcumulado = 0;

        for(int j = 0; j < (int)facturas.size(); j++) {
            if(facturas[j].getIdMetodoPago() == idMetodoActual) {
                totalAcumulado += facturas[j].getCostoFinal();
            }
        }

        if(totalAcumulado > 0) {
            cout << left << setw(25) << nombreMetodo
                 << " | "
                 << right << setw(15) << totalAcumulado
                 << "\n";
        }
    }

    cout << "------------------------------------------------------\n";
}

//Turnos por obra social
void ServicioReporte::reporteTurnosPorObraSocial() {
    system("cls");
    cout << "\n--- CANTIDAD DE TURNOS POR OBRA SOCIAL ---\n";

    vector<ObraSocial> obras = _servicioObraSocial.obtenerObrasSociales();
    vector<Turno> turnos = _servicioTurno.obtenerTurnos();
    vector<Paciente> pacientes;

     cout << left << setw(25) << "Obra Social"
         << " | "
         << right << setw(10) << "Turnos" << "\n";

    cout << "-----------------------------------------------\n";

    for (int i = 0; i < obras.size(); i++) {
        int idOS = obras[i].getId();
        string nombreOS = obras[i].getNombre();

        int contador = 0;

        for (int j = 0; j < turnos.size(); j++) {
            int idPaciente = turnos[j].getIDPaciente();

            Paciente paciente;
            if (_servicioPaciente.buscarPorId(idPaciente, paciente)) {
                if (paciente.getCodigoObraSocial() == idOS) {
                    contador++;
                }
            }
        }

        if (contador > 0) {
            cout << left << setw(25) << nombreOS
                 << " | "
                 << right << setw(10) << contador
                 << "\n";
        }
    }

    cout << "--------------------------------------------\n";
}

//Asistencia de turnos
void ServicioReporte::reporteAsistenciaTurnos() {
    system("cls");
    cout << "\n--- ESTADISTICA DE ASISTENCIA A TURNOS ---\n";

    vector<Turno> turnos = _servicioTurno.obtenerTurnos();

    int asistidos = 0, noAsistidos = 0;

    for (int i = 0; i < (int) turnos.size(); i++) {
        if (turnos[i].getAsistio()){
            asistidos++;
        }
        else noAsistidos++;
    }

    int total = asistidos + noAsistidos;
    float porcentaje = total > 0 ? (asistidos * 100.0f / total) : 0;

    cout << left << setw(25) << "Asistidos"
         << " | " << right << setw(10) << asistidos << "\n";
    cout << left << setw(25) << "No asistidos"
         << " | " << right << setw(10) << noAsistidos << "\n";
    cout << "---------------------------------------\n";
    cout << "Porcentaje de asistencia: " << porcentaje << "%\n";
}

//Facturacion por obra social
void ServicioReporte::reporteFacturasPorObraSocial() {
    system("cls");
    cout << "\n--- FACTURAS POR OBRA SOCIAL ---\n";

    vector<ObraSocial> obras = _servicioObraSocial.obtenerObrasSociales();
    vector<Paciente> pacientes = _servicioPaciente.obtenerPacientes();
    vector<Factura> facturas = _servicioFactura.obtenerFacturas();

    for (int i = 0; i < (int)obras.size(); i++) {

        int cantidad = 0;
        float total = 0;

        for (int j = 0; j < (int)facturas.size(); j++) {

            int idPac = facturas[j].getIdPaciente();

            for (int k = 0; k < (int)pacientes.size(); k++) {
                if (pacientes[k].getId() == idPac &&
                    pacientes[k].getCodigoObraSocial() == obras[i].getId()) {

                    cantidad++;
                    total += facturas[j].getCostoFinal();
                }
            }
        }

        if (cantidad > 0) {
            cout << "\nObra Social: " << obras[i].getNombre();
            cout << "\nCantidad de Facturas: " << cantidad;
            cout << "\nTotal Facturado: $" << total;
            cout << "\n-------------------------------------";
        }
    }
}

void ServicioReporte::reporteRankingMetodoPago() {
    system("cls");
    cout << "\n--- METODOS DE PAGO MAS USADOS ---\n";

    vector<MetodoDePago> metodos = _servicioMetodoDePago.obtenerMetodosDePago();
    vector<Factura> facturas = _servicioFactura.obtenerFacturas();


    cout << left << setw(25) << "Metodo de Pago"
         << " | "
         << right << setw(10) << "Usos" << "\n";

    cout << "-----------------------------------------------\n";

    for (int i = 0; i < (int)metodos.size(); i++) {

        int contador = 0;

        for (int j = 0; j < (int)facturas.size(); j++) {
            if (facturas[j].getIdMetodoPago() == metodos[i].getId()) {
                contador++;
            }
        }

        if (contador > 0) {
            cout << left << setw(25) << metodos[i].getNombre()
                 << " | "
                 << right << setw(10) << contador
                 << "\n";
        }
    }

    cout << "-----------------------------------------------\n";
}


