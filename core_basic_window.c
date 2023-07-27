#include "raylib.h"

int main(void)
{
    const int telaLargura = 900;
    const int telaLateral = 700;
    const int telaAltura = 700;

    int chaveTeste = 00;

    int tabuleiro[8][8];

    for (int i = 0; i < 8; i++){

        for (int j = 0; j < 8; j++){

         tabuleiro[i][j]=0;

        }
    }

    InitWindow(telaLargura, telaAltura, "Cyberpunk 1945");

    Texture2D pecaDama = LoadTexture("resources/peca11.png");
    Texture2D pecaDama2 = LoadTexture("resources/peca22.png");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        BeginDrawing();

            ClearBackground(RAYWHITE);

           int celulaTamanho = telaLateral / 8;

            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    int posX = i * celulaTamanho;
                    int posY = j * celulaTamanho;

                    Color celulaCor = (i + j) % 2 == 0 ? WHITE : LIGHTGRAY;
                    // As peças que a soma das coordenadas dá impar são as que as peças podem andar

                    DrawRectangle(posX, posY, celulaTamanho, celulaTamanho, celulaCor);
                    DrawRectangleLines(posX, posY, celulaTamanho, celulaTamanho, BLACK);

                    if ((j < 3) && ((i + j) % 2 != 0))
                    {
                        int centroX = posX + celulaTamanho / 2;
                        int centroY = posY + celulaTamanho / 2;
                        int raio = celulaTamanho / 3;

                        tabuleiro[j][i]=1;

                        DrawTexture(pecaDama, centroX - raio, centroY - raio, WHITE);
                    }
                    else if ((j > 4) && ((i + j) % 2 != 0))
                    {
                        int centroX = posX + celulaTamanho / 2;
                        int centroY = posY + celulaTamanho / 2;
                        int raio = celulaTamanho / 3;

                        tabuleiro[j][i]=2;

                        DrawTexture(pecaDama2, centroX - raio, centroY - raio, WHITE);
                    }
                }
            }

            DrawRectangle(690, 0, 200, 700, BLACK);
            DrawRectangle(695, 5, 200-10, 690, GRAY);

            if(!chaveTeste){

                 for (int i = 0; i < 8; i++){

                    printf("|");

                    for (int j = 0; j < 8; j++){

                     printf(" %d |",tabuleiro[i][j]);

                    }

                    printf("\n");
                }

                chaveTeste ++;
            }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
