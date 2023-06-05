/*  JOGO CONNECT 4  */

#include<stdio.h>
#define qntd_linhas 6
#define qntd_colunas 7

void asteriscos();              
int escolher_posicao_peca(int vezjog);     
void mostrar_tabuleiro(int tabuleiro[qntd_linhas][qntd_colunas]);
void colocar_ficha(int col_escolhida, int tabuleiro[qntd_linhas][qntd_colunas], int jog);

int main()
{
    int jogador = 1, vencedor = 0, linha, coluna, coluna_escolhida, cont = 0;
    int tabuleiro_connect[qntd_linhas][qntd_colunas];

    for (linha = 0; linha < qntd_linhas; linha++)
    {
        for (coluna = 0; coluna < qntd_colunas; coluna++)
        {
            tabuleiro_connect[linha][coluna] = 0;
        }
    }

    printf("\nBEM-VINDO AO CONNECT 4\n");

    while (vencedor == 0)
    {
        coluna_escolhida = escolher_posicao_peca(jogador);
        printf("\n");
        colocar_ficha(coluna_escolhida, tabuleiro_connect, jogador);
        if (cont >= 6)
        {
            vencedor = verificar_vencedor(tabuleiro_connect);
        }


        if (jogador == 1)
        {
            jogador = 2;
        }
        else
        {
            jogador = 1;
        }
        cont++;
    }
    asteriscos();
    printf("Parabens! O jogador %d venceu.", vencedor);
    asteriscos();
}


int escolher_posicao_peca(int vezJog)
{
    int coluna_ficha;
    printf("\nVez do jogador %d: ", vezJog);
    do
    {
        printf("\nEscolha a coluna em que deseja colocar a ficha: ");
        scanf("%d", &coluna_ficha);
    } while (coluna_ficha <= 0 || coluna_ficha > 7);
    return coluna_ficha;
}

void asteriscos()
{
    printf("\n");
    for (int i = 0; i < 40; i++)
    {
        printf("*");
    }
    printf("\n");
}

void mostrar_tabuleiro(int tabuleiro[qntd_linhas][qntd_colunas])
{
    printf("    1   2   3   4   5   6   7");
    for (int i = 0; i < qntd_linhas; i++)
    {
        printf("\n%d |", i);
        for (int j = 0; j < qntd_colunas; j++)
        {
            printf(" %d |", tabuleiro[i][j]);
        }
    }
}

void colocar_ficha(int col_escolhida, int tabuleiro[qntd_linhas][qntd_colunas], int jog)
{
    for (int i = 0; i < qntd_linhas; i++)
    {
        for (int j = 0; j < qntd_colunas; j++)
        {
            if (col_escolhida == j + 1)
            {
                while (tabuleiro[i + 1][j] == 0 && i != qntd_linhas - 1)
                {
                    i++;
                }
                tabuleiro[i][j] = jog;
                mostrar_tabuleiro(tabuleiro);
                printf("\n\n");
                return 0;
            }
        }
    }
}

