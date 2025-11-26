#pragma once
#include <cstring>
#include <string>

class Analisis{
    private:
       int _id;
       char _nombre [30];
       int _idCategoria;
       float _valor;
       bool _estado;

    public:
        Analisis();
        Analisis(int id, std::string nombre, int idCategoria, float valor);

        int getId() const;
        std::string getNombre() const;
        int getIdCategoria() const;
        float getValor() const;
        bool getEstado() const;

        void setId(int idAnalisis);
        void setNombre(std::string& nombre);
        void setIdCategoria(int idCategoria);
        void setValor(float valor);
        void setEstado(bool estado);
};
