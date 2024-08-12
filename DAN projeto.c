#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

//----------------------------------------------------------------
// Universidade IFMA
// Sistemas de Informacao - Segundo periodo
// Disciplina de Linguagem de Programa��o I
// Professor: Daniel
// Alunos: Daniel Moura e Robson da Silva
// Projeto A - Cria��o de Software para Controle de Obras
//----------------------------------------------------------------

#define STRLEN 30
#define MAX 1000
// variavel global para quantidade de termos das strings

typedef struct
{
    char nome[STRLEN];
    char Endereco[STRLEN];
    char DataNascimento[STRLEN];
    char cep[STRLEN];
    char email[STRLEN];
    char telefone[STRLEN];
    char celular[STRLEN];
} Cliente;
// struct Cliente com o tamanho da string
// definida na variavel global

typedef struct
{
    char nome[STRLEN];
    char matricula[STRLEN];
    char dataDeEmissao[STRLEN];
    char cargo[STRLEN];
} Funcionarios;
// struct Funcionario com o tamanho da string
// definida na variavel global

typedef struct
{
    int dataDiaInicio;
    int dataMesInicio;
    int dataAnoInicio;
    int dataDiaTermino;
    int dataMesTermino;
    int dataAnoTermino;
} Data;
// struct Data que � uma struct unica visto que
// h� apenas uma data de come�o e final (que eh o previsto de termino)
// caso haja alguma mudan�a, dever� ser alterado no menu de cadastro

typedef struct
{
    char idDaObra[STRLEN];
    char nomeDaObra[STRLEN];
    char EngenheiroResponsavel[STRLEN];
    Data data;
} Obras;
// definicao da struct de obra
// com uma struct dentro dela para
// armazenar datas

//----------------------------------------------------------------
int quantCliente, quantObra, quantFuncionario;
long int endereco;
// variaveis globais

//----------------------------------------------------------------

Cliente cliente[MAX];
Funcionarios funcionario[MAX];
Obras obra[MAX];
// structs declaradas de maneira global
// de modo a serem acessadas por quaisquer funcoes
//----------------------------------------------------------------
FILE *arqCliente, *arqFuncionario, *arqObra;
// declara a variavel de ponteiro que aponta pro arquivo

//----------------------------------------------------------------
void cadastro_cliente();
void printar_cliente();
void cadastro_funcionario();
void printar_funcionario();
void cadastro_Obra();
void printar_Obra();
void salvarArquivoCliente();
void salvarArquivoFuncionario();
void salvarArquivoObra();
void AlterarCliente();
void AlterarFuncionario();
void AlterarObra();
void Salvar();
void alterar_cadastros();
void ExibirStatusObra();
void Relatorios();
void Cadastro();
void Menu_principal();
void limpar_buffer();

// Consome todo o buffer do teclado

// chamada de funcoes

//----------------------------------------------------------------
// cadastro e prints de relatorio
int main()
{

    Menu_principal();
}

void cadastro_cliente(int quantCliente, FILE *arqCliente)
{
    // cadastro de novos clientes
    Cliente novoCliente;
    //  cria um novo parametro struct que vai

    Cliente *p_cliente = &cliente[quantCliente];
    // cria um ponteiro de struct para percorrer
    // o vetor novoCliente para armazenar um novo cliente
    // quando for necessario

    int flag = 0;
    // flagzinha pra ver se esse mesmo item (inicial) esta repetido
    fflush(stdin);

    for (int i = 0; i < quantCliente; i++)
    {
        // le os dados do usuario e joga no vetor de struct original
        fflush(stdin);
        // limpar_buffer();
        printf("Nome do cliente: \n");
        fgets(cliente[i].nome, STRLEN, stdin);
        // limpar_buffer();
        fflush(stdin);

        printf("Endereco: \n");
        fgets(cliente[i].Endereco, STRLEN, stdin);
        limpar_buffer();
        // fflush(stdin);

        printf("data de Nasc.: \n");
        fgets(cliente[i].DataNascimento, STRLEN, stdin);
        // limpar_buffer();
        fflush(stdin);

        printf("CEP: \n");
        fgets(cliente[i].cep, STRLEN, stdin);
        // limpar_buffer();
        fflush(stdin);

        printf("Email: \n");
        fgets(cliente[i].email, STRLEN, stdin);
        // limpar_buffer();
        fflush(stdin);

        printf("Telefone: \n");
        fgets(cliente[i].telefone, STRLEN, stdin);
        // limpar_buffer();
        fflush(stdin);

        printf("Celular: \n");
        fgets(cliente[i].celular, STRLEN, stdin);
        // limpar_buffer();
        fflush(stdin);

        // novoCliente.nome = cliente[i].nome;
        //  limpar_buffer();

        for (int j = 0; j < quantCliente; j++)
        {
            if (strcmp(novoCliente.nome, cliente[j].nome) == 0)
            {
                flag++; // flag pra achar repeticoes
                // se a flag for = 0 nao h� erro
                // se a flag for > 0 h� erro
            }
            if (flag != 0) // se for achada alguma repeticao entra no if
            {
                system("cls"); // printa o erro e limpa a tela
                printf("Erro: o Nome desse Cliente ja existe na database!!\n");
                printf("aperte qualquer tecla pra retornar ao menu.\n");
                limpar_buffer(); // limpa o buffer de memoria
                // evita o erro por \n
                return;
                // nao retorna nada pois a funcao eh void
            }
        }

        // Atribuindo os dados inseridos pelo usuario na posicao atual do ponteiro
        *p_cliente = novoCliente;

        // Incrementando o ponteiro para apontar para a proxima posicao
        p_cliente++;
    }
    // cadastro do novo cliente(caso o vetor de struct tenha sido
    // preenchido anteriormente)
}

