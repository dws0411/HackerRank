#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    //Write your logic to print the tokens of the sentence here.
    int i;
    for(i =0; i<strlen(s);i++){
        if(s[i] != 0x20){           //0x20是空格，即若字符串当前位置不为空格则打印，若为空格则换行;或表示为*(s+i)
            printf("%c",s[i]);
        }else{
            printf("\n");
        }
    };
    
    return 0;
}

