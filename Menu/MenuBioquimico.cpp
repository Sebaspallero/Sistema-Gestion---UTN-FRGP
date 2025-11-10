#include "../MenuH/MenuBioquimico.h"
#include <iostream>
using namespace std;

MenuBioquimico::MenuBioquimico() : Menu("Menu de Bioquimicos"), servicioBioquimico() {}


void MenuBioquimico::ejecutar() {
    int opcion = 0;
    do {
        mostrarTitulo();
        cout << "1. Registrar nuevo bioquimico\n";
        cout << "2. Modificar bioquimico\n";
        cout << "3. Eliminar bioquimico\n";
        cout << "4. Listar bioquimicos\n";
        cout << "5. Ordenar bioquimicos por apellido\n";
        cout << "6. Ordenar bioquimicos por legajo\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";

        if (!(cin >> opcion)) {
            cout << "Entrada invalida.\n";
            limpiarBuffer();
            continue;
        }

        switch (opcion) {
            case 1: {
                servicioBioquimico.crearBioquimico();
                break;
            }

            case 2: {
                servicioBioquimico.modificarBioquimico();
                break;
            }

            case 3: {
                servicioBioquimico.eliminarBioquimico();
                break;
            }

            case 4: {
                servicioBioquimico.listarBioquimicos();
                break;
            }

            case 5: {
                servicioBioquimico.ordenarBioquimicosPorApellido();
                break;
            }

            case 6: {
                servicioBioquimico.ordenarBioquimicosPorLegajo();
                break;
            }

            case 0: {
                cout << "Volviendo..." << endl;
                break;
            }

            default: {
                cout << "Opcion invalida. " << endl;
                break;
            }
        }
    } while (opcion != 0);
}
