#include "DialogEvento.h"
#include "ui_DialogEvento.h"

DialogEvento::DialogEvento(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEvento),
    evento(0)
{
    ui->setupUi(this);
}

DialogEvento::DialogEvento(QWidget *parent, ED1::Lista<TP2::Lutador*> *listaLutador, ED1::Lista<TP2::Evento*> *listaEvento) :
    QDialog(parent),
    ui(new Ui::DialogEvento),
    listaLutador(listaLutador),
    listaEvento(listaEvento),
    evento(0)
{
    ui->setupUi(this);
    ui->tableWidgetListaEventos->setEnabled(false);
    ui->tableWidgetListaLutadores->setEnabled(false);
    ui->pushButtonGerirLuta->setEnabled(false);
    ui->pushButtonMarcarLuta->setEnabled(false);
    ui->pushButtonLutar->setEnabled(false);
    ui->pushButtonStatusLuta->setEnabled(false);
    ui->textEdit->setEnabled(false);
    ui->pushButtonSalvar->setEnabled(false);
    int cont = 0;
    try{
        ui->tableWidgetListaLutadores -> setRowCount (listaLutador->getQuantidadeDeElementos());
        while(cont != listaLutador->getQuantidadeDeElementos()){
            ui->tableWidgetListaLutadores->setItem(cont , 0, new QTableWidgetItem((listaLutador->operator [](cont))->getNome()));
            cont++;
        }
        exibeEventos();
        ui->labelNomeEvento->setText("<font color='#c80000'>Nenhum Evento Selecionado</font>");
    }catch(QString &erro){
        QMessageBox::information(this,"ERRO","<font color='#c80000'>" +erro+ "</font>");
    }
}

DialogEvento::~DialogEvento()
{
    delete ui;
}



void DialogEvento::on_pushButtonCriarEvento_clicked()
{

    try{
        if(ui->lineEditNomeEvento->text() == "") throw QString("Nome inválido.");

        std::string *data = 0;
        std::string *horario = 0;
        TP2::SeparaString separadorData;
        TP2::SeparaString separadorHora;
        int cont = 0;
        TP2::Evento *novoEvento = 0;

        cont = listaEvento->getQuantidadeDeElementos();

        while(cont != 0){
            if((ui->lineEditNomeEvento->text()) == (listaEvento->operator [](cont - 1))->getNome()) throw QString("Evento já existente.");
            cont--;
        }

        std::string dataEvento = (ui->lineEditData->text()).toStdString();
        std::string horarioEvento = ui->lineEditHorario->text().toStdString();


        //Separando Data e Horário

        data = separadorData.separarString(dataEvento,'/');
        horario = separadorHora.separarString(horarioEvento, ':');
        //data = dataEvento.split("/");

        if((separadorHora.getCont()) != 2) throw QString ("Horário inválido");
        if((separadorData.getCont()) != 3) throw QString ("Data Inválida.");

        novoEvento = new TP2::Evento(ui->lineEditLocal->text(), std::stoi(data[0]), std::stoi(data[1]), std::stoi(data[2]), std::stoi(horario[0]), std::stoi(horario[1]), ui->lineEditQuantidadeDeLutas->text().toInt(), ui->lineEditNomeEvento->text());

        listaEvento->inserirFim(novoEvento);

        exibeEventos();

        delete[] data;
        delete[] horario;
    }catch(QString &erro){
        QMessageBox::information(this,"Erro","<font color='#c80000'>" +erro+ "</font>");
    }catch(std::bad_alloc){
        QMessageBox::information(this,"Erro","<font color='#c80000'>Memória insuficiente.</font>");
    }
}

void DialogEvento::on_pushButtonGerirEvento_clicked()
{
    int posicao = ui->lineEditPegaEvento->text().toInt();
    try{
        evento = (listaEvento->operator []((posicao - 1)));
        ui->labelNomeEvento->setText("<font color='#c80000'>"+evento->getNome()+"</font>");

        ui->pushButtonMarcarLuta->setEnabled(true);

        ui->textEdit->setText(evento->exibeLutas());

        ui->pushButtonGerirLuta->setEnabled(true);
    }catch(QString &erro){
        QMessageBox::information(this,"Erro","<font color='#c80000'>" +erro+ "</font>");
    }
}

