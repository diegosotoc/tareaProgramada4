#include "agregarformulario.h"
#include "ui_agregarformulario.h"

agregarFormulario::agregarFormulario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::agregarFormulario)
{
    ui->setupUi(this);
}

agregarFormulario::~agregarFormulario()
{
    delete ui;
}

int agregarFormulario::GetID(){
    return this->ui->lineID->text().toInt();
}

string agregarFormulario::GetNombre(){
    return this->ui->lineNombre->text().toStdString();
}

int agregarFormulario::GetExistencias(){
    return this->ui->lineExistencias->text().toInt();
}
