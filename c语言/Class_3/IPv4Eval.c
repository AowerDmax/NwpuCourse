#include "Ipv4Eval.h"
#include <string.h>
#include <stdio.h>
//判断是否是ipv4地址
// xxx.xxx.xxx.xxx
// 要求：
// 1. 每个地址包含四个十进制数, 和 3个 (.)
// 2. 其范围是0 ~ 255
// 3. 用(.)分割
// 4. ipv4内的地址不会以0开头
// 5. 长度范围判断条件 0.0.0.0 ~ 255.255.255.255 长度范围 7 ~ 15
// 6. ipv4地址内只有 (.) 和数字两种符号
int ipv4Eval(char q[])
{
    int len = strlen(q);
    // printf("len = %d\n", len);
    // printf("q = %s\n", q);
    // 5. 长度范围判断条件
    if (len < 7 || len > 15)
    {
        printf("长度范围判断条件 0.0.0.0 ~ 255.255.255.255 长度范围 7 ~ 15\n");
        printf("长度为：%d, 长度不符合ipv4格式要求\n", len);
        return 0;
    }

    int total = 0;
    int num = 0;
    int flag = 0;
    for (int i = 0; i < len; i++)
    {
        int idx = q[i] - '0';
        // printf("idx = %d\n", idx);
        if (idx >= 0 && idx <= 9)
        {
            // 4. ipv4内的地址不会以0开头 0x
            //不是第0位，此时total 为 0 ，前一位为0
            if (i && !total && q[i - 1] == '0')
            {
                printf("ipv4内的地址不会以0开头\n");
                printf("该ip地址的第%d个位置出现0x格式,不符合ipv4地址要求\n", num + 1);
                return 0;
            }

            total = total * 10 + idx;
        } // 3. 用(.)分割
        else if (q[i] == '.')
        {
            // printf("total = %d\n", total);
            //记录 . 的数量
            num++;
            //记录最后一个 . 的下标
            flag = i;
            // 2. 其范围是0 ~ 255
            if (total < 0 || total > 255)
            {
                printf("ipv4内的地址其数值范围是0 ~ 255\n");
                printf("该ip地址的第%d个位置出现不在范围的数字%d,不符合ipv4地址要求\n", num, total);
                return 0;
            }

            //开始计算下一个数
            total = 0;
        }
        else
        {
            // 6. ipv4地址内只有 (.) 和数字两种符号
            //出现其他符号
            printf("ipv4地址内只有 (.) 和数字两种符号\n");
            printf("该ip地址的第%d个位置出现其他符号,不符合ipv4地址要求\n", num + 1);
            return 0;
        }
    }
    // 1. 每个地址包含四个十进制数, 和 3个 (.)
    if (num == 3 && flag < len - 1 && q[flag + 1] >= '0' && q[flag + 1] <= '9' && total >= 0 && total <= 255)
        return 1;
    if (num != 3)
    {
        printf("ipv4地址只包含四个十进制数和三个(.)\n");
        printf("该ip地址出现%d个(.),不符合ipv4地址要求\n", num);
    }
    else if (num == 3 && flag < len - 1 && q[flag + 1] >= '0' && q[flag + 1] <= '9' && total < 0 || total > 255)
    {
        printf("ipv4内的地址其数值范围是0 ~ 255\n");
        printf("该ip地址的第%d个位置出现不在范围的数字%d,不符合ipv4地址要求\n", num + 1, total);
    }
    else if (flag == len - 1)
    {
        printf("ipv4地址为xxx.xxx.xxx.xxx格式\n");
        printf("出现..情况，不符合ipv4要求\n");
    }

    return 0;
}