#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int id;
  char nome[50];
  char descricao[100];
  float preco;
  int quantidade;
} Produto;

void inserirProduto(Produto **produtos, int *numProdutos);
void listarProdutos(Produto *produtos, int numProdutos);
void comprarProduto(Produto *produtos, int numProdutos);
void ordenarProdutos(Produto *produtos, int numProdutos);

int main() {
  Produto *produtos = NULL;
  int numProdutos = 0;
  int opcao;

  do {
    printf("\nMenu:\n");
    printf("1. Inserir Produto\n");
    printf("2. Listar Produtos\n");
    printf("3. Comprar Produto\n");
    printf("4. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    getchar();  // Limpar o buffer do teclado

      switch (opcao) {
        case 1:
          inserirProduto(&produtos, &numProdutos);
          break;
        case 2:
          listarProdutos(produtos, numProdutos);
          break;
        case 3:
          comprarProduto(produtos, numProdutos);
          break;
        case 4:
          printf("Saindo...\n");
          break;
        default:
          printf("Opcao invalida!\n");
      }
  } while (opcao != 4);

  free(produtos);
  return 0;
}

void inserirProduto(Produto **produtos, int *numProdutos) {
  *produtos = realloc(*produtos, (*numProdutos + 1) * sizeof(Produto));

  Produto *novoProduto = &(*produtos)[*numProdutos];

  printf("Digite o ID do produto: ");
  scanf("%d", &novoProduto->id);
  getchar();  // Limpar o buffer do teclado
  printf("Digite o nome do produto: ");
  fgets(novoProduto->nome, sizeof(novoProduto->nome), stdin);
  novoProduto->nome[strcspn(novoProduto->nome, "\n")] = '\0';  // Remover nova linha
  printf("Digite a descricao do produto: ");
  fgets(novoProduto->descricao, sizeof(novoProduto->descricao), stdin);
  novoProduto->descricao[strcspn(novoProduto->descricao, "\n")] = '\0';
  printf("Digite o preco do produto: ");
  scanf("%f", &novoProduto->preco);
  printf("Digite a quantidade em estoque: ");
  scanf("%d", &novoProduto->quantidade);

  (*numProdutos)++;
}

void listarProdutos(Produto *produtos, int numProdutos) {
  ordenarProdutos(produtos, numProdutos);

  printf("\nLista de Produtos:\n");
  for (int i = 0; i < numProdutos; i++) {
    printf("ID: %d\n", produtos[i].id);
    printf("Nome: %s\n", produtos[i].nome);
    printf("Descricao: %s\n", produtos[i].descricao);
    printf("Preco: %.2f\n", produtos[i].preco);
    printf("Quantidade: %d\n", produtos[i].quantidade);
    printf("\n");
  }
}

void comprarProduto(Produto *produtos, int numProdutos) {
  int id, quantidade;
  printf("Digite o ID do produto que deseja comprar: ");
  scanf("%d", &id);

  Produto *produto = NULL;
  for (int i = 0; i < numProdutos; i++) {
    if (produtos[i].id == id) {
      produto = &produtos[i];
    break;
    }
  }

  if (produto == NULL) {
    printf("Produto Inexistente.\n");
  return;
  }

  printf("Digite a quantidade que deseja comprar: ");
  scanf("%d", &quantidade);

  if (quantidade > produto->quantidade) {
    printf("Estoque insuficiente.\n");
  }else {
     produto->quantidade -= quantidade;
     printf("Compra realizada com sucesso.\n");
   }
}

void ordenarProdutos(Produto *produtos, int numProdutos) {
  for (int i = 0; i < numProdutos - 1; i++) {
    for (int j = 0; j < numProdutos - i - 1; j++) {
      if (strcmp(produtos[j].nome, produtos[j + 1].nome) > 0) {
        Produto temp = produtos[j];
        produtos[j] = produtos[j + 1];
        produtos[j + 1] = temp;
      }
    }
  }
}