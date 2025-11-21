#include "../MenuH/MenuBioquimico.h"
#include <iostream>

using namespace std;

MenuBioquimico::MenuBioquimico() : Menu("Menu de Bioquimicos"), servicioBioquimico() {}

void MenuBioquimico::ejecutar() {
    int opcion = -1;

    do {
        system("cls");
        mostrarTitulo();
        cout << "1. Registrar nuevo bioquimico\n";
        cout << "2. Eliminar bioquimico\n";
        cout << "3. Modificar bioquimico\n";
        cout << "4. Listar bioquimicos\n";
        cout << "------------------------------\n";
        cout << "5. Ordenar bioquimicos por apellido\n";
        cout << "6. Ordenar bioquimicos por legajo\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";

        if (!(cin>>opcion)) {
            system ("cls");
            cout << "Entrada invalida. Debe ingresar un numero. " << endl;
            limpiarBuffer();
            opcion = -1;
            pausar();
        }

        else{
        limpiarBuffer();
        switch (opcion) {
            case 1:
                servicioBioquimico.crearBioquimico();
                pausar();
                break;

            case 2:
                servicioBioquimico.eliminarBioquimico();
                pausar();
                break;

            case 3:
                servicioBioquimico.modificarBioquimico();
                pausar();
                break;

            case 4:
                servicioBioquimico.listarBioquimicos(servicioBioquimico.obtenerBioquimicos());
                pausar();
                break;

            case 5:
                servicioBioquimico.ordenarBioquimicosPorApellido();
                pausar();
                break;

            case 6:
                servicioBioquimico.ordenarBioquimicosPorLegajo();
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
        }

    } while (opcion != 0);
}
