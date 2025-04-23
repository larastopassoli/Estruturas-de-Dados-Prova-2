
   
#include "../include/posfixa.hpp"
#include <string>
#include <stack>
#include <cctype>
#include <stdexcept>
#include <iostream>

using namespace std;

int posfixa(Fila<char> &entrada) {

// Função auxiliar: prioridade dos operadores
int prioridade(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Converte expressão infixa (vinda da fila) para pós-fixa
string converterParaExpressaoFinal(Fila<char> &entrada) {
    stack<char> operadores;
    string expressao_final = "";

    while (!entrada.vazia()) {
        char c = entrada.dequeue();

        if (isdigit(c)) {
            expressao_final += c;
            expressao_final += ' ';
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!operadores.empty() && prioridade(operadores.top()) >= prioridade(c)) {
                expressao_final += operadores.top();
                expressao_final += ' ';
                operadores.pop();
            }
            operadores.push(c);
        }
        else if (isspace(c)) {
            continue;
        }
        else {
            throw runtime_error("Expressão contém caractere inválido.");
        }
    }

    while (!operadores.empty()) {
        expressao_final += operadores.top();
        expressao_final += ' ';
        operadores.pop();
    }

    return expressao_final;
}

// Avalia a expressão pós-fixa
int calcularExpressao(const string& expressao_final) {
    stack<int> valores;
    string elemento = "";

    for (size_t i = 0; i < expressao_final.length(); ++i) {
        char c = expressao_final[i];

        if (isdigit(c)) {
            elemento += c;
        }
        else if (c == ' ') {
            if (!elemento.empty()) {
                valores.push(stoi(elemento));
                elemento.clear();
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (valores.size() < 2) {
                throw runtime_error("Expressão malformada: operandos insuficientes.");
            }

            int b = valores.top(); valores.pop();
            int a = valores.top(); valores.pop();

            if (c == '/' && b == 0) {
                throw runtime_error("Erro: divisão por zero.");
            }

            switch (c) {
                case '+': valores.push(a + b); break;
                case '-': valores.push(a - b); break;
                case '*': valores.push(a * b); break;
                case '/': valores.push(a / b); break;
            }
        }
    }

    if (valores.size() != 1) {
        throw runtime_error("Expressão malformada: operandos ou operadores em excesso.");
    }

    return valores.top();
}

// Função principal chamada com a fila de entrada
int posfixa(Fila<char> &entrada) {
    string expressao_final = converterParaExpressaoFinal(entrada);
    return calcularExpressao(expressao_final);
}

}