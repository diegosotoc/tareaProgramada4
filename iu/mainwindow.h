#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "../lib/lib.h"
//#include "../lib/producto.h"
//#include "../lib/tienda.h"
//#include "../lib/excepcionesTienda.h"
//#include "../lib/excepcionesProducto.h"

#include "../libreria/producto.h"
#include "../libreria/tienda.h"
#include "../libreria/excepcionesTienda.h"
#include "../libreria/excepcionesProducto.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_lineNombre_editingFinished();

    void on_btnLimpiar_clicked();

    void on_btnAgregar_clicked();

    void on_btnModificar_clicked();

    void on_btnEliminar_clicked();

    void on_btnSiguientePagina_clicked();

    void on_btnRegresarTienda_clicked();

    void on_btnCrearTienda_clicked();

    void on_btnGuardarTienda_clicked();

    void on_btnCargarTienda_clicked();

private:
    Ui::MainWindow *ui;
    Tienda *tienda;

};
#endif // MAINWINDOW_H
