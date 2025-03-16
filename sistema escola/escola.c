// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Arqivos
#include "Structs\structs.h"
#include "Func\Save\save.h"
#include "Func\Load\load.h"
#include "Func\Delete\delete.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    struct Aluno alunos[100];
    struct Professor professores[100];
    struct Pedago pedagogico[100];

    int opcao, opcaoAluno, opcaoProf, opcaoPeda, cadPeda = 0, cadAluno = 0, cadProf = 0;
    
    cadAluno = carregarAlunos(alunos);
    cadPeda = carregarPedago(pedagogico);
    cadProf = carregarProfs(professores);

    printf("selecione uma opção\n");
    printf("1 - Alunos\n");
    printf("2 - Professores\n");
    printf("3 - Pedago\n");
    printf("4 - Geral\n");
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
                int ra, existe = 0;

                printf("Digite o RA do aluno");
                scanf("%d", &ra);
                getchar();

                for (int i = 0; i < cadAluno; i++)
                {
                    if (alunos[i].numero == ra)
                    {
                        existe = 1;
                        break;
                    }
                }

                if (existe)
                {
                    printf("Ja existe um usuario com esse RA\n");
                }
                else
                {
                    alunos[cadAluno].numero = ra;

                    printf("Escreva o nome do aluno: ");
                    scanf("%[^\n]s", alunos[cadAluno].nome);
                    getchar();
                    fflush(stdin);

                    printf("Escreva a escolaridade do aluno: ");
                    scanf("%[^\n]s", alunos[cadAluno].escolaridade);
                    getchar();
                    fflush(stdin);

                    cadAluno++;

                    printf("Aluno adicionado com sucesso!\n");
                }
            }
            break;

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
                        scanf("%[^\n]s", alunos[i].nome);
                        fflush(stdin);

                        printf("Escreva a nova escolaridade do aluno: ");
                        scanf("%[^\n]s", alunos[i].escolaridade);
                        fflush(stdin);

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
                int ra, existe = 0;
                printf("Digite o RA do professor\n");
                scanf("%d", &ra);
                getchar();

                for (int i = 0; i < cadProf; i++)
                {
                    if (professores[i].numero == ra)
                    {
                        existe = 1;
                        break;
                    }
                }

                if (existe)
                {
                    printf("ja existe um professor com esse RA\n");
                    break;
                }
                else
                {

                    professores[cadProf].numero = ra;
                    printf("Escreva o nome do Professor: ");
                    scanf("%[^\n]s", professores[cadProf].nome);
                    getchar();
                    fflush(stdin);

                    printf("Escreva a materia do Professor: ");
                    scanf("%[^\n]s", professores[cadProf].materia);
                    getchar();
                    fflush(stdin);

                    cadProf++;

                    printf("Professor adicionado com sucesso!\n");
                    break;
                }
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
                        scanf("%[^\n]s", professores[i].nome);
                        fflush(stdin);

                        printf("Escreva a nova materia do professor: ");
                        scanf("%[^\n]s", professores[i].materia);
                        fflush(stdin);

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
                int ra, existe = 0;

                printf("Digite o RA do membro da equipe\n");
                scanf("%d", &ra);
                getchar();

                for (int i = 0; i < cadPeda; i++)
                {
                    if (pedagogico[i].numero == ra)
                    {
                        existe = 1;
                        break;
                    }
                }

                if (existe)
                {
                    printf("Já existe um membro com esse RA\n");
                    break;
                }
                else
                {

                    pedagogico[cadPeda].numero = ra;

                    printf("Escreva o nome do membro da equipe: ");
                    scanf("%[^\n]s", pedagogico[cadPeda].nome);
                    getchar();
                    fflush(stdin);

                    printf("Escreva o cargo do membro: ");
                    scanf("%[^\n]s", pedagogico[cadPeda].cargo);
                    getchar();
                    fflush(stdin);

                    cadPeda++;

                    printf("Membro adicionado com sucesso na equipe!\n");
                    break;
                }
            }

            case 2:
            {
                printf("Membros do Sistema\n");

                if (cadPeda == 0)
                {
                    printf("Nenhum membro cadastrado");
                }
                else
                {
                    for (int i = 0; i < cadPeda; i++)
                    {
                        printf("Nome: %s\n", pedagogico[i].nome);
                        printf("Cargo: %s\n", pedagogico[i].cargo);
                        printf("Número: %d\n", pedagogico[i].numero);
                        printf("-------------------------\n");
                    }
                    break;
                }
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
                        scanf("%[^\n]s", pedagogico[i].cargo);
                        fflush(stdin);

                        printf("Escreva o novo nome RA do membro: ");
                        scanf("%[^\n]s", pedagogico[i].nome);
                        fflush(stdin);

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
    case 4:
    //verifica se tem alunos cadastrados
        if (cadAluno == 0)
        {
            printf("Nenhum aluno cadastrado no sistema\n\n");
        }
        else
        {
            // Imprime os alunos
            printf("---Alunos do Sistema---\n\n");
            for (int i = 0; i < cadAluno; i++)
            {
                printf("Nome: %s\n", alunos[i].nome);
                printf("Escolaridade: %s\n", alunos[i].escolaridade);
                printf("Número: %d\n\n", alunos[i].numero);
                printf("----------------------\n");
                printf("\n");
            }
        }
        //verifica se tem professores cadastrados
        if (cadProf == 0)
        {
            printf("Nenhum Professor cadastrado no sistema\n\n");
        }
        else
        {
            // Imprime os professores
            printf("---Professores no Sistema---\n\n");
            for (int i = 0; i < cadProf; i++)
            {
                printf("Nome: %s\n", professores[i].nome);
                printf("Matéria: %s\n", professores[i].materia);
                printf("Número: %d\n\n", professores[i].numero);
                printf("----------------------\n");
                printf("\n");
            }
        }
        //verifica se tem membros cadastrados
        if (cadPeda == 0)
        {
            printf("Nenhum membro cadastrado no sistema\n\n");
        }
        else
        {
            // Imprime os membros pedagógicos
            printf("---Membros Pedagógicos no Sistema---\n\n");
            for (int i = 0; i < cadPeda; i++)
            {
                printf("Nome: %s\n", pedagogico[i].nome);
                printf("Cargo: %s\n", pedagogico[i].cargo);
                printf("Número: %d\n\n", pedagogico[i].numero);
                printf("----------------------\n");
                printf("\n");
            }
        }
        break;
    }
    return 0;
}