#include "SeparaString.h"
namespace TP2 {

std::string* SeparaString::separarString(std::string texto, char separador){
    if(texto.length() == 0) throw QString("A string está vazia");
    std::string *aux = 0;
    int contString = 0;
    for(int i = 0; i < (texto.length()); i++){
        if(texto.at(i) == separador){
            cont++;
        }
    }
    cont++;

    if(cont == 0) throw QString("Nenhum separador especificado foi encontrado.");

    aux = new std::string[(cont)];

    for(int i = 0; i < cont; i++){
        aux[i] = "";
        while((texto.length() != contString) && (texto.at(contString) != separador)){
            aux[i] += texto.at(contString);
            contString++;
        }
        contString++;
    }

    return aux;
}


}
