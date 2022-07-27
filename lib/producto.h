#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Producto{
    private:
        
        int idProducto;
        char nombreProducto[20];
        int Existencias;

    public:

        Producto(int idProducto, string nombreProducto, int Existencias);
        Producto();
        ~Producto();

        int GetID();
        void ModificarNombre(string nuevoNombre);
        void ModificarExistencias(int existencias);

        friend ostream& operator << (ostream &streamSalida, const Producto *producto);
};

#endif