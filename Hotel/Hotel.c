#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include "reserva.h"

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();

    SetConsoleOutputCP(CPAGE_UTF8);

    int select = 4;
    do
    {
        printf("\nSeja bem vindo!\n");
        printf("===============================================\n");
        printf("             Hotel - Atendimento\n");
        printf("===============================================\n");
        printf("1 - Reservar Quarto\n");
        printf("2 - Gerar Fatura\n");
        printf("0 - Sair\n");
        printf("Escolha a obra desejada: ");
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            system("cls");
            Reserva();

            break;

        default:
            break;
        }
        SetConsoleOutputCP(CPAGE_DEFAULT);
    } while (select != 0);
}