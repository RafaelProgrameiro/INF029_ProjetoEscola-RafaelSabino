#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>

#define TAM_ALUNO 3
#define TAM_PROF 3

typedef struct {
  int dia;
  int mes;
  int ano;
} Data;

typedef struct {
  int matricula;
  char nome[50];
  char sexo;
  Data dataNascimento;
  char cpf[11];
  bool ativo;
} Pessoa;

//prototipos
int menuGeral();
int menuAluno();
int menuProfessor();
int menuAtualizar();
bool cadastrarPessoa(int opcao, Pessoa lista[], int qtd, int matricula);
void listarPessoas(Pessoa lista[], int qtd);
bool atualizarPessoa(int opcao, Pessoa lista[], int qtd, bool encontrado, int matriculaPessoa);
bool removerPessoa(Pessoa lista[], int qtd, bool encontrado, int matriculaPessoa);

int main() {
  // configuracao da localizacao para acentuacao das palavras
	setlocale(LC_ALL, "Portuguese");

  //variaveis globais
  Pessoa listaAluno[TAM_ALUNO] = {0};
  Pessoa listaProfessor[TAM_PROF] = {0};
  int qtdAluno = 0;
  int qtdProf = 0;
  int opcao;
  bool sair = false;
  int matricula = 1;

  while(!sair)
  {
    opcao = menuGeral();

    switch (opcao)
    {
      case 0: sair = true; break;
      case 1:
      {
        bool sairAluno = false;
        int opcaoAluno;

        printf("Módulo Aluno\n");

        while(!sairAluno)
        {
          opcaoAluno = menuAluno();

          switch(opcaoAluno)
          {
            case 0: sairAluno = true; break;
            case 1: 
            {                           
              printf("\nListar Alunos\n");

              if(qtdAluno == 0)
              {
                printf("Lista de alunos está vazia.\n");
                break;
              }
              
              listarPessoas(listaAluno, qtdAluno);
              
              break;
            }
            case 2: 
            {
              printf("\nCadastrar Aluno\n");

              if(cadastrarPessoa(opcao, listaAluno, qtdAluno, matricula))
              {
                matricula++;
                qtdAluno++;
                printf("Aluno cadastrado com sucesso\n");
              }
              else
                printf("Não foi possível realizar o cadastro\n");

              break;
            }            
            case 3:
            {              
              printf("Atualizar Aluno\n");              
              int matriculaAluno;
              bool encontrado = false;

              if(qtdAluno == 0)
              {
                printf("Lista de alunos está vazia.\n");
                break;
              }

              printf("Digite a matrícula do aluno: ");              
              scanf("%d", &matriculaAluno);

              if(matriculaAluno < 0)
              {
                printf("Matrícula inválida\n");
                break;
              }

              encontrado = atualizarPessoa(opcao, listaAluno, qtdAluno, encontrado, matriculaAluno);

              if (encontrado)
                printf("Aluno atualizado com sucesso\n");
              else
                printf("Matrícula inexistente.\n");

              break;
            } 
            case 4:
            {
              printf("\nRemover Aluno\n");

              int matriculaAluno;
              bool encontrado = false;

              if(qtdAluno == 0)
              {
                printf("Lista de alunos está vazia.\n");
                break;
              }

              printf("Digite a matrícula do aluno: ");              
              scanf("%d", &matriculaAluno);

              if(matriculaAluno < 0)
              {
                printf("Matrícula inválida\n");
                break;
              }

              encontrado = removerPessoa(listaAluno, qtdAluno, encontrado, matriculaAluno);

              if (encontrado)
              {
                printf("Aluno removido com sucesso\n");
                qtdAluno--;
              }
              else
                printf("Matrícula inexistente.\n");
              
              break;              
            } 
            default: printf("Opção Inválida\n"); break;
          }
        }
        break;        
      } 
      case 2: 
      {
        bool sairProfessor = false;
        int opcaoProfessor;

        printf("Módulo Professor\n");

        while(!sairProfessor)
        {
          opcaoProfessor = menuProfessor();

          switch(opcaoProfessor)
          {
            case 0: sairProfessor = true; break;
            case 1: 
            {             
              printf("\nListar Professores\n");

              if(qtdProf == 0)
              {
                printf("Lista de professores está vazia.\n");
                break;
              }
              
              listarPessoas(listaProfessor, qtdProf);
              
              break;
            }
            case 2: 
            {
              printf("\nCadastrar Professor\n");

              if(cadastrarPessoa(opcao, listaProfessor, qtdProf, matricula))
              {
                matricula++;
                qtdProf++;
                printf("Professor cadastrado com sucesso\n");
              }
              else
                printf("Não foi possível realizar o cadastro\n");

              break;
            }            
            case 3:
            {              
              printf("Atualizar Professor\n");              
              int matriculaProf;
              bool encontrado = false;

              if(qtdProf == 0)
              {
                printf("Lista de professores está vazia.\n");
                break;
              }

              printf("Digite a matrícula do professor: ");              
              scanf("%d", &matriculaProf);

              if(matriculaProf < 0)
              {
                printf("Matrícula inválida\n");
                break;
              }

              encontrado = atualizarPessoa(opcao, listaProfessor, qtdProf, encontrado, matriculaProf);

              if (encontrado)
                printf("Professor atualizado com sucesso\n");
              else
                printf("Matrícula inexistente.\n");

              break;
            } 
            case 4:
            {
              printf("\nRemover Professor\n");

              int matriculaProf;
              bool encontrado = false;

              if(qtdProf == 0)
              {
                printf("Lista de professores está vazia.\n");
                break;
              }

              printf("Digite a matrícula do professor: ");              
              scanf("%d", &matriculaProf);

              if(matriculaProf < 0)
              {
                printf("Matrícula inválida\n");
                break;
              }

              encontrado = removerPessoa(listaProfessor, qtdProf, encontrado, matriculaProf);

              if (encontrado)
              {
                printf("Professor removido com sucesso\n");
                qtdProf--;
              }
              else
                printf("Matrícula inexistente.\n");
              
              break;              
            } 
            default: printf("Opção Inválida\n"); break;
          }
        }
        break;        
      }
      case 3: printf("Módulo Disciplina\n"); break;
      default: printf("Opção Inválida\n"); break;
    }
  }

  //fim do codigo
  return 0;
}

