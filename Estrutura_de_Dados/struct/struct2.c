// Definir um tipo chamado Aluno para armazenar os seguintes dados de um aluno: numero de matrícula e
// data de nascimento (tipo Data).
// Escrever um programa em C para ler a data de hoje armazenando-a em uma varia vel do tipo Data. A seguir ler
// uma quantidade indeterminada de dados de alunos (Aluno). Para cada aluno lido escrever se ele ja completou
// 18 anos ate a data informada. O programa termina ao ser informado um valor negativo para a matrí cula. Nesta
// situaçao a data de nascimento nao deve ser lida.

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia, mes, ano;
} Data;

typedef struct
{
    int matricula;
    Data dataNasc;
} Aluno;

int main(void)
{
    Data dataAtual;
    Aluno aluno;

    printf("Digite a data de hoje no formato: DD/MM/YYYY\n");
    do
    {
        printf("Digite o dia de hoje: ");
        scanf("%d", &dataAtual.dia);
        if (dataAtual.dia <= 0 || dataAtual.dia > 31)
        {
            printf("Dia inválido. Digite novamente.\n");
            getchar();
            getchar();
            printf("\n");
        }
    } while (dataAtual.dia <= 0 || dataAtual.dia > 31);

    do
    {
        printf("Digite o mes atual: ");
        scanf("%d", &dataAtual.mes);
        if (dataAtual.mes <= 0 || dataAtual.mes > 12)
        {
            printf("Mês inválido. Digite novamente.\n");
            getchar();
            getchar();
            printf("\n");
        }
    } while (dataAtual.mes <= 0 || dataAtual.mes > 12);

    do
    {
        printf("Digite o ano atual: ");
        scanf("%d", &dataAtual.ano);
        if (dataAtual.ano < 1895 || dataAtual.ano > 2025)
        {
            printf("Ano inválido. Digite novamente.\n");
            getchar();
            getchar();
            printf("\n");
        }

    } while (dataAtual.ano < 1895 || dataAtual.ano > 2025);

    printf("Data atual: %d/%d/%d\n", dataAtual.dia, dataAtual.mes, dataAtual.ano);

    do
    {
        printf("Digite a matrícula do aluno: ");
        scanf("%d", &aluno.matricula);
        if (aluno.matricula < 0)
        {
            printf("Número inválido de matrícula.\n");
            break;
        }

        printf("Digite digite a data de nascimento do aluno no formato: DD:MM:YYYY\n");
        do
        {
            printf("Dia de nascimento: ");
            scanf("%d", &aluno.dataNasc.dia);
            if (aluno.dataNasc.dia < 0 || aluno.dataNasc.dia > 31)
            {
                printf("Dia inválido. Digite novamente.\n");
                getchar();
                getchar();
                printf("\n");
            }

        } while (aluno.dataNasc.dia < 0 || aluno.dataNasc.dia > 31);

        do
        {
            printf("Mês de nascimento: ");
            scanf("%d", &aluno.dataNasc.mes);
            if (aluno.dataNasc.mes < 0 || aluno.dataNasc.mes > 12)
            {
                printf("Dia inválido. Digite novamente.\n");
                getchar();
                getchar();
                printf("\n");
            }

        } while (aluno.dataNasc.mes < 0 || aluno.dataNasc.mes > 12);

        do
        {
            printf("Ano de nascimento: ");
            scanf("%d", &aluno.dataNasc.ano);
            if (aluno.dataNasc.ano < 1895 || aluno.dataNasc.ano > 2025)
            {
                printf("Ano inválido. Digite novamente.\n");
                getchar();
                getchar();
                printf("\n");
            }

        } while (aluno.dataNasc.ano < 1895 || aluno.dataNasc.ano > 2025);

        if ((dataAtual.ano > aluno.dataNasc.ano + 18))
        {
            printf("Aluno já completou 18 anos.\n");
        }
        else if (dataAtual.ano == aluno.dataNasc.ano + 18)
        {
            if (dataAtual.mes > aluno.dataNasc.mes)
            {
                printf("Aluno já completou 18 anos.\n");
            }
            else if (dataAtual.mes == aluno.dataNasc.mes && aluno.dataNasc.dia <= dataAtual.dia)
            {
                printf("Aluno já completou 18 anos.\n");
            }
            else
            {
                printf("Aluno ainda não completou 18 anos.\n");
            }
        }
        else
        {
            printf("Aluno ainda não completou 18 anos.\n");
        }
        printf("\n");

    } while (aluno.matricula > 0);

    return 0;
}