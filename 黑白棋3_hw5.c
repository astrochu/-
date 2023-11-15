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

// 印出棋盤
void printChessboard(int chess[bS][bS]) {
    for (int i = 0; i < bS; i++) {
        for (int j = 0; j < bS; j++) {
            if (chess[i][j] == 0) {
                printf("0 ");
            } else if (chess[i][j] == 1) {
                printf("1 ");
            } else if (chess[i][j] == 2) {
                printf("2 ");
            }
        }
        printf("\n");
    }
}

//8個方向的移動
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

//當前位置的可下位置
int pM(int i, int j) {
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
                if (chess[x][y] == 0) { //遇到空白，跳出迴圈，接續檢查下個方向
                    break;
                } else if (chess[x][y] == pC) { //遇到同色，跳出迴圈，接續檢查下個方向
                    break;
                } else { //遇到異色，繼續檢查下一格，尋找空位
                    x += dx[p];
                    y += dy[p];
                    step ++;
                    if (x >= 0 && x <= 7 && y >= 0 && y <= 7 && chess[x][y] == 0) {
                        printf("(%d,%d) ", i + step * dx[p], j + step * dy[p]);
                    }
                }
            }
        }
        return cM;
    }
}

// 玩家下棋(黑色)
void Move() {
    int pC = 1;
    int i, j;

    do { // 輸入位置，檢查是否有效
        printf("請輸入下棋位置 (格式：行,列)：");
        scanf("%d,%d", &i, &j);

        if (i < 0 || i >= bS || j < 0 || j >= bS || chess[i][j] != 0) {
            printf("無效位置\n");
        } else {
            chess[i][j] = pC;
            break;
        }

    } while (1);

    for (int p = 0; p < 8; p++) {
        int x = i + dx[p];
        int y = j + dy[p];

        while (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
            if (chess[x][y] == 0) { //遇到空白，跳出迴圈，接續檢查下個方向
                break;
            } else if (chess[x][y] == pC) { //遇到同色，跳出迴圈，接續檢查下個方向
                break;
            } else {
                chess[x][y] = pC;  // 遇到對手的顏色，將其變成自己的顏色

                x += dx[p]; // 繼續檢查下一格，找到同色停止
                y += dy[p];

                if (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
                    if (chess[x][y] == pC) {
                        break;
                    }
                }
            }
        }
    }
    printf("\n");
}


// 印出棋盤中可以下黑子的位置
void printBlackMoves(int chess[bS][bS]) {
    printf("黑棋可下位置: ");

    for (int i = 0; i < bS; i++) {
        for (int j = 0; j < bS; j++) {
            if (chess[i][j] == 1) {
                if (pM(i, j) == 0) {
                }
            }
        }
    }
    printf("\n");
}

// 印出棋盤中可以下白子的位置
void printWhiteMoves(int chess[bS][bS]) {
    printf("白棋可下位置: ");

    for (int i = 0; i < bS; i++) {
        for (int j = 0; j < bS; j++) {
            if (chess[i][j] == 2) {
                if (pM(i, j) == 0) {
                }
            }
        }
    }
    printf("\n");
}


// 主程式
int main() {
    int i, j;
    for (int round = 1; ; round ++) {
        printBlackMoves(chess);
        printChessboard(chess);
        Move();
        printChessboard(chess);
    }
}
