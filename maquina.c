/* Nome: Tiago Cunha e Thiago Laudiano
Turma: 10ºF
Numero: Tiago Cunha = 23, Thiago = 21
Função: Criar uma maquina de cafe (Maquina do Sr.Paulo) */

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    do {

        int opcao, nivelAcucar;
        float valordoproduto, dinheiroInserido, totalPago, troco;

        // MENU
        puts("\033[36m===============================================\033[0m");
        puts("\033[33m|         Maquina de cafe 24h do Sr. Paulo    |\033[0m");
        puts("\033[36m===============================================\033[0m");

        puts("\033[32m1: Café.........................0.60EUR\033[0m");
        puts("\033[32m2: Galão........................0.80EUR\033[0m");
        puts("\033[32m3: Meia de leite................0.75EUR\033[0m");
        puts("\033[32m4: Chocolate quente.............1.00EUR\033[0m");
        puts("\033[32m5: Capuccino....................1.20EUR\033[0m");
        puts("\033[32m6: Sair\033[0m");

        printf("\033[36mEscolha uma das opções:\033[0m ");
        scanf("%d", &opcao);
        fflush(stdin);
        Beep(2000, 150);

        if (opcao < 1 || opcao > 6)  {
            printf("\nNumero invalido, digite outro numero\n ");
            Sleep(2000);
            system("cls");
            fflush(stdin);
            continue;
        }

        if (opcao == 6) {
            printf("Obrigado por usar a Maquina do Sr.Paulo. Ele agora esta muito feliz :) ");
            break;
        }

        switch(opcao) {
            case 1: valordoproduto = 0.60; break;
            case 2: valordoproduto = 0.80; break;
            case 3: valordoproduto = 0.75; break;
            case 4: valordoproduto = 1.00; break;
            case 5: valordoproduto = 1.20; break;
        }

        // PAGAMENTO APENAS COM MOEDAS 0.05 ATÉ 2€
        totalPago = 0;
        while (totalPago < valordoproduto) {

            printf("\033[34mInsira moeda (0.05, 0.10, 0.20, 0.50, 1.00, 2.00 EUR): \033[0m");
            scanf("%f", &dinheiroInserido);

            if ((dinheiroInserido > 0.049 && dinheiroInserido < 0.051) ||
                (dinheiroInserido > 0.099 && dinheiroInserido < 0.101) ||
                (dinheiroInserido > 0.199 && dinheiroInserido < 0.201) ||
                (dinheiroInserido > 0.499 && dinheiroInserido < 0.501) ||
                (dinheiroInserido > 0.999 && dinheiroInserido < 1.001) ||
                (dinheiroInserido > 1.999 && dinheiroInserido < 2.001)) {

                totalPago += dinheiroInserido;
                Beep(1500, 120);

                if (totalPago < valordoproduto) {
                    printf("\033[33mDinheiro insuficiente! Faltam %.2f EUR.\033[0m\n", valordoproduto - totalPago);
                }

            } else {
                printf("\033[31mMoeda nao aceite! Tente novamente.\033[0m\n");
                Sleep(1500);
                system("cls");
                fflush(stdin);
            }
        }

        troco = totalPago - valordoproduto;
        printf("\033[32mPagamento aceite! Troco: %.2f EUR\033[0m\n", troco);

        // AÇÚCAR
        do {
            printf("\033[35mDeseja açúcar na bebida?\n");
            printf("0 - Sem açúcar\n");
            printf("1 - Normal\n");
            printf("2 - Muito doce\n");
            printf("Escolha uma opção: \033[0m");
            scanf("%d", &nivelAcucar);

            if (nivelAcucar < 0 || nivelAcucar > 2) {
                printf("\033[31mOpção inválida! Digite novamente.\033[0m\n");
                fflush(stdin);
            }

        } while (nivelAcucar < 0 || nivelAcucar > 2);

        switch(nivelAcucar) {
            case 0: printf("\033[33mBebida sem açúcar selecionada.\033[0m\n"); break;
            case 1: printf("\033[33mBebida com açúcar normal.\033[0m\n"); break;
            case 2: printf("\033[33mBebida muito doce!\033[0m\n"); break;
        }

        // Entrega
        printf("\033[32mProduto a ser entregue... [");
        for (int i = 0; i < 10; i++) {
            printf("=");
            fflush(stdout); // Limpar buffer da saida
            Sleep(200);
        }
        printf("] Concluído!\033[0m\n");

        for (int i = 0; i < 5; i++) {
            Beep(1000, 150);
            Sleep(750);
        }

        printf("\033[0mRetire a sua bebida!\033[0m\n");
        printf("\033[0mObrigado e volte sempre!\033[0m\n");

        Sleep(5000);
        system("cls");
        printf("\n");

    } while (1);

    return 0;
}