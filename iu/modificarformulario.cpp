#include "modificarformulario.h"
#include "ui_modificarformulario.h"

using namespace std;

modificarFormulario::modificarFormulario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modificarFormulario)
{
    ui->setupUi(this);
}

modificarFormulario::~modificarFormulario()
{
    delete ui;
}

int modificarFormulario::GetID(){
    return this->ui->lineID->text().toInt();
}

string modificarFormulario::GetNombre(){
    return this->ui->lineNombre->text().toStdString();
}
int modificarFormulario::GetExistencias(){
    bool esNumero;
    int existencias = this->ui->lineExistencias->text().toInt(&esNumero);
    if (esNumero) {
        return existencias;
    }
    return -1;

}