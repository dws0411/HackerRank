#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int* total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int** total_number_of_pages;

int main()
{
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);
    
    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);
    //初始化两个指针
    total_number_of_books=(int*)malloc(sizeof(int)*total_number_of_shelves);
    
    total_number_of_pages=(int**)malloc(sizeof(int*)*total_number_of_shelves);
    
    for(int i=0; i<total_number_of_shelves; i++){
        total_number_of_books[i]=0;
        total_number_of_pages[i]=(int*)malloc(sizeof(int));//此处注意，此处仅仅为totao_number_of_pages[i]又申请了“1个”int类型的数据空间，故后续需要再继续增加
    }
    
    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) {
            int x, y;
            scanf("%d %d", &x, &y);
            //x书架书的总数+1
            *(total_number_of_books+x)+=1;
            //由于指针total_number_of_pages[i]在初始化时，仅仅为其下一维数组初始化了1个int数据空间，故当添加多本书时，需要动态添加
            *(total_number_of_pages+x)=realloc(*(total_number_of_pages+x), *(total_number_of_books+x)*sizeof(int));
            //往x书架的最后添加一本y页的书
            *(*(total_number_of_pages+x)+*(total_number_of_books+x)-1)=y;
        } else if (type_of_query == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }
    
    return 0;
}
