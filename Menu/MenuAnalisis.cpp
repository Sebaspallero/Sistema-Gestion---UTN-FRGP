#include "../MenuH/Menu.h"
#include "../MenuH/MenuAnalisis.h"
#include "../ServicioH/ServicioAnalisis.h"
#include <iostream>

using namespace std;

MenuAnalisis::MenuAnalisis() : Menu("Menu de Analisis"), _servicioAnalisis() {}

void MenuAnalisis::ejecutar() {
    int opcion = -1;

    do {
        system("cls");
        mostrarTitulo();
        cout << "1. Registrar nuevo analisis\n";
        cout << "2. Eliminar analisis\n";
        cout << "3. Modificar analisis\n";
        cout << "4. Listar analisis\n";
        cout << "------------------------------\n";
        cout << "5. Buscar por nombre\n";
        cout << "6. Buscar por categoria\n";
        cout << "7. Ordenar analisis por nombre\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";

        if (!(cin>>opcion)) {
            system("cls");
            cout << "Entrada invalida.Debe ingresar un numero. " << endl;
            limpiarBuffer();
            opcion = -1;
            pausar();
        }

        else {
        switch (opcion) {
            case 1:
                _servicioAnalisis.crearAnalisis();
                pausar();
                break;

            case 2:
                _servicioAnalisis.eliminarAnalisis();
                pausar();
                break;

            case 3:
                _servicioAnalisis.modificarAnalisis();
                pausar();
                break;

            case 4:
                _servicioAnalisis.listarAnalisis(_servicioAnalisis.obtenerAnalisis());
                pausar();
                break;

            case 5:
                _servicioAnalisis.listarPorNombre();
                pausar();
                break;

            case 6:
                _servicioAnalisis.buscarPorCategoria();
                pausar();
                break;

            case 7:
                _servicioAnalisis.ordenarPorCategoria();
                pausar();
                break;

            case 0:
                cout << "Volviendo al menu principal..." << endl;
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
