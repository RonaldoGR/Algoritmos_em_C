#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(void) {
  char palavra[30];
  int letras, vogais = 0, i;

  printf("Digite uma palavra: ");
  scanf("%s", palavra);
  for(i = 0; i < 30; i++) {
    if (tolower(palavra[i]) == 'a' || tolower(palavra[i]) == 'e' || tolower(palavra[i]) == 'i' || tolower(palavra[i]) == 'o' || tolower(palavra[i]) == 'u') vogais++;
  }

  for(i = 0; palavra[i] != '\0'; i++){
    letras++;
  }
  // letras = strlen(palavra);
  printf("VOGAIS: %d\n", vogais);
  printf("NÚMERO DE LETRAS DA PALAVRA: %i\n", letras);
}

