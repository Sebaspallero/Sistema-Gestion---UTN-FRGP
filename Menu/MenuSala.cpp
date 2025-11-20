#include "../MenuH/MenuSala.h"
#include <iostream>

using namespace std;

MenuSala::MenuSala() : Menu("Menu de Salas"), servicioSala() {}

void MenuSala::ejecutar() {
    int opcion = -1;

    do {
        system("cls");
        mostrarTitulo();
        cout << "1. Registrar nueva sala\n";
        cout << "2. Eliminar sala\n";
        cout << "3. Modificar sala\n";
        cout << "4. Listar salas\n";
        cout << "------------------------------\n";
        cout << "5. Buscar por nombre\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";

        if (!(cin >> opcion)) {
            system("cls");
            cout << "Entrada invalida. Debe ingresar un numero." << endl;
            limpiarBuffer();
            opcion = -1;
            pausar();
        }

        else{
        switch (opcion) {
            case 1:
                servicioSala.crearSala();
                pausar();
                break;

            case 2:
                servicioSala.eliminarSala();
                pausar();
                break;

            case 3:
                servicioSala.modificarSala();
                pausar();
                break;

            case 4:
                servicioSala.listarSalas(servicioSala.obtenerSalas());
                pausar();
                break;

            case 5:
                servicioSala.buscarSalaPorNombre();
                pausar();
                break;

            case 0:
                cout << "Volviendo al menu principal..." << endl;
                limpiarBuffer();
                break;

            default:
                cout << "Opcion invalida. Intente nuevamente" << endl;
                pausar();
                break;
            }
        }
    } while (opcion != 0);
}
