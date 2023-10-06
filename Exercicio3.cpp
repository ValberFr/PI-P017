#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Produto {
private:
    string nome;
    double preco;
    int codigo;
public:
    Produto(string nome, double preco, int codigo) : nome(nome), preco(preco), codigo(codigo) {}

    string getNome() const {
        return nome;
    }

    double getPreco() const {
        return preco;
    }

    int getCodigo() const {
        return codigo;
    }
};


