#include "../ManagerH/ManagerCategoria.h"
#include "../EntidadesH/Categoria.h"
#include "../ServicioH/ServicioCategoria.h"
#include "../ManagerH/Manager.h"
#include "../ManagerH/ManagerAnalisis.h"
#include <cstring>
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

ServicioCategoria::ServicioCategoria(): _managerCategoria("categorias.dat") {}

//CREAR CATEGORÍA
void ServicioCategoria::crearCategoria() {
    int id = _managerCategoria.obtenerNuevoId();
    string nombre;
    do{
        std::cout<<"Ingrese el nombre de la categoria: "<<std::endl;
        std::getline(std::cin,nombre);
        if(nombre.empty() || nombre.find_first_not_of(' ') == std::string::npos){
            std::cout<<"El nombre no puede ser vacio. Intentelo nuevamente."<<std::endl;
        }
    }while(nombre.empty() || nombre.find_first_not_of(' ') == std::string::npos);
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

    int id;
    int posicion;
    string nombre;
    listarCategorias(listaCategorias);
    // VALIDAR ID
    cout << "Ingrese el ID de la categoria a modificar: ";

    while (!(cin >> id)) {
        cout << "Error: Debe ingresar un número entero.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ingrese el ID: ";
    }
    cin.ignore();

    posicion = _managerCategoria.buscar(id);
    if (posicion == -1) {
        cout << "No se encontró una categoría activa con ese ID.\n";
        return;
    }


    do {
        cout << "Ingrese el nuevo nombre de la categoría: ";
        getline(cin, nombre);

        if (nombre.empty() || nombre.find_first_not_of(' ') == string::npos) {
            cout << "El nombre no puede estar vacío. Intente nuevamente.\n";
        }

    } while (nombre.empty() || nombre.find_first_not_of(' ') == string::npos);

    // MODIFICAR
    Categoria categoria = _managerCategoria.leer(posicion);
    categoria.setNombre(nombre);

    if (_managerCategoria.modificar(categoria, posicion)) {
        cout << "Categoria modificada con exito!\n";
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
        cout << std::endl << "-- LISTADO DE CATEGORIAS --"<< std::endl;
        for (int i = 0; i < categorias.size(); i++) {
            Categoria categoria = categorias[i];
            cout << "ID: " << categoria.getId()
                 << " | Nombre: " << categoria.getNombre()
                 << std::endl;
        }
    }
}

void ServicioCategoria::eliminarCategoria() {
    std::vector<Categoria> lista = _managerCategoria.leerTodos();

    if(lista.empty()){
        cout << "\n No hay categorias para eliminar.\n";
        return;
    }
    listarCategorias(lista);
    cout << std::endl << " Ingrese el ID a eliminar: ";
    int id;
    cin >> id;

    bool eliminado = _managerCategoria.eliminar(id);

    if(eliminado){
        cout << std::endl << "-- ELIMINADO EXITOSAMENTE --"<< std::endl;
     }else{
         cout << std::endl << "-- OCURRIO UN ERROR AL ELIMINAR LA CATEGORIA --"<< std::endl;
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

std::string ServicioCategoria::buscarPorId(int id){
    bool encontro = false;
    std::string nombreCategoria = _managerCategoria.buscarPorId(id, encontro);
    if (!encontro) {
        return "Desconocida";
    }
    return nombreCategoria;
}




