#ifndef TIENDA_H
#define TIENDA_H

#include <string>
#include <vector>
#include "producto.h"

using namespace std;

class Tienda
{
private:
    vector<Producto *> productos;
    char nombre[15];
    char direccionWeb[24];
    char direccionFisica[24];
    char telefono[8];
public:
    Tienda(string nombre, string direccionWeb, string direccionFisica, string telefono);
    void ConstructorIU(string nombre, string direccionWeb, string direccionFisica, string telefono);

    void Agregar(Producto *producto);
    void Borrar(int idProducto);
    void Cambiar(int idProducto, string nuevoNombreProducto);
    void Existencias(int idProducto, int existencias);

    void StreamEntrada(istream *streamEntrada);
    void StreamSalida(ostream *streamSalida);

    Producto *GetProducto(int idProducto);
    Tienda();
    ~Tienda();

    friend ostream &operator<<(ostream &o, const Tienda *tienda);
};

#endif
