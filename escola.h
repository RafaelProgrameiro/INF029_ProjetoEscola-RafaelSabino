#ifndef ESCOLA_H
#define ESCOLA_H

#include <stdbool.h>

#define TAM_ALUNO 3
#define TAM_PROF 3
#define TAM_DISC 3
#define MAX_ALUNOS 60

typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    int matricula;
    char nome[50];
    char sexo;
    Data dataNascimento;
    char cpf[12];
    int qtdDisciplinas;
    bool ativo;
} Pessoa;

typedef struct {
    char nome[25];
    int cod, semestre, totalVagas;
    Pessoa professor;
    int matriculaAlunos[MAX_ALUNOS];
    int qtdAlunosMatriculados;
    bool ativo;
} Disciplina;

#endif