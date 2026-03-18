#include <stdio.h>

#define horizontal 10
#define vertical 10
#define tamanho_hab 5

//Void para inserir o CONE
void cone(int matriz[tamanho_hab][tamanho_hab]){
   int meio = tamanho_hab / 2;
   for(int i = 0; i < tamanho_hab; i++){
      for(int j = 0; j < tamanho_hab; j++){
         matriz[i][j] = 0;
         if (i <= meio && j >= meio - i && j <= meio + i){
            matriz[i][j] = 1;
         }
      }
   }
}
//Void para inserir a CRUZ
void cruz(int matriz[tamanho_hab][tamanho_hab]){
   int meio = tamanho_hab / 2;
   for(int i = 0; i < tamanho_hab; i++){
      for(int j = 0; j < tamanho_hab; j++){
         matriz[i][j] = 0;
         if (j == meio || i == meio){
            matriz[i][j] = 1;
         }
      }
   }
}
//Void para inserir o OCTAEDRO
void octaedro(int matriz[tamanho_hab][tamanho_hab]){
   int meio = tamanho_hab / 2;
   for(int i = 0; i < tamanho_hab; i++){
      for(int j = 0; j < tamanho_hab; j++){
         matriz[i][j] = 0;
         int largura = (i <= meio)? i : (tamanho_hab - (i + 1));
         if (j >= meio - largura && j <= meio + largura){
            matriz[i][j] = 1;
         }   
      }
   }
}

//Void para aplicar a Habilidade no tabuleiro
void aplicar_hab(int matriz[vertical][horizontal], int hab[tamanho_hab][tamanho_hab], int x, int y){
   /*Os valores x e y são coordenadas para aplicar a habilidade */
   int linha;
   int coluna;
   for(int i = 0; i < tamanho_hab; i++){
      for(int j = 0; j < tamanho_hab; j++){
         if (hab[i][j] == 1){ // Selecionando apenas os campos em que a habilidade aparece 
            linha = x + i;
            coluna = y + j;
            // condição para criar limite do tabuleiro na aplicação da Habilidade
            if (linha >= 0 && linha < vertical && coluna >= 0 && coluna < horizontal){
               matriz[linha][coluna] = 5; // valor que aparecerá no tabuleiro
            }
         }
      }
   }
}

int main() {

     /*###########################
       # DECLARAÇÃO DE VARIÁVEIS #
       ###########################*/
    char coordenadas_letras[horizontal] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int coordenadas_numeros[vertical];
    int tabuleiro[vertical][horizontal];
    int habilidade_cone[tamanho_hab][tamanho_hab];
    int habilidade_cruz[tamanho_hab][tamanho_hab];
    int habilidade_octaedro[tamanho_hab][tamanho_hab];
    int navio_1[3] = {3, 3, 3};
    int navio_2[3] = {3, 3, 3};
    int navio_3[3] = {3, 3, 3};
    int navio_4[3] = {3, 3, 3};

    
    
    


    printf (" ### BATALHA NAVAL ###\n\n");
    

    /*#############################
      # POSICIONAMENTO DOS NAVIOS #
      #############################*/

      // *i* para números e *j* para letras
     for (int i = 0; i < vertical; i++){
        for (int j = 0; j < horizontal; j++){
            tabuleiro[i][j] = 0; // Preenchimento do tabuleiro com 0
            // Declaração de coordenadas dos navios DIAGONAL
            if(i == j && j > 0 && j < 4){ 
             tabuleiro[i][j] = navio_1[i - 1];
            } else if((j + i) == 9 && j > 6){
             tabuleiro[i][j] = navio_2[j - 7];
            } 
            // Declaração de coordenadas dos navios VERTICAL/HORIZONTAL
            else if(i == 6 && j > 2 && j < 6){ 
             tabuleiro[i][j] = navio_3[j - 3];
            } else if(j == 4 && i > 1 && i < 5){
             tabuleiro[i][j] = navio_4[i - 2];
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

    cone(habilidade_cone);
    cruz(habilidade_cruz);
    octaedro(habilidade_octaedro);
     
    printf("\nHABILIDADE CONE:\n");

    for(int i = 0; i < tamanho_hab; i++){
       for(int j = 0; j < tamanho_hab; j++){
          printf("%d ", habilidade_cone[i][j]); 
         }
       printf("\n");
      }
      /* 0 0 0 1 0 0 0 
         0 0 1 1 1 0 0 
         0 1 1 1 1 1 0 
         1 1 1 1 1 1 1 
         0 0 0 0 0 0 0 
         0 0 0 0 0 0 0 
         0 0 0 0 0 0 0 */

    printf("\nHABILIDADE CRUZ:\n");
    for(int i = 0; i < tamanho_hab; i++){
       for(int j = 0; j < tamanho_hab; j++){
          printf("%d ", habilidade_cruz[i][j]); 
         }
       printf("\n");
      }
     /*  0 0 0 1 0 0 0 
         0 0 0 1 0 0 0 
         0 0 0 1 0 0 0 
         1 1 1 1 1 1 1 
         0 0 0 1 0 0 0 
         0 0 0 1 0 0 0 
         0 0 0 1 0 0 0 */

    printf("\nHABILIDADE OCTAEDRO:\n");  
    for(int i = 0; i < tamanho_hab; i++){
       for(int j = 0; j < tamanho_hab; j++){
          printf("%d ", habilidade_octaedro[i][j]); 
         }
       printf("\n");
      }
      /* 0 0 0 1 0 0 0 
         0 0 1 1 1 0 0 
         0 1 1 1 1 1 0 
         1 1 1 1 1 1 1 
         0 1 1 1 1 1 0 
         0 0 1 1 1 0 0 
         0 0 0 1 0 0 0  */

    printf("\n");

    /*#############################
      # APRESENTAÇÃO DO TABULEIRO #
      #############################*/
      
      // COORDENADAS DAS HABILIDADES
    aplicar_hab(tabuleiro, habilidade_cone, 0, 0);
    aplicar_hab(tabuleiro, habilidade_cruz, 4, 5);
    aplicar_hab(tabuleiro, habilidade_octaedro, 5, 0);

      // COORDENADAS SUPERIORES (LETRAS) 
    printf("   ");// organização das letras

    for (int i = 0; i < horizontal; i++){
        printf("%c ", coordenadas_letras[i]);
     }
    printf("\n");

     // COORDENADAS LATERAIS (NÚMEROS) + POSICIONAMENTO
    for (int i = 0; i < vertical; i++){
         coordenadas_numeros[i] = (i + 1);
         printf("%2d ",coordenadas_numeros[i]);
         /* Aumento da casa decimal para organização do espaçamento da tabela */  
       for(int j = 0; j < horizontal; j++){
             printf("%d ", tabuleiro[i][j]);
             /* Apresentação da tabela com os valores dos navios */ 
            }
         printf("\n");
     }
    printf("\n");  

          // APRESENTAÇÃOFINAL:

          /*  A B C D E F G H I J 
            1 0 0 5 0 0 0 0 0 0 3 
            2 0 5 5 5 0 0 0 0 3 0 
            3 5 5 5 5 5 0 0 3 0 0 
            4 0 0 0 3 3 0 0 0 0 0 
            5 0 0 0 0 3 0 0 5 0 0 
            6 0 0 5 0 0 0 0 5 0 0 
            7 0 5 5 5 3 5 5 5 5 5 
            8 5 5 5 5 5 0 0 5 0 0 
            9 0 5 5 5 0 0 0 5 0 0 
           10 0 0 5 0 0 0 0 0 0 0 */      

    return 0;
}
