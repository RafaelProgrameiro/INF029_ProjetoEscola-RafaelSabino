#ifndef RELATORIO_H
#define RELATORIO_H
#include "disciplina.h"
#include "pessoa.h"
#include <stdbool.h>

bool detalharDisciplina(Disciplina lista[], Pessoa listaAluno[], int qtdAluno, int qtdDisc, bool encontrado, int codDisciplina);
void listarPessoasPorSexo(Pessoa lista[], int qtd, char sexo);
void listarPessoasPorOrdemAlfabetica(Pessoa lista[], int qtd);
void listarPessoasPorDataNascimento(Pessoa lista[], int qtd);
void listarAniversariantesDoMes(Pessoa listaAluno[], Pessoa listaProf[], int qtdAluno, int qtdProf, int mes);
void buscarPessoaPeloNome(Pessoa listaAluno[], Pessoa listaProf[], int qtdAluno, int qtdProf, char busca[]);
void listarAlunosComMenosDeTresDisciplinas(Pessoa lista[], int qtd);
void listarDisciplinasComMaisDeQuarentaVagas(Disciplina lista[], int qtd);

#endif