void DialogEvento::on_DeletarEvento_clicked()
{
    TP2::Evento *aux = 0;
    try{
        int posicao = ui->lineEditPegaEvento->text().toInt();
        if(((listaEvento->operator [](posicao -1))->getListaLutas()->getQuantidadeDeElementos()) != 0) throw QString("Evento não pode ser excluído.");
        aux = listaEvento->retirarDoMeio(posicao - 1);
        evento = 0;

        ui->textEdit->clear();

        ui->labelNomeEvento->setText("<font color='#c80000'>Nenhum Evento Selecionado</font>");

        exibeEventos();

    }catch(QString &erro){
        QMessageBox::information(this,"Erro","<font color='#c80000'>" +erro+ "</font>");
    }
}

void DialogEvento::on_pushButtonMarcarLuta_clicked()
{
    int aux = listaLutador->getQuantidadeDeElementos();
    TP2::Lutador *auxLutador1 = 0;
    TP2::Lutador *auxLutador2 = 0;
    TP2::Luta *luta = 0;

    try{
        luta = new TP2::Luta();
        if(evento->getQuantidadeDeLutas() == evento->getQuantidadedeLutasCadastradas()) throw QString("Não é possível cadastrar mais lutas.");
        if(ui->lineEditPrimeiroLutador->text() == ui->lineEditSegundoLutador->text()) throw QString("Mesmo Lutador.");


        auxLutador1 = (listaLutador->operator [](ui->lineEditPrimeiroLutador->text().toInt() - 1));
        auxLutador2 = (listaLutador->operator [](ui->lineEditSegundoLutador->text().toInt() - 1));

        if(auxLutador1->getCategoria() != auxLutador2->getCategoria()) throw QString("Lutadores de categorias diferentes.");

        aux = 0;
        while(aux != evento->getListaLutas()->getQuantidadeDeElementos()){
            if(((evento->getListaLutas()->operator [](aux))->getLutador1() == auxLutador1 || ((evento->getListaLutas()->operator [](aux))->getLutador2() == auxLutador2)) || (((evento->getListaLutas()->operator [](aux))->getLutador1() == auxLutador2) || ((evento->getListaLutas()->operator [](aux))->getLutador2() == auxLutador1))) throw QString("Lutadores já cadastrados.");
            aux++;
        }
        auxLutador1->setCadastro(1);
        auxLutador2->setCadastro(1);
        luta->setLutador1(auxLutador1);
        luta->setLutador2(auxLutador2);
        luta->setRounds(ui->lineEditRaunds->text().toInt());
        luta->setStatus("Cadastrada");

        evento->listaLutas(luta);

        ui->textEdit->clear();

        ui->textEdit->setText(evento->exibeLutas());

        ui->pushButtonGerirLuta->setEnabled(true);

    }catch(QString &erro){
        QMessageBox::information(this,"Erro","<font color='#c80000'>" +erro+ "</font>");
    }catch(std::bad_alloc){
        QMessageBox::information(this,"Erro","<font color='#c80000'>Memória insuficiente.</font>");
    }
}

void DialogEvento::on_pushButtonGerirLuta_clicked()
{
    int posicao = ui->lineEditGerirLuta->text().toInt();
    try{
        lutaAux = evento->getLuta(posicao);
        ui->pushButtonStatusLuta->setEnabled(true);
    }catch(QString &erro){
        QMessageBox::information(this,"Erro","<font color='#c80000'>" +erro+ "</font>");
    }
}

void DialogEvento::on_pushButtonStatusLuta_clicked()
{
    try{
        if(lutaAux->getStatus() != "Cadastrada") throw QString("Luta com status diferente de cadastrada.");
        if(lutaAux->getStatus() == "indefinido") throw QString ("Luta não selecionada.");
        lutaAux->setStatus(ui->comboBox->currentText());
        if(lutaAux->getStatus() == "Aprovada"){
            ui->pushButtonLutar->setEnabled(true);
        }
        ui->textEdit->clear();

        ui->textEdit->setText(evento->exibeLutas());
    }catch(QString &erro){
        QMessageBox::information(this,"Erro","<font color='#c80000'>" +erro+ "</font>");
    }

}

