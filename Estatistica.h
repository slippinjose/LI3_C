#ifndef BST_h
#define BST_h

/*Matriz que guarda o número de publicações com 10 ou menos autores*/
typedef struct matriz *matrix;
/*Lista ligada simples que guarda o número de publicações com 11 ou mais autores */
typedef struct node *nodo;
/*Array de apontadores para listas ligadas simples, cada posição corresponde ao ano.*/
typedef struct casos_extra *listas;


/*			Operações sobre a Matriz 		*/
matrix inicializa_matriz ();
void insere (matrix , int , int);
/*			Operações sobre o Array com apontadores para listas ligadas simples 		*/
listas inicializa_ArrayListas();
void insere_ArrayListas (listas, int, int);
void imprime_lista (listas);
/*Função de inserção numa lista ligada simples.*/
nodo insere_lista (nodo , int);

/*Recebe um Array. Faz o somatório de artigos para cada ano da matriz e insere os valores nas respectivas posições do array.*/
void somatorio_matriz (int [], matrix);
/*Recebe uma lista ligada simples (que trata duma pequena parte dos casos) relativa a um ano e calcula todos os artigos desse ano.*/
int somatorio_lista (nodo);
/*Recebe um Array e invoca a função em cima referida sobre as listas ligadas de todos os anos adicionado esses valores às respectivas posições do array.*/
void somatorio_TotalLista (int [], listas);
/*Preenche o array com o número total de artigos dum ano nas respectivas posicões.*/
void somatorio (int [], matrix, listas);

/*Recebe um Array já preenchido, um limite inferior A e superior B dum dado intervalo. Retorna o somatório desde a posição A até B do array.*/
int Nnum_intervalo (int [], int, int);

/*Recebe como argumento um array e um inteiro A. Procura na matriz os três primeiros elementos do linha(ano) A e coloca esses elementos no array.*/
void numpub_primeiro_ate_terceiro (int [], int, matrix);

/*Recebe um Array, um inteiro A e preenche o array no qual cada posição N corresponde ao número de artigos com N+1 autores do ano A.*/ 
void publicacoes_ano_array (matrix , nodo, int [], int);

/*Função que retorna o número de artigos publicados num determinado ano.*/
int publicacoes_ano (matrix, listas, int);

/*Cria um ficheiro .csv com todos os artigos de todos os números de autores.*/
void tabela_excel (int [], matrix, listas, FILE *);

/*Função que permite ao utilizador consultar as tabelas, recuando ou avançado nelas.*/
int imprime_array (int [], int);
	
#endif                     
