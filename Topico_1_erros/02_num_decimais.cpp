#include <iostream>

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
    int aux = M - m; //auxiliar para pegar o tanto de valores para serem mostrados
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

int main() {

    double decimal;
    int base, precisao, m, M;

    cin >> decimal >> base >> precisao >> m >> M;

    string i = decimal_para_binario(decimal, m, M);
    string j = cont_negativos(i, m, M);

    cout << j << endl;
    return 0;
}
