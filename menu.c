#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "menu.h"

int menuGeral()
{
  int opcao;
  printf("\nProjeto Escola\n");
  printf("1 - Aluno\n");
  printf("2 - Professor\n");
  printf("3 - Disciplina\n");
  printf("4 - Relatórios\n");
  printf("0 - Sair\n");
  
  scanf("%d", &opcao);
  getchar();

  return opcao;
}

int menuPessoa(int opcao)
{
  int opcaoPessoa;
  char pessoa[12] = {"Pessoas"};
  
  switch(opcao)
  {
  case 1: strcpy(pessoa, "Alunos"); break;
  case 2: strcpy(pessoa, "Professores"); break;
  default: printf("Opção inválida"); break;
  }

  printf("\n1 - Listar %s\n", pessoa);
  printf("2 - Cadastrar %s\n", pessoa);
  printf("3 - Atualizar %s\n", pessoa);
  printf("4 - Remover %s\n", pessoa);
  printf("0 - Voltar\n");

  scanf("%d", &opcaoPessoa);
  getchar();

  return opcaoPessoa;
}

int menuDisciplina()
{
  int opcaoDisc;
  printf("\n1 - Listar Disciplinas\n");
  printf("2 - Cadastrar Disciplina\n");
  printf("3 - Remover Disciplina\n");
  printf("4 - Inserir Aluno\n");
  printf("5 - Remover Aluno\n");
  printf("0 - Voltar\n");

  scanf("%d", &opcaoDisc);
  getchar();

  return opcaoDisc;
}

int menuAtualizarPessoa()
{
  int opcaoAtualizar;
  printf("\n1 - Atualizar nome\n");
  printf("2 - Atualizar sexo\n");
  printf("3 - Atualizar data de nascimento\n");
  printf("4 - Atualizar cpf\n");
  printf("0 - Cancelar\n");

  scanf("%d", &opcaoAtualizar);
  getchar();

  return opcaoAtualizar;
}

int menuRelatorios()
{
  int opcaoRelatorio;
  printf("\n1 - Listar Alunos/Professores\n");
  printf("2 - Listar Disciplinas\n");
  printf("3 - Detalhar Disciplina\n");
  printf("4 - Listar Alunos/Professores por sexo\n");
  printf("5 - Listar Alunos/Professores em ordem alfabética\n");
  printf("6 - Listar Alunos/Professores por data de nascimento\n");
  printf("11 - Aniversariantes do mês\n");
  printf("12 - Listar pessoas por busca do nome\n");
  printf("13 - Listar Alunos matriculados em menos de 3 disciplinas\n");
  printf("14 - Listar Disciplinas com mais de 40 vagas\n");
  printf("0 - Voltar\n");

  scanf("%d", &opcaoRelatorio);
  getchar();

  return opcaoRelatorio;
}