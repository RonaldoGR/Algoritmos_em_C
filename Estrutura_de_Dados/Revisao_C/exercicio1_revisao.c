#include <stdio.h>
#include <stdlib.h>

// 1.1 Escreva	um	programa	em	C	para	ler	um	valor	Q	que	representa	a	quantidade	de	alunos	de	uma	turma.	A	
// seguir	 ler	 Q	 pares	 de	 dados	 contendo,	 cada	 um,	 a	 altura	 e	 um	 código	 para	 masculino	 (1)	 e	 outro	 para	
// feminino	(2)	de	cada	aluno.	Calcular	e	escrever:
// -A	altura	do	aluno mais	alto	da	turma.
// -A	média	de	altura	das	alunas

int main (void) {
    int codigo, Q, i, alunos = 0, alunas = 0;
    float altura, mediaAlturaAlunas, alunoMaisAlto = 0.0, somaAltura = 0.0;
   

  do {
    printf("Digite a quantidade de alunos da turma: ");
    scanf("%d", &Q);
    if (Q <= 0) {
        printf("Somente serão aceitos numeros positivos.\n");
        getchar();
        getchar();
    } 
  } while (Q <= 0);

    for (int i = 0; i < Q; i++) {
        do {
            printf("Digite a altura do aluno(a)(m): ");
            scanf("%f", &altura);
            if (altura < 0) {
                printf("Somente serão aceitas alturas maiores que 0.\n");
                getchar();
                getchar();
            }
        } while (altura < 0);
        do {
            printf("Digite 1 se o aluno(a) for do sexo masculino e 2 se for do sexo feminino: ");
            scanf("%d", &codigo);
            if (codigo != 1 && codigo != 2) {
                printf("Somente serão aceitos valores entre 1 e 2.\n");
                getchar();
                getchar();
            }
            
            if(codigo == 1) {
                alunos++;
                if (altura > alunoMaisAlto) alunoMaisAlto = altura;
            } else {
                alunas++;
                somaAltura += altura;
            }
        } while (codigo != 1 && codigo != 2);
    }

   

    mediaAlturaAlunas = somaAltura / alunas;
    printf("\n");
    printf("Media da altura das alunos: %.2f\n", mediaAlturaAlunas);
    printf("Aluno mais alto da turma: %.2f\n", alunoMaisAlto);

    return 0;
}