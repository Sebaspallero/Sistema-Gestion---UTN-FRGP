#include "../MenuH/MenuPrincipal.h"
#include <iostream>

using namespace std;

MenuPrincipal::MenuPrincipal() : Menu("Menu Principal") {}

void MenuPrincipal::ejecutar() {
    int opcion = 0;
    do {
        mostrarTitulo();
        cout << "1. Gestionar Salas\n";
        cout << "2. Gestionar Obras Sociales\n";
        cout << "3. Gestionar Pacientes\n";
        cout << "4. Gestionar Bioquimicos\n";
        cout << "5. Gestionar Categorias\n";
        cout << "6. Gestionar Analisis\n";
        cout << "7. Gestionar Metodos de Pago\n";
        cout << "8. Gestionar Facturas (SIN IMPLEMENTAR)\n";
        cout << "9. Gestionar Turnos (SIN IMPLEMENTAR)\n";
        cout << "10.Gestionar Resultados (SIN IMPLEMENTAR)\n";
        cout << "0. Salir del Sistema\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                menuSala.ejecutar();
                limpiarBuffer();
                break;
            case 2:
                menuObraSocial.ejecutar();
                limpiarBuffer();
                break;
            case 3:
                menuPaciente.ejecutar();
                limpiarBuffer();
                break;
            case 4:
                menuBioquimico.ejecutar();
                limpiarBuffer();
                break;
            case 5:
                menuCategoria.ejecutar();
                limpiarBuffer();
                break;
            case 6:
                menuAnalisis.ejecutar();
                limpiarBuffer();
                break;
            case 7:
                menuMetodoDePago.ejecutar();
                limpiarBuffer();
                break;
        /** case 8:
                menuFacturas.ejecutar();
                limpiarBuffer();
                break;
            case 9:
                menuTurnos.ejecutar();
                limpiarBuffer();
                break;
            case 10:
                menuResultados.ejecutar();
                limpiarBuffer();
                break;
        */
            case 0:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
        }

    } while (opcion != 0);
}
