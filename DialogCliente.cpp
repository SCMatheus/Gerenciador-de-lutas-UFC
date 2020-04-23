#include "DialogCliente.h"
#include "ui_DialogCliente.h"

DialogCliente::DialogCliente(QWidget *parent, ED1::Lista<TP2::Cliente*> *listaClientes) :
    QDialog(parent),
    ui(new Ui::DialogCliente),
    listaClientes(listaClientes)
{
    ui->setupUi(this);

    if(this->listaClientes->getQuantidadeDeElementos() != 0){

       mostraClientes();

    }
    ui->tableWidget->setColumnWidth(0,90);
    ui->tableWidget->setColumnWidth(1,120);
    ui->tableWidget->setColumnWidth(2,65);
    ui->tableWidget->setColumnWidth(3,65);
    ui->tableWidget->setColumnWidth(4,65);
    ui->tableWidget->setColumnWidth(5,90);
    ui->tableWidget->setColumnWidth(6,120);
    ui->pushButtonSalvar->setEnabled(false);
    ui->tableWidget->setEnabled(false);
}
DialogCliente::DialogCliente(QWidget *parent):
    QDialog(parent),
    ui(new Ui::DialogCliente)
{
    ui->setupUi(this);
}

DialogCliente::~DialogCliente()
{
    delete ui;
}

void DialogCliente::mostraClientes(){
    int cont = 0;
    ui->tableWidget -> setRowCount ( listaClientes->getQuantidadeDeElementos());
    while(cont != listaClientes->getQuantidadeDeElementos()){
        ui->tableWidget->setItem(cont , 0, new QTableWidgetItem((listaClientes->operator [](cont))->getNome()));
        ui->tableWidget->setItem(cont , 1, new QTableWidgetItem(QString::number((listaClientes->operator [](cont))->getCodigo())));
        ui->tableWidget->setItem(cont , 2, new QTableWidgetItem(QString::number((listaClientes->operator [](cont))->getCPF())));
        ui->tableWidget->setItem(cont , 3, new QTableWidgetItem(QString::number((listaClientes->operator [](cont))->getIdade())));
        ui->tableWidget->setItem(cont , 4, new QTableWidgetItem(QString::number((listaClientes->operator [](cont))->getSaldo())));
        ui->tableWidget->setItem(cont , 5, new QTableWidgetItem(((QString::number((listaClientes->operator [](cont))->getRendaMensal())))));
        ui->tableWidget->setItem(cont , 6, new QTableWidgetItem(((QString::number((listaClientes->operator [](cont))->getLimApostas())))));
        cont++;
    }
}

void DialogCliente::on_pushButtonCadastrar_clicked()
{

    int cont = 0;
    TP2::Cliente *cliente = 0;
    QDate sistemaData = QDate::currentDate();
    try{
        if(ui->lineEditNome->text() == "") throw QString("Preencha todos os campos.");
        if(ui->lineEditCodigo->text() == "") throw QString("Preencha todos os campos.");
        if(ui->lineEditCPF->text() == "") throw QString("Preencha todos os campos.");
        if(ui->lineEditDataDeNascimento->text() == "") throw QString("Preencha todos os campos.");
        if(ui->lineEditLimiteDeApostas->text() == "") throw QString("Preencha todos os campos.");
        if(ui->lineEditSaldo->text() == "") throw QString("Preencha todos os campos.");
        if(ui->lineEditRendaMensal->text() == "") throw QString("Preencha todos os campos.");
        cliente = new TP2::Cliente(ui->lineEditRendaMensal->text().toFloat(), ui->lineEditLimiteDeApostas->text().toFloat(), ui->lineEditSaldo->text().toFloat());
        cliente->setDataNascimento(ui->lineEditDataDeNascimento->text());
        cliente->setCPF(ui->lineEditCPF->text().toInt());
        cliente->setCodigo(ui->lineEditCodigo->text().toInt());
        cliente->setNome(ui->lineEditNome->text());
        cliente->descobreIdade();
        cliente->descobreDataCadastro();

        while(cont != listaClientes->getQuantidadeDeElementos()){
            if(((listaClientes->operator [](cont))->getNome()) == cliente->getNome()) throw QString("cliente não pode ser cadastrado duas vezes.");
            if(((listaClientes->operator [](cont))->getCodigo()) == cliente->getCodigo()) throw QString("Clientes com mesmo código.");
            cont++;
        }

        listaClientes->inserirFim(cliente);

        mostraClientes();

    }catch(QString &erro){
            QMessageBox::information(this,"ERRO","<font color='#c80000'>" +erro+ "</font>");
        }
}

