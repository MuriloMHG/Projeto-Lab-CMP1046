#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <limits.h>
#include <math.h>

//FEITO PELOS ALUNOS: GABRIEL COELHO, MURILO HENRIQUE GOMES E VICTOR ROBERTI

int atualizarPrestacao(void);
int calcularCirculo(void);
int calcularHipotenusa(void);
int calcularLosango(void);
int calcularQuadrado(void);
int consumoVeiculo(void);
int FinalizarPrograma(void);
void gotoxy(int x, int y);
void Janela(int Col, int Lin, int Colunas, int Linhas, char Char);
double LerNumero(int Col, int Lin, int inteiro);
int LerOpcao(int limite);
void LinhaHorizontal(int Col, int Lin, int Colunas, char Char);
void LinhaVertical(int Col, int Lin, int Colunas, int Linhas, char Char);
void Mensagem(const char *texto);
int menuFiguras(void);
void menuPrincipal(void);
void menuSequencial(void);
void PrepararPrograma(const char *titulo);
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
        printf("Apos o calculo: 5 - Menu anterior  6 - Menu principal");

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

        opcao = FinalizarPrograma();
    } while (opcao == 1);

    return opcao;
}

int calcularCirculo(void)
{
    double area;
    int opcao;
    double perimetro;
    const double PI = 3.141592653589793;
    double raio;

    do
    {
        PrepararPrograma("1.2 - CIRCULO");
        gotoxy(5, 9);
        printf("Raio do circulo: ");
        raio = LerNumero(35, 9, 0);

        area = PI * raio * raio;
        perimetro = 2.0 * PI * raio;

        gotoxy(5, 14);
        printf("Area     : %.2f unidades quadradas", area);
        gotoxy(5, 16);
        printf("Perimetro: %.2f unidades", perimetro);
        gotoxy(5, 19);
        printf("Area = PI * raio * raio | Perimetro = 2 * PI * raio");
        opcao = FinalizarPrograma();
    } while (opcao == 1);

    return opcao;
}

int calcularHipotenusa(void)
{
    double cateto1;
    double cateto2;
    double hipotenusa;
    int opcao;

    do
    {
        PrepararPrograma("1.1 - TRIANGULO RETANGULO");
        gotoxy(5, 9);
        printf("Primeiro cateto: ");
        cateto1 = LerNumero(35, 9, 0);
        gotoxy(5, 11);
        printf("Segundo cateto : ");
        cateto2 = LerNumero(35, 11, 0);

        hipotenusa = sqrt(cateto1 * cateto1 + cateto2 * cateto2);

        gotoxy(5, 15);
        printf("Hipotenusa: %.2f unidades", hipotenusa);
        gotoxy(5, 19);
        printf("Hipotenusa = raiz quadrada de (cateto1^2 + cateto2^2)");
        opcao = FinalizarPrograma();
    } while (opcao == 1);

    return opcao;
}

int calcularLosango(void)
{
    double area;
    double diagonalMaior;
    double diagonalMenor;
    int opcao;

    do
    {
        PrepararPrograma("1.4 - LOSANGO");
        gotoxy(5, 9);
        printf("Diagonal maior: ");
        diagonalMaior = LerNumero(35, 9, 0);
        gotoxy(5, 11);
        printf("Diagonal menor: ");
        diagonalMenor = LerNumero(35, 11, 0);

        area = (diagonalMaior * diagonalMenor) / 2.0;

        gotoxy(5, 15);
        printf("Area do losango: %.2f unidades quadradas", area);
        gotoxy(5, 19);
        printf("Area = (diagonal maior * diagonal menor) / 2");
        opcao = FinalizarPrograma();
    } while (opcao == 1);

    return opcao;
}

