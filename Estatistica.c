#include <stdio.h>
#include <stdlib.h>
#include "Estatistica.h"

typedef struct matriz{
        int tabela[50][10];
}matriz;

typedef struct node{
	int autores;
	int contador;
	struct node *next;
}node;


typedef struct casos_extra{
	struct node *extra[50];
}casos_extra;

matrix inicializa_matriz (){
	int i,j;
	matrix  new = (matrix) malloc (sizeof (struct matriz));
	for (i=0;i<50;i++){
		for (j=0;j<10;j++)
			new->tabela[i][j] = 0;
		}
	return new;
}

void insere_matriz (matrix m, int nomes, int ano){
	m->tabela[ano][nomes]++;
}

void display_matriz (matrix m){
	int i,j;
	for (i=0;i<46;i++){
		printf ("------------------%d-----------------------\n", i+1968);
		for (j=0;j<10;j++)
			printf ("Publicações com %d autores - %d\n", j+1, m->tabela[i][j]);
		}
}

listas inicializa_ArrayListas (){
	int i;
	listas novo = (listas) malloc(sizeof(struct casos_extra));
	for (i=0;i<50;i++)
		novo->extra[i]=NULL;
	return novo;
}

void insere_ArrayListas (listas l, int a, int aut){
	int ano = a-1968;
	l->extra[ano] = insere_lista (l->extra[ano], aut);
}
	
nodo insere_lista (nodo l, int n){
        if (l!=NULL){
                nodo aux,aux2;
                for (aux=l;aux!=NULL;aux=aux->next){
                        if (aux->autores==n){
                                aux->contador++;
                                return l;
                                }
                        aux2=aux;
                        }
                nodo novo = (nodo) malloc (sizeof (struct node));
                novo->autores = n;
                novo->contador = 1;
                novo->next = NULL;
                aux2->next = novo;
                return l;
                }
        else{
                nodo novo = (nodo) malloc (sizeof (struct node));
                novo->autores = n;
                novo->contador =1;
                novo->next = NULL;
                l = novo;
                return l;
                }
}



void imprime_lista (listas l){
	nodo aux;
	for (aux=l->extra[0];aux!=NULL;aux=aux->next)
		printf (" %d Autores, %d vezes\n", aux->autores, aux->contador);
}

void somatorio (int anos[], matrix m, listas l){
	somatorio_matriz (anos, m);
	somatorio_TotalLista (anos, l);
}
	
void somatorio_matriz (int anos[], matrix m){
	int i,j,total; 
	for (i=0;i<46;i++){
		total = 0;
		for (j=0;j<10;j++){
			total = total + m->tabela[i][j];
			}
		anos[i]=total;
		}
}

void somatorio_TotalLista (int anos[], listas l){
	int i;
	for (i=0;i<46;i++)
		anos[i] = anos[i]+ somatorio_lista (l->extra[i]);
}

int somatorio_lista (nodo n){
	int total=0;
	nodo aux;
	for (aux=n;aux!=NULL;aux=aux->next)
		total = total + aux->contador;
	return total;
}
			
int Nnum_intervalo (int a[], int inf, int sup){
	int i;
	int total=0;
	for (i=inf;i<=sup;i++)
		total = total + a[i];
	return total;
}

void numpub_primeiro_ate_terceiro (int anos [], int ano, matrix m){
	anos[0] = m->tabela[ano][0];
	anos[1] = m->tabela[ano][1];
	anos[2] = m->tabela[ano][2];
} 

void publicacoes_ano_array (matrix m, nodo root, int anos[], int ano){
	int i;
	nodo aux;
	for (i=0;i<50;i++)
		anos[i]=0;
	for (i=0;i<10;i++)
		if ((m->tabela[ano][i])!=0) anos[i]=m->tabela[ano][i];
	for (aux=root; aux!=NULL; aux=aux->next)
		anos[aux->autores-1] = aux->contador;
}

int publicacoes_ano (matrix m, listas l,int ano){
	int i;
	int total = 0;
	nodo aux;
	for (i=0;i<10;i++)
		total = total + m->tabela[ano][i];
	for (aux=l->extra[ano]; aux!=NULL; aux=aux->next)
		total = total + aux->contador;
	return total;
}
	

void tabela_excel (int anos[], matrix m, listas l, FILE *file){
	int i,j;
	for (i=0;i<46;i++){
		publicacoes_ano_array (m, l->extra[i], anos, i);
		for (j=0;j<46;j++)
			if (anos[j]!=0) fprintf (file, "\"%d\",\"%d\",\"%d\"\n", i+1968, j+1, anos[j]);
		}
}

int imprime_array (int anos[], int flag){
	int j;
	if (flag==1){
		for (j=0;j<24;j++)
			printf ("Ano %d - %d publicações.\n",j+1968,anos[j]);	
		return 1;
		}
	else if (flag==2){
		for (j=24;j<46;j++)
			printf ("Ano %d - %d publicações.\n", j+1968, anos[j]);
		return 2;
		}
	return -1;
}