void DialogEvento::on_pushButtonLutar_clicked()
{
    try{
        srand((unsigned)time(0));
        int x = rand()%(3-1+1) + 1;
        TP2::Lutador *auxLutador1;
        TP2::Lutador *auxLutador2;


        auxLutador1 = (evento->getListaLutas()->operator [](ui->lineEditGerirLuta->text().toInt() - 1))->getLutador1();

        auxLutador2 = (evento->getListaLutas()->operator [](ui->lineEditGerirLuta->text().toInt() - 1))->getLutador2();


        if(x == 1){
            lutaAux->setResultado("Primeiro Lutador");
            auxLutador1->setVitorias((auxLutador1->getVitorias() + 1));
            auxLutador2->setDerrotas((auxLutador2->getDerrotas() + 1));
        }
        if(x == 2){
            lutaAux->setResultado("Segundo Lutador");
            auxLutador2->setVitorias((auxLutador2->getVitorias() + 1));
            auxLutador1->setDerrotas((auxLutador1->getDerrotas() + 1));
        }
        if(x == 3){
            lutaAux->setResultado("Empate");
            auxLutador2->setEmpates((auxLutador2->getEmpates() + 1));
            auxLutador1->setEmpates((auxLutador1->getEmpates() + 1));
        }

        lutaAux->setStatus("Realizada");
        ui->textEdit->clear();

        ui->textEdit->setText(evento->exibeLutas());

        ui->pushButtonLutar->setEnabled(false);
        ui->pushButtonStatusLuta->setEnabled(false);

        evento->verificaSituacao();
        exibeEventos();

    }catch(QString &erro){
        QMessageBox::information(this,"Erro","<font color='#c80000'>" +erro+ "</font>");
    }
}

void DialogEvento::exibeEventos(){
    QString data2 = "";
    int cont =0;
    ui->tableWidgetListaEventos -> setRowCount ( listaEvento->getQuantidadeDeElementos());
    while(cont != listaEvento->getQuantidadeDeElementos()){
        data2 = QString::number((listaEvento->operator [](cont))->getDia()) + "/" + QString::number((listaEvento->operator [](cont))->getMes()) + "/" + QString::number((listaEvento->operator [](cont))->getAno());
        ui->tableWidgetListaEventos->setItem(cont , 0, new QTableWidgetItem(((listaEvento->operator [](cont))->getNome())));
        ui->tableWidgetListaEventos->setItem(cont, 1 , new QTableWidgetItem(data2));
        ui->tableWidgetListaEventos->setItem(cont, 2 , new QTableWidgetItem((listaEvento->operator [](cont))->getSituacao()));

        cont++;
   }
}

void DialogEvento::on_pushButtonEditar_clicked()
{

    int posicao;
    TP2::Evento *eventoAux = 0;
    try{
        posicao = (ui->lineEditEditar->text().toInt()) - 1;

        eventoAux = listaEvento->operator [](posicao);
        eventoAux->verificaSituacao();
        if(eventoAux->getSituacao() == "Realizado") throw QString("Evento não pode ser Alterado.");

        ui->lineEditNomeEvento->setText(eventoAux->getNome());
        ui->lineEditLocal->setText(eventoAux->getLocal());
        ui->lineEditData->setText(QString::number(eventoAux->getDia()) + "/" + QString::number(eventoAux->getMes()) + "/" + QString::number(eventoAux->getAno()));
        ui->lineEditHorario->setText(QString::number(eventoAux->getHora()) + ":" + QString::number(eventoAux->getMinutos()));
        ui->lineEditQuantidadeDeLutas->setText(QString::number(eventoAux->getQuantidadeDeLutas()));

        ui->pushButtonCriarEvento->setEnabled(false);
        ui->DeletarEvento->setEnabled(false);
        ui->pushButtonGerirEvento->setEnabled(false);
        ui->pushButtonEditar->setEnabled(false);
        ui->pushButtonSalvar->setEnabled(true);
        ui->lineEditEditar->setEnabled(false);

    }catch(QString &erro){
        QMessageBox::information(this,"ERRO","<font color='#c80000'>" +erro+ "</font>");
    }
}

void DialogEvento::on_pushButtonEditarLuta_clicked()
{
    int posicao;
    TP2::Luta *lutaAux = 0;
    try{
        posicao = (ui->lineEditEditarLuta->text().toInt()) - 1;

        lutaAux = (evento->getListaLutas())->operator [](posicao);
        if(lutaAux->getStatus() == "Realizada") throw QString("Luta não pode ser Alterado.");

        ui->lineEditPrimeiroLutador->setText(lutaAux->getLutador1()->getNome());
        ui->lineEditSegundoLutador->setText(lutaAux->getLutador2()->getNome());
        ui->lineEditRaunds->setText(QString::number(lutaAux->getRounds()));


        ui->pushButtonMarcarLuta->setEnabled(false);
        ui->pushButtonEditarLuta->setEnabled(false);
        ui->pushButtonGerirLuta->setEnabled(false);
        ui->pushButtonStatusLuta->setEnabled(false);
        ui->pushButtonSalvarLuta->setEnabled(true);
        ui->lineEditEditarLuta->setEnabled(false);

    }catch(QString &erro){
        QMessageBox::information(this,"ERRO","<font color='#c80000'>" +erro+ "</font>");
    }
}

