#include "Evento.h"
namespace TP2 {
QString Evento::getSituacao() const
{
    return situacao;
}

void Evento::setSituacao(const QString &value)
{
    situacao = value;
}

Evento::Evento(QString local, int dia, int mes, int ano, int hora, int minutos, int quantidadeDeLutas,QString nome){
    if((ano <= 1900) || (ano > 2300)) throw QString("Ano inválido.");
    if((mes <= 0) || (mes > 12)) throw QString ("Mês inválido.");
    if(dia <= 0) throw QString("Dia inválido.");
    if(mes == 2){
        if(dia > 28) throw QString("Dia inválido.");
    }else if((mes == 1) || (mes == 3) || (mes == 5) || (mes == 7) || (mes == 8) || (mes == 10) || (mes == 12)){
        if(dia > 31) throw QString("Dia inválido.");
    }else
        if(dia > 30) throw QString ("Dia inválido.");
    if((hora < 0) ||(hora > 24)) throw QString("Horário inválido.");
    if((minutos < 0) || (minutos > 59)) throw QString ("Horário inválido.");
    if(quantidadeDeLutas <= 0) throw QString("Quantidade de Lutas inválida.");

    this->hora = hora;
    this->minutos = minutos;
    this->quantidadeDeLutas = quantidadeDeLutas;
    this->local = local;
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
    this->nome = nome;
    this->situacao = "Agendado";
    lutas = new ED1::Lista<Luta*>();
}

void Evento::setDia(int dia){
    if(mes == 2){
        if(dia > 28) throw QString("Dia inválido.");
    }else if((mes == 1) || (mes == 3) || (mes == 5) || (mes == 7) || (mes == 8) || (mes == 10) || (mes == 12)){
        if(dia > 31) throw QString("Dia inválido.");
    }else
        if(dia > 30) throw QString ("Dia inválido.");
    this->dia = dia;
}

void Evento::setMes(int mes){
    if((mes <= 0) || (mes > 12)) throw QString ("Mês inválido.");
    this->mes = mes;
}

void Evento::setAno(int ano){
    if((ano <= 1900) || (ano > 2300)) throw QString("Ano inválido.");
    this->ano = ano;
}

void Evento::listaLutas(Luta *luta){
    lutas->inserirFim(luta);
}

QString Evento::exibeLutas(){
    QString todasLutas = "";
    int cont  = 0;

    while(cont != (lutas->getQuantidadeDeElementos())){
        todasLutas += QString::number(cont+1) + " - " + ((lutas->operator [](cont))->mostrarLuta());
        cont++;
    }
    return todasLutas;
}

void Evento::setHora(int hora){
    if((hora < 0) ||(hora > 24)) throw QString("Horário inválido.");
    this->hora = hora;
}

void Evento::setMinutos(int minutos){
    if((minutos < 0) || (minutos > 59)) throw QString ("Horário inválido.");
    this->minutos = minutos;
}

void Evento::setQuantidadeDeLutas(int quantidadeDeLutas){
    if(quantidadeDeLutas <= 0) throw QString("Quantidade de Lutas inválida.");
    this->quantidadeDeLutas = quantidadeDeLutas;
}
int Evento::getQuantidadedeLutasCadastradas(){
    return lutas->getQuantidadeDeElementos();
}

void Evento::verificaSituacao(){
    if(lutas->getQuantidadeDeElementos() != quantidadeDeLutas){
        situacao = "Agendado";
    }else
    {
        int aux = 0;
        int aux2 = 0;
        while(aux != lutas->getQuantidadeDeElementos()){
            if((lutas->operator [](aux))->getStatus() == "Realizada"){
                aux2++;
            }
            aux++;
        }
        if(aux2 == aux){
            situacao = "Realizado";
        }else
            situacao = "Agendado";
    }
}
}
