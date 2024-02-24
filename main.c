#include <stdio.h>
#include "StrList.h"
#include "StrList.c"

int main(){
    StrList* list = StrList_alloc(); //Creating a new list.
    int input;
    int index;
    char word[50];
    

    do{
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            scanf("%d", &input);
            for(int i = 0;i < input;i++){
                char newWord[50];
                scanf("%s",newWord);
                StrList_insertLast(list, newWord);
            }
            break;

        case 2:
            scanf(" %d", &index);
            char words[50];
            if(scanf("%s",words)>=0){
                StrList_insertAt(list,words,index);
            }
            break;

        case 3:
            StrList_print(list);
            break;

        case 4:
            StrList_size(list);
            break;

        case 5:
            scanf(" %d", &index);
            StrList_printAt(list,index);    
            break;


        case 6:
            StrList_printLen(list);    
            break;


        case 7:
            scanf("%s", word);
            StrList_count(list,word);     
            break;


        case 8:
            scanf("%s", word);
            StrList_remove(list,word);    
            break;


        case 9:
            scanf(" %d", &index);
            StrList_removeAt(list,index);    
            break;


        case 10:
            StrList_reverse(list);    
            break;


        case 11:
            int i = (list->_size)-1;
            while(i>0){
                StrList_removeAt(list,i);
                i--;
            }
            list->_head->_data = "";  
            break;

        case 12:
            StrList_sort(list);   
            break;


        case 13:
            StrList_isSorted(list);    
            break;

        case 0:
            StrList_free(list);
            return 0;
            break;
            
        default:
            return 0;
            break;
        } 
    }while(input!=0);
    
return 0;
}
