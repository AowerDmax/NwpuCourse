#include "Ipv6Eval.h"
#include <string.h>
#include <stdio.h>

//判断是否是ipv6地址
// xxxx:xxxx:xxxx:xxxx:xxxx:xxxx:xxxx:xxxx
// 要求：
// 1. 每个地址包含八个十六进制数, 和 7个 (:)
// 2. 其范围是0000:0000:0000:0000:0000:0000:0000:0000 到 ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff  ffff->2^17 - 1 = 131072
// 3. 用(:)分割
// 4. ipv6内的地址可以以0开头
// 5. 长度范围判断条件 0:0:0:0:0:0:0:0 ~ ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff 长度范围 15 ~ 39
// 6. ipv6地址内只有 (:) 和数字 字母{A, a, B, b, C, c, D, d, E, e, F, f}三种符号
// 7. 不能出现::以及 0xxxx的情况

int ipv6Eval(char q[])
{
    int len = strlen(q);
    // printf("len = %d\n", len);
    // printf("q = %s\n", q);
    // 5. 长度范围判断条件
    if (len < 15 || len > 39)
    {
        printf("0:0:0:0:0:0:0:0 ~ ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff 长度范围 15 ~ 39\n");
        printf("长度为：%d, 长度不符合ipv6格式要求\n", len);
        return 0;
    }

    //记录数字的长度
    int total = 0;
    //记录 : 的数量
    int num = 0;
    //记录符号的数量
    int flag = 0;
    for (int i = 0; i < len; i++)
    {
        int idx = q[i] - '0';
        int idxa = q[i] - 'a';
        int idxb = q[i] - 'A';
        // printf("idx = %d\n", idx);
        // 6. ipv6地址内只有 (:) 和数字 字母{A, a, B, b, C, c, D, d, E, e, F, f}三种符号
        if (idx >= 0 && idx <= 9 || idxa >= 0 && idxa <= 5 || idxb >= 0 && idxb <= 5)
        {
            //记录数字的长度
            total++;
        } // 3. 用(:)分割
        else if (q[i] == ':')
        {
            // printf("total = %d\n", total);
            //记录:的数量
            num++;
            //记录最后一个:的下标
            flag = i;
            // 7. 不能出现::以及 0xxxx的情况
            if (total == 0 || total > 4)
            {
                if (total == 0)
                {
                    printf("ipv6内的地址不会出现::紧密相连的情况\n");
                    printf("该ip地址的第%d个位置出现::紧密相连的情况,不符合ipv6地址要求\n", num);
                }
                if (total > 4)
                {
                    printf("ipv6内的地址不会出现xxxxx的情况\n");
                    printf("该ip地址的第%d个位置出现xxxxx的情况,不符合ipv6地址要求\n", num);
                }
                return 0;
            }

            //开始计算下一个数
            total = 0;
        }
        else
        {
            // 6. ipv6地址内只有 (:) 和数字 字母{A, a, B, b, C, c, D, d, E, e, F, f}三种符号
            //出现其他符号
            printf("ipv6地址内只有 (:) 和数字 字母{A, a, B, b, C, c, D, d, E, e, F, f}三种符号\n");
            printf("该ip地址的第%d个位置出现出现其他符号%c,不符合ipv6地址要求\n", num + 1, q[i]);
            return 0;
        }
    }
    // 1. 每个地址包含八个十六进制数, 和 7个 (:)
    if (num == 7 && total != 0)
        return 1;
    if (num != 7)
    {
        printf("ipv6地址内有7个 (:)符号\n");
        printf("该ip地址只有%d个(:)符号,不符合ipv6地址要求\n", num);
    }
    if (total == 0)
    {
        printf("ipv6地址内有8个16进制的数字\n");
        printf("该ip地址只有%d个16进制的数字,不符合ipv6地址要求\n", num);
    }
    return 0;
}