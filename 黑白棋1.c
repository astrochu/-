#include <stdio.h>
#define bS 8 //board size

//�ѽL
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

//8�Ӥ�V������
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

int main() {
    int i, j;
    scanf("%d,%d", &i, &j);// ��J�y��

    int pC = chess[i][j];// �T�w�y��(i, j)���Ѥl�C�� pC = positioncolor

    if (pC == 0) {
        printf("(%d,%d) �ť�\n", i, j);//�Y���ťաA�����ˬd
    } else {
        printf("(%d,%d)=%d, %s��\n", i, j, pC,(pC == 1)? "��" : "��");
    }

    int x, y, p;

    if (pC == 1) { //�¦�
        for (p = 0; p < 8; p++) {
            int x = i + dx[p];
            int y = j + dy[p];

            while (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
                if (chess[x][y] == 0) {
                    break; //�J��ťաA���X�j��A�����ˬd�U�Ӥ�V
                } else if (chess[x][y] == 1) {
                    break; //�J��¦�A���X�j��A�����ˬd�U�Ӥ�V
                } else if (chess[x][y] == 2) {
                    x += dx[p];
                    y += dy[p]; //�J��զ�A�~���ˬd�U�@��
                    if (x >= 0 && x <= 7 && y >= 0 && y <= 7 && chess[x][y] == 0) {
                        printf("(%d,%d)\n", x, y);//�J��ťաA��X�Ӧ�m
                    }
                }
            }
        }
    }

    if (pC == 2) { //�զ�
        for (p = 0; p < 8; p++) {
            int x = i + dx[p];
            int y = j + dy[p];

            while (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
                if (chess[x][y] == 0) {
                    break; //�J��ťաA���X�j��A�����ˬd�U�Ӥ�V
                } else if (chess[x][y] == 2) {
                    break; //�J��զ�A���X�j��A�����ˬd�U�Ӥ�V
                } else if (chess[x][y] == 1) {
                    x += dx[p];
                    y += dy[p]; //�J��¦�A�~���ˬd�U�@��
                    if (x >= 0 && x <= 7 && y >= 0 && y <= 7 && chess[x][y] == 0) {
                        printf("(%d,%d)\n", x, y);//�J��ťաA��X�Ӧ�m
                    }
                }
            }
        }
    }

    return 0;
}
