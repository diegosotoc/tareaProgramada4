#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../libreria/producto.h"
#include "../libreria/tienda.h"
#include "QMessageBox"
#include "QFileDialog"
#include "modificarformulario.h"
#include "agregarformulario.h"
#include <fstream>
#include <sstream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->tienda = new Tienda();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnCrearTienda_clicked()
{
    string nombre = this->ui->lineNombre->text().toStdString();
    QString nombreTituloTienta = this->ui->lineNombre->text().toStdString().c_str();
    string dirWeb = this->ui->lineDirWeb->text().toStdString();
    string dirFisica = this->ui->lineDirFisica->text().toStdString();
    string telefono = this->ui->lineTelefono->text().toStdString();

    this->tienda->ConstructorIU(nombre, dirWeb, dirFisica, telefono);

    this->ui->labelTituloTienda->setText(nombreTituloTienta);
}

void MainWindow::on_btnAgregar_clicked()
{
    agregarFormulario agregarFormulario{this};
    int result = agregarFormulario.exec();

    if (result == QDialog::Accepted){
        int idProducto = agregarFormulario.GetID();
        string nombreProducto = agregarFormulario.GetNombre();
        int existenciasProducto = agregarFormulario.GetExistencias();

        try{
            Producto *producto = new Producto(idProducto, nombreProducto, existenciasProducto);
            this->tienda->Agregar(producto);

            QString idProducto_ = QString::number(idProducto);
            QString nombreProducto_ = QString::fromStdString(nombreProducto);
            QString existenciasProducto_ = QString::number(existenciasProducto);
            this->ui->listWidget->addItem(" [ " + idProducto_ + " ] " + "  " + nombreProducto_ + "  " 
            + "  < Disponibles: " + existenciasProducto_ + " > ");
        }
        catch (const exception &e){
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Error");
            msgbox->setText("No se ha podido agregar el producto correctamente");
            msgbox->open();
        }
    }
}

// Modificar producto
void MainWindow::on_btnModificar_clicked()
{
    QListWidgetItem *producto = this->ui->listWidget->currentItem();

    // no hay item seleccionado
    if (producto == nullptr){
        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("Selección de item");
        msgbox->setText("No se ha seleccionado ningún item");
        msgbox->open();
    }else{
        modificarFormulario modificarFormulario{this};
        int result = modificarFormulario.exec();

        QString idProducto_ = QString::number(this->tienda->GetProducto(this->ui->listWidget->currentRow())->GetID());
        string nombreProducto = modificarFormulario.GetNombre();
        int existencias = modificarFormulario.GetExistencias();

        this->tienda->GetProducto(this->ui->listWidget->currentRow())->ModificarNombre(nombreProducto);
        this->tienda->GetProducto(this->ui->listWidget->currentRow())->ModificarExistencias(existencias);

        QString texto = producto->text();
        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("Selección de item");
        msgbox->setText("Se ha agregado el item correctamente");
        msgbox->open();

        QString nombreProducto_ = QString::fromStdString(nombreProducto);
        QString existenciasProducto_ = QString::number(existencias);

        this->ui->listWidget->currentItem()->setText(" [ " + idProducto_ + " ] " + "  "
        + nombreProducto_ + "  " + "  < Disponibles: " + existenciasProducto_ + " > ");
    }
}

// Eliminar
void MainWindow::on_btnEliminar_clicked()
{
    QListWidgetItem *itemSeleccionado = this->ui->listWidget->currentItem();

    // No hay item seleccionado
    if (itemSeleccionado == nullptr)
    {
        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("Error");
        msgbox->setText("No hay ningún ítem seleccionado");
        msgbox->open();
    }
    else
    {
        try {
            QListWidgetItem *linea = this->ui->listWidget->takeItem(this->ui->listWidget->currentRow());
            delete linea;
            this->tienda->Borrar(this->ui->listWidget->currentRow());
        } catch (const exception &e) {
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Error");
            msgbox->setText("No podido eliminar correctamente");
            msgbox->open();
        }
    }
}

// Funcion para limpiar la pantalla
void MainWindow::on_btnLimpiar_clicked()
{
    this->ui->lineNombre->setText("");
    this->ui->lineDirWeb->setText("");
    this->ui->lineDirFisica->setText("");
    this->ui->lineTelefono->setText("");
    this->ui->labelTituloTienda->setText("");
    this->ui->listWidget->clear();
}

// Botones para regresar y cambiar de página.
void MainWindow::on_btnSiguientePagina_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_btnRegresarTienda_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

// Cargar y Descargar Tienda
void MainWindow::on_btnGuardarTienda_clicked()
{
    QString archivoBinario = QFileDialog::getSaveFileName(this);

    if (archivoBinario != ""){
        string nombre = this->ui->lineNombre->text().toStdString();
        string dirWeb = this->ui->lineDirWeb->text().toStdString();
        string dirFisica = this->ui->lineDirFisica->text().toStdString();
        string telefono = this->ui->lineTelefono->text().toStdString();
        try{

            this->tienda->ConstructorIU(nombre, dirWeb, dirFisica, telefono);
        }
        catch (const exception &e){
            QMessageBox *msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("Error");
            msgBox->setText(e.what());
            msgBox->open();
            return;
        }

        try {
            string archivoBinario_ = archivoBinario.toStdString();
            ofstream archivoSalida(archivoBinario_, ios::out | ios::binary);
            if (!archivoSalida.is_open()){
                QMessageBox *msgBox = new QMessageBox(this);
                msgBox->setWindowTitle("Error");
                msgBox->setText("No se ha podido abrir el archivo");
                msgBox->open();
                return;
            }

            this->tienda->StreamSalida(&archivoSalida);
            archivoSalida.close();

        }catch (const exception &e){
            QMessageBox *msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("Error");
            msgBox->setText("Ha ocurrido un erorr cargando el archivo");
            msgBox->open();
            return;
       }
    }
}

void MainWindow::on_btnCargarTienda_clicked()
{
    QString archivoBinario = QFileDialog::getOpenFileName(this);

    if (archivoBinario != ""){
        string archivoBinario_ = archivoBinario.toStdString();

        ifstream archivoEntrada(archivoBinario_, ios::in | ios::binary);

        if (!archivoEntrada.is_open()){
            QMessageBox *msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("Error");
            msgBox->setText("No se ha podido abrir el archivo");
            msgBox->open();
            return;
        }
        try {
            this->tienda = new Tienda();
            this->tienda->StreamEntrada(&archivoEntrada);
            archivoEntrada.close();

            stringstream generarUI;
            generarUI << this->tienda;
            string tira{};

            getline(generarUI, tira);
            this->ui->lineNombre->setText(QString::fromStdString(tira));
            getline(generarUI, tira);
            this->ui->lineDirWeb->setText(QString::fromStdString(tira));
            getline(generarUI, tira);
            this->ui->lineDirFisica->setText(QString::fromStdString(tira));
            getline(generarUI, tira);
            this->ui->lineTelefono->setText(QString::fromStdString(tira).mid(0, 8));
            this->ui->listWidget->clear();

            while (getline(generarUI, tira)){
                QString producto = QString::fromStdString(tira);
                this->ui->listWidget->addItem(producto);
            }

        }catch (const exception &e){
            QMessageBox *msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("Error");
            msgBox->setText("No se ha podido cargar la tienda correctamente");
            msgBox->open();
            return;
        }
    }
}
