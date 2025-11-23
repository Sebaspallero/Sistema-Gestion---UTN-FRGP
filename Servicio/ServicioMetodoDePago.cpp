#include "../ServicioH/ServicioMetodoDePago.h"
#include "../ServicioH/ServiciosUtilidades.h"
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
    vector<MetodoDePago> lista = managerMetodoDePago.leerTodos();
    int id = managerMetodoDePago.obtenerNuevoId();
    string nombre;
    bool bandera;
    do {
    bandera = true;
    cout << "Ingrese el nombre: ";
    getline(cin, nombre);
    for(int i=0;i<lista.size();i++){
        if(lista[i].getNombre()==nombre){
            cout<<"Ya existe un metodo de pago con ese nombre."<<endl;
            bandera = false;
        }
    }
    if (nombre.empty() || nombre.find_first_not_of(' ') == string::npos) {
        cout << "El nombre no puede estar vacío. Intente nuevamente."<<endl;
    }

    } while (nombre.empty() || nombre.find_first_not_of(' ') == string::npos || bandera == false);

    MetodoDePago metodoPago(id, nombre);

    if (managerMetodoDePago.guardar(metodoPago)) {
        cout << "Metodo de pago registrado con exito!\n";
    } else {
        cout << "Error al intentar guardar el metodo de pago.\n";
    }
}

void ServicioMetodoDePago::modificarMetodoDePago() {
    std::vector <MetodoDePago> lista = managerMetodoDePago.leerTodos();
    if(lista.empty()){
        cout << "\nNo hay metodos de pago para modificar.\n";
        return;
    }
    listarMetodosDePago(lista);
    int id;
    bool bandera;
    char opcion;

    do{
        id=pedirEntero("\nIngrese el ID a modificar: ");
        bandera = false;
        for(int i=0;i<lista.size();i++){
            if(lista[i].getId()==id){
                bandera = true;
                break;
            }
        }
        if(!bandera){
            cout<<"No existe ese numero de ID."<<endl;
            opcion=pedirCharSN("Quieres intentarlo nuevamente? S/N (S = Si / N = No)");
        }
        if(opcion == 'N' || opcion == 'n'){
            cout<<"Error al modificar el metodo de pago."<<endl;
            return;
        }
    }while(bandera == false);
    string nombre;
    limpiarBuffer();
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
    std::vector<MetodoDePago> lista = managerMetodoDePago.leerTodos();

    if(lista.empty()){
        cout << "\nNo hay metodos de pago para eliminar.\n";
        return;
    }
    listarMetodosDePago(lista);

    int id;
    bool bandera;
    char opcion;
    do{
        id=pedirEntero("Ingrese el ID a eliminar: ");
        bandera = false;
        for(int i=0;i<lista.size();i++){
            if(lista[i].getId()==id){
                bandera = true;
            }
        }
        if(!bandera){
            cout<<"No existe ese numero de ID."<<endl;
            opcion=pedirCharSN("Quieres intentarlo nuevamente? S/N (S = Si / N = No)");
        }
        if(opcion == 'N' || opcion == 'n'){
            bandera = true;
        }
    }while(bandera == false);
    bool eliminado = managerMetodoDePago.eliminar(id);

    if(eliminado){
        cout << "\n-- ELIMINADO EXITOSAMENTE --\n";
     }else{
         cout << "\n-- OCURRIO UN ERROR AL ELIMINAR EL METODO DE PAGO --\n";
    }
}

std::vector<MetodoDePago> ServicioMetodoDePago:: obtenerMetodosDePago(){
    return managerMetodoDePago.leerTodos();
}

void ServicioMetodoDePago::listarMetodosDePago(const std::vector<MetodoDePago>& metodosDePago) {
    if (metodosDePago.empty()) {
        cout << "No hay metodos de pago registrados.\n";
    } else {
        cout << "\n-- LISTADO DE METODOS DE PAGO --\n";
        for (int i = 0; i < metodosDePago.size(); i++) {
            MetodoDePago metodoPago = metodosDePago[i];
            cout << "ID: " << metodoPago.getId()
                 << " | Nombre: " << metodoPago.getNombre()
                 << "\n";
        }
    }
}


