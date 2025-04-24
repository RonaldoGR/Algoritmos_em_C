#include <stdio.h>
#include <stdlib.h>
#include "filacf.h"

void criaFila(FilaCF *f){
     f->frente= 0;
     f->re= -1;
}

int insere(FilaCF *f,int dado){
   if (estaCheia(*f)) {
          return FILA_CHEIA;
     }
  
     f->re = (f->re + 1) % MAX_NODOS;
     f->v[f->re] = dado;
     return SUCESSO;


}

int retira(FilaCF *f,int *dado){
     if (estaVazia(*f)) {
          return FILA_VAZIA;
     }
     *dado = f->v[f->frente];
     f->frente = (f->frente + 1) % MAX_NODOS;
     return SUCESSO;     

}

int estaCheia(FilaCF f){
     if ((f.re + 1) % MAX_NODOS == f.frente) {
          return FILA_CHEIA;
     }
     return SUCESSO;
}

int estaVazia(FilaCF f){
     if (f.re == -1) {
          return FILA_VAZIA;
     }
     return SUCESSO;

}

int consulta(FilaCF f,int *dado){
 FilaCF f2;
    int i, d, resul, fr, re;
    
    fr = f.frente;
    re = f.re;
    criaFila(&f2);
    
    for (i=fr; i<=re; i++){
         retira(&f,&d);
         insere(&f2,d);
         if (*dado == d)
            resul= SUCESSO;
    }

    f.frente= fr;
    f.re= fr-1;
    for (i=f2.frente;i<=f2.re;i++){
         retira(&f2,&d);
         insere(&f,d);
    }
    return(resul);
}

void exibeFila(FilaCF f){
     int i;
     for (i=f.frente; i<=f.re; i++)
         printf("%d ", f.v[i]);
     printf("\nFr= %d - Re= %d\n\n",f.frente, f.re);      
}


// A lógica geral da função tenta **procurar um valor na fila (`consulta`) sem alterar o conteúdo original**, usando uma fila auxiliar. No entanto, há **problemas críticos** na implementação:

// ---

// ### ❌ **1. Loop `for (i = fr; i <= re; i++)` não funciona para fila circular**
// - A fila é circular. Quando `frente > re`, esse `for` simplesmente **não percorre a fila corretamente**.
// - Exemplo: se `frente = 4` e `re = 1`, esse `for` nem roda, mesmo com dados na fila.

// ---

// ### ❌ **2. `resul` pode ficar indefinido**
// - Se o dado **não for encontrado**, `resul` **nunca é inicializado** antes de ser retornado.

// ---

// ### ⚠️ **3. A fila original `f` é passada por valor**
// - Modificações como `f.frente = fr` e `f.re = fr - 1` **não afetam a fila original fora da função**. Isso pode dar falsa impressão de restauração.

// ---

// ### ⚠️ **4. O segundo `for` usa novamente `i = frente até re`, mesma limitação**
// - Mesmo erro do primeiro loop: não lida com fila circular corretamente.

// ---

// ### ✅ Resumo:
// A ideia está no caminho certo, mas precisa:
// - Lidar corretamente com fila circular (usar `% MAX_NODOS`)
// - Inicializar `resul`
// - Corrigir lógica de restauração
// - Garantir que a fila original permaneça inalterada

// Se quiser, posso te ajudar a reestruturar isso corretamente.