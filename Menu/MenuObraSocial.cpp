#include "../MenuH/MenuObraSocial.h"
#include <iostream>
using namespace std;

MenuObraSocial::MenuObraSocial() : Menu("Menu de Obras Sociales"), servicioObraSocial() {}

void MenuObraSocial::ejecutar() {
    int opcion = 0;
    do {
        mostrarTitulo();
        cout << "1. Registrar nueva obra social\n";
        cout << "2. Listar obras sociales\n";
        cout << "3. Eliminar obra social\n";
        cout << "4. Buscar por nombre\n";
        cout << "5. Modificar obra social\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";

        if (!(cin >> opcion)) {
            cout << "Entrada inválida.\n";
            limpiarBuffer();
            continue;
        }

        switch (opcion) {
            case 1: {
                servicioObraSocial.crearObraSocial();
                break;
            }

            case 2: {
                servicioObraSocial.listarObrasSociales();
                break;
            }

            case 3: {
                servicioObraSocial.eliminarObraSocial();
                break;
            }

            case 4: {
                servicioObraSocial.buscarObraSocialPorNombre();
                break;
            }

            case 5: {
                servicioObraSocial.modificarObraSocial();
                break;
            }
            case 0: cout << "Volviendo...\n"; break;
            default: cout << "Opción inválida.\n"; break;
        }
    } while (opcion != 0);
}
