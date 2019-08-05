#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char str[128]; //存字符串
    scanf("%s", str);
    int i;
    int arr[10] = {0};
    int len = strlen(str);
    for(i = 0;i <= len;i++){
        //printf("str = %d ", str[i]);
        //printf("str[i] = %d", (int)str[i]);
        switch((int)str[i]){
            case 48: arr[0]++;break;
            case 49: arr[1]++;break;
            case 50: arr[2]++;break;
            case 51: arr[3]++;break;
            case 52: arr[4]++;break;
            case 53: arr[5]++;break;
            case 54: arr[6]++;break;
            case 55: arr[7]++;break;
            case 56: arr[8]++;break;
            case 57: arr[9]++;break;
            default: break;
        }
    }
    int j;
    for(j = 0;j <= 9;j++){
    printf("%d ",arr[j]);
    }   
    return 0;
}
