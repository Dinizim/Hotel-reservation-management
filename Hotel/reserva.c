#include <stdio.h>
#define NUM_QUARTOS 32
#define NUM_ANDARES 8


struct Quartos
{
    int NumQuarto;
    char Status[20];
    char GuestName[20];
};

void encontrarQuarto()
{
    struct Quarto quartos[NUM_QUARTOS];

    FILE *arquivo = fopen("quartos.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return 1; 
    }
    //fscaf para puxar dados do arquivo txt
     for (int i = 0; i < NUM_QUARTOS; ++i)
    {

        if (fscanf(arquivo, "%d", &quartos[i].numero) != 1)
        {
            printf("Erro ao ler número do quarto %d\n", i + 1);
            break;
        }

        if (fscanf(arquivo, "%9s", quartos[i].status) != 1)
        {
            printf("Erro ao ler status do quarto %d\n", i + 1);
            break;
        }
        if (fscanf(arquivo, "%9s", quartos[i].nome) != 1)
        {
            printf("Erro ao ler nome do hospede %d\n", i + 1);
            break;
        }
    }

    fclose(arquivo);

}
void Reserva()
{
}