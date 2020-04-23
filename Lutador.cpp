#include "Lutador.h"

namespace TP2 {

Lutador::Lutador(float peso, float altura, QString nacionalidade, int vitorias, int derrotas, int empates):
    categoria(""),
    cadastro(0)
{

    //Exceções

    if((peso <= 40) || (peso >= 150)) throw QString ("Peso Inválido.");
    if((altura <= 1)  || (altura >= 3)) throw QString ("Altura Inválida.");
    if(nacionalidade == "") throw QString ("Digite uma nacionalidade.");
    if(derrotas < 0) throw QString ("Quantidade de derrotas inválida.");
    if(vitorias < 0) throw QString ("Quantidade de vitórias inválida.");
    if(empates < 0) throw QString ("Quantidade de empates inválidos.");

    //Setando atributos

    this->peso = peso;
    this->altura = altura;
    this->nacionalidade = nacionalidade;
    this->vitorias = vitorias;
    this->derrotas = derrotas;
    this->empates = empates;
    Categoria();
}

//Metodos Set

void Lutador::setPeso(float peso){
    if((peso <= 40) || (peso >= 150)) throw QString ("Peso Inválido.");
    this->peso = peso;
}

void Lutador::setAltura(float altura){
    if((altura <= 1)  || (altura >= 3)) throw QString ("Altura Inválida");
    this->altura = altura;
}

void Lutador::setNacionalidade(QString nacionalidade){
    if(nacionalidade == "") throw QString ("Digite uma nacionalidade");
    this->nacionalidade = nacionalidade;
}


void Lutador::Categoria(){

    if((peso <= 52) || (peso > 120.2)) throw QString("Peso inválido");

    if(peso <= 56.7){
        categoria = "Peso Mosca";
    }else if(peso <= 61.2){
        categoria = "Peso Galo";
    }else if(peso <= 65.8){
        categoria = "Peso Pena";
    }else if(peso <= 70.3)
        categoria = "Peso Leve";
    else if(peso <= 77.1)
        categoria = "Peso Meio-médio";
    else if(peso <= 83.9)
        categoria = "Peso Meio";
    else if(peso <= 93)
        categoria = "Peso Meio-pesado";
    else if(peso <= 120.2)
        categoria = "Peso Pesado";
}

void Lutador::checaIdade(int idade)
{
    if((idade < 18)||(idade > 60)) throw QString ("Idade inválida.");
}

void Lutador::setVitorias(int vitorias){
    if(vitorias < 0) throw QString("Quantidade de vitórias inválida.");
    this->vitorias = vitorias;
}

void Lutador::setDerrotas(int derrotas){
    if(derrotas < 0) throw QString("Quantidade de vitórias inválida.");
    this->derrotas = derrotas;
}

void Lutador::setEmpates(int empates){
    if(empates < 0) throw QString("Quantidade de empates inválida.");
    this->empates = empates;
}

}
