#include <stdio.h>
#include "StrList.h"


int main(){

    StrList_alloc(); //Creating a new list.
    int input;
    // int graph[GRAPH_SIZE][GRAPH_SIZE];

    do{
        scanf(" %d", &input);
        switch (input)
        {
        case 1:
            putInValues(graph);
            floydWarshall(graph);
            break;

        case 2:
            ifPathItoJ(graph);
            break;

        case 3:
            shortestPath(graph);
            break;

        case 4:
            return 0;
            break;

        case 5:
            return 0;     
            break;


        case 6:
            return 0;     
            break;


        case 7:
            return 0;     
            break;


        case 8:
            return 0;     
            break;


        case 9:
            return 0;     
            break;


        case 10:
            return 0;     
            break;


        case 11:
            return 0;     
            break;


        case 12:
            return 0;     
            break;


        case 13:
            return 0;     
            break;

        case 0:
            return 0;
            break;
            
        default:
            break;
        } 
    }
    while(1);
    
return 0;
}


