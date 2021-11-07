#ifndef ARVFUNCOES_H_INCLUDED
#define ARVFUNCOES_H_INCLUDED
#endif //ARVFUNCOES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Estrutura da Árvore
typedef struct ARVORE  {
    int info;
    struct ARVORE *esq; 
    struct ARVORE *dir;
}ARVORE;

// Árvore vazia
ARVORE *inicia_arv(){
    return NULL;
}

//Criar Árvore
ARVORE *CriaNo(int num){
    ARVORE *a = (ARVORE*)malloc(sizeof(ARVORE));
    a->info = num;
    return a;
}

//1 - Ler uma árvore de um arquivo fornecido pelo usuário
ARVORE *LerArvore(FILE *arq){
    char c;
    int num;

    fscanf(arq,"%c",&c);  // Ler '('
    fscanf(arq,"%d",&num); // Ler a raiz

    if(num == -1){  //se num for == -1 quer dizer que não tem valor, É NULL
        fscanf(arq,"%c",&c);  //Ler ')'
        return NULL;
    }else{
        ARVORE *a = CriaNo(num);

        a->esq = LerArvore(arq);  // Sub.arq
        a->dir = LerArvore(arq);  // Sub.dir

        fscanf(arq,"%c",&c);   //Ler')'
        return a; 
    }
}

//2 - Imprimir a árvore (opções: pré-ordem; em-ordem; pós-ordem; e em largura)
void ImprimirPreOrdem(ARVORE *a){
    if(a != NULL){
        printf("%d ",a->info);         // Raiz
        ImprimirPreOrdem(a->esq);     //SubArvore esquerda
        ImprimirPreOrdem(a->dir);     //SubArvore Direita
    }
}

void ImprimirEmOrdem(ARVORE *a){
    if(a != NULL){
        ImprimirEmOrdem(a->esq);     //SubArvore esquerda
        printf("%d ",a->info);   // Raiz
        ImprimirEmOrdem(a->dir);     //SubArvore Direita
    }
}

void ImprimirPosOrdem(ARVORE *a){
    if(a != NULL){
        ImprimirPosOrdem(a->esq);     //SubArvore esquerda
        ImprimirPosOrdem(a->dir);     //SubArvore Direita
        printf("%d ",a->info);    // Raiz
    }
}

// Altura da Arvore
int Altura(ARVORE *a){
    if(a == NULL)
        return 0;
    else {
        int he = Altura(a->esq);
        int hd = Altura(a->dir);
        if(he>hd)  
            return he + 1;    
        else                       // Raiz 
            return hd + 1;
    }
}

//imprimir nivel
void ImprimirNivel(ARVORE *a, int cont, int nivel){
     if(a != NULL){                // NULL?
        if(cont == nivel)
            printf("%d ",a->info);  // Raiz
        else{
            ImprimirNivel(a->esq,cont+1,nivel);
            ImprimirNivel(a->dir,cont+1,nivel);
        }
     }
}

void ImprimirEmLargura(ARVORE *a){
    if(a != NULL){
        int i;
        int h =Altura(a);
        for(i=0; i<h; i++){
            ImprimirNivel(a, 0,i);
            printf("\n");
        }
    }
}

//3 - Verificar se um elemento x existe na árvore
int ExisteElemento(ARVORE *a, int x){
    if(a==NULL)
        return 0;
    if (a->info == x)
        return 1;
    else {
        int ret = ExisteElemento(a->esq,x);
        if(ret == 1)  
            return 1;
        return ExisteElemento(a->dir,x);
    }
}

//4 - Contar o número de elementos na árvore
void ContarElementos(ARVORE *a, int elemento){
    if(a != NULL){
        elemento++;
        ContarElementos(a->esq,elemento);
        ContarElementos(a->dir,elemento);       
    }
    printf ("Tem %d elementos na arvore",elemento);
}

//5 - Imprimir os nós folhas da árvore 
void ImprimirFolha(ARVORE *a){
    if(a != NULL){
        if((a->esq == NULL)  && ( a->dir ==NULL ))
            printf("%d ",a->info);
    }
    ImprimirFolha(a->esq);
    ImprimirFolha(a->dir);
}

//contar niveis 
int ContarNivel(ARVORE *a, int cont, int n){
    if(a==NULL )
        return 0;
    else    
        if(cont == n)
            return 1;
        else
            return ContarNivel(a->esq,cont+1,n)+ContarNivel(a->dir,cont+1,n);
}

//Contar Arvore
int ContarArvore(ARVORE *a){
	if(a == NULL)
		return 0;
	else 
        return 1+ContarArvore(a->esq) + ContarArvore(a->dir);
}

//6 - Verificar se uma arvore está balanceada
int balanceada(ARVORE *a){
        if(a==NULL) 
            return 1;
        else{
            if(balanceada(a->esq) == 0 || balanceada(a->dir) == 0)
                return 0;
            else {
                int he = Altura(a->esq);
                int hd = Altura(a->dir);
                if(abs(hd-hd)>1)
                    return 0;
                else 
                    return 1;
            }
        }
}

//7 - Verificar se uma árvore é cheia 
int ArvoreCheia(ARVORE *a){
    if(ContarArvore(a) == pow(2,Altura(a)-1)) 
        return 1;
    else   
        return 0;

}

//8 - Imprimir o nível de um nó x
void ImprimirNo(ARVORE *a, int No,int nivel){
    if (a!=NULL){
        if(a->info == No )
            printf("%d", nivel);
        else{
        ImprimirNo(a, No,nivel+1);
        ImprimirNo(a,No,nivel+1);
        }
    }
}
//9 - Sair
//Futuramente implementar o remover arvore