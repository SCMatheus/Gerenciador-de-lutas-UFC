#ifndef DIALOGEVENTO_H
#define DIALOGEVENTO_H
#include <Lutador.h>
#include <Lista.h>
#include <QDialog>
#include <QMessageBox>
#include <Evento.h>
#include <QStringList>
#include <SeparaString.h>
#include <time.h>

namespace Ui {
class DialogEvento;
}

class DialogEvento : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEvento(QWidget *parent = 0);
    DialogEvento(QWidget *parent = 0, ED1::Lista<TP2::Lutador*> *listaLutador = 0, ED1::Lista<TP2::Evento*> *listaEvento = 0);
    ~DialogEvento();

private slots:
    void on_pushButtonCriarEvento_clicked();

    void on_pushButtonGerirEvento_clicked();

    void on_DeletarEvento_clicked();

    void on_pushButtonMarcarLuta_clicked();

    void on_pushButtonGerirLuta_clicked();

    void on_pushButtonStatusLuta_clicked();

    void on_pushButtonLutar_clicked();

    void exibeEventos();

    void on_pushButtonEditar_clicked();

    void on_pushButtonEditarLuta_clicked();

    void on_pushButtonSalvar_clicked();

    void on_pushButtonDeleteLuta_clicked();

    void on_pushButtonSalvarLuta_clicked();

private:
    Ui::DialogEvento *ui;
    ED1::Lista<TP2::Lutador*> *listaLutador;
    ED1::Lista<TP2::Evento*> *listaEvento;
    TP2::Evento *evento;
    TP2::Luta *lutaAux;
};

#endif // DIALOGEVENTO_H
