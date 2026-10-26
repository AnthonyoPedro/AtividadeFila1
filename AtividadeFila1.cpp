
#include <iostream>
#include <string>
using namespace std;

struct Pessoa {
    string nome;
    int prioridade;
    Pessoa* prox;
};

Pessoa* inicio = NULL;

int definirPrioridade(int tipo) {
    if (tipo == 1) {
        return 4;
    } else if (tipo == 2) {
        return 3;
    } else if (tipo == 3) {
        return 3;
    } else if (tipo == 4) {
        return 2;
    } else {
        return 1;
    }
}

void inserir(string nome, int tipo) {
    Pessoa* nova = new Pessoa;

    nova->nome = nome;
    nova->prioridade = definirPrioridade(tipo);
    nova->prox = NULL;

    if (inicio == NULL || nova->prioridade > inicio->prioridade) {
        nova->prox = inicio;
        inicio = nova;
    } else {
        Pessoa* aux = inicio;

        while (aux->prox != NULL &&
               aux->prox->prioridade >= nova->prioridade) {
            aux = aux->prox;
        }

        nova->prox = aux->prox;
        aux->prox = nova;
    }

    cout << "Pessoa inserida na fila!\n";
}

void remover() {
    if (inicio == NULL) {
        cout << "Fila vazia!\n";
    } else {
        Pessoa* aux = inicio;

        cout << "Pessoa atendida: " << aux->nome << endl;

        inicio = inicio->prox;
        delete aux;
    }
}

void imprimir() {
    if (inicio == NULL) {
        cout << "Fila vazia!\n";
    } else {
        Pessoa* aux = inicio;

        cout << "\n--- FILA DO BANCO ---\n";

        while (aux != NULL) {
            cout << "Nome: " << aux->nome
                 << " | Prioridade: " << aux->prioridade
                 << endl;

            aux = aux->prox;
        }
    }
}

int main() {
    int opcao, tipo;
    string nome;

    do {
        cout << "\n1 - Inserir pessoa";
        cout << "\n2 - Remover pessoa";
        cout << "\n3 - Imprimir fila";
        cout << "\n0 - Sair";
        cout << "\nEscolha: ";
        cin >> opcao;

        if (opcao == 1) {
            cout << "\nNome da pessoa: ";
            cin >> nome;

            cout << "\nTipo de pessoa:";
            cout << "\n1 - Idoso";
            cout << "\n2 - PCD";
            cout << "\n3 - Gestante";
            cout << "\n4 - Pessoa autista";
            cout << "\n5 - Demais pessoas";
            cout << "\nEscolha: ";
            cin >> tipo;

            if (tipo < 1 || tipo > 5) {
                cout << "Tipo invalido!\n";
            } else {
                inserir(nome, tipo);
            }
        } else if (opcao == 2) {
            remover();
        } else if (opcao == 3) {
            imprimir();
        } else if (opcao != 0) {
            cout << "Opcao invalida!\n";
        }

    } while (opcao != 0);

    while (inicio != NULL) {
        remover();
    }

    return 0;
}
