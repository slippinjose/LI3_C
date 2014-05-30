#ifndef AVL_h
#define AVL_h

/*AVL de strings, cada string corresponde ao nome dum autor.*/
typedef struct node  *Node; 
/*Array de apontadores para AVLs de Strings, cada posição corresponde a uma letra.*/
typedef struct Alfabeto  *Alfa;

/*			Operações sobre o Array de apontadores para AVLs 		*/
/*Insere o nome do autor na respectiva árvore*/
void insertion_path (Alfa, char *);
Alfa init_array ();

/* 			Operações sobre a AVl			*/
Node init_tree ();
Node  insert(Node , char*);

/* 			Operações de balanceamento da AVL		*/
int   height(Node );
Node rotateright(Node );
Node rotateleft(Node );
Node RR(Node );
Node LL(Node );
Node LR(Node );
Node RL(Node );
int BF(Node );

/* 		Operações que transformam a AVL numa lista duplamente ligada 			*/
Node findLeftmost (Node );
Node findRightmost (Node );
Node avl2list (Node );
/*Função que determina qual a árvore que vai ser transformada numa lista duplamente ligada*/
Node converte_arvore (Alfa, char);

/*Recebe um Array. Percorre a AVL e vai preenchendo o array da seguinte forma: 0-Comprimento de nome mínimo; 1-Comprimento de nome máximo; 2-Número de nomes; 3-Somatório do comprimento dos nomes*/	
void profiling_nomes (int [], Node);
/*Invoca a função em cima referida sobre todas as AVLs. No fim, o array contém nas posicões em cima referidas os dados completos do ficheiro de texto.*/
void profiling_total (int [], Alfa ); 

/*Esta função trata de imprimir os nomes contidos na lista ligada segundo a opção do utilizador, podendo recuar ou avançar na lista.*/
Node printlist (Node, int);
/*Retorna o comprimento duma lista (neste caso um AVL recentemente transformada numa lista duplamente ligada)*/
int length_lista (Node );
/*Função que recebe uma árvore AVL, copia-a e returna o que foi copiado.*/
Node copia_arvore (Node );
/*Liberta a memória duma lista duplamente ligada.*/
void destroi_lista (Node );
#endif
