#include <iostream>

using namespace std;

int main() {
    // D = Dígito, V = Verificador (Dígito verificador)
    int cpf;
    cout << "Insira o CPF: ";
    cin >> cpf;

    // Verifica se tem 8 ou 9 dígitos
    if ((cpf < 10000000) || (cpf > 999999999)) {
        cout << "Seu CPF eh invalido por favor tente novamente!";
        return 0; // Finaliza o programa
    }

    // 
    int d1, d2, d3, d4, d5, d6, d7, d8, d9;
    d9 = cpf % 10;
    cpf = cpf /10;
    d8 = cpf % 10;
    cpf = cpf /10;
    d7 = cpf % 10;
    cpf = cpf /10;
    d6 = cpf % 10;
    cpf = cpf /10;
    d5 = cpf % 10;
    cpf = cpf /10;
    d4 = cpf % 10;
    cpf = cpf /10;
    d3 = cpf % 10;
    cpf = cpf /10;
    d2 = cpf % 10;
    d1 = cpf / 10;

    int v1, v2;
    // Calculando o dígito verificador 1:
    v1 = (d1*10) + (d2*9) + (d3*8) + (d4*7) + (d5*6) + (d6*5) + (d7*4) + (d8*3) + (d9*2);
    v2 = (d1 + d2 + d3 + d4 + d5 + d6 + d7 + d8 + d9) + v1
    // Verificando se o resto do somatório é menor que 2.
    if (v1 < 2){
        v1 = 0;
    } else {
        // Caso não seja, subtraímos o valor de v1 de 11.
        v1 = 11 - v1;
    }

    v2 = v1 * 2
    if (v2 < 2){
        v2 = 0;
    } else {
        v2 = 11 - v2;
    }

    
    // Mostra o novo cpf
    cout << "Seu CPF com os dois digitos verificadores eh: ";
    cout << d1 << d2 << d3 << ".";
    cout << d4 << d5 << d6 << ".";
    cout << d7 << d8 << d9 << "-";
    cout << v1 << v2 << endl;

    return 0;
}