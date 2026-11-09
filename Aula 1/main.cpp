#include <fstream>
#include <iostream>
using namespace std;

int main () {
    FILE *arquivo = fopen("pessoas.txt", "r");

    if (arquivo == nullptr) {
        cout << "Arquivo não encontrado";
        return 1;
    }

    char linha[80];

    while (fgets(linha, sizeof(linha), arquivo) != nullptr) {
        char nome[50];
        int idade;
        char email[50];
        sscanf(linha, "%s %d %s", &nome, &idade, &email);

       cout << "Nome: " << nome << "\nIdade: " << idade << "\nEmail: " << email << "\n\n";
       // printf("\nNome: %s \nIdade: %d \nEmail: %s \n\n",nome, idade, email);
    }

    fclose(arquivo);
    
}