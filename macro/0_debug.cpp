//
// Created by coastcao(操海兵) on 2019-09-05.
//

#include <stdio.h>
#include <stdlib.h>
#define DEBUG
int main(void)
{
    int i = 0;
    char c;
    while(1)
    {
        i++;
        c = getchar();
        if('\n' != c)
        {
            getchar();
        }
        if('q' == c || 'Q' == c)
        {
#ifdef DEBUG//判断DEBUG是否被定义了
            printf("We get:%c,about to exit.\n",c);
#endif
            break;
        }
        else
        {
            printf("i = %d",i);
#ifdef DEBUG
            printf(",we get:%c",c);
#endif
            printf("\n");
        }
    }
    printf("Hello World!\n");
    return 0;
}

/*#endif用于终止#if预处理指令。*/