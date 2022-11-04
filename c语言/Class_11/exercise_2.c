#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
/**
 * 贪心
 *
 */

int *arr;
char *buff;
int n;

int main()
{
    buff = (char *)malloc(sizeof(char) * 255);
    FILE *fp = fopen("t2.txt", "r");
    FILE *out = fopen("out_t2.txt", "w");
    while (!feof(fp))
    {
        fscanf(fp, "%d", &n);
        if (arr)
            free(arr);
        arr = (int *)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
            fscanf(fp, "%d", &arr[i]);
        int res = 0;
        int l = 0;
        int r = n;
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[j]);
            fprintf(out, "%d ", arr[j]);
        }
        printf("\n");
        fprintf(out, "\n");
        while (1)
        {
            int times = 0;
            int min = 0x3f;
            for (int i = 0; i < n; i++)
            {
                if (!times && arr[i])
                {
                    l = i;
                    times++;
                }

                if (times && !arr[i])
                {
                    r = i;
                    break;
                }
                if (times)
                    min = min(min, arr[i]);
            }
            if (!times)
                break;
            for (int i = l; i < r; i++)
                arr[i] -= min;
            res++;
            for (int j = 0; j < n; j++)
            {
                printf("%d ", arr[j]);
                fprintf(out, "%d ", arr[j]);
            }
            printf("\n");
            fprintf(out, "\n");
            r = n;
            l = 0;
        }
        printf("res: %d\n", res);
        fprintf(out, "res: %d\n", res);
    }

    return 0;
}