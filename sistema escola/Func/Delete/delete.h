#include <stdio.h>
#include "../../Structs/structs.h"

// FUNÇÕES PARA EXCLUIR ALUNOS, PROFESSORES E PEDAGOGICO
void excluirAluno(struct Aluno alunos[], int *total)
{
    int numeroExcluir;
    printf("Digite o n�mero do aluno que deseja excluir: ");
    scanf("%d", &numeroExcluir);

    int encontrado = 0;
    for (int i = 0; i < *total; i++)
    {
        if (alunos[i].numero == numeroExcluir)
        {
            encontrado = 1;
            for (int j = i; j < (*total) - 1; j++)
            {
                alunos[j] = alunos[j + 1]; // Desloca os alunos para preencher o espaço
            }
            (*total)--; // Reduz o total de alunos
            break;
        }
    }

    if (encontrado)
    {
        FILE *arquivo = fopen("alunos.txt", "w");
        if (arquivo == NULL)
        {
            printf("Erro ao abrir o arquivo para salvar!\n");
            return;
        }
        for (int i = 0; i < *total; i++)
        {
            fprintf(arquivo, "%s %d %s\n", alunos[i].nome, alunos[i].numero, alunos[i].escolaridade);
        }
        fclose(arquivo);
        printf("Aluno removido com sucesso!\n");
    }
    else
    {
        printf("Aluno não encontrado.\n");
    }
}

void excluirProf(struct Professor professores[], int *total)
{
    int numeroExcluir;
    printf("Digite o número do professor que deseja excluir: ");
    scanf("%d", &numeroExcluir);

    int encontrado = 0;
    for (int i = 0; i < *total; i++)
    {
        if (professores[i].numero == numeroExcluir)
        {
            encontrado = 1;
            for (int j = i; j < (*total) - 1; j++)
            {
                professores[j] = professores[j + 1]; // Desloca os alunos para preencher o espaço
            }
            (*total)--; // Reduz o total de alunos
            break;
        }
    }

    if (encontrado)
    {
        FILE *arquivo = fopen("profs.txt", "w");
        if (arquivo == NULL)
        {
            printf("Erro ao abrir o arquivo para salvar!\n");
            return;
        }
        for (int i = 0; i < *total; i++)
        {
            fprintf(arquivo, "%s %d %s\n", professores[i].nome, professores[i].numero, professores[i].materia);
        }
        fclose(arquivo);
        printf("Professor removido com sucesso!\n");
    }
    else
    {
        printf("Professor não encontrado.\n");
    }
}

void excluirPedago(struct Pedago pedagogico[], int *total)
{
    int numeroExcluir;
    printf("Digite o número do membro da equipe que deseja excluir: ");
    scanf("%d", &numeroExcluir);

    int encontrado = 0;
    for (int i = 0; i < *total; i++)
    {
        if (pedagogico[i].numero == numeroExcluir)
        {
            encontrado = 1;
            for (int j = i; j < (*total) - 1; j++)
            {
                pedagogico[j] = pedagogico[j + 1]; // Desloca os alunos para preencher o espaço
            }
            (*total)--; // Reduz o total de alunos
            break;
        }
    }

    if (encontrado)
    {
        FILE *arquivo = fopen("pedago.txt", "w");
        if (arquivo == NULL)
        {
            printf("Erro ao abrir o arquivo para salvar!\n");
            return;
        }
        for (int i = 0; i < *total; i++)
        {
            fprintf(arquivo, "%s %d %s\n", pedagogico[i].nome, pedagogico[i].numero, pedagogico[i].cargo);
        }
        fclose(arquivo);
        printf("Membro removido com sucesso!\n");
    }
    else
    {
        printf("Membro não encontrado.\n");
    }
}
