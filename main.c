#include <stdio.h>
#include "StrList.h"
#include "StrList.c"
#define SIZE 1000

int main(){
    StrList* StrList = StrList_alloc(); //Creating a new list.
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
            scanf(" %s", str);
            for(int i = 0; i<input;i++){
                int j = 0;
                char word[SIZE];
                while(strcmp(&str[i]," ")!=0){
                    word[j] = str[i]; 
                } 
                StrList_insertLast(StrList, word);
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
            break;

        case 5:
            scanf(" %d", &index);
            StrList_printAt(StrList,index);    
            break;


        case 6:
            StrList_printLen(StrList);    
            break;


        case 7:
            scanf(" %s", str);
            StrList_count( StrList,str);     
            break;


        case 8:
            scanf(" %s", str);
            StrList_remove(StrList,str);    
            break;


        case 9:
            scanf(" %d", &index);
            StrList_removeAt(StrList,index);    
            break;


        case 10:
            StrList_reverse(StrList);    
            break;


        case 11:
            StrList_free(StrList);    
            break;


        case 12:
            StrList_sort(StrList);   
            break;


        case 13:
            StrList_isSorted(StrList);    
            break;

        case 0:
            StrList_free(StrList);
            return 0;
            break;
            
        default:
            break;
        } 
    }
    while(1);
    
return 0;
}

