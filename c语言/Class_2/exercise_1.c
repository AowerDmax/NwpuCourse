//斗地主
//为了方便表示每一张牌，我们对所有的牌进行编码，一共54张牌，编码1~54
// 0 代表 黑桃_A 2 代表 黑桃_2 .... 12 代表 黑桃_k
// 13代表 红桃_A .................. 25 代表 红桃_k
// 26代表 草花_A .................. 38 代表 草花_k
// 39代表 方块_A .................. 51 代表 方块_k
// 52 代表 小王 53 代表大王
// suit = {'黑桃', '红桃', '草花', '方块'} Joker = {'小王', '大王'}
// x 是 牌的编码
// if x / 13 < 4 then suit[x/13] + x % 13
// if x / 13 == 4 then Joker[x % 13]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct card
{
    int id;
    char suits[20];
};

struct card cards[54];
char *suit[] = {"黑桃", "红桃", "草花", "方块"};
char *joker[] = {"小王", "大王"};
char *face[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "k"};
int flag[54] = {0};

void licensing()
{
    for (int i = 0; i < 54; i++)
    {
        flag[i] = 0;
    }

    for (int i = 0; i < 54; i++)
    {
        int x = rand() % 54;
        while (flag[x] != 0)
        {
            x = rand() % 54;
        }
        flag[x] = 1;
        cards[i].id = x;
        if (x / 13 < 4)
        {
            strcpy(cards[i].suits, suit[x / 13]);
            strcpy(cards[i].suits, "_");
            strcpy(cards[i].suits, face[x % 13]);
        }
        else
        {
            strcpy(cards[i].suits, joker[x % 13]);
        }
    }

    for (int i = 0; i <= 53; i++)
    {
        if (i % 17 == 0 && i != 0)
        {
            printf("\n");
        }
        if (i % 17 == 0 && i / 17 != 3)
        {
            printf("玩家%d: ", i / 17 + 1);
        }
        else if (i / 17 == 3 && i % 17 == 0)
        {
            printf("底牌: ");
        }

        printf("%s ", cards[i].suits);
    }
    puts("");
}

int main()
{
    int times;
    scanf("%d", &times);
    for (int i = 0; i < times; i++)
    {
        printf("第%d次发牌:\n", i + 1);
        licensing();
    }

    return 0;
}