#include "../MenuH/Menu.h"
#include "../MenuH/MenuCategoria.h"
#include "../ServicioH/ServicioCategoria.h"

using namespace std;

MenuCategoria::MenuCategoria() : Menu("Menu de Categorias"), _servicioCategoria() {}

void MenuCategoria::ejecutar(){
    int opcion = -1;

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
        cout << "Seleccione una opcion: ";

        if (!(cin>>opcion)) {
            system("cls");
            cout << "Entrada invalida. Debe ingresar un numero. " << endl;
            limpiarBuffer();
            opcion = -1;
            pausar();
        }

        else{
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
        }

    } while (opcion != 0);

}
