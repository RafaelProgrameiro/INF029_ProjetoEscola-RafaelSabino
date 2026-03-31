#include "utils.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool validaCpf(char cpf[])
{
  int cpfNumerico[11];
  int soma, resto, div1, div2;
  
  if(strlen(cpf) != 11)
  {
    printf("O cpf digitado não tem 11 digitos\n");
    return false;
  }

  for(int i = 0; i < 11; i++)
  {
    if (!isdigit(cpf[i]))
    {
      printf("Usar apenas digitos para preencher o cpf\n");
      return false; 
    }
    cpfNumerico[i] = cpf[i] - '0';
  }

  soma = 0;
  for(int i = 0, j = 10; i < 9; i++, j--)
    soma += cpfNumerico[i] * j;

  resto = soma % 11;
  div1 = (resto < 2) ? 0 : (11 - resto);

  soma = 0;
  for(int i = 0, j = 11; i < 10; i++, j--)
    soma += cpfNumerico[i] * j;

  resto = soma % 11;
  div2 = (resto < 2) ? 0 : (11 - resto);

  if(!(div1 == cpfNumerico[9] && div2 == cpfNumerico[10]))
    return false;

  return true;
}

bool validaData(int dia, int mes, int ano)
{ 
  bool bissexto;

  if(ano % 4 == 0)
  {
    if(ano % 100 == 0)
    {
      if(ano % 400 == 0)
        bissexto = true;
      else
        bissexto = false;
    }else
      bissexto = true;      
  } else
      bissexto = false;

  if(dia <= 0 || dia > 31)
  {
    printf("O dia precisa ser entre 1 e 31\n");
    return false;
  }

  if(mes <= 0 || mes > 12)
  {
    printf("O mês precisa ser entre 1 e 12\n");
    return false;
  }

  if(mes == 2 && !bissexto && dia > 28)
  {
    printf("Dia inválido para o mês e ano informado\n");
    return false;
  }

  if(mes == 2 && bissexto && dia > 29)
  {
    printf("Dia inválido para o mês e ano informado\n");
    return false;
  }

  if((mes == 4 || mes == 6 || mes == 9 || mes == 11 ) && dia > 30)
  {
    printf("Dia inválido para o mês informado\n");
    return false;
  }  

  if(ano < 1900 && ano > 2026)
  {
    printf("O ano precisa ser maior que 1900 e/ou menor que 2026\n");
    return false;
  }

  return true;
}

void formataCpf(char cpf[])
{
  for(int i = 0; i < 3; i++)
    printf("%c", cpf[i]);
  printf(".");

  for(int i = 3; i < 6; i++)
    printf("%c", cpf[i]);
  printf(".");

  for(int i = 6; i < 9; i++)
    printf("%c", cpf[i]);
  printf("-");

  for(int i = 9; i < 11; i++)
    printf("%c", cpf[i]);  
}

void formataData(int dia, int mes, int ano)
{
  if(dia < 10)
    printf("0");
  printf("%d/", dia);

  if(mes < 10)
    printf("0");
  printf("%d/", mes);

  printf("%d", ano);
}

void ordenarPessoasPorNome(Pessoa lista[], int qtd)
{
  Pessoa aux;
  
  for(int i = 0; i < qtd - 1; i++)
    for(int j = 0; j < qtd - i - 1; j++)
      if(strcmp(lista[j].nome, lista[j + 1].nome) > 0)
      {
        aux = lista[j];
        lista[j] = lista[j + 1];
        lista[j + 1] = aux;
      }
}