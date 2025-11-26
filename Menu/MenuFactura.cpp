#include "../MenuH/Menu.h"
#include "../MenuH/MenuFactura.h"
#include "../ServicioH/ServicioFactura.h"
#include "../ServicioH/ServiciosUtilidades.h"

using namespace std;

MenuFactura::MenuFactura() : Menu("Menu de Facturas"), servicioFactura() {}

void MenuFactura::ejecutar(){
    int opcion;

    do {
        system("cls");
        mostrarTitulo();
        cout << "1. Registrar nueva factura\n";
        cout << "2. Eliminar factura\n";
        cout << "3. Modificar factura\n";
        cout << "4. Listar facturas\n";
        cout << "------------------------------\n";
        cout << "5. Buscar por metodo de Pago\n";
        cout << "6. Buscar por fecha\n";
        cout << "7. Buscar por paciente\n";
        cout << "8. Ordenar facturas por fecha de pago\n";
        cout << "0. Volver al menu principal\n";
        opcion = pedirEntero("Seleccione una opcion: ");
        limpiarBuffer();
        switch (opcion) {
            case 1:
                servicioFactura.crearFactura();
                pausar();
                break;

            case 2:
                servicioFactura.eliminarFactura();
                pausar();
                break;

            case 3:
                servicioFactura.modificarFactura();
                pausar();
                break;

            case 4:
                servicioFactura.listarFacturas(servicioFactura.obtenerFacturas());
                pausar();
                break;

            case 5:
                servicioFactura.buscarPorMetodoDePago();
                pausar();
                break;

            case 6:
                servicioFactura.buscarPorFecha();
                pausar();
                break;

            case 7:
                servicioFactura.buscarPorPaciente();
                pausar();
                break;

            case 8:
                servicioFactura.ordenarPorFechaDePago();
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
