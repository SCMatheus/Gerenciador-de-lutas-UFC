#ifndef LUTADOR_H
#define LUTADOR_H
#include <QString>
#include<Pessoa.h>

namespace TP2 {
class Lutador : public Pessoa
{
private:
    float peso;
    float altura;
    int vitorias;
    int derrotas;
    QString nacionalidade;
    QString categoria;
    int empates;
    bool cadastro;
public:
    Lutador():Pessoa(),peso(0),altura(0),nacionalidade(""),categoria(""),vitorias(-1),derrotas(-1), empates(0), cadastro(0){}
    Lutador(float peso, float altura, QString nacionalidade, int vitorias, int derrotas, int empates);

    //Métodos Set

    void setPeso(float peso);
    void setAltura(float altura);
    void setNacionalidade(QString nacionalidade);
    void setVitorias(int vitorias);
    void setDerrotas(int derrotas);
    void setEmpates(int empates);
    void setCategoria(QString categoria){this->categoria = categoria;}
    void setCadastro(bool cadastro){this->cadastro = cadastro;}

    //Métodos Get

    float getPeso(){return peso;}
    float getAltura(){return altura;}
    QString getNacionalidade(){return nacionalidade;}
    QString getCategoria(){return categoria;}
    int getVitorias(){return vitorias;}
    int getDerrotas(){return derrotas;}
    int getEmpates(){return empates;}
    bool getCadastro(){return cadastro;}


    //Métodos de operações

    void Categoria();
    void checaIdade(int idade);
};
}
#endif // LUTADOR_H
