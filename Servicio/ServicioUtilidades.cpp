#include<iostream>
#include <string>
#include <limits>
#include "../ServicioH/ServiciosUtilidades.h"

using namespace std;

int pedirEntero(const std::string& mensaje) {
    int valor;
    while (true) {
        std::cout << mensaje;
        if (std::cin >> valor) return valor;
        std::cout << "Entrada invalida."<<std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

char pedirChar(const std::string& mensaje) {
    char c;

    while (true) {
        std::cout << mensaje << " ";
        if (std::cin >> c) {
            // Limpiamos todo lo que el usuario haya escrito después del primer char
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return c;
        }

        // Si fallo limpiamos
        std::cout << "Entrada invalida. Debe ingresar un solo caracter."<<std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}


char pedirCharSN(const std::string& mensaje) {
    char c;
    while (true) {
        c = pedirChar(mensaje);

        if (c == 'S' || c == 's' || c == 'N' || c == 'n') {
            return c;
        }

        std::cout << "Entrada invalida. Debe ingresar 'S' o 'N'."<<std::endl;
    }
}


float pedirFloat(const std::string &mensaje) {
    float valor;
    std::string input;

    while (true) {
        std::cout << mensaje;
        std::getline(std::cin, input);

        // Evitar cadenas vacías o sólo espacios
        if (input.empty() || input.find_first_not_of(' ') == std::string::npos) {
            std::cout << "Entrada invalida. Debe ingresar un numero.\n";
            continue;
        }

        try {
            size_t pos; //almacena la posicion del primer caracter que no fue procesado durante la conversion
            valor = std::stof(input, &pos);  //Convierte una cadena a un float

            // Validar que TODOS los caracteres se hayan convertido
            if (pos != input.length()) {
                std::cout << "Entrada invalida. No ingrese letras ni simbolos.\n";
                continue;
            }

            return valor; // valor válido

        } catch (...) {
            std::cout << "Entrada invalida. Intente nuevamente.\n";
        }
    }
}


std::string pedirString(const std::string& mensaje) {
    std::string texto;

    while (true) {
        std::cout << mensaje;
        std::getline(std::cin, texto);

        if (texto == "0") {
            return "0";    // Valor especial para cancelar
        }

        if (!texto.empty() && texto.find_first_not_of(' ') != std::string::npos) {
            return texto;
        }

        std::cout << "El texto no puede estar vacio.\n";
    }
}

void limpiarBuffer(){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Fecha pedirFecha(const std::string& mensaje, int anioMin, int anioMax) {
    int dia, mes, anio;

    while (true) {
        cout << "\n" << mensaje << endl;

        while (true) {
            cout << "Dia (1-31): ";
            if (cin >> dia && dia >= 1 && dia <= 31) break;
            cout << "Dia invalido.\n";
            limpiarBuffer();
        }

        while (true) {
            cout << "Mes (1-12): ";
            if (cin >> mes && mes >= 1 && mes <= 12) break;
            cout << "Mes invalido.\n";
            limpiarBuffer();
        }

        while (true) {
            cout << "Anio (" << anioMin << "-" << anioMax << "): ";
            if (cin >> anio && anio >= anioMin && anio <= anioMax) break;
            cout << "Anio invalido.\n";
            limpiarBuffer();
        }

        if (validarFecha(dia, mes, anio)) {
            return Fecha(dia, mes, anio);
        }

        cout << "La fecha ingresada no es valida. Intente nuevamente.\n";
    }
}

bool validarFecha(int dia, int mes, int anio) {
    if (anio <= 0) return false;
    if (mes < 1 || mes > 12) return false;
    if (dia < 1 || dia > 31) return false;

    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)
        return false;
    if (mes == 2 && dia > 28)
        return false;

    return true;
}

