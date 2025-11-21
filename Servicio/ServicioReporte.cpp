#include "../ServicioH/ServicioReporte.h"
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
        cout << "Ingrese anio: "; cin >> anio;
        if(cin.fail() || anio < 2000){
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

    cout << "Presione ENTER para salir.";
    limpiarBuffer();
    cin.get();
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
        limpiarBuffer(); cin.get();
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

    cout << "\nPresione ENTER para salir.";
    limpiarBuffer(); cin.get();
}

// Recaudacion por metodo de pago
void ServicioReporte::reporteRecaudacionPorMetodoPago() {
    system("cls");
    cout << "\n--- RECAUDACION POR METODO DE PAGO ---\n";

    vector<Factura> facturas = _servicioFactura.obtenerFacturas();
    vector<MetodoDePago> metodos = _servicioMetodoDePago.obtenerMetodosDePago();

    cout << "Metodo de Pago       | Total Recaudado\n";
    cout << "--------------------------------------\n";

    for(int i = 0; i < metodos.size(); i++) {
        int idMetodoActual = metodos[i].getId();
        string nombreMetodo = metodos[i].getNombre();
        float totalAcumulado = 0;

        for(int j = 0; j < (int)facturas.size(); j++) {
            if(facturas[j].getIdMetodoPago() == idMetodoActual) {
                totalAcumulado += facturas[j].getCostoFinal();
            }
        }

        if(totalAcumulado > 0) {
             cout << nombreMetodo << ": $" << totalAcumulado << endl;
        }
    }

    cout << "\nPresione ENTER para salir.";
    limpiarBuffer(); cin.get();
}