// funcao para ler dados do cliente e gravar na struct

// ----------------------------------------------------------------

void printar_cliente(int quantCliente, FILE *arqCliente)
{
    // relatorio do cliente

    // imprime o relatorio de funcionario
    arqCliente = fopen("Cliente.txt", "r");
    // le arquivo como somente leitura
    if (arqCliente == NULL)
    {
        printf("Sem relatorios no momento...\n\n");
        // se o arquivo nao existir ou estiver sem nada nao vai imprimir
        fclose(arqCliente);
        // fecha o arquivo
    }
    else
    {

        for (int i = 0; i < quantCliente; i++)
        {
            printf("Cliente %d:\n", i + 1);
            printf("Nome do cliente: \n");
            printf("%s\n", cliente[i].nome);
            printf("Endere�o do cliente: \n");
            printf("%s\n", cliente[i].Endereco);
            printf("data de nascimento do cliente: \n");
            printf("%s\n", cliente[i].DataNascimento);
            printf("CEP do cliente: \n");
            printf("%s\n", cliente[i].cep);
            printf("Email do cliente: \n");
            printf("%s\n", cliente[i].email);
            printf("Telefone do cliente: \n");
            printf("%s\n", cliente[i].telefone);
            printf("Celular do cliente: \n");
            printf("%s\n", cliente[i].celular);
            // printa na tela os dados requeridos e da um fflush na saida
        }
    }
}

void cadastro_funcionario(int quantFuncionario, FILE *arqFuncionario)
{
    // cadastro de funcionario

    Funcionarios novoFuncionario;
    //  cria um novo parametro struct que vai
    // ajudar a preencher o vetor de struct original

    Funcionarios *p_funcionario = &funcionario[quantCliente];
    // cria um ponteiro de struct para percorrer
    // o vetor novoCliente para armazenar um novo cliente
    // quando for necessario

    int flag = 0;

    for (int i = 0; i < quantFuncionario; i++)
    {
        // recebe no vetor de struct original os dados do funcionario
        fflush(stdin);
        printf("Nome do Funcionario: \n");
        fgets(funcionario[i].nome, STRLEN, stdin);
        fflush(stdin);

        printf("Matricula: \n");
        fgets(funcionario[i].matricula, STRLEN, stdin);
        fflush(stdin);

        printf("data de Emissao: \n");
        fgets(funcionario[i].dataDeEmissao, STRLEN, stdin);
        fflush(stdin);

        printf("Cargo: \n");
        fgets(funcionario[i].cargo, STRLEN, stdin);
        fflush(stdin);

        for (int j = 0; j < quantFuncionario; j++) // novo for pra comparacao
        {
            if (strcmp(funcionario[i].nome, funcionario[j].nome) == 0)
            {
                flag++; // flag pra achar repeticoes
                // se a flag for = 0 nao h� erro
                // se a flag for > 0 h� erro
            }
            if (flag != 0) // se for achada alguma repeticao entra no if
            {
                system("cls"); // printa o erro e limpa a tela
                printf("Erro: o Nome desse Funcionario ja existe na database!!\n");
                printf("aperte qualquer tecla pra retornar ao menu.\n");
                limpar_buffer(); // limpa o buffer
                return;
            }
        }
        // Atribuindo os dados inseridos pelo usuario na posicao atual do ponteiro
        *p_funcionario = novoFuncionario;

        // Incrementando o ponteiro para apontar para a proxima posicao
        p_funcionario++;
    }
}

