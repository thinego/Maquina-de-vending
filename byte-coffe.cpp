#include <iostream>
#include <stdlib.h>
#include <locale>
#include <cstdlib>
#include <windows.h>

using namespace std;

string produtos[10] = {
"Cafe Longo","Cafe Curto","Cafe Pingado","Chocolate",
"Capuccino","Galao","Cha de Limao","Leite",
"Chocolate Quente","Agua"
};

float precos[10] = {0.70,0.70,0.80,0.85,0.95,0.95,0.95,0.60,1.00,0.50};

int stock[10] = {12,12,12,12,12,12,12,12,12,12};

int vendidos[10] = {0};

float totalVendas = 0;

void menu()
{
    cout << "\n===== MAQUINA DE CAFE =====\n";

    for(int i=0;i<10;i++)
    {
        cout << i+1 << " - " << produtos[i];

        if(stock[i]==0)
            cout << " --- ESGOTADO";
        else
            cout << " --- " << precos[i] << " EUR";

        cout << endl;
    }

    cout << "0 - Sair\n";
}

float pagamento(float preco)
{
    float moeda,total=0;

    while(total<preco)
    {
        cout << "Inserir moeda (0.05 0.10 0.20 0.50 1 2): ";
        
        cin >> moeda;

        if(abs (moeda-0.05) < 0.001 || abs (moeda-0.10) < 0.001 || abs (moeda-0.20) < 0.001 || abs (moeda-0.50) < 0.001 || abs (moeda-1.00) < 0.001 || abs (moeda-2.00) < 0.001)
        {
            total+=moeda;
            cout << "Total inserido: " << total << endl;
        }
        else
            cout << "Moeda invalida\n";
            system("cls");
    }

    float troco = total-preco;

    cout << "Troco: " << troco << endl;

    return troco;
}

int escolherAcucar()
{
    int nivel;

    do{
        cout << "\nNivel de acucar:\n";
        cout << "0 - Sem acucar\n";
        cout << "1 - Normal\n";
        cout << "2 - Muito doce\n";
        cout << "Escolha: ";

        cin >> nivel;

        if(nivel<0 || nivel>2)
            cout << "Opcao invalida\n";
            system("cls");

    }while(nivel<0 || nivel>2);

    if(nivel==0)
        cout << "Bebida sem acucar\n";

    if(nivel==1)
        cout << "Bebida com acucar normal\n";

    if(nivel==2)
        cout << "Bebida muito doce\n";

    return nivel;
}

void entregar()
{
    cout << "A preparar bebida...\n";

    for(int i=0;i<10;i++)
    {
        cout << "=";
        Sleep(200);
    }

    cout << "\nRetire a sua bebida\n";
}

void relatorio()
{
    cout << "\n===== RELATORIO VENDAS =====\n";

    for(int i=0;i<10;i++)
        cout << produtos[i] << " vendidos: " << vendidos[i] << endl;

    cout << "Total vendas: " << totalVendas << " EUR\n";
}
void talao(string produto, float preco, float pago, float troco)
{
    char op;

    cout << "Deseja talao? (s/n): ";
    cin >> op;

    if(op=='s' || op=='S')
    {
        cout << "\n----- TALAO -----\n";
        cout << "Produto: " << produto << endl;
        cout << "Preco: " << preco << " EUR\n";
        cout << "Pago: " << pago << " EUR\n";
        cout << "Troco: " << troco << " EUR\n";
        cout << "-----------------\n";
        system("pause");
        system("cls");
    }
}
void modoGestao()
{
    int pin;

    cout << "PIN: ";
    cin >> pin;

    if(pin!=1234)
    {
        cout << "PIN errado\n";
        return;
    }

    int op;

    do{

        cout << "\n===== MODO GESTAO =====\n";
        cout << "1 - Alterar preco\n";
        cout << "2 - Repor stock\n";
        cout << "3 - Relatorio vendas\n";
        cout << "0 - Sair\n";

        cin >> op;

        if(op==1)
        {
            int p;
            float novo;

            cout << "Produto: ";
            cin >> p;

            cout << "Novo preco: ";
            cin >> novo;

            precos[p-1]=novo;
        }

        if(op==2)
        {
            int p;
            int qtd;

            cout << "Produto: ";
            cin >> p;

            cout << "Quantidade (max 12): ";
            cin >> qtd;

            if(qtd<=12)
                stock[p-1]=qtd;
        }

        if(op==3)
            relatorio();

    }while(op!=0);
}

int main()
{
    setlocale(LC_ALL,"portuguese");

    int opcao;

    while(true)
    {
        menu();

        cout << "Opcao (-99 gestao): ";
        cin >> opcao;

        if(opcao==-99)
        {
            modoGestao();
            continue;
        }

        if(opcao==0)
            break;

        if(opcao<1 || opcao>10)
        {
            cout << "Opcao invalida\n";
            continue;
        }

        if(stock[opcao-1]==0)
        {
            cout << "Produto esgotado\n";
            continue;
        }

        pagamento(precos[opcao-1]);

        escolherAcucar();

        entregar();

        talao(produtos[opcao-1],precos[opcao-1],precos[opcao-1],0);

        stock[opcao-1]--;

        vendidos[opcao-1]++;

        totalVendas += precos[opcao-1];
    }

    cout << "Obrigado por usar a maquina!\n";

    return 0;
}