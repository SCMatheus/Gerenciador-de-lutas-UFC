#ifndef DIALOG_H
#define DIALOG_H
#include <Lista.h>
#include <Lutador.h>
#include <QMessageBox>
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    Dialog(QWidget *parent = 0, ED1::Lista<TP2::Lutador*> *listaLutador = 0);
    ~Dialog();

private slots:
    void on_pushButtonCadastrar_clicked();

    void on_pushButtonDeletaLutador_clicked();

    void mostraLutadores();

    void on_pushButtonEditar_clicked();

    void on_pushButtonSalvar_clicked();

private:
    Ui::Dialog *ui;
    ED1::Lista<TP2::Lutador*> *listaLutador;
};

#endif // DIALOG_H