void printar_funcionario(int quantCliente, FILE *arqFuncionario)
{
    // imprime o relatorio de funcionario
    arqFuncionario = fopen("Funcionario.txt", "r");
    // le o arquivo como somente leitura
    if (arqFuncionario == NULL)
    {
        printf("Sem relatorios no momento...\n\n");
        fclose(arqFuncionario);
        // se nao houver arquivo fecha o arquivo e printa a mensagem de erro
    }
    else
    {
        for (int i = 0; i < quantFuncionario; i++)
        {
            printf("Funcionario %d:\n", i + 1);
            printf("Nome: %s", cliente[i].nome);
            printf("Matricula: %s", funcionario[i].matricula);
            printf("Data de Emissao: %s", funcionario[i].dataDeEmissao);
            printf("Cargo: %s", funcionario[i].cargo);

            // printa na tela os dados requeridos e da um fflush na saida
        }
    }
}

void cadastro_Obras(int quantObra, FILE *arqObra)
{
    // cadastro da obra
    Obras novaObra;
    //  cria um novo parametro struct que vai
    // receber provisoriamente os dados de imput
    //  do usuario

    Obras *p_obra = &obra[quantObra];
    // cria um ponteiro de struct para percorrer
    // o vetor novoCliente para armazenar um novo cliente
    // quando for necessario

    int flag = 0;
    // flagzinha pra ver se esse mesmo item (inicial) esta repetido

    for (int i = 0; i < quantObra; i++)
    {
        // recebe os dados da obra no vetor de struct original
        printf("Id da Obra: \n");
        fgets(obra[i].idDaObra, STRLEN, stdin);
        fflush(stdin);

        printf("Nome da Obra: \n");
        fgets(obra[i].nomeDaObra, STRLEN, stdin);
        fflush(stdin);

        printf("Engenheiro Resposavel: \n");
        fgets(obra[i].EngenheiroResponsavel, STRLEN, stdin);
        fflush(stdin);

        // Datas do Inicio
        printf("Digite o Dia: \n");
        scanf("%d", &obra[i].data.dataDiaInicio);
        printf("Digite o Mes: \n");
        scanf("%d", &obra[i].data.dataMesInicio);
        printf("Digite o Ano: \n");
        scanf("%d", &obra[i].data.dataAnoInicio);
        printf("Digite o Dia do Termino: \n");
        fflush(stdin);
        // Datas do Termino
        scanf("%d", &obra[i].data.dataDiaTermino);
        printf("Digite o Mes do Termino: \n");
        scanf("%d", &obra[i].data.dataMesTermino);
        printf("Digite o Ano do Termino: \n");
        scanf("%d", &obra[i].data.dataAnoTermino);
        fflush(stdin);

        for (int j = 0; j < quantCliente; j++)
        {
            if (strcmp(novaObra.idDaObra, obra[j].idDaObra) == 0)
            {
                flag++;
                // flag pra achar repeticoes
                // se a flag for = 0 nao h� erro
                // se a flag for > 0 h� erro
            }
            if (flag != 0) // achando erro entra no if
            {
                system("cls"); // limpa a tela e printa o erro
                printf("Erro: O Id da obra especificado nao existe!!\n");
                printf("aperte qualquer tecla pra retornar ao menu.\n");
                limpar_buffer();
                // printa o erro e limpa o buffer do teclado para evitar
                // erro por \n
                return;
                // nao retorna nada pois a funcao eh void
            }
        }
        // Atribuindo os dados inseridos pelo usuario na posicao atual do ponteiro
        *p_obra = novaObra;

        // Incrementando o ponteiro para apontar para a proxima posicao
        p_obra++;
    }
    // cadastro do novo cliente(caso o vetor de struct tenha sido
    // preenchido anteriormente)
}

void printar_Obra(int quantObra, FILE *arqObra)
{
    // imprime o relatorio de obra
    arqObra = fopen("nomeArquivo.txt", "r");
    if (arqObra == NULL) // verifica se o arquivo nao existe ou se nao esta preenchido
    {
        printf("Sem relatorios no momento...\n\n");
        // se estiver printa a mensagem e fecha o arquivo
        fclose(arqObra);
    }
    else
    {

        for (int i = 0; i < quantObra; i++)
        {
            // printa os dados requeridos na tela
            printf("Funcionario %d:\n", i + 1);
            printf("%s\n", obra[i].idDaObra);
            printf("Nome da Obra: \n");
            printf("%s\n", obra[i].nomeDaObra);
            printf("Engenheiro Responsavel: \n");
            printf("%s\n", obra[i].EngenheiroResponsavel);
            printf("data de inicio: \n");
            printf("%d /", obra[i].data.dataDiaInicio);
            printf(" %d /", obra[i].data.dataMesInicio);
            printf(" %d\n", obra[i].data.dataAnoInicio);
            printf("data de Termino: \n");
            printf("%d /", obra[i].data.dataDiaTermino);
            printf(" %d /", obra[i].data.dataMesTermino);
            printf(" %d\n", obra[i].data.dataAnoTermino);
        }
    }
    // nao retorna nada pois a funcao eh void
}

