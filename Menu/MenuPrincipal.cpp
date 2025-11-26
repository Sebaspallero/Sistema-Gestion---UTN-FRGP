#include "../MenuH/MenuPrincipal.h"
#include <iostream>
#include "../ServicioH/ServiciosUtilidades.h"

using namespace std;

MenuPrincipal::MenuPrincipal() : Menu("Menu Principal") {}

void MenuPrincipal::ejecutar() {
    int opcion;

    do {
        system("cls");
        mostrarTitulo();
        cout << "1. Gestionar Salas\n";
        cout << "2. Gestionar Obras Sociales\n";
        cout << "3. Gestionar Pacientes\n";
        cout << "4. Gestionar Bioquimicos\n";
        cout << "5. Gestionar Categorias\n";
        cout << "6. Gestionar Analisis\n";
        cout << "7. Gestionar Metodos de Pago\n";
        cout << "8. Gestionar Facturas\n";
        cout << "9. Gestionar Turnos\n";
        cout << "10.Gestionar Resultados\n";
        cout << "------------------------------\n";
        cout << "11. Reportes\n";
        cout << "0. Salir del Sistema\n";
        opcion = pedirEntero("Seleccione una opcion: ");

        limpiarBuffer();
        switch (opcion) {
            case 1:
                menuSala.ejecutar();
                pausar();
                break;
            case 2:
                menuObraSocial.ejecutar();
                pausar();
                break;
            case 3:
                menuPaciente.ejecutar();
                pausar();
                break;
            case 4:
                menuBioquimico.ejecutar();
                pausar();
                break;
            case 5:
                menuCategoria.ejecutar();
                pausar();
                break;
            case 6:
                menuAnalisis.ejecutar();
                pausar();
                break;
            case 7:
                menuMetodoDePago.ejecutar();
                pausar();
                break;
            case 8:
                menuFactura.ejecutar();
                pausar();
                break;
            case 9:
                menuTurno.ejecutar();
                pausar();
                break;
            case 10:
                menuResultado.ejecutar();
                pausar();
                break;
            case 11:
                menuReporte.ejecutar();
                pausar();
                break;
            case 0:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
                pausar();
            }

    } while (opcion != 0);
}
