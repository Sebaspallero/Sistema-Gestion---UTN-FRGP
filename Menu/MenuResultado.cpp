/**
#include "../MenuH/Menu.h"
#include "../MenuH/MenuResultado.h"
#include "../ServicioH/ServicioResultado.h"

using namespace std;

MenuResultado::MenuResultado() : Menu("Menu de Resultados"), servicioResultado() {}

void MenuResultado::ejecutar(){
int opcion = 0;
    do {
        mostrarTitulo();
        cout << "1. Registrar nuevo resultado\n";
        cout << "2. Modificar resultado\n";
        cout << "3. Eliminar resultado\n";
        cout << "4. Listar resultados\n";
        cout << "5. Buscar por paciente\n";
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
                servicioResultado.crearResultado();
                break;

            case 2:
                servicioResultado.modificarResultado();
                break;

            case 3:
                servicioResultado.eliminarResultado();
                break;

            case 4:
                servicioResultado.listarResultados();
                break;

            case 5:
                servicioResultado.buscarPorPaciente();
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
