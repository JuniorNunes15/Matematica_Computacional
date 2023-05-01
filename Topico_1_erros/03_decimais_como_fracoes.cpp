#include <iostream>
#include <cmath>

using namespace std;

string decimal_para_binario(double decimal, int m, int M) {
    string binario = ""; //string que vai guardar o novo valor convertido a binarios
    int aux = M - m + 10; //vai pegar o valor total de M - m e + 10, apenas para pegar mais numeros para caso serem necessarios
    int b; //valor para pegar o inteiro do decimal 
    while(aux > 0) {
        decimal *= 2;
        b = decimal;
        if(decimal >= 1) //verificacao para caso o valor ja seja maior que 1, e caso for, resetar o valor
            decimal = decimal - (int)decimal;
        binario += std::to_string(b); //na string vai sendo adicionado sempre o novo valor de b, formando o binario
        aux--;
    }
    return binario;
}

string cont_negativos(string binario, int m, int M) { //funcao que vai remover os n primeiros zeros do binario
    string novo_binario = "0."; //o novo valor do binario vai ser guardada em uma nova string
    int cont_zeros = 0; //auxiliar para contar quantos zeros no inicio foi retirados
    bool eliminar = true; //booleano auxiliar para que no for, seja pegues apenas os zeros antes do primeiro 1
    int aux = M; //auxiliar para pegar o tanto de valores para serem mostrados
    for(int i = 0; i < aux+cont_zeros; i++) { 
        if(binario[i] == '0' && eliminar) { //verifica os n primeiros zeros anteriores ao 1
            cont_zeros++;
        }
        else {
            eliminar = false;
            novo_binario += binario[i];
        }
    }
    novo_binario += " -" + std::to_string(cont_zeros);
    return novo_binario;
}

void fracao(string binario, int M, double decimal) {
    int *numerador = (int*)malloc(sizeof(int)*M);
    int *denominador = (int*)malloc(sizeof(int)*M);
    int aux = 1, j = 0;
    int aux_decimal = 0;
    for(int i = 2; i < M+2; i++) {
        if(binario[i] == '1') {
            numerador[j] = 1;
            denominador[j] = aux*2;
            j++;
        }
        if(decimal < 1) {
            aux_decimal++;
            decimal *= 10;
        }
        aux *= 2;
    }
    int k = static_cast<int>(binario[binario.length()-1]) - static_cast<int>('0');
    int num_final = 0;
    for(int i = 0; i < j; i++) {
        while(denominador[i] < denominador[j-1]) {
            numerador[i] *= 2;
            denominador[i] *= 2;
        }
        num_final += numerador[i];
    }
    
    int den_final = denominador[0] * pow(2,k);
    cout << num_final << "/" << den_final << endl; 


    int num_compare = 1;
    int dem_compare = pow(10,aux_decimal);

    num_compare *= den_final;
    num_final *= dem_compare;
    int x = dem_compare;
    dem_compare *= den_final; 
    den_final *= x;
    num_compare -= num_final;

    while(1) {
        if(num_compare % 2 == 0 && den_final % 2 == 0) {
            num_compare /= 2;
            den_final /= 2;
        }
        else if(num_compare % 3 == 0 && den_final % 3 == 0) {
            num_compare /= 3;
            den_final /= 3;
        }
        else if(num_compare % 5 == 0 && den_final % 5 == 0) {
            num_compare /= 5;
            den_final /= 5;
        }
        else if(num_compare % 7 == 0 && den_final % 7 == 0) {
            num_compare /= 7;
            den_final /= 7;
        }
        else if(num_compare % 11 == 0 && den_final % 11 == 0) {
            num_compare /= 11;
            den_final /= 11;
        }
        else {
            break;
        }
    }

    cout << num_compare << "/" << den_final << endl;
}

int main() {

    double decimal;
    int base, precisao, m, M;

    cin >> decimal >> base >> precisao >> m >> M;

    string i = decimal_para_binario(decimal, m, M);
    string j = cont_negativos(i, precisao, precisao);

    if( M < static_cast<int>(j[j.length()-1]) - static_cast<int>('0') ) { 
        cout << "underflow" << endl;
    }
    else {
        fracao(j, precisao, decimal);
    }

    return 0;
}