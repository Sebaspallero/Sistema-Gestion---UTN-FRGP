#include "../MenuH/Menu.h"
#include "../MenuH/MenuFactura.h"
#include "../ServicioH/ServicioFactura.h"

using namespace std;

MenuFactura::MenuFactura() : Menu("Menu de Facturas"), servicioFactura() {}

void MenuFactura::ejecutar(){
int opcion = 0;
    do {
        mostrarTitulo();
        cout << "1. Registrar nueva factura\n";
        cout << "2. Modificar factura\n";
        cout << "3. Eliminar factura\n";
        cout << "4. Listar facturas\n";
        cout << "5. Buscar por metodo de Pago\n";
        cout << "6. Buscar por fecha\n";
        cout << "7. Buscar por paciente\n";
        cout << "8. Ordenar facturas por fecha de pago\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";

        cin>> opcion;
        if (!opcion) {
            cout << "Entrada invalida." << endl;
            limpiarBuffer();
        }

        else{
        switch (opcion) {
            case 1:
                servicioFactura.crearFactura();
                break;

            case 2:
                servicioFactura.modificarFactura();
                break;

            case 3:
                servicioFactura.eliminarFactura();
                break;

            case 4:
                servicioFactura.listarFacturas(servicioFactura.obtenerFacturas());
                break;

            case 5:
                servicioFactura.buscarPorMetodoDePago();
                break;

            case 6:
                servicioFactura.buscarPorFecha();
                break;

            case 7:
                servicioFactura.buscarPorPaciente();
                break;

            case 8:
                servicioFactura.ordenarPorFechaDePago();
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
