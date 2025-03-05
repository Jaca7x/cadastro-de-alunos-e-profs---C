// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Aluno {
    char nome[100];
    char escolaridade[50];
    float numero;
};

struct Professor {
    char nome[100];
    char materia[50];
    float numero;
};

int main() {
    struct Aluno alunos[100]; 
    struct Professor professores[100];
    int opcao, opcaoAluno, opcaoProf, cadAluno = 0, cadProf = 0;
    setlocale(LC_ALL, "Portuguese");

    printf("selecione uma opção\n");
    printf("1 - Alunos\n");
    printf("2 - Professores\n");
    scanf("%d", &opcao);
    
switch (opcao)
{
case 1:
do {
    printf("Selecione uma opção\n");
    printf("1 - Adicionar Aluno\n");
    printf("2 - Visualizar Alunos\n");
    printf("3 - Editar Alunos\n");
    printf("4 - Sair\n");

    scanf("%d", &opcaoAluno);

    switch (opcaoAluno) {
        case 1: {
            printf("Escreva o nome do aluno: ");
            scanf("%s", alunos[cadAluno].nome);
            getchar();

            printf("Escreva o número do aluno: ");
            scanf("%f", &alunos[cadAluno].numero);
            getchar();

            printf("Escreva a escolaridade do aluno: ");
            scanf("%s", alunos[cadAluno].escolaridade);
            getchar();

            cadAluno++;

            printf("Aluno adicionado com sucesso!\n");
            break;
        }

        case 2: {
            printf("Alunos do Sistema\n");
            for (int i = 0; i < cadAluno; i++) {
                printf("Nome: %s\n", alunos[i].nome);
                printf("Número: %.2f\n", alunos[i].numero);
                printf("Escolaridade: %s\n", alunos[i].escolaridade);
                printf("-------------------------\n");
            }
            break;
        }

        case 3: {
            if (cadAluno == 0) {
                printf("Nenhum aluno cadastrado para editar\n");
                break;
            }

            char nome[100];

            printf("Escreva o nome do aluno que deseja editar: ");
            scanf("%s", nome);

            int encontrado = 0;

            for (int i = 0; i < cadAluno; i++) {
                if (strcmp(alunos[i].nome, nome) == 0) {
                    printf("Escreva o novo nome do aluno: ");
                    scanf("%s", alunos[i].nome);

                    printf("Escreva o novo númmero do aluno: ");
                    scanf("%f", &alunos[i].numero);

                    printf("Escreva a nova escolaridade do aluno: ");
                    scanf("%s", alunos[i].escolaridade);

                    printf("Aluno editado com sucesso.\n");
                    encontrado = 1;
                    break;
                }
            }

            if (!encontrado) {
                printf("Aluno não encontrado\n");
            }

            break; 
        }

        case 4: 
            printf("Encerrando sistema\n");
            break;
        default:
            printf("Opção inválida\n");
            break;
    }
} while (opcaoAluno != 4);

    case 2: {
        do {
            printf("Selecione uma opção\n");
            printf("1 - Adicionar Professor\n");
            printf("2 - Visualizar Professores\n");
            printf("3 - Editar Professores\n");
            printf("4 - Sair\n");
        
            scanf("%d", &opcaoProf);
        
            switch (opcaoProf) {
                case 1: {
                    printf("Escreva o nome do Professor: ");
                    scanf("%s", professores[cadProf].nome);
                    getchar();
        
                    printf("Escreva o nÃºmero do aluno: ");
                    scanf("%f", &professores[cadProf].numero);
                    getchar();
        
                    printf("Escreva a escolaridade do aluno: ");
                    scanf("%s", professores[cadProf].materia);
                    getchar();
        
                    cadProf++;
        
                    printf("Professor adicionado com sucesso!\n");
                    break;
                }
        
                case 2: {
                    printf("Professores do Sistema\n");
                    for (int i = 0; i < cadProf; i++) {
                        printf("Nome: %s\n", professores[i].nome);
                        printf("Número: %.2f\n", professores[i].numero);
                        printf("Materia: %s\n", professores[i].materia);
                        printf("-------------------------\n");
                    }
                    break;
                }
        
                case 3: {
                    if (cadProf == 0) {
                        printf("Nenhum professor cadastrado para editar\n");
                        break;
                    }
        
                    char nome[100];
        
                    printf("Escreva o nome do professor que deseja editar: ");
                    scanf("%s", nome);
        
                    int encontrado = 0;
        
                    for (int i = 0; i < cadProf; i++) {
                        if (strcmp( professores[i].nome, nome) == 0) {
                            printf("Escreva o novo nome do professor: ");
                            scanf("%s", professores[i].nome);
        
                            printf("Escreva o novo númmero do professor: ");
                            scanf("%f", &professores[i].numero);
        
                            printf("Escreva a nova materia do professor: ");
                            scanf("%s", professores[i].materia);
        
                            printf("Aluno editado com sucesso.\n");
                            encontrado = 1;
                            break;
                        }
                    }
        
                    if (!encontrado) {
                        printf("Professor não encontrado\n");
                    }
        
                    break; 
                }
        
                case 4: 
                    printf("Encerrando sistema\n");
                    break;
                default:
                    printf("Opção inválida\n");
                    break;
            }
        } while (opcaoProf != 4);
        break;
    }
    
   
} 
}




