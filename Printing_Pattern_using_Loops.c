#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
    int i,j;
  	// Complete the code to print the pattern.
    int arr[2*n-1][2*n-1];
    for(i = 0;i<=n-1;i++){
        for(j =i; j<2*n-i; j++){
            arr[i][j] = (n-i);
            arr[2*n-2-i][j] = (n-i);
        }
    }
    for(j =0; j<n-1; j++){
        for(i =j; i<2*n-j-1; i++){
            arr[i][j] = (n-j);
            arr[i][2*n-2-j] = (n-j);
        }
    }
    for(int i=0;i<2*n-1;i++){
        for(int j=0;j<2*n-1;j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

