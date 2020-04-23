#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QString>
#include <Evento.h>
#include <QMessageBox>
#include <dialog.h>
#include <QMainWindow>
#include <DialogEvento.h>
#include <Persistencia.h>
#include <DialogCliente.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButtonCadastrarClientes_clicked();

private:
    Ui::MainWindow *ui;
    ED1::Lista<TP2::Evento*> *listaEvento;
    ED1::Lista<TP2::Lutador*> *listaLutador;
    ED1::Lista<TP2::Cliente*> *listaClientes;
};

#endif // MAINWINDOW_H
