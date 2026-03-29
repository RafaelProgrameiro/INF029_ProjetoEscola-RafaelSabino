#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

#define TAM_ALUNO 3
#define TAM_PROF 3
#define TAM_DISC 3
#define MAX_ALUNOS 60

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
  char cpf[12];
  bool ativo;
} Pessoa;

typedef struct {
  char nome[25];
  int cod;
  int semestre;
  int totalVagas;
  Pessoa professor;
  int matriculaAlunos[MAX_ALUNOS];
  int qtdAlunosMatriculados;
  bool ativo;
} Disciplina;

//prototipos
int menuGeral();
int menuPessoa(int opcao);
int menuDisciplina();
int menuAtualizarPessoa();
bool cadastrarPessoa(int opcao, Pessoa lista[], int qtd, int matricula);
void listarPessoas(Pessoa lista[], int qtdAluno);
bool atualizarPessoa(int opcao, Pessoa lista[], int qtd, bool encontrado, int matriculaPessoa);
bool removerPessoa(Pessoa lista[], int qtd, bool encontrado, int matriculaPessoa);
bool validaCpf(char cpf[]);
bool validaData(int dia, int mes, int ano);
void formataCpf(char cpf[]);
void formataData(int dia, int mes, int ano);
bool cadastrarDisciplina(Disciplina lista[], Pessoa listaProfessor[], int qtdProf, int qtd, int cod);
void listarDisciplinas(Disciplina lista[], int qtd);
bool removerDisciplina(Disciplina lista[], int qtd, bool encontrado, int codDisciplina);
bool inserirAlunoNaDisciplina(Disciplina lista[], Pessoa listaAluno[], int qtdAluno, int qtd, bool encontrado, int codDisciplina);
bool removerAlunoDaDisciplina(Disciplina lista[], int qtd, bool encontrado, int codDisciplina);

int main() {
  // configuracao da localizacao para acentuacao das palavras
	setlocale(LC_ALL, "Portuguese");

  //variaveis globais
  Pessoa listaAluno[TAM_ALUNO] = {0};
  Pessoa listaProfessor[TAM_PROF] = {0};
  Disciplina listaDisciplina[TAM_PROF] = {0};
  int qtdAluno = 0;
  int qtdProf = 0;
  int qtdDisc = 0;
  int opcao;
  bool sair = false;
  int matricula = 1;
  int cod = 1;

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
          opcaoAluno = menuPessoa(opcao);

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
          opcaoProfessor = menuPessoa(opcao);

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
      case 3:
      {
        bool sairDisciplina = false;
        int opcaoDisciplina;

        printf("Módulo Disciplina\n");

        while(!sairDisciplina)
        {
          opcaoDisciplina = menuDisciplina();

          switch(opcaoDisciplina)
          {
            case 0: sairDisciplina = true; break;
            case 1:
            {
              printf("\nListar Disciplinas\n");

              if(qtdDisc == 0)
              {
                printf("Lista de disciplinas está vazia.\n");
                break;
              }

              listarDisciplinas(listaDisciplina, qtdDisc);

              break;
            }
            case 2:
            {
              printf("\nCadastrar Disciplina\n");

              if(cadastrarDisciplina(listaDisciplina, listaProfessor, qtdProf, qtdDisc, cod))
              {
                cod++;
                qtdDisc++;
                printf("Disciplina cadastrada com sucesso\n");
              }
              else
                printf("Não foi possível realizar o cadastro\n");

              break;
            } 
            case 3:
            {
              int codDisciplina;
              bool encontrado = false;

              printf("\nRemover Disciplina\n");
              if(qtdDisc == 0)
              {
                printf("Lista de disciplinas está vazia.\n");
                break;
              }

              printf("Digite o código da disciplina: ");              
              scanf("%d", &codDisciplina);

              if(codDisciplina < 0)
              {
                printf("Código inválido\n");
                break;
              }

              encontrado = removerDisciplina(listaDisciplina, qtdDisc, encontrado, codDisciplina);

              if (encontrado)
              {
                printf("Disciplina removida com sucesso\n");
                qtdDisc--;
              }
              else
                printf("Código inexistente.\n");

              break;
            }
            case 4:
            {
              printf("\nMatricular aluno na disciplina\n");
              int codDisciplina;
              bool encontrado = false;

              if(qtdDisc == 0)
              {
                printf("Lista de disciplinas está vazia.\n");
                break;
              }

              printf("Digite o código da disciplina: ");              
              scanf("%d", &codDisciplina);

              if(codDisciplina < 0)
              {
                printf("Código inválido\n");
                break;
              }

              encontrado = inserirAlunoNaDisciplina(listaDisciplina, listaAluno, qtdAluno, qtdDisc, encontrado, codDisciplina);

              if (encontrado)
                printf("Aluno inserido na disciplina com sucesso\n");
              else
                printf("Não foi possivel inserir o aluno da disciplina\n");

              break;
            }
            case 5:
            {
              int codDisciplina;
              bool encontrado = false;

              printf("\nRemover aluno da disciplina\n");

              if(qtdDisc == 0)
              {
                printf("Lista de disciplinas está vazia.\n");
                break;
              }

              printf("Digite o código da disciplina: ");              
              scanf("%d", &codDisciplina);

              if(codDisciplina < 0)
              {
                printf("Código inválido\n");
                break;
              }

              encontrado = removerAlunoDaDisciplina(listaDisciplina, qtdDisc, encontrado, codDisciplina);
              
              if (encontrado)
                printf("Aluno removido da disciplina com sucesso\n");
              else
                printf("Não foi possivel remover o aluno da disciplina\n");

              break;
            }
            default: printf("Opção Inválida\n"); break;
          }
        }
        break;
      }
      default: printf("Opção Inválida\n"); break;
    }
  }

  //fim do main
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