int calcularQuadrado(void)
{
    double area;
    double diagonal;
    double lado;
    int opcao;
    double perimetro;

    do
    {
        PrepararPrograma("1.3 - QUADRADO");
        gotoxy(5, 9);
        printf("Lado do quadrado: ");
        lado = LerNumero(35, 9, 0);

        area = lado * lado;
        perimetro = 4.0 * lado;
        diagonal = lado * sqrt(2.0);

        gotoxy(5, 14);
        printf("Area     : %.2f unidades quadradas", area);
        gotoxy(5, 16);
        printf("Perimetro: %.2f unidades", perimetro);
        gotoxy(5, 18);
        printf("Diagonal : %.2f unidades", diagonal);
        gotoxy(5, 19);
        printf("Area = lado^2 | Perimetro = 4 * lado | Diagonal = lado * raiz(2)");
        opcao = FinalizarPrograma();
    } while (opcao == 1);

    return opcao;
}

int consumoVeiculo(void)
{
    double distancia;
    double duracao;
    double etanolA;
    double etanolB;
    double etanolC;
    double gasolinaA;
    double gasolinaB;
    double gasolinaC;
    double gastoEtanolA;
    double gastoEtanolB;
    double gastoEtanolC;
    double gastoGasolinaA;
    double gastoGasolinaB;
    double gastoGasolinaC;
    int opcao;
    const double precoEtanol = 2.90;
    const double precoGasolina = 3.80;
    double velocidadeMedia;

    do
    {
        PrepararPrograma("2 - CONSUMO DE VEICULO");
        gotoxy(5, 9);
        printf("Duracao da viagem (horas): ");
        duracao = LerNumero(35, 9, 0);
        gotoxy(5, 11);
        printf("Velocidade media (km/h)  : ");
        velocidadeMedia = LerNumero(35, 11, 0);

        distancia = duracao * velocidadeMedia;

        gasolinaA = distancia / 8.0;
        gasolinaB = distancia / 10.0;
        gasolinaC = distancia / 12.0;

        etanolA = gasolinaA * 1.40;
        etanolB = gasolinaB * 1.40;
        etanolC = gasolinaC * 1.40;

        gastoGasolinaA = gasolinaA * precoGasolina;
        gastoGasolinaB = gasolinaB * precoGasolina;
        gastoGasolinaC = gasolinaC * precoGasolina;
        gastoEtanolA = etanolA * precoEtanol;
        gastoEtanolB = etanolB * precoEtanol;
        gastoEtanolC = etanolC * precoEtanol;

        gotoxy(5, 14);
        printf("TIPO  GASOLINA (L)   GASTO (R$)   ETANOL (L)    GASTO (R$)");
        gotoxy(5, 15);
        printf("A     %12.2f %12.2f %12.2f %13.2f",
               gasolinaA, gastoGasolinaA, etanolA, gastoEtanolA);
        gotoxy(5, 16);
        printf("B     %12.2f %12.2f %12.2f %13.2f",
               gasolinaB, gastoGasolinaB, etanolB, gastoEtanolB);
        gotoxy(5, 17);
        printf("C     %12.2f %12.2f %12.2f %13.2f",
               gasolinaC, gastoGasolinaC, etanolC, gastoEtanolC);
        gotoxy(5, 18);
        printf("Distancia: %.2f km | Gasolina: A = 8, B = 10, C = 12 km/l", distancia);
        gotoxy(5, 19);
        printf("Precos por litro: gasolina R$ 3.80 | etanol R$ 2.90");
        opcao = FinalizarPrograma();
    } while (opcao == 1);

    return opcao;
}

