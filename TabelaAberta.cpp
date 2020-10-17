#include <iostream>
#include <cmath>
#include "TabelaAberta.hpp"

using namespace std;

TabelaAberta::TabelaAberta(int tam, int type) {
    if (tam >= 0 && (type == 1 || type == 2)) {
        this->tam = tam;
        this->type = type;
        this->colisoes = 0;
        this->tabela = (int*)malloc(this->tam * sizeof(int));
        for (int i = 0; i < this->tam; i++) {
            this->tabela[i] = -1;
        }
    } else {
        exit(0);
    }
}

int TabelaAberta::hashDivisao(int key) {
    return key % this->tam;
}

int TabelaAberta::hashMultiplicacao(int key) {
    float k = key;
    float a = ((sqrt(5) - 1) / 2);
    float ka = k * a;
    float c = fmod(ka, 1.0);
    int hk = floor(this->tam * c);
    return hk;
}

int TabelaAberta::sondagemLinear(int key) {
    int tentativas = 0;
    for (int i = 0; i < this->tam; i++) {
        int divisao = hashDivisao(key);
        int index = (divisao + i) % this->tam;
        if (this->tabela[index] == -1) {
            return index;
        } else {
            tentativas++;
            colisoes++;
        }
    }
    return -1;
}

int TabelaAberta::sondagemDupla(int key) {
    int tentativas = 0;
    for (int i = 0; i < this->tam; i++) {
        int divisao = hashDivisao(key);
        int multiplicacao = hashMultiplicacao(key);
        int index = (divisao + (i * multiplicacao)) % this->tam;
        if (this->tabela[index] == -1) {
            return index;
        } else {
            tentativas++;
            colisoes++;
        }
    }
    return -1;
}

void TabelaAberta::insert(int key, int data) {
    int index;
    if (type == 1) {
        index = sondagemLinear(key);
    } else {
        index = sondagemDupla(key);
    }
    if (index != -1) {
        this->tabela[index] = data;
    } else {
        cout << "Erro ao inserir o valor " << data << " na chave " << key << endl;
    }
}

void TabelaAberta::print() {
    for (int i = 0; i < this->tam; i++) {
        cout << this->tabela[i] << " ";
    }
    cout << endl;
}

void TabelaAberta::printType() {
    if (type == 1) {
        cout << "Tabela aberta com sondagem linear" << endl;
    } else {
        cout << "Tabela aberta com sondagem dupla" << endl;
    }
}

int TabelaAberta::getColisoes() {
    return colisoes;
}
