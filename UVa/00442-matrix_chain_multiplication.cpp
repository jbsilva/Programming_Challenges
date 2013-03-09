// ===================================================================
//
//       Filename:  00442-matrix_chain_multiplication.cpp
//
//    Description:  UVa 442 - Matrix Chain Multiplication
//
//                  Após aplicar uma modificação do Shunting-yard algorithm às
//                  entradas de teste percebe-se que o RPN resultante é
//                  equivalente a string da expressão após remover os '(' e
//                  trocar os ')' pelo operador de multiplicação.
//
//                  Pelo enunciado nunca acontecerá de ter parênteses sobrando
//                  ou faltando, o que causaria problemas.
//
//                  Basta, então, interpretar esse RPN lembrando que o produto
//                  de Amxn por Bnxo resulta em Cmxo e requer m*n*o
//                  multiplicações.
//
//        Version:  1.0
//        Created:  09/07/2012 04:43:02 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ===================================================================
#include <iostream>
#include <string>
#include <stack>
using namespace std;

typedef struct
{
    int rows;
    int cols;
} matrix;

int main()
{
    matrix matrices[27];                                 // 0=A, 1=B, ..., 25=Z
    int qtd;
    cin >> qtd;
    char name;
    for (int i = 0; i < qtd; i++)
    {
        cin >> name;
        cin >> matrices[name - 'A'].rows >> matrices[name - 'A'].cols;
    }
    cin.ignore();                                // Ignora \n da linha anterior
    string linha;
    while (getline(cin, linha))
    {
        stack<matrix> pilha;
        int multipls = 0;
        bool error = false;
        for (unsigned int i = 0; i < linha.length(); i++)
        {
            if (linha.at(i) == '(');                              // Ignora '('
            else if (linha.at(i) == ')')                        // trata como *
            {
                matrix b = pilha.top(); pilha.pop();
                matrix a = pilha.top(); pilha.pop();
                if (a.cols == b.rows)            // Condição para multiplicação
                {
                    matrix c = {a.rows, b.cols};
                    pilha.push(c);                      // Troca A e B por C=AB
                    multipls += a.rows * a.cols * b.cols;
                }
                else
                {
                    error = true;
                    break;
                }
            }
            else                                        // É uma letra de A a Z
                pilha.push(matrices[linha.at(i) - 'A']);
        }
        if (error)
            cout << "error" << endl;
        else
            cout << multipls << endl;
    }
    return 0;
}
