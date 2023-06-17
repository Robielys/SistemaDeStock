#ifndef MUESTRAARCHIVO_H
#define MUESTRAARCHIVO_H
#include "Muestra.h"

class MuestraArchivo
{
public:
    void listar(Muestra* muest, int nroRegistro);
    Muestra BuscarMuestra(int nroID);
    bool guardar(Muestra art);
    /*bool guardarModificacion(Muestra muest, int posicion);*/
    int buscar(int ID);
    int getCantidad();
    int CrearID();

};

#endif // MUESTRAARCHIVO_H
