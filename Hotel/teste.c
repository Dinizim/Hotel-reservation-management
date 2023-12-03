#include <stdio.h>
#define NUM_QUARTOS 32

struct Quarto
{
    char nome[20];
    int numero;
    char status[10]; // Pode ser "Livre" ou "Ocupado"
};

int main()
{
    struct Quarto quartos[NUM_QUARTOS];

    // Carregar dados do arquivo
    FILE *arquivo = fopen("quartos.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return 1; // Saia com código de erro
    }

    for (int i = 0; i < NUM_QUARTOS; ++i)
    {
        // Utilizando fscanf separadamente para número e status
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

    int j = 3;
    int k = 1;
    // Exibir status dos quartos
    printf("Status dos Quartos:\n\n");
    for (int i = 0; i < NUM_QUARTOS; ++i)
    {
        if (++j == 4) {
            printf("\n");
            printf("Andar %d:\n", k);
            printf("\n"); // Adiciona uma nova linha após cada grupo de 4 quartos
            j = 0; // Reinicia o contador
            k++;
        }
        printf("Quarto %d: %s\n", quartos[i].numero, quartos[i].status);
        


    }

    return 0;
}
