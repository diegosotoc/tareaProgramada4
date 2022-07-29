#ifndef AGREGARFORMULARIO_H
#define AGREGARFORMULARIO_H

#include <QDialog>

using namespace std;
namespace Ui {
class agregarFormulario;
}

class agregarFormulario : public QDialog
{
    Q_OBJECT

public:
    explicit agregarFormulario(QWidget *parent = nullptr);
    ~agregarFormulario();

    int GetID();
    string GetNombre();
    int GetExistencias();


private:
    Ui::agregarFormulario *ui;
};

#endif // AGREGARFORMULARIO_H