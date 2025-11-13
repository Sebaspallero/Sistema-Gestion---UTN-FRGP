/**
#include "../MenuH/Menu.h"
#include "../MenuH/MenuTurno.h"
#include "../ServicioH/ServicioTurno.h"

using namespace std;

MenuTurno::MenuTurno() : Menu("Menu de Turnos"), servicioTurno() {}

void MenuTurno::ejecutar(){
int opcion = 0;
    do {
        mostrarTitulo();
        cout << "1. Registrar nuevo turno\n";
        cout << "2. Modificar turno\n";
        cout << "3. Eliminar turno\n";
        cout << "4. Listar turnos\n";
        cout << "5. Buscar por fecha\n";
        cout << "6. Buscar por paciente\n";
        cout << "7. Buscar por bioquimico\n";
        cout << "8. Confirmar turno\n";
        cout << "9. Ordenar turnos por fecha\n"
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";

        cin>> opcion;
        if (!opcion) {
            cout << "Entrada invalida." << endl;
            limpiarBuffer();
        }

        else{
        switch (opcion) {
            case 1:
                servicioTurno.crearTurno();
                break;

            case 2:
                servicioTurno.modificarTurno();
                break;

            case 3:
                servicioTurno.eliminarTurno();
                break;

            case 4:
                servicioTurno.listarTurnos();
                break;

            case 5:
                servicioTurno.buscarPorFecha();
                break;

            case 6:
                servicioTurno.buscarPorPaciente();
                break;

            case 7:
                servicioTurno.buscarPorBioquimico();
                break;

            case 8:
                servicioTurno.confirmarTurno();
                break;

            case 9:
                servicioTurno.ordenarPorFecha();
                break;

            case 0:
                cout << "Volviendo al menú principal..." << endl;
                break;

            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
                break;
            }
        }

    } while (opcion != 0);

}

*/
