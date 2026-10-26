#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <limits.h>

int atualizarPrestacao(void);
void gotoxy(int x, int y);
void Janela(int Col, int Lin, int Colunas, int Linhas, char Char);
double LerNumero(int Col, int Lin, int inteiro);
int LerOpcao(int limite);
void LinhaHorizontal(int Col, int Lin, int Colunas, char Char);
void LinhaVertical(int Col, int Lin, int Colunas, int Linhas, char Char);
void Mensagem(const char *texto);
void menuPrincipal(void);
void menuSequencial(void);
void TextoJanela(void);

int atualizarPrestacao(void)
{
    int diasAtraso;
    double juros;
    double multa;
    int opcao;
    double prestacao;
    double valorAtualizado;

    do
    {
        Janela(1, 1, 90, 24, '=');
        gotoxy(29, 5);
        printf("ATUALIZAR PRESTACAO DE VEICULO");
        gotoxy(42, 7);
        printf("ENTRADA");
        gotoxy(16, 23);
        printf("Preencha os campos. Ao concluir, escolha o que deseja fazer.");

        Mensagem("Informe o valor original. Use ponto para separar os centavos.");
        gotoxy(5, 9);
        printf("Valor original da prestacao : ");
        prestacao = LerNumero(35, 9, 0);

        Mensagem("Informe a quantidade inteira de dias de atraso, maior que zero.");
        gotoxy(5, 11);
        printf("Quantidade de dias de atraso: ");
        diasAtraso = (int)LerNumero(35, 11, 1);

        multa = prestacao * 0.05;

        juros = prestacao * 0.09 * diasAtraso / 30.0;
        valorAtualizado = prestacao + multa + juros;

        gotoxy(43, 13);
        printf("SAIDA");
        gotoxy(5, 14);
        printf("Valor original  : R$ %.2f", prestacao);
        gotoxy(5, 15);
        printf("Multa de 5%%     : R$ %.2f", multa);
        gotoxy(5, 16);
        printf("Juros por atraso: R$ %.2f", juros);
        gotoxy(5, 18);
        printf("VALOR ATUALIZADO: R$ %.2f", valorAtualizado);
        gotoxy(5, 19);
        printf("Juros simples   : 9%% ao mes. Mes considerado: 30 dias.");

        gotoxy(3, 23);
        printf("%-86s", "");
        gotoxy(3, 23);
        printf("Opcao [  ]");
        gotoxy(16, 23);
        printf("1 - Repetir  2 - Menu de programas");
        Mensagem("Deseja repetir ou voltar ao menu de programas? Escolha 1 ou 2.");

        opcao = LerOpcao(2);
        if (opcao == 0)
            opcao = 2;
    } while (opcao == 1);

    return opcao;
}

void gotoxy(int x, int y)
{
    COORD posicao;

    fflush(stdout);
    posicao.X = (SHORT)(x - 1);
    posicao.Y = (SHORT)(y - 1);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posicao);
}

void Janela(int Col, int Lin, int Colunas, int Linhas, char Char)
{
    HANDLE console;
    DWORD modoOriginal = 0;

    system("cls");
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleMode(console, &modoOriginal);
    SetConsoleMode(console, modoOriginal & ~ENABLE_WRAP_AT_EOL_OUTPUT);

    LinhaHorizontal(Col, Lin, Colunas, Char);
    LinhaHorizontal(Col, Lin + 3, Colunas, Char);
    LinhaHorizontal(Col, Lin + 5, Colunas, Char);
    LinhaHorizontal(Col, Lin + 11, Colunas, Char);
    LinhaHorizontal(Col, Lin + 19, Colunas, Char);
    LinhaHorizontal(Col, Lin + 21, Colunas, Char);
    LinhaHorizontal(Col, Lin + Linhas - 1, Colunas, Char);
    LinhaVertical(Col, Lin, Colunas, Linhas, '*');
    TextoJanela();

    fflush(stdout);
    SetConsoleMode(console, modoOriginal);
}

double LerNumero(int Col, int Lin, int inteiro)
{
    double numero;
    int tamanho = 0;
    int tecla;
    char texto[16] = "";

    for (;;)
    {
        gotoxy(Col + tamanho, Lin);
        tecla = getch();

        if (tecla == 0 || tecla == 224)
        {
            getch();
        }
        else if (tecla == 8 && tamanho > 0)
        {
            tamanho--;
            texto[tamanho] = '\0';
            gotoxy(Col + tamanho, Lin);
            printf(" ");
        }
        else if (tecla == 13)
        {
            numero = strtod(texto, NULL);
            if (numero > 0 && (!inteiro || numero <= INT_MAX))
                return numero;

            Mensagem("Digite um numero positivo valido e pressione Enter.");
        }
        else if (tamanho < 15 &&
                 ((tecla >= '0' && tecla <= '9') ||
                  (!inteiro && tecla == '.' && strchr(texto, '.') == NULL)))
        {
            texto[tamanho] = (char)tecla;
            tamanho++;
            texto[tamanho] = '\0';
            printf("%c", tecla);
        }
    }
}

