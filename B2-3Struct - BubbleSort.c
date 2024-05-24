#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 50

typedef struct {
  char nome[50];
  double nota;
} Aluno;

void incluirAluno(Aluno alunos[], int *contador);
void listarAlunos(Aluno alunos[], int contador);
void ordenarAlunosPorNome(Aluno alunos[], int contador);
void exibirMenu();

int main() {
  Aluno alunos[MAX_ALUNOS];
  int contador = 0;
  int opcao;

  do {
    exibirMenu();
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    getchar(); // Limpar buffer do teclado

    switch (opcao) {
    case 1:
      incluirAluno(alunos, &contador);
      break;
    case 2:
      listarAlunos(alunos, contador);
      break;
    case 3:
      printf("Encerrando o programa.\n");
      break;
    default:
      printf("Opcao invalida. Tente novamente.\n");
    }
  } while (opcao != 3);

  return 0;
}

void exibirMenu() {
  printf("\nMenu:\n");
  printf("1. Incluir aluno\n");
  printf("2. Listar alunos\n");
  printf("3. Sair\n");
}

void incluirAluno(Aluno alunos[], int *contador) {
  if (*contador < MAX_ALUNOS) {
    printf("Nome do aluno: ");
    fgets(alunos[*contador].nome, 50, stdin);
    alunos[*contador].nome[strcspn(alunos[*contador].nome, "\n")] =
        '\0'; // Remover nova linha

    printf("Nota do aluno: ");
    scanf("%lf", &alunos[*contador].nota);
    getchar(); // Limpar buffer do teclado

    (*contador)++;
  } else {
    printf("Capacidade maxima de alunos atingida.\n");
  }
}

void listarAlunos(Aluno alunos[], int contador) {
  if (contador == 0) {
    printf("Nenhum aluno cadastrado.\n");
    return;
  }

  ordenarAlunosPorNome(alunos, contador);

  printf("\nLista de alunos:\n");
  for (int i = 0; i < contador; i++) {
    printf("Nome: %s, Nota: %.2f, Situacao: %s\n", alunos[i].nome,
           alunos[i].nota, alunos[i].nota >= 6.00 ? "Aprovado" : "Reprovado");
  }
}

void ordenarAlunosPorNome(Aluno alunos[], int contador) {
  for (int i = 0; i < contador - 1; i++) {
    for (int j = 0; j < contador - i - 1; j++) {
      if (strcmp(alunos[j].nome, alunos[j + 1].nome) > 0) {
        Aluno temp = alunos[j];
        alunos[j] = alunos[j + 1];
        alunos[j + 1] = temp;
      }
    }
  }
}