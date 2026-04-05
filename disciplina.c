#include "disciplina.h"
#include <stdio.h>
#include <string.h>

bool cadastrarDisciplina(Disciplina lista[], Pessoa listaProfessor[], int qtdProf, int qtd, int cod)
{ 
  char nome[25];
  bool nomeValido = false;
  int tamNome;
  int semestre;
  bool semestreValido = false;
  int totalVagas;
  bool totalVagasValido = false;
  int matriculaProf;
  bool profEncontrado = false;
  Pessoa professor;

  if(qtd == TAM_DISC)
  {
    printf("Lista de disciplinas já está cheia.\n");
    return false;
  }
 
  while(!nomeValido)
  {
    printf("Digite o nome do disciplina (pelo menos 3 letras) ou '0' para cancelar cadastro: ");
    fgets(nome, 25, stdin);

    nome[strcspn(nome, "\n")] = '\0';

    if(strcmp(nome, "0") == 0)
      return false;

    tamNome = strlen(nome); 

    if(tamNome < 3 || tamNome > 25)
      printf("Tamanho do nome inválido\n");
    else    
      nomeValido = true;  
  }

  while(!semestreValido)
  {
    printf("Digite o semestre da disciplina (mínimo: 1, máximo: 8) ou '0' para cancelar cadastro: ");
    scanf("%d", &semestre);

    if(semestre == 0)
      return false;

    if(semestre < 0 || semestre > 8)    
      printf("Número inválido para o semestre\n");
    else
      semestreValido = true;
  }

  while(!totalVagasValido)
  {
    printf("Digite a quantidade de vagas para a disciplina (mínimo: 5, máximo: 60) ou '0' para cancelar cadastro: ");
    scanf("%d", &totalVagas);

    if(totalVagas == 0)
      return false;
  
    if(totalVagas < 5 || totalVagas > 60)    
      printf("Número inválido para a quantidade de vagas\n");
    else      
      totalVagasValido = true;
  }

  while(!profEncontrado)
  {
    printf("Digite a matricula do professor da disciplina ou '0' para cancelar cadastro: ");
    scanf("%d", &matriculaProf);

    if(matriculaProf == 0)
      return false;

    for(int i = 0; i < qtdProf; i++)
    {
      if(matriculaProf == listaProfessor[i].matricula)
      {
        profEncontrado = true;
        professor = listaProfessor[i];
        break;
      }
    }

    if(!profEncontrado)    
      printf("Não foi possível encontrar um professor com esta matrícula\n");
  }
  
  lista[qtd].cod = cod;
  lista[qtd].ativo = true;
  strcpy(lista[qtd].nome, nome);  
  lista[qtd].semestre = semestre;
  lista[qtd].totalVagas = totalVagas;
  lista[qtd].professor = professor;
  for(int i = 0; i < qtdProf; i++)
    if(listaProfessor[i].matricula == matriculaProf)
    {
      listaProfessor[i].qtdDisciplinas++;
      break;
    }
  lista[qtd].qtdAlunosMatriculados = 0;
  for(int i = 0; i < MAX_ALUNOS; i++)
    lista[qtd].matriculaAlunos[i] = 0;

  return true;
}

void imprimirDisciplina(Disciplina disc)
{
  printf("\nNome: %s\n", disc.nome);
  printf("Código: %d\n", disc.cod);
  printf("Semestre: %dº\n", disc.semestre);
  printf("Total de vagas: %d\n", disc.totalVagas);
  printf("Total de alunos matriculados: %d\n", disc.qtdAlunosMatriculados);
  printf("Vagas Restantes: %d\n", disc.totalVagas - disc.qtdAlunosMatriculados);
  printf("Professor: %s\n", disc.professor.nome);
}

void listarDisciplinas(Disciplina lista[], int qtd)
{  
  for(int i = 0; i < qtd; i++)
  { 
    if(lista[i].ativo)   
    {                  
      imprimirDisciplina(lista[i]);
      printf("-------------------\n");
    }
  }
}

