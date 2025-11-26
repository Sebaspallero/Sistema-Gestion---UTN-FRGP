#include "../MenuH/Menu.h"
#include "../MenuH/MenuReporte.h"
#include "../ServicioH/ServicioReporte.h"
#include "../ServicioH/ServiciosUtilidades.h"

using namespace std;

MenuReporte::MenuReporte() : Menu("Menu de Reportes"), servicioReporte() {}

void MenuReporte::ejecutar(){
    int opcion;

    do {
        system("cls");
        mostrarTitulo();
        cout << "1. Recaudacion total por mes\n";
        cout << "2. Cantidad de turnos de un analisis\n";
        cout << "3. Recaudacion por metodo de pago\n";
        cout << "4. Turnos por obra social\n";
        cout << "5. Facturas por obra social\n";
        cout << "6. Asistencia de turnos\n";
        cout << "7. Ranking de metodos de pago\n";
        cout << "------------------------------\n";
        cout << "0. Volver al menu principal\n";
        opcion = pedirEntero("Seleccione una opcion: ");

        limpiarBuffer();
        switch (opcion) {
            case 1:
                servicioReporte.reporteRecaudacionMensual();
                pausar();
                break;

            case 2:
                servicioReporte.reporteCantidadPorAnalisis();
                pausar();
                break;

            case 3:
                servicioReporte.reporteRecaudacionPorMetodoPago();
                pausar();
                break;

            case 4:
                servicioReporte.reporteTurnosPorObraSocial();
                pausar();
                break;

            case 5:
                servicioReporte.reporteFacturasPorObraSocial();
                pausar();
                break;

            case 6:
                servicioReporte.reporteAsistenciaTurnos();
                pausar();
                break;

            case 7:
                servicioReporte.reporteRankingMetodoPago();
                pausar();
                break;

            case 0:
                cout << "Volviendo al menú principal..." << endl;
                break;

            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
                pausar();
                break;
            }

    } while (opcion != 0);

}
