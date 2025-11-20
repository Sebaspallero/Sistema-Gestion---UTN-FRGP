/*
#include "../MenuH/Menu.h"
#include "../MenuH/MenuReporte.h"
#include "../ServicioH/ServicioReporte.h"

using namespace std;

MenuReporte::MenuReporte() : Menu("Menu de Reportes"), servicioReporte() {}

void MenuReporte::ejecutar(){
    int opcion = -1;

    do {
        system("cls");
        mostrarTitulo();
        cout << "1. Recaudacion por analisis\n";
        cout << "2. Recaudacion por obra social\n";
        cout << "3. Cantidad de analisis en el mes\n";
        cout << "4. Cantidad de tipos de analisis en el mes\n";
        cout << "------------------------------\n";
        cout << "5. Cantidad de nuevos pacientes por mes\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";

        if (!(cin>>opcion)) {
            system("cls");
            cout << "Entrada invalida. Debe ingresar un numero. " << endl;
            limpiarBuffer();
            opcion = -1;
            pausar();
        }

        else{
        switch (opcion) {
            case 1:
                servicioReporte.obtenerRecaudacionPorAnalisis();
                pausar();
                break;

            case 2:
                servicioReporte.obtenerRecaudacionPorObraSocial();
                pausar();
                break;

            case 3:
                servicioReporte.obtenerCantidadAnalisisMes();
                pausar();
                break;

            case 4:
                servicioReporte.obtenerCantidadTiposAnalisisMes();
                pausar();
                break;

            case 5:
                servicioReporte.obtenerCantidadNuevosPacientesMes();
                pausar();
                break;

            case 0:
                cout << "Volviendo al menú principal..." << endl;
                limpiarBuffer();
                break;

            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
                pausar();
                break;
            }
        }

    } while (opcion != 0);

}
*/
