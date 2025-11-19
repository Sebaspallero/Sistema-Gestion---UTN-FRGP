#include "../ServicioH/ServicioPaciente.h"
#include <iostream>
#include <limits>
using namespace std;

ServicioPaciente::ServicioPaciente() : managerPaciente("pacientes.dat"), servicioObraSocial() {}

void ServicioPaciente::limpiarBuffer() const {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void ServicioPaciente::crearPaciente() {
    cout << "\n-- REGISTRAR PACIENTE --\n";

    int id = managerPaciente.obtenerNuevoId();
    string nombre, apellido, email, telefono;
    int dia, mes, anio, dni, codigoObraSocial;

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

    cout << "Ingrese telefono: ";
    getline(cin, telefono);

    std::vector<ObraSocial> lista = servicioObraSocial.obtenerObrasSociales();

    if (lista.empty()) {
        cout << "\nNo hay obras sociales registradas. No se puede registrar paciente.\n";
        return;
    }

    servicioObraSocial.listarObrasSociales(lista);

    cout << "Ingrese el codigo de la obra social: ";
    cin >> codigoObraSocial;

    Fecha fechaNacimiento(dia, mes, anio);

    Paciente paciente(id, nombre, apellido, fechaNacimiento, dni, email, telefono, codigoObraSocial);

    if(managerPaciente.guardar(paciente)){
        cout << "Paciente creado con exito!\n";
    } else {
        cout << "Error al intentar crear el paciente.\n";
    }
}

std::vector<Paciente> ServicioPaciente :: obtenerPacientes(){
    return managerPaciente.leerTodos();
}

void ServicioPaciente::listarPacientes(const std::vector<Paciente>& pacientes) {
    if (pacientes.empty()) {
        cout << "No hay pacientes registrados.\n";
    } else {
        cout << "\n-- LISTADO DE PACIENTES --\n";
        for (int i = 0; i < pacientes.size(); i++) {
            Paciente paciente = pacientes[i];
            cout << "ID: " << paciente.getId()
                 << " | Nombre: " << paciente.getNombre()
                 << " | Apellido: " << paciente.getApellido()
                 << " | DNI: " << paciente.getDNI()
                 << " | Obra Social: " << paciente.getCodigoObraSocial()
                 << "\n";
        }
    }
}

void ServicioPaciente::eliminarPaciente() {
    std::vector<Paciente> lista = obtenerPacientes();

    if (lista.empty()) {
        cout << "\nNo hay pacientes para eliminar.\n";
        return;
    }

    listarPacientes(lista);
    cout << "\nIngrese el ID a eliminar: ";
    int id;
    cin >> id;

    bool eliminado = managerPaciente.eliminar(id);

    if (eliminado) {
        cout << "\n-- ELIMINADO EXITOSAMENTE --\n";
    } else {
        cout << "\n-- OCURRIO UN ERROR AL ELIMINAR EL PACIENTE --\n";
    }
}

void ServicioPaciente::modificarPaciente() {
    std::vector<Paciente> lista = obtenerPacientes();

    if (lista.empty()) {
        cout << "\nNo hay pacientes para modificar.\n";
        return;
    }

    listarPacientes(lista);
    cout << "\nIngrese el ID a modificar: ";
    int id;
    cin >> id;
    limpiarBuffer();

    string nombre, apellido, email, telefono;
    int dia, mes, anio, dni, codigoObraSocial;

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

    cout << "Nuevo telefono: ";
    getline(cin, telefono);

    std::vector<ObraSocial> listaObras = servicioObraSocial.obtenerObrasSociales();

    if (listaObras.empty()) {
        cout << "\nNo hay obras sociales registradas. No se puede modificar paciente.\n";
        return;
    }

    servicioObraSocial.listarObrasSociales(listaObras);

    cout << "Nuevo codigo de obra social: ";
    cin >> codigoObraSocial;

    int posicion = managerPaciente.buscar(id);
    if (posicion == -1) {
        cout << "No se encontro un paciente con ese ID.\n";
        return;
    }

    Fecha fechaNacimiento(dia, mes, anio);

    Paciente paciente = managerPaciente.leer(posicion);
    paciente.setNombre(nombre);
    paciente.setApellido(apellido);
    paciente.setFechaNacimiento(fechaNacimiento);
    paciente.setDNI(dni);
    paciente.setEmail(email);
    paciente.setTelefono(telefono);
    paciente.setCodigoObraSocial(codigoObraSocial);

    if(managerPaciente.modificar(paciente, posicion)){
        cout << "Paciente modificado con exito!\n";
    } else {
        cout << "Error al intentar modificar el paciente.\n";
    }
}

void ServicioPaciente::buscarPacientePorDNI() {
    cout << "\nIngrese el DNI a buscar: ";
    int dni;
    cin >> dni;

    Paciente paciente = managerPaciente.buscarPorDNI(dni);

    if (paciente.getId() > 0) {
        cout << "ID: " << paciente.getId()
             << " | Nombre: " << paciente.getNombre()
             << " | Apellido: " << paciente.getApellido()
             << " | DNI: " << paciente.getDNI()
             << "\n";
    } else {
        cout << "No se encontro el paciente.\n";
    }
}

void ServicioPaciente::buscarPacientePorApellido() {
    cout << "\nIngrese el apellido a buscar: ";
    string apellido;
    limpiarBuffer();
    getline(cin, apellido);

    vector<Paciente> resultados = managerPaciente.buscarPorApellido(apellido);

    if (resultados.empty()) {
        cout << "No se encontraron pacientes con ese apellido.\n";
    } else {
        for (int i = 0; i < resultados.size(); i++) {
            Paciente paciente = resultados[i];
            cout << "ID: " << paciente.getId()
                 << " | Nombre: " << paciente.getNombre()
                 << " | Apellido: " << paciente.getApellido()
                 << " | DNI: " << paciente.getDNI()
                 << " | Obra Social: " << paciente.getCodigoObraSocial()
                 << "\n";
        }
    }
}

std::vector<Paciente> ServicioPaciente::ordenarPacientesPorApellido() {
    std::vector<Paciente> listaOrdenada = managerPaciente.ordenarPorApellido();

    cout << "\nPacientes ordenados por apellido:\n";
    for (int i = 0; i < listaOrdenada.size(); i++) {
        cout << "Apellido: " << listaOrdenada[i].getApellido() << endl;
        cout << "Nombre: " << listaOrdenada[i].getNombre() << endl;
        cout << "DNI: " << listaOrdenada[i].getDNI() << endl;
        cout << "Obra Social: " << listaOrdenada[i].getCodigoObraSocial() << endl;
        cout << "-------------------------" << endl;
    }
    return listaOrdenada;
}
