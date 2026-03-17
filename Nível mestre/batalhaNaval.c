#include <stdio.h>

#define horizontal 10
#define vertical 10

void cone(int tabuleiro[vertical][horizontal], int){}

int main() {

     /*###########################
       # DECLARAÇÃO DE VARIÁVEIS #
       ###########################*/
    char coordenadas_letras[horizontal] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int coordenadas_numeros[vertical];
    int tabuleiro[horizontal][vertical];
    int navio_1[3] = {3, 3, 3};
    int navio_2[3] = {3, 3, 3};
    int navio_3[3] = {3, 3, 3};
    int navio_4[3] = {3, 3, 3};

    
    
    


    printf (" ### BATALHA NAVAL ###\n\n");
    printf("   ");

    /*#############################
      # POSICIONAMENTO DOS NAVIOS #
      #############################*/

      // *N* para números e *L* para letras
     for (int N = 0; N < vertical; N++){
        for (int L = 0; L < horizontal; L++){
            tabuleiro[L][N] = 0; // Preenchimento do tabuleiro com 0
            // Declaração de coordenadas dos navios DIAGONAL
            if(L == N && N > 0 && N < 4){ 
             tabuleiro[L][N] = navio_1[N - 1];
            } else if((L + N) == 9 && N > 6){
             tabuleiro[L][N] = navio_2[N - 7];
            } 
            // Declaração de coordenadas dos navios VERTICAL/HORIZONTAL
            else if(L == 6 && N > 2 && N < 6){ 
             tabuleiro[L][N] = navio_3[N - 3];
            } else if(N == 4 && L > 1 && L < 5){
             tabuleiro[L][N] = navio_4[L - 2];
            }
        }
     }
        
            /* (C5, D5, D5), (G4, G5, G6), (B2, C3, D4) e (A10, B9, C8) 
              A B C D E F G H I J 
            1 0 0 0 0 0 0 0 0 0 0 
            2 0 3 0 0 0 0 0 0 0 0 
            3 0 0 3 0 0 0 0 0 0 0 
            4 0 0 0 3 0 0 3 0 0 0 
            5 0 0 3 3 3 0 3 0 0 0 
            6 0 0 0 0 0 0 3 0 0 0 
            7 0 0 0 0 0 0 0 0 0 0 
            8 0 0 3 0 0 0 0 0 0 0 
            9 0 3 0 0 0 0 0 0 0 0 
           10 3 0 0 0 0 0 0 0 0 0*/

           
       

    /*#############################
      # APRESENTAÇÃO DO TABULEIRO #
      #############################*/
      // COORDENADAS SUPERIORES (LETRAS) 
     for (int i = 0; i < horizontal; i++){
        printf("%c ", coordenadas_letras[i]);
     }
     printf("\n");

     // COORDENADAS LATERAIS (NÚMEROS) + POSICIONAMENTO
     for (int j = 0; j < vertical; j++){
         coordenadas_numeros[j] = (j + 1);
         printf("%2d ",coordenadas_numeros[j]);
         /* Aumento da casa decimal para organização do espaçamento da tabela */  
        for(int k = 0; k < vertical; k++){
             printf("%d ", tabuleiro[k][j]);
             /* Apresentação da tabela com os valores dos navios */  
            }
         printf("\n");

     }
     printf("\n");           

    return 0;
}
