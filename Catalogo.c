#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Catalogo.h"

typedef struct nodo_catalogo{
	char nome[65];
	struct nodo_publicacoes *publicacoes;
	struct nodo_coautores *coautores;
	struct nodo_catalogo *left,*right;
	int ht;
}nodo_catalogo;

typedef struct nodo_publicacoes{
	int ano;
	int artigos;
	struct nodo_publicacoes *left, *right;
	int ht;
}nodo_publicacoes;

typedef struct nodo_coautores{
	int publicacoes;
	char nome[65];
	int ht;
	struct nodo_coautores *left, *right;
}nodo_coautores;

typedef struct lresult{
	char nome[65];
	struct lresult *next,*prev;
}lresult;

typedef struct lresult_q12{
	char nome[65];
	int pub;
	struct lresult_q12 *next,*prev;
}lresult_q12;

result insere_rlista (result l, char *s){
	result novo,aux,ant;
	novo = malloc (sizeof (struct lresult));
	strcpy (novo->nome, s);
	novo->next = NULL;
        if (l==NULL){
		l = novo;
		l->prev = NULL;
		return l;
		}
	else {
		for (aux=l;aux->next!=NULL;aux=aux->next);
		ant = aux;
		aux->next = novo;
		novo->prev = ant;
		return l;
		}
}

result_q12 insere_rlista_q12 (result_q12 l, char *s, int p){
	result_q12 novo,aux,ant;
	novo = malloc (sizeof (struct lresult_q12));
	strcpy (novo->nome, s);
	novo->next = NULL;
	novo->pub = p;
	if (l==NULL){
		l = novo;
		l->prev = NULL;
		return l;
		}
	else {
		for (aux=l;aux->next!=NULL;aux=aux->next);
		ant = aux;
		aux->next = novo;
		novo->prev = ant;
		return l;
		}
}
		

int height_publicacoes(avl_p T){
        int lh,rh;
        if(T==NULL) return(0);
        if(T->left==NULL) lh=0;
        else lh=1+T->left->ht;
        if(T->right==NULL) rh=0;
        else rh=1+T->right->ht;
        if(lh>rh) return(lh);
        return(rh);
}

avl_p rotateright_publicacoes(avl_p x){
        avl_p y;
        y=x->left;
        x->left=y->right;
        y->right=x;
        x->ht=height_publicacoes(x);
        y->ht=height_publicacoes(y);
        return(y);
}

avl_p rotateleft_publicacoes(avl_p x){
        avl_p y;
        y=x->right;
        x->right=y->left;
        y->left=x;
        x->ht=height_publicacoes(x);
        y->ht=height_publicacoes(y);
        return(y);
}

avl_p RR_publicacoes(avl_p T){
        T=rotateleft_publicacoes(T);
        return(T);
}

avl_p LL_publicacoes(avl_p T){
        T=rotateright_publicacoes(T);
        return(T);
}

avl_p LR_publicacoes(avl_p T){
        T->left=rotateleft_publicacoes(T->left);
        T=rotateright_publicacoes(T);
        return(T);
}

avl_p RL_publicacoes(avl_p T){
        T->right=rotateright_publicacoes(T->right);
        T=rotateleft_publicacoes(T);
return(T);
}

int BF_publicacoes(avl_p T){
        int lh,rh;
        if(T==NULL) return 0;
        if(T->left==NULL) lh=0;
        else  lh=1+T->left->ht;
        if(T->right==NULL) rh=0;
        else rh=1+T->right->ht;
        return(lh-rh);
}


int height_coautores(avl_c T){
        int lh,rh;
        if(T==NULL) return(0);
        if(T->left==NULL) lh=0;
        else lh=1+T->left->ht;
        if(T->right==NULL) rh=0;
        else rh=1+T->right->ht;
        if(lh>rh) return(lh);
        return(rh);
}

avl_c rotateright_coautores(avl_c x){
        avl_c y;
        y=x->left;
        x->left=y->right;
        y->right=x;
        x->ht=height_coautores(x);
        y->ht=height_coautores(y);
        return(y);
}

avl_c rotateleft_coautores(avl_c x){
        avl_c y;
        y=x->right;
        x->right=y->left;
        y->left=x;
        x->ht=height_coautores(x);
        y->ht=height_coautores(y);
        return(y);
}

avl_c RR_coautores(avl_c T){
        T=rotateleft_coautores(T);
        return(T);
}

avl_c LL_coautores(avl_c T){
        T=rotateright_coautores(T);
        return(T);
}

