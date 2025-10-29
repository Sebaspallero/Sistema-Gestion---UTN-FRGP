#pragma once

class Categoria{
private:
    int _idCategoria;
    char _nombre[30];
    bool _estado;
public:
    int getIDCategoria() const;
    std::string getNombre() const;
    bool getEstado() const;
    void setIDCategoria(int idCategoria);
    void setNombre(std::string& nombre);
    void setEstado(bool estado);
};
