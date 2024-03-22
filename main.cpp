#include <iostream>

using namespace std;

/*
Descrição:
Faça um algoritmo em C++ que solicite ao usuário UM valor inteiro de 8 a 9 dígitos, que irá representar o número de um CPF. A seguir, calcule os dois dígitos verificadores, conforme instruções abaixo, e exiba o CPF completo. 
*/

// FORMULA EXEMPLO
/* 
cpf = 123456789
d3 = cpf
d3 -= cpf % 10 -> 123456789 - 9 = 123456780 // Acha o último digito do número
d3 /= 10 -> 12345678 // Remove o zero
d3 %= 10 -> 8 // Acha o último digito do novo número
*/

// BASE 10
#define E2 100
#define E3 1000
#define E4 10000
#define E5 100000
#define E6 1000000
#define E7 10000000
#define E8 100000000
#define E9 1000000000
#define E10 1000000000

int main() {
    int cpf;

    cout << "Qual eh os primeiro digitos (9 a 8) do seu cpf? ";
    cin >> cpf;

    // Digitos da esquerda para direita
    int d2, d3, d4, d5, d6, d7, d8, d9, d10;
    d2 = cpf % 10;
    d3 = ((cpf-(cpf % 10)) / 10) % 10;
    d4 = ((cpf-(cpf % E2)) / E2) % 10;
    d5 = ((cpf-(cpf % E3)) / E3) % 10;
    d6 = ((cpf-(cpf % E4)) / E4) % 10;
    d7 = ((cpf-(cpf % E5)) / E5) % 10;
    d8 = ((cpf-(cpf % E6)) / E6) % 10;
    d9 = ((cpf-(cpf % E7)) / E7) % 10;
    d10 = ((cpf-(cpf % E8)) / E8) % 10;
    
    // Primeiro digito verificador do CPF
    int firstVD;
    // Soma dos digitos
    firstVD = (d2 * 2) + (d3 * 3) + (d4 * 4);
    firstVD += (d5 * 5) + (d6 * 6) + (d7 * 7);
    firstVD += (d8 * 8) + (d9 * 9) + (d10 * 10);
    // Resto da divisão
    firstVD %= 11;
    if (firstVD < 2) {
        firstVD = 0;
    } else {
        firstVD = 11 - firstVD;
    }

    // Segundo digito verificador do CPF
    int secondVD;
    // Soma dos digitos
    secondVD = firstVD * 2;
    secondVD += (d2 * 3) + (d3 * 4) + (d4 * 5);
    secondVD += (d5 * 6) + (d6 * 7) + (d7 * 8);
    secondVD += (d8 * 9) + (d9 * 10) + (d10 * 11);
    // Resto da divisão
    secondVD %= 11;
    if (secondVD < 2) {
        secondVD = 0;
    } else {
        secondVD = 11 - secondVD;
    }

    // Mostra o novo cpf
    cout << "Seu CPF com os dois digitos verificadores eh: ";
    cout << d10 << d9 << d8 << ".";
    cout << d7 << d6 << d5 << ".";
    cout << d4 << d3 << d2 << "-";
    cout << firstVD << secondVD << endl;
    return 0;
}