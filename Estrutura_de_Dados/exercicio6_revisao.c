#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Escreva	um	programa	em	C	para	ler	a	quantidade	L	de	linhas	(máximo	10)	e	a	quantidade	C	de	colunas	
// (máximo	10)	de	uma	matriz.	A	seguir	ler	uma	matriz	L	x	C	(considere	que	serão	informados	apenas	valores	
// positivos).	A	seguir	ler	uma	quantidade	indeterminada	de	valores.	Para	cada	valor	escrever	uma	mensagem	
// indicando	 se	 ele	 está	 ou	 não	 armazenado	 na	 matriz.	 Para	 cada	 valor	 informado,	 a	 mensagem	 deve	 ser	
// impressa	apenas	uma	vez.	O	programa	termina	ao	ser	informado	um	valor	negativo.

int main (void){
    int l, c, i, j, flag = 0, contador = 0, valor;

    srand(time(NULL));

    do {
        printf("Digite a quantidade de linhas da matriz: ");
        scanf("%d", &l);
        if (l > 10 || l < 1) {
            printf("Somente valores entre 1 e 10\n");
            getchar();
            getchar();
            system("clear");
        }
    } while (l > 10 || l < 1);
   

    do {
        printf("Digite a quantidade de colunas da matriz: ");
         scanf("%d", &c);
         if (c <= 0) {
            printf("Somente valores positivos.\n");
            getchar();
            getchar();
            system("clear");
         }
    }while (c <= 0);
    

    int matriz[l][c];
    
    for (i = 0; i < l; i++) {
        for(j = 0; j < c; j++){
            matriz[i][j] =  rand() % 20 + 1;
            printf("MATRIZ[%d][%d] = %d\n",i,j, matriz[i][j]);
        }
    }
    
    do {    
        printf("Digite um valor: ");
        scanf("%d", &valor);
        if(valor < 0) break;
        flag = 0;
        for (i = 0; i < l; i++) {
            if (flag == 1 ) break;
            for(j = 0; j < c; j++){
                    if (matriz[i][j] == valor){
                        printf("O valor está na matriz.\n");
                        flag = 1;
                        break;
                    } 
                    if (i == l-1 && j == c-1) {
                        printf("O valor não está na matriz.\n");
                        flag = 1;
                        break;
                    }             
                }
            }
    } while (valor > 0 );
   
    
    
    return 0;
}