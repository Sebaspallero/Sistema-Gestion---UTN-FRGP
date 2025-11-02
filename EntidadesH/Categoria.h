#pragma once
#include <cstring>
#include <string>

class Categoria{
    private:
        int _id;
        char _nombre[30];
        bool _estado;

    public:
        Categoria();
        Categoria(int id, std::string nombre);

        int getId() const;
        std::string getNombre() const;
        bool getEstado() const;

        void setId(int idCategoria);
        void setNombre(std::string& nombre);
        void setEstado(bool estado);
};
