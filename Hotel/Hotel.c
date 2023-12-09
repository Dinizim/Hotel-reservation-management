#include <stdio.h>
#include "reserva.h"

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();

    SetConsoleOutputCP(CPAGE_UTF8);

    int select;
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
        scanf("%d", select);
    } while (select != 0);
    switch (select)
    {
    case 1:
        Reserva();
        break;

    default:
        break;
    }
    SetConsoleOutputCP(CPAGE_DEFAULT);
}