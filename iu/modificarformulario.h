#ifndef MODIFICARFORMULARIO_H
#define MODIFICARFORMULARIO_H

#include <QDialog>

using namespace std;

namespace Ui {
class modificarFormulario;
}

class modificarFormulario : public QDialog
{
    Q_OBJECT

public:
    explicit modificarFormulario(QWidget *parent = nullptr);
    ~modificarFormulario();

    int GetID();
    string GetNombre();
    int GetExistencias();


private:
    Ui::modificarFormulario *ui;
};

#endif
