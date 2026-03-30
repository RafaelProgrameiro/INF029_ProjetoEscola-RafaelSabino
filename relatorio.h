#ifndef RELATORIO_H
#define RELATORIO_H
#include "disciplina.h"
#include "pessoa.h"
#include <stdbool.h>

bool detalharDisciplina(Disciplina lista[], Pessoa listaAluno[], int qtdAluno, int qtdDisc, bool encontrado, int codDisciplina);

#endif