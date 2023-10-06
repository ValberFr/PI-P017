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

struct ItemEstoque {
    Produto produto;
    int quantidade;
};


class Estoque {
private:
    vector<ItemEstoque> itens;

public:

    void adicionarProduto(const Produto& produto, int quantidade) {
        for (auto& item : itens) {
            if (item.produto.getCodigo() == produto.getCodigo()) {
                item.quantidade += quantidade;
                return;
            }
        }
        itens.push_back({produto, quantidade});
    }

    
    int getQuantidade(const Produto& produto) const {
        for (const auto& item : itens) {
            if (item.produto.getCodigo() == produto.getCodigo()) {
                return item.quantidade;
            }
        }
        return 0;
    }

    
    void removerProduto(const Produto& produto, int quantidade) {
        for (auto& item : itens) {
            if (item.produto.getCodigo() == produto.getCodigo()) {
                item.quantidade -= quantidade;
                if (item.quantidade < 0) {
                    item.quantidade = 0;
                }
                return;
            }
        }
    }
};


int main() {
    Estoque estoque;
    
    Produto maca("Maca", 2.5, 101);
    Produto arroz("Arroz", 10.0, 102);
    Produto leite("Leite", 4.0, 103);
    Produto chocolate("Chocolate", 3.0, 104);

    estoque.adicionarProduto(maca, 50);
    estoque.adicionarProduto(arroz, 30);
    estoque.adicionarProduto(leite, 20);
    estoque.adicionarProduto(chocolate, 5);

    CarrinhoDeCompras carrinho(estoque);

    carrinho.adicionarProduto(maca, 3);
    carrinho.adicionarProduto(arroz, 2);
    carrinho.adicionarProduto(leite, 1);

    cout << "Valor total da compra: " << carrinho.calcularValorTotal() << endl;

    carrinho.removerProduto(arroz, 1);

    cout << "Valor total apos remoção: " << carrinho.calcularValorTotal() << endl;

    carrinho.esvaziarCarrinho();

    cout << "Valor total apos esvaziar o carrinho: " << carrinho.calcularValorTotal() << endl;

    carrinho.adicionarProduto(chocolate, 10);
    //cout << "Quantidade de chocolates no carrinho: " << carrinho.getQuantidadeProduto(p4) << endl;

    carrinho.adicionarProduto(maca, 2);
    carrinho.adicionarProduto(arroz, 3);
    carrinho.adicionarProduto(leite, 1);
    carrinho.adicionarProduto(chocolate, 2);

    carrinho.exibirCarrinho();

    return 0;
}
