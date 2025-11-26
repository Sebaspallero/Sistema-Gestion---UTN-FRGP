#include "../MenuH/MenuBioquimico.h"
#include "../ServicioH/ServiciosUtilidades.h"
#include <iostream>

using namespace std;

MenuBioquimico::MenuBioquimico() : Menu("Menu de Bioquimicos"), servicioBioquimico() {}

void MenuBioquimico::ejecutar() {
    int opcion;

    do {
        system("cls");
        mostrarTitulo();
        cout << "1. Registrar nuevo bioquimico\n";
        cout << "2. Eliminar bioquimico\n";
        cout << "3. Modificar bioquimico\n";
        cout << "4. Listar bioquimicos\n";
        cout << "------------------------------\n";
        cout << "5. Buscar Bioquimico por Matricula\n";
        cout << "6. Ordenar bioquimicos por apellido\n";
        cout << "7. Ordenar bioquimicos por matricula\n";
        cout << "0. Volver al menu principal\n";
        opcion = pedirEntero("Seleccione una opcion: ");

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
                servicioBioquimico.buscarPorMatricula();
                pausar();
                break;

            case 6:
                servicioBioquimico.ordenarBioquimicosPorApellido();
                pausar();
                break;

            case 7:
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

    } while (opcion != 0);
}
