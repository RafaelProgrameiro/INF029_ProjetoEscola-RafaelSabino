#include "relatorio.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>

// LISTA DE PESSOAS A PARTIR DE UMA STRING DE BUSCA.O USUARIO INFORMA NO MINIMO TRES LETRAS E DEVE SER LISTADO TODAS AS PESSOAS QUE CONTEM ESSAS TRES LETRAS NO NOME
// LISTA DE ALUNOS MATRICULADOS EM MENOS DE 3 DISCIPLINAS
// LISTA DE DISCIPLINAS, COM NOME DO PROFESSOR, QUE EXTRAPOLAM 40 VAGAS

bool detalharDisciplina(Disciplina lista[], Pessoa listaAluno[], int qtdAluno, int qtdDisc, bool encontrado, int codDisciplina)
{
  for(int i = 0; i < qtdDisc; i++)
  {
    if(codDisciplina == lista[i].cod && lista[i].ativo)
    {
      encontrado = true;
      int matriculaAluno;
      printf("\nNome: %s", lista[i].nome);
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
            printf(" Matricula: %d - Nome: %s", listaAluno[k].matricula, listaAluno[k].nome);
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
      printf("\nNome: %s", lista[i].nome);
      printf("Matrícula: %d\n", lista[i].matricula);
      printf("Sexo: %c\n", lista[i].sexo);
      printf("Data de nascimento: ");
      formataData(lista[i].dataNascimento.dia, lista[i].dataNascimento.mes, lista[i].dataNascimento.ano);
      printf("\nCpf: ");
      formataCpf(lista[i].cpf);
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
  int contador = 0;

  printf("Alunos: \n");
  if(qtdAluno == 0)              
    printf("Lista de alunos está vazia.\n");
  else
  {
    for(int i = 0; i < qtdAluno; i++)
    {
      if(listaAluno[i].ativo && listaAluno[i].dataNascimento.mes == mes)
      {
        contador++;
        printf("\nNome: %s", listaAluno[i].nome);
        printf("Matrícula: %d\n", listaAluno[i].matricula);
        printf("Sexo: %c\n", listaAluno[i].sexo);
        printf("Data de nascimento: ");
        formataData(listaAluno[i].dataNascimento.dia, listaAluno[i].dataNascimento.mes, listaAluno[i].dataNascimento.ano);
        printf("\nCpf: ");
        formataCpf(listaAluno[i].cpf);
        printf("\n------------\n");
      }
    }
  }
  if (contador == 0)
    printf("Nenhum aluno faz aniversário neste mês\n");

  contador = 0;

  printf("Professores: \n");    
  if(qtdProf == 0)  
    printf("Lista de professores está vazia.\n");
  else
  {
    for(int i = 0; i < qtdProf; i++)
    {
      if(listaProfessor[i].ativo && listaProfessor[i].dataNascimento.mes == mes)
      {
        contador++;
        printf("\nNome: %s", listaProfessor[i].nome);
        printf("Matrícula: %d\n", listaProfessor[i].matricula);
        printf("Sexo: %c\n", listaProfessor[i].sexo);
        printf("Data de nascimento: ");
        formataData(listaProfessor[i].dataNascimento.dia, listaProfessor[i].dataNascimento.mes, listaProfessor[i].dataNascimento.ano);
        printf("\nCpf: ");
        formataCpf(listaProfessor[i].cpf);
        printf("\n------------\n");
      }
    }
  }
  if (contador == 0)
    printf("Nenhum professor faz aniversário neste mês\n");
}