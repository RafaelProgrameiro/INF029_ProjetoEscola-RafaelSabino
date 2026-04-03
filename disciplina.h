#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <stdbool.h>
#include "escola.h"

bool cadastrarDisciplina(Disciplina lista[], Pessoa listaProfessor[], int qtdProf, int qtd, int cod);
void imprimirDisciplina(Disciplina disc);
void listarDisciplinas(Disciplina lista[], int qtd);
bool removerDisciplina(Disciplina lista[], Pessoa listaProfessor[], int qtd, int qtdProf, bool encontrado, int codDisciplina);
bool inserirAlunoNaDisciplina(Disciplina lista[], Pessoa listaAluno[], int qtdAluno, int qtd, bool encontrado, int codDisciplina);
bool removerAlunoDaDisciplina(Disciplina lista[], Pessoa listaAluno[], int qtd, int qtdAluno, bool encontrado, int codDisciplina);

#endif