//----------------------------------------------------------------
// manipulacao de arquivo
void salvarArquivoCliente(int quantCliente, FILE *arqCliente)
{

    arqCliente = fopen("Cliente.txt", "a");
    // salva o documento come�ando da ultima posicao
    // pois assim nao sobrescreve o que ja foi utilizado antes
    if (arqCliente)
    {
        fprintf(arqCliente, "%d\n", quantCliente);
        for (int i = 0; i < quantCliente; i++)
        {
            // joga os dados digitados pelo usuario
            // dentro do arquivo
            fprintf(arqCliente, "%s\n", cliente[i].nome);
            fprintf(arqCliente, "%s\n", cliente[i].Endereco);
            fprintf(arqCliente, "%s\n", cliente[i].DataNascimento);
            fprintf(arqCliente, "%s\n", cliente[i].cep);
            fprintf(arqCliente, "%s\n", cliente[i].email);
            fprintf(arqCliente, "%s\n", cliente[i].telefone);
            fprintf(arqCliente, "%s\n", cliente[i].celular);
        }

        fclose(arqCliente); // fecha o arquivo para liberar memoria
    }
    else
    {
        printf("Arquivo nao foi salvo!!!\n");
        // se o ponteiro estiver com lixo de memoria ou for invalido
        // printa erro
    }
}

void salvarArquivoFuncionario(int quantFuncionario, FILE *arqFuncionario)
{

    arqFuncionario = fopen("Funcionario.txt", "a");
    // salva o documento come�ando da ultima posicao
    // pois assim nao sobrescreve o que ja foi utilizado antes

    if (arqFuncionario) // verifica se a variavel quantidade de funcionarios eh verdadeira
    {
        fprintf(arqFuncionario, "%d\n", quantFuncionario);
        for (int i = 0; i < quantFuncionario; i++)
        {
            // joga os dados digitados pelo usuario
            // dentro do arquivo
            fprintf(arqFuncionario, "%s\n", funcionario[i].nome);
            fprintf(arqFuncionario, "%s\n", funcionario[i].matricula);
            fprintf(arqFuncionario, "%s\n", funcionario[i].dataDeEmissao);
            fprintf(arqFuncionario, "%s\n", funcionario[i].cargo);
        }

        fclose(arqFuncionario); // fecha o arquivo para liberar memoria
    }
    else
    {
        printf("Arquivo nao foi salvo!!!\n");
        // else do if, se nao verdadeira a condicao
        // for fecha a funcao
    }
}

void salvarArquivoObra(int quantObra, FILE *arqObra)
{

    arqObra = fopen("Obra.txt", "a");
    // salva o documento come�ando da ultima posicao
    // pois assim nao sobrescreve o que ja foi utilizado antes

    if (arqObra) // verifica se a variavel quantidade de funcionarios eh verdadeira
    {
        fprintf(arqObra, "%d\n", quantObra);
        for (int i = 0; i < quantObra; i++)
        {
            // joga os dados digitados pelo usuario
            // dentro do arquivo
            fprintf(arqObra, "%s\n", obra[i].idDaObra);
            fprintf(arqObra, "%s\n", obra[i].nomeDaObra);
            fprintf(arqObra, "%s\n", obra[i].EngenheiroResponsavel);
            fprintf(arqObra, "%d\n", obra[i].data.dataDiaInicio);
            fprintf(arqObra, "%d\n", obra[i].data.dataMesInicio);
            fprintf(arqObra, "%d\n", obra[i].data.dataAnoInicio);
            fprintf(arqObra, "%d\n", obra[i].data.dataDiaTermino);
            fprintf(arqObra, "%d\n", obra[i].data.dataMesTermino);
            fprintf(arqObra, "%d\n", obra[i].data.dataAnoTermino);
        }

        fclose(arqObra); // fecha o arquivo para liberar memoria
    }
    else
    {
        printf("Arquivo nao foi salvo!!!\n");
        // else do if, se nao verdadeira a condicao
        // for fecha a funcao
    }
}

