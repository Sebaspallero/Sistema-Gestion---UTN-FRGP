#include "../ServicioH/ServicioBioquimico.h"
#include "../ManagerH/Manager.h"
#include <iostream>
#include <limits>
using namespace std;

ServicioBioquimico::ServicioBioquimico() : managerBioquimico("bioquimicos.dat") {}

void ServicioBioquimico::limpiarBuffer() const {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void ServicioBioquimico::crearBioquimico() {
    cout << "\n-- REGISTRAR BIOQUIMICO --\n";

    int id = managerBioquimico.obtenerNuevoId();
    string nombre, apellido, email;
    int dia, mes, anio, dni, matricula;

    cout << "Ingrese nombre: ";
    limpiarBuffer();
    getline(cin, nombre);

    cout << "Ingrese apellido: ";
    getline(cin, apellido);

    cout << "Ingrese dia de nacimiento: ";
    cin >> dia;

    cout << "Ingrese mes de nacimiento: ";
    cin >> mes;

    cout << "Ingrese año de nacimiento: ";
    cin >> anio;

    cout << "Ingrese DNI: ";
    cin >> dni;
    limpiarBuffer();

    cout << "Ingrese email: ";
    getline(cin, email);

    cout << "Ingrese matricula: ";
    cin >> matricula;

    Fecha fechaNacimiento(dia, mes, anio);

    Bioquimico bioquimico(id, nombre, apellido, fechaNacimiento, dni, email, matricula);

    if(managerBioquimico.guardar(bioquimico)){
        cout << "Bioquimico creado con exito!\n";
    } else {
        cout << "Error al intentar crear el Bioquimico.\n";
    }
}

void ServicioBioquimico::modificarBioquimico() {
    std::vector<Bioquimico> lista = listarBioquimicos();

    if (lista.empty()) {
        cout << "\nNo hay bioquimicos para modificar.\n";
        return;
    }

    cout << "\nIngrese el ID a modificar: ";
    int id;
    cin >> id;
    limpiarBuffer();

    string nombre, apellido, email;
    int dia, mes, anio, dni, matricula;

    cout << "Nuevo nombre: ";
    getline(cin, nombre);

    cout << "Nuevo apellido: ";
    getline(cin, apellido);

    cout << "Nuevo dia de nacimiento: ";
    cin >> dia;

    cout << "Nuevo mes de nacimiento: ";
    cin >> mes;

    cout << "Nuevo año de nacimiento: ";
    cin >> anio;

    //HACER VALIDACIONES DE QUE LOS DIAS, MES, ANIO INGRESADOS SEAN INT

    cout << "Nuevo DNI: ";
    cin >> dni;
    limpiarBuffer();

    cout << "Nuevo email: ";
    getline(cin, email);

    cout << "Nueva matricula: ";
    cin >> matricula;
    limpiarBuffer();

    int posicion = managerBioquimico.buscar(id);
    if (posicion == -1) {
        cout << "No se encontro un bioquimico con ese ID.\n";
        return;
    }

    Fecha fechaNacimiento(dia, mes, anio);

    Bioquimico bioquimico = managerBioquimico.leer(posicion);
    bioquimico.setNombre(nombre);
    bioquimico.setApellido(apellido);
    bioquimico.setFechaNacimiento(fechaNacimiento);
    bioquimico.setDNI(dni);
    bioquimico.setEmail(email);
    bioquimico.setMatricula(matricula);

    if(managerBioquimico.modificar(bioquimico, posicion)){
        cout << "Bioquimico modificado con exito!\n";
    } else {
        cout << "Error al intentar modificar el bioquimico.\n";
    }
}

std::vector<Bioquimico> ServicioBioquimico::listarBioquimicos() {
    cout << "\n-- LISTADO DE BIOQUIMICOS --\n";

    vector<Bioquimico> bioquimicos = managerBioquimico.leerTodos();

    if (bioquimicos.empty()) {
        cout << "No hay bioquimicos registrados.\n";
    } else {
        for (int i = 0; i < bioquimicos.size(); i++) {
            Bioquimico bioquimico = bioquimicos[i];
            cout << "ID: " << bioquimico.getId()
                 << " | Nombre: " << bioquimico.getNombre()
                 << " | Apellido: " << bioquimico.getApellido()
                 << " | DNI: " << bioquimico.getDNI()
                 << " | Matricula: " << bioquimico.getMatricula()
                 << "\n";
        }
    }

    return bioquimicos;
}

void ServicioBioquimico::eliminarBioquimico() {
    std::vector<Bioquimico> lista = listarBioquimicos();

    if (lista.empty()) {
        cout << "\nNo hay bioquimicos para eliminar.\n";
        return;
    }

    cout << "\nIngrese el ID a eliminar: ";
    int id;
    cin >> id;

    bool eliminado = managerBioquimico.eliminar(id);

    if (eliminado) {
        cout << "\n-- ELIMINADO EXITOSAMENTE --\n";
    } else {
        cout << "\n-- OCURRIO UN ERROR AL ELIMINAR EL BIOQUIMICO --\n";
    }
}

std::vector<Bioquimico> ServicioBioquimico::ordenarBioquimicosPorApellido() {
    std::vector<Bioquimico> listaOrdenada = managerBioquimico.ordenarPorApellido();

    cout << "\nBioquimicos ordenados por apellido:\n";
    for (int i = 0; i < listaOrdenada.size(); i++) {
        cout << "Apellido: " << listaOrdenada[i].getApellido() << endl;
        cout << "Nombre: " << listaOrdenada[i].getNombre() << endl;
        cout << "Matricula: " << listaOrdenada[i].getMatricula() << endl;
        cout << "-------------------------" << endl;
    }
    return listaOrdenada;
}

std::vector<Bioquimico> ServicioBioquimico::ordenarBioquimicosPorLegajo() {
    std::vector<Bioquimico> listaOrdenada = managerBioquimico.ordenarPorLegajo();

    cout << "\nBioquimicos ordenados por legajo:\n";
    for (int i = 0; i < listaOrdenada.size(); i++) {
        cout << "Matricula: " << listaOrdenada[i].getMatricula() << endl;
        cout << "Apellido: " << listaOrdenada[i].getApellido() << endl;
        cout << "Nombre: " << listaOrdenada[i].getNombre() << endl;
        cout << "-------------------------" << endl;
    }
    return listaOrdenada;
}
