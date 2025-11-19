#include "../MenuH/Menu.h"
#include "../MenuH/MenuCategoria.h"
#include "../ServicioH/ServicioCategoria.h"

using namespace std;

MenuCategoria::MenuCategoria() : Menu("Menu de Categorias"), _servicioCategoria() {}

void MenuCategoria::ejecutar(){
int opcion = 0;
    do {
        mostrarTitulo();
        cout << "1. Registrar nueva categoria\n";
        cout << "2. Modificar categoria\n";
        cout << "3. Eliminar categoria\n";
        cout << "4. Listar categorias\n";
        cout << "5. Buscar por nombre\n";
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
                _servicioCategoria.crearCategoria();
                break;

            case 2:
                _servicioCategoria.modificarCategoria();
                break;

            case 3:
                _servicioCategoria.eliminarCategoria();
                break;

            case 4:
                _servicioCategoria.listarCategorias(_servicioCategoria.obtenerCategorias());
                break;

            case 5:
                _servicioCategoria.buscarPorNombre();
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
