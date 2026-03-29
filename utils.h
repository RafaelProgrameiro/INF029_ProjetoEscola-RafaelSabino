#ifndef UTIL_H
#define UTIL_H
#include <stdbool.h>

bool validaCpf(char cpf[]);
bool validaData(int dia, int mes, int ano);
void formataCpf(char cpf[]);
void formataData(int dia, int mes, int ano);

#endif