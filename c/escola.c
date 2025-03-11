// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Aluno
{
    char nome[100];
    char escolaridade[50];
    int numero;
};

struct Professor
{
    char nome[100];
    char materia[50];
    int numero;
};

struct Pedago
{
    char nome[100];
    char cargo[150];
    int numero;
};

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
        fprintf(arquivo, "%s %d %s\n", alunos[i].nome, alunos[i].numero, alunos[i].escolaridade);
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
        fprintf(arquivo, "%s %d %s\n", pedagogico[i].nome, pedagogico[i].numero, pedagogico[i].cargo);
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
        fprintf(arquivo, "%s %d %s\n", professores[i].nome, professores[i].numero, professores[i].materia);
    }
    fclose(arquivo);
}

// CARREGA OS ALUNOS SALVOS DO .TXT
int carregarAlunos(struct Aluno alunos[])
{
    FILE *arquivo = fopen("alunos.txt", "r");
    if (arquivo == NULL)
    {
        return 0; // Nenhum dado salvo ainda
    }
    int i = 0;
    while (fscanf(arquivo, "%s %d %s", alunos[i].nome, &alunos[i].numero, alunos[i].escolaridade) != EOF)
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
    while (fscanf(arquivo, "%s %d %s", pedagogico[i].nome, &pedagogico[i].numero, pedagogico[i].cargo) != EOF)
    {
        i++;
    }
    fclose(arquivo);
    return i; // Retorna o número de alunos carregados
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
    while (fscanf(arquivo, "%s %d %s", professores[i].nome, &professores[i].numero, professores[i].materia) != EOF)
    {
        i++;
    }
    fclose(arquivo);
    return i; // Retorna o número de alunos carregados
}

