#include "../MenuH/Menu.h"
#include "../MenuH/MenuAnalisis.h"
#include "../ServicioH/ServicioAnalisis.h"
#include <iostream>

using namespace std;

MenuAnalisis::MenuAnalisis() : Menu("Menu de Analisis"), _servicioAnalisis() {}

void MenuAnalisis::ejecutar() {
    int opcion = 0;

    do {
        mostrarTitulo();
        cout << "1. Registrar nuevo analisis\n";
        cout << "2. Modificar analisis\n";
        cout << "3. Eliminar analisis\n";
        cout << "4. Listar analisis\n";
        cout << "5. Buscar por nombre\n";
        cout << "6. Buscar por categoria\n";
        cout << "7. Ordenar analisis por nombre\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";

        cin>> opcion;
        if (!opcion) {
            cout << "Entrada invalida." << endl;
            limpiarBuffer();
        }

        else {
        switch (opcion) {
            case 1:
                _servicioAnalisis.crearAnalisis();
                break;

            case 2:
                _servicioAnalisis.modificarAnalisis();
                break;

            case 3:
                _servicioAnalisis.eliminarAnalisis();
                break;

            case 4:
                _servicioAnalisis.listarAnalisis(_servicioAnalisis.obtenerAnalisis());
                break;

            case 5:
                _servicioAnalisis.listarPorNombre();
                break;

            case 6:
                _servicioAnalisis.buscarPorCategoria();
                break;

            case 7:
                _servicioAnalisis.ordenarPorCategoria();
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
