#include <iostream>

using namespace std;

int main() {

    int cpf, cpfCalc, d1, d2, d3, d4, d5, d6, d7, d8, d9, resto, digVerificador1, digVerificador2;

    cout<<"Digite um CPF sem os dois digitos finais (digitos verificadores): ";
    cin >> cpf;

    cpfCalc = cpf; // O valor do cpf é atribuído a outra variável para preservar o valor original do cpf, que será usado depois.


    /* Aqui começa a cadeia de cálculos para desconstruir o número do cpf em várias variáveis.
    Primeiramente calculamos o módulo do cpf por 10 para se obter o primeiro dígito (d1).
    Depois dividimos o valor do cpf por 10, o compilador descarta a parte decimal do resultado e usamos o novo valor para
    calcular o próximo dígito. O processo se repete até o último dígito. */

    d1 = cpfCalc % 10;
    cpfCalc = cpfCalc / 10;
    d2 = cpfCalc % 10;
    cpfCalc = cpfCalc / 10;
    d3 = cpfCalc % 10;
    cpfCalc = cpfCalc / 10;
    d4 = cpfCalc % 10;
    cpfCalc = cpfCalc / 10;
    d5 = cpfCalc % 10;
    cpfCalc = cpfCalc / 10;
    d6 = cpfCalc % 10;
    cpfCalc = cpfCalc / 10;
    d7 = cpfCalc % 10;
    cpfCalc = cpfCalc / 10;
    d8 = cpfCalc % 10;

    if (cpf > 99999999) { // Se o cpf digitado contém mais de 8 dígitos, 'd9' é calculado. Se não, 'd9' recebe 0.
        d9 = cpfCalc / 10;
    } else {
        d9 = 0;
    }

    /* Aqui no cálculo da soma dos dígitos, se o cpf digitado contém apenas 8 dígitos, então 'd9' será 0, e a expressão
    'd9 * 10' também será 0, assim desconsiderando o 'd9' da fórmula. */
    resto = (d9 * 10 + d8 * 9 + d7 * 8 + d6 * 7 + d5 * 6 + d4 * 5 + d3 * 4 + d2 * 3 + d1 * 2) % 11;

    if (resto < 2) { // Se o resto da divisão feita acima for menor que 2, o dígito verificador passa a ser 0.
        digVerificador1 = 0;
    } else {
        digVerificador1 = 11 - resto;
        /* Se o resto fosse menor que dois, o dígito verificador seria um número de 2 dígitos, o que não faria sentido,
        por isso é feita a verificação. */
    }

    resto = (d9 * 11 + d8 * 10 + d7 * 9 + d6 * 8 + d5 * 7 + d4 * 6 + d3 * 5 + d2 * 4 + d1 * 3 + digVerificador1 * 2) % 11;

    if (resto < 2) {
        digVerificador2 = 0;
    } else {
        digVerificador2 = 11 - resto;
    }

    cout << "O CPF completo e: " << cpf << digVerificador1 << digVerificador2;

    return 0;
}