// FUNÇÕES PARA EXCLUIR ALUNOS, PROFESSORES E PEDAGOGICO
void excluirAluno(struct Aluno alunos[], int *total)
{
    int numeroExcluir;
    printf("Digite o número do aluno que deseja excluir: ");
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

int main()
{

    struct Aluno alunos[100];
    struct Professor professores[100];
    struct Pedago pedagogico[100];

    int opcao, opcaoAluno, opcaoProf, opcaoPeda, cadPeda = 0, cadAluno = 0, cadProf = 0;
    setlocale(LC_ALL, "Portuguese");

    cadAluno = carregarAlunos(alunos);
    cadPeda = carregarPedago(pedagogico);
    cadProf = carregarProfs(professores);

    printf("selecione uma opção\n");
    printf("1 - Alunos\n");
    printf("2 - Professores\n");
    printf("3 - Pedago\n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        do
        {
            printf("Selecione uma opção\n");
            printf("1 - Adicionar Aluno\n");
            printf("2 - Visualizar Alunos\n");
            printf("3 - Editar Alunos\n");
            printf("4 - Excluir Alunos\n");
            printf("5 - Voltar\n");
            printf("6 - Sair\n");

            scanf("%d", &opcaoAluno);

            switch (opcaoAluno)
            {
            case 1:
            {
                printf("Escreva o nome do aluno: ");
                scanf("%s", alunos[cadAluno].nome);
                getchar();

                printf("Escreva o número RA do aluno: ");
                scanf("%d", &alunos[cadAluno].numero);
                getchar();

                printf("Escreva a escolaridade do aluno: ");
                scanf("%s", alunos[cadAluno].escolaridade);
                getchar();

                cadAluno++;

                printf("Aluno adicionado com sucesso!\n");
                break;
            }

            case 2:
            {
                printf("Alunos do Sistema\n");
                if (cadAluno == 0)
                {
                    printf("Nnehum aluno encontrado");
                }
                else
                {
                    for (int i = 0; i < cadAluno; i++)
                    {
                        printf("Nome: %s\n", alunos[i].nome);
                        printf("Número: %d\n", alunos[i].numero);
                        printf("Escolaridade: %s\n", alunos[i].escolaridade);
                        printf("-------------------------\n");
                    }
                    break;
                }
            }

            case 3:
            {
                if (cadAluno == 0)
                {
                    printf("Nenhum aluno cadastrado para editar\n");
                    break;
                }

                int numero;

                printf("Escreva RA do aluno que deseja editar: ");
                scanf("%d", &numero);

                int encontrado = 0;

                for (int i = 0; i < cadAluno; i++)
                {
                    if (alunos[i].numero == numero)
                    {
                        printf("Escreva o novo RA do aluno: ");
                        scanf("%d", &alunos[i].numero);

                        printf("Escreva o novo nome do aluno: ");
                        scanf("%s", alunos[i].nome);

                        printf("Escreva a nova escolaridade do aluno: ");
                        scanf("%s", alunos[i].escolaridade);

                        printf("Aluno editado com sucesso.\n");
                        encontrado = 1;
                        break;
                    }
                }

                if (!encontrado)
                {
                    printf("Aluno não encontrado\n");
                }
                break;
            }

            case 4:
            {
                excluirAluno(alunos, &cadAluno);
                break;
            }

            case 5:
            {
                printf("Voltando ao inicio...\n");
                return main();
                break;
            }

            case 6:
                salvarAlunos(alunos, cadAluno);
                printf("Encerrando sistema\n");
                break;
            default:
                printf("Opção inválida\n");
                break;
            }
        } while (opcaoAluno != 6);
        break;

    case 2:
    {
        do
        {
            printf("Selecione uma opção\n");
            printf("1 - Adicionar Professor\n");
            printf("2 - Visualizar Professores\n");
            printf("3 - Editar Professores\n");
            printf("4 - Excluir Professores\n");
            printf("5 - Voltar\n");
            printf("6 - Sair\n");

            scanf("%d", &opcaoProf);

            switch (opcaoProf)
            {
            case 1:
            {
                printf("Escreva o nome do Professor: ");
                scanf("%s", professores[cadProf].nome);
                getchar();

                printf("Escreva o número RA do professor: ");
                scanf("%d", &professores[cadProf].numero);
                getchar();

                printf("Escreva a materia do Professor: ");
                scanf("%s", professores[cadProf].materia);
                getchar();

                cadProf++;

                printf("Professor adicionado com sucesso!\n");
                break;
            }
            case 2:
            {
                if (cadProf == 0)
                {
                    printf("Nenhum professor encontrado\n");
                }
                else
                {
                    printf("Professores do Sistema\n");
                    for (int i = 0; i < cadProf; i++)
                    {
                        printf("Nome: %s\n", professores[i].nome);
                        printf("Número: %d\n", professores[i].numero);
                        printf("Materia: %s\n", professores[i].materia);
                        printf("-------------------------\n");
                    }
                    break;
                }
            }
            case 3:
            {
                if (cadProf == 0)
                {
                    printf("Nenhum professor cadastrado para editar\n");
                    break;
                }
                int numero;

                printf("Escreva o RA do professor que deseja editar: ");
                scanf("%d", &numero);

                int encontrado = 0;

                for (int i = 0; i < cadProf; i++)
                {
                    if (professores[i].numero == numero)
                    {
                        printf("Escreva o novo RA do professor: ");
                        scanf("%d", &professores[i].numero);

                        printf("Escreva o novo nome do professor: ");
                        scanf("%s", professores[i].nome);

                        printf("Escreva a nova materia do professor: ");
                        scanf("%s", professores[i].materia);

                        printf("Professor editado com sucesso.\n");
                        encontrado = 1;
                        break;
                    }
                }

                if (!encontrado)
                {
                    printf("Professor não encontrado\n");
                }

                break;
            }

            case 4:
            {
                excluirProf(professores, &cadProf);
                break;
            }

            case 5:
            {
                printf("Voltando ao inicio...\n");
                return main();
                break;
            }

            case 6:
                salvarProfs(professores, cadProf);
                printf("Encerrando sistema\n");
                break;
            default:
                printf("Opção inválida\n");
                break;
            }
        } while (opcaoProf != 6);
        break;
    }
    case 3:
    {
        do
        {
            printf("Selecione uma opção\n");
            printf("1 - Adicionar Equipe Pedagogica\n");
            printf("2 - Visualizar Equipe\n");
            printf("3 - Editar Equipe\n");
            printf("4 - Excluir Membro\n");
            printf("5 - Voltar\n");
            printf("6 - Sair\n");

            scanf("%d", &opcaoPeda);

            switch (opcaoPeda)
            {
            case 1:
            {
                printf("Escreva o nome do membro da equipe: ");
                scanf("%s", pedagogico[cadPeda].nome);
                getchar();

                printf("Escreva o cargo do membro: ");
                scanf("%s", pedagogico[cadPeda].cargo);
                getchar();

                printf("Escreva o numero do RA do membro: ");
                scanf("%d", &pedagogico[cadPeda].numero);
                getchar();

                cadPeda++;

                printf("Membro adicionado com sucesso na equipe!\n");
                break;
            }

            case 2:
            {
                printf("Membros do Sistema\n");
                for (int i = 0; i < cadPeda; i++)
                {
                    printf("Nome: %s\n", pedagogico[i].nome);
                    printf("Cargo: %s\n", pedagogico[i].cargo);
                    printf("Número: %d\n", pedagogico[i].numero);
                    printf("-------------------------\n");
                }
                break;
            }

            case 3:
            {
                if (cadPeda == 0)
                {
                    printf("Nenhum membro cadastrado para editar\n");
                    break;
                }

                int numero;

                printf("Escreva o RA do membro que deseja editar: ");
                scanf("%d", &numero);

                int encontrado = 0;

                for (int i = 0; i < cadPeda; i++)
                {
                    if (pedagogico[i].numero == numero)
                    {
                        printf("Escreva o novo RA do membro: ");
                        scanf("%d", &pedagogico[i].numero);

                        printf("Escreva o novo cargo do membro: ");
                        scanf("%s", pedagogico[i].cargo);

                        printf("Escreva o novo nome RA do membro: ");
                        scanf("%s", pedagogico[i].nome);

                        printf("Membro editado com sucesso.\n");
                        encontrado = 1;
                        break;
                    }
                }

                if (!encontrado)
                {
                    printf("Membro não encontrado\n");
                }
                break;
            }

            case 4:
            {
                excluirPedago(pedagogico, &cadPeda);
                break;
            }

            case 5:
            {
                printf("Voltando ao inicio...\n");
                return main();
                break;
            }

            case 6:
                salvarPedago(pedagogico, cadPeda);
                printf("Encerrando sistema\n");
                break;
            default:
                printf("Opção inválida\n");
                break;
            }
        } while (opcaoPeda != 6);
        break;
    }
    }
    return 0;
}