int LerOpcao(int limite)
{
    int Opcao = -1;
    int tecla;

    for (;;)
    {
        gotoxy(10, 23);
        if (Opcao >= 0)
            printf("%d ]", Opcao);
        else
            printf("  ]");
        gotoxy(10, 23);
        tecla = getch();

        if (tecla == 27)
            return 0;

        if (tecla == 0 || tecla == 224)
        {
            getch();
        }
        else if (tecla >= '0' && tecla <= '9')
        {
            Opcao = tecla - '0';
        }
        else if (tecla == 8)
        {
            Opcao = -1;
        }
        else if (tecla == 13)
        {
            if (Opcao >= 1 && Opcao <= limite)
                return Opcao;

            Mensagem("Opcao invalida. Escolha uma das opcoes mostradas no menu.");
            Opcao = -1;
        }
    }
}

void LinhaHorizontal(int Col, int Lin, int Colunas, char Char)
{
    int i;

    gotoxy(Col, Lin);
    for (i = 0; i < Colunas; i++)
        printf("%c", Char);
}

void LinhaVertical(int Col, int Lin, int Colunas, int Linhas, char Char)
{
    int i;

    for (i = 1; i < Linhas - 1; i++)
    {
        gotoxy(Col, Lin + i);
        printf("%c", Char);
        gotoxy(Col + Colunas - 1, Lin + i);
        printf("%c", Char);
    }
}

int main(void)
{
    setlocale(LC_ALL, "");
    setlocale(LC_NUMERIC, "C");
    system("color F0");
    system("mode con cols=90 lines=25");

    menuPrincipal();

    gotoxy(1, 25);
    return 0;
}

void Mensagem(const char *texto)
{
    gotoxy(10, 21);
    printf("%-77.77s", texto);
    fflush(stdout);
}

void menuPrincipal(void)
{
    int Opcao;

    do
    {
        Janela(1, 1, 90, 24, '=');
        gotoxy(2, 12);
        printf("%88s", "");
        LinhaHorizontal(2, 13, 88, '=');
        gotoxy(39, 5);
        printf("MENU PRINCIPAL");
        gotoxy(8, 8);
        printf("1 - ESTRUTURA SEQUENCIAL");
        gotoxy(8, 9);
        printf("2 - ESTRUTURA CONDICIONAL");
        gotoxy(8, 10);
        printf("3 - ESTRUTURA DE REPETICAO");
        gotoxy(8, 11);
        printf("4 - VARIAVEIS COMPOSTAS HOMOGENEAS");
        gotoxy(8, 12);
        printf("5 - ENCERRAR");
        gotoxy(8, 15);
        printf("Escolha a estrutura. Depois, escolha o programa.");
        gotoxy(16, 23);
        printf("1 - Sequencial  2 - Condicional  3 - Repeticao  4 - Vetores  5 - Encerrar");
        Mensagem("Digite 1, 2, 3, 4 ou 5 e pressione Enter. 5 encerra o programa.");

        Opcao = LerOpcao(5);

        switch (Opcao)
        {
            case 1:
                menuSequencial();
                break;

            case 2:
                Mensagem("Estrutura condicional ainda nao foi feita. Pressione uma tecla.");
                getch();
                break;

            case 3:
                Mensagem("Estrutura de repeticao ainda nao foi feita. Pressione uma tecla.");
                getch();
                break;

            case 4:
                Mensagem("Variaveis compostas homogeneas ainda nao foram feitas. Pressione uma tecla.");
                getch();
                break;

            case 5:
                break;
        }
    } while (Opcao != 5 && Opcao != 0);
}

void menuSequencial(void)
{
    int Opcao;

    do
    {
        Janela(1, 1, 90, 24, '=');
        gotoxy(36, 5);
        printf("ESTRUTURA SEQUENCIAL");
        gotoxy(8, 8);
        printf("1 - FIGURAS GEOMETRICAS");
        gotoxy(8, 9);
        printf("2 - CONSUMO DE VEICULO");
        gotoxy(8, 10);
        printf("3 - ATUALIZAR PRESTACAO DE VEICULO");
        gotoxy(8, 11);
        printf("4 - RETORNAR AO MENU PRINCIPAL");
        gotoxy(8, 15);
        printf("Selecione a atividade que deseja executar.");
        gotoxy(16, 23);
        printf("1 - Figuras   2 - Consumo   3 - Prestacao   4 - Retornar");
        Mensagem("Digite a opcao e pressione Enter. Opcao 4 ou Esc volta ao principal.");

        Opcao = LerOpcao(4);

        switch (Opcao)
        {
            case 1:
                Mensagem("Aguardando codigo de figuras do grupo. Pressione uma tecla.");
                getch();
                break;

            case 2:
                Mensagem("Aguardando codigo de consumo do grupo. Pressione uma tecla.");
                getch();
                break;

            case 3:
                atualizarPrestacao();
                break;

            case 4:
                break;
        }
    } while (Opcao != 4 && Opcao != 0);
}

void TextoJanela(void)
{
    gotoxy(29, 2);
    printf("CMP1046 - LABORATORIO DE PROGRAMACAO");
    gotoxy(33, 3);
    printf("Prof: Anibal Vicente Vieira");
    gotoxy(4, 21);
    printf("Mens [");
    gotoxy(88, 21);
    printf("]");
    gotoxy(3, 23);
    printf("Opcao [  ]");
}


