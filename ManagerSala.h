#include "Manager.h"
#include "Sala.h"

class ManagerSala : public Manager<Sala>{

    public:
        ManagerSala(std::string nombreArchivo);

        Sala buscarPorNombre(std::string nombre);

};
