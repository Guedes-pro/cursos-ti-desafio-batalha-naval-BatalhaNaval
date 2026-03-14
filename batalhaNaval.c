#include <stdio.h>


int main() {

    char coordenadas_letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int coordenadas_numeros[1][10];
    int tabuleiro[10][10];

    printf (" ### BATALHA NAVAL ###\n\n");
    printf("   ");

    for (int i = 0; i < 10; i++){
        printf("%c ", coordenadas_letras[i]);
    }
    printf("\n");

    for (int j = 0; j < 10; j++){
      if (j < 9){
         int a = (j + 1);
         coordenadas_numeros[0][j] = a; 
         printf(" %d ",coordenadas_numeros[0][j]); 

         for(int k = 0; k < 10; k++){
             tabuleiro[j][k] = 0;
             printf("%d ", tabuleiro[0][k]);
            }
         printf("\n");
        } else {
            int a = (j + 1);
         coordenadas_numeros[0][j] = a; 
         printf("%d ",coordenadas_numeros[0][j]); 

         for(int k = 0; k < 10; k++){
             tabuleiro[j][k] = 0;
             printf("%d ", tabuleiro[0][k]);
            }
         printf("\n");
        }
    }
                

    return 0;
}
