#ifndef Catalogo_h
#define Catalogo_h

/*AVL com os nomes dos autores e apontadores para as AVLs de co-autores e publicações.*/
typedef struct nodo_catalogo *avl_catalogo;
/*AVL de publicações.*/
typedef struct nodo_publicacoes *avl_p;
/*AVL de co-autores.*/
typedef struct nodo_coautores *avl_c;
/*Lista duplamente ligada usada para representar os resultados de todas as queries que retornem listas de nomes excepto a query 12.*/
typedef struct lresult *result;
/*Lista duplamente ligada especificamente criada para a query 12 pois a cada nome está associado um número de publicações.*/
typedef struct lresult_q12 *result_q12;


/*                 Operações sobre as listas duplamente ligadas
 Neste caso só há inserções.*/
result insere_rlista (result, char *);			        
result_q12 insre_rlista_q12 (result_q12, char *, int);    


/*                  Operações de balanceamento das três AVLs.      */
int height_publicacoes (avl_p);
avl_p rotateright_publicacoes (avl_p);
avl_p rotateleft_publicacoes (avl_p);
avl_p RR_publicacoes (avl_p);
avl_p LL_publicacoes (avl_p);
avl_p LR_publicacoes (avl_p);
avl_p RL_publicacoes (avl_p);
int BF_publicacoes (avl_p);

int height_coautores (avl_c);
avl_c rotateright_coautores (avl_c);
avl_c rotateleft_coautores (avl_c);
avl_c RR_coautores (avl_c);
avl_c LL_coautores (avl_c);
avl_c LR_coautores (avl_c);
avl_c RL_coautores (avl_c);
int BF_coautores (avl_c);

int height_catalogo (avl_catalogo);
avl_catalogo rotateright_catalogo (avl_catalogo);
avl_catalogo rotateleft_catalogo (avl_catalogo);
avl_catalogo RR_catalogo (avl_catalogo);
avl_catalogo LL_catalogo (avl_catalogo);
avl_catalogo LR_catalogo (avl_catalogo);
avl_catalogo RL_catalogo (avl_catalogo);
int BF_catalogo (avl_catalogo);


/*             Operações sobre as AVLs

Retorna o endereço do nodo cujo nome for igual ao que receber como parâmetro*/
avl_catalogo procura_posivao (avl_catalogo, char*);
/*Inicializa a AVL principal*/
avl_catalogo init_avlCatalogo ();
/*Função de inserção dum autor na AVL principal*/
avl_catalogo insere_avlCatalogo (avl_catalogo, char*);
/*Recebe como parâmetro um ano, e incrementa o número de artigos publicados nesse ano dum determinado autor*/                                  
avl_p insere_publicacoes (avl_p, int);
/*Função de inserção de um co-autor na árvore AVL dos co-autores*/
avl_c insere_coautores (avl_c, char*);
/*Recebe como argumento os nomes todos duma linha de texto, o ano e insere-os a todos nos respectivos lugares nas respectivas árvores.*/
avl_catalogo insere_catalogo (avl_catalogo, char[][65], int, int);


/*Percorre a AVL principal e retorna o número de autores que só publicaram a solo.*/
int num_autores_solo (avl_catalogo);                                                                               

/*Retorna quantas vezes um determinado autor publicou num determinado ano*/
int publicacoes_determinado_ano (avl_catalogo, char *, int);                                                       

/*Dado um ano, percorre uma AVL de publicações e retorna quantos artigos foram publicados nesse ano.*/
int procura_artigos (avl_p, int);
/*Dado uma AVL de publicações, preenche um array com o número de publicações em cada ano*/
void total_anos (avl_p, int[]);													
/*Recebe o nome do autor como argumento e invoca a função total_anos completar a tabela de publicações do determinado autor*/
void total_anos_final (avl_catalogo, int[], char *);

/*Função que percorre a AVL dos co-autores e retorna o número de artigos publicados com o co-autor com que mais publicou*/
int maximo_publicacoes_coautor (avl_c,int);
/*Função que retorna a lista final que contém os co-autores com quem mais o autor (recebido como parâmetro) publicou.*/					
result maximo_publicacoes_coautor_final (avl_catalogo, char *);
/*Recebe um inteiro N como parâmetro, percorre a AVL dos co-autores e insere numa lista duplamente ligada os co-autores que tiverem publicado N artigos com o autor*/
result preenche_lista (result, avl_c, int);

/*Recebe um ano como argumento, percorre a AVL de publicações e verifica se foi publicado algum artigo nesse ano.*/
int verifica_publicacao_ano (avl_p, int);
/*Recebe o limite inferior e superior dum intervalo de anos, invoca a função anterior sobre todos os anos para verificar se publicou em todos os anos desse intervalo*/
int verifica_publicacoes_intervalo (avl_p, int, int);
/*Recebe o limite inferior e superior dum intervalo, e insere numa lista duplamente ligada os autores que tenham publicado em todos os anos do intervalo*/
result preenche_lista_intervalo (result, avl_catalogo, int, int);
/*Faz o mesmo que a função em cima referida mas invoca a lista ligada.*/
result preenche_lista_intervalo_final (avl_catalogo, int, int);

/*Recebe uma lista duplamente ligada (comprimento>N) e um inteiro N. Retorna uma lista duplamente ligada só com os primeiros N elementos.*/
result_q12 trim_lista_q12 (result_q12 , int);
/*Retorna o número máximo de publicações de todos os autores dum determinado ano*/
int maximo_publicacoes (avl_catalogo, int, int);				
/*Recebe um inteiro N e um inteiro A. Insere numa lista duplamente ligada os autores que tenham publicado N artigos no ano A e retorna essa mesma lista*/
result_q12 insere_rlista_autores_commais_publicacoes (avl_catalogo,result_q12,int,int);                             
/*Recebe um inteiro N e um inteiro A. Retorna uma lista duplamente ligada que contém os N autores que mais artigos publicaram no ano A.*/
result_q12 lista_publicacoes_nAutores (avl_catalogo, int, int);	

/*Funções que retornam o comprimento das listas ligadas.*/					
int length_rlista_q12  (result_q12 r);										 				
int length_rlista (result r);

/*Estas funções tratam de imprimir os nomes contidos nas listas ligadas segundo a opção do utilizador, podendo recuar ou avançar na lista.*/
result_q12 print_rlist_q12 (result_q12, int);  				 
result print_rlist (result,int);

/*Estas funções libertam a memória das listas duplamente ligadas.*/
void destroi_rlista (result );
void destroi_rlista_q12 (result_q12 );
#endif