//----------------------------------------------------------------
// alteracoes cadastrais
void AlterarCliente(FILE *arqCliente)
{
    // int tamanho = strlen(comparacao);

    arqCliente = fopen("Cliente.txt", "r");

    if (arqCliente == NULL)
    {
        printf("nenhum cliente cadastrado\n");
        system("pause");
        fclose(arqCliente);
    }
    else
    {
        for (int i = 0; i < quantCliente; i++)
        {

            arqCliente = fopen("Cliente.txt", "w");
            // segue com as alteracoes cadastrais
            // dadas pelo user
            fflush(stdin); // limpa buffer se houver alguma coisa ja sera deletada
            printf("Digite as alteracoes: \n\n");
            printf("Nome do cliente: \n");
            fgets(cliente[i].nome, STRLEN, stdin);
            fflush(stdin);

            printf("Endereco: \n");
            fgets(cliente[i].Endereco, STRLEN, stdin);
            fflush(stdin);

            printf("data de Nasc.: \n");
            fgets(cliente[i].DataNascimento, STRLEN, stdin);
            fflush(stdin);

            printf("CEP: \n");
            fgets(cliente[i].cep, STRLEN, stdin);
            fflush(stdin);

            printf("Email: \n");
            fgets(cliente[i].email, STRLEN, stdin);
            fflush(stdin);

            printf("Telefone: \n");
            fgets(cliente[i].telefone, STRLEN, stdin);
            fflush(stdin);

            printf("Celular: \n");
            fgets(cliente[i].celular, STRLEN, stdin);
            fflush(stdin);
        }
    }
}

void AlterarFuncionario(FILE *funcionarioS2)
{

    funcionarioS2 = fopen("Funcionario.txt", "r");

    if (funcionarioS2 == NULL)
    {
        printf("nenhum cliente cadastrado\n");
        system("pause");
        fclose(funcionarioS2);
    }
    else
    {
        for (int i = 0; i < quantFuncionario; i++)
        {
            funcionarioS2 = fopen("Funcionario.txt", "w");
            // alteracoes cadastrais
            // dadas pelo user
            fflush(stdin); // limpa o buffer
            printf("Digite as alteracoes:\n\n");
            printf("Nome do Funcionario: \n");
            fgets(funcionario[i].nome, STRLEN, stdin);
            fflush(stdin);

            printf("Matricula: \n");
            fgets(funcionario[i].matricula, STRLEN, stdin);
            fflush(stdin);

            printf("data de Emissao: \n");
            fgets(funcionario[i].dataDeEmissao, STRLEN, stdin);
            fflush(stdin);

            printf("Cargo: \n");
            fgets(funcionario[i].cargo, STRLEN, stdin);
            fflush(stdin);
        }
    }
}

void AlterarObra(FILE *ObraS2)
{

    ObraS2 = fopen("Obra.txt", "r");

    if (ObraS2 == NULL)
    {
        printf("nenhum cliente cadastrado\n");
        system("pause");
        fclose(ObraS2);
    }
    else
    {
        for (int i = 0; i < quantObra; i++)
        {
            ObraS2 = fopen("Obra.txt", "w");

            fflush(stdin); // limpa o buffer
            // segue com as alteracoes cadastrais
            // dadas pelo user
            printf("Digite as alteracoes:\n\n");
            printf("Id da Obra: \n");
            fgets(obra[i].idDaObra, STRLEN, stdin);
            fflush(stdin);

            printf("Nome da Obra: \n");
            fgets(obra[i].nomeDaObra, STRLEN, stdin);
            fflush(stdin);

            printf("Engenheiro Resposavel: \n");
            fgets(obra[i].EngenheiroResponsavel, STRLEN, stdin);
            fflush(stdin);
            // Datas do Inicio
            printf("Digite o Dia: \n");
            scanf("%d", &obra[i].data.dataDiaInicio);

            printf("Digite o Mes: \n");
            fscanf("%d", &obra[i].data.dataMesInicio);
            printf("Digite o Ano: \n");
            fscanf("%d", &obra[i].data.dataAnoInicio);
            printf("Digite o Dia do Termino: \n");
            fflush(stdin);
            // Datas do Termino
            fscanf("%d", &obra[i].data.dataDiaTermino);
            printf("Digite o Mes do Termino: \n");

            fscanf("%d", &obra[i].data.dataMesTermino);
            printf("Digite o Ano do Termino: \n");

            fscanf("%d", &obra[i].data.dataAnoTermino);
            fflush(stdin);
        }
    }
}

