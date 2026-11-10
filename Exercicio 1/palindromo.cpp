//*Elabore um algoritmo recursivo para checar se uma string é um palíndromo (uma palavra que ao ser invertida, fica igual).
//*Para representar o tipo string você pode usar o próprio tipo da biblioteca <string> ou um ponteiro char*.

#include <iostream>
using namespace std;

bool Palindromo(const char* inicio, const char* fim=nullptr){
    if(fim==nullptr){
        if (inicio==nullptr || *inicio=='\0')
            return true;
        
        fim=inicio;
        
        while(*fim!='\0')
            fim++;
        
        fim--;
    }

    if(inicio>=fim)
        return true;

    if(*inicio!=*fim)
        return false;

    return Palindromo(inicio + 1, fim - 1);
}

int main() {
    FILE *arquivo = fopen("possiveispaindromos.txt", "r");
    FILE *arquivo2 = fopen ("palindromos.txt", "a");
    char linha[100];

    while (fgets(linha, sizeof(linha), arquivo) != nullptr){
    if(Palindromo(linha)){
        fprintf(arquivo, "\n%s",linha);
        cout << "\nPalavra " << linha << " Adicionada";
    }   
    else{
        cout<<"\nA palavra "<<linha<<" nao e um palindromo.\n";
        }
    }
    fclose(arquivo);
    fclose(arquivo2);

    return 0;
}