#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ED1::Persistencia pegaArquivos;

    ui->setupUi(this);
    this->listaLutador = new ED1::Lista<TP2::Lutador*>();
    this->listaEvento = new ED1::Lista<TP2::Evento*>();
    this->listaClientes = new ED1::Lista<TP2::Cliente*>();
    try{
        listaLutador = pegaArquivos.inclusaoFimLutadores();
        listaClientes = pegaArquivos.inclusaoFimClientes();
        listaEvento = pegaArquivos.inclusaoFimEventos(listaLutador);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO","<font color='#c80000'>" +erro+ "</font>");
    }
}

MainWindow::~MainWindow()
{
    ED1::Persistencia arquivos;
    try {
        arquivos.gravarArquivoLutador(listaLutador);
        arquivos.gravaArquivoListaLutasEvento(listaEvento);
        arquivos.gravaArquivoListaEventos(listaEvento);
        arquivos.gravarArquivoCliente(listaClientes);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO","<font color='#c80000'>" +erro+ "</font>");
    }
    delete listaLutador;
    delete listaEvento;
    delete listaClientes;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    try{
        if(listaLutador->getQuantidadeDeElementos() < 2) throw QString ("Sem lutadores suficientes para criar um evento.");
        DialogEvento *objeto = 0;
        objeto = new DialogEvento(0, listaLutador, listaEvento);
        objeto->show();
    }catch(QString &erro){
        QMessageBox::information(this,"Erro","<font color='#c80000'>" +erro+ "</font>");
    }catch(std::bad_alloc){
        QMessageBox::information(this,"Erro","<font color='#c80000'>Memória insuficiente.</font>");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    try{
        Dialog *objeto = 0;
        objeto = new Dialog(0, listaLutador);
        objeto->show();
    }catch(std::bad_alloc){
        QMessageBox::information(this,"Erro","<font color='#c80000'>Memória insuficiente.</font>");
    }
}

void MainWindow::on_pushButtonCadastrarClientes_clicked()
{
    try{
        DialogCliente *objeto = 0;
        objeto = new DialogCliente(0, listaClientes);
        objeto->show();
    }catch(std::bad_alloc){
        QMessageBox::information(this,"Erro","<font color='#c80000'>Memória insuficiente.</font>");
    }
}