int Status(Obras obra[], FILE *arquivo, int dia, int mes, int ano)
{
    fseek(arquivo, MAX, SEEK_SET);
    fread(obra, sizeof(obra), quantObra, arquivo);

    for (int i = 0; i < quantObra; i++)
    {
        if (obra[i].data.dataDiaTermino <= dia && obra[i].data.dataMesTermino <= mes && obra[i].data.dataAnoTermino <= ano)
        {
            return 1; // Obra dentro do prazo
        }
        else if (obra[i].data.dataDiaTermino > dia)
        {
            return 0; // Obra atrasada
        }
        else if (obra[i].data.dataDiaTermino == dia && obra[i].data.dataMesTermino > mes)
        {
            return 0; // Obra atrasada
        }
        else if (obra[i].data.dataDiaTermino == dia && obra[i].data.dataMesTermino == mes && obra[i].data.dataAnoTermino > ano)
        {
            return 0; // Obra atrasada
        }
    }

    return 0; // Obra atrasada (caso nenhuma obra esteja dentro do prazo)
}

int StatusPrevisto(Obras obra[], FILE *arquivo, int ano, int mes, int dia)
{
    // Compara a data inicio com o input do usuario
    // para saber se a obra esta dentro da data prevista
    // ou se ainda nao comecou
    fseek(arquivo, 0, SEEK_SET);
    fread(obra, sizeof(obra), quantObra, arquivo);

    for (int i = 0; i < quantObra; i++)
    {
        if (dia < obra[i].data.dataDiaInicio && mes <= obra[i].data.dataMesInicio && ano <= obra[i].data.dataAnoInicio)
        {
            return 1; // Obra dentro da data prevista ou ainda não iniciada
        }
        else if (dia > obra[i].data.dataDiaInicio)
        {
            return 0; // Obra em andamento ou já finalizada
        }
        else if (dia == obra[i].data.dataDiaInicio && mes > obra[i].data.dataMesInicio)
        {
            return 0; // Obra em andamento ou já finalizada
        }
        else if (dia == obra[i].data.dataDiaInicio && mes == obra[i].data.dataMesInicio && ano > obra[i].data.dataAnoInicio)
        {
            return 0; // Obra em andamento ou já finalizada
        }
    }

    return 0; // Obra em andamento ou já finalizada (caso nenhuma obra esteja prevista para iniciar)
}

void alterar_cadastros()
{
    // menu que altera cadastros
    int op; // variavel de controle usada para gerenciar o menu
    char comparaCliente[100], comparaFuncionario[100], comparaObra[100];
    int tam1 = strlen(comparaCliente);
    int tam2 = strlen(comparaFuncionario);
    int tam3 = strlen(comparaObra);
    // vetores para cada uma das alternativas
    // para controlar quem vai comparar com quem

    do
    {
        // menu propriamente dito
        printf("=== Alterar Cadastros ===\n");
        printf("As opcoes de alteracao sao:\n");
        printf("-------------------------------------------\n");
        printf("1 - Cliente\n");
        printf("2 - Funcionario\n");
        printf("3 - Obra\n");
        printf("0 - Sair\n");
        printf("Escolha qual cadastro alterar(digite o numero a seguir):\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("digite o Cliente que deseja alterar:\n");
            fgets(comparaCliente, sizeof(comparaCliente), stdin);
            fflush(stdin);
            //  pede pro usuario digitar o cliente a ser procurado
            //  e comparado
            AlterarCliente(comparaCliente);
            // chama a funcao de comparacao que ja da o resultado
            break;
        case 2:
            printf("digite o Funcionario que deseja alterar:\n");
            fgets(comparaFuncionario, sizeof(comparaFuncionario), stdin);
            fflush(stdin);
            //  pede pro usuario digitar o funcionario a ser procurado
            //  e comparado
            AlterarFuncionario(comparaFuncionario); // chama a funcao de comparacao que ja da o resultado
            break;
        case 3:
            printf("digite a Obra que deseja alterar:\n");
            fgets(comparaObra, sizeof(comparaObra), stdin);
            fflush(stdin);
            //  pede pro usuario digitar o funcionario a ser procurado
            //  e comparado
            AlterarObra(comparaObra); // chama a funcao de comparacao que ja da o resultado
            break;
        case 0:
            Menu_principal(); // retorna para o menu principal quando user acaba de usar o menu secundario
            break;
        }

    } while (op != 0);
}

