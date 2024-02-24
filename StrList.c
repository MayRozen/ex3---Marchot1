#include <stdio.h>
#include "StrList.h"
#include <stdlib.h>
#include <string.h>

int Compare_list(const void *a, const void *b);

// Node & List Data Structures
typedef struct _node {
    char* _data;
    struct _node * _next;
} Node;


struct _StrList {
    Node* _head;
    size_t _size;
};

StrList* StrList_alloc(){
    StrList* p = (StrList*)malloc(sizeof(StrList));
	p->_head = NULL;
	p->_size = 0;
	return p;
}

Node* Node_alloc(char* data,Node* next){
	Node* n = (Node*)malloc(sizeof(Node));
	n->_data = data;
	n->_next = next;
	return n;
}

void Node_free(Node* node) {
	free(node);
}

void StrList_free(StrList* StrList){
    if (StrList == NULL){
        return;
    } 
	Node* p1 = StrList->_head;
	Node* p2;
	while(p1) {
		p2 = p1;
		p1 = p1->_next;
		Node_free(p2);
	}
	free(StrList);

}

size_t StrList_size(const StrList* StrList){
	int size = (int)StrList->_size;
	printf("%d\n",size);
    return StrList->_size;

}

void StrList_insertLast(StrList* StrList, const char* data){
	char* str = strdup(data);
	Node* newNode = Node_alloc(str,NULL);
	if(StrList->_head == NULL){
		StrList->_head = newNode;
	}
	else{
		Node* p = StrList->_head;
		while(p->_next != NULL){
			p = p->_next;
		}
		p->_next = newNode;
	}
	++(StrList->_size);
}


void StrList_insertAt(StrList* StrList, const char* data,int index){
	char* str = strdup(data);
	Node* newNode = Node_alloc(str,NULL);
	Node* p = StrList->_head;
	Node* prev = NULL;
	for(int i = 0; i < index&&p!=NULL; i++){
		prev = p;
		p = p->_next;
	}
	newNode->_next = p;
	prev->_next = newNode;
	++(StrList->_size);
}

char* StrList_firstData(const StrList* list){
	char* ans = (char*)list->_head->_data;
    return ans;
}

void StrList_print(const StrList* StrList){
    Node* p = StrList->_head;
	while(p->_next!=NULL) {
		printf("%s ",p->_data);
		p = p->_next;
	}
	if(p!=NULL){
		printf("%s",p->_data);
	}
	printf("\n");
}

void StrList_printAt(const StrList* Strlist,int index){// hadar
	Node* p = Strlist->_head;
	for (int i = 0; i < index&&p!=NULL; i++)
	{
		p = p->_next;
	}
	printf("%s\n",p->_data);
}

int StrList_printLen(const StrList* Strlist){//hadar
	Node* p = Strlist->_head;
	char* str = Strlist->_head->_data;
	int count = 0;
	while (p->_next!=NULL)
		{
			count += strlen(str);
			p = p->_next;
			str = p->_data;
		}
		count += strlen(str);
		printf("%d\n",count);
	return count;
}

int StrList_count(StrList* StrList, const char* data){//hadar
	int count = 0;
	Node* p = StrList->_head;
	char *str = StrList->_head->_data;
	while (p!=NULL){
		if(strcmp(str,data) == 0){
			count++;
		}
		str = p->_data;
		p = p->_next;
		}
	printf("%d\n",count);
	return count;
}

void StrList_remove(StrList* list, const char* data){//hadar
	char *str = list->_head->_data;
	Node* p = list->_head;
	Node* prev = NULL;
	while (p!=NULL){
		if(strcmp(str,data) == 0){
			if (prev == NULL) {
					// If the match is in the first node
					list->_head = p->_next;
				}
			else {
				// If the match is in a subsequent node
					prev->_next = p->_next;
				}
				free(p);
				--(list->_size);
				return;
			}
		prev = p;
		p = p->_next;
		str = p->_data;
	}
}

void StrList_removeAt(StrList* list, int index){//hadar
	if(list->_head == NULL){//if the list is empty
		return;
	}
	Node* p = list->_head;
	Node* prev = NULL;
	for (int i = 0; i<index;i++){
		prev = p;
		p = p->_next;
	}
	if(prev == NULL){//the head is removed
		if(p->_next == NULL){//if we remove the last node of the list
			list->_head = NULL;
			free(p);
			--(list->_size);
			return;
		}
		list->_head = p->_next;
	}
	else if(p->_next == NULL){
		prev->_next = NULL;
	}
	else {
		// If the match is in a subsequent node
		prev->_next = p->_next;
	}
	free(p);
	--(list->_size);
}

int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){
    const int eq= 0;
	const int neq= 1;
	
	const Node* p1= StrList1->_head;
	const Node* p2= StrList2->_head;
	while(p1!=NULL) {
		if (p2==NULL||p1->_data!=p2->_data) return neq;
		p1= p1->_next;
		p2= p2->_next;
	}
	if (p2!=NULL) return neq;
	return eq;
}

StrList* StrList_clone(const StrList* StringList){
    StrList*  ret = StrList_alloc();
	StrList* cloneH = (StrList*)malloc(sizeof(StrList));
	ret->_size= StringList->_size;
	strcpy(cloneH->_head->_data,StringList->_head->_data);
	cloneH->_head->_next = NULL;
	Node* copyP = cloneH->_head;
	Node* origP = NULL;
	if (StringList->_head==NULL)
	{
		return NULL;
	}
	
	while(origP!=NULL) {
		Node* newNode = (Node*)malloc(sizeof(Node));
		strcpy(newNode->_data, origP->_data);
		newNode->_next = NULL;
		copyP->_next = newNode;
		origP = origP->_next;
	}
	return cloneH;

}

void StrList_reverse(StrList* list){
	Node* p = list->_head;
	Node* prev = NULL;
	Node* nextNode = NULL;
	while (p != NULL) {
			// Save the next node
			nextNode = p->_next;
			
			// Reverse the link
			p->_next = prev;
			
			// Move to the next nodes
			prev = p;
			p = nextNode;
		}
		// Update the head of the list
		list->_head = prev;
}

void StrList_sort(StrList* list){
	if(list->_head==NULL){
		return;
	}
	Node* p = list->_head;
	Node* ptmp = list->_head;
	char* tmp = "";
		while(ptmp!=NULL){
			p = ptmp;
			while(p!=NULL){
				if (strcmp(ptmp->_data,p->_data) > 0){
					tmp = ptmp->_data;
					ptmp->_data = p->_data;
					p->_data = tmp;
				}
				p = p->_next;
			}
			ptmp = ptmp->_next;
		}
}

int StrList_isSorted(StrList* StrList){
	Node* p = StrList->_head->_next;
	Node* prev = StrList->_head;
	while(p!=NULL){
		if((strcmp(prev->_data,p->_data))>0){
			printf("false\n");
			return 0; //false
		}
		prev = p;
		p = p->_next;
	}
	printf("true\n");
	return 1; //true
}
