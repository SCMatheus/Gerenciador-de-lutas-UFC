#include "Pessoa.h"
namespace TP2 {

Pessoa::Pessoa(int codigo, QString nome, long long int cpf, QString dataNascimento):
    idade(0)
{

    //Exceções

    if(codigo <= 0) throw QString ("Código Inválido.");
    if(nome == "") throw QString ("Digite um nome.");
    if(cpf <= 0) throw QString ("CPF Inválido.");
    if(dataNascimento == "") throw QString ("Digite uma data válida.");

    //Setando atributos

    this->codigo = codigo;
    this->nome = nome;
    this->dataNascimento = dataNascimento;
    this->cpf = cpf;

}

//Metodos Set


void Pessoa::setCodigo(int codigo){
    if(codigo <= 0) throw QString ("Código Inválido.");
    this->codigo = codigo;
}

void Pessoa::setNome(QString nome){
    if(nome == "") throw QString ("Digite um nome.");
    this->nome = nome;
}



void Pessoa::setDataNascimento(QString dataNascimento){
    if(dataNascimento == "") throw QString ("Digite uma data válida.");
    this->dataNascimento = dataNascimento;
}

void Pessoa::setCPF(long long int cpf){
    if(cpf <= 0) throw QString ("CPF inválido.");
    this->cpf = cpf;
}

void Pessoa::descobreIdade(){
    if(dataNascimento == "") throw QString ("Sem data de nascimento.");
    QDate sistemaData = QDate::currentDate();
    int dia = sistemaData.day();
    int mes = sistemaData.month();
    int ano = sistemaData.year();
    int idade = 0;
    QStringList data = dataNascimento.split('/');
    if(data[1].toInt() == mes){
        if(data[0].toInt() < dia){
            idade = ((ano - (data[2].toInt())) -1);
        }else
            idade = (ano - (data[2].toInt()));
    }else if ((data[1]).toInt() < mes){
        idade = ((ano - (data[2].toInt())) -1);
    }else
    {
       idade = (ano - (data[2].toInt()));
    }
    setIdade(idade);
}
void Pessoa::setIdade(int idade){
    checaIdade(idade);
    this->idade = idade;
}

}
