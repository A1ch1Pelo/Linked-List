#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

void builder(struct node* n, int init){
	 n->data = init;
	 n->next = NULL;
}	

struct node* list_builder(int val){
	struct node* m = malloc(sizeof(struct node));
        builder(m, val); 
	return m;
}

void add(struct node* n, int val){
   while(n->next != NULL){
	 n = n->next;
   }
   struct node* m = list_builder(val);
   n->next = m;
}

int read(struct node* ptr, int pos){
	for(int i= 0;  pos > i; ++i){
		ptr = ptr->next;
	}
	printf("%d\n", ptr->data);
	return ptr->data;
}

int erase(struct node* pt, int nod){

    for(int i=1; nod > i; ++i){
        pt = pt->next;
    }
    struct node* ptr = pt->next;
    pt->next = ptr->next;
    free(ptr);
    return 0;
}
int write(struct node* ptr, int pos, int val){
    for(int i=0; pos > i; ++i){
        ptr = ptr->next;
    }
	ptr->data = val;
	return val;
}

int read_all(struct node* ptr){
   for(int i=0; ptr->next != NULL; ++i){
	 ptr = ptr->next;
   	 printf("%d\n", ptr->data);
   }
  
	return ptr->data;
}

int erase_all(struct node* ptr){
  struct node* test = ptr; //set to be header
	while(ptr != NULL){
		struct node* buffer = ptr->next; // ptr->next holder 
		free(ptr);
		ptr = buffer;
	}
	test->next=NULL; // set node 1 to be null to leave all node values
	return 0;
}

int main(){
	struct node* head = list_builder(0); // HEADER
	add(head, 100); //1
	add(head, 22); //2
	add(head, 43);  //3
	add(head, 69); //4
	read_all(head); 
	printf("\n");
	//write(head, 0, 39);
	erase_all(head);
	read_all(head);
	return 0;
}
