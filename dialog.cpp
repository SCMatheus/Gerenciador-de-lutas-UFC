#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}
Dialog::Dialog(QWidget *parent, ED1::Lista<TP2::Lutador*> *listaLutador):
    QDialog(parent),
    ui(new Ui::Dialog),
    listaLutador(listaLutador)
{
    ui->setupUi(this);
    if(this->listaLutador->getQuantidadeDeElementos() != 0){

       mostraLutadores();

    }
    ui->tableWidget->setColumnWidth(0,90);
    ui->tableWidget->setColumnWidth(1,120);
    ui->tableWidget->setColumnWidth(2,65);
    ui->tableWidget->setColumnWidth(3,65);
    ui->tableWidget->setColumnWidth(4,65);
    ui->tableWidget->setColumnWidth(5,100);
    ui->tableWidget->setColumnWidth(6,54);
    ui->tableWidget->setColumnWidth(7,120);
    ui->tableWidget->setEnabled(false);
    ui->pushButtonSalvar->setEnabled(false);
}

Dialog::~Dialog()
{
    listaLutador = 0;
    delete  listaLutador;
    delete  ui;
}

void Dialog::on_pushButtonCadastrar_clicked()
{
    int cont = 0;
    TP2::Lutador *lutador = 0;
    try{
        lutador = new TP2::Lutador(ui->lineEditPeso->text().toFloat(), ui->lineEditAltura->text().toFloat(), ui->lineEditNacionalidade->text(), ui->lineEditVitorias->text().toInt(), ui->lineEditDerrotas->text().toInt(), ui->lineEditEmpates->text().toInt());
        lutador->setDataNascimento(ui->lineEditDataDeNascimento->text());
        lutador->setCPF(ui->lineEditCPF->text().toInt());
        lutador->setCodigo(ui->lineEditCodigo->text().toInt());
        lutador->setNome(ui->lineEditNome->text());
        lutador->descobreIdade();


        while(cont != listaLutador->getQuantidadeDeElementos()){
            if(((listaLutador->operator [](cont))->getNome()) == lutador->getNome()) throw QString("Lutador não pode ser cadastrado duas vezes.");
            if(((listaLutador->operator [](cont))->getCodigo()) == lutador->getCodigo()) throw QString("Lutadores com mesmo código.");
            cont++;
        }

        listaLutador->inserirFim(lutador);

        mostraLutadores();

    }catch(QString &erro){
            QMessageBox::information(this,"ERRO","<font color='#c80000'>" +erro+ "</font>");
        }
}

void Dialog::on_pushButtonDeletaLutador_clicked()
{
    int posicao = 0;
    try{

        posicao = (ui->lineEditPosicaoLutador->text().toInt()) - 1;
        if((listaLutador->operator [](posicao))->getCadastro() == 1) throw QString("Lutador não pode ser excluído.");
        delete (listaLutador->retirarDoMeio(posicao));
        mostraLutadores();

    }catch(QString &erro){
                QMessageBox::information(this,"ERRO","<font color='#c80000'>" +erro+ "</font>");
            }
}


void Dialog::mostraLutadores(){
    int cont = 0;
    ui->tableWidget -> setRowCount ( listaLutador->getQuantidadeDeElementos());
    while(cont != listaLutador->getQuantidadeDeElementos()){
        ui->tableWidget->setItem(cont , 0, new QTableWidgetItem((listaLutador->operator [](cont))->getNome()));
        ui->tableWidget->setItem(cont , 1, new QTableWidgetItem(QString::number((listaLutador->operator [](cont))->getCodigo())));
        ui->tableWidget->setItem(cont , 2, new QTableWidgetItem(QString::number((listaLutador->operator [](cont))->getVitorias())));
        ui->tableWidget->setItem(cont , 3, new QTableWidgetItem(QString::number((listaLutador->operator [](cont))->getDerrotas())));
        ui->tableWidget->setItem(cont , 4, new QTableWidgetItem(QString::number((listaLutador->operator [](cont))->getEmpates())));
        ui->tableWidget->setItem(cont , 5, new QTableWidgetItem(((listaLutador->operator [](cont))->getCategoria())));
        ui->tableWidget->setItem(cont , 6, new QTableWidgetItem(((QString::number((listaLutador->operator [](cont))->getIdade())))));
        ui->tableWidget->setItem(cont , 7, new QTableWidgetItem(((QString::number((listaLutador->operator [](cont))->getCPF())))));
        cont++;
    }
}

void Dialog::on_pushButtonEditar_clicked()
{
    int posicao;
    TP2::Lutador *lutadorAux = 0;
    try{
        posicao = (ui->lineEditEditar->text().toInt()) - 1;

        lutadorAux = listaLutador->operator [](posicao);

        ui->lineEditNome->setText(lutadorAux->getNome());
        ui->lineEditCodigo->setText(QString::number(lutadorAux->getCodigo()));
        ui->lineEditCPF->setText(QString::number(lutadorAux->getCPF()));
        ui->lineEditDataDeNascimento->setText(lutadorAux->getDataNascimento());
        ui->lineEditAltura->setText(QString::number(lutadorAux->getAltura()));
        ui->lineEditPeso->setText(QString::number(lutadorAux->getPeso()));
        ui->lineEditNacionalidade->setText(lutadorAux->getNacionalidade());
        ui->lineEditVitorias->setText(QString::number(lutadorAux->getVitorias()));
        ui->lineEditDerrotas->setText(QString::number(lutadorAux->getDerrotas()));
        ui->lineEditEmpates->setText(QString::number(lutadorAux->getEmpates()));

        ui->pushButtonCadastrar->setEnabled(false);
        ui->pushButtonDeletaLutador->setEnabled(false);
        ui->pushButtonEditar->setEnabled(false);
        ui->pushButtonSalvar->setEnabled(true);
        ui->lineEditEditar->setEnabled(false);

    }catch(QString &erro){
        QMessageBox::information(this,"ERRO","<font color='#c80000'>" +erro+ "</font>");
    }
}

void Dialog::on_pushButtonSalvar_clicked()
{
    int posicao;
    TP2::Lutador *lutadorAux = 0;
    try{
        posicao = (ui->lineEditEditar->text().toInt()) - 1;

        lutadorAux = listaLutador->operator [](posicao);

        lutadorAux->setNome(ui->lineEditNome->text());
        lutadorAux->setDerrotas(ui->lineEditDerrotas->text().toInt());
        lutadorAux->setVitorias(ui->lineEditVitorias->text().toInt());
        lutadorAux->setEmpates(ui->lineEditEmpates->text().toInt());
        lutadorAux->setNacionalidade(ui->lineEditNacionalidade->text());
        lutadorAux->setPeso(ui->lineEditPeso->text().toFloat());
        lutadorAux->setDataNascimento(ui->lineEditDataDeNascimento->text());
        lutadorAux->setCPF(ui->lineEditCPF->text().toInt());
        lutadorAux->setCodigo(ui->lineEditCodigo->text().toInt());
        lutadorAux->setAltura(ui->lineEditAltura->text().toFloat());
        lutadorAux->descobreIdade();

        mostraLutadores();


        ui->pushButtonCadastrar->setEnabled(true);
        ui->pushButtonDeletaLutador->setEnabled(true);
        ui->pushButtonEditar->setEnabled(true);
        ui->pushButtonSalvar->setEnabled(false);
        ui->lineEditEditar->setEnabled(true);
    }catch(QString &erro){
            QMessageBox::information(this,"ERRO","<font color='#c80000'>" +erro+ "</font>");
        }
}
