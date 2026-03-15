#include <stdio.h>

#define horizontal 10
#define vertical 10

int main() {

     /*###########################
       # DECLARAÇÃO DE VARIÁVEIS #
       ###########################*/
    char coordenadas_letras[horizontal] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int coordenadas_numeros[vertical];
    int tabuleiro[horizontal][vertical];
    int navio_1[3] = {3, 3, 3};
    int navio_2[3] = {3, 3, 3};
    
    


    printf (" ### BATALHA NAVAL ###\n\n");
    printf("   ");

    /*#############################
      # POSICIONAMENTO DOS NAVIOS #
      #############################*/

      // *N* para números e *L* para letras
     for (int N = 0; N < vertical; N++){
        for (int L = 0; L < horizontal; L++){
            tabuleiro[N][L] = 0; // Preenchimento do tabuleiro com 0
        }
     }
            // Declaração de coordenadas dos navios  
            /* (C5, D5, D5) e (G4, G5, G6) 
              A B C D E F G H I J 
            1 0 0 0 0 0 0 0 0 0 0 
            2 0 0 0 0 0 0 0 0 0 0 
            3 0 0 0 0 0 0 0 0 0 0 
            4 0 0 0 0 0 0 3 0 0 0 
            5 0 0 3 3 3 0 3 0 0 0 
            6 0 0 0 0 0 0 3 0 0 0 
            7 0 0 0 0 0 0 0 0 0 0 
            8 0 0 0 0 0 0 0 0 0 0 
            9 0 0 0 0 0 0 0 0 0 0 
           10 0 0 0 0 0 0 0 0 0 0*/

           
                tabuleiro[4][2] = navio_1[0];
                tabuleiro[4][3] = navio_1[1];
                tabuleiro[4][4] = navio_1[2];
           
                tabuleiro[3][6] = navio_2[0];
                tabuleiro[4][6] = navio_2[1];
                tabuleiro[5][6] = navio_2[2];

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
        for(int k = 0; k < 10; k++){
             printf("%d ", tabuleiro[j][k]);
             /* Apresentação da tabela com os valores dos navios */  
            }
         printf("\n");

     }
     printf("\n");           

    return 0;
}
