#ifndef CLIENTEARCHIVO_H
#define CLIENTEARCHIVO_H
#include "Cliente.h"

class ClienteArchivo {
public:
    void listar(Cliente* cli, int nroRegistro);
    Cliente BuscarCli(int nroID);
    bool guardar(Cliente cli);
    bool guardarModificacion(Cliente cli, int posicion);
    int buscar(int ID);
    int getCantidad();
    int CrearID();
};
#endif // CLIENTEARCHIVO_H