void DialogEvento::on_pushButtonSalvar_clicked()
{
    int posicao;
    TP2::Evento *eventoAux = 0;
    std::string *data = 0;
    std::string *horario = 0;
    TP2::SeparaString separadorData;
    TP2::SeparaString separadorHora;
    try{
        posicao = (ui->lineEditEditar->text().toInt()) - 1;

        eventoAux = listaEvento->operator [](posicao);

        std::string dataEvento = (ui->lineEditData->text()).toStdString();
        std::string horarioEvento = ui->lineEditHorario->text().toStdString();


        //Separando Data e Horário

        data = separadorData.separarString(dataEvento,'/');
        horario = separadorHora.separarString(horarioEvento, ':');
        //data = dataEvento.split("/");

        if((separadorHora.getCont()) != 2) throw QString ("Horário inválido");
        if((separadorData.getCont()) != 3) throw QString ("Data Inválida.");

        eventoAux->setNome(ui->lineEditNomeEvento->text());
        eventoAux->setLocal(ui->lineEditLocal->text());
        eventoAux->setDia(std::stoi(data[0]));
        eventoAux->setMes(std::stoi(data[1]));
        eventoAux->setAno(std::stoi(data[2]));
        eventoAux->setHora(std::stoi(horario[0]));
        eventoAux->setMinutos(std::stoi(horario[1]));
        eventoAux->setQuantidadeDeLutas(ui->lineEditQuantidadeDeLutas->text().toInt());

        exibeEventos();

        delete[] data;
        delete[] horario;

        ui->pushButtonCriarEvento->setEnabled(true);
        ui->DeletarEvento->setEnabled(true);
        ui->pushButtonEditar->setEnabled(true);
        ui->pushButtonSalvar->setEnabled(false);
        ui->lineEditEditar->setEnabled(true);
        ui->pushButtonGerirEvento->setEnabled(true);
    }catch(QString &erro){
            QMessageBox::information(this,"ERRO","<font color='#c80000'>" +erro+ "</font>");
        }
}

void DialogEvento::on_pushButtonDeleteLuta_clicked()
{
    TP2::Luta *aux = 0;
    try{
        int posicao = ui->lineEditEditarLuta->text().toInt() -1;
        if((((evento->getListaLutas())->operator [](posicao)))->getStatus() == "Realizada") throw QString("Luta não pode ser excluída.");
        aux = ((evento->getListaLutas())->retirarDoMeio(posicao));

        aux->getLutador1()->setCadastro(0);
        aux->getLutador2()->setCadastro(0);

        ui->textEdit->clear();

        ui->textEdit->setText(evento->exibeLutas());

        delete aux;

    }catch(QString &erro){
        QMessageBox::information(this,"Erro","<font color='#c80000'>" +erro+ "</font>");
    }
}

void DialogEvento::on_pushButtonSalvarLuta_clicked()
{
    int posicao = 0;
    TP2::Luta *lutaAux = 0;
    TP2::Lutador *lutadorUm = 0;
    TP2::Lutador *lutadorDois = 0;

    try{
        posicao = (ui->lineEditEditarLuta->text().toInt()) - 1;

        lutaAux = (evento->getListaLutas())->operator [](posicao);

        lutadorUm = (listaLutador->operator [](ui->lineEditPrimeiroLutador->text().toInt()))-1;
        lutadorDois = (listaLutador->operator [](ui->lineEditSegundoLutador->text().toInt()))-1;

        lutaAux->setLutador1(lutadorUm);
        lutaAux->setLutador2(lutadorDois);
        lutaAux->setRounds(ui->lineEditRaunds->text().toInt());

        evento->exibeLutas();


        ui->pushButtonMarcarLuta->setEnabled(true);
        ui->pushButtonEditarLuta->setEnabled(true);
        ui->pushButtonGerirLuta->setEnabled(true);
        ui->pushButtonStatusLuta->setEnabled(true);
        ui->pushButtonSalvarLuta->setEnabled(false);
        ui->lineEditEditarLuta->setEnabled(true);
    }catch(QString &erro){
            QMessageBox::information(this,"ERRO","<font color='#c80000'>" +erro+ "</font>");
        }
}
