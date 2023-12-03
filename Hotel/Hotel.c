#include <stdio.h>
#include "reserva.h"

int main()
{
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
        
        break;
    
    default:
        break;
    }

}