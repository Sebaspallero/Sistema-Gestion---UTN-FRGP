#include "../MenuH/Menu.h"
#include "../MenuH/MenuTurno.h"
#include "../ServicioH/ServicioTurno.h"
#include "../ServicioH/ServiciosUtilidades.h"

using namespace std;

MenuTurno::MenuTurno() : Menu("Menu de Turnos"), servicioTurno() {}

void MenuTurno::ejecutar(){
    int opcion;

    do {
        system("cls");
        mostrarTitulo();
        cout << "1. Registrar nuevo turno\n";
        cout << "2. Eliminar turno\n";
        cout << "3. Modificar turno\n";
        cout << "4. Listar turnos\n";
        cout << "------------------------------\n";
        cout << "5. Buscar por fecha\n";
        cout << "6. Buscar por paciente\n";
        cout << "7. Buscar por bioquimico\n";
        cout << "8. Confirmar turno\n";
        cout << "9. Ordenar turnos por fecha\n";
        cout << "0. Volver al menu principal\n";
        opcion = pedirEntero("Seleccione una opcion: ");
        limpiarBuffer();
        switch (opcion) {
            case 1:
                servicioTurno.crearTurno();
                pausar();
                break;

            case 2:
                servicioTurno.eliminarTurno();
                pausar();
                break;

            case 3:
                servicioTurno.modificarTurno();
                pausar();
                break;

            case 4:
                servicioTurno.listarTurnos(servicioTurno.obtenerTurnos());
                pausar();
                break;

            case 5:
                servicioTurno.buscarPorFecha();
                pausar();
                break;

            case 6:
                servicioTurno.buscarPorPaciente();
                pausar();
                break;

            case 7:
                servicioTurno.buscarPorBioquimico();
                pausar();
                break;

            case 8:
                servicioTurno.confirmarTurno();
                pausar();
                break;

            case 9:
                servicioTurno.ordenarPorFecha();
                pausar();
                break;

            case 0:
                cout << "Volviendo al menu principal..." << endl;
                break;

            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
                pausar();
                break;
            }

    } while (opcion != 0);

}
