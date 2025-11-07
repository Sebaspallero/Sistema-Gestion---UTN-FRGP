#include "../MenuH/Menu.h"
#include <iostream>
#include <limits>
using namespace std;

Menu::Menu(const std::string& titulo) : titulo(titulo) {}

void Menu::mostrarTitulo() const {
    cout << "==== " << titulo << " ====" << endl;
}

void Menu::pausar() const {
    cout << "\nPresione una tecla para continuar...";
    cin.ignore();
    cin.get();
}

void Menu::limpiarBuffer() const{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