//funcoes
int menuGeral()
{
  int opcao;
  printf("\nProjeto Escola\n");
  printf("1 - Aluno\n");
  printf("2 - Professor\n");
  printf("3 - Disciplina\n");
  printf("0 - Sair\n");
  
  scanf("%d", &opcao);
  getchar();

  return opcao;
}

int menuAluno()
{
  int opcaoAluno;
  printf("\n1 - Listar Alunos\n");
  printf("2 - Cadastrar Aluno\n");
  printf("3 - Atualizar Aluno\n");
  printf("4 - Remover Aluno\n");
  printf("0 - Voltar\n");

  scanf("%d", &opcaoAluno);
  getchar();

  return opcaoAluno;
}

int menuProfessor()
{
  int opcaoProf;
  printf("\n1 - Listar Professores\n");
  printf("2 - Cadastrar Professor\n");
  printf("3 - Atualizar Professor\n");
  printf("4 - Remover Professor\n");
  printf("0 - Voltar\n");

  scanf("%d", &opcaoProf);
  getchar();

  return opcaoProf;
}

int menuAtualizar()
{
  int opcaoAtualizar;
  printf("\n1 - Atualizar nome\n");
  printf("2 - Atualizar sexo\n");
  printf("0 - Cancelar\n");

  scanf("%d", &opcaoAtualizar);
  getchar();

  return opcaoAtualizar;
}

bool cadastrarPessoa(int opcao, Pessoa lista[], int qtd, int matricula)
{ 
  char pessoa[10] = {"Pessoa"};
  switch(opcao)
  {
    case 1: strcpy(pessoa, "Aluno"); break;
    case 2: strcpy(pessoa, "Professor"); break;
    default: printf("Opção inválida\n"); break;
  }

  if(qtd == TAM_ALUNO)
  {
    printf("Lista de %ss já está cheia.\n", pessoa);
    return false;
  }

  char nome[50];
  bool sexoValido = false;
  char sexo;

  lista[qtd].matricula = matricula;
  lista[qtd].ativo = true;

  printf("Digite o nome do %s: ", pessoa);
  fgets(nome, 50, stdin);

  strcpy(lista[qtd].nome, nome);

  while(!sexoValido)
  {
    printf("Digite o caracter para o válido para o sexo (maiúsculo): \n");
    printf("M - Masculino\n");
    printf("F - Feminino\n");

    scanf(" %c", &sexo);
    switch (sexo)    
    {
      case 'M': lista[qtd].sexo = sexo; sexoValido = true; break;
      case 'F': lista[qtd].sexo = sexo; sexoValido = true; break;
      default: printf("Entrada inválida.\n"); break;
    }
  }
  return true;
}

void listarPessoas(Pessoa lista[], int qtd)
{  
  for(int i = 0; i < qtd; i++)
  { 
    if(lista[i].ativo)   
    {                  
      printf("\nNome: %s", lista[i].nome);
      printf("Matrícula: %d\nSexo: %c\n", lista[i].matricula, lista[i].sexo);
      printf("------------\n");
    }
  }
}

bool atualizarPessoa(int opcao, Pessoa lista[], int qtd, bool encontrado, int matriculaPessoa)
{
  int opcaoAtualizar;
  bool sairAtualizar = false;
  char pessoa[10] = {"Pessoa"};
  switch(opcao)
  {
    case 1: strcpy(pessoa, "Aluno"); break;
    case 2: strcpy(pessoa, "Professor"); break;
    default: printf("Opção inválida\n"); break;
  }

  for(int i = 0; i < qtd; i++)
  {
    if(matriculaPessoa == lista[i].matricula && lista[i].ativo)
    {
      encontrado = true;
      while(!sairAtualizar)
      {
       opcaoAtualizar = menuAtualizar();

       switch(opcaoAtualizar)
       {
        case 0: sairAtualizar = true; break;
        case 1:
        {
          char nome[50];

          printf("Digite o nome do aluno: ");
          getchar();
          fgets(nome, 50, stdin);

          strcpy(lista[i].nome, nome);
          sairAtualizar = true;
          break;

        }
        case 2: 
        {
          char sexo;
          bool sexoValido = false;

          while(!sexoValido)
          {
            printf("Digite o caracter para o sexo do aluno: \n");
            printf("M - Masculino\n");
            printf("F - Feminino\n");

            scanf(" %c", &sexo);
            switch (sexo)    
            {
              case 'M': lista[i].sexo = sexo; sexoValido = true; break;
              case 'F': lista[i].sexo = sexo; sexoValido = true; break;
              default: printf("Digite o caracter válido para o sexo (maiúsculo)"); break;
            }
          }
          sairAtualizar = true;
          break;
        }
        default: printf("Opção inválida\n"); break;
       }
      }   
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
      {
        lista[j].matricula = lista[j + 1].matricula;
        lista[j].sexo = lista[j + 1].sexo;
        lista[j].ativo = lista[j + 1].ativo;
      }      
      break;
    }                
  }
  return encontrado ? true : false;
}