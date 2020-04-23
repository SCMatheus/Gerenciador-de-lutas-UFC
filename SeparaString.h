#ifndef SEPARASTRING_H
#define SEPARASTRING_H
#include <string>
#include <QString>
#include<QMessageBox>
namespace TP2 {
class SeparaString
{
private:
    int cont;
public:
    SeparaString(): cont(0){}
    std::string* separarString(std::string texto, char separador);

    void setCont(int cont){this->cont = cont;}

    int getCont(){return cont;}
};
}
#endif // SEPARASTRING_H
