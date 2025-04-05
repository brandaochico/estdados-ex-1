#include<stdio.h>
#include<stdlib.h>

struct ALUNOS {
    int matricula;
    double g1, g2, media;
};

struct ALUNOS maiorMedia(struct ALUNOS alunos[], int n) {
    int indiceMaior = 0;
    for (int i = 1; i < n; i++) {
        if (alunos[i].media > alunos[indiceMaior].media) {
            indiceMaior = i;
        }
    }
    return alunos[indiceMaior];
}

void ordenarPorMedia(struct ALUNOS alunos[], int n) {
    for (int i = 1; i < n; i++) {
        struct ALUNOS atual = alunos[i];
        int j = i - 1;

        while (j >= 0 && alunos[j].media < atual.media) {
            alunos[j + 1] = alunos[j];
            j--;
        }

        alunos[j + 1] = atual;
    }
}

void imprimirVetorAlunos(struct ALUNOS alunos[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Matricula: %d, G1: %.2lf, G2: %.2lf, Media: %.2lf\n",
               alunos[i].matricula,
               alunos[i].g1,
               alunos[i].g2,
               alunos[i].media);
    }
}

int main() {
    int n;
    printf("Quantos alunos serão cadastrados? ");
    scanf("%d", &n);
    
    struct ALUNOS alunos[n];
    
    for(int i=0; i<n; i++) {
        printf("Aluno %d -----------------\n", i+1);
        printf("Informe a matrícula: ");
        scanf("%d", &alunos[i].matricula);
        
        printf("Informe a nota G1: ");
        scanf("%lf", &alunos[i].g1);
        
        printf("Informe a nota G2: ");
        scanf("%lf", &alunos[i].g2);
        
        alunos[i].media = (alunos[i].g1 + alunos[i].g2) / 2.0;
        printf("Média do aluno: %lf\n", alunos[i].media);
        
        printf("\n");
    }
    
    struct ALUNOS alunoComMaiorMedia = maiorMedia(alunos, n);
    
    printf("\nAluno com maior media:\n");
    printf("Matricula: %d | G1: %.2lf | G2: %.2lf | Media: %.2lf\n",
            alunoComMaiorMedia.matricula,
            alunoComMaiorMedia.g1,
            alunoComMaiorMedia.g2,
            alunoComMaiorMedia.media);
    
    printf("\n");
            
    ordenarPorMedia(alunos, n);
    printf("Médias ordenadas:\n");
    imprimirVetorAlunos(alunos, n);
    
    printf("\n");
    
    printf("Alunos em substituição:\n");
    for(int i=0; i<n; i++) {
        if(alunos[i].media < 6) {
            printf("Matricula: %d | G1: %.2lf | G2: %.2lf | Media: %.2lf\n",
                alunos[i].matricula,
                alunos[i].g1,
                alunos[i].g2,
                alunos[i].media);
        }
    }
}