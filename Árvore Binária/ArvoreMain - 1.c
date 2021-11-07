#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
#include<locale.h>
#include"FuncoesArvore.h"

int main(){
    setlocale(LC_ALL, "Portuguese");
    ARVORE *a = inicia_arv();
    int opcoes,elemento, contaArv,imprimir, no;
    int nivel = 0;
    FILE *arq;
    arq = fopen ("1arvore.txt","r");

    while(opcoes != 9){
        printf("\t\t\t Menu: (Escolha um número )");
        printf("\n 1) Ler Arvore");
        printf("\n 2) Imprimir Arvore");
        printf("\n 3) Verificar se um elemento x existe");
        printf("\n 4) Contar o número de elementos na arvore ");
        printf("\n 5) Imprimir os nós folhas da árvoree");
        printf("\n 6) Verificar se uma arvore esta balanceada ");
        printf("\n 7) Verificar se uma árvore eh cheia");
        printf("\n 8) Imprimir o nivel de um no x");
        printf("\n 9) Sair");
        printf("\n\t Digite uma opcao: ");
        scanf("%d", &opcoes);
        switch(opcoes){
            case 1:              //Ler Arvore
                a = LerArvore(arq);
								if(a != NULL){
									printf("arquivo lido com sucesso\n");
								}
            break;
            case 2:                                                                         //Imprimir Arvore
                printf("1 - Imprimir pre Ordem:");
                printf("2 - Imprimir em Ordem:");
                printf("3 - Imprimir pos Ordem:");
                printf("4 - Imprimir em Largura:");
                scanf("%d",&imprimir);
                if(imprimir == 1)
                    ImprimirPreOrdem(a);    
                else if(imprimir == 2)
                    ImprimirEmOrdem(a);
                else if(imprimir == 3)
                    ImprimirPosOrdem(a);
                else if(imprimir == 4)
                    ImprimirEmLargura(a);
            break;
            case 3:                                                                             //Verificar se um elemento x existe
                printf("Elemento:");
                scanf("%d",&elemento);
                int verificar = ExisteElemento(a, elemento);
								if(verificar == 1)
									printf("elemento existe");
								else
									printf("elemento nao existe");
            break;
            case 4:                                                                              // Contar o numero de elementos na arvore
                ContarElementos(a, contaArv);
                break;
            case 5:                                                                              //Imprimir os nós folhas da árvore 
                ImprimirFolha(a);
            break;
            case 6:                                                                              //Verificar se uma arvore está balanceada
                int balanceada = balanceada(a);
                if(balanceada == 1)
                    printf("Arvore balanceada");
                else 
                    printf("Arvore não balanceada");
            break;
            case 7:                                                                             //Verificar se uma árvore é cheia
               int cheia = ArvoreCheia(a);
               if(cheia == 1)
                   printf("Arvore cheia!")
               else    
                    printf("Arvore não cheia");
            break;
            case 8:                                                                             //Imprimir o nível de um nó x
                printf("Qual elemento deseja saber o nivel?");
                scanf("%d", &no);
                ImprimirNo(a,no,nivel);
            break;
            case 9:
                printf("\n Obrigado por usar o programa ! \n");                 // Sair
            break;
            default:
                printf("Digite uma opção valida!");                                      
            break;
        }
    }
    fclose(arq);
}