avl_c LR_coautores(avl_c T){
        T->left=rotateleft_coautores(T->left);
        T=rotateright_coautores(T);
        return(T);
}

avl_c RL_coautores(avl_c T){
        T->right=rotateright_coautores(T->right);
        T=rotateleft_coautores(T);
return(T);
}

int BF_coautores(avl_c T){
        int lh,rh;
        if(T==NULL) return 0;
        if(T->left==NULL) lh=0;
        else  lh=1+T->left->ht;
        if(T->right==NULL) rh=0;
        else rh=1+T->right->ht;
        return(lh-rh);
}

int height_catalogo(avl_catalogo T){
        int lh,rh;
        if(T==NULL) return(0);
        if(T->left==NULL) lh=0;
        else lh=1+T->left->ht;
        if(T->right==NULL) rh=0;
        else rh=1+T->right->ht;
        if(lh>rh) return(lh);
        return(rh);
}

avl_catalogo rotateright_catalogo(avl_catalogo x){
        avl_catalogo y;
        y=x->left;
        x->left=y->right;
        y->right=x;
        x->ht=height_catalogo(x);
        y->ht=height_catalogo(y);
        return(y);
}

avl_catalogo rotateleft_catalogo(avl_catalogo x){
        avl_catalogo y;
        y=x->right;
        x->right=y->left;
        y->left=x;
        x->ht=height_catalogo(x);
        y->ht=height_catalogo(y);
        return(y);
}

avl_catalogo RR_catalogo(avl_catalogo T){
        T=rotateleft_catalogo(T);
        return(T);
}

avl_catalogo LL_catalogo(avl_catalogo T){
        T=rotateright_catalogo(T);
        return(T);
}

avl_catalogo LR_catalogo(avl_catalogo T){
        T->left=rotateleft_catalogo(T->left);
        T=rotateright_catalogo(T);
        return(T);
}

avl_catalogo RL_catalogo(avl_catalogo T){
        T->right=rotateright_catalogo(T->right);
        T=rotateleft_catalogo(T);
return(T);
}

int BF_catalogo(avl_catalogo T){
        int lh,rh;
        if(T==NULL) return 0;
        if(T->left==NULL) lh=0;
        else  lh=1+T->left->ht;
        if(T->right==NULL) rh=0;
        else rh=1+T->right->ht;
        return(lh-rh);
}


avl_catalogo init_avlCatalogo (){
	avl_catalogo novo = NULL;
	return novo;
}

avl_catalogo insere_avlCatalogo (avl_catalogo l, char *nome){
	if (l==NULL){
		l=(avl_catalogo) malloc (sizeof (nodo_catalogo));
		strcpy (l->nome, nome);
		l->coautores = NULL;
		l->publicacoes = NULL; 
		l->left = NULL;
		l->right = NULL;
		}
        else if(strcmp(nome,l->nome)>0){
            l->right=insere_avlCatalogo(l->right,nome);
            if(BF_catalogo(l)==-2)
                if(strcmp(nome,l->right->nome)>0) l=RR_catalogo(l);
                else l=RL_catalogo(l);
        }
	else if (strcmp (nome, l->nome)==0) return l;
        else{
                l->left=insere_avlCatalogo(l->left,nome);
                if(BF_catalogo(l)==2)
                    if(strcmp(nome,l->left->nome)<0) l=LL_catalogo(l);
                    else l=LR_catalogo(l);
	 }
	l->ht=height_catalogo(l);
	return l;
}


		
      

avl_p insere_publicacoes (avl_p T, int a){
        if (T==NULL){
                T=(avl_p)malloc(sizeof(struct nodo_publicacoes));
                T->ano = a;
                T->artigos= 1;
                T->left = NULL;
                T->right = NULL;
                }
        else if (a>T->ano){
                T->right = insere_publicacoes (T->right,a);
                if (BF_publicacoes(T)==-2)
                        if (a>T->ano) T=RR_publicacoes(T);
                        else T=RL_publicacoes(T);
                }
        else if (a==T->ano) T->artigos ++;
        else if (a<T->ano) {
                T->left = insere_publicacoes (T->left, a);
                if (BF_publicacoes(T)==2)
                        if (a<T->ano) T==LL_publicacoes(T);
                        else T=LR_publicacoes(T);
                }
                T->ht = height_publicacoes(T);
                return (T);
}


