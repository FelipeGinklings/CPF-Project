// Caethano Rampelotti da Rosa,Eduardo José de Souza, Arthur Felipe e Felipe Ginklings.
#include <iostream>
using namespace std;

int main() {
    int cpf,pr1,pr2; 
//informando o cpf e salvando ele em outras variaves.
    cout << "Informe o CPF (apenas números): ";
    cin >> cpf;
    int cpf1=cpf;
    int cpf_final=cpf;
 // Verificando se o CPF tem 9 dígitos.
    if (cpf < 100000000 || cpf > 999999999) {
        cout << "O CPF deve conter 9 dígitos";
    } else {
        // Separando os digitos.
        int digito2= (cpf % 10)*2;
        cpf /= 10;
        int digito3= (cpf % 10)*3;
        cpf /= 10;
        int digito4= (cpf % 10)*4;
        cpf /= 10;
        int digito5 = (cpf % 10)*5;
        cpf /= 10;
        int digito6 = (cpf % 10)*6;
        cpf /= 10;
        int digito7 = (cpf % 10)*7;
        cpf /= 10;
        int digito8 = (cpf % 10)*8;
        cpf /= 10;
        int digito9 = (cpf % 10)*9;
        cpf /= 10;
        int digito10 = (cpf % 10)*10;
//Efetuando o primeiro digito confimardor	
	int soma=digito10+digito9+digito8+digito7+digito6+digito5+digito4+digito3+digito2;
	int divisao=soma/11;
	int mod=soma%11;
    if(mod>2){
		pr1=11-mod;
	}else{
		pr1=0;
	}
//Separando os digitos com o novo cpf.      
	int digito_2= pr1*2; 
    int digito_3= (cpf1 % 10)*3;
    cpf1 /= 10;
    int digito_4= (cpf1 % 10)*4;
    cpf1 /= 10;
    int digito_5= (cpf1 % 10)*5;
    cpf1 /= 10;
    int digito_6 = (cpf1 % 10)*6;
    cpf1 /= 10;
    int digito_7 = (cpf1 % 10)*7;
    cpf1 /= 10;
    int digito_8 = (cpf1 % 10)*8;
    cpf1 /= 10;
    int digito_9 = (cpf1 % 10)*9;
    cpf1 /= 10;
    int digito_10 = (cpf1 % 10)*10;
    cpf1 /= 10;
    int digito_11 = (cpf1 % 10)*11;
//Efetuando o segundodigito comfirmador digito confimardor.	
    int soma2=digito_11+digito_10+digito_9+digito_8+digito_7+digito_6+digito_5+digito_4+digito_3+digito_2;
    int divisao2=soma2/11;
	int mod2=soma2%11;
    if(mod2>2){
		pr2=11-mod2;
	}else{
		pr2=0;
	}
    cout<<"Cpf:"<<cpf_final<<pr1<<pr2;   
    }
    return 0;
}
