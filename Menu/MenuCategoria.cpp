#include "../MenuH/Menu.h"
#include "../MenuH/MenuCategoria.h"
#include "../ServicioH/ServicioCategoria.h"
#include "../ServicioH/ServiciosUtilidades.h"

using namespace std;

MenuCategoria::MenuCategoria() : Menu("Menu de Categorias"), _servicioCategoria() {}

void MenuCategoria::ejecutar(){
    int opcion;

    do {
        system("cls");
        mostrarTitulo();
        cout << "1. Registrar nueva categoria\n";
        cout << "2. Eliminar categoria\n";
        cout << "3. Modificar categoria\n";
        cout << "4. Listar categorias\n";
        cout << "------------------------------\n";
        cout << "5. Buscar por nombre\n";
        cout << "0. Volver al menu principal\n";
        opcion = pedirEntero("Seleccione una opcion: ");

        limpiarBuffer();
        switch (opcion) {
            case 1:
                _servicioCategoria.crearCategoria();
                pausar();
                break;

            case 2:
                _servicioCategoria.eliminarCategoria();
                pausar();
                break;

            case 3:
                _servicioCategoria.modificarCategoria();
                pausar();
                break;

            case 4:
                _servicioCategoria.listarCategorias(_servicioCategoria.obtenerCategorias());
                pausar();
                break;

            case 5:
                _servicioCategoria.buscarPorNombre();
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