avl_c insere_coautores(avl_c T,char *s){
        if(T==NULL){
                T=(avl_c)malloc(sizeof(struct nodo_coautores));
                strcpy (T->nome, s);
                T->publicacoes = 1;
                T->left=NULL;
                T->right=NULL;
        }
        else if(strcmp(s,T->nome)>0){
            T->right=insere_coautores(T->right,s);
            if(BF_coautores(T)==-2)
                if(strcmp(s,T->right->nome)>0) T=RR_coautores(T);
                else T=RL_coautores(T);
        }
        else if (strcmp(s,T->nome)==0) T->publicacoes++;
        else{
                T->left=insere_coautores(T->left,s);
                if(BF_coautores(T)==2)
                    if(strcmp(s,T->left->nome)<0) T=LL_coautores(T);
                    else T=LR_coautores(T);
            }
            T->ht=height_coautores(T);
            return(T);
}

avl_catalogo procura_posicao (avl_catalogo l, char *s){
	while (l!=NULL){
		if (strcmp (s,l->nome)==0) return l;
		else if (strcmp (s,l->nome)>0) l = procura_posicao (l->right,s);
		else l = procura_posicao (l->left,s);
		}
	return NULL;
}
	
avl_catalogo insere_catalogo (avl_catalogo l, char nomes[][65], int a, int tamanho){
	avl_catalogo aux;
	int i,j;
	for (i=0;i<tamanho;i++){
		l = insere_avlCatalogo (l,nomes[i]);
		aux = procura_posicao (l, nomes[i]);
		for (j=0;j<i;j++)
			aux->coautores = insere_coautores (aux->coautores, nomes[j]);
		for (j=i+1;j<tamanho;j++)
			aux->coautores = insere_coautores (aux->coautores, nomes[j]);
		aux->publicacoes = insere_publicacoes (aux->publicacoes, a);
		}
	return l;
}

int num_autores_solo (avl_catalogo l){
        int total=0;
        if (l!=NULL){
                if (l->coautores==NULL) total = 1 + num_autores_solo (l->left) + num_autores_solo (l->right);
                else total = num_autores_solo (l->left) + num_autores_solo (l->right);
                }
        return total;
}

int publicacoes_determinado_ano (avl_catalogo c, char *s,int ano){
	int resultado;
	avl_catalogo aux = procura_posicao (c,s);
	if (aux==NULL) return -1;
	avl_p pub= aux->publicacoes;
	resultado = procura_artigos (pub, ano);
	return resultado;
}

int procura_artigos (avl_p c, int a){
	avl_p p = c;
	while (p!=NULL){
		if (p->ano==a) return (p->artigos);
		if (a>p->ano) p=p->right;
		else p=p->left;	
		}
	return 0;
}

void total_anos (avl_p p, int anos[]){
	if (p!=NULL){
		total_anos (p->left, anos);
		anos[p->ano-1968] = p->artigos;
		total_anos (p->right, anos);
		}
}

void total_anos_final (avl_catalogo l, int anos[], char *s){
	avl_catalogo aux = procura_posicao (l,s);
	total_anos (aux->publicacoes, anos);
}

result maximo_publicacoes_coautor_final (avl_catalogo l, char *s){
	result r = NULL;
	avl_catalogo aux= procura_posicao (l,s);
	int maximo = maximo_publicacoes_coautor (aux->coautores,0);
	r = preenche_lista (r,aux->coautores,maximo);
	return r;
}

int maximo_publicacoes_coautor (avl_c c, int maximo){
	if (c!=NULL){
		if ((c->publicacoes)>maximo) maximo = c->publicacoes;
		maximo = maximo_publicacoes_coautor (c->left,maximo);
		maximo = maximo_publicacoes_coautor (c->right,maximo);
		}
	return maximo;
}

result preenche_lista (result r, avl_c c, int maximo){
	if (c!=NULL){
		if ((c->publicacoes)==maximo) r = insere_rlista (r,c->nome);
		r = preenche_lista (r, c->left, maximo);
		r = preenche_lista (r, c->right, maximo);
		}
	return r;
}

result print_rlist (result root, int opc){
        int i;
        result aux = root;
        while (root!=NULL)
                if (opc==2){
                        for (i=0;i<24 && root->next!=NULL;i++,root=root->next)
                                printf ("%s\n", root->nome);
			if (root!=NULL) printf ("%s\n", root->nome);
                        return root;
                        }
                else if (opc==1){
			for (i=0;i<48 && aux->prev!=NULL;aux=aux->prev,i++);
                        for (i=0;i<24 && aux!=NULL;i++, aux=aux->next)
                                printf ("%s\n", aux->nome);
                        return aux;
                        }
}

int verifica_publicacoes_intervalo (avl_p p, int ano_inf, int ano_sup){
	int i, flag=1;
	for (i=ano_inf;i<=ano_sup;i++)
		if ((verifica_publicacao_ano(p,i))==0) flag = 0;
	return flag;
}
	
	

int verifica_publicacao_ano (avl_p p, int ano){
	int flag=0;
	if (p!=NULL){
		if (p->ano == ano) flag = 1;
		else {
			 if (ano>p->ano) flag = verifica_publicacao_ano (p->right,ano);
		 	 else	flag = verifica_publicacao_ano (p->left,ano);
			}
	}
	return flag;
}

result preenche_lista_intervalo (result r, avl_catalogo c, int ano_inf, int ano_sup){
	if (c!=NULL){
		if (verifica_publicacoes_intervalo(c->publicacoes, ano_inf, ano_sup)==1) r = insere_rlista (r, c->nome);
		r = preenche_lista_intervalo (r, c->left, ano_inf, ano_sup);
		r = preenche_lista_intervalo (r, c->right, ano_inf, ano_sup);
		}
	return r;
}

result preenche_lista_intervalo_final (avl_catalogo c, int ano_inf, int ano_sup){
	result r = NULL;
	r = preenche_lista_intervalo (r,c,ano_inf,ano_sup);
	return r;
}



int length_rlista (result r){
	result aux;
	int total = 0;
	for (aux=r;aux!=NULL;aux=aux->next)
		total++;
	return total;
}

result_q12 trim_lista_q12 (result_q12 r, int n){
	result_q12 aux;
	int i=1;
	for (aux=r;i<n;aux=aux->next)
		i++;
	aux->next = NULL;
	return r;
}

int length_rlista_q12 (result_q12 r){
	result_q12 aux;
	int total = 0;
	for (aux=r;aux!=NULL;aux=aux->next)
		total++;
	return total;
}

int maximo_publicacoes (avl_catalogo c, int ano, int maximo){
	if (c!=NULL){
		if ((procura_artigos (c->publicacoes,ano))>maximo) maximo  = procura_artigos (c->publicacoes,ano);
		maximo = maximo_publicacoes (c->left,ano,maximo);
		maximo = maximo_publicacoes (c->right,ano,maximo);
		}
	return maximo;
}

result_q12 insere_rlista_autores_commais_publicacoes (avl_catalogo c, result_q12 r, int publicacoes, int ano){
	if (c!=NULL){
		if (procura_artigos (c->publicacoes,ano)==publicacoes) r = insere_rlista_q12 (r,c->nome,publicacoes);
		r = insere_rlista_autores_commais_publicacoes (c->left,r,publicacoes,ano);
		r = insere_rlista_autores_commais_publicacoes (c->right,r,publicacoes,ano);
		}
	return r;
}

result_q12 lista_publicacoes_nAutores (avl_catalogo c, int ano, int n){
	result_q12 r = NULL;
	int maximo = maximo_publicacoes (c,ano,0);
	while (maximo>0){
		r = insere_rlista_autores_commais_publicacoes (c,r,maximo,ano);
		if (length_rlista_q12 (r)> n){
			r = trim_lista_q12 (r,n);
			break;
			}
		maximo--;
		}
	return r;
}

result_q12 print_rlist_q12 (result_q12 root,int opc){
        int i;
        result_q12 aux = root;
        while (root!=NULL)
                if (opc==2){
                        for (i=0;i<24 && root->next!=NULL;i++,root=root->next)
                                printf ("%s - %d publicacões.\n", root->nome, root->pub);
			if (root!=NULL) printf ("%s - %d publicações.\n", root->nome, root->pub);
                        return root;
                        }
                else if (opc==1){
			for (i=0;i<48&&aux->prev!=NULL; aux=aux->prev, i++);
                        for (i=0;i<24 && aux!=NULL;i++, aux=aux->next)
                                printf ("%s - %d publicações.\n", aux->nome, aux->pub);
                        return aux;
                        }
}

void destroi_rlista (result r){
	result aux, ant;
        aux = r;
        while (aux!=NULL){
                ant = aux;
                aux = aux->next;
                free (ant);
                }
}

void destroi_rlista_q12 (result_q12 r){
        result_q12 aux, ant;
        aux = r;
        while (aux!=NULL){
                ant = aux;
                aux = aux->next;
                free (ant);
          	}
} 
