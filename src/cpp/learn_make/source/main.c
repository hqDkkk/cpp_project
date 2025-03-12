#include<stdio.h>
#include"../header/add.h"
#include"../header/sub.h"
#include"../header/div.h"
int main()
{
    int a,b;
    a=10;
    b=5;
    printf("%d+%d=%d\n",a,b,add(a,b));
    printf("%d-%d=%d\n",a,b,sub(a,b));
    printf("%d*%d=%d\n",a,b,div(a,b));

    return 0;
}
