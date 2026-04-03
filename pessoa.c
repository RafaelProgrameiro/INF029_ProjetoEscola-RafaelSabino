#include "pessoa.h"
#include "utils.h"
#include "menu.h"
#include <stdio.h>
#include <string.h>

bool cadastrarPessoa(int opcao, Pessoa lista[], int qtd, int matricula)
{ 
  char pessoa[12] = {"Pessoas"};
  int  tam_lista;
  char nome[50];
  bool nomeValido = false;
  int sexoNum;
  bool sexoValido = false;
  char sexo;
  int dia, mes, ano;
  bool dataValida = false;
  char cpf[12];
  bool cpfValido = false;

  switch(opcao)
  {
    case 1: strcpy(pessoa, "Alunos"); tam_lista = TAM_ALUNO; break;
    case 2: strcpy(pessoa, "Professores"); tam_lista = TAM_PROF; break;
    default: printf("Opção inválida\n"); break;
  }

  if(qtd == tam_lista)
  {
    printf("Lista de %ss já está cheia.\n", pessoa);
    return false;
  }

  while(!nomeValido)
  {
    printf("Digite o nome do %s (pelo menos 3 letras): ", pessoa);
    fgets(nome, 50, stdin);

    int tamNome = strlen(nome);

    if(tamNome > 0 && nome[tamNome - 1] == '\n')
    {
      nome[tamNome - 1] = '\0';
      tamNome--;
    }

    if(tamNome < 3 || tamNome > 50)
      printf("Tamanho do nome inválido\n");
    else    
      nomeValido = true;  
  }

  while(!sexoValido)
  {
    printf("Digite o caracter válido para o sexo (maiúsculo): \n");
    printf("1 - Masculino\n");
    printf("2 - Feminino\n");

    if(scanf("%d", &sexoNum) != 1)
    {
      printf("Entrada inválida.\n");

      int c;
      while ((c = getchar()) != '\n' && c != EOF);

      continue;
    }

    switch (sexoNum)    
    {
      case 1: sexo = 'M'; sexoValido = true; break;
      case 2: sexo = 'F'; sexoValido = true; break;
      default: printf("Entrada inválida.\n"); break;
    }
  }

  while(!dataValida)
  {
    printf("Digite o dia, mês e ano do nascimento (Ex: 16 10 1990): ");
    scanf("%d %d %d", &dia, &mes, &ano);

    dataValida = validarData(dia, mes, ano);
    if(!dataValida)
      printf("Entrada inválida\n");
  }

  getchar();

  while(!cpfValido)
  {
    printf("Digite o cpf (somente números): ");
    fgets(cpf, 12, stdin);

    cpfValido = validarCpf(cpf);
    if(!cpfValido)
      printf("Entrada inválida\n");      
  }

  lista[qtd].matricula = matricula;
  lista[qtd].ativo = true;  
  strcpy(lista[qtd].nome, nome);
  lista[qtd].sexo = sexo;
  lista[qtd].dataNascimento.dia = dia;
  lista[qtd].dataNascimento.mes = mes;
  lista[qtd].dataNascimento.ano = ano;
  strcpy(lista[qtd].cpf, cpf);
  lista[qtd].qtdDisciplinas = 0;

  return true;
}

void imprimirPessoa(Pessoa p)
{
  printf("\nNome: %s\n", p.nome);
  printf("Matrícula: %d\n", p.matricula);
  printf("Sexo: %c\n", p.sexo);
  printf("Data de nascimento: ");
  formatarData(p.dataNascimento.dia, p.dataNascimento.mes, p.dataNascimento.ano);
  printf("\nCpf: ");
  formatarCpf(p.cpf);
  printf("\nQuantidade de disciplinas: %d", p.qtdDisciplinas);      
  printf("\n------------\n");
}

void listarPessoas(Pessoa lista[], int qtd)
{  
  for(int i = 0; i < qtd; i++)
  { 
    if(lista[i].ativo)   
      imprimirPessoa(lista[i]);    
  }
}

