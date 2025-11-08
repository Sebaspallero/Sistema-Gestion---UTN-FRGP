#include "../MenuH/MenuSala.h"
#include <iostream>
using namespace std;

MenuSala::MenuSala() : Menu("Menu de Salas"), servicioSala() {}

void MenuSala::ejecutar() {
    int opcion = 0;
    do {
        mostrarTitulo();
        cout << "1. Registrar nueva sala\n";
        cout << "2. Listar todas las salas\n";
        cout << "3. Eliminar sala\n";
        cout << "4. Buscar por nombre\n";
        cout << "5. Modificar Sala\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";

        if (!(cin >> opcion)) {
            cout << "Entrada invalida. Intente de nuevo.\n";
            limpiarBuffer();
            continue;
        }

        switch (opcion) {
            case 1: {
                servicioSala.crearSala();
                break;
            }

            case 2: {
                servicioSala.listarSalas();
                break;
            }

            case 3: {
                servicioSala.eliminarSala();
                break;
            }

            case 4: {
                servicioSala.buscarSalaPorNombre();
                break;
            }

            case 5: {
                servicioSala.modificarSala();
                break;
            }

            case 0:
                cout << "Volviendo al menu principal\n";
                limpiarBuffer();
                break;

            default:
                cout << "Opcion no reconocida. Por favor, elija entre 0 y 5.\n";
                break;
        }

    } while (opcion != 0);
}