int verificar_vencedor(int tabuleiro[qntd_linhas][qntd_colunas])
{
    for (int i = 0; i < qntd_linhas; i++)
    {
        for (int j = 0; j < qntd_colunas; j++)
        {
            if (j == 0)
            {
                if (tabuleiro[0][j] == 1 && tabuleiro[1][j] == 1 
                    && tabuleiro[2][j] == 1 && tabuleiro[3][j] == 1)
                {
                    return 1;
                }
                else
                {
                    if (tabuleiro[1][j] == 1 && tabuleiro[2][j] == 1 
                        && tabuleiro[3][j] == 1 && tabuleiro[4][j] == 1)
                    {
                        return 1;
                    }
                    else
                    {
                        if (tabuleiro[2][j] == 1 && tabuleiro[3][j] == 1 
                            && tabuleiro[4][j] == 1 && tabuleiro[5][j] == 1)
                        {
                            return 1;
                        }
                    }
                }  
                if (tabuleiro[0][j] == 2 && tabuleiro[1][j] == 2 
                    && tabuleiro[2][j] == 2 && tabuleiro[3][j] == 2)
                {
                    return 2;
                }
                else
                {
                    if (tabuleiro[1][j] == 2 && tabuleiro[2][j] == 2 
                        && tabuleiro[3][j] == 2 && tabuleiro[4][j] == 2)
                    {
                        return 2;
                    }
                    else
                    {
                        if (tabuleiro[2][j] == 2 && tabuleiro[3][j] == 2 
                            && tabuleiro[4][j] == 2 && tabuleiro[5][j] == 2)
                        {
                            return 2;
                        }
                    }
                }  
            }
            else
            {
                if (j == 1)
                {
                    if (tabuleiro[0][j] == 1 && tabuleiro[1][j] == 1 
                        && tabuleiro[2][j] == 1 && tabuleiro[3][j] == 1)
                    {
                        return 1;
                    }
                    else
                    {
                        if (tabuleiro[1][j] == 1 && tabuleiro[2][j] == 1 
                            && tabuleiro[3][j] == 1 && tabuleiro[4][j] == 1)
                        {
                            return 1;
                        }
                        else
                        {
                            if (tabuleiro[2][j] == 1 && tabuleiro[3][j] == 1 
                                && tabuleiro[4][j] == 1 && tabuleiro[5][j] == 1)
                            {
                                return 1;
                            }
                        }
                    }  
                    if (tabuleiro[0][j] == 2 && tabuleiro[1][j] == 2 
                        && tabuleiro[2][j] == 2 && tabuleiro[3][j] == 2)
                    {
                        return 2;
                    }
                    else
                    {
                        if (tabuleiro[1][j] == 2 && tabuleiro[2][j] == 2 
                            && tabuleiro[3][j] == 2 && tabuleiro[4][j] == 2)
                        {
                            return 2;
                        }
                        else
                        {
                            if (tabuleiro[2][j] == 2 && tabuleiro[3][j] == 2 
                                && tabuleiro[4][j] == 2 && tabuleiro[5][j] == 2)
                            {
                                return 2;
                            }
                        }
                    }  
                }
                else
                {
                    if (j == 2)
                    {
                        if (tabuleiro[0][j] == 1 && tabuleiro[1][j] == 1 
                            && tabuleiro[2][j] == 1 && tabuleiro[3][j] == 1)
                        {
                            return 1;
                        }
                        else
                        {
                            if (tabuleiro[1][j] == 1 && tabuleiro[2][j] == 1 
                                && tabuleiro[3][j] == 1 && tabuleiro[4][j] == 1)
                            {
                                return 1;
                            }
                            else
                            {
                                if (tabuleiro[2][j] == 1 && tabuleiro[3][j] == 1 
                                    && tabuleiro[4][j] == 1 && tabuleiro[5][j] == 1)
                                {
                                    return 1;
                                }
                            }
                        }  
                        if (tabuleiro[0][j] == 2 && tabuleiro[1][j] == 2 
                            && tabuleiro[2][j] == 2 && tabuleiro[3][j] == 2)
                        {
                            return 2;
                        }
                        else
                        {
                            if (tabuleiro[1][j] == 2 && tabuleiro[2][j] == 2 
                                && tabuleiro[3][j] == 2 && tabuleiro[4][j] == 2)
                            {
                                return 2;
                            }
                            else
                            {
                                if (tabuleiro[2][j] == 2 && tabuleiro[3][j] == 2 
                                    && tabuleiro[4][j] == 2 && tabuleiro[5][j] == 2)
                                {
                                    return 2;
                                }
                            }
                        }  
                    }
                    else
                    {
                        if (j == 3)
                        {
                            if (tabuleiro[0][j] == 1 && tabuleiro[1][j] == 1 
                                && tabuleiro[2][j] == 1 && tabuleiro[3][j] == 1)
                            {
                                return 1;
                            }
                            else
                            {
                                if (tabuleiro[1][j] == 1 && tabuleiro[2][j] == 1 
                                    && tabuleiro[3][j] == 1 && tabuleiro[4][j] == 1)
                                {
                                    return 1;
                                }
                                else
                                {
                                    if (tabuleiro[2][j] == 1 && tabuleiro[3][j] == 1 
                                        && tabuleiro[4][j] == 1 && tabuleiro[5][j] == 1)
                                    {
                                        return 1;
                                    }
                                }
                            }  
                            if (tabuleiro[0][j] == 2 && tabuleiro[1][j] == 2 
                                && tabuleiro[2][j] == 2 && tabuleiro[3][j] == 2)
                            {
                                return 2;
                            }
                            else
                            {
                                if (tabuleiro[1][j] == 2 && tabuleiro[2][j] == 2 
                                    && tabuleiro[3][j] == 2 && tabuleiro[4][j] == 2)
                                {
                                    return 2;
                                }
                                else
                                {
                                    if (tabuleiro[2][j] == 2 && tabuleiro[3][j] == 2 
                                        && tabuleiro[4][j] == 2 && tabuleiro[5][j] == 2)
                                    {
                                        return 2;
                                    }
                                }
                            }  
                        }
                        else
                        {
                            if (j == 4)
                            {
                                if (tabuleiro[0][j] == 1 && tabuleiro[1][j] == 1 
                                    && tabuleiro[2][j] == 1 && tabuleiro[3][j] == 1)
                                {
                                    return 1;
                                }
                                else
                                {
                                    if (tabuleiro[1][j] == 1 && tabuleiro[2][j] == 1 
                                        && tabuleiro[3][j] == 1 && tabuleiro[4][j] == 1)
                                    {
                                        return 1;
                                    }
                                    else
                                    {
                                        if (tabuleiro[2][j] == 1 && tabuleiro[3][j] == 1 
                                            && tabuleiro[4][j] == 1 && tabuleiro[5][j] == 1)
                                        {
                                            return 1;
                                        }
                                    }
                                }  
                                if (tabuleiro[0][j] == 2 && tabuleiro[1][j] == 2 
                                    && tabuleiro[2][j] == 2 && tabuleiro[3][j] == 2)
                                {
                                    return 2;
                                }
                                else
                                {
                                    if (tabuleiro[1][j] == 2 && tabuleiro[2][j] == 2 
                                        && tabuleiro[3][j] == 2 && tabuleiro[4][j] == 2)
                                    {
                                        return 2;
                                    }
                                    else
                                    {
                                        if (tabuleiro[2][j] == 2 && tabuleiro[3][j] == 2 
                                            && tabuleiro[4][j] == 2 && tabuleiro[5][j] == 2)
                                        {
                                            return 2;
                                        }
                                    }
                                }  
                            }
                            else
                            {
                                if (j == 5)
                                {
                                    if (tabuleiro[0][j] == 1 && tabuleiro[1][j] == 1 
                                        && tabuleiro[2][j] == 1 && tabuleiro[3][j] == 1)
                                    {
                                        return 1;
                                    }
                                    else
                                    {
                                        if (tabuleiro[1][j] == 1 && tabuleiro[2][j] == 1 
                                            && tabuleiro[3][j] == 1 && tabuleiro[4][j] == 1)
                                        {
                                            return 1;
                                        }
                                        else
                                        {
                                            if (tabuleiro[2][j] == 1 && tabuleiro[3][j] == 1 
                                                && tabuleiro[4][j] == 1 && tabuleiro[5][j] == 1)
                                            {
                                                return 1;
                                            }
                                        }
                                    }  
                                    if (tabuleiro[0][j] == 2 && tabuleiro[1][j] == 2 
                                        && tabuleiro[2][j] == 2 && tabuleiro[3][j] == 2)
                                    {
                                        return 2;
                                    }
                                    else
                                    {
                                        if (tabuleiro[1][j] == 2 && tabuleiro[2][j] == 2 
                                            && tabuleiro[3][j] == 2 && tabuleiro[4][j] == 2)
                                        {
                                            return 2;
                                        }
                                        else
                                        {
                                            if (tabuleiro[2][j] == 2 && tabuleiro[3][j] == 2 
                                                && tabuleiro[4][j] == 2 && tabuleiro[5][j] == 2)
                                            {
                                                return 2;
                                            }
                                        }
                                    }  
                                }
                                else
                                {
                                    if (j == 6)
                                    {
                                        if (tabuleiro[0][j] == 1 && tabuleiro[1][j] == 1 
                                            && tabuleiro[2][j] == 1 && tabuleiro[3][j] == 1)
                                        {
                                            return 1;
                                        }
                                        else
                                        {
                                            if (tabuleiro[1][j] == 1 && tabuleiro[2][j] == 1 
                                                && tabuleiro[3][j] == 1 && tabuleiro[4][j] == 1)
                                            {
                                                return 1;
                                            }
                                            else
                                            {
                                                if (tabuleiro[2][j] == 1 && tabuleiro[3][j] == 1 
                                                    && tabuleiro[4][j] == 1 && tabuleiro[5][j] == 1)
                                                {
                                                    return 1;
                                                }
                                            }
                                        }  
                                        if (tabuleiro[0][j] == 2 && tabuleiro[1][j] == 2 
                                            && tabuleiro[2][j] == 2 && tabuleiro[3][j] == 2)
                                        {
                                            return 2;
                                        }
                                        else
                                        {
                                            if (tabuleiro[1][j] == 2 && tabuleiro[2][j] == 2 
                                                && tabuleiro[3][j] == 2 && tabuleiro[4][j] == 2)
                                            {
                                                return 2;
                                            }
                                            else
                                            {
                                                if (tabuleiro[2][j] == 2 && tabuleiro[3][j] == 2 
                                                    && tabuleiro[4][j] == 2 && tabuleiro[5][j] == 2)
                                                {
                                                    return 2;
                                                }
                                            }
                                        }  
                                    }
                                    else
                                    {
                                        if (j == 1)
                                        {
                                            if (tabuleiro[0][j] == 1 && tabuleiro[1][j] == 1 
                                                && tabuleiro[2][j] == 1 && tabuleiro[3][j] == 1)
                                            {
                                                return 1;
                                            }
                                            else
                                            {
                                                if (tabuleiro[1][j] == 1 && tabuleiro[2][j] == 1 
                                                    && tabuleiro[3][j] == 1 && tabuleiro[4][j] == 1)
                                                {
                                                    return 1;
                                                }
                                                else
                                                {
                                                    if (tabuleiro[2][j] == 1 && tabuleiro[3][j] == 1 
                                                        && tabuleiro[4][j] == 1 && tabuleiro[5][j] == 1)
                                                    {
                                                        return 1;
                                                    }
                                                }
                                            }  
                                            if (tabuleiro[0][j] == 2 && tabuleiro[1][j] == 2 
                                                && tabuleiro[2][j] == 2 && tabuleiro[3][j] == 2)
                                            {
                                                return 2;
                                            }
                                            else
                                            {
                                                if (tabuleiro[1][j] == 2 && tabuleiro[2][j] == 2 
                                                    && tabuleiro[3][j] == 2 && tabuleiro[4][j] == 2)
                                                {
                                                    return 2;
                                                }
                                                else
                                                {
                                                    if (tabuleiro[2][j] == 2 && tabuleiro[3][j] == 2 
                                                        && tabuleiro[4][j] == 2 && tabuleiro[5][j] == 2)
                                                    {
                                                        return 2;
                                                    }
                                                }
                                            }  
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if ( i == 0)
            {
                if (tabuleiro[i][0] == 1 && tabuleiro[i][1] == 1 
                    && tabuleiro[i][2] == 1 && tabuleiro[i][3] == 1)
                {
                    return 1;
                }
                else
                {
                    if (tabuleiro[i][1] == 1 && tabuleiro[i][2] == 1 
                        && tabuleiro[i][3] == 1 && tabuleiro[i][4] == 1)
                    {
                        return 1;
                    }
                    else
                    {
                        if (tabuleiro[i][2] == 1 && tabuleiro[i][3] == 1 
                            && tabuleiro[i][4] == 1 && tabuleiro[i][5] == 1)
                        {
                            return 1;
                        }
                        else
                        {
                            if (tabuleiro[i][3] == 1 && tabuleiro[i][4] == 1 
                                && tabuleiro[i][5] == 1 && tabuleiro[i][6] == 1)
                            {
                                return 1;
                            }
                            else
                            {
                                if (tabuleiro[i][4] == 1 && tabuleiro[i][5] == 1 
                                    && tabuleiro[i][6] == 1 && tabuleiro[i][7] == 1)
                                {
                                    return 1;
                                }
                            }
                        }
                    }
                }
                if (tabuleiro[i][0] == 2 && tabuleiro[i][1] == 2 
                    && tabuleiro[i][2] == 2 && tabuleiro[i][3] == 2)
                {
                    return 2;
                }
                else
                {
                    if (tabuleiro[i][1] == 2 && tabuleiro[i][2] == 2 
                        && tabuleiro[i][3] == 2 && tabuleiro[i][4] == 2)
                    {
                        return 2;
                    }
                    else
                    {
                        if (tabuleiro[i][2] == 2 && tabuleiro[i][3] == 2 
                            && tabuleiro[i][4] == 2 && tabuleiro[i][5] == 2)
                        {
                            return 2;
                        }
                        else
                        {
                            if (tabuleiro[i][3] == 2 && tabuleiro[i][4] == 2 
                                && tabuleiro[i][5] == 2 && tabuleiro[i][6] == 2)
                            {
                                return 2;
                            }
                            else
                            {
                                if (tabuleiro[i][4] == 2 && tabuleiro[i][5] == 2 
                                    && tabuleiro[i][6] == 2 && tabuleiro[i][7] == 2)
                                {
                                    return 2;
                                }
                            }
                        }
                    }
                }    
            }
            else
            {
                if (i == 1)
                {
                    if (tabuleiro[i][0] == 1 && tabuleiro[i][1] == 1 
                        && tabuleiro[i][2] == 1 && tabuleiro[i][3] == 1)
                    {
                        return 1;
                    }
                    else
                    {
                        if (tabuleiro[i][1] == 1 && tabuleiro[i][2] == 1 
                            && tabuleiro[i][3] == 1 && tabuleiro[i][4] == 1)
                        {
                            return 1;
                        }
                        else
                        {
                            if (tabuleiro[i][2] == 1 && tabuleiro[i][3] == 1 
                                && tabuleiro[i][4] == 1 && tabuleiro[i][5] == 1)
                            {
                                return 1;
                            }
                            else
                            {
                                if (tabuleiro[i][3] == 1 && tabuleiro[i][4] == 1 
                                    && tabuleiro[i][5] == 1 && tabuleiro[i][6] == 1)
                                {
                                    return 1;
                                }
                                else
                                {
                                    if (tabuleiro[i][4] == 1 && tabuleiro[i][5] == 1 
                                        && tabuleiro[i][6] == 1 && tabuleiro[i][7] == 1)
                                    {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                    if (tabuleiro[i][0] == 2 && tabuleiro[i][1] == 2 
                        && tabuleiro[i][2] == 2 && tabuleiro[i][3] == 2)
                    {
                        return 2;
                    }
                    else
                    {
                        if (tabuleiro[i][1] == 2 && tabuleiro[i][2] == 2 
                            && tabuleiro[i][3] == 2 && tabuleiro[i][4] == 2)
                        {
                            return 2;
                        }
                        else
                        {
                            if (tabuleiro[i][2] == 2 && tabuleiro[i][3] == 2 
                                && tabuleiro[i][4] == 2 && tabuleiro[i][5] == 2)
                            {
                                return 2;
                            }
                            else
                            {
                                if (tabuleiro[i][3] == 2 && tabuleiro[i][4] == 2 
                                    && tabuleiro[i][5] == 2 && tabuleiro[i][6] == 2)
                                {
                                    return 2;
                                }
                                else
                                {
                                    if (tabuleiro[i][4] == 2 && tabuleiro[i][5] == 2 
                                        && tabuleiro[i][6] == 2 && tabuleiro[i][7] == 2)
                                    {
                                        return 2;
                                    }
                                }
                            }
                        }
                    }    
                }
                else
                {
                    if (i == 2)
                    {
                        if (tabuleiro[i][0] == 1 && tabuleiro[i][1] == 1 
                            && tabuleiro[i][2] == 1 && tabuleiro[i][3] == 1)
                        {
                            return 1;
                        }
                        else
                        {
                            if (tabuleiro[i][1] == 1 && tabuleiro[i][2] == 1 
                                && tabuleiro[i][3] == 1 && tabuleiro[i][4] == 1)
                            {
                                return 1;
                            }
                            else
                            {
                                if (tabuleiro[i][2] == 1 && tabuleiro[i][3] == 1 
                                    && tabuleiro[i][4] == 1 && tabuleiro[i][5] == 1)
                                {
                                    return 1;
                                }
                                else
                                {
                                    if (tabuleiro[i][3] == 1 && tabuleiro[i][4] == 1 
                                        && tabuleiro[i][5] == 1 && tabuleiro[i][6] == 1)
                                    {
                                        return 1;
                                    }
                                    else
                                    {
                                        if (tabuleiro[i][4] == 1 && tabuleiro[i][5] == 1 
                                            && tabuleiro[i][6] == 1 && tabuleiro[i][7] == 1)
                                        {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                        if (tabuleiro[i][0] == 2 && tabuleiro[i][1] == 2 
                            && tabuleiro[i][2] == 2 && tabuleiro[i][3] == 2)
                        {
                            return 2;
                        }
                        else
                        {
                            if (tabuleiro[i][1] == 2 && tabuleiro[i][2] == 2 
                                && tabuleiro[i][3] == 2 && tabuleiro[i][4] == 2)
                            {
                                return 2;
                            }
                            else
                            {
                                if (tabuleiro[i][2] == 2 && tabuleiro[i][3] == 2 
                                    && tabuleiro[i][4] == 2 && tabuleiro[i][5] == 2)
                                {
                                    return 2;
                                }
                                else
                                {
                                    if (tabuleiro[i][3] == 2 && tabuleiro[i][4] == 2 
                                        && tabuleiro[i][5] == 2 && tabuleiro[i][6] == 2)
                                    {
                                        return 2;
                                    }
                                    else
                                    {
                                        if (tabuleiro[i][4] == 2 && tabuleiro[i][5] == 2 
                                            && tabuleiro[i][6] == 2 && tabuleiro[i][7] == 2)
                                        {
                                            return 2;
                                        }
                                    }
                                }
                            }
                        }    
                    }
                    else
                    {
                        if ( i == 3)
                        {
                            if (tabuleiro[i][0] == 1 && tabuleiro[i][1] == 1 
                                && tabuleiro[i][2] == 1 && tabuleiro[i][3] == 1)
                            {
                                return 1;
                            }
                            else
                            {
                                if (tabuleiro[i][1] == 1 && tabuleiro[i][2] == 1 
                                    && tabuleiro[i][3] == 1 && tabuleiro[i][4] == 1)
                                {
                                    return 1;
                                }
                                else
                                {
                                    if (tabuleiro[i][2] == 1 && tabuleiro[i][3] == 1 
                                        && tabuleiro[i][4] == 1 && tabuleiro[i][5] == 1)
                                    {
                                        return 1;
                                    }
                                    else
                                    {
                                        if (tabuleiro[i][3] == 1 && tabuleiro[i][4] == 1 
                                            && tabuleiro[i][5] == 1 && tabuleiro[i][6] == 1)
                                        {
                                            return 1;
                                        }
                                        else
                                        {
                                            if (tabuleiro[i][4] == 1 && tabuleiro[i][5] == 1 
                                                && tabuleiro[i][6] == 1 && tabuleiro[i][7] == 1)
                                            {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            }
                            if (tabuleiro[i][0] == 2 && tabuleiro[i][1] == 2 
                                && tabuleiro[i][2] == 2 && tabuleiro[i][3] == 2)
                            {
                                return 2;
                            }
                            else
                            {
                                if (tabuleiro[i][1] == 2 && tabuleiro[i][2] == 2 
                                    && tabuleiro[i][3] == 2 && tabuleiro[i][4] == 2)
                                {
                                    return 2;
                                }
                                else
                                {
                                    if (tabuleiro[i][2] == 2 && tabuleiro[i][3] == 2 
                                        && tabuleiro[i][4] == 2 && tabuleiro[i][5] == 2)
                                    {
                                        return 2;
                                    }
                                    else
                                    {
                                        if (tabuleiro[i][3] == 2 && tabuleiro[i][4] == 2 
                                            && tabuleiro[i][5] == 2 && tabuleiro[i][6] == 2)
                                        {
                                            return 2;
                                        }
                                        else
                                        {
                                            if (tabuleiro[i][4] == 2 && tabuleiro[i][5] == 2 
                                                && tabuleiro[i][6] == 2 && tabuleiro[i][7] == 2)
                                            {
                                                return 2;
                                            }
                                        }
                                    }
                                }
                            }    
                        }
                        else
                        {
                            if ( i == 4)
                            {
                                if (tabuleiro[i][0] == 1 && tabuleiro[i][1] == 1 
                                    && tabuleiro[i][2] == 1 && tabuleiro[i][3] == 1)
                                {
                                    return 1;
                                }
                                else
                                {
                                    if (tabuleiro[i][1] == 1 && tabuleiro[i][2] == 1 
                                        && tabuleiro[i][3] == 1 && tabuleiro[i][4] == 1)
                                    {
                                        return 1;
                                    }
                                    else
                                    {
                                        if (tabuleiro[i][2] == 1 && tabuleiro[i][3] == 1 
                                            && tabuleiro[i][4] == 1 && tabuleiro[i][5] == 1)
                                        {
                                            return 1;
                                        }
                                        else
                                        {
                                            if (tabuleiro[i][3] == 1 && tabuleiro[i][4] == 1 
                                                && tabuleiro[i][5] == 1 && tabuleiro[i][6] == 1)
                                            {
                                                return 1;
                                            }
                                            else
                                            {
                                                if (tabuleiro[i][4] == 1 && tabuleiro[i][5] == 1 
                                                    && tabuleiro[i][6] == 1 && tabuleiro[i][7] == 1)
                                                {
                                                    return 1;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (tabuleiro[i][0] == 2 && tabuleiro[i][1] == 2 
                                    && tabuleiro[i][2] == 2 && tabuleiro[i][3] == 2)
                                {
                                    return 2;
                                }
                                else
                                {
                                    if (tabuleiro[i][1] == 2 && tabuleiro[i][2] == 2 
                                        && tabuleiro[i][3] == 2 && tabuleiro[i][4] == 2)
                                    {
                                        return 2;
                                    }
                                    else
                                    {
                                        if (tabuleiro[i][2] == 2 && tabuleiro[i][3] == 2 
                                            && tabuleiro[i][4] == 2 && tabuleiro[i][5] == 2)
                                        {
                                            return 2;
                                        }
                                        else
                                        {
                                            if (tabuleiro[i][3] == 2 && tabuleiro[i][4] == 2 
                                                && tabuleiro[i][5] == 2 && tabuleiro[i][6] == 2)
                                            {
                                                return 2;
                                            }
                                            else
                                            {
                                                if (tabuleiro[i][4] == 2 && tabuleiro[i][5] == 2 
                                                    && tabuleiro[i][6] == 2 && tabuleiro[i][7] == 2)
                                                {
                                                    return 2;
                                                }
                                            }
                                        }
                                    }
                                }    
                            }
                            else
                            {
                                if ( i == 0)
                                {
                                    if (tabuleiro[i][0] == 1 && tabuleiro[i][1] == 1 
                                        && tabuleiro[i][2] == 1 && tabuleiro[i][3] == 1)
                                    {
                                        return 1;
                                    }
                                    else
                                    {
                                        if (tabuleiro[i][1] == 1 && tabuleiro[i][2] == 1 
                                            && tabuleiro[i][3] == 1 && tabuleiro[i][4] == 1)
                                        {
                                            return 1;
                                        }
                                        else
                                        {
                                            if (tabuleiro[i][2] == 1 && tabuleiro[i][3] == 1 
                                                && tabuleiro[i][4] == 1 && tabuleiro[i][5] == 1)
                                            {
                                                return 1;
                                            }
                                            else
                                            {
                                                if (tabuleiro[i][3] == 1 && tabuleiro[i][4] == 1 
                                                    && tabuleiro[i][5] == 1 && tabuleiro[i][6] == 1)
                                                {
                                                    return 1;
                                                }
                                                else
                                                {
                                                    if (tabuleiro[i][4] == 1 && tabuleiro[i][5] == 1 
                                                        && tabuleiro[i][6] == 1 && tabuleiro[i][7] == 1)
                                                    {
                                                        return 1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (tabuleiro[i][0] == 2 && tabuleiro[i][1] == 2 
                                        && tabuleiro[i][2] == 2 && tabuleiro[i][3] == 2)
                                    {
                                        return 2;
                                    }
                                    else
                                    {
                                        if (tabuleiro[i][1] == 2 && tabuleiro[i][2] == 2 
                                            && tabuleiro[i][3] == 2 && tabuleiro[i][4] == 2)
                                        {
                                            return 2;
                                        }
                                        else
                                        {
                                            if (tabuleiro[i][2] == 2 && tabuleiro[i][3] == 2 
                                                && tabuleiro[i][4] == 2 && tabuleiro[i][5] == 2)
                                            {
                                                return 2;
                                            }
                                            else
                                            {
                                                if (tabuleiro[i][3] == 2 && tabuleiro[i][4] == 2 
                                                    && tabuleiro[i][5] == 2 && tabuleiro[i][6] == 2)
                                                {
                                                    return 2;
                                                }
                                                else
                                                {
                                                    if (tabuleiro[i][4] == 2 && tabuleiro[i][5] == 2 
                                                        && tabuleiro[i][6] == 2 && tabuleiro[i][7] == 2)
                                                    {
                                                        return 2;
                                                    }
                                                }
                                            }
                                        }
                                    }    
                                }
                            }
                        }
                    }
                }
            }      
        }   
    }
}