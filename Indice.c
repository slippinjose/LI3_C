#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Indice.h"

typedef struct node{  
	char nome[256];
   	struct node *left,*right;
   	int ht;
}node;

typedef struct Alfabeto{
        struct node *letras[26];
}Alfabeto;


Node init_tree (){
	Node root = NULL;
	return root;
}


Node insert(Node T,char *s){
	if(T==NULL){
        	T=(Node)malloc(sizeof(struct node));
        	strcpy (T->nome, s);
        	T->left=NULL;
        	T->right=NULL;
    	}
    	else
        if(strcmp(s,T->nome)>0){
            T->right=insert(T->right,s);
            if(BF(T)==-2)                
		if(strcmp(s,T->right->nome)>0) T=RR(T);
                else T=RL(T);
        }
        else if(strcmp(s,T->nome)<=0){
                T->left=insert(T->left,s);
                if(BF(T)==2)
                    if(strcmp(s,T->left->nome)<=0) T=LL(T);
                    else T=LR(T);
            }
            T->ht=height(T);
            return(T);
}

int height(Node T){
	int lh,rh;
	if(T==NULL) return(0);
	if(T->left==NULL) lh=0;
	else lh=1+T->left->ht;
    	if(T->right==NULL) rh=0;
    	else rh=1+T->right->ht;
    	if(lh>rh) return(lh);
    	return(rh);
}

Node rotateright(Node x){
    	Node y;
    	y=x->left;
    	x->left=y->right;
    	y->right=x;
    	x->ht=height(x);
    	y->ht=height(y);
    	return(y);
}
Node rotateleft(Node x){
    	Node y;
    	y=x->right;
    	x->right=y->left;
    	y->left=x;
    	x->ht=height(x);
    	y->ht=height(y);
    	return(y);
}
Node RR(Node T){
    	T=rotateleft(T);
    	return(T);
}
Node LL(Node T){
    	T=rotateright(T);
    	return(T);
}
Node LR(Node T){
    	T->left=rotateleft(T->left);
    	T=rotateright(T);
    	return(T);
}
Node RL(Node T){
    	T->right=rotateright(T->right);
    	T=rotateleft(T);
return(T);
}

int BF(Node T){
	int lh,rh;
    	if(T==NULL) return 0;
    	if(T->left==NULL) lh=0;
    	else  lh=1+T->left->ht;
    	if(T->right==NULL) rh=0;
   	else rh=1+T->right->ht;
    	return(lh-rh);
}

Node findLeftmost(Node list) {
    if (!list->left) return list;
    return findLeftmost(list->left);
}

Node findRightmost(Node list) {
    if (!list->right) return list;
    return findRightmost(list->right);
}

Node avl2list(Node tree) {
    if (!tree) return NULL;

    if (tree->left) {
        tree->left=findRightmost(avl2list(tree->left));
        tree->left->right=tree;
    }
    if (tree->right) {
        tree->right=avl2list(tree->right);
        tree->right->left=tree;
    }
    return findLeftmost(tree);
}


Node printlist (Node root, int opc){
	int i;
	Node aux = root;
	while (root!=NULL)
		if (opc==2){
			for (i=0;i<24 && root!=NULL;i++,root=root->right)
				printf ("%s\n", root->nome);
			return root;
			}
		else if (opc==1){
			for (i=0;i<48;aux=aux->left,i++);
			for (i=0;i<24 && aux!=NULL;i++, aux=aux->right)
				printf ("%s\n", aux->nome);
			return aux;
			}
}


void inorder(Node T){
    	if(T!=NULL){
        	inorder(T->left);
        	printf("%s\n",T->nome);
        	inorder(T->right);
    	}
}


void insertion_path (Alfa a, char *s){
	if (s[0]=='A' || s[0]=='a') a->letras[0] = insert (a->letras[0], s);
        else if (s[0]=='B' || s[0]=='b') a->letras[1] = insert (a->letras[1], s);
        else if (s[0]=='C' || s[0]=='c') a->letras[2] = insert (a->letras[2], s);
        else if (s[0]=='D' || s[0]=='d') a->letras[3] = insert (a->letras[3], s);
        else if (s[0]=='E' || s[0]=='e') a->letras[4] = insert (a->letras[4], s);
        else if (s[0]=='F' || s[0]=='f') a->letras[5] = insert (a->letras[5], s);
        else if (s[0]=='G' || s[0]=='g') a->letras[6] = insert (a->letras[6], s);
        else if (s[0]=='H' || s[0]=='h') a->letras[7] = insert (a->letras[7], s);
        else if (s[0]=='I' || s[0]=='i') a->letras[8] = insert (a->letras[8], s);
        else if (s[0]=='J' || s[0]=='j') a->letras[9] = insert (a->letras[9], s);
        else if (s[0]=='K' || s[0]=='k') a->letras[10] = insert (a->letras[10], s);
        else if (s[0]=='L' || s[0]=='l') a->letras[11] = insert (a->letras[11], s);
        else if (s[0]=='M' || s[0]=='m') a->letras[12] = insert (a->letras[12], s);
        else if (s[0]=='N' || s[0]=='n') a->letras[13] = insert (a->letras[13], s);
        else if (s[0]=='O' || s[0]=='o') a->letras[14] = insert (a->letras[14], s);
        else if (s[0]=='P' || s[0]=='p') a->letras[15] = insert (a->letras[15], s);
        else if (s[0]=='Q' || s[0]=='q') a->letras[16] = insert (a->letras[16], s);
        else if (s[0]=='R' || s[0]=='r') a->letras[17] = insert (a->letras[17], s);
        else if (s[0]=='S' || s[0]=='s') a->letras[18] = insert (a->letras[18], s);
        else if (s[0]=='T' || s[0]=='t') a->letras[19] = insert (a->letras[19], s);
        else if (s[0]=='U' || s[0]=='u') a->letras[20] = insert (a->letras[20], s);
        else if (s[0]=='V' || s[0]=='v') a->letras[21] = insert (a->letras[21], s);
        else if (s[0]=='W' || s[0]=='w') a->letras[22] = insert (a->letras[22], s);
        else if (s[0]=='X' || s[0]=='x') a->letras[23] = insert (a->letras[23], s);
        else if (s[0]=='Y' || s[0]=='y') a->letras[24] = insert (a->letras[24], s);
        else if (s[0]=='Z' || s[0]=='z') a->letras[25] = insert (a->letras[25], s);
        else a->letras[26] = insert (a->letras[26], s);
}