bool removerDisciplina(Disciplina lista[], Pessoa listaProfessor[], int qtd, int qtdProf, bool encontrado, int codDisciplina)
{  
  for(int i = 0; i < qtd; i++)
  {
    if(codDisciplina == lista[i].cod && lista[i].ativo)
    {
      encontrado = true;
      lista[i].ativo = false;
        
      for(int j = i; j < qtd - 1; j++)
        lista[j] = lista[j + 1];

      for(int j = 0; j < qtdProf; j++)
        if(listaProfessor[j].matricula == lista[i].professor.matricula)
        {
          listaProfessor[j].qtdDisciplinas--;
          break;
        }

      break;
    }                
  }
  return encontrado ? true : false;
}

bool inserirAlunoNaDisciplina(Disciplina lista[], Pessoa listaAluno[], int qtdAluno, int qtd, bool encontrado, int codDisciplina)
{
  int matriculaAluno;
  int posicao;
        
  for(int i = 0; i < qtd; i++)
  {
    if(codDisciplina == lista[i].cod && lista[i].ativo)
    {
      encontrado = true;

      if(lista[i].qtdAlunosMatriculados >= lista[i].totalVagas)
      {
        printf("A disciplina já está cheia\n");
        return false;
      }

      printf("Digite a matrícula do aluno que deseja inserir na disciplina: ");
      scanf("%d", &matriculaAluno);
      
      bool alunoEncontrado = false;

      for(int j = 0; j < qtdAluno; j++)
      {
        if(matriculaAluno == listaAluno[j].matricula)
        {
          alunoEncontrado = true;
          break;
        }
      }

      if(!alunoEncontrado)
      {
        printf("Nenhum aluno com esta matricula\n");
        return false;
      }

      for(int k = 0; k < lista[i].qtdAlunosMatriculados; k++)
      {
        if(lista[i].matriculaAlunos[k] == matriculaAluno)
        {
          printf("Aluno já está matriculado na disciplina\n");
          return false;
        }
      }
      
      posicao = lista[i].qtdAlunosMatriculados;
      lista[i].matriculaAlunos[posicao] = matriculaAluno;
      lista[i].qtdAlunosMatriculados++;
      for(int i = 0; i < qtdAluno; i++)
        if(listaAluno[i].matricula == matriculaAluno)
        {
          listaAluno[i].qtdDisciplinas++;
          break;
        }
      break;
    }
  }

  if(!encontrado)  
    printf("Código de disciplina inválido\n");

  return encontrado ? true : false;
}


bool removerAlunoDaDisciplina(Disciplina lista[], Pessoa listaAluno[], int qtd, int qtdAluno, bool encontrado, int codDisciplina)
{
  int matriculaAluno;
  int posicao;

  for(int i = 0; i < qtd; i++)
  {
    if(codDisciplina == lista[i].cod && lista[i].ativo)
    {
      encontrado = true;

      printf("Digite a matrícula do aluno que deseja remover da disciplina: ");
      scanf("%d", &matriculaAluno);
      
      bool alunoEncontrado = false;

      for(int j = 0; j < lista[i].qtdAlunosMatriculados; j++)
      {
        if(matriculaAluno == lista[i].matriculaAlunos[j])
        {
          alunoEncontrado = true;
          posicao = j;
          break;
        }
      }

      if(!alunoEncontrado)
      {
        printf("Nenhum aluno com esta matricula está matriculado na disciplina\n");
        return false;
      }

      lista[i].matriculaAlunos[posicao] = 0;

      for(int j = posicao; j < lista[i].qtdAlunosMatriculados - 1; j++)
        lista[j] = lista[j + 1];

      lista[i].qtdAlunosMatriculados--;
      
      for(int j = 0; j < qtdAluno; j++)
        if(listaAluno[j].matricula == matriculaAluno)
        {
          listaAluno[j].qtdDisciplinas--;
          break;
        }

      break;
    }
  }

  if(!encontrado)  
    printf("Código de disciplina inválido\n");

  return encontrado ? true : false;
}