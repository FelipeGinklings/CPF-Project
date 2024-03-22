// Eduardo José de Souza, Caethano, Arthur Felipe e Felipe Ginklings.

#include <iostream>
using namespace std;

int main() {

    // D = Dígito, V = Verificador (Dígito verificador)
    int cpf, d1, d2, d3, d4, d5, d6, d7, d8, d9, v1, v2;

    cout << "Insira o CPF: \n";
    cin >> cpf;

    // Verificando se o CPF tem 9 dígitos.
    if ((cpf <= 999999999) && (cpf >= 100000000)){

        // Isolando o dígito e indo para o próximo
        d9 = cpf%10;
        cpf = cpf/10;
        d8 = cpf%10;
        cpf = cpf/10;
        d7 = cpf%10;
        cpf = cpf/10;
        d6 = cpf%10;
        cpf = cpf/10;
        d5 = cpf%10;
        cpf = cpf/10;
        d4 = cpf%10;
        cpf = cpf/10;
        d3 = cpf%10;
        cpf = cpf/10;
        d2 = cpf%10;
        d1 = cpf/10;

        // Calculando o dígito verificador 1:
        v1 = ((d1*10) + (d2*9) + (d3*8) + (d4*7) + (d5*6) + (d6*5) + (d7*4) + (d8*3) + (d9*2))%11;

        // Verificando se o resto do somatório é menor que 2.
        if (v1 < 2){
            v1 = 0;
        } else {
            // Caso não seja, subtraímos o valor de v1 de 11.
            v1 = 11 - v1;
        }
        
        // Calculando o dígito verificador 2:
        v2 = ((d1*11) + (d2*10) + (d3*9) + (d4*8) + (d5*7) + (d6*6) + (d7*5) + (d8*4) + (d9*3) + (v1*2))%11;

        if (v2 < 2){
            v2 = 0;
        } else {
            v2 = 11 - v2;
        }

        // Resultado final. Mostrando o CPF.
        cout << "\nCPF: " << d1 << d2 << d3 << "." << d4 << d5 << d6 << "." << d7 << d8 << d9 << "-" << v1 << v2;

    } else if ((cpf <= 99999999) && (cpf >= 10000000)){
        // Após verificar uma segunda vez, se o CPF é de 8 dígitos, continuamos.

        // Isolando o dígito e indo para o próximo, assim como no condicional anterior.
        d8 = cpf%10;
        cpf = cpf/10;
        d7 = cpf%10;
        cpf = cpf/10;
        d6 = cpf%10;
        cpf = cpf/10;
        d5 = cpf%10;
        cpf = cpf/10;
        d4 = cpf%10;
        cpf = cpf/10;
        d3 = cpf%10;
        cpf = cpf/10;
        d2 = cpf%10;
        d1 = cpf/10;

        // Calculando o dígito verificador 1:
        v1 = ((d1*9) + (d2*8) + (d3*7) + (d4*6) + (d5*5) + (d6*4) + (d7*3) + (d8*2))%11;

        // Verificando se o resto do somatório é menor que 2.
        if (v1 < 2){
            v1 = 0;
        } else {
            v1 = 11 - v1;
        }
        
        // Calculando o dígito verificador 2:
        v2 = ((d1*10) + (d2*9) + (d3*8) + (d4*7) + (d5*6) + (d6*5) + (d7*4) + (d8*3) + (v1*2))%11;

        if (v2 < 2){
            v2 = 0;
        } else {
            v2 = 11 - v2;
        }

        // CPF final:
        cout << "\nCPF: " << "0" << d1 << d2 << "." << d3 << d4 << d5 << "." << d6 << d7 << d8 << "-" << v1 << v2;


    } else {
        // Caso tenha sido colocado um número com menos de 8 dígitos ou com mais de 9 dígitos.
        cout << "CPF inválido!";
    }

    return 0;
}
