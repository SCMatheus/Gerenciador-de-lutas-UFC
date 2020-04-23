#ifndef PESSOA_H
#define PESSOA_H
#include<QString>
#include<QStringList>
#include <QDate>

namespace TP2 {

class Pessoa
{
protected:
    int codigo;
    QString nome;
    int idade;
    long long int cpf;
    QString dataNascimento;
public:
    Pessoa():codigo(0),nome(""), idade(0),cpf(0),dataNascimento(""){}
    Pessoa(int codigo, QString nome, long long int cpf, QString dataNascimento);

    //Métodos Set

    void setCodigo(int codigo);
    void setNome(QString nome);
    void setCPF(long long int cpf);
    void setDataNascimento(QString dataNascimento);
    void setIdade(int idade);

    //Métodos Get

    int getCodigo(){return codigo;}
    QString getNome(){return nome;}
    long long int getCPF(){return cpf;}
    QString getDataNascimento(){return dataNascimento;}
    int getIdade(){return idade;}

    //
    void descobreIdade();
    virtual void checaIdade(int idade) = 0;
};
}

#endif // PESSOA_H