void ExibirStatusObra()
{
    int op, dia, mes, ano; // op = variavel de controle do menu
    // dia mes e ano = variaives de auxilio para input do usuario

    do
    {
        // menu propriamente dito
        system("cls");
        printf("=== Status das Obras ===\n");
        printf("As opcoes sao:\n");
        printf("-------------------------------------------\n");
        printf("1 - Relatorio das Obras \n");
        printf("2 - Relatorio de Obras Previstas\n");
        printf("0 - Sair\n");
        printf("\nEscolha qual status exibir(digite o numero a seguir):\n");
        scanf("%d", &op);
        fflush(stdin);

        switch (op)
        {
        case 1:
            system("cls");
            printf("Digite o dia do prazo de entrega:\n");
            scanf("%d", &dia); // recebe de input todas as informacoes para relatorio
            fflush(stdin);
            printf("Digite o mes do prazo de entrega:\n");
            scanf("%d", &mes);
            fflush(stdin);
            printf("Digite o ano do prazo de entrega:\n");
            scanf("%d", &ano);
            fflush(stdin);
            if (Status(obra, arqObra, dia, mes, ano) == 0) // se der 0= falso
            {
                printf("Obra Em Andamento.\n"); // digita que a obra esta em andamento
            }
            else
            {
                printf("Obra Concluida.\n"); // se der 1= verdadeiro entao obra ja esta concluida
            }
            getchar();
            break;
        case 2:
            system("cls");
            printf("Digite o dia do prazo de entrega:\n");
            scanf("%d", &dia);
            fflush(stdin);
            printf("Digite o mes do prazo de entrega:\n");
            scanf("%d", &mes);
            fflush(stdin);
            printf("Digite o ano do prazo de entrega:\n");
            scanf("%d", &ano);
            fflush(stdin);
            if (StatusPrevisto(obra, arqObra, dia, mes, ano) == 0) // se der 0= falso
            {
                printf("Obra atrasada. \n"); // sofre atraso
            }
            else
            {
                printf("Obra dentro do prazo. \n"); // se der 1= verdadeiro entao obra esta dentro do prazo
            }
            getchar();
            break;
        case 0:
            Menu_principal(); // retorna para o menu principal quando user acaba de usar o menu secundario
            // digitando 0
            break;
        }

    } while (op != 0);
}

void Relatorios()
{
    // eh a opcao que eh chamada para testar o loop
    int op;

    do
    {
        // menu propriamente dito
        system("cls");
        printf("=== Exibir Relatorios ===\n");
        printf("As opcoes sao:\n");
        printf("-------------------------------------------\n");
        printf("1 - Relatorio de Clientes: \n");
        printf("2 - Relatorio de Funcionario\n");
        printf("3 - Relatorio de Obras\n");
        printf("0 - Sair\n");
        printf("\nEscolha qual relatorio exibir(digite o numero a seguir):\n");
        scanf("%d", &op);
        fflush(stdin);

        switch (op)
        {
        case 0:
            Menu_principal(); // retorna para o menu principal quando user acaba de usar o menu secundario
            break;
        case 1:
            system("cls");
            printar_cliente(quantCliente, arqCliente); // funcao de relatorio de cliente
            system("pause");
            break; // parametros sao a quantidade de clientes e o arquivo onde estao armazenadas as informacoes
        case 2:
            system("cls");
            printar_funcionario(quantFuncionario, arqFuncionario); // relatorio de funcionario
            system("pause");
            break; // parametros sao a quantidade de funcionarios e o arquivo onde estao armazenadas as informacoes
        case 3:
            system("cls");
            printar_Obra(quantObra, arqObra); // relatorio de obras
            system("pause");
            break; // parametros sao a quantidade de obras e o arquivo onde estao armazenadas as informacoes
        }

    } while (op != 0);
}

