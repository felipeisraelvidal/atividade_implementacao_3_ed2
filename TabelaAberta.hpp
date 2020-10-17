#include <stdio.h>

class TabelaAberta {
    
public:
    TabelaAberta(int tam, int type);
    void insert(int key, int data);
    
    void printType();
    
    void print();
    
    int getColisoes();
    
private:
    int* tabela;
    int tam;
    int type;
    int colisoes;
    
    int hashDivisao(int key);
    int hashMultiplicacao(int key);
    int sondagemLinear(int key);
    int sondagemDupla(int key);
};
