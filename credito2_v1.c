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

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N_ASSENTOS 44

typedef struct{
    int numero;       // cada item representa uma poltrona;
    char status;      // mostra se a poltrona está vazia(v) ou ocupada(o)
    char posicao;     // mostra se a poltrona esta na janela(j) ou no corredor(c)
}tPoltrona;

void inicializar(tPoltrona* onibus){
    // tPoltrona onibus[N_ASSENTOS];

    for(int i = 0; i<N_ASSENTOS; i++){
        onibus[i].numero = i+1;

        if(i%2 == 0){
            onibus[i].posicao = 'C';
        }
        else{onibus[i].posicao = 'J';}

        onibus[i].status = 'L';
    }
}
void visualizar(tPoltrona* onibus){
    printf("\n== ÁGUIA BRANCA ==\n\n");
    printf("Horário de partida: 6:30\n");
    printf("Horário de chegada: 14:50\n");
    printf("Ponto de partida: Itabuna, BA - rodoviária\n");
    printf("Ponto de chegada: Salvador, BA - rodoviária\n");
    printf("Selecione a quantidade de passageiros digitando o número da poltrona desejada.\n");
    printf("Poltronas selecionadas: \n"); // mostra a quantidade poltronas selecionadas;

    for(int i = 0; i<11; i++){
        if(onibus[i].status == 'O'){
            printf("\tX");
        }
        else{
            printf("\t%0d", 3 + 4*i);
        }
    }
    printf("\n");

    for(int i = 0; i<11; i++){
        if(onibus[i].status == 'O'){
            printf("\tX");
        }
        else{
            printf("\t%0d", 4 + 4*i);
        }
    }
    printf("\n\n");

    for(int i = 0; i<11; i++){
        if(onibus[i].status == 'O'){
            printf("\tX");
        }
        else{
            printf("\t%0d", 2 + 4*i);
        }
    }
    printf("\n");

    for(int i = 0; i<11; i++){
        if(onibus[i].status == 'O'){
            printf("\tX");
        }
        else{
            printf("\t%0d", 1 + 4*i);
        }
    }
}
void consultar(tPoltrona* onibus){
    int num_poltrona;
    printf("\nQual poltrona deseja consultar: ");
    scanf("%d", &num_poltrona);
    getchar();

    printf("\n -> Poltrona:\t%d\n", num_poltrona);
    printf("   -> Posição: \t%c\n", onibus[num_poltrona].posicao);
    printf("   -> Status: \t%c\n", onibus[num_poltrona].status);
}

void vender(tPoltrona* onibus){
    int num_poltrona;
    printf("Digite o número da poltrona que você deseja comprar: ");
    scanf("%d", &num_poltrona);
    getchar();
    onibus[num_poltrona].status = 'O'; // atribui o status de 'ocupada' à poltrona selecionada
}
void cancelar(){}
void relatorio(){}

void comando(char op){
    tPoltrona onibus[N_ASSENTOS];
    switch(op){
        case 'I': inicializar(onibus);
            break;
        case 'V': visualizar(onibus);
            break;
        case 'P': consultar(onibus);
            break;
        case 'E': vender(onibus);
            break;
        case 'C': cancelar(onibus);
            break;
        case 'R': relatorio(onibus);
            break;
        default: printf("Opção inválida\n");
    }
}

void menu(){
    char op;

    while(1){
        printf("\n    === MENU ===\n");
        printf("    I - Inicializar\n");
        printf("    V - Visualizar\n");
        printf("    P - Consultar Poltrona\n");
        printf("    E - Vender\n");
        printf("    C - Cancelar Venda\n");
        printf("    R - Relatório\n");
        printf("    S - Sair\n");

        printf("opção: ");
        fflush(stdin);
        op = getchar();
        getchar();

        if(op == 'S' || op == 's')
            break;

        comando(op);
    }
    printf("\nEncerrando programa...\n");
}


int main(void){
    printf("=== BEM-VINDO ===\n");
    printf("ALAN TRANSPORTES\n\n");
    menu();

    return 0;
}
