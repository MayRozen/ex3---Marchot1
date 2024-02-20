#include <stdio.h>
#include "StrList.h"
#include "StrList.c"
#define SIZE 1000

int main(){
    StrList* StrList= StrList_alloc(); //Creating a new list.
    int input;
    char str[SIZE];
    int index;
    // int graph[GRAPH_SIZE][GRAPH_SIZE];

    do{
        scanf(" %d", &input);
        switch (input)
        {
        case 1:
            scanf(" %d", &input);
            for(int i=0;i<input;i++){
                scanf(" %s", str);
                StrList_insertLast(StrList, str);
            } 
            break;

        case 2:
        scanf(" %d", &index);
        scanf(" %s", str);
            StrList_insertAt(StrList,str,index);
            break;

        case 3:
            StrList_print(StrList);
            break;

        case 4:
        StrList_size(StrList);
            return 0;
            break;

        case 5:
        scanf(" %d", &index);
        StrList_printAt(StrList,index);
            return 0;     
            break;


        case 6:
        StrList_printLen(StrList);
            return 0;     
            break;


        case 7:
        scanf(" %s", str);
        StrList_count( StrList,str);
            return 0;     
            break;


        case 8:
        scanf(" %s", str);
        StrList_remove(StrList,str);
            return 0;     
            break;


        case 9:
        scanf(" %d", &index);
        StrList_removeAt(StrList,index);
            return 0;     
            break;


        case 10:
        StrList_reverse(StrList);
            return 0;     
            break;


        case 11:
            StrList_free(StrList);
            return 0;     
            break;


        case 12:
        StrList_sort(StrList);
            return 0;     
            break;


        case 13:
        StrList_isSorted(StrList);
            return 0;     
            break;

        case 0:
        StrList_free(StrList);
            return 0;
            break;
            
        default:
            break;
        } 
    }
    while(input!=0);
    
return 0;
}

