#ifndef PESSOA_H
#define PESSOA_H
#include <stdbool.h>
#include "escola.h"

bool cadastrarPessoa(int opcao, Pessoa lista[], int qtd, int matricula);
void listarPessoas(Pessoa lista[], int qtdAluno);
bool atualizarPessoa(int opcao, Pessoa lista[], int qtd, bool encontrado, int matriculaPessoa);
bool removerPessoa(Pessoa lista[], int qtd, bool encontrado, int matriculaPessoa);

#endif