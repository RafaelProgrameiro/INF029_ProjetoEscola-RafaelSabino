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
bool cadastrarAluno(Pessoa listaAluno[], int qtdAluno, int matricula);
void listarAlunos(Pessoa listaAluno[], int qtdAluno);
bool atualizarAluno(Pessoa listaAluno[], int qtdAluno, bool encontrado, int matriculaAluno);
bool removerAluno(Pessoa listaAluno[], int qtdAluno, bool encontrado, int matriculaAluno);
bool cadastrarProfessor(Pessoa listaProfessor[], int qtdProf, int matricula);
void listarProfessores(Pessoa listaProfessor[], int qtdProf);
bool atualizarProfessor(Pessoa listaProfessor[], int qtdProf, bool encontrado, int matriculaAluno);
bool removerProfessor(Pessoa listaProfessor[], int qtdProf, bool encontrado, int matriculaAluno);

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
              
              listarAlunos(listaAluno, qtdAluno);
              
              break;
            }
            case 2: 
            {
              printf("\nCadastrar Aluno\n");

              if(cadastrarAluno(listaAluno, qtdAluno, matricula))
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

              encontrado = atualizarAluno(listaAluno, qtdAluno, encontrado, matriculaAluno);

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

              encontrado = removerAluno(listaAluno, qtdAluno, encontrado, matriculaAluno);

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
              
              listarProfessores(listaProfessor, qtdProf);
              
              break;
            }
            case 2: 
            {
              printf("\nCadastrar Professor\n");

              if(cadastrarProfessor(listaProfessor, qtdProf, matricula))
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

              encontrado = atualizarProfessor(listaProfessor, qtdProf, encontrado, matriculaProf);

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

              encontrado = removerProfessor(listaProfessor, qtdProf, encontrado, matriculaProf);

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

bool cadastrarAluno(Pessoa listaAluno[], int qtdAluno, int matricula)
{ 
  if(qtdAluno == TAM_ALUNO)
  {
    printf("Lista de alunos já está cheia.\n");
    return false;
  }

  char nome[50];
  bool sexoValido = false;
  char sexo;

  listaAluno[qtdAluno].matricula = matricula;
  listaAluno[qtdAluno].ativo = true;

  printf("Digite o nome do aluno: ");
  getchar();
  fgets(nome, 50, stdin);

  strcpy(listaAluno[qtdAluno].nome, nome);

  while(!sexoValido)
  {
    printf("Digite o caracter para o válido para o sexo (maiúsculo): \n");
    printf("M - Masculino\n");
    printf("F - Feminino\n");

    scanf(" %c", &sexo);
    switch (sexo)    
    {
      case 'M': listaAluno[qtdAluno].sexo = sexo; sexoValido = true; break;
      case 'F': listaAluno[qtdAluno].sexo = sexo; sexoValido = true; break;
      default: printf("Entrada inválida.\n"); break;
    }
  }
  return true;
}

void listarAlunos(Pessoa listaAluno[], int qtdAluno)
{
  for(int i = 0; i < qtdAluno; i++)
  { 
    if(listaAluno[i].ativo)   
    {                  
      printf("\nNome: %s", listaAluno[i].nome);
      printf("Matrícula: %d\nSexo: %c\n", listaAluno[i].matricula, listaAluno[i].sexo);
      printf("------------\n");
    }
  }
}

bool atualizarAluno(Pessoa listaAluno[], int qtdAluno, bool encontrado, int matriculaAluno)
{
  int opcaoAtualizar;
  bool sairAtualizar = false;  

  for(int i = 0; i < qtdAluno; i++)
  {
    if(matriculaAluno == listaAluno[i].matricula && listaAluno[i].ativo)
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

          strcpy(listaAluno[i].nome, nome);
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
              case 'M': listaAluno[i].sexo = sexo; sexoValido = true; break;
              case 'F': listaAluno[i].sexo = sexo; sexoValido = true; break;
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

bool removerAluno(Pessoa listaAluno[], int qtdAluno, bool encontrado, int matriculaAluno)
{
  for(int i = 0; i < qtdAluno; i++)
  {
    if(matriculaAluno == listaAluno[i].matricula && listaAluno[i].ativo)
    {
      encontrado = true;
      listaAluno[i].ativo = false;
      for(int j = i; j < qtdAluno - 1; j++)
      {
        listaAluno[j].matricula = listaAluno[j + 1].matricula;
        listaAluno[j].sexo = listaAluno[j + 1].sexo;
        listaAluno[j].ativo = listaAluno[j + 1].ativo;
      }      
      break;
    }                
  }
  return encontrado ? true : false;
}

bool cadastrarProfessor(Pessoa listaProfessor[], int qtdProf, int matricula)
{ 
  if(qtdProf == TAM_PROF)
  {
    printf("Lista de professores já está cheia.\n");
    return false;
  }

  char nome[50];
  bool sexoValido = false;
  char sexo;

  listaProfessor[qtdProf].matricula = matricula;
  listaProfessor[qtdProf].ativo = true;

  printf("Digite o nome do professor: ");
  getchar();
  fgets(nome, 50, stdin);

  strcpy(listaProfessor[qtdProf].nome, nome);

  while(!sexoValido)
  {
    printf("Digite o caracter para o válido para o sexo (maiúsculo): \n");
    printf("M - Masculino\n");
    printf("F - Feminino\n");

    scanf(" %c", &sexo);
    switch (sexo)    
    {
      case 'M': listaProfessor[qtdProf].sexo = sexo; sexoValido = true; break;
      case 'F': listaProfessor[qtdProf].sexo = sexo; sexoValido = true; break;
      default: printf("Entrada inválida.\n"); break;
    }
  }
  return true;
}

void listarProfessores(Pessoa listaProfessor[], int qtdProf)
{
  for(int i = 0; i < qtdProf; i++)
  { 
    if(listaProfessor[i].ativo)   
    {                  
      printf("\nNome: %s", listaProfessor[i].nome);
      printf("Matrícula: %d\nSexo: %c\n", listaProfessor[i].matricula, listaProfessor[i].sexo);
      printf("------------\n");
    }
  }
}

bool atualizarProfessor(Pessoa listaProfessor[], int qtdProf, bool encontrado, int matriculaProf)
{
  int opcaoAtualizar;
  bool sairAtualizar = false;  

  for(int i = 0; i < qtdProf; i++)
  {
    if(matriculaProf == listaProfessor[i].matricula && listaProfessor[i].ativo)
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

          printf("Digite o nome do Professor: ");
          getchar();
          fgets(nome, 50, stdin);

          strcpy(listaProfessor[i].nome, nome);
          sairAtualizar = true;
          break;

        }
        case 2: 
        {
          char sexo;
          bool sexoValido = false;

          while(!sexoValido)
          {
            printf("Digite o caracter para o sexo do Professor: \n");
            printf("M - Masculino\n");
            printf("F - Feminino\n");

            scanf(" %c", &sexo);
            switch (sexo)    
            {
              case 'M': listaProfessor[i].sexo = sexo; sexoValido = true; break;
              case 'F': listaProfessor[i].sexo = sexo; sexoValido = true; break;
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

bool removerProfessor(Pessoa listaProfessor[], int qtdProf, bool encontrado, int matriculaProf)
{
  for(int i = 0; i < qtdProf; i++)
  {
    if(matriculaProf == listaProfessor[i].matricula && listaProfessor[i].ativo)
    {
      encontrado = true;
      listaProfessor[i].ativo = false;
      for(int j = i; j < qtdProf - 1; j++)
      {
        listaProfessor[j].matricula = listaProfessor[j + 1].matricula;
        listaProfessor[j].sexo = listaProfessor[j + 1].sexo;
        listaProfessor[j].ativo = listaProfessor[j + 1].ativo;
      }      
      break;
    }                
  }
  return encontrado ? true : false;
}