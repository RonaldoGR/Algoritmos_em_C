/* Ler um vetor R de 5 elementos contendo o gabarito da LOTO. 
A seguir ler um vetor A de 10 elementos contendo uma aposta.
A seguir imprima quantos pontos fez o apostador. */ 

#include <stdio.h>
#include <stdlib.h>


int main(void) {
 int gabarito[5], numeros_jogados[10];
 int acerto = 0, i, j, duplicado;

 for (i = 0; i < 5; i++) {
  printf("GABARITO[%i] = ", i);
  scanf("%d", &gabarito[i]);
  system("clear");
 }

    
      for (i = 0; i < 10; i++) {
         do {
            duplicado = 0;
            
            printf("NUMEROS DO JOGADOR: ");
            scanf("%d", &numeros_jogados[i]);
        
            for(j = 0; j < i; j++) {
              if (numeros_jogados[i] == numeros_jogados[j]){
                  duplicado = 1;
                  printf("Não pode repetir números!\n");
                  getchar();
                  getchar();
                }
                system("clear");
              }
         } while (duplicado == 1);
       } 
  


for (i = 0; i < 5; i++) {
  for(j = 0; j < 10; j++) {
    if (gabarito[i] == numeros_jogados[j]) acerto++;
  }
}


printf("O jogador acertou %d dos números jogados\n", acerto);

}