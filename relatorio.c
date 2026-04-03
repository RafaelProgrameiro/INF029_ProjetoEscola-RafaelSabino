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
      printf("\nNome: %s\n", lista[i].nome);
      printf("Código: %d\n", lista[i].cod);
      printf("Semestre: %dº\n", lista[i].semestre);
      printf("Total de vagas: %d\n", lista[i].totalVagas);
      printf("Total de alunos matriculados: %d\n", lista[i].qtdAlunosMatriculados);
      printf("Vagas Restantes: %d\n", lista[i].totalVagas - lista[i].qtdAlunosMatriculados);
      printf("Professor: %s", lista[i].professor.nome);
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
      printf("------------\n");
      break;
    }
  }

  return encontrado ? true : false;
}

void listarPessoasPorSexo(Pessoa lista[], int qtd, char sexo)
{
  for(int i = 0; i < qtd; i++)
  {
    if(lista[i].ativo && lista[i].sexo == sexo)
    {
      printf("\nNome: %s\n", lista[i].nome);
      printf("Matrícula: %d\n", lista[i].matricula);
      printf("Sexo: %c\n", lista[i].sexo);
      printf("Data de nascimento: ");
      formataData(lista[i].dataNascimento.dia, lista[i].dataNascimento.mes, lista[i].dataNascimento.ano);
      printf("\nCpf: ");
      formataCpf(lista[i].cpf);
      printf("\nQuantidade de disciplinas: %d", lista[i].qtdDisciplinas);
      printf("\n------------\n");
    }
  }
}

void listarPessoasPorOrdemAlfabetica(Pessoa lista[], int qtd)
{
  Pessoa pessoasOrdenada[TAM_ALUNO];

  for(int i = 0; i < qtd; i++)
    pessoasOrdenada[i]= lista[i];

  ordenarPessoasPorNome(pessoasOrdenada, qtd);
  listarPessoas(pessoasOrdenada, qtd);
}

void listarPessoasPorDataNascimento(Pessoa lista[], int qtd)
{
  Pessoa pessoasOrdenada[TAM_ALUNO];

  for(int i = 0; i < qtd; i++)
    pessoasOrdenada[i]= lista[i];

  ordenarPessoasPorDataNacimento(pessoasOrdenada, qtd);
  listarPessoas(pessoasOrdenada, qtd);
}

void listarAniversariantesDoMes(Pessoa listaAluno[], Pessoa listaProfessor[], int qtdAluno, int qtdProf, int mes)
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
        printf("\nNome: %s\n", listaAluno[i].nome);
        printf("Matrícula: %d\n", listaAluno[i].matricula);
        printf("Sexo: %c\n", listaAluno[i].sexo);
        printf("Data de nascimento: ");
        formataData(listaAluno[i].dataNascimento.dia, listaAluno[i].dataNascimento.mes, listaAluno[i].dataNascimento.ano);
        printf("\nCpf: ");
        formataCpf(listaAluno[i].cpf);
        printf("\nQuantidade de disciplinas: %d", listaAluno[i].qtdDisciplinas);
        printf("\n------------\n");
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
      if(listaProfessor[i].ativo && listaProfessor[i].dataNascimento.mes == mes)
      {
        encontrou = true;
        printf("\nNome: %s\n", listaProfessor[i].nome);
        printf("Matrícula: %d\n", listaProfessor[i].matricula);
        printf("Sexo: %c\n", listaProfessor[i].sexo);
        printf("Data de nascimento: ");
        formataData(listaProfessor[i].dataNascimento.dia, listaProfessor[i].dataNascimento.mes, listaProfessor[i].dataNascimento.ano);
        printf("\nCpf: ");
        formataCpf(listaProfessor[i].cpf);
        printf("\nQuantidade de disciplinas: %d", listaProfessor[i].qtdDisciplinas);
        printf("\n------------\n");
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
        printf("\nNome: %s\n", listaAluno[i].nome);
        printf("Matrícula: %d\n", listaAluno[i].matricula);
        printf("Sexo: %c\n", listaAluno[i].sexo);
        printf("Data de nascimento: ");
        formataData(listaAluno[i].dataNascimento.dia, listaAluno[i].dataNascimento.mes, listaAluno[i].dataNascimento.ano);
        printf("\nCpf: ");
        formataCpf(listaAluno[i].cpf);
        printf("\nQuantidade de disciplinas: %d", listaAluno[i].qtdDisciplinas);
        printf("\n------------\n");
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
        printf("\nNome: %s\n", listaProf[i].nome);
        printf("Matrícula: %d\n", listaProf[i].matricula);
        printf("Sexo: %c\n", listaProf[i].sexo);
        printf("Data de nascimento: ");
        formataData(listaProf[i].dataNascimento.dia, listaProf[i].dataNascimento.mes, listaProf[i].dataNascimento.ano);
        printf("\nCpf: ");
        formataCpf(listaProf[i].cpf);
        printf("\nQuantidade de disciplinas: %d", listaProf[i].qtdDisciplinas);
        printf("\n------------\n");
      }
  }

  if(!encontrou)
    printf("Nenhum professor encontrado para essa busca\n");
}

void listarAlunosComMenosDeTresDisciplinas(Pessoa lista[], int qtd)
{
  for(int i = 0; i < qtd; i++)
  {
    if(lista[i].ativo && lista[i].qtdDisciplinas < 3)
    {
      printf("\nNome: %s\n", lista[i].nome);
      printf("Matrícula: %d\n", lista[i].matricula);
      printf("Sexo: %c\n", lista[i].sexo);
      printf("Data de nascimento: ");
      formataData(lista[i].dataNascimento.dia, lista[i].dataNascimento.mes, lista[i].dataNascimento.ano);
      printf("\nCpf: ");
      formataCpf(lista[i].cpf);
      printf("\nQuantidade de disciplinas: %d", lista[i].qtdDisciplinas);
      printf("\n------------\n");
    }
  }
}

void listarDisciplinasComMaisDeQuarentaVagas(Disciplina lista[], int qtd)
{
  for(int i = 0; i < qtd; i++)
  {
    if(lista[i].ativo && lista[i].totalVagas >= 40)
    {
      printf("\nNome: %s\n", lista[i].nome);
      printf("Código: %d\n", lista[i].cod);
      printf("Semestre: %dº\n", lista[i].semestre);
      printf("Total de vagas: %d\n", lista[i].totalVagas);
      printf("Total de alunos matriculados: %d\n", lista[i].qtdAlunosMatriculados);
      printf("Vagas Restantes: %d\n", lista[i].totalVagas - lista[i].qtdAlunosMatriculados);
      printf("Professor: %s", lista[i].professor.nome);
      printf("\n------------\n");
    }
  }
}