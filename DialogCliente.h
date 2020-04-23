#ifndef DIALOGCLIENTE_H
#define DIALOGCLIENTE_H
#include <QString>
#include <Lista.h>
#include <QDialog>
#include <Cliente.h>
#include <Persistencia.h>
#include <QMessageBox>
#include <QDate>

namespace Ui {
class DialogCliente;
}

class DialogCliente : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCliente(QWidget *parent = 0);
    explicit DialogCliente(QWidget *parent = 0, ED1::Lista<TP2::Cliente *> *listaClientes = 0);
    void mostraClientes();
    ~DialogCliente();

private slots:
    void on_pushButtonCadastrar_clicked();

    void on_pushButtonDeletar_clicked();

    void on_pushButtonEditar_clicked();

    void on_pushButtonSalvar_clicked();

private:
    Ui::DialogCliente *ui;
    ED1::Lista<TP2::Cliente*> *listaClientes;
};

#endif // DIALOGCLIENTE_H
