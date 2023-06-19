#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <string>
using namespace std;

class Cliente{
private:
    int _ID;
    char _NombreEmpresa[50];
    int _Cuit;
    char _Correo[50];
    bool _Estado;
public:
    void setID(int id);
    void setNombreEmpresa(string NombreEmpresa);
    void setCuit(int Cuit);
    void setCorreo(string Correo);
    void setEstado(bool Estado);
    int getID();
    string getNombreEmpresa();
    int getCuit();
    string getCorreo();
    bool getEstado();
    void Cargar();
    void Mostrar();
};

#endif // CLIENTE_H_INCLUDED