int menuPessoa(int opcao)
{
  int opcaoPessoa;
  char pessoa[12] = {"Pessoas"};
  
  switch(opcao)
  {
  case 1: strcpy(pessoa, "Alunos"); break;
  case 2: strcpy(pessoa, "Professores"); break;
  default: printf("Opção inválida"); break;
  }

  printf("\n1 - Listar %s\n", pessoa);
  printf("2 - Cadastrar %s\n", pessoa);
  printf("3 - Atualizar %s\n", pessoa);
  printf("4 - Remover %s\n", pessoa);
  printf("0 - Voltar\n");

  scanf("%d", &opcaoPessoa);
  getchar();

  return opcaoPessoa;
}

int menuDisciplina()
{
  int opcaoDisc;
  printf("\n1 - Listar Disciplinas\n");
  printf("2 - Cadastrar Disciplina\n");
  printf("3 - Remover Disciplina\n");
  printf("4 - Inserir Aluno\n");
  printf("5 - Remover Aluno\n");
  printf("0 - Voltar\n");

  scanf("%d", &opcaoDisc);
  getchar();

  return opcaoDisc;
}

int menuAtualizarPessoa()
{
  int opcaoAtualizar;
  printf("\n1 - Atualizar nome\n");
  printf("2 - Atualizar sexo\n");
  printf("3 - Atualizar data de nascimento\n");
  printf("4 - Atualizar cpf\n");
  printf("0 - Cancelar\n");

  scanf("%d", &opcaoAtualizar);
  getchar();

  return opcaoAtualizar;
}

