#include<iostream>
#include <string>
#include <limits>
#include "../ServicioH/ServiciosUtilidades.h"
int pedirEntero(const std::string& mensaje) {
    int valor;
    while (true) {
        std::cout << mensaje;
        if (std::cin >> valor) return valor;
        std::cout << "Entrada inválida."<<std::endl;
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
        std::cout << "Entrada inválida. Debe ingresar un solo caracter."<<std::endl;
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

        std::cout << "Entrada inválida. Debe ingresar 'S' o 'N'."<<std::endl;
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
            std::cout << "Entrada inválida. Debe ingresar un número.\n";
            continue;
        }

        try {
            size_t pos;
            valor = std::stof(input, &pos);

            // Validar que TODOS los caracteres se hayan convertido
            if (pos != input.length()) {
                std::cout << "Entrada inválida. No ingrese letras ni símbolos.\n";
                continue;
            }

            return valor; // valor válido

        } catch (...) {
            std::cout << "Entrada inválida. Intente nuevamente.\n";
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

        std::cout << "El texto no puede estar vacío.\n";
    }
}
