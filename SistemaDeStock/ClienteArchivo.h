#ifndef CLIENTEARCHIVO_H
#define CLIENTEARCHIVO_H
#include "Cliente.h"

class ClienteArchivo {
public:
    void listar(Cliente* cli, int nroRegistro);
    Cliente BuscarCliente(int nroID);
    bool guardar(Cliente cli);
    bool guardarModificacion(Cliente cliente, int posicion);
    int buscar(int ID);
    int getCantidad();
    int CrearID();
};
#endif // CLIENTEARCHIVO_H
