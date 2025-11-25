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

//CREAR METODO DE PAGO
void ServicioMetodoDePago::crearMetodoDePago() {

    cout << "\n-- REGISTRAR METODO DE PAGO --\n";
    vector<MetodoDePago> lista = managerMetodoDePago.leerTodos();
    int id = managerMetodoDePago.obtenerNuevoId();
    string nombre;
    bool nombreValido = false;

    do {
    cout << "Ingrese el nombre: ";
    getline(cin, nombre);

    nombreValido = true;

    if (nombre.empty() || nombre.find_first_not_of(' ') == string::npos) {
        cout << "El nombre no puede estar vacio. Intente nuevamente."<<endl;
        nombreValido = false;
        continue;
    }

    for(int i=0;i < (int)lista.size();i++){
        if(lista[i].getNombre()==nombre){
            cout<<"Ya existe un metodo de pago con ese nombre."<<endl;
            nombreValido = false;
            break;
        }
    }
    } while (!nombreValido);

    MetodoDePago metodoPago(id, nombre);

    if (managerMetodoDePago.guardar(metodoPago)) {
        cout << "Metodo de pago registrado con exito!\n";
    } else {
        cout << "Error al intentar guardar el metodo de pago.\n";
    }
}

//MODIFICAR METODO DE PAGO
void ServicioMetodoDePago::modificarMetodoDePago() {
    std::vector <MetodoDePago> lista = managerMetodoDePago.leerTodos();

    if(lista.empty()){
        cout << "\nNo hay metodos de pago para modificar.\n";
        return;
    }

    listarMetodosDePago(lista);

    int id;
    bool idValido;
    char opcion;

    do{
        id=pedirEntero("\nIngrese el ID a modificar: ");
        idValido = false;
        for(int i=0;i < (int)lista.size();i++){
            if(lista[i].getId()==id){
                idValido = true;
                break;
            }
        }
        if(!idValido){
            cout<<"No existe ese numero de ID."<<endl;
            opcion=pedirCharSN("Quieres intentarlo nuevamente? (S/N): ");
        }
        if(opcion == 'N' || opcion == 'n'){
            cout<<"Error al modificar el metodo de pago."<<endl;
            return;
        }
    }while(!idValido);

    string nombre;
    bool nombreValido = false;
    limpiarBuffer();

    do{
        cout << "Nuevo nombre: ";
        getline(cin, nombre);

        nombreValido = true;

        if (nombre.empty() || nombre.find_first_not_of(' ')==string::npos){
            cout << "El nombre no puede estar vacio. Intente nuevamente. " << endl;
            nombreValido = false;
            continue;
        }

        for (int i=0; i < (int)lista.size(); i++){
            if (lista[i].getNombre() == nombre && lista[i].getId() != id) {
                cout << "Ya existe un metodo de pago con ese nombre. " << endl;
                nombreValido = false;
                break;
            }
        }
    }while(!nombreValido);

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

//ELIMINAR METODO DE PAGO
void ServicioMetodoDePago::eliminarMetodoDePago() {
    vector<MetodoDePago> lista = managerMetodoDePago.leerTodos();

    if(lista.empty()){
        cout << "\nNo hay metodos de pago para eliminar.\n";
        return;
    }

    listarMetodosDePago(lista);

    int id;
    cout << "Ingrese el ID a eliminar (0 para cancelar): ";
    cin >> id;

    if (id == 0){
        cout << "Operacion cancelada." << endl;
        return;
    }

    int posicion = managerMetodoDePago.buscar(id);
    if (posicion == -1){
        cout << "No se encontro un metodo de pago con ese ID. " << endl;
        return;
    }

    cout << "Esta seguro que desea eliminar este metodo de pago? (S/N): ";
    char confirma;
    cin >> confirma;

    if (confirma == 'S' || confirma == 's'){
        bool eliminado = managerMetodoDePago.eliminar(id);
        if (eliminado){
            cout << "\n-- ELIMINADO EXITOSAMENTE --\n";
        }else{
            cout << "\n-- OCURRIO UN ERROR AL ELIMINAR EL METODO DE PAGO --\n";
            }
        } else{
            cout << "Operacion cancelada. " << endl;
            return;
        }
    }

//OBTENER METODOS DE PAGO
std::vector<MetodoDePago> ServicioMetodoDePago:: obtenerMetodosDePago(){
    return managerMetodoDePago.leerTodos();
}

//LISTAR METODOS DE PAGO
void ServicioMetodoDePago::listarMetodosDePago(const std::vector<MetodoDePago>& metodosDePago) {
    if (metodosDePago.empty()) {
        cout << "No hay metodos de pago registrados.\n";
    } else {
        cout << "\n-- LISTADO DE METODOS DE PAGO --\n";
        for (int i = 0; i < (int)metodosDePago.size(); i++) {
            MetodoDePago metodoPago = metodosDePago[i];
            cout << "ID: " << metodoPago.getId()
                 << " | Nombre: " << metodoPago.getNombre()
                 << endl;
        }
    }
}
