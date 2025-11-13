#include "../ServicioH/ServicioMetodoDePago.h"
#include <iostream>
#include <limits>
using namespace std;

ServicioMetodoDePago::ServicioMetodoDePago() : managerMetodoDePago("metodos_de_pago.dat") {}

void ServicioMetodoDePago::limpiarBuffer() const {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void ServicioMetodoDePago::crearMetodoDePago() {
    cout << "\n-- REGISTRAR METODO DE PAGO --\n";

    int id = managerMetodoDePago.obtenerNuevoId();
    string nombre;

    cout << "Ingrese el nombre: ";
    limpiarBuffer();
    getline(cin, nombre);

    MetodoDePago metodoPago(id, nombre);

    if (managerMetodoDePago.guardar(metodoPago)) {
        cout << "Metodo de pago registrado con exito!\n";
    } else {
        cout << "Error al intentar guardar el metodo de pago.\n";
    }
}

void ServicioMetodoDePago::modificarMetodoDePago() {
    std::vector <MetodoDePago> lista = listarMetodosDePago();

    if(lista.empty()){
        cout << "\nNo hay metodos de pago para modificar.\n";
        return;
    }

    cout << "\nIngrese el ID a modificar: ";
    int id;
    cin >> id;
    limpiarBuffer();

    string nombre;

    cout << "Nuevo nombre: ";
    getline(cin, nombre);

    int posicion = managerMetodoDePago.buscar(id);
    if (posicion == -1) {
        cout << "No se encontro un metodo de pago con ese ID.\n";
        return;
    }

    MetodoDePago metodoPago = managerMetodoDePago.leer(posicion);
    metodoPago.setNombre(nombre);

    if (managerMetodoDePago.modificar(metodoPago, posicion)) {
        cout << "Metodo de pago modificado con exito!\n";
    } else {
        cout << "Error al intentar modificar el metodo de pago.\n";
    }
}

void ServicioMetodoDePago::eliminarMetodoDePago() {
    std::vector<MetodoDePago> lista = listarMetodosDePago();

    if(lista.empty()){
        cout << "\nNo hay metodos de pago para eliminar.\n";
        return;
    }

    cout << "\nIngrese el ID a eliminar: ";
    int id;
    cin >> id;

    bool eliminado = managerMetodoDePago.eliminar(id);

    if(eliminado){
        cout << "\n-- ELIMINADO EXITOSAMENTE --\n";
     }else{
         cout << "\n-- OCURRIO UN ERROR AL ELIMINAR EL METODO DE PAGO --\n";
    }
}

std::vector <MetodoDePago> ServicioMetodoDePago::listarMetodosDePago() {
    cout << "\n-- LISTADO DE METODOS DE PAGO --\n";

    vector<MetodoDePago> metodosPago = managerMetodoDePago.leerTodos();

    if (metodosPago.empty()) {
        cout << "No hay metodos de pago registrados.\n";
    } else {
        for (int i = 0; i < metodosPago.size(); i++) {
            MetodoDePago metodoPago = metodosPago[i];
            cout << "ID: " << metodoPago.getId()
                 << " | Nombre: " << metodoPago.getNombre()
                 << "\n";
        }
    }

    return metodosPago;
}
