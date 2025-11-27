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
    system("cls");
    cout << "\n-- REGISTRAR METODO DE PAGO --\n";

    vector<MetodoDePago> lista = managerMetodoDePago.leerTodos();
    int id = managerMetodoDePago.obtenerNuevoId();
    string nombre;

    while (true) {
        cout << "Ingrese el nombre (0 para cancelar): ";
        getline(cin, nombre);

        if (nombre == "0") return;

        if (nombre.empty() || nombre.find_first_not_of(' ') == string::npos) {
            cout << "El nombre no puede estar vacio.\n";
            continue;
        }

        bool duplicado = false;
        for (const MetodoDePago& mp : lista) {
            if (mp.getNombre() == nombre) {
                duplicado = true;
                break;
            }
        }

        if (duplicado) {
            cout << "Ya existe un metodo de pago con ese nombre.\n";
            continue;
        }

        break;
    }

    MetodoDePago metodoPago(id, nombre);

    if (managerMetodoDePago.guardar(metodoPago)) {
        cout << "Metodo de pago registrado con exito!\n";
    } else {
        cout << "Error al intentar guardar el metodo de pago.\n";
    }
}

//MODIFICAR METODO DE PAGO
void ServicioMetodoDePago::modificarMetodoDePago() {
    system("cls");
    vector<MetodoDePago> lista = managerMetodoDePago.leerTodos();

    if (lista.empty()) {
        cout << "\nNo hay metodos de pago para modificar.\n";
        return;
    }

    listarMetodosDePago(lista);

    int id;
    int posicion = -1;

    // Selección de ID
    while (true) {
        cout << "\nIngrese el ID a modificar (0 para cancelar): ";

        if (!(cin >> id)) {
            cout << "Debe ingresar un numero.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (id == 0) return;

        posicion = managerMetodoDePago.buscar(id);
        if (posicion != -1) break;

        cout << "No existe un metodo de pago con ese ID.\n";
    }
    system("cls");
    MetodoDePago metodo = managerMetodoDePago.leer(posicion);

    string nombre;

    while (true) {
        cout << "Nuevo nombre [" << metodo.getNombre() << "] (0 para cancelar): ";
        getline(cin, nombre);

        if (nombre == "0") return;

        if (nombre.empty()) {
            nombre = metodo.getNombre(); // acepta el anterior
            break;
        }

        if (nombre.find_first_not_of(' ') == string::npos) {
            cout << "El nombre no puede ser vacio.\n";
            continue;
        }

        bool duplicado = false;
        for (const MetodoDePago& mp : lista) {
            if (mp.getId() != id && mp.getNombre() == nombre) {
                duplicado = true;
                break;
            }
        }

        if (duplicado) {
            cout << "Ya existe un metodo de pago con ese nombre.\n";
            continue;
        }

        break;
    }

    metodo.setNombre(nombre);

    if (managerMetodoDePago.modificar(metodo, posicion)) {
        cout << "Metodo de pago modificado con exito!\n";
    } else {
        cout << "Error al intentar modificar el metodo de pago.\n";
    }
}

//ELIMINAR METODO DE PAGO
void ServicioMetodoDePago::eliminarMetodoDePago() {
    system("cls");
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
    system("cls");
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
