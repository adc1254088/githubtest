#include <stdio.h>
#include <stdlib.h>
typedef struct
    {
        int *t1;
        int t2;
    } TEST;
int main()
{
    TEST *dp = calloc(1,sizeof(TEST));
    dp->t1 = calloc(1,sizeof(int));
    *dp->t1 = 1;
    dp->t2 = 2;
    printf("%p\n",(void*)dp->t1);
    printf("%d\n",*dp->t1);
    printf("%d\n",&dp->t1);
    printf("%d\n",dp->t2);
    printf("%d\n",*&dp->t2);
    printf("%d\n",&dp->t2);
    printf("%d\n",dp);
    printf("%d\n",*dp);
    printf("%d\n",&dp);
    free(dp->t1);
    free(dp);
    return 0;
}