bool cadastrarPessoa(int opcao, Pessoa lista[], int qtd, int matricula)
{ 
  char pessoa[12] = {"Pessoas"};
  int  tam_lista;
  char nome[50];
  char sexo;
  bool sexoValido = false;
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

  printf("Digite o nome do %s: ", pessoa);
  fgets(nome, 50, stdin);

  while(!sexoValido)
  {
    printf("Digite o caracter válido para o sexo (maiúsculo): \n");
    printf("M - Masculino\n");
    printf("F - Feminino\n");

    scanf(" %c", &sexo);
    switch (sexo)    
    {
      case 'M': sexoValido = true; break;
      case 'F': sexoValido = true; break;
      default: printf("Entrada inválida.\n"); break;
    }
  }

  while(!dataValida)
  {
    printf("Digite o dia, mês e ano do nascimento (Ex: 16 10 1990): ");
    scanf("%d %d %d", &dia, &mes, &ano);

    dataValida = validaData(dia, mes, ano);
    if(!dataValida)
      printf("Entrada inválida\n");
  }

  getchar();

  while(!cpfValido)
  {
    printf("Digite o cpf (somente números): ");
    fgets(cpf, 12, stdin);

    cpfValido = validaCpf(cpf);
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

  return true;
}

void listarPessoas(Pessoa lista[], int qtd)
{  
  for(int i = 0; i < qtd; i++)
  { 
    if(lista[i].ativo)   
    {                  
      printf("\nNome: %s", lista[i].nome);
      printf("Matrícula: %d\n", lista[i].matricula);
      printf("Sexo: %c\n", lista[i].sexo);
      printf("Data de nascimento: ");
      formataData(lista[i].dataNascimento.dia, lista[i].dataNascimento.mes, lista[i].dataNascimento.ano);
      printf("\nCpf: ");
      formataCpf(lista[i].cpf);
      printf("\n------------\n");
    }
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

          printf("Digite o nome do %s: ", pessoa);
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
            printf("Digite o caracter válido para o sexo (maiúsculo): \n");
            printf("M - Masculino\n");
            printf("F - Feminino\n");

            scanf(" %c", &sexo);
            switch (sexo)    
            {
              case 'M': lista[i].sexo = sexo; sexoValido = true; break;
              case 'F': lista[i].sexo = sexo; sexoValido = true; break;
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

            dataValida = validaData(dia, mes, ano);
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

            cpfValido = validaCpf(cpf);
            if(!cpfValido)
              printf("O cpf digitado não tem 11 digitos.\n");
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

bool cadastrarDisciplina(Disciplina lista[], Pessoa listaProfessor[], int qtdProf, int qtd, int cod)
{ 
  char nome[25];
  int semestre;
  bool semestreValido = false;
  int totalVagas;
  bool totalVagasValido = false;
  int matriculaProf;
  bool profEncontrado = false;
  Pessoa professor;

  if(qtd == TAM_DISC)
  {
    printf("Lista de disciplinas já está cheia.\n");
    return false;
  }

  printf("Digite o nome do disciplina: ");
  fgets(nome, 25, stdin);

  strcpy(lista[qtd].nome, nome);

  while(!semestreValido)
  {
    printf("Digite o semestre da disciplina (mínimo: 1, máximo: 8): ");
    scanf("%d", &semestre);

    if(semestre <= 0 || semestre > 8)
    {
      printf("Número inválido para o semestre\n");
      return false;
    }
    semestreValido = true;
  }

  while(!totalVagasValido)
  {
    printf("Digite a quantidade de vagas para a disciplina (mínimo: 5, máximo: 60): ");
    scanf("%d", &totalVagas);
  
    if(totalVagas < 5 || totalVagas > 60)
    {
      printf("Número inválido para a quantidade de vagas\n");
      return false;
    }

    totalVagasValido = true;
  }

  while(!profEncontrado)
  {
    printf("Digite a matricula do professor da disciplina: ");
    scanf("%d", &matriculaProf);

    for(int i = 0; i < qtdProf; i++)
    {
      if(matriculaProf == listaProfessor[i].matricula)
      {
        profEncontrado = true;
        professor = listaProfessor[i];
        break;
      }
    }

    if(!profEncontrado)
    {
      printf("Não foi possível encontrar um professor com esta matrícula\n");
      return false;
    }
  }
  
  lista[qtd].cod = cod;
  lista[qtd].ativo = true;  
  lista[qtd].semestre = semestre;
  lista[qtd].totalVagas = totalVagas;
  lista[qtd].professor = professor;
  lista[qtd].qtdAlunosMatriculados = 0;
  for(int i = 0; i < MAX_ALUNOS; i++)
    lista[qtd].matriculaAlunos[i] = 0;

  return true;
}

void listarDisciplinas(Disciplina lista[], int qtd)
{  
  for(int i = 0; i < qtd; i++)
  { 
    if(lista[i].ativo)   
    {                  
      printf("\nNome: %s", lista[i].nome);
      printf("Código: %d\n", lista[i].cod);
      printf("Semestre: %dº\n", lista[i].semestre);
      printf("Total de vagas: %d\n", lista[i].totalVagas);
      printf("Total de alunos matriculados: %d\n", lista[i].qtdAlunosMatriculados);
      printf("Vagas Restantes: %d\n", lista[i].totalVagas - lista[i].qtdAlunosMatriculados);
      printf("Professor: %s", lista[i].professor.nome);
      printf("\n------------\n");
    }
  }
}

bool removerDisciplina(Disciplina lista[], int qtd, bool encontrado, int codDisciplina)
{  
  for(int i = 0; i < qtd; i++)
  {
    if(codDisciplina == lista[i].cod && lista[i].ativo)
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

bool inserirAlunoNaDisciplina(Disciplina lista[], Pessoa listaAluno[], int qtdAluno, int qtd, bool encontrado, int codDisciplina)
{
  int matriculaAluno;
  int posicao;
        
  for(int i = 0; i < qtd; i++)
  {
    if(codDisciplina == lista[i].cod && lista[i].ativo)
    {
      encontrado = true;

      if(lista[i].qtdAlunosMatriculados >= lista[i].totalVagas)
      {
        printf("A disciplina já está cheia\n");
        return false;
      }

      printf("Digite a matrícula do aluno que deseja inserir na disciplina: ");
      scanf("%d", &matriculaAluno);
      
      bool alunoEncontrado = false;

      for(int j = 0; j < qtdAluno; j++)
      {
        if(matriculaAluno == listaAluno[j].matricula)
        {
          alunoEncontrado = true;
          break;
        }
      }

      if(!alunoEncontrado)
      {
        printf("Nenhum aluno com esta matricula\n");
        return false;
      }

      for(int k = 0; k < lista[i].qtdAlunosMatriculados; k++)
      {
        if(lista[i].matriculaAlunos[k] == matriculaAluno)
        {
          printf("Aluno já está matriculado na disciplina\n");
          return false;
        }
      }
      
      posicao = lista[i].qtdAlunosMatriculados;
      lista[i].matriculaAlunos[posicao] = matriculaAluno;
      lista[i].qtdAlunosMatriculados++; 
      
      break;
    }
  }

  if(!encontrado)  
    printf("Código de disciplina inválido\n");

  return encontrado ? true : false;
}

bool removerAlunoDaDisciplina(Disciplina lista[], int qtd, bool encontrado, int codDisciplina)
{
  int matriculaAluno;
  int posicao;

  for(int i = 0; i < qtd; i++)
  {
    if(codDisciplina == lista[i].cod && lista[i].ativo)
    {
      encontrado = true;

      printf("Digite a matrícula do aluno que deseja remover da disciplina: ");
      scanf("%d", &matriculaAluno);
      
      bool alunoEncontrado = false;

      for(int j = 0; j < lista[i].qtdAlunosMatriculados; j++)
      {
        if(matriculaAluno == lista[i].matriculaAlunos[j])
        {
          alunoEncontrado = true;
          posicao = j;
          break;
        }
      }

      if(!alunoEncontrado)
      {
        printf("Nenhum aluno com esta matricula está matriculado na disciplina\n");
        return false;
      }

      lista[i].matriculaAlunos[posicao] = 0;

      for(int j = posicao; j < lista[i].qtdAlunosMatriculados - 1; j++)
        lista[j] = lista[j + 1];

      lista[i].qtdAlunosMatriculados--;

      break;
    }
  }

  if(!encontrado)  
    printf("Código de disciplina inválido\n");

  return encontrado ? true : false;
}