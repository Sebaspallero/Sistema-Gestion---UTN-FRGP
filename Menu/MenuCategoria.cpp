#include "../MenuH/Menu.h"
#include "../MenuH/MenuCategoria.h"
#include "../ServicioH/ServicioCategoria.h"

MenuCategoria::MenuCategoria() : Menu("Menu de Categorias"), _servicioCategoria() {}

void MenuCategoria::ejecutar(){
int opcion = 0;
    do {
        mostrarTitulo();
        std::cout << "1. Registrar nueva Categoria"<<std::endl;
        std::cout << "2. Modificar Categoria"<<std::endl;
        std::cout << "3. Eliminar Categoria"<<std::endl;
        std::cout << "4. Listar Categorias activas"<<std::endl;
        std::cout << "5. Buscar Categorias por nombre"<<std::endl;
        std::cout << "0. Volver al menu principal"<<std::endl;
        std::cout << "Seleccione una opcion: ";

        if (!(std::cin >> opcion)) {
            std::cout << "Entrada invalida."<<std::endl;
            limpiarBuffer();
            continue;
        }
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

            case 4: {
                _servicioCategoria.listarCategoriasActivas();
                break;
            }

            case 5: {
                _servicioCategoria.buscarPorNombre();
                break;
            }

            case 0:
                std::cout << "\nVolviendo al menú principal..."<< std::endl;
                break;

            default:
                std::cout << "\nOpción inválida. Intente nuevamente."<< std::endl;
                break;
        }
    } while (opcion != 0);

}
