#include <stdio.h>
#include "../../Structs/structs.h"


// SALVAR ALUNOS EM UM ARQUIVO .TXT
void salvarAlunos(struct Aluno alunos[], int total)
{
    FILE *arquivo = fopen("alunos.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para salvar!\n");
        return;
    }
    for (int i = 0; i < total; i++)
    {
        fprintf(arquivo, "\"%s\" %d \"%s\"\n", alunos[i].nome, alunos[i].numero, alunos[i].escolaridade);
    }
    fclose(arquivo);
}

// SALVAR PEDAGOGICO EM UM ARQUIVO .TXT
void salvarPedago(struct Pedago pedagogico[], int total)
{
    FILE *arquivo = fopen("pedago.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para salvar!\n");
        return;
    }
    for (int i = 0; i < total; i++)
    {
        fprintf(arquivo, "\"%s\" %d \"%s\"\n", pedagogico[i].nome, pedagogico[i].numero, pedagogico[i].cargo);
    }
    fclose(arquivo);
}

// SALVAR PROFESSORES EM UM ARQUIVO .TXT
void salvarProfs(struct Professor professores[], int total)
{
    FILE *arquivo = fopen("profs.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para salvar!\n");
        return;
    }
    for (int i = 0; i < total; i++)
    {
        fprintf(arquivo, "\"%s\" %d \"%s\"\n", professores[i].nome, professores[i].numero, professores[i].materia);
    }
    fclose(arquivo);
}

 