#include <stdio.h>
#include "../../Structs\structs.h"

// CARREGA OS ALUNOS SALVOS DO .TXT
int carregarAlunos(struct Aluno alunos[])
{
    FILE *arquivo = fopen("alunos.txt", "r");
    if (arquivo == NULL)
    {
        return 0; // Nenhum dado salvo ainda
    }
    int i = 0;
    while (fscanf(arquivo, " \"%[^\"]\" %d \"%[^\"]\" ", alunos[i].nome, &alunos[i].numero, alunos[i].escolaridade) != EOF)
    {
        i++;
    }
    fclose(arquivo);
    return i; // Retorna o número de alunos carregados
}

// CARREGA A EQUIPE PEDAGÓGICA SALVA DO .TXT
int carregarPedago(struct Pedago pedagogico[])
{
    FILE *arquivo = fopen("pedago.txt", "r");
    if (arquivo == NULL)
    {
        return 0; // Nenhum dado salvo ainda
    }
    int i = 0;
    while (fscanf(arquivo, " \"%[^\"]\" %d \"%[^\"]\" ", pedagogico[i].nome, &pedagogico[i].numero, pedagogico[i].cargo) != EOF)
    {
        i++;
    }
    fclose(arquivo);
    return i; // Retorna o número de pedagogos carregados
}

// CARREGA OS PROFESSORES SALVOS DO .TXT
int carregarProfs(struct Professor professores[])
{
    FILE *arquivo = fopen("profs.txt", "r");
    if (arquivo == NULL)
    {
        return 0; // Nenhum dado salvo ainda
    }
    int i = 0;
    while (fscanf(arquivo, " \"%[^\"]\" %d \"%[^\"]\" ", professores[i].nome, &professores[i].numero, professores[i].materia) != EOF)
    {
        i++;
    }
    fclose(arquivo);
    return i; // Retorna o número de professores carregados
}
