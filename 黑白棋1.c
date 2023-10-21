#include <stdio.h>
#define bS 8 //board size

//棋盤
int chess[bS][bS] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 2, 1, 0, 0, 0},
    {0, 0, 0, 1, 2, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

//8個方向的移動
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

int main() {
    int i, j;
    scanf("%d,%d", &i, &j);// 輸入座標

    int pC = chess[i][j];// 確定座標(i, j)的棋子顏色 pC = positioncolor

    if (pC == 0) {
        printf("(%d,%d) 空白\n", i, j);//若為空白，不用檢查
    } else {
        printf("(%d,%d)=%d, %s棋\n", i, j, pC,(pC == 1)? "黑" : "白");
    }

    int x, y, p;

    if (pC == 1) { //黑色
        for (p = 0; p < 8; p++) {
            int x = i + dx[p];
            int y = j + dy[p];

            while (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
                if (chess[x][y] == 0) {
                    break; //遇到空白，跳出迴圈，接續檢查下個方向
                } else if (chess[x][y] == 1) {
                    break; //遇到黑色，跳出迴圈，接續檢查下個方向
                } else if (chess[x][y] == 2) {
                    x += dx[p];
                    y += dy[p]; //遇到白色，繼續檢查下一格
                    if (x >= 0 && x <= 7 && y >= 0 && y <= 7 && chess[x][y] == 0) {
                        printf("(%d,%d)\n", x, y);//遇到空白，輸出該位置
                    }
                }
            }
        }
    }

    if (pC == 2) { //白色
        for (p = 0; p < 8; p++) {
            int x = i + dx[p];
            int y = j + dy[p];

            while (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
                if (chess[x][y] == 0) {
                    break; //遇到空白，跳出迴圈，接續檢查下個方向
                } else if (chess[x][y] == 2) {
                    break; //遇到白色，跳出迴圈，接續檢查下個方向
                } else if (chess[x][y] == 1) {
                    x += dx[p];
                    y += dy[p]; //遇到黑色，繼續檢查下一格
                    if (x >= 0 && x <= 7 && y >= 0 && y <= 7 && chess[x][y] == 0) {
                        printf("(%d,%d)\n", x, y);//遇到空白，輸出該位置
                    }
                }
            }
        }
    }

    return 0;
}
