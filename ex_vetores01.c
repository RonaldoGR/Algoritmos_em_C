#include <stdio.h>
#include <stdlib.h>


int main(void) {
 int gabarito[5], numeros_jogados[10];
 int acerto = 0, i, j, k, duplicado = 0;

 for (i = 0; i < 5; i++) {
  printf("GABARITO[%i] = ", i);
  scanf("%d", &gabarito[i]);
  system("clear");
 }

 
    
      for (k = 0; k < 10; k++) {
         do {
            duplicado = 0;
            
            printf("NUMEROS_JOGADOS[%i] = ", k);
            scanf("%d", &numeros_jogados[k]);
        
            for(j = 0; j < k; j++) {
              if (numeros_jogados[k] == numeros_jogados[j]){
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