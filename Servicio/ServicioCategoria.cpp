#include "../ManagerH/ManagerCategoria.h"
#include "../EntidadesH/Categoria.h"
#include "../ServicioH/ServicioCategoria.h"
#include "../ManagerH/Manager.h"
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

ServicioCategoria::ServicioCategoria(): _managerCategoria("categorias.dat") {}

//CREAR CATEGORÍA
void ServicioCategoria::crearCategoria() {
    int id = _managerCategoria.obtenerNuevoId();
    string nombre;

    cout<<"Ingrese el nombre de la categoria: "<<endl;
    cin.ignore();
    getline(cin,nombre);

    Categoria categoria (id, nombre);

    if(_managerCategoria.guardar(categoria)){
        cout << "Categoria registrada con exito!\n";
    }else{
        cout << "Error al intentar guardar una categoria.\n";
    }
}


//MODIFICAR CATEGORIA
void ServicioCategoria::modificarCategoria() {
    std::vector<Categoria> listaCategorias = _managerCategoria.leerTodos();

    if(listaCategorias.empty()){
        cout << "\nNo hay categorias para modificar.\n";
        return;
    }

    int posicion;
    int id;
    string nombre;

    cout<<"Elija el ID de la Categoria a modificar: "<<endl;
    cin>>id;

    cout<<"Ingrese el nuevo nombre de la categoria: "<<endl;
    cin.ignore();
    getline(cin,nombre);

    posicion = _managerCategoria.buscar(id);
    if (posicion == -1) {
        cout << "No se encontro una categoria con ese ID.\n";
        return;
    }

    Categoria categoria = _managerCategoria.leer(posicion);
    categoria.setNombre(nombre);

    if (_managerCategoria.modificar(categoria, posicion)) {
        cout << "categoria modificada con exito!\n";
    } else {
        cout << "Error al intentar modificar la categoria.\n";
    }
}

 std::vector<Categoria> ServicioCategoria::obtenerCategorias(){
    return _managerCategoria.leerTodos();
}

void ServicioCategoria::listarCategorias(const std::vector<Categoria>& categorias) {
    if (categorias.empty()) {
        cout << "No hay categorias registrados.\n";
    } else {
        cout << "\n-- LISTADO DE CATEGORIAS --\n";
        for (int i = 0; i < categorias.size(); i++) {
            Categoria categoria = categorias[i];
            cout << "ID: " << categoria.getId()
                 << " | Nombre: " << categoria.getNombre()
                 << "\n";
        }
    }
}

void ServicioCategoria::eliminarCategoria() {
    std::vector<Categoria> lista = _managerCategoria.leerTodos();

    if(lista.empty()){
        cout << "\nNo hay categorias para eliminar.\n";
        return;
    }

    cout << "\nIngrese el ID a eliminar: ";
    int id;
    cin >> id;

    bool eliminado = _managerCategoria.eliminar(id);

    if(eliminado){
        cout << "\n-- ELIMINADO EXITOSAMENTE --\n";
     }else{
         cout << "\n-- OCURRIO UN ERROR AL ELIMINAR LA CATEGORIA --\n";
    }
}


void ServicioCategoria::buscarPorNombre(){
    bool encontro = false;
    std::string nombre;

    std::cout<<"Ingrese el nombre de la categoria que desea buscar: ";
    std::cin.ignore();
    std::getline(std::cin,nombre);

    Categoria categoria = _managerCategoria.buscarPorNombre(nombre, encontro);

    if(encontro){
        std::cout<<"ID : "<<categoria.getId()<<" | Nombre: " <<categoria.getNombre()<<std::endl;
    }else{
        std::cout<<"No se encontro ninguna categoria con ese nombre. Intentelo nuevamente."<<std::endl;
    }

}
