#ifndef ARTICULO_H
#define ARTICULO_H
#include <string>
using namespace std;

class Articulo
{
private:
    int _ID;
    char _Categoria[50];
    char _Modelo[6];
    char _TipoDeMaterial[50];
    int _Capacidad;
    int _Diametro;
    int _Stock;
    bool _Estado;
public:
    void setID(int ID);
    void setCategoria(const char* Categoria);
    void setModelo(const char* Modelo);
    void setTipoDeMaterial(const char* TipoDeMaterial);
    void setCapacidad(int Capacidad);
    void setDiametro(int Diametro);
    void setStock(int Stock);
    int descontarStock(int stock);
    void setEstado(bool Estado);

    int getID();
    const char* getCategoria();
    const char* getModelo();
    const char* getTipoDeMaterial();
    int getCapacidad();
    int getDiametro();
    int getStock();
    bool getEstado();

    void Cargar();
    void Mostrar(int Aumentar);
    void Mostrar2(int cant, int Aumentar);
    void MostrarBaja(int Aumentar);
    bool modificar();

};

#endif // ARTICULO_H
