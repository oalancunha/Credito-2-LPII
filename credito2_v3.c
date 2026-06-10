/***
 * CRÉDITO 2 - MODULARIZAÇÃO
 * Entrega: 
 * - Para entrega o grupo deve submeter o arquivo C do trabalho no Classroom. 
 * - Permitido apenas até 3 integrantes no grupo. 
 * - Valor : 10,0 pontos 
 * - Data de entrega: 12/06
 * 
 * Plano:
 *      -Nesta atividade o foco é desenvolver um programa inspirado em uma venda de passagens de ônibus. 
 *       Imagine que um operador de um guichê precisa realizar vendas de passagens de um ônibus com 44 lugares. 
 * 
 * Funções:
 * I - Inicializar
 * V - Visualizar
 * P - Consultar Poltrona
 * E - Vender
 * C - Cancelar Venda
 * R - Relatório
 * S - Sair
 *          
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define N_ASSENTOS 44

typedef struct{
    int numero;
    char status;      // L = Livre | O = Ocupada
    char posicao;     // J = Janela | C = Corredor
} tPoltrona;

void inicializar(tPoltrona *onibus){

    for(int i = 0; i < N_ASSENTOS; i++){

        onibus[i].numero = i + 1;
        onibus[i].status = 'L';

        int coluna = i % 4;

        if(coluna == 0 || coluna == 3)
            onibus[i].posicao = 'J';
        else
            onibus[i].posicao = 'C';
    }

    printf("\nÔnibus inicializado com sucesso!\n");
}

void visualizar(tPoltrona *onibus){

    printf("\n== ÁGUIA BRANCA ==\n\n");

    printf("Horário de partida: 06:30\n");
    printf("Horário de chegada: 14:50\n");
    printf("Ponto de partida: Itabuna - BA\n");
    printf("Ponto de chegada: Salvador - BA\n\n");

    printf("Legenda:\n");
    printf("X = Ocupada\n\n");

    for(int i = 0; i < N_ASSENTOS; i += 4){

        for(int j = 0; j < 4; j++){

            if(onibus[i + j].status == 'O')
                printf(" X ");
            else
                printf("%02d ", onibus[i + j].numero);

            if(j == 1)
                printf("   ");
        }

        printf("\n");
    }
}

void consultar(tPoltrona *onibus){

    int num_poltrona;

    printf("\nQual poltrona deseja consultar? ");
    scanf("%d", &num_poltrona);

    if(num_poltrona < 1 || num_poltrona > N_ASSENTOS){
        printf("Poltrona inválida!\n");
        return;
    }

    num_poltrona--;

    printf("\nPoltrona: %d\n", onibus[num_poltrona].numero);

    printf("Posição: ");

    if(onibus[num_poltrona].posicao == 'J')
        printf("Janela\n");
    else
        printf("Corredor\n");

    printf("Status: ");

    if(onibus[num_poltrona].status == 'L')
        printf("Livre\n");
    else
        printf("Ocupada\n");
}

void vender(tPoltrona *onibus){

    int num_poltrona;

    printf("\nDigite a poltrona desejada: ");
    scanf("%d", &num_poltrona);

    if(num_poltrona < 1 || num_poltrona > N_ASSENTOS){
        printf("Poltrona inválida!\n");
        return;
    }

    num_poltrona--;

    if(onibus[num_poltrona].status == 'O'){
        printf("Poltrona já está ocupada!\n");
        return;
    }

    onibus[num_poltrona].status = 'O';

    printf("Venda realizada com sucesso!\n");
}

void cancelar(tPoltrona *onibus){

    int num_poltrona;

    printf("\nDigite a poltrona para cancelar: ");
    scanf("%d", &num_poltrona);

    if(num_poltrona < 1 || num_poltrona > N_ASSENTOS){
        printf("Poltrona inválida!\n");
        return;
    }

    num_poltrona--;

    if(onibus[num_poltrona].status == 'L'){
        printf("Essa poltrona já está livre!\n");
        return;
    }

    onibus[num_poltrona].status = 'L';

    printf("Venda cancelada com sucesso!\n");
}

void relatorio(tPoltrona *onibus){

    int livres = 0;
    int ocupadas = 0;
    int janela = 0;
    int corredor = 0;

    float perc_ocupacao;
    float perc_janela;
    float perc_corredor;
    float arrecadado;

    for(int i = 0; i < N_ASSENTOS; i++){

        if(onibus[i].status == 'O'){

            ocupadas++;

            if(onibus[i].posicao == 'J')
                janela++;
            else
                corredor++;
        }
        else{
            livres++;
        }
    }

    perc_ocupacao = (ocupadas * 100.0) / N_ASSENTOS;

    if(ocupadas > 0){
        perc_janela = (janela * 100.0) / ocupadas;
        perc_corredor = (corredor * 100.0) / ocupadas;
    }
    else{
        perc_janela = 0;
        perc_corredor = 0;
    }

    arrecadado = ocupadas * 53.20;

    printf("\n========== RELATÓRIO ==========\n");

    printf("Total de poltronas........: %d\n", N_ASSENTOS);
    printf("Poltronas livres..........: %d\n", livres);
    printf("Poltronas ocupadas........: %d\n", ocupadas);
    printf("Percentual de ocupação....: %.2f%%\n", perc_ocupacao);

    printf("\n--- Vendas por posição ---\n");

    printf("Janela....................: %d\n", janela);
    printf("Corredor..................: %d\n", corredor);

    printf("Percentual Janela.........: %.2f%%\n", perc_janela);
    printf("Percentual Corredor.......: %.2f%%\n", perc_corredor);

    printf("\nValor arrecadado..........: R$ %.2f\n", arrecadado);

    printf("===============================\n");
}

void comando(char op, tPoltrona *onibus){

    switch(op){

        case 'I':
            inicializar(onibus);
            break;

        case 'V':
            visualizar(onibus);
            break;

        case 'P':
            consultar(onibus);
            break;

        case 'E':
            vender(onibus);
            break;

        case 'C':
            cancelar(onibus);
            break;

        case 'R':
            relatorio(onibus);
            break;

        default:
            printf("Opção inválida!\n");
    }
}

void menu(){

    char op;

    tPoltrona onibus[N_ASSENTOS];

    inicializar(onibus);

    while(1){

        printf("\n=== MENU ===\n");
        printf("I - Inicializar\n");
        printf("V - Visualizar\n");
        printf("P - Consultar Poltrona\n");
        printf("E - Vender\n");
        printf("C - Cancelar Venda\n");
        printf("R - Relatório\n");
        printf("S - Sair\n");

        printf("\nOpção: ");
        scanf(" %c", &op);

        op = toupper(op);

        if(op == 'S')
            break;

        comando(op, onibus);
    }

    printf("\nEncerrando programa...\n");
}

int main(){

    printf("=== BEM-VINDO ===\n");
    printf("ALAN TRANSPORTES\n");

    menu();

    return 0;
}