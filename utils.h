#ifndef UTIL_H
#define UTIL_H
#include <stdbool.h>
#include "pessoa.h"

bool validarCpf(char cpf[]);
bool validarData(int dia, int mes, int ano);
void formatarCpf(char cpf[]);
void formatarData(int dia, int mes, int ano);
void ordenarPessoasPorNome(Pessoa lista[], int qtd);
void ordenarPessoasPorDataNacimento(Pessoa lista[], int qtd);

#endif