int FinalizarPrograma(void)
{
    int opcao;

    gotoxy(3, 23);
    printf("%-86s", "");
    gotoxy(3, 23);
    printf("OPCAO [  ]");
    gotoxy(16, 23);
    printf("1-Repetir  5 - Retornar ao menu anterior  6 - Retornar ao menu principal");
    Mensagem("Escolha 1 para repetir, 5 para o menu anterior ou 6 para o principal.");

    do
    {
        opcao = LerOpcao(6);
        if (opcao == 0)
            opcao = 5;
        if (opcao != 1 && opcao != 5 && opcao != 6)
            Mensagem("Opcao invalida. Escolha 1, 5 ou 6 e pressione Enter.");
    } while (opcao != 1 && opcao != 5 && opcao != 6);

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
    LinhaHorizontal(Col, Lin + 2, Colunas, Char);
    LinhaHorizontal(Col, Lin + 19, Colunas, Char);
    LinhaHorizontal(Col, Lin + 21, Colunas, Char);
    LinhaHorizontal(Col, Lin + Linhas - 1, Colunas, Char);
    LinhaVertical(Col, Lin, Colunas, Linhas, Char);
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
        else 
        if (tecla >= '0' && tecla <= '9')
        {
            Opcao = tecla - '0';
        }
        else 
        if (tecla == 8)
        {
            Opcao = -1;
        }
        else 
        if (tecla == 13)
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

int menuFiguras(void)
{
    int Opcao;
    int retorno;

    do
    {
        Janela(1, 1, 90, 24, '=');
        gotoxy(36, 5);
        printf("FIGURAS GEOMETRICAS");
        gotoxy(8, 7);
        printf("1 - TRIANGULO RETANGULO: HIPOTENUSA");
        gotoxy(8, 8);
        printf("2 - CIRCULO: AREA E PERIMETRO");
        gotoxy(8, 9);
        printf("3 - QUADRADO: AREA, PERIMETRO E DIAGONAL");
        gotoxy(8, 10);
        printf("4 - LOSANGO: AREA");
        gotoxy(8, 11);
        printf("5 - RETORNAR AO MENU ANTERIOR");
        gotoxy(8, 12);
        printf("6 - RETORNAR AO MENU PRINCIPAL");
        gotoxy(8, 15);
        printf("Use a mesma unidade para todas as medidas de uma figura.");
        gotoxy(16, 23);
        printf("1-Triangulo 2-Circulo 3-Quadrado 4-Losango 5-Anterior 6-Principal");
        Mensagem("Escolha a figura, 5 para o menu anterior ou 6 para o principal.");
        Opcao = LerOpcao(6);
        retorno = 5;

        switch (Opcao)
        {
            case 1:
                retorno = calcularHipotenusa();
                break;
            case 2:
                retorno = calcularCirculo();
                break;
            case 3:
                retorno = calcularQuadrado();
                break;
            case 4:
                retorno = calcularLosango();
                break;
            case 6:
                return 6;
        }

        if (retorno == 6)
            return 6;
    } while (Opcao != 5 && Opcao != 0);

    return 5;
}

void menuPrincipal(void)
{
    int Opcao;

    do
    {
        Janela(1, 1, 90, 24, '=');
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
        printf("4 - RETORNAR AO MENU ANTERIOR");
        gotoxy(8, 15);
        printf("Selecione a atividade que deseja executar.");
        gotoxy(16, 23);
        printf("1-Figuras  2-Consumo  3-Prestacao  4-Anterior");
        Mensagem("Escolha 1, 2, 3 ou 4 e pressione Enter.");
        Opcao = LerOpcao(5);

        switch (Opcao)
        {
            case 1:
                if (menuFiguras() == 6)
                    return;
                break;
            case 2:
                if (consumoVeiculo() == 6)
                    return;
                break;
            case 3:
                if (atualizarPrestacao() == 6)
                    return;
                break;
            case 4:
                Mensagem("Opcao invalida. Escolha 1, 2, 3 ou 4. Pressione uma tecla.");
                getch();
                break;
        }
    } while (Opcao != 4 && Opcao != 0);
}

void PrepararPrograma(const char *titulo)
{
    Janela(1, 1, 90, 24, '=');
    gotoxy(46 - (int)strlen(titulo) / 2, 5);
    printf("%s", titulo);
    gotoxy(42, 7);
    printf("ENTRADA");
    gotoxy(43, 13);
    printf("SAIDA");
    gotoxy(16, 23);
    printf("Apos o calculo: 5 - Menu anterior  6 - Menu principal");
    Mensagem("Digite valores positivos. Use ponto para decimais e confirme com Enter.");
}

void TextoJanela(void)
{
    gotoxy(38, 2);
    printf("PROJETO CMP1046");
    gotoxy(3, 21);
    printf("MENS: [");
    gotoxy(88, 21);
    printf("]");
    gotoxy(3, 23);
    printf("OPCAO [  ]");
}



