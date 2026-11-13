#include <iostream>
using namespace std;

void lerArquivo();
void cadastrar();

int main() {
    char opcao = '0';

    while(opcao != '3' && opcao != 'E' && opcao != 'e'){
        cout << "\033c\n================================================"
             << "\n###>     BEM-VINDO AO JOGO DE DOMINO!       <###\n\n"
             << "\t      1 - [V]isualizar   \n"
             << "\t      2 - [C]adastrar   \n"
             << "\t      3 - [E]ncerrar   \n"
             << "================================================\n"
             << "Escolha uma opcao: ";
        cin >> opcao;

        switch(opcao){
            case '1': case 'V': case 'v':
                lerArquivo();
                break;
            case '2': case 'C': case 'c':
                cadastrar();
                break;
            case '3': case 'E': case 'e':
                cout << "\nVoce selecionou encerrar programa!\n";
                break;
            default:
                cout << "\nOpcao inexistente, escolha novamente.\n";
                break;
        }
    }

    return 0;
}

void lerArquivo(){
    char placa[10];
    char modelo[100];
    char marca[100];
    char linha[256];
    char sair;

    FILE *arquivo = fopen("cadastros.txt", "r");

    if (arquivo == nullptr) {
        cout << "Erro ao abrir arquivo!";
        return;
    }

    while (fgets(linha, sizeof(linha), arquivo) != nullptr) {
        sscanf(linha, "%s %s %s", &marca, &modelo, &placa);

        cout << "Marca: " << marca << "\nModelo: " << modelo << "\nPlaca " << placa << "\n\n"; 
    }
    

    do {
        cout << "Deseja retornar? Digite S ou N: ";
        cin >> sair;

        if (sair != 's' && sair != 'S' && sair != 'n' && sair != 'N') {
            cout << "Opcao invalida! Tente novamente.\n";
        }

    } while (sair != 's' && sair != 'S' && sair != 'n' && sair != 'N');

    fclose(arquivo);
}

void cadastrar(){
    char placa[10];
    char modelo[100];
    char marca[100];
    char linha[256];
    FILE *arquivo = fopen("cadastros.txt", "a");

    if (arquivo == nullptr) {
        cout << "Erro ao abrir arquivo!";
        return;
    }   

    cout << "\n\n--- Novo carro ---";
    cout << "\nMarca: ";
    cin >> marca; 

    cout << "\nModelo: ";
    cin >> modelo;

    cout << "\nPlaca ex:[QHV-9A17]:  ";
    cin >> placa;

    fprintf(arquivo, "\n%s %s %s", marca, modelo, placa);
    fclose(arquivo);
}



