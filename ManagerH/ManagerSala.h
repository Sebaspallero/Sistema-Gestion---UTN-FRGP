#include "Manager.h"
#include "../EntidadesH/Sala.h"

class ManagerSala : public Manager<Sala>{

    public:
        ManagerSala(std::string nombreArchivo);

        Sala buscarPorNombre(std::string nombre);
        bool crearSala(std::string& nombre, int piso);
        bool modificarSala(std::string& nombre, int piso, bool disponible, int id);

};
