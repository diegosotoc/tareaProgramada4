#ifndef ExcepcionesProducto_H
#define ExcepcionesProducto_H

#include <exception>

using namespace std;

class ExcepcionNombreProducto : public exception
{
public:
    ExcepcionNombreProducto() noexcept = default;
    ~ExcepcionNombreProducto() = default;

    virtual const char *what() const noexcept{
        return "ERROR: Ingresar un nombre valido.";
    }
};

class ExcepcionNegativo : public exception
{
public:
    ExcepcionNegativo() noexcept = default;
    ~ExcepcionNegativo() = default;

    virtual const char *what() const noexcept{
        return "ERROR: Ingresar un ID valido.";
    }
};

class ExcepcionDisponibilidad : public exception
{
public:
    ExcepcionDisponibilidad() noexcept = default;
    ~ExcepcionDisponibilidad() = default;

    virtual const char *what() const noexcept{
        return "ERROR: Ingresar una disponibilidad valida";
    }
};

#endif