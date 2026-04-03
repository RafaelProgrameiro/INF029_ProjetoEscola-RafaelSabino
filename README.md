# Sistema Escola - INF029

Este projeto consiste em um sistema de gerenciamento escolar desenvolvido em linguagem C como atividade extra para a disciplina de Laboratório de Programação (INF029) do curso de Graduação Tecnológica em Análise e Desenvolvimento de Sistemas (ADS) no IFBA.

## Informações Gerais
* **Instituição**: IFBA - Instituto Federal de Educação, Ciência e Tecnologia da Bahia.
* **Departamento**: Departamento de Ciência da Computação.
* **Disciplina**: INF029 - Laboratório de Programação.
* **Professor**: Prof. Renato Novais.
* **Data do Requisito**: 17/04/2026.
* **Aluno**: Rafael Sabino de Sousa.

## Funcionalidades Solicitadas
O sistema permite o cadastro completo (incluir, excluir e atualizar) das seguintes entidades:

* **Alunos**: Matrícula, Nome, Sexo, Data de Nascimento e CPF.
* **Professores**: Matrícula, Nome, Sexo, Data de Nascimento e CPF.
* **Disciplinas**: Nome, Código, Semestre e Professor responsável.
    * **Gerenciamento de alunos**: Inserir ou excluir alunos de uma disciplina específica.

## Relatórios e Buscas
O programa gera diversos relatórios para suporte à gestão escolar:

* **Listagens Gerais**: Exibição de Alunos, Professores e Disciplinas cadastrados.
* **Filtros por Sexo**: Listar alunos ou professores filtrados por Masculino/Feminino.
* **Ordenação**: Listar pessoas ordenadas por Nome ou por Data de Nascimento.
* **Busca por Texto**: Localizar pessoas (professor/aluno) a partir de uma string de busca com no mínimo três letras.
* **Datas e Vagas**:
    * Lista de aniversariantes do mês.
    * Lista de disciplinas que extrapolam 40 vagas.
    * Lista de alunos matriculados em menos de 3 disciplinas.

## Como Compilar e Executar

### Compilação
Utilize o GCC para compilar todos os módulos do sistema:
```bash
gcc main.c pessoa.c disciplina.c utils.c menu.c relatorio.c -o sistema_escola
```
### Execução
```bash
./sistema_escola
```