void Cadastro()
{
    // eh a opcao que eh chamada para testar o loop
    // menu para controlar o cadastro
    int op;

    do
    {
        // menu propriamente dito
        system("cls");
        printf("====== Cadastro ======\n");
        printf("\n As opcoes sao:\n");
        printf("-------------------------------------------\n");
        printf("1 - Cadastrar Clientes\n");
        printf("2 - Cadastrar Funcionarios\n");
        printf("==================\n");
        printf("Cargos disponiveis para cadastro\n");
        printf("- Vendedor\n");
        printf("- Engenheiro\n");
        printf("- Gerente\n");
        printf("==================\n");
        printf("3 - Cadastrar Obras\n");
        printf("0 - Sair\n");

        printf("\nInforme a opcao(digite o numero a seguir):\n");
        scanf("%d", &op);
        fflush(stdin);

        switch (op)
        {
        case 0:
            Menu_principal();
            break;
        case 1:
            system("cls");
            printf("digite a quantidade de clientes que deseja cadastrar:\n");
            scanf("%d", &quantCliente); // pede ao usuario que informe a quantidade de clientes
            if (quantCliente == 0)
            {
                op = 0; // se a quantidade de clientes for zero, zera a variavel de controle do menu e fecha o programa
                break;
            }
            if (quantCliente > MAX) // se a quantidade de clientes ultrapassar o limite de armazenamento do programa
            {                       // programa da mensagem de erro
                printf("Quantidade excedeu o limite m�ximo.\n");
            }
            cadastro_cliente(quantCliente, arqCliente); // convoca as funcoes de cliente para logo em seguida salvar todos os dados no arquivo
            salvarArquivoCliente(quantCliente, arqCliente);
            break;
        case 2:
            system("cls");
            printf("digite a quantidade de funcionarios que deseja cadastrar:\n");
            scanf("%d", &quantFuncionario);
            if (quantFuncionario == 0)
            {
                op = 0; // se a quantidade de clientes for zero, zera a variavel de controle do menu e fecha o programa
                break;
            }
            if (quantFuncionario > MAX) // se a quantidade de funcionarios ultrapassar o limite de armazenamento do programa
            {                           // programa da mensagem de erro
                printf("Quantidade excedeu o limite m�ximo.\n");
            }
            cadastro_funcionario(quantFuncionario, arqFuncionario); // se nao der erro convoca as funcoes de funcionario para logo em seguida salvar todos os dados no arquivo
            salvarArquivoFuncionario(quantFuncionario, arqFuncionario);
            break;
            // le os dados do funcionario e grava na struct
        case 3:
            system("cls");
            printf("digite a quantidade de funcionarios que deseja cadastrar:\n");
            scanf("%d", &quantObra);
            if (quantObra == 0)
            {
                op = 0; // se a quantidade de clientes for zero, zera a variavel de controle do menu e fecha o programa
                break;
            }
            if (quantObra > MAX) // se a quantidade de obras ultrapassar o limite de armazenamento do programa
            {                    // programa da mensagem de erro
                printf("Quantidade excedeu o limite m�ximo.\n");
            }
            cadastro_Obras(quantObra, arqObra); // se nao der erro convoca as funcoes de obra para logo em seguida salvar todos os dados no arquivo
            salvarArquivoObra(quantObra, arqObra);
            break;
            // le os dados da obra e grava na struct
        default:
            system("cls");
            printf("Error, tente novamente.\n\n");
            getchar();
            return;
        }

    } while (op != 0);
}

void Menu_principal()
{
    // Menu principal, que vai ser o centro do programa

    // eh a opcao que eh chamada para testar o loop
    int op;

    // printf("digite a quantidade de clientes que deseja cadastrar:\n");
    // scanf("%d", &quantCliente);

    do
    {
        // fazer menu de cadastrar usuario
        system("cls");
        printf("====== Menu Principal ======\n\n");
        printf("\*As opcoes sao:\n");
        printf("-------------------------------------------\n");
        printf("1 - Cadastro(Clientes, Funcionarios e Obras\n");
        printf("2 - Alterar Cadastros\n");
        printf("3 - Exibir Status da Obra\n");
        printf("4 - Exibir Relatorio\n");
        printf("5 - Salvar \n");
        printf("0 - Sair\n");
        printf("\nInforme a opcao(digite o numero a seguir):\n");
        scanf("%d", &op);
        fflush(stdin);

        switch (op)
        {
        case 0:
            system("cls");
            break;
        case 1:
            // puxa o menu de cadastro
            system("cls");
            Cadastro();
            break;
        case 2:
            // puxa o menu de alteracao de cadastro
            system("cls");
            alterar_cadastros();
            break;
        case 3:
            // exibe o status atual da obra
            // se a obra estiver finalizada
            // ou em andamento
            system("cls");
            ExibirStatusObra();
            break;
        case 4:
            // imprime os relatorios das obras
            system("cls");
            Relatorios();
            break;
        case 5:
            // salva os dados no arquivo
            // os argumentos da funcao sao a quantidade de dados e o ponteiro de arquivo
            system("cls");
            salvarArquivoCliente(quantCliente, arqCliente);
            salvarArquivoFuncionario(quantFuncionario, arqFuncionario);
            salvarArquivoObra(quantObra, arqObra);
            getchar();
            break;
        default:
            // volta para a digita��o de opcao
            // caso a entrada esteja incorreta
            system("cls");
            printf("\nOpcao invalida. Tente novamente.\n");
            getchar();
            break;
        }
        system("cls");
        printf("\nPrograma Encerrado![...]\n");
        return 0;

    } while (op != 0);
}

void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}
