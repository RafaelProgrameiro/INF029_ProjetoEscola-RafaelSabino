#include "relatorio.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>

bool detalharDisciplina(Disciplina lista[], Pessoa listaAluno[], int qtdAluno, int qtdDisc, bool encontrado, int codDisciplina)
{
  for(int i = 0; i < qtdDisc; i++)
  {
    if(codDisciplina == lista[i].cod && lista[i].ativo)
    {
      encontrado = true;
      int matriculaAluno;
      imprimirDisciplina(lista[i]);
      printf("Alunos matriculados:\n");

      if(lista[i].qtdAlunosMatriculados == 0)
        printf("Nenhum aluno cadastrado na disciplina\n");

      for(int j = 0; j < lista[i].qtdAlunosMatriculados; j++)
      {
        matriculaAluno = lista[i].matriculaAlunos[j];

        for(int k = 0; k < qtdAluno; k++)
        {
          if(matriculaAluno == listaAluno[k].matricula && listaAluno[k].ativo)
            printf("Matricula: %d - Nome: %s", listaAluno[k].matricula, listaAluno[k].nome);
        }
      }    
      printf("-------------------\n");
      break;
    }
  }

  return encontrado ? true : false;
}

void listarPessoasPorSexo(Pessoa lista[], int qtd, char sexo)
{
  printf("\nListar por sexo\n");

  for(int i = 0; i < qtd; i++)
  {
    if(lista[i].ativo && lista[i].sexo == sexo)
    {
      imprimirPessoa(lista[i]);
    }
  }
}

void listarPessoasPorOrdemAlfabetica(Pessoa lista[], int qtd)
{
  printf("\nListar por ordem alfabetica\n");

  Pessoa pessoasOrdenada[TAM_ALUNO];

  for(int i = 0; i < qtd; i++)
    pessoasOrdenada[i]= lista[i];

  ordenarPessoasPorNome(pessoasOrdenada, qtd);
  listarPessoas(pessoasOrdenada, qtd);
}

void listarPessoasPorDataNascimento(Pessoa lista[], int qtd)
{
  printf("\nListar por data de nascimento\n");

  Pessoa pessoasOrdenada[TAM_ALUNO];

  for(int i = 0; i < qtd; i++)
    pessoasOrdenada[i]= lista[i];

  ordenarPessoasPorDataNacimento(pessoasOrdenada, qtd);
  listarPessoas(pessoasOrdenada, qtd);
}

void listarAniversariantesDoMes(Pessoa listaAluno[], Pessoa listaProf[], int qtdAluno, int qtdProf, int mes)
{
  bool encontrou = false;

  printf("Alunos: \n");
  if(qtdAluno == 0)              
    printf("Lista de alunos está vazia.\n");
  else
  {
    for(int i = 0; i < qtdAluno; i++)
    {
      if(listaAluno[i].ativo && listaAluno[i].dataNascimento.mes == mes)
      {
        encontrou = true;
        imprimirPessoa(listaAluno[i]);
      }
    }
  }
  if (!encontrou)
    printf("Nenhum aluno faz aniversário neste mês\n");

  encontrou = false;

  printf("Professores: \n");    
  if(qtdProf == 0)  
    printf("Lista de professores está vazia.\n");
  else
  {
    for(int i = 0; i < qtdProf; i++)
    {
      if(listaProf[i].ativo && listaProf[i].dataNascimento.mes == mes)
      {
        encontrou = true;
        imprimirPessoa(listaProf[i]);
      }
    }
  }
  if (!encontrou)
    printf("Nenhum professor faz aniversário neste mês\n");
}

void buscarPessoaPeloNome(Pessoa listaAluno[], Pessoa listaProf[], int qtdAluno, int qtdProf, char busca[])
{
  bool encontrou = false;  

  printf("Alunos: \n");
  if(qtdAluno == 0)              
    printf("Lista de alunos está vazia.\n");
  else
  {
    for (int i = 0; i < qtdAluno; i++)
      if(strstr(listaAluno[i].nome, busca) != NULL)
      {
        encontrou = true;
        imprimirPessoa(listaAluno[i]);
      }
  }
  
  if(!encontrou)
    printf("Nenhum aluno encontrado para essa busca\n");
    
  encontrou = false;
  
  printf("Professores: \n");    
  if(qtdProf == 0)  
    printf("Lista de professores está vazia.\n");
  else
  {
    for (int i = 0; i < qtdProf; i++)
      if(strstr(listaProf[i].nome, busca) != NULL)
      {
        encontrou = true;
        imprimirPessoa(listaProf[i]);
      }
  }

  if(!encontrou)
    printf("Nenhum professor encontrado para essa busca\n");
}

void listarAlunosComMenosDeTresDisciplinas(Pessoa lista[], int qtd)
{
  bool encontrou = false;
  for(int i = 0; i < qtd; i++)
  {
    if(lista[i].ativo && lista[i].qtdDisciplinas < 3)
    {
      encontrou = true;
      imprimirPessoa(lista[i]);
    }
  }

  if(!encontrou)
    printf("Nenhum aluno com menos de 3 disciplinas matriculadas\n");
}

void listarDisciplinasComMaisDeQuarentaVagas(Disciplina lista[], int qtd)
{
  bool encontrou = false;
  for(int i = 0; i < qtd; i++)
  {
    if(lista[i].ativo && lista[i].totalVagas >= 40)
    {
      encontrou = true;
      imprimirDisciplina(lista[i]);
    }
  }

  if(!encontrou)
    printf("Nenhum disciplina com mais de 40 vagas\n");
}