#include "../ServicioH/ServicioAnalisis.h"
#include "../ManagerH/ManagerAnalisis.h"
#include "../ServicioH/ServicioCategoria.h"
#include <string>
#include <iostream>

ServicioAnalisis::ServicioAnalisis(): _managerAnalisis("analisis.dat") {}

//CREAR ANALISIS   NO RECIBE POR PARAMETROS, LO PIDE AHI
bool ServicioAnalisis::crearAnalisis() {
    ServicioCategoria servicioCategoria;
    int idCategoria;
    float valor;
    int id = _managerAnalisis.obtenerNuevoId();
    std::string nombre;
    servicioCategoria.listarCategoriasActivas();
    std::vector<Categoria> activos = servicioCategoria.obtenerCategoriasActivas();
    bool categoriaValida = false;
    while (!categoriaValida) {
        std::cout << "Ingrese el ID de la categoría (0 para cancelar): ";
        std::cin >> idCategoria;

        if (idCategoria == 0) {
            std::cout << "Operación cancelada.\n";
            return false;
        }

        for (int i = 0; i < activos.size(); i++) {
            if (activos[i].getId() == idCategoria && activos[i].getEstado()) {
                categoriaValida = true;
                break;
            }
        }

        if (!categoriaValida) {
            std::cout << "ID inválido. Intente nuevamente.\n";
        }
    }
    std::cout<<"Ingrese el nombre del analisis: "<<std::endl;
    std::cin.ignore();
    std::getline(std::cin,nombre);
    std::cout<<"Ingrese el valor del analisis: $";std::cin>>valor;
    Analisis analisis(id, nombre, idCategoria, valor);
    return _managerAnalisis.guardar(analisis);
}


bool ServicioAnalisis::modificarAnalisis() {
   int posicion,id,idCategoria;
   float valor;
   bool estado;
   std::string nombre;
   ServicioCategoria servicioCategoria;
   std::cout<<"=== LISTA DE ANALISIS ==="<<std::endl;
   std::vector<Analisis> listaAnalisis = _managerAnalisis.leerTodos();
   _managerAnalisis.listarAnalisis(listaAnalisis);
   std::cout<<"Ingrese el ID correspondiente al Analisis que desea modificar: ";
   std::cin>>id;
   posicion = _managerAnalisis.buscar(id);
   if (posicion == -1) {
    return false;
    }

    Analisis analisis = _managerAnalisis.leer(posicion);
    std::cout<<"=Lista de Categorias="<<std::endl;
    servicioCategoria.listarCategoriasActivas();
    std::cout<<"-Elija la Categoria que corresponde al Analisis: ";std::cin>>idCategoria;
    analisis.setIdCategoria(idCategoria);
    std::cin.ignore();
    std::cout<<"-Ingrese el nombre del Analisis: ";std::getline(std::cin,nombre);
    analisis.setNombre(nombre);
    std::cout<<"-Ingrese el valor del Analisis: ";std::cin>>valor;
    analisis.setValor(valor);
    std::cout<<"-Esta disponible el Analisis (1 = si / 0 = no): ";std::cin>>estado;
    analisis.setEstado(estado);
    if (_managerAnalisis.modificar(analisis, posicion)) {
        std::cout << "Análisis modificado correctamente."<<std::endl;
        return true;
    } else {
        std::cout << "Error al intentar modificar el análisis."<<std::endl;
        return false;
    }
}

void ServicioAnalisis::listarAnalisisActivos(){
    std::vector<Analisis> lista = _managerAnalisis.leerTodos();
    std::vector<Analisis> activos;

    for (int i = 0; i < (int)lista.size(); i++) {
        if (lista[i].getEstado()) {
            activos.push_back(lista[i]);
        }
    }
    _managerAnalisis.listarAnalisis(activos);
}

bool ServicioAnalisis::eliminarAnalisis(){
    std::vector<Analisis> lista = _managerAnalisis.leerTodos();
    if (lista.empty()) {
        std::cout << "No hay Analisis cargados."<<std::endl;
        return false;
    }
    _managerAnalisis.listarAnalisis(lista);
    std::cout << "Ingrese el ID del Analisis a eliminar: "<<std::endl;
    int id;
    std::cin>>id;

    // (opcional: chequeos de existencia/estado)
    if (_managerAnalisis.eliminar(id)) {
        std::cout << "Analisis dado de baja correctamente."<<std::endl;
        return true;
    } else {
        std::cout << "No se encontró el Analisis o ya estaba inactivo."<<std::endl;
        return false;
    }
}

void ServicioAnalisis::buscarPorCategoria(){
    int idCategoria;
    ServicioCategoria servicioCategoria;
    servicioCategoria.listarCategoriasActivas();
    std::cout<<"Ingrese el ID de la categoria por la cual desea filtrar: ";std::cin>>idCategoria;std::cout<<std::endl;
    std::vector<Analisis> categoria = _managerAnalisis.buscarPorCategoria(idCategoria);
    std::cout<<"== Estudios Filtrados por Categoria "<<idCategoria<<" =="<<std::endl;
    for(int i = 0 ; i < categoria.size(); i ++){
        std::cout << "Categoria: " << categoria[i].getIdCategoria()
              << " | ID: " << categoria[i].getId()
              << " | Nombre: " << categoria[i].getNombre()
              << " | Valor: $" << categoria[i].getValor()
              << " | Estado: " << (categoria[i].getEstado() ? "Activo" : "Inactivo")
              << std::endl;

    }
    std::cout<<std::endl;
}
void ServicioAnalisis::listarPorNombre(){
    std::string nombre;
    std::cout<<"Ingrese el nombre del Analisis por el que quiere filtrar: ";
    std::cin.ignore();
    std::getline(std::cin,nombre);
    std::vector<Analisis> lista = _managerAnalisis.leerTodos();
    std::vector<Analisis> listaPorNombre = _managerAnalisis.buscarPorNombre(nombre);
    std::cout<<"Filtrado por: "<<nombre<<std::endl;
    for(int i = 0; i<listaPorNombre.size();i++){
        std::cout << "Categoria: " << listaPorNombre[i].getIdCategoria()
              << " | ID: " << listaPorNombre[i].getId()
              << " | Nombre: " << listaPorNombre[i].getNombre()
              << " | Valor: $" << listaPorNombre[i].getValor()
              << " | Estado: " << (listaPorNombre[i].getEstado() ? "Activo" : "Inactivo")
              << std::endl;
    }
}


void ServicioAnalisis::ordenarPorCategoria() {
    std::vector<Analisis> lista = _managerAnalisis.leerTodos();

    if (lista.size() == 0) {
        std::cout << "\nNo hay análisis cargados.\n";
        return;
    }
    for (int i = 0; i < (int)lista.size() - 1; i++) {
        for (int j = i + 1; j < (int)lista.size(); j++) {
            if (lista[i].getIdCategoria() > lista[j].getIdCategoria()) {
                Analisis aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }
    // Mostrar la lista ordenada
    std::cout << "\n=== ANALISIS ORDENADOS POR CATEGORIA ===\n";
    for (int i = 0; i < (int)lista.size(); i++) {
        std::cout << "ID Analisis: " << lista[i].getId()
                  << " | ID Categoria: " << lista[i].getIdCategoria()
                  << " | Nombre: " << lista[i].getNombre()
                  << " | Valor: $" << lista[i].getValor()
                  << " | Estado: " << (lista[i].getEstado() ? "Activo" : "Inactivo")
                  << std::endl;
    }
}














