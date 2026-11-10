#include <fstream>
#include <iostream>
using namespace std;

int main () {
    FILE *arquivo = fopen("pessoas.txt", "r");

    if (arquivo == nullptr) {
        cout << "Arquivo não encontrado";
        return 1;
    }

    char nome[50];
    int idade;
    char email[50];

    char linha[80];

    while (fgets(linha, sizeof(linha), arquivo) != nullptr) {

        sscanf(linha, " %49[^;]; %d %s", &nome, &idade, &email);

        cout << "Nome: " << nome << "\nIdade: " << idade << "\nEmail: " << email << "\n\n"; 
       // printf("\nNome: %s \nIdade: %d \nEmail: %s \n\n",nome, idade, email);
    }

    fclose(arquivo);
    
    arquivo = fopen("pessoas.txt", "a");

    cout << "\n\n--- Nova pessoa ---";
    cout << "\nNome; ";
    cin >> nome; 

    cout << "\nIdade: ";
    cin >> idade;

    cout << "\nEmail: ";
    cin >> email;

    fprintf(arquivo, "\n%s;%d %s", nome, idade, email);
    fclose(arquivo);

}