void DialogCliente::on_pushButtonDeletar_clicked()
{
    int posicao = 0;
    try{

        posicao = (ui->lineEditEditar->text().toInt()) - 1;
        delete (listaClientes->retirarDoMeio(posicao));
        mostraClientes();

    }catch(QString &erro){
                QMessageBox::information(this,"ERRO","<font color='#c80000'>" +erro+ "</font>");
            }
}

void DialogCliente::on_pushButtonEditar_clicked()
{
    int posicao;
    TP2::Cliente *clienteAux = 0;
    try{
        posicao = (ui->lineEditEditar->text().toInt()) - 1;

        clienteAux = listaClientes->operator [](posicao);

        ui->lineEditNome->setText(clienteAux->getNome());
        ui->lineEditCodigo->setText(QString::number(clienteAux->getCodigo()));
        ui->lineEditCPF->setText(QString::number(clienteAux->getCPF()));
        ui->lineEditDataDeNascimento->setText(clienteAux->getDataNascimento());
        ui->lineEditRendaMensal->setText(QString::number(clienteAux->getRendaMensal()));
        ui->lineEditSaldo->setText(QString::number(clienteAux->getSaldo()));
        ui->lineEditLimiteDeApostas->setText(QString::number(clienteAux->getLimApostas()));

        ui->pushButtonCadastrar->setEnabled(false);
        ui->pushButtonDeletar->setEnabled(false);
        ui->pushButtonEditar->setEnabled(false);
        ui->pushButtonSalvar->setEnabled(true);
        ui->lineEditEditar->setEnabled(false);

    }catch(QString &erro){
        QMessageBox::information(this,"ERRO","<font color='#c80000'>" +erro+ "</font>");
    }
}

void DialogCliente::on_pushButtonSalvar_clicked()
{
    int posicao;
    TP2::Cliente *clienteAux = 0;
    try{
        if(ui->lineEditNome->text() == "") throw QString("Preencha todos os campos.");
        if(ui->lineEditCodigo->text() == "") throw QString("Preencha todos os campos.");
        if(ui->lineEditCPF->text() == "") throw QString("Preencha todos os campos.");
        if(ui->lineEditDataDeNascimento->text() == "") throw QString("Preencha todos os campos.");
        if(ui->lineEditLimiteDeApostas->text() == "") throw QString("Preencha todos os campos.");
        if(ui->lineEditSaldo->text() == "") throw QString("Preencha todos os campos.");
        if(ui->lineEditRendaMensal->text() == "") throw QString("Preencha todos os campos.");
        posicao = (ui->lineEditEditar->text().toInt()) - 1;

        clienteAux = listaClientes->operator [](posicao);

        clienteAux->setNome(ui->lineEditNome->text());
        clienteAux->setRendaMensal((ui->lineEditRendaMensal->text().toFloat()));
        clienteAux->setSaldo(ui->lineEditSaldo->text().toFloat());
        clienteAux->setDataNascimento(ui->lineEditDataDeNascimento->text());
        clienteAux->setCPF(ui->lineEditCPF->text().toInt());
        clienteAux->setCodigo(ui->lineEditCodigo->text().toInt());
        clienteAux->setLimApostas(ui->lineEditLimiteDeApostas->text().toFloat());
        clienteAux->descobreIdade();

        mostraClientes();


        ui->pushButtonCadastrar->setEnabled(true);
        ui->pushButtonDeletar->setEnabled(true);
        ui->pushButtonEditar->setEnabled(true);
        ui->pushButtonSalvar->setEnabled(false);
        ui->lineEditEditar->setEnabled(true);
    }catch(QString &erro){
            QMessageBox::information(this,"ERRO","<font color='#c80000'>" +erro+ "</font>");
        }
}
