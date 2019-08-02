#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_LEN 128

int main() 
{
    char c1;
    char c2[MAX_LEN];
    char c3[MAX_LEN];
    
    scanf("%c",&c1);
    printf("%c\n",c1);

    scanf("%s", c2);
    printf("%s\n",c2);
    scanf("\n");        //添加此句后才能使后一句输入完整且包含空格
    scanf("%[^\n]",c3);
    printf("%s",c3);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
