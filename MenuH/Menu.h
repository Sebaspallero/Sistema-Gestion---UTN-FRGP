#pragma once
#include <string>

class Menu {
    protected:
        std::string titulo;

    public:
        Menu(const std::string& titulo);
        void mostrarTitulo() const;
        void pausar() const;
        void limpiarBuffer() const;
};
