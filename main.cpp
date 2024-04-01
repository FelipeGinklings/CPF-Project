// Arthur Felipe, Caethano, Eduardo José de Souza e Felipe Ginklings.
#include <iostream>

using namespace std;

/*
Descrição:
Faça um algoritmo em C++ que solicite ao usuário UM valor inteiro de 8 a 9 dígitos,
que irá representar o número de um CPF.
A seguir, calcule os dois dígitos verificadores,
conforme as instruções, e exiba o CPF completo. 
*/

int main() {
    // CPF
    int cpf;
    cout << "Insira o CPF: ";
    cin >> cpf;

    // Verifica se tem 8 ou 9 dígitos
    if ((cpf < 10000000) || (cpf > 999999999)) {
        cout << "Seu CPF é inválido, por favor, tente novamente!";
        return 0; // Finaliza o programa
    }

    // d = Dígito
    int d1, d2, d3, d4, d5, d6, d7, d8, d9;
    d9 = cpf % 10;
    
    cpf /= 10; // Remove o último digito do cpf e retorna o novo cpf
    d8 = cpf % 10; // O último digito do novo cpf
    // O processo acima se repete abaixo
    cpf /= 10;
    d7 = cpf % 10;
    cpf /= 10;
    d6 = cpf % 10;
    cpf /= 10;
    d5 = cpf % 10;
    cpf /= 10;
    d4 = cpf % 10;
    cpf /= 10;
    d3 = cpf % 10;
    cpf /= 10;
    d2 = cpf % 10;
    d1 = cpf / 10;

    // v = Dígito verificador
    int v1, v2;

    // Soma inicial de v1 e v2 é a mesma
    v1 = (d1*10) + (d2*9) + (d3*8);
    v1 += (d4*7) + (d5*6) + (d6*5);
    v1 += (d7*4) + (d8*3) + (d9*2);
    v2 = v1;

    // Resto da divisão por 11.
    v1 %= 11;

    // Verificando se o resto do somatório é menor que 2
    if (v1 < 2) {
        v1 = 0;
    } else {
        // Caso não seja, subtraímos o valor de v1 de 11
        v1 = 11 - v1;
    }

    // Complementando a soma de v2
    v2 += ( d1 + d2 + d3 );
    v2 += ( d4 + d5 + d6 ); 
    v2 += (d7 + d8 + d9);
    v2 += (v1 * 2);

    // Resto da divisão por 11
    v2 %= 11;

    // Verificando se o resto do somatório é menor que 2
    if (v2 < 2) {
        v2 = 0;
    } else {
        v2 = 11 - v2;
    }

    // Mostra o novo cpf
    cout << "Seu CPF com os dois digitos verificadores é: ";
    cout << d1 << d2 << d3 << ".";
    cout << d4 << d5 << d6 << ".";
    cout << d7 << d8 << d9 << "-";
    cout << v1 << v2 << endl;

    return 0; // Finaliza o programa
}
