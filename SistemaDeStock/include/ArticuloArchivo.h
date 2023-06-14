#ifndef ARTICULOARCHIVO_H
#define ARTICULOARCHIVO_H
#include "Articulo.h"

class ArchivoArticulo{
public:
    void Listar(Articulo* art, int nroRegistro);
    Articulo BuscarArt(int nroID);
    bool guardar(Articulo art);
    bool guardarModificacion(Articulo art, int posicion);
    int buscar(int ID);
    bool buscar1(string ID);
    bool baja(int pos);
    int getCantidad();
    int CrearID();


};
#endif // ARTICULOARCHIVO_H
