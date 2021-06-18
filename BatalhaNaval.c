#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

void explicacao(){
    printf( "BATALHA NAVAL\n"
            "Regras:\n"
            " Antes do início do jogo, cada jogador coloca os seus navios nos quadros, alinhados horizontalmente.\n"
            " O jogo é composto por 3 submarinos, 3 cruzadores e 2 porta aviões para ambos jogadores.\n"
            " Os navios não podem se sobrepor.\n"
            " Após os navios terem sido posicionados o jogo continua numa série de turnos.\n"
            " Em cada turno, um jogador atira em um quadrado do oponente.\n"
			" O quadrado é identificado pela número da linha (horizontal) e número da coluna (vertical).\n"
            " Caso acerte o disparo, o jogador poderá atirar novamente.\n\n"
            "Após atirar:\n"
            " X = TIRO NA ÁGUA (ERROU O TIRO)\n"
            " 1 = ACERTOU O SUBMARINO (1 CÉLULA)\n"
            " 2 = ACERTOU O CRUZADOR (2 CÉLULAS)\n"
            " 4 = ACERTOU O PORTA AVIÕES (4 CÉLULAS)\n");
}
void inicializa_campo(int primeiro_campo[10][10], int segundo_campo[10][10]){
    int linha, coluna;

    for(linha = 0;linha < 10; linha++){
        for(coluna = 0; coluna < 10; coluna++){
            primeiro_campo[linha][coluna] = 1;
            segundo_campo[linha][coluna] = 1;
        }
    }                    
}
void mostrar_campoj1(int primeiro_campo[10][10]){
    int linha, coluna;

    printf("\n\t    JOGADOR 1\n");
    printf("   0  1  2  3  4  5  6  7  8  9\n");

    for(linha = 0; linha < 10; linha++){
        printf("%d ", linha);
        for(coluna=0; coluna < 10; coluna++){
            if(primeiro_campo[linha][coluna] == 1){
                printf(" ~ ");
            }else if(primeiro_campo[linha][coluna] == 2){
                printf(" 1 ");  
            }else if(primeiro_campo[linha][coluna] == 3){
                printf(" 2 ");
            }else if(primeiro_campo[linha][coluna] == 4){
                printf(" 4 ");
            }else if(primeiro_campo[linha][coluna] == 5){
                printf(" X ");
            } 
        }
    printf("\n");
    }  
    printf("\n");
}
void mostrar_campoj2(int segundo_campo[10][10]){
    int linha, coluna;

    printf("\n\t    JOGADOR 2\n");
    printf("   0  1  2  3  4  5  6  7  8  9\n");

    for(linha = 0; linha < 10; linha++){
        printf("%d ", linha);
        for(coluna = 0; coluna < 10; coluna++){
            if(segundo_campo[linha][coluna] == 1){
                printf(" ~ ");
            }else if(segundo_campo[linha][coluna] == 2){
                printf(" 1 "); 
            }else if(segundo_campo[linha][coluna] == 3){
                printf(" 2 ");
            }else if(segundo_campo[linha][coluna] == 4){
                printf(" 4 ");
            }else if(segundo_campo[linha][coluna] == 5){
                printf(" X ");
            } 
        }
    printf("\n");
    }
}
void posiciona_submarinos_j1(int submarino_1a[2], int submarino_2a[2], int submarino_3a[2], int primeiro_campo[10][10]){
    printf("\nJOGADOR 1 POSICIONE OS SUBMARINOS");
    do{
    printf("\nDigite a linha do primeiro submarino: ");
    scanf("%d", &submarino_1a[0]);
    printf("Digite a coluna do primeiro submarino: ");
    scanf("%d", &submarino_1a[1]);
    if(submarino_1a[0] > 9 || submarino_1a[1] > 9){
        printf("Escolha inválida\n");
    }else{
        primeiro_campo[submarino_1a[0]][submarino_1a[1]] = 2;
    }
    }while(submarino_1a[0] > 9 || submarino_1a[1] > 9);
  
    do{
    printf("\nDigite a linha do segundo submarino: ");
    scanf("%d", &submarino_2a[0]);
    printf("Digite a coluna do segundo submarino: ");
    scanf("%d", &submarino_2a[1]);
    if(submarino_2a[0] > 9 || submarino_2a[1] > 9){
        printf("Escolha inválida\n");
    }else{
        primeiro_campo[submarino_2a[0]][submarino_2a[1]] = 2;
    }
    }while(submarino_2a[0] > 9 || submarino_2a[1] > 9);

    do{
    printf("\nDigite a linha do terceiro submarino: ");
    scanf("%d", &submarino_3a[0]);
    printf("Digite a coluna do terceiro submarino: ");
    scanf("%d", &submarino_3a[1]);
    if(submarino_3a[0] > 9 || submarino_3a[1] > 9){
        printf("Escolha inválida\n");
    }else{
        primeiro_campo[submarino_3a[0]][submarino_3a[1]] = 2;
    }
    }while(submarino_3a[0] > 9 || submarino_3a[1] > 9);
}
void posiciona_cruzadores_j1(int cruzador_1a[4], int cruzador_2a[4], int cruzador_3a[4], int primeiro_campo[10][10]){
    printf("\nJOGADOR 1 POSICIONE OS CRUZADORES");
    do{
    printf("\nDigite a linha do primeiro cruzador: ");
    scanf("%d", &cruzador_1a[0]);
    printf("Digite a coluna do primeiro cruzador: ");
    scanf("%d", &cruzador_1a[1]);
    cruzador_1a[2] = cruzador_1a[0];
    cruzador_1a[3] = cruzador_1a[1] + 1;
    if(cruzador_1a[0] > 9 || cruzador_1a[1] > 9 || cruzador_1a[3] > 9){
        printf("Escolha inválida\n");
    }else{
        primeiro_campo[cruzador_1a[0]][cruzador_1a[1]] = 3;
        primeiro_campo[cruzador_1a[2]][cruzador_1a[3]] = 3;  
    }
    }while(cruzador_1a[0] > 9 || cruzador_1a[1] > 9 || cruzador_1a[3] > 9);

    do{ 
    printf("\nDigite a linha do segundo cruzador: ");
    scanf("%d", &cruzador_2a[0]);
    printf("Digite a coluna do segundo cruzador: ");
    scanf("%d", &cruzador_2a[1]);
    cruzador_2a[2] = cruzador_2a[0];
    cruzador_2a[3] = cruzador_2a[1] + 1;
    if(cruzador_2a[0] > 9 || cruzador_2a[1] > 9 || cruzador_2a[3] > 9){
        printf("Escolha inválida\n");
    }else{
        primeiro_campo[cruzador_2a[0]][cruzador_2a[1]] = 3;
        primeiro_campo[cruzador_2a[2]][cruzador_2a[3]] = 3;  
    }
    }while(cruzador_2a[0] > 9 || cruzador_2a[1] > 9 || cruzador_2a[3] > 9);

    do{ 
    printf("\nDigite a linha do terceiro cruzador: ");
    scanf("%d", &cruzador_3a[0]);
    printf("Digite a coluna do terceiro cruzador: ");
    scanf("%d", &cruzador_3a[1]);
    cruzador_3a[2] = cruzador_3a[0];
    cruzador_3a[3] = cruzador_3a[1] + 1;
    if(cruzador_3a[0] > 9 || cruzador_3a[1] > 9 || cruzador_3a[3] > 9){
        printf("Escolha inválida\n");
    }else{
        primeiro_campo[cruzador_3a[0]][cruzador_3a[1]] = 3;
        primeiro_campo[cruzador_3a[2]][cruzador_3a[3]] = 3;  
    }
    }while(cruzador_3a[0] > 9 || cruzador_3a[1] > 9 || cruzador_3a[3] > 9);    
}
void posiciona_avioes_j1(int porta_avioes1a[8], int porta_avioes2a[8], int primeiro_campo[10][10]){
    printf("\nJOGADOR 1 POSICIONE OS PORTA AVIÕES");
    do{
    printf("\nDigite a linha do primeiro porta aviões: ");
    scanf("%d", &porta_avioes1a[0]);
    printf("Digite a coluna do primeiro porta aviões: ");
    scanf("%d", &porta_avioes1a[1]);
    porta_avioes1a[2] = porta_avioes1a[0];
    porta_avioes1a[3] = porta_avioes1a[1] + 1;
    porta_avioes1a[4] = porta_avioes1a[0];
    porta_avioes1a[5] = porta_avioes1a[3] + 1;
    porta_avioes1a[6] = porta_avioes1a[0];
    porta_avioes1a[7] = porta_avioes1a[5] + 1;
    if(porta_avioes1a[0] > 9 || porta_avioes1a[1] > 9 || porta_avioes1a[7] > 9){
        printf("Escolha inválida\n");
    }else{
        primeiro_campo[porta_avioes1a[0]][porta_avioes1a[1]] = 4;
        primeiro_campo[porta_avioes1a[2]][porta_avioes1a[3]] = 4;
        primeiro_campo[porta_avioes1a[4]][porta_avioes1a[5]] = 4;
        primeiro_campo[porta_avioes1a[6]][porta_avioes1a[7]] = 4;
    }
    }while(porta_avioes1a[0] > 9 || porta_avioes1a[1] > 9 || porta_avioes1a[7] > 9);
    
    do{
    printf("\nDigite a linha do segundo porta aviões: ");
    scanf("%d", &porta_avioes2a[0]);
    printf("Digite a coluna do segundo porta aviões: ");
    scanf("%d", &porta_avioes2a[1]);   
    porta_avioes2a[2] = porta_avioes2a[0];
    porta_avioes2a[3] = porta_avioes2a[1] + 1;
    porta_avioes2a[4] = porta_avioes2a[0];
    porta_avioes2a[5] = porta_avioes2a[3] + 1;
    porta_avioes2a[6] = porta_avioes2a[0];
    porta_avioes2a[7] = porta_avioes2a[5] + 1;
    if(porta_avioes2a[0] > 9 || porta_avioes2a[1] > 9 || porta_avioes2a[7] > 9){
        printf("Escolha inválida\n");
    }else{
        primeiro_campo[porta_avioes2a[0]][porta_avioes2a[1]] = 4;
        primeiro_campo[porta_avioes2a[2]][porta_avioes2a[3]] = 4;
        primeiro_campo[porta_avioes2a[4]][porta_avioes2a[5]] = 4;
        primeiro_campo[porta_avioes2a[6]][porta_avioes2a[7]] = 4; 
    }
    }while(porta_avioes2a[0] > 9 || porta_avioes2a[1] > 9 || porta_avioes2a[7] > 9);  
}
void posiciona_submarinos_j2(int submarino_1b[2], int submarino_2b[2], int submarino_3b[2], int segundo_campo[10][10]){
    printf("\nJOGADOR 2 POSICIONE OS SUBMARINOS");
    do{
    printf("\nDigite a linha do primeiro submarino: ");
    scanf("%d", &submarino_1b[0]);
    printf("Digite a coluna do primeiro submarino: ");
    scanf("%d", &submarino_1b[1]);
    if(submarino_1b[0] > 9 || submarino_1b[1] > 9){
        printf("Escolha inválida\n");
    }else{
        segundo_campo[submarino_1b[0]][submarino_1b[1]] = 2;
    }
    }while(submarino_1b[0] > 9 || submarino_1b[1] > 9);

    do{
    printf("\nDigite a linha do segundo submarino: ");
    scanf("%d", &submarino_2b[0]);
    printf("Digite a coluna do segundo submarino: ");
    scanf("%d", &submarino_2b[1]);
    if(submarino_2b[0] > 9 || submarino_2b[1] > 9){
        printf("Escolha inválida\n");
    }else{
        segundo_campo[submarino_2b[0]][submarino_2b[1]] = 2;
    }
    }while(submarino_2b[0] > 9 || submarino_2b[1] > 9);

    do{
    printf("\nDigite a linha do terceiro submarino: ");
    scanf("%d", &submarino_3b[0]);
    printf("Digite a coluna do terceiro submarino: ");
    scanf("%d", &submarino_3b[1]);
    if(submarino_3b[0] > 9 || submarino_3b[1] > 9){
        printf("Escolha inválida\n");
    }else{
        segundo_campo[submarino_3b[0]][submarino_3b[1]] = 2;
    }
    }while(submarino_3b[0] > 9 || submarino_3b[1] > 9);
}
void posiciona_cruzadores_j2(int cruzador_1b[4], int cruzador_2b[4], int cruzador_3b[4], int segundo_campo[10][10]){
    printf("\nJOGADOR 2 POSICIONE OS CRUZADORES");                     
    do{
    printf("\nDigite a linha do primeiro cruzador: ");
    scanf("%d", &cruzador_1b[0]);
    printf("Digite a coluna do primeiro cruzador: ");
    scanf("%d", &cruzador_1b[1]);
    cruzador_1b[2] = cruzador_1b[0];
    cruzador_1b[3] = cruzador_1b[1] + 1;
    if(cruzador_1b[0] > 9 || cruzador_1b[1] > 9 || cruzador_1b[3] > 9){
        printf("Escolha inválida\n");
    }else{
        segundo_campo[cruzador_1b[0]][cruzador_1b[1]] = 3;
        segundo_campo[cruzador_1b[2]][cruzador_1b[3]] = 3;
    }
    }while(cruzador_1b[0] > 9 || cruzador_1b[1] > 9 || cruzador_1b[3] > 9);

    do{
    printf("\nDigite a linha do segundo cruzador: ");
    scanf("%d", &cruzador_2b[0]);
    printf("Digite a coluna do segundo cruzador: ");
    scanf("%d", &cruzador_2b[1]);
    cruzador_2b[2] = cruzador_2b[0];
    cruzador_2b[3] = cruzador_2b[1] + 1;
    if(cruzador_2b[0] > 9 || cruzador_2b[1] > 9 || cruzador_2b[3] > 9){
        printf("Escolha inválida\n");
    }else{
        segundo_campo[cruzador_2b[0]][cruzador_2b[1]] = 3;
        segundo_campo[cruzador_2b[2]][cruzador_2b[3]] = 3;
    }
    }while(cruzador_2b[0] > 9 || cruzador_2b[1] > 9 || cruzador_2b[3] > 9);
    
    do{
    printf("\nDigite a linha do terceiro cruzador: ");
    scanf("%d", &cruzador_3b[0]);
    printf("Digite a coluna do terceiro cruzador: ");
    scanf("%d", &cruzador_3b[1]);
    cruzador_3b[2] = cruzador_3b[0];
    cruzador_3b[3] = cruzador_3b[1] + 1;
    if(cruzador_3b[0] > 9 || cruzador_3b[1] > 9 || cruzador_3b[3] > 9){
        printf("Escolha inválida\n");
    }else{
        segundo_campo[cruzador_3b[0]][cruzador_3b[1]] = 3;
        segundo_campo[cruzador_3b[2]][cruzador_3b[3]] = 3;
    }
    }while(cruzador_3b[0] > 9 || cruzador_3b[1] > 9 || cruzador_3b[3] > 9);
}
void posiciona_avioes_j2(int porta_avioes1b[8], int porta_avioes2b[8], int segundo_campo[10][10]){
    printf("\nJOGADOR 2 POSICIONE OS PORTA AVIÕES");
    do{
    printf("\nDigite a linha do primeiro porta aviões: ");
    scanf("%d", &porta_avioes1b[0]);
    printf("Digite a coluna do primeiro porta aviões: ");
    scanf("%d", &porta_avioes1b[1]);
    porta_avioes1b[2] = porta_avioes1b[0];
    porta_avioes1b[3] = porta_avioes1b[1] + 1;
    porta_avioes1b[4] = porta_avioes1b[0];
    porta_avioes1b[5] = porta_avioes1b[3] + 1;
    porta_avioes1b[6] = porta_avioes1b[0];
    porta_avioes1b[7] = porta_avioes1b[5] + 1;
    if(porta_avioes1b[0] > 9 || porta_avioes1b[1] > 9 || porta_avioes1b[7] > 9){
        printf("Escolha inválida\n");
    }else{
    segundo_campo[porta_avioes1b[0]][porta_avioes1b[1]] = 4;
    segundo_campo[porta_avioes1b[2]][porta_avioes1b[3]] = 4;
    segundo_campo[porta_avioes1b[4]][porta_avioes1b[5]] = 4;
    segundo_campo[porta_avioes1b[6]][porta_avioes1b[7]] = 4;
    }
    }while(porta_avioes1b[0] > 9 || porta_avioes1b[1] > 9 || porta_avioes1b[7] > 9);
   
    do{
    printf("\nDigite a linha do segundo porta aviões: ");
    scanf("%d", &porta_avioes2b[0]);
    printf("Digite a coluna do primeiro porta aviões: ");
    scanf("%d", &porta_avioes2b[1]);  
    porta_avioes2b[2] = porta_avioes2b[0];
    porta_avioes2b[3] = porta_avioes2b[1] + 1;
    porta_avioes2b[4] = porta_avioes2b[0];
    porta_avioes2b[5] = porta_avioes2b[3] + 1;
    porta_avioes2b[6] = porta_avioes2b[0];
    porta_avioes2b[7] = porta_avioes2b[5] + 1;
    if(porta_avioes2b[0] > 9 || porta_avioes2b[1] > 9 || porta_avioes2b[7] > 9){
        printf("Escolha inválida\n");
    }else{
    segundo_campo[porta_avioes2b[0]][porta_avioes2b[1]] = 4;
    segundo_campo[porta_avioes2b[2]][porta_avioes2b[3]] = 4;
    segundo_campo[porta_avioes2b[4]][porta_avioes2b[5]] = 4;
    segundo_campo[porta_avioes2b[6]][porta_avioes2b[7]] = 4;
    }
    }while(porta_avioes2b[0] > 9 || porta_avioes2b[1] > 9 || porta_avioes2b[7] > 9);
}
void atirar_j1(int tiro[2], int segundo_campo[10][10]){  
    do{
    printf("\nJOGADOR 1 PREPARE-SE PARA ATIRAR\n");
    printf("Digite a linha que deseja atirar: ");
    scanf("%d", &tiro[0]);
    printf("Digite a coluna que deseja atirar: ");
    scanf("%d", &tiro[1]);
    if(tiro[0] > 9 || tiro[1] > 9){
        printf("Escolha inválida\n");
    }else if(segundo_campo[tiro[0]][tiro[1]] != 1){
        printf("Você ja atirou nessa posição\n");
    }
    }while(tiro[0] > 9 || tiro[1] > 9 || segundo_campo[tiro[0]][tiro[1]] != 1);
}
void atirar_j2(int tiro_2[2], int primeiro_campo[10][10]){ 
    do{
    printf("\nJOGADOR 2 PREPARE-SE PARA ATIRAR\n");
    printf("Digite a linha que deseja atirar: ");
    scanf("%d", &tiro_2[0]);
    printf("Digite a coluna que deseja atirar: ");
    scanf("%d", &tiro_2[1]);
    if(tiro_2[0] > 9 || tiro_2[1] > 9){
        printf("Escolha inválida\n");
    }else if(primeiro_campo[tiro_2[0]][tiro_2[1]] != 1){
        printf("Você ja atirou nessa posição\n");
    }
    }while(tiro_2[0] > 9 || tiro_2[1] > 9 || primeiro_campo[tiro_2[0]][tiro_2[1]] != 1);
}
void acertou_navios_j1(int submarino_1a[2], int submarino_2a[2], int submarino_3a[2],
                    int cruzador_1a[4], int cruzador_2a[4], int cruzador_3a[4],
                    int porta_avioes1a[8], int porta_avioes2a[8], 
                    int tiro_2[2], int primeiro_campo[10][10]){
    
    if(submarino_1a[0] == tiro_2[0] && submarino_1a[1] == tiro_2[1]){
        primeiro_campo[tiro_2[0]][tiro_2[1]] = 2;
    }else if(submarino_2a[0] == tiro_2[0] && submarino_2a[1] == tiro_2[1]){
        primeiro_campo[tiro_2[0]][tiro_2[1]] = 2;   
    }else if(submarino_3a[0] == tiro_2[0] && submarino_3a[1] == tiro_2[1]){
        primeiro_campo[tiro_2[0]][tiro_2[1]] = 2;   
    }
    else if(cruzador_1a[0] == tiro_2[0] && cruzador_1a[1] == tiro_2[1]){
        primeiro_campo[tiro_2[0]][tiro_2[1]] = 3;   
    }else if(cruzador_1a[2] == tiro_2[0] && cruzador_1a[3] == tiro_2[1]){
        primeiro_campo[tiro_2[0]][tiro_2[1]] = 3;   
    }else if(cruzador_2a[0] == tiro_2[0] && cruzador_2a[1] == tiro_2[1]){
        primeiro_campo[tiro_2[0]][tiro_2[1]] = 3;  
    }else if(cruzador_2a[2] == tiro_2[0] && cruzador_2a[3] == tiro_2[1]){
        primeiro_campo[tiro_2[0]][tiro_2[1]] = 3;  
    }else if(cruzador_3a[0] == tiro_2[0] && cruzador_3a[1] == tiro_2[1]){
        primeiro_campo[tiro_2[0]][tiro_2[1]] = 3;   
    }else if(cruzador_3a[2] == tiro_2[0] && cruzador_3a[3] == tiro_2[1]){
        primeiro_campo[tiro_2[0]][tiro_2[1]] = 3;  
    }
    else if(porta_avioes1a[0] == tiro_2[0] && porta_avioes1a[1] == tiro_2[1]){
        primeiro_campo[tiro_2[0]][tiro_2[1]] = 4;  
    }else if(porta_avioes1a[2] == tiro_2[0] && porta_avioes1a[3] == tiro_2[1]){
        primeiro_campo[tiro_2[0]][tiro_2[1]] = 4;  
    }else if(porta_avioes1a[4] == tiro_2[0] && porta_avioes1a[5] == tiro_2[1]){
        primeiro_campo[tiro_2[0]][tiro_2[1]] = 4;  
    }else if(porta_avioes1a[6] == tiro_2[0] && porta_avioes1a[7] == tiro_2[1]){
        primeiro_campo[tiro_2[0]][tiro_2[1]] = 4;  
    }
    else if(porta_avioes2a[0] == tiro_2[0] && porta_avioes2a[1] == tiro_2[1]){
        primeiro_campo[tiro_2[0]][tiro_2[1]] = 4;  
    }else if(porta_avioes2a[2] == tiro_2[0] && porta_avioes2a[3] == tiro_2[1]){
        primeiro_campo[tiro_2[0]][tiro_2[1]] = 4;   
    }else if(porta_avioes2a[4] == tiro_2[0] && porta_avioes2a[5] == tiro_2[1]){
        primeiro_campo[tiro_2[0]][tiro_2[1]] = 4;   
    }else if(porta_avioes2a[6] == tiro_2[0] && porta_avioes2a[7] == tiro_2[1]){
        primeiro_campo[tiro_2[0]][tiro_2[1]] = 4;  
    }else{
        primeiro_campo[tiro_2[0]][tiro_2[1]] = 5;
    }    
}
void acertou_navios_j2(int submarino_1b[2], int submarino_2b[2], int submarino_3b[2],
                    int cruzador_1b[4], int cruzador_2b[4], int cruzador_3b[4],
                    int porta_avioes1b[8], int porta_avioes2b[8], 
                    int tiro[2], int segundo_campo[10][10]){
    
    if(submarino_1b[0] == tiro[0] && submarino_1b[1] == tiro[1]){
        segundo_campo[tiro[0]][tiro[1]] = 2;
    }else if(submarino_2b[0] == tiro[0] && submarino_2b[1] == tiro[1]){
        segundo_campo[tiro[0]][tiro[1]] = 2;     
    }else if(submarino_3b[0] == tiro[0] && submarino_3b[1] == tiro[1]){
        segundo_campo[tiro[0]][tiro[1]] = 2;     
    }
    else if(cruzador_1b[0] == tiro[0] && cruzador_1b[1] == tiro[1]){
        segundo_campo[tiro[0]][tiro[1]] = 3;   
    }else if(cruzador_1b[2] == tiro[0] && cruzador_1b[3] == tiro[1]){
        segundo_campo[tiro[0]][tiro[1]] = 3;    
    }else if(cruzador_2b[0] == tiro[0] && cruzador_2b[1] == tiro[1]){
        segundo_campo[tiro[0]][tiro[1]] = 3;   
    }else if(cruzador_2b[2] == tiro[0] && cruzador_2b[3] == tiro[1]){
        segundo_campo[tiro[0]][tiro[1]] = 3;      
    }else if(cruzador_3b[0] == tiro[0] && cruzador_3b[1] == tiro[1]){
        segundo_campo[tiro[0]][tiro[1]] = 3;       
    }else if(cruzador_3b[2] == tiro[0] && cruzador_3b[3] == tiro[1]){
        segundo_campo[tiro[0]][tiro[1]] = 3;     
    }  
    else if(porta_avioes1b[0] == tiro[0] && porta_avioes1b[1] == tiro[1]){
        segundo_campo[tiro[0]][tiro[1]] = 4;      
    }else if(porta_avioes1b[2] == tiro[0] && porta_avioes1b[3] == tiro[1]){
        segundo_campo[tiro[0]][tiro[1]] = 4;     
    }else if(porta_avioes1b[4] == tiro[0] && porta_avioes1b[5] == tiro[1]){
        segundo_campo[tiro[0]][tiro[1]] = 4;      
    }else if(porta_avioes1b[6] == tiro[0] && porta_avioes1b[7] == tiro[1]){
        segundo_campo[tiro[0]][tiro[1]] = 4;     
    }
    else if(porta_avioes2b[0] == tiro[0] && porta_avioes2b[1] == tiro[1]){
        segundo_campo[tiro[0]][tiro[1]] = 4;     
    }else if(porta_avioes2b[2] == tiro[0] && porta_avioes2b[3] == tiro[1]){
        segundo_campo[tiro[0]][tiro[1]] = 4;      
    }else if(porta_avioes2b[4] == tiro[0] && porta_avioes2b[5] == tiro[1]){
        segundo_campo[tiro[0]][tiro[1]] = 4;    
    }else if(porta_avioes2b[6] == tiro[0] && porta_avioes2b[7] == tiro[1]){
        segundo_campo[tiro[0]][tiro[1]] = 4;    
    }else{
        segundo_campo[tiro[0]][tiro[1]] = 5;
    }    
}
void vencedor(int acertou, int acertou2){
    if (acertou == 17){
        printf("JOGADOR 1 ATINGIU TODOS OS NAVIOS E VENCEU");
    }else if (acertou2 == 17){
        printf("JOGADOR 2 ATINGIU TODOS OS NAVIOS E VENCEU");
    }
}
int main(){
    setlocale(LC_ALL, "Portuguese");
    int acertou = 0;
    int primeiro_campo[10][10];
    int tiro_2[2];
    int submarino_1a[2], submarino_2a[2], submarino_3a[2];
    int cruzador_1a[4], cruzador_2a[4], cruzador_3a[4];
    int porta_avioes1a[8], porta_avioes2a[8];

    int acertou2 = 0;
    int segundo_campo[10][10];
    int tiro[2];
    int submarino_1b[2], submarino_2b[2], submarino_3b[2];
    int cruzador_1b[4], cruzador_2b[4], cruzador_3b[4];
    int porta_avioes1b[8], porta_avioes2b[8];

    explicacao();
    system("pause");
    system("cls");
    inicializa_campo(primeiro_campo, segundo_campo);
    
    mostrar_campoj1(primeiro_campo);
    posiciona_submarinos_j1(submarino_1a, submarino_2a, submarino_3a, primeiro_campo);
    system("cls");
    mostrar_campoj1(primeiro_campo);
    posiciona_cruzadores_j1(cruzador_1a,cruzador_2a,cruzador_3a, primeiro_campo);
    system("cls");
    mostrar_campoj1(primeiro_campo);
    posiciona_avioes_j1(porta_avioes1a,porta_avioes2a, primeiro_campo);
    system("cls");
    mostrar_campoj1(primeiro_campo);
    system("pause");
    system("cls");

    mostrar_campoj2(segundo_campo);
    posiciona_submarinos_j2(submarino_1b, submarino_2b, submarino_3b, segundo_campo);
    system("cls");
    mostrar_campoj2(segundo_campo);
    posiciona_cruzadores_j2(cruzador_1b,cruzador_2b,cruzador_3b, segundo_campo);
    system("cls");
    mostrar_campoj2(segundo_campo);
    posiciona_avioes_j2(porta_avioes1b, porta_avioes2b, segundo_campo);
    system("cls");
    mostrar_campoj2(segundo_campo);
    system("pause");
    system("cls");

    inicializa_campo(primeiro_campo, segundo_campo);

    while (acertou != 17 && acertou2 != 17){
        do{
        mostrar_campoj1(primeiro_campo);
        mostrar_campoj2(segundo_campo);
        atirar_j1(tiro, segundo_campo);
        acertou_navios_j2(submarino_1b, submarino_2b, submarino_3b,
                            cruzador_1b, cruzador_2b, cruzador_3b, porta_avioes1b, porta_avioes2b, 
                                tiro, segundo_campo);
            system("cls");
            if(segundo_campo[tiro[0]][tiro[1]] != 5){
                acertou ++;
            }
        }while(segundo_campo[tiro[0]][tiro[1]] != 5 && acertou != 17);
        
        if(acertou == 17){
            break;
        }
        do{
            mostrar_campoj1(primeiro_campo);
            mostrar_campoj2(segundo_campo);
            atirar_j2(tiro_2, primeiro_campo);
            acertou_navios_j1(submarino_1a, submarino_2a, submarino_3a,
                                cruzador_1a, cruzador_2a, cruzador_3a, porta_avioes1a, porta_avioes2a, 
                                    tiro_2, primeiro_campo);
            system("cls");
            if(primeiro_campo[tiro_2[0]][tiro_2[1]] != 5){
                acertou2 ++;
            }          
        }while (primeiro_campo[tiro_2[0]][tiro_2[1]] != 5 && acertou2 != 17);      
    }
    mostrar_campoj1(primeiro_campo);
    mostrar_campoj2(segundo_campo);
    printf("\nFIM DE JOGO\n");
    vencedor(acertou, acertou2);
}
