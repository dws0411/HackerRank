#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
  //Write your code here.
  int i,j;
  int max1,max2,max3;   //用来存计算完后符合规则的结果
  int rst1,rst2,rst3;   //用来存临时计算完成的结果
  max1 = 0;     //初始化
  max2 = 0;
  max3 = 0;
  for(i = 1; i<n; i++){
      for(j = i+1; j<=n; j++){
          rst1 = i & j;
          rst2 = i | j;
          rst3 = i ^ j;
          if(rst1 > max1 && rst1 < k){max1 = rst1;
          }
          if(rst2 > max2 && rst2 < k){max2 = rst2;
          }
          if(rst3 > max3 && rst3 < k){max3 = rst3;
          }

      }
  }
  printf("%d \n",max1);
  printf("%d \n", max2);
  printf("%d", max3);
  return;
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);         //n是字符集S的大小，k是最大临界值
    calculate_the_maximum(n, k);
 
    return 0;
}
