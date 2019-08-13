#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Complete the following function.

int marks_summation(int* marks, int number_of_students, char gender) {
  //Write your code here.
  int count1 = 0,count2 = 0;
  int ret = strcmp(&gender,"g");
  for(int i=0;i<number_of_students;i++){
      if(ret == 0){      //若gender为"g"
            count1 += marks[i+1];
            i++;
      }else {           
            count2 += marks[i];
            i++;
      }
  }
  if(ret == 0){
      return count1;
  }else {
      return count2;
  }
}

int main() {
    int number_of_students;
    char gender;
    int sum;
  
    scanf("%d", &number_of_students);
    int *marks = (int *) malloc(number_of_students * sizeof (int));
 
    for (int student = 0; student < number_of_students; student++) {
        scanf("%d", (marks + student));
    }
    
    scanf(" %c", &gender);
    sum = marks_summation(marks, number_of_students, gender);
    printf("%d", sum);
    free(marks);
 
    return 0;
}