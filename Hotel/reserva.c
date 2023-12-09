#include <stdio.h>
#include <string.h>
#include <time.h>

#define NUM_QUARTOS 32
#define NUM_ANDARES 8

struct Quartos
{
    int andar;
    int NumQuarto;
    char Status[20];
    char GuestName[20];
};

struct reserva
{
    char nome[20];
    int quartoSelect;
    int noites;
    char Date[11];
    char Cod[11];
};

struct Quartos quartos[NUM_QUARTOS];

void obterDataHoraAtual(char *dataHora)
{
    time_t t;
    struct tm *info;

    time(&t);
    info = localtime(&t);

    strftime(dataHora, 20, "%d/%m/%Y %H:%M:%S", info);
}
void encontrarQuarto()
{
    FILE *arquivo = fopen(".\\output\\Quartos.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
    }

    for (int i = 0; i < NUM_QUARTOS; ++i)
    {
        if (fscanf(arquivo, "%d", &quartos[i].NumQuarto) != 1)
        {
            printf("Erro ao ler número do quarto %d\n", i + 1);
            break;
        }

        if (fscanf(arquivo, "%19s", quartos[i].Status) != 1)
        {
            printf("Erro ao ler status do quarto %d\n", i + 1);
            break;
        }

        if (fscanf(arquivo, "%19s", quartos[i].GuestName) != 1)
        {
            printf("Erro ao ler nome do hospede %d\n", i + 1);
            break;
        }

        if (fscanf(arquivo, "%d", &quartos[i].andar) != 1)
        {
            printf("Erro ao ler número do andar %d\n", i + 1);
            break;
        }
    }

    fclose(arquivo);
}
void Reserva()
{
    struct reserva reservas[5];
    int quartoEncontrado = 0;
    char dadosCorreto;
    encontrarQuarto();

    do
    {

        do
        {
            printf("===============================================\n");
            printf("             Hotel - Reservar Quarto\n");
            printf("===============================================\n");

            printf("\nEscolha um dos Quartos Disponiveis :\n\n");
            int coluna_atual = 0;
            // mostra os quartos em uma tabela de 4 colunas
            for (int i = 0; i < NUM_QUARTOS; ++i)
            {
                if (strcmp(quartos[i].Status, "Livre") == 0)
                {
                    printf(" Quarto %3d: %-6s | ", quartos[i].NumQuarto, quartos[i].Status);
                    coluna_atual++;
                    if (coluna_atual == 4)
                    {
                        printf("\n");
                        coluna_atual = 0;
                    }
                }
            }
            scanf("%d", &reservas[1].quartoSelect);

            quartoEncontrado = 0;

            for (int i = 0; i < NUM_QUARTOS; ++i)
            {
                if (quartos[i].NumQuarto == reservas[1].quartoSelect)
                {
                    quartoEncontrado = 1;
                    system("cls");
                    break;
                }
            }
            system("cls");
        } while (quartoEncontrado == 0);
        printf("===============================================\n");
        printf("             Hotel - Reservar Quarto\n");
        printf("===============================================\n");
        printf("Nome do Hóspede:");
        fflush(stdin);
        reservas[1].nome[strcspn(reservas[1].nome, "\n")] = '\0';
        fgets(reservas[1].nome, sizeof(reservas[1].nome), stdin);
        printf("Quantas Noites : ");
        scanf("%d", &reservas[1].noites);

        system("cls");

        printf("===============================================\n");
        printf("             Hotel - Reservar Quarto\n");
        printf("===============================================\n");
        printf("Nome do Hospede: %s", reservas[1].nome);
        printf("Quarto Selecionado: %d\n", reservas[1].quartoSelect);
        printf("Noites: %d\n", reservas[1].noites);
        obterDataHoraAtual(reservas[1].Date); // Obtém a data e hora atual
        printf("Data e Hora da Reserva: %s\n", reservas[1].Date);

        printf("\nos dados estão corretos? (s/n)");
        scanf(" %c", &dadosCorreto);
        system("cls");

    } while (dadosCorreto == 'n');
    // atualiza os status do quarto
    if (dadosCorreto == 's')
    {

                
        char nomeArquivo[100];
        sprintf(nomeArquivo, ".\\output\\Hospedes\\reserva_%d.txt", reservas[1].quartoSelect);

        FILE *arquivoReserva = fopen(nomeArquivo, "w");
        if (arquivoReserva == NULL)
        {
            printf("Erro ao abrir o arquivo de reserva\n");
        }

        // Escrever os detalhes da reserva no arquivo
        fprintf(arquivoReserva, "Nome do Hospede: %s\n", reservas[1].nome);
        fprintf(arquivoReserva, "Quarto Selecionado: %d\n", reservas[1].quartoSelect);
        fprintf(arquivoReserva, "Noites: %d\n", reservas[1].noites);
        fprintf(arquivoReserva, "Data e Hora da Reserva: %s\n", reservas[1].Date);

        // Fechar o arquivo
        fclose(arquivoReserva);
        for (int i = 0; i < NUM_QUARTOS; ++i)
        {
            if (quartos[i].NumQuarto == reservas[1].quartoSelect)
            {
                strcpy(quartos[i].Status, "ocupado");
                strcpy(quartos[i].GuestName, reservas[1].nome);
                break;
            }
        }
        FILE *arquivo = fopen(".\\output\\Quartos.txt", "w");
        if (arquivo == NULL)
        {
            printf("Erro ao abrir o arquivo para escrita\n");
        }
        for (int i = 0; i < NUM_QUARTOS; ++i)
        {
            fprintf(arquivo, "%d %s %s %d\n", quartos[i].NumQuarto, quartos[i].Status, quartos[i].GuestName, quartos[i].andar);
        }
        fclose(arquivo);
    }
    else
    {
        printf("Erro ao cadastrar reserva\n");
    }

    
}
