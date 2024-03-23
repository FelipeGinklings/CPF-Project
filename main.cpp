// Caethano Rampelotti da Rosa,Eduardo José de Souza, Arthur Felipe e Felipe Ginklings.
#include <iostream>

using namespace std;

/*
Descrição:
Faça um algoritmo em C++ que solicite ao usuário UM valor inteiro de 8 a 9 dígitos, que irá representar o número de um CPF. A seguir, calcule os dois dígitos verificadores, conforme instruções abaixo, e exiba o CPF completo. 
*/

// FORMULA EXEMPLO
/* 
dn = (( cpf - ( cpf % 10^(n-1) )) / 10^(n-1) ) % 10
Para: cpf = 123456789 ; n = 2
d2 = (( 123456789 - ( 123456789 % 10^(2-1) )) / 10^(2-1) ) % 10
d2 = (( 123456789 - ( 123456789 % 10^(1) )) / 10^(1) ) % 10
d2 = (( 123456789 - ( 123456789 % 10 )) / 10 ) % 10
d2 = (( 123456789 - 9 ) / 10 ) % 10
d2 = ( 123456780 / 10 ) % 10
d2 = 12345678 % 10
d2 = 8
*/

// BASE 10
#define E2 100
#define E3 1000
#define E4 10000
#define E5 100000
#define E6 1000000
#define E7 10000000
#define E8 100000000

int main() {
    int cpf;
    cout << "Qual eh os primeiro digitos (9 a 8) do seu cpf? ";
    cin >> cpf;

    // Verificar o tamanho do CPF
    if ((cpf < 10000000) || (cpf > 999999999)) {
        cout << "Seu CPF eh invalido por favor tente novamente!";
        return 0; // Finaliza o programa
    }

    // Digitos da esquerda para direita (calculo feito com base na fórmula do inicio do código)
    int d1, d2, d3, d4, d5, d6, d7, d8, d9;
    d1 = cpf % 10;
    d2 = ((cpf-(cpf % 10)) / 10) % 10;
    d3 = ((cpf-(cpf % E2)) / E2) % 10;
    d4 = ((cpf-(cpf % E3)) / E3) % 10;
    d5 = ((cpf-(cpf % E4)) / E4) % 10;
    d6 = ((cpf-(cpf % E5)) / E5) % 10;
    d7 = ((cpf-(cpf % E6)) / E6) % 10;
    d8 = ((cpf-(cpf % E7)) / E7) % 10;
    d9 = ((cpf-(cpf % E8)) / E8) % 10;

    // Primeiro e segundo digito verificador do CPF
    int firstVD, secondVD;
    
    // Soma dos digitos para o primeiro digito verificador
    firstVD = (d1 * 2) + (d2 * 3) + (d3 * 4);
    firstVD += (d4 * 5) + (d5 * 6) + (d6 * 7);
    firstVD += (d7 * 8) + (d8 * 9) + (d9 * 10);

    // Soma dos digitos para o segundo digito verificador
    secondVD = firstVD;
    secondVD += d1 + d2 + d3 + d4 + d5 + d6 + d7 + d8 + d9; 

    // Resto da divisão 1
    firstVD %= 11;
    // firstVD = firstVD < 2 ? 0 : 11 - firstVD;
    if (firstVD < 2) {
        firstVD = 0;
    } else {
        firstVD = 11 - firstVD;
        secondVD += firstVD * 2;
    }

    // Resto da divisão 2
    secondVD %= 11;
    // secondVD = secondVD < 2 ? 0 : 11 - secondVD;
    if (secondVD < 2) {
        secondVD = 0;
    } else {
        secondVD = 11 - secondVD;
    }

    // Mostra o novo cpf
    cout << "Seu CPF com os dois digitos verificadores eh: ";
    cout << d9 << d8 << d7 << ".";
    cout << d6 << d5 << d4 << ".";
    cout << d3 << d2 << d1 << "-";
    cout << firstVD << secondVD << endl;
    return 0;
}