Node converte_arvore (Alfa a, char c){
	Node aux;
	if (c=='A' || c=='a') aux = avl2list (copia_arvore(a->letras[0]));
        else if (c=='B' || c=='b') aux=avl2list (copia_arvore(a->letras[1]));
        else if (c=='C' || c=='c') aux=avl2list (copia_arvore(a->letras[2]));
        else if (c=='D' || c=='d') aux=avl2list (copia_arvore(a->letras[3]));
        else if (c=='E' || c=='e') aux=avl2list (copia_arvore(a->letras[4]));
        else if (c=='F' || c=='f') aux=avl2list (copia_arvore(a->letras[5]));
        else if (c=='G' || c=='g') aux=avl2list (copia_arvore(a->letras[6]));
        else if (c=='H' || c=='h') aux=avl2list (copia_arvore(a->letras[7]));
        else if (c=='I' || c=='i') aux=avl2list (copia_arvore(a->letras[8]));
        else if (c=='J' || c=='j') aux=avl2list (copia_arvore(a->letras[9]));
        else if (c=='K' || c=='k') aux=avl2list (copia_arvore(a->letras[10]));
        else if (c=='L' || c=='l') aux=avl2list (copia_arvore(a->letras[11]));
        else if (c=='M' || c=='m') aux=avl2list (copia_arvore(a->letras[12]));
        else if (c=='N' || c=='n') aux=avl2list (copia_arvore(a->letras[13]));
        else if (c=='O' || c=='o') aux=avl2list (copia_arvore(a->letras[14]));
        else if (c=='P' || c=='p') aux=avl2list (copia_arvore(a->letras[15]));
        else if (c=='Q' || c=='q') aux=avl2list (copia_arvore(a->letras[16]));
        else if (c=='R' || c=='r') aux=avl2list (copia_arvore(a->letras[17]));
        else if (c=='S' || c=='s') aux=avl2list (copia_arvore(a->letras[18]));
        else if (c=='T' || c=='t') aux=avl2list (copia_arvore(a->letras[19]));
        else if (c=='U' || c=='u') aux=avl2list (copia_arvore(a->letras[20]));
        else if (c=='V' || c=='v') aux=avl2list (copia_arvore(a->letras[21]));
        else if (c=='W' || c=='w') aux=avl2list (copia_arvore(a->letras[22]));
        else if (c=='X' || c=='x') aux=avl2list (copia_arvore(a->letras[23]));
        else if (c=='Y' || c=='y') aux=avl2list (copia_arvore(a->letras[24]));
        else if (c=='Z' || c=='z') aux=avl2list (copia_arvore(a->letras[25]));
        else aux=avl2list (copia_arvore(a->letras[26]));
	return aux;
}


Alfa init_array () {
	int i;
	Alfa novo = (Alfa) malloc (sizeof (struct Alfabeto));
	for (i=0;i<26;i++)
		novo->letras[i]=NULL;
	return novo;
} 
     
void profiling_nomes (int anos[], Node t){
	if (t!=NULL){
		if ((strlen (t->nome))<anos[0]) anos[0] = strlen (t->nome);
		if ((strlen (t->nome))>anos[1]) anos[1] = strlen (t->nome);
		anos[2]++;
		anos[3] = anos[3] + strlen (t->nome);
		profiling_nomes (anos, t->left);
		profiling_nomes (anos, t->right);
		}
}	

void profiling_total (int anos[], Alfa a){
	int i;
	for (i=0;i<27;i++)
		profiling_nomes (anos, a->letras[i]);
}

int length_lista (Node root){
	int total = 0;
	Node aux;
	for (aux=root;aux!=NULL;aux=aux->right)
		total++;
	return total;
}

Node copia_arvore (Node r){
	Node new;
	if (r!=NULL){
		new = malloc (sizeof (struct node));
		strcpy (new->nome,r->nome);
		new->left = copia_arvore (r->left);
		new->right = copia_arvore (r->right);
		}
	else return NULL;
	return new;
}
		
void destroi_lista (Node r){
	Node aux, ant;
	aux = r;
	while (aux!=NULL){
		ant = aux;
		aux = aux->right;
		free (ant);
		}
}		
	
		
