// 3.1 Definir um tipo chamado Horario para armazenar um horario composto de: hora, minuto, segundo.
// Escreva um programa em C para ler dois horarios. Escreva o menor horario no formato HH:MM:SS. No caso de
// igualdade escrever a mensagem "Horarios iguais".

#include <stdio.h>
#include <stdlib.h>

typedef struct struct1
{
    int horas, minutos, segundos;
} Horario; 


void comparaHorarios(Horario horario[2]);

int main (void) {
   Horario horario[2];
   int contador = 0;

   while (contador < 2) {
        do {
                printf("Digite o %dº horário no formato: HH:MM:SS\n", contador + 1);
                printf("Digite a hora: ");
                scanf("%d", &horario[contador].horas);
                if (horario[contador].horas < 0) {
                    printf("Não serão aceitos horários negativos.\n");
                    getchar();
                    getchar();
                    system("clear");
                } 
                if (horario[contador].horas > 23) {
                    printf("Não serão aceitos números maiores que 23.\n");
                    getchar();
                    getchar();
                    system("clear");
                } 
    

        } while (horario[contador].horas < 0 || horario[contador].horas > 23);

        do {
            printf("Digite os minutos: ");
            scanf("%d", &horario[contador].minutos);
            if (horario[contador].minutos < 0) {
                printf("Não serão aceitos minutos negativos.\n");
                getchar();
                getchar();
                system("clear");
            } 
            if (horario[contador].minutos > 60) {
                printf("Não serão aceitos números maiores que 59.\n");
                getchar();
                getchar();
                system("clear");
            } 

        } while (horario[contador].minutos < 0 || horario[contador].minutos > 60);

        do {
            
            printf("Digite os segundos: ");
            scanf("%d", &horario[contador].segundos);
            if (horario[contador].segundos < 0) {
                printf("Não serão aceitos segundos negativos.\n");
                getchar();
                getchar();
                system("clear");
            } 
            if (horario[contador].segundos > 60) {
                printf("Não serão aceitos números maiores que 59.\n");
                getchar();
                getchar();
                system("clear");
            } 


        } while (horario[contador].segundos < 0);

        printf("Horário: %d:%d:%d\n", horario[contador].horas, horario[contador].minutos, horario[contador].segundos);
        printf("\n");
         

    contador++;
   }
   comparaHorarios(horario);
   
    return 0;
}

void comparaHorarios(Horario horario[2]) {

        if (horario[0].horas > horario[1].horas) {
            printf("O primeiro horário é maior.\n");
            return;
        } 

        if (horario[0].horas < horario[1].horas) {
            printf("O segundo horário é maior.\n");
            return;
        }
        
        if (horario[0].minutos > horario[1].minutos) {
            printf("O primeiro horário é maior.\n");
            return;
        }
        if (horario[0].minutos < horario[1].minutos) {
            printf("O segundo horário é maior.\n");
            return;
        } 
        if (horario[0].segundos > horario[1].segundos) {
            printf("O primeiro horário é maior.\n");
            return;
        }
        if (horario[0].segundos < horario[1].segundos) {
            printf("O segundo horário é maior\n");
            return;
        } else {
            printf("Os dois horários são iguais.\n");
            return;
        }
}