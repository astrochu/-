#include <stdio.h>
#define bS 8 //boardSize

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

//當前位置的可下位置
int pM(int i, int j) { //positionMove
    int pC = chess[i][j];// positionColor確定座標(i, j)的棋子顏色
    int cM = 0; //canMove

    if (pC == 0) {
        return cM;
    } else {
        cM = 1;
        for (int p = 0; p < 8; p++) {
            int x = i + dx[p];
            int y = j + dy[p];
            int step = 1;

            while (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
                if (chess[x][y] == 0) {
                    break; //遇到空白，跳出迴圈，接續檢查下個方向
                } else if (chess[x][y] == pC) {
                    break; //遇到同色，跳出迴圈，接續檢查下個方向
                } else {
                    x += dx[p];
                    y += dy[p]; //遇到異色，繼續檢查下一格，尋找空位
                    step ++;
                    if (x >= 0 && x <= 7 && y >= 0 && y <= 7 && chess[x][y] == 0) {
                        printf("(%d,%d) ", i + step * dx[p], j + step * dy[p]);
                    }
                }
            }
        }
        //printf("\n");
        return cM;
    }
}

// 印出棋盤中可以下黑子的位置
void printBlackMoves(int chess[bS][bS]) {
    printf("黑棋可下位置:\n");
    for (int i = 0; i < bS; i++) {
        for (int j = 0; j < bS; j++) {
            if (chess[i][j] == 1) {
                if (pM(i, j) == 0) {
                    printf("(%d,%d) ", i, j);
                }
            }
        }
    }
}

// 印出棋盤中可以下白子的位置
void printWhiteMoves(int chess[bS][bS]) {
    printf("白棋可下位置:\n");
    for (int i = 0; i < bS; i++) {
        for (int j = 0; j < bS; j++) {
            if (chess[i][j] == 2) {
                if (pM(i, j) == 0) {
                    printf("(%d,%d) ", i, j);
                }
            }
        }
    }
}

// 主程式
int main() {
    int i, j;
    scanf("%d,%d", &i, &j); //輸入座標
    int result = pM(i, j);

    if (result == 0) {
        printf("該位置沒有棋子\n");
    }
    printBlackMoves(chess);
    printWhiteMoves(chess);


    return 0;
}