bool atualizarPessoa(int opcao, Pessoa lista[], int qtd, bool encontrado, int matriculaPessoa)
{
  int opcaoAtualizar;
  bool sairAtualizar = false;
  char pessoa[12] = {"Pessoas"};
  switch(opcao)
  {
    case 1: strcpy(pessoa, "Alunos"); break;
    case 2: strcpy(pessoa, "Professores"); break;
    default: printf("Entrada inválida.\n"); break;
  }

  for(int i = 0; i < qtd; i++)
  {
    if(matriculaPessoa == lista[i].matricula && lista[i].ativo)
    {
      encontrado = true;
      while(!sairAtualizar)
      {
       opcaoAtualizar = menuAtualizarPessoa();

       switch(opcaoAtualizar)
       {
        case 0: sairAtualizar = true; break;
        case 1:
        {
          char nome[50];
          bool nomeValido = false;

          

          while(!nomeValido)
          {           
            printf("Digite o nome do %s: ", pessoa);
            fgets(nome, 50, stdin);

            int tamNome = strlen(nome);

            if(tamNome > 0 && nome[tamNome - 1] == '\n')
            {
              nome[tamNome - 1] = '\0';
              tamNome--;
            }

            if(tamNome < 3 || tamNome > 50)
              printf("Tamanho do nome inválido\n");
            else    
              nomeValido = true;
          }

          strcpy(lista[i].nome, nome);
          sairAtualizar = true;
          break;
        }
        case 2: 
        {
          int sexoNum;
          bool sexoValido = false;

          while(!sexoValido)
          {
            printf("Digite o caracter válido para o sexo (maiúsculo): \n");
            printf("1 - Masculino\n");
            printf("2 - Feminino\n");

            if(scanf("%d", &sexoNum) != 1)
            {
              printf("Entrada inválida.\n");

              int c;
              while ((c = getchar()) != '\n' && c != EOF);

              continue;
            }

            switch (sexoNum)    
            {
              case 1: lista[i].sexo = 'M'; sexoValido = true; break;
              case 2: lista[i].sexo = 'F'; sexoValido = true; break;
              default: printf("Entrada inválida.\n"); break;
            }
          }
          sairAtualizar = true;
          break;
        }
        case 3:
        {
          int dia, mes, ano;
          bool dataValida = false;

          while(!dataValida)
          {
            printf("Digite o dia, mês e ano do nascimento (Ex: 16 10 1990): ");
            scanf("%d %d %d", &dia, &mes, &ano);

            dataValida = validarData(dia, mes, ano);
            if(!dataValida)
              printf("Entrada inválida\n");
          }
          lista[i].dataNascimento.dia = dia;
          lista[i].dataNascimento.mes = mes;
          lista[i].dataNascimento.ano = ano;

          sairAtualizar = true;
          break;
        }
        case 4:
        {
          char cpf[12];
          bool cpfValido = false;

          while(!cpfValido)
          {
            printf("Digite o cpf (somente números): ");
            fgets(cpf, 12, stdin);

            cpfValido = validarCpf(cpf);
            if(!cpfValido)
              printf("Cpf informado inválido\n");
          }
          strcpy(lista[i].cpf, cpf);

          sairAtualizar = true;
          break;
        }
        default: printf("Opção inválida\n"); break;
       }
      }   
      break;
    }        
  }
  return encontrado ? true : false;
}

bool removerPessoa(Pessoa lista[], int qtd, bool encontrado, int matriculaPessoa)
{  
  for(int i = 0; i < qtd; i++)
  {
    if(matriculaPessoa == lista[i].matricula && lista[i].ativo)
    {
      encontrado = true;
      lista[i].ativo = false;
      
      for(int j = i; j < qtd - 1; j++)
        lista[j] = lista[j + 1];
      break;
    }                
  }
  return encontrado ? true : false;
}