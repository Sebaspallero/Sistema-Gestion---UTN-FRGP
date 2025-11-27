#include "../ServicioH/ServicioBioquimico.h"
#include "../ManagerH/Manager.h"
#include "../ServicioH/ServiciosUtilidades.h"
#include <iostream>
#include <limits>
using namespace std;

//CONSTRUCTORES
ServicioBioquimico::ServicioBioquimico() : managerBioquimico("bioquimicos.dat") {}

void ServicioBioquimico::limpiarBuffer() const {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//COMPROBAR DNI UNICO
bool ServicioBioquimico::existeDNI(int dni) {
    vector<Bioquimico> lista = managerBioquimico.leerTodos();
    for (int i = 0; i < (int)lista.size(); i++) {
        if (lista[i].getDNI() == dni) return true;
    }
    return false;
}

//COMPROBAR MATRICULA UNICA
bool ServicioBioquimico::existeMatricula(int matricula) {
    vector<Bioquimico> lista = managerBioquimico.leerTodos();
    for (int i = 0; i < (int)lista.size(); i++) {
        if (lista[i].getMatricula() == matricula) return true;
    }
    return false;
}

//CREAR BIOQUIMICO
void ServicioBioquimico::crearBioquimico() {
    system("cls");
    cout << "\n-- REGISTRAR BIOQUIMICO --\n";

    int id = managerBioquimico.obtenerNuevoId();
    string nombre, apellido, email;
    int dni, matricula;

    //NOMBRE
    while (true) {
        cout << "Ingrese nombre (0 para salir): ";
        getline(cin, nombre);

        if (nombre == "0") return;

        if (!nombre.empty() && nombre.find_first_not_of(' ') != string::npos) break;

        cout << "El nombre no puede estar vacio.\n";
    }

    //APELLIDO
    while (true) {
        cout << "Ingrese apellido (0 para salir): ";
        getline(cin, apellido);

        if (apellido == "0") return;

        if (!apellido.empty() && apellido.find_first_not_of(' ') != string::npos) break;

        cout << "El apellido no puede estar vacio.\n";
    }

    //FECHA NACIMIENTO
    cout << "(Ingrese 0 en cualquier campo para cancelar)\n";
    Fecha fechaNacimiento = pedirFecha("Ingrese la fecha de nacimiento:", 1900, 2025);
    if (fechaNacimiento.getAnio() == 0) return;

    limpiarBuffer();

    //DNI
    while (true) {
        cout << "Ingrese DNI (0 para salir): ";
        if (cin >> dni) {
            if (dni == 0) {
                limpiarBuffer();
                return;
            }
            if (dni > 0) {
                if (!existeDNI(dni)) {
                    limpiarBuffer();
                    break;
                } else cout << "Error: Ya existe un bioquimico con ese DNI." << endl;
            } else cout << "El DNI debe ser positivo." << endl;
        } else {
            cout << "Error: Debe ingresar un numero." << endl;
            limpiarBuffer();
        }
    }

    //EMAIL
    while (true) {
        cout << "Ingrese email (0 para salir): ";
        getline(cin, email);

        if (email == "0") return;

        if (!email.empty()) break;

        cout << "El email no puede estar vacio.\n";
    }

    //MATRICULA
    while (true) {
        cout << "Ingrese matricula (0 para salir): ";
        if (cin >> matricula) {

            if (matricula == 0) {
                limpiarBuffer();
                return;
            }

            if (matricula > 0) {
                if (!existeMatricula(matricula)){
                    limpiarBuffer();
                    break;
                } else cout << "Error: Ya existe un bioquimico con esa matricula." << endl;
            } else cout << "La matricula debe ser positiva." << endl;
        } else {
            cout << "Error: Debe ingresar un numero." << endl;
            limpiarBuffer();
        }
    }

    Bioquimico bioquimico(id, nombre, apellido, fechaNacimiento, dni, email, matricula);

    if(managerBioquimico.guardar(bioquimico)){
        cout << "Bioquimico creado con exito!\n";
    } else {
        cout << "Error al intentar crear el Bioquimico.\n";
    }
}

//MODIFICAR BIOQUIMICO
void ServicioBioquimico::modificarBioquimico() {
    system("cls");
    std::vector<Bioquimico> lista = managerBioquimico.leerTodos();

    if (lista.empty()) {
        cout << "\nNo hay bioquimicos para modificar.\n";
        return;
    }

    listarBioquimicos(lista);

    int id;
    int posicion = -1;

    //ID
    while (true) {
        cout << "\nIngrese el ID a modificar (0 para salir): ";
        if (cin >> id) {
            if (id == 0) return;
            posicion = managerBioquimico.buscar(id);
            if (posicion != -1) {
                limpiarBuffer();
                break;
            }
            cout << "No se encontro un bioquimico con ese ID.\n";
        } else {
            cout << "Error: Debe ingresar un numero.\n";
            limpiarBuffer();
        }
    }

    Bioquimico bioquimico = managerBioquimico.leer(posicion);
    system("cls");
    string nombre, apellido, email;
    int dni, matricula;

    cout << "\n-- MODIFICANDO DATOS (Presione ENTER en textos para mantener el actual, 0 para cancelar) --\n";

    //NOMBRE
    cout << "Nombre actual [" << bioquimico.getNombre() << "]: ";
    getline(cin, nombre);
    if (nombre == "0") return;
    if (nombre.empty()){
            nombre = bioquimico.getNombre();
    } else{
           if (nombre.find_first_not_of(' ')==string::npos){
            cout << "El nombre no pueden ser solo espacios. Se mantiene el actual." << endl;
            nombre = bioquimico.getNombre();
           }
    }

    //APELLIDO
    cout << "Apellido actual [" << bioquimico.getApellido() << "]: ";
    getline(cin, apellido);
    if (apellido == "0") return;
    if (apellido.empty()){
            apellido = bioquimico.getApellido();
    } else{
            if (apellido.find_first_not_of(' ')==string::npos){
                cout << "El apellido no pueden ser solo espacios. Se mantiene el actual." << endl;
                apellido = bioquimico.getApellido();
            }
        }

    //FECHA NACIMIENTO
    cout << "\n-- Fecha de nacimiento actual: "
     << bioquimico.getFechaNacimiento().toString() << "\n";

    cout << "(Ingrese 0 en cualquier campo para cancelar)\n";

    Fecha fechaNacimiento = pedirFecha("Ingrese nueva fecha:", 1900, 2025);

    if (fechaNacimiento.getAnio() == 0) return;

    // DNI
    while (true) {
        cout << "Nuevo DNI [" << bioquimico.getDNI() << "]: ";
        if (cin >> dni) {
            if (dni == 0) {
                limpiarBuffer();
                return;
            }
            if (dni > 0) {
                if (dni == bioquimico.getDNI()) {
                    limpiarBuffer();
                    break; //MISMO DNI PUEDE PASAR
                } else if (!existeDNI(dni)) {
                    limpiarBuffer();
                    break; // CAMBIO DNI OK
                } else {
                    cout << "Error: Ese DNI ya existe en el sistema.\n";
                }
            } else cout << "El DNI debe ser positivo.\n";
        } else {
            cout << "Error: Ingrese un numero.\n";
            limpiarBuffer();
        }
    }
    limpiarBuffer();

    // EMAIL
    cout << "Nuevo email [" << bioquimico.getEmail() << "]: ";
    getline(cin, email);
    if (email == "0") return;
    if (email.empty()) email = bioquimico.getEmail();

    // MATRICULA
    while (true) {
        cout << "Nueva matricula [" << bioquimico.getMatricula() << "]: ";
        if (cin >> matricula) {
            if (matricula == 0) {
                limpiarBuffer();
                return;
            }
            if (matricula > 0) {
                if (matricula == bioquimico.getMatricula() || !existeMatricula(matricula)) {
                    limpiarBuffer();
                    break;
                } else {
                    cout << "Error: Ya existe un bioquimico con esa matricula. " << endl;
                }
            } else {
                cout << "La matricula debe ser positiva." << endl;
            }
        } else {
            cout << "Error: Ingrese un numero.\n";
            limpiarBuffer();
        }
    }

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
//OBTENER BIOQUIMICOS
std::vector<Bioquimico> ServicioBioquimico::obtenerBioquimicos(){
    return managerBioquimico.leerTodos();
}

//LISTAR BIOQUIMICOS
void ServicioBioquimico::listarBioquimicos(const std::vector<Bioquimico>& bioquimicos) {
    system("cls");
    if (bioquimicos.empty()) {
        cout << "No hay bioquimicos registrados.\n";
        return;
    } else {
        cout << "\n-- LISTADO DE BIOQUIMICOS --\n";
        for (int i = 0; i < (int)bioquimicos.size(); i++) {
            Bioquimico bioquimico = bioquimicos[i];
            cout << "ID: " << bioquimico.getId()
                 << " | Nombre: " << bioquimico.getNombre()
                 << " | Apellido: " << bioquimico.getApellido()
                 << " | DNI: " << bioquimico.getDNI()
                 << " | Matricula: " << bioquimico.getMatricula()
                 << "\n";
        }
    }
}

//ELIMINAR BIOQUIMICO
void ServicioBioquimico::eliminarBioquimico() {
    system("cls");
    std::vector<Bioquimico> lista = managerBioquimico.leerTodos();

    if (lista.empty()) {
        cout << "\nNo hay bioquimicos para eliminar.\n";
        return;
    }

    listarBioquimicos(lista);

    int id;
    id = pedirEntero("\nIngrese el ID a eliminar (0 para cancelar): ");
    if (id == 0){
        cout << "Operacion cancelada." << endl;
        return;
    }

    int posicion = managerBioquimico.buscar(id);
    if (posicion == -1){
        cout << "No se encontro un bioquimico con ese ID." << endl;
        return;
    }

    cout << "Esta seguro que desea eliminar este bioquimico? (S/N): " << endl;
    char confirma;
    cin >> confirma;

    if (confirma == 'S' || confirma == 's'){
        bool eliminado = managerBioquimico.eliminar(id);
        if (eliminado){
            cout << "\n-- ELIMINADO EXITOSAMENTE --\n";
        } else {
        cout << "\n-- OCURRIO UN ERROR AL ELIMINAR EL BIOQUIMICO --\n";
            }
        } else{
                cout << "Operacion cancelada." << endl;
        }
    }

//ORDENAR POR APELLIDO
void ServicioBioquimico::ordenarBioquimicosPorApellido() {
    system("cls");
    std::vector<Bioquimico> listaOrdenada = managerBioquimico.ordenarPorApellido();

    if (listaOrdenada.empty()) {
        cout << "No hay bioquimicos registrados.\n";
        return;
    }

    cout << "\nBioquimicos ordenados por apellido:\n";
    cout << "-------------------------" << endl;
    for (int i=0; i < (int)listaOrdenada.size(); i++) {
        const Bioquimico& b = listaOrdenada[i];
        cout << "Apellido: " << b.getApellido() << endl
             << "Nombre: " << b.getNombre() << endl
             << "Matricula: " << b.getMatricula() << endl
             << "-------------------------" << endl;
    }
}

//ORDENAR POR MATRICULA
void ServicioBioquimico::ordenarBioquimicosPorLegajo() {
    system("cls");
    std::vector<Bioquimico> listaOrdenada = managerBioquimico.ordenarPorLegajo();

    if (listaOrdenada.empty()) {
        cout << "No hay bioquimicos registrados.\n";
        return;
    }

    cout << "\nBioquimicos ordenados por matricula:\n";
    cout << "-------------------------" << endl;
    for (int i=0; i < (int)listaOrdenada.size(); i++) {
        const Bioquimico &b = listaOrdenada[i];
        cout << "Matricula: " << b.getMatricula() << endl
             << "Apellido: " << b.getApellido() << endl
             << "Nombre: " << b.getNombre() << endl
             << "-------------------------" << endl;
    }
}

void ServicioBioquimico::buscarPorMatricula(){
    system("cls");
int matricula;
bool encontro;
Bioquimico bioquimico;
matricula = pedirEntero("Ingrese la matricula de Bioquimico que desea buscar (0 para cancelar): ");
if(matricula == 0){return;}
bioquimico = managerBioquimico.buscarPorMatricula(matricula,encontro);
if(encontro){
    cout << "\n-- BIOQUIMICO MATRICULA: "<<matricula<<" --\n";
            cout << "ID: " << bioquimico.getId()
                 << " | Nombre: " << bioquimico.getNombre()
                 << " | Apellido: " << bioquimico.getApellido()
                 << " | DNI: " << bioquimico.getDNI()
                 << " | Matricula: " << bioquimico.getMatricula()
                 << "\n";

}else{
    cout<<"No existe un Bioquimico con ese numero de matricula."<<endl;
}
}
