#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    int ret;
    for(int i = 0;i<strlen(a);i++){
        for(int j = i;j<strlen(b);j++){
            ret = strcmp(&a[i],&b[j]);
            if(ret > 0){
                return 1;       //若ret>0,说明a在b后面,需条换顺序
            }else if (ret < 0) {
                return -1;      //反之，说明a在b前面，不需调换顺序
            }else {
                break;          //相等
            }
        }
    }
    if(strlen(a) == strlen(b)){
        return 0;
    }if(strlen(a) < strlen(b)){
        return -1;   //不需调换顺序
    }else {
        return 1;  //需调换顺序
    }   
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    int ret;
    for(int i = 0;i<strlen(a);i++){
        for(int j = i;j<strlen(b);j++){
            ret = strcmp(&a[i],&b[j]);
            if(ret > 0){
                return -1;       //若ret>0,说明a在b后面，不需调换顺序
            }else if (ret < 0) {
                return 1;      //反之，说明a在b前面，需调换顺序
            }else {
                break;          //相等
            }
        }
    }
    if(strlen(a) == strlen(b)){
        return 0;
    }if(strlen(a) < strlen(b)){
        return 1;          
    }else {
        return -1;
    }
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int count1,count2;
    char* arr1;   //用来存储字符串a中出现的非重复字符
    char* arr2;   //存储b
    int sign = 0;           //标志位，用来表示a字符串中当前字符是否在arr1中出现；b字符串同理
    int i,j;
    arr1 = (char* )malloc(sizeof(char)*strlen(a));  //初始化
    arr2 = (char* )malloc(sizeof(char)*strlen(b));
    arr1[0] = a[0];
    arr2[0] = b[0];

    for(i=0;i<strlen(a);i++){
        sign = 0;    //每次轮到新字母时需要将标志位重置0
        for(j = 0;j<strlen(arr1);j++){
            if(a[i] == arr1[j]){
                sign = 1;   //a字符串中有字符a1与arr1内字符相同则将sign等于1
                break;
            }
        }
        if(!sign){
            arr1[strlen(arr1)] = a[i];
        }
    }
    count1 = strlen(arr1);  //记录arr1长度
    
    for(i=0;i<strlen(b);i++){
        sign = 0;
        for(j=0;j<strlen(arr2);j++){
            if(b[i] == arr2[j]){
                sign =1;
                break;
            }
        }
        if(!sign){
            arr2[strlen(arr2)] = b[i];
        }
    }
    count2 = strlen(arr2);
    if(count1 > count2){
        return 1;   //表示a字符串中不同字符数量大于b，故需要调换顺序
    }else if (count1 < count2) {
        return -1;
    }else {
        int ret = lexicographic_sort(a, b);
        return ret;
    }
}

int sort_by_length(const char* a, const char* b) {
    if(strlen(a) > strlen(b)){
        return 1;
    }else if (strlen(a) < strlen(b)) {
    return -1;
    }else {
    int ret = lexicographic_sort(a,b);
    return ret;
    }
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    int ret;    //调用排序函数的返回结果
    char* temp;  //
    for(int i =0;i<len-1;i++){
        for(int j = i+1;j<len;j++){
            ret = (*cmp_func)(arr[i],arr[j]);
            if(ret == 1){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
        
    }
    return;
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
