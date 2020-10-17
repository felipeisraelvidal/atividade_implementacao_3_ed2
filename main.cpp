#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "TabelaAberta.hpp"

using namespace std;

void readFile(string filePath) {
    ifstream file;
    file.open(filePath);
    
    if (file.is_open()) {
        string firstLine;
        getline(file, firstLine);
        istringstream iss(firstLine);
        int tam, n, type;
        iss >> tam;
        iss >> n;
        iss >> type;
        
        TabelaAberta table(tam, type);
        table.printType();
        cout << "Tabela de tamanho: " << tam << endl;
        cout << n << " items" << endl;
        for (int i = 0; i < n; i++) {
            string strNum;
            getline(file, strNum);
            istringstream stream(strNum);
            int num;
            stream >> num;
            cout << num << " ";
            table.insert(num, num);
        }
        cout << endl;
        table.print();
        cout << "Colisões: " << table.getColisoes() << endl;
    }
}

int main(int argc, const char * argv[]) {
    
    string filePath;
    cout << "Caminho do arquivo de entrada: ";
    cin >> filePath;
    readFile(filePath);
    
    return 0;
}