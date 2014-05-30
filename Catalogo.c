#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Indice.h"
#include "Estatistica.h"
#include "Catalogo.h"

int le_inteiro (){
  int n;
	char input[20];
	fgets (input, 20, stdin);
	char *token;
	token = strtok(input, " ");
	n = atoi (token);
	return n;
}

char le_caracter(){
	char c;
	char input[5];
	fgets (input,5,stdin);
	c = input[0];
	return c;
}


char *trim(char *str){
        size_t len = 0;
        char *frontp = str - 1;
        char *endp = NULL;
        if( str == NULL )
                return NULL;
        if( str[0] == '\0' )
                return str;
        len = strlen(str);
        endp = str + len;
        while( isspace(*(++frontp)) );
        while( isspace(*(--endp)) && endp != frontp );
                if( str + len - 1 != endp )
                        *(endp + 1) = '\0';
        else if( frontp != str &&  endp == frontp )
                *str = '\0';
        endp = str;
        if( frontp != str ){
            while( *frontp ) *endp++ = *frontp++;
            *endp = '\0';
        }
        return str;
}

void imprime_barras (){
	printf ("--------------------------------------------\n--------------------------------------------\n");
}

void imprime_barra (){
	printf ("--------------------------------------------\n");
}
                
int main (){
	int auxiliar[46];	 	
	char entrada[15];
	char c;
	int opcao, ano1, ano2, intervalo,interrupt;
	char buffer[1024];
	char linha[50][65];
	char *token;
	int linhas, ano, nomes,max,min,i,j;
	float pag;
	linhas = ano = nomes = max = 0;min = 3000;interrupt=1;
	system ("clear");
	printf ("--------------------------------------------\n------------------GESTAUTS------------------\n");
	printf ("               Seja bem-vindo!\n\n");
	sleep (0.5); printf ("           -Prima Enter para continuar-\n");
	imprime_barras();
	while (getchar()!='\n');
	system ("clear") ; 
	printf ("Digite o nome do ficheiro que gostaria de ler (não se esqueça de terminar com .txt): \n");
	fgets (entrada,15,stdin);
	trim (entrada);
	Alfa array = init_array();
	matrix m = inicializa_matriz(); 
	listas l = inicializa_ArrayListas();
	avl_catalogo ca = init_avlCatalogo();
	FILE* file = fopen (entrada,"r");
	while (fgets (buffer, 1024, file)>0){
		token = strtok (buffer, ",");
		for(i=0;token!=NULL;i++){
			trim (token);
			if (isdigit (token[0])) ano = atoi (token); 
			else  strcpy (linha[i],token);
			token = strtok (NULL, ",");
			nomes++;
			}
		if (ano>max) max = ano;
		for (j=0;j<i-1;j++)
			insertion_path (array, linha[j]);
		ca = insere_catalogo (ca, linha, ano, i-1);
		if ((ano<min)&&(ano!=0)) min = ano;
		linhas ++; i--; 
		if (i<=10) insere_matriz (m, i-1, ano-1968);
		else insere_ArrayListas (l, ano, i);
	}
	printf ("O ficheiro tem o nome \"%s\". Tem %d publicações, %d nomes, e os anos variam entre [%d-%d].\n",entrada, linhas, nomes-linhas, min, max);
	while (interrupt!=0){
	printf ("-------------------------------------------\n------------------MENU---------------------\n");
	printf ("Escolha uma opção no seguinte menu:\n1. Publicações de todos os anos.\n2. Número de publicações dum determinado autor num determinado ano.\n");
	printf ("3. Número de autores que só publicaram a solo.\n4. Dado um autor, criar uma tabela com os artigos de ano a ano.\n5. Todos os nomes duma dada letra.\n");
	printf ("6. Número de publicações num intervalo fechado de anos.\n7. Dado um autor, determinar o nome dos coautores com quem mais publicou.\n");
	printf ("8. Dado um intervalo de anos, retornar todos os autores que publicaram nesse intervalo.\n9. Dado um ano, criar um ficheiro com as publicações de 1,2 ou 3 autores.\n");
	printf ("10. Criar um ficheiro CSV com as publicações de cada ano.\n11. Dado um ano, determinar a lista de N autores (dado pelo utilizador) com maior número de publicações.\n");
	printf ("12. Dado um ano e um autor, determinar a sua percentagem de publicações relativamente a esse ano.\n13. Comprimento médio dos nomes, nome mais curto e mais longo.\n");
	imprime_barras();
	printf ("Opcao:\n");
	opcao = le_inteiro();
	switch (opcao){
		case 1: somatorio (auxiliar, m, l);
			printf ("Página 1/2.\n");
			j= imprime_array (auxiliar,1);
			ano1=1;
			while (ano1==1||ano1==2){
				printf ("Digite 2 para avançar, 1 para recuar e qualquer outro número para sair.\n");
				ano1 = le_inteiro();
				if (j==1 && ano1==1) printf ("Não pode recuar mais.\n");
				else if (j==2 && ano1==2) printf ("Não pode avançar mais.\n");
				else if (ano1==1 || ano1==2){
					printf ("Pág. %d/2.\n", ano1);
					j=imprime_array (auxiliar, ano1);
					}
				}			
			break;
                case 2: printf ("Qual o nome do autor?\n");
                        fgets (buffer,50,stdin);
                        trim (buffer);
                        printf ("Quer o número de publicações de que ano?\n");
                        ano1 = le_inteiro();
                        ano2 = publicacoes_determinado_ano (ca,buffer,ano1);
                        if (ano2==-1){
                                 printf ("Esse nome não consta na base de dados.\n");
                                 break;
                                }
                        printf ("O autor %s publicou %d artigos em %d.\n", buffer, ano2, ano1);
                        break;

		case 3: ano2 = num_autores_solo (ca);
			printf ("O número de autores que só publicaram a solo é: %d.\n", ano2);
			break;
		case 4: printf ("Quer a tabela de que autor?\n");
			fgets (buffer, 50, stdin);
			trim (buffer);
			for (i=0;i<46;i++)
				auxiliar[i]=0;
			total_anos_final (ca,auxiliar,buffer);
			printf ("Tabela de publicações de %s:\n", buffer);
			ano1=1;
			printf ("Página 1/2\n");
			j = imprime_array (auxiliar,1);
			while (ano1==1||ano1==2){
				printf ("Digite 2 para avançar, 1 para recuar e qualquer outro número para sair.\n");
				ano1 = le_inteiro();	
				if (j==1 && ano1==1) printf ("Não pode recuar mais.\n");
				else if (j==2 && ano1==2) printf ("Não pode avançar mais.\n");
				else if (ano1==1 || ano1==2){
					printf ("Pág %d/2.\n",ano1);
					j=imprime_array (auxiliar,ano1);
					}
				}
			break;
		case 5: printf("Escolha a letra: \n");
			c = le_caracter();
			Node aux = converte_arvore (array, c);
			pag = (float) length_lista (aux)/24;
			if (pag>0 && pag<1) intervalo = 1;
			else if (pag>1) intervalo = (int) pag;
			printf ("\nEsta lista contém %d nomes dispostos em %d páginas, cada uma com 24 nomes.\n", (int)pag*24, (int)pag);
			printf ("Pág. 1/%d\n", intervalo);
			aux = printlist (aux,2);
			ano1 = 1; opcao = 1;
			while ((opcao==1||opcao==2)&& intervalo!=1){
				printf ("Digite 2 para avançar, 1 para recuar e 0 para sair.\n");
				opcao = le_inteiro();
				if (opcao==2) ano1++;
				if (opcao==1) ano1--;
				if (opcao==0) break;
				if (ano1<=0){
					printf ("Chegou ao início!\n");
					break;
					}
				if (ano1>=intervalo+1){
					printf ("Chegou ao fim!\n");
					break;
				}
				printf ("Pág. %d/%d\n", ano1, intervalo);
				aux = printlist (aux,opcao);
				}
			destroi_lista (aux);
			break;
		case 6: printf ("Qual o limite inferior?\n");
			ano1 = le_inteiro();
			printf ("E qual o limite superior?\n");
			ano2 = le_inteiro();
			somatorio (auxiliar, m, l);
			intervalo = Nnum_intervalo(auxiliar, ano1-1968, ano2-1968);
			printf ("Entre %d e %d houve %d publicações.\n", ano1, ano2, intervalo);
			break;
		case 7: printf ("Qual o nome do autor que deseja?\n");
			fgets (buffer,50,stdin);
			trim (buffer);
			result r = maximo_publicacoes_coautor_final (ca,buffer);
			pag = (float) length_rlista (r)/24;
			if (pag>0 && pag<1){
				 intervalo = 1;
				 printf ("\nEsta lista contém %d nomes.\n", length_rlista (r));
				}
			else if (pag>1) {
				intervalo = (int) pag;
				if (intervalo==1) intervalo = 2;
				printf ("\nEsta lista contém %d nomes dispostos em %d páginas, cada uma com 24 nomes.\n", length_rlista(r), intervalo);
				}
			printf ("Os coautores com quem o %s mais publicou foram:\n", buffer);
			printf ("Pág. 1/%d\n", intervalo); 
			ano1=1;opcao=1;
			r=print_rlist (r,2); 
			while ((opcao==1 || opcao == 2) && intervalo!=1){
				printf ("Digite 2 para avançar, 1 para recuar e 0 para sair.\n");	
				opcao = le_inteiro();
				if (opcao==2) ano1++;
				if (opcao==1) ano1--;
				if (opcao==0) break;
				if (ano1<=0){
					printf ("Chegou ao início!\n");
					break;
					}
				if (ano1>=intervalo+1){
					printf ("Chegou ao fim!\n");
					break;
					}
				printf ("Pág. %d/%d\n", ano1, intervalo);
				r = print_rlist (r,opcao);
				}
			destroi_rlista (r);
			break;
		case 8: printf ("Qual o limite inferior?\n");
			ano1 = le_inteiro();
			printf ("E qual o limite superior?\n");
			ano2 = le_inteiro();
			result r2 = preenche_lista_intervalo_final (ca, ano1,ano2);
			pag = (float) length_rlista (r2)/24;
			if (pag>0 && pag<1){
				 intervalo = 1;
				 printf ("\nEsta lista contém %d nomes.\n", length_rlista (r2));
				}
			else if (pag>1) {
				intervalo = (int)pag;
				if (intervalo==1) intervalo =2;
				printf ("\nEsta lista contém %d nomes dispostos em %d páginas, cada uma com 24 nomes.\n", length_rlista (r2), intervalo);
				}
			printf ("Pág. 1/%d.\n", intervalo); 
			ano1=1;opcao=1;
			r2 = print_rlist (r2,2);
			while ((opcao==1||opcao==2)&& intervalo!=1){
				printf ("Digite 2 para avançar, 1 para recuar e 0 para sair.\n");
				opcao = le_inteiro();
				if (opcao==2) ano1 ++;
				if (opcao==1) ano1--;	
				if (opcao==0) break;
				if (ano1<=0) {
					printf ("Chegou ao início!\n");
					break;
					}
				if (ano1>=intervalo+1){
					printf ("Chegou ao fim!\n");
					break;
					}
				printf ("Pág. %d/%d\n", ano1, intervalo);
				r2 = print_rlist (r2,opcao);
				}
			destroi_rlista (r2);
			break;
		case 9: printf ("Qual é o ano que pretende utilizar?\n");
			ano2 = le_inteiro();
			printf ("Qual o nome do ficheiro que pretende criar? (Não se esqueça de terminar com .txt)\n");
			fgets (buffer, 50, stdin);
			trim (buffer);
			file = fopen (buffer,"w+");
			numpub_primeiro_ate_terceiro (auxiliar, ano2-1968, m);
			fprintf (file, "Publicações de %d com: 1 Autor | 2 Autores | 3 Autores.\n",ano2);
			fprintf (file, " %d | %d | %d \n", auxiliar[0], auxiliar[1], auxiliar[2]);
			printf ("Foi criado o ficheiro com o nome \"%s\".\n", buffer);
			fclose (file);
			break;
		case 10: printf ("Qual o nome do ficheiro que pretende criar? (Não se esqueça de terminar com .csv)\n");
			 fgets (entrada, 15, stdin);
			 trim (entrada);
			 file = fopen (entrada,"w+");
			 fprintf (file, "\"Ano\",\"#Autores\",\"#Artigos\"\n");
			 tabela_excel (auxiliar, m, l, file);
			 printf ("Foi criado o ficheiro com o nome \"%s\".\n",entrada);
			 fclose (file);
			 break;
		case 11: printf ("Quer utilizar que ano?\n");
			 ano1 = le_inteiro();
			 printf ("Qual é o tamanho da lista de autores que quer?\n");
			 intervalo = le_inteiro();
			 result_q12 r3 = lista_publicacoes_nAutores (ca,ano1,intervalo);
			 pag = (float) length_rlista_q12 (r3)/24;
                         if (pag>0 && pag<1) intervalo = 1;
                         else if (pag>1){
				 intervalo = (int)pag;
				 if (intervalo==1) intervalo = 2;
				 printf ("\nOs %d nomes estão dispostos em %d páginas, cada uma com 24 nomes.\n", length_rlista_q12 (r3), intervalo);
				}
                         printf ("Pág. 1/%d.\n", intervalo);
			 r3 = print_rlist_q12 (r3,2);
                         ano1=1;opcao=1;
			 while ((opcao==1 || opcao==2)&& intervalo!=1){
                                printf ("Digite 2 para avançar, 1 para recuar e 0 para sair.\n");
                                opcao = le_inteiro();
                                if (opcao==2) ano1 ++;
                                if (opcao==1) ano1--;
				if (opcao==0) break;
                                if (ano1<=0) {
                                        printf ("Chegou ao início!\n");
                                        break;
                                        }
                                if (ano1>=intervalo+1){
                                        printf ("Chegou ao fim!\n");
                                        break;
                                        }
                                printf ("Pág. %d/%d\n", ano1, intervalo);
                                r3 = print_rlist_q12 (r3,opcao);
                                }
			 destroi_rlista_q12 (r3);
                         break;
		case 12: printf ("Digite o nome do autor:\n");
			 fgets (buffer, 50, stdin);
			 trim (buffer);
			 printf ("E quer a percentagem de publicacções relativas a que ano?\n");
			 ano1 = le_inteiro();
			 ano2 = publicacoes_determinado_ano (ca,buffer,ano1);
			 if (ano2==-1) {
				printf ("Esse autor não publicou nenhum artigo durante esse ano.\n");
				break;
				}
			intervalo = publicacoes_ano (m,l,ano1-1968);
			float percentagem = ((float)ano2/(float)intervalo)*100;
			printf ("A percentagem de publicações de %s em %d é de %.2f%%.\n", buffer, ano1, percentagem);
			break;
                case 13: auxiliar[0] = 3000;
                        auxiliar[1] = auxiliar [2] = auxiliar [3] = 0;
                        profiling_total (auxiliar, array);
                        float media = ((float)auxiliar[3]/(float)auxiliar[2]);
                        printf ("O comprimento médio é %.2f, o nome mais comprido tem %d caractéres e o mais curto tem %d.\n", media, auxiliar[1], auxiliar[0]);
                        break;
		default: printf ("ERRO!\n");
			 break;

		}
	imprime_barras();
	printf ("Se quiser sair do programa prima 0, caso contrário prima qualquer outro número.\n");
	interrupt = le_inteiro();
	system ("clear");
	}
	return 0;
}

