#include "relatorio.h"
#include <stdio.h>

// DETALHAR UMA DISCIPLINA
// LISTAR ALUNOS POR SEXO
// LISTAR ALUNOS ORDENADOS POR NOME
// LISTAR PROFESSORES ORDENADOS POR DATA DE NASCIMENTO
// LISTAR PROFESSORES POR SEXO
// LISTAR PROFESSORES ORDENADOS POR NOME
// LISTAR PROFESSORES ORDENADOS POR DATA DE NASCIMENTO
// ANIVERSARIANTES DO MES
// LISTA DE PESSOAS A PARTIR DE UMA STRING DE BUSCA.O USUARIO INFORMA NO MINIMO TRES LETRAS
// E DEVE SER LISTADO TODAS AS PESSOAS QUE CONTEM ESSAS TRES LETRAS NO NOME
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