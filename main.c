#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include "escola.h"
#include "pessoa.h"
#include "disciplina.h"
#include "menu.h"
#include "relatorio.h"

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
      case 4:
      {
        bool sairRelatorio = false;
        int opcaoRelatorio;

        printf("Módulo Relatórios\n");

        while(!sairRelatorio)
        {
          opcaoRelatorio = menuRelatorios();
          switch(opcaoRelatorio)
          {
            case 0: sairRelatorio = true; break;
            case 1: 
            {
              int opcaoPessoa;
              bool opcaoValida = false;

              while(!opcaoValida)
              {
                printf("\nListar Alunos/Professores\n");
                printf("1 - Listar Alunos\n");
                printf("2 - Listar Professores\n");
                printf("0 - Voltar\n");
                scanf("%d", &opcaoPessoa);

                switch(opcaoPessoa)
                {
                  case 0: opcaoValida = true; break;
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
                    printf("\nListar Professores\n");

                    if(qtdAluno == 0)
                    {
                      printf("Lista de professores está vazia.\n");
                      break;
                    }
                    
                    listarPessoas(listaProfessor, qtdProf);
                    
                    break;
                  }
                  default: printf("Opção inválida\n"); break;
                }
              }
              break;
            }
            case 2:
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
            case 3:
            {
              int codDisciplina;
              bool encontrado = false;
              
              printf("\nDetalhar Disciplina\n");

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

              encontrado = detalharDisciplina(listaDisciplina, listaAluno, qtdAluno, qtdDisc, encontrado, codDisciplina);
              
              if (!encontrado)
                printf("Não foi encontrar a disciplina informada\n");

              break;
            }
            case 4:
            {
              int opcaoPessoa;
              bool opcaoValida = false;

              printf("\nListar Alunos/Professores por sexo\n");

              while(!opcaoValida)
              {                
                printf("1 - Listar Alunos\n");
                printf("2 - Listar Professores\n");
                printf("0 - Voltar\n");
                scanf("%d", &opcaoPessoa);

                switch(opcaoPessoa)
                {
                  case 0: opcaoValida = true; break;
                  case 1:
                  {                           
                    int opcaoSexo;
                    bool opcaoSexoValida = false;
                    char sexo;
                    char sexoTexto[10] = "Masculino";

                    printf("\nListar Alunos por sexo\n");

                    if(qtdAluno == 0)
                    {
                      printf("Lista de alunos está vazia.\n");
                      break;
                    }

                    while(!opcaoSexoValida)
                    {
                      printf("\nSexo\n");
                      printf("1 - Masculino\n");
                      printf("2 - Feminino\n");
                      printf("0 - Voltar\n");
                      scanf("%d", &opcaoSexo);

                      switch(opcaoSexo)
                      {
                        case 0: opcaoSexoValida = true; break;
                        case 1: sexo = 'M'; opcaoSexoValida = true; break;
                        case 2: sexo = 'F'; opcaoSexoValida = true; strcpy(sexoTexto, "Feminino"); break;
                        default: printf("Opção inválida\n"); break;                        
                      }                      
                    }                   
                    printf("Alunos do sexo: '%s'\n", sexoTexto);
                    listarPessoasPorSexo(listaAluno, qtdAluno, sexo);
                    
                    break;
                  }
                  case 2: 
                  {
                    int opcaoSexo;
                    bool opcaoSexoValida = false;
                    char sexo;
                    char sexoTexto[10] = "Masculino";

                    printf("\nListar Professores por sexo\n");

                    if(qtdProf == 0)
                    {
                      printf("Lista de professores está vazia.\n");
                      break;
                    }

                    while(!opcaoSexoValida)
                    {
                      printf("\nSexo\n");
                      printf("1 - Masculino\n");
                      printf("2 - Feminino\n");
                      printf("0 - Voltar\n");
                      scanf("%d", &opcaoSexo);

                      switch(opcaoSexo)
                      {
                        case 0: opcaoSexoValida = true; break;
                        case 1: sexo = 'M'; opcaoSexoValida = true; break;
                        case 2: sexo = 'F'; opcaoSexoValida = true; strcpy(sexoTexto, "Feminino"); break;
                        default: printf("Opção inválida\n"); break;                        
                      }                      
                    }                   
                    
                    printf("Professores do sexo: '%s'\n", sexoTexto);
                    listarPessoasPorSexo(listaProfessor, qtdProf, sexo);
                    
                    break;
                  }
                  default: printf("Opção inválida\n"); break;
                }
              }
              break;
            }
            case 5:
            {
              printf("\nListar Alunos/Professores em Ordem Alfabética\n");

              int opcaoPessoa;
              bool opcaoValida = false;

              while(!opcaoValida)
              {
                printf("\nListar Alunos/Professores\n");
                printf("1 - Listar Alunos\n");
                printf("2 - Listar Professores\n");
                printf("0 - Voltar\n");
                scanf("%d", &opcaoPessoa);

                switch(opcaoPessoa)
                {
                  case 0: opcaoValida = true; break;
                  case 1:
                  {                           
                    printf("\nListar Alunos\n");                    

                    if(qtdAluno == 0)
                    {
                      printf("Lista de alunos está vazia.\n");
                      break;
                    }                    
                    
                    listarPessoasPorOrdemAlfabetica(listaAluno, qtdAluno);
                    
                    break;
                  }
                  case 2:
                  {                           
                    printf("\nListar Professores\n");                    

                    if(qtdProf == 0)
                    {
                      printf("Lista de professores está vazia.\n");
                      break;
                    }                    
                    
                    listarPessoasPorOrdemAlfabetica(listaProfessor, qtdProf);
                    
                    break;
                  }
                  default: printf("Opção inválida\n"); break;
                }
              }
              break;
            }
            case 6: 
            {
              printf("\nListar Alunos/Professores em Ordem Alfabética\n");

              int opcaoPessoa;
              bool opcaoValida = false;

              while(!opcaoValida)
              {
                printf("\nListar Alunos/Professores\n");
                printf("1 - Listar Alunos\n");
                printf("2 - Listar Professores\n");
                printf("0 - Voltar\n");
                scanf("%d", &opcaoPessoa);

                switch(opcaoPessoa)
                {
                  case 0: opcaoValida = true; break;
                  case 1:
                  {                           
                    printf("\nListar Alunos\n");

                    if(qtdAluno == 0)
                    {
                      printf("Lista de alunos está vazia.\n");
                      break;
                    }                    
                    
                    listarPessoasPorDataNascimento(listaAluno, qtdAluno);
                    
                    break;
                  }
                  case 2:
                  {                           
                    printf("\nListar Professores\n");                    

                    if(qtdProf == 0)
                    {
                      printf("Lista de professores está vazia.\n");
                      break;
                    }                    
                    
                    listarPessoasPorDataNascimento(listaProfessor, qtdProf);
                    
                    break;
                  }
                  default: printf("Opção inválida\n"); break;
                }
              }
              break;
            }
            case 7:
            {
              int mes;
              printf("\nListar aniversariantes do mês\n");

              printf("Digite o mês (1 a 12): ");
              scanf("%d", &mes);

              if(mes < 0 || mes > 12)
              {
                printf("Mês inválido\n");
                break;
              }

              listarAniversariantesDoMes(listaAluno, listaProfessor, qtdAluno, qtdProf, mes);

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

  printf("Sistema encerrado.\n");
  return 0;
}
