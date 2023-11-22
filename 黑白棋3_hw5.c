#include <stdio.h>
#define bS 8 //boardSize

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


//印出當前棋盤
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


//八個方向
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

void updateBoard(int i, int j, int pC) {
    for (int p = 0; p < 8; p++) {
        int x = i + dx[p];
        int y = j + dy[p];

        while (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
            if (chess[x][y] == 0) {
                break;
            } else if (chess[x][y] == pC) { // 找到相同顏色的棋子，進行更新
                while (x != i || y != j) {
                    x -= dx[p];
                    y -= dy[p];
                    chess[x][y] = pC;
                }
                break;
            } else {
                x += dx[p];
                y += dy[p];
            }
        }
    }
}

//玩家移動(黑棋)
void Move() {
    int pC = 1;
    int i, j;

    do {
        printf("請輸入下棋位置 (格式：行,列)：");
        scanf("%d,%d", &i, &j);

        int key = 0;
        int colorChanges = 0;

        for (int p = 0; p < 8; p++) {
            int x = i + dx[p];
            int y = j + dy[p];
            int changesInThisDirection = 0;

            while (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
                if (chess[x][y] == 0) {
                    break;
                } else if (chess[x][y] == pC) {
                    if (changesInThisDirection > 0) {
                        colorChanges += changesInThisDirection;
                        key = 1;
                    }
                    break;
                } else {
                    changesInThisDirection++;
                    x += dx[p];
                    y += dy[p];
                }
            }
        }

        if (key) {
            updateBoard(i, j, pC);
            printf("黑棋下(%d, %d),翻了 %d 顆白棋\n", i, j, colorChanges);
            break;
        } else {
            printf("無效位置\n");
        }
    } while (1);
}

int evaluateMove(int i, int j, int pC) {
    int count = 0;

    for (int p = 0; p < 8; p++) {
        int x = i + dx[p];
        int y = j + dy[p];
        int tempCount = 0;

        while (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
            if (chess[x][y] == 0) {
                break;
            } else if (chess[x][y] == pC) {
                count += tempCount;
                break;
            } else {
                x += dx[p];
                y += dy[p];
                tempCount++;
            }
        }
    }

    return count;
}

void aiMove() {
    int pC = 2;
    int bestMoveI = -1;
    int bestMoveJ = -1;
    int maxColorChanges = 0;

    for (int i = 0; i < bS; i++) {
        for (int j = 0; j < bS; j++) {
            if (chess[i][j] == 0) {
                int colorChanges = evaluateMove(i, j, pC);
                if (colorChanges > maxColorChanges) {
                    maxColorChanges = colorChanges;
                    bestMoveI = i;
                    bestMoveJ = j;
                }
            }
        }
    }

    if (bestMoveI != -1 && bestMoveJ != -1) {
        updateBoard(bestMoveI, bestMoveJ, pC);
        printf("白棋下(%d, %d),翻了 %d 顆黑棋\n",bestMoveI, bestMoveJ, maxColorChanges);
    } else {
        printf("沒有位置可以下棋了");
    }
}

void printBlackMoves(int chess[bS][bS]) {
    printf("黑棋可下位置: ");

    for (int i = 0; i < bS; i++) {
        for (int j = 0; j < bS; j++) {
            if (chess[i][j] == 1) {
                pM(i, j);
            }
        }
    }
    printf("\n");
}

void printWhiteMoves(int chess[bS][bS]) {
    printf("白棋可下位置: ");
    int count = 0;

    for (int i = 0; i < bS; i++) {
        for (int j = 0; j < bS; j++) {
            if (chess[i][j] == 2) {
                pM(i, j);
            }
        }
    }
    printf("\n");
}

int main() {
    int i, j;

    while (1) {
        printChessboard(chess);
        printBlackMoves(chess);
        Move();
        printChessboard(chess);
        printWhiteMoves(chess);
        aiMove();
    }

    return 0;
}

