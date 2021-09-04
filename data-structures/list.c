#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node *next;
};

typedef struct Node Node;
Node *head, *tail = NULL;
int len = 0;

Node *create_node(int x);
void append(int x);
void del(int pos);
void display();

int main(){
    append(1);
    append(2);
    append(3);
    append(4);
    display();
    printf("\nlen = %d\n\n", len);
    
    del(2);
    display();
    printf("\nlen = %d", len);
    
    return 0;
}

Node *create_node(int x){
    Node *temp;
    temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void append(int x){
    Node *new_node = create_node(x);
    if(head == NULL){
        head = tail = new_node;
    }
    else{
        tail->next = new_node;
        tail = new_node;
    }
    len++;
}

void del(int pos){
    Node *actual = head;
    
    if(pos == 0){
        head = head->next;
    }
    else{
        for(int i = 0; i < pos - 1; i++){
            actual = actual->next;
        }
        Node *deleted = actual->next;
        actual->next = actual->next->next;
        free(deleted);
    }
    len--;
}

void display(){
    if(head == NULL){
        printf("A lista está vazia!");
    }
    else{
        Node *actual = head;
        while(actual != NULL){
           printf("%d; ", actual->data);
           actual = actual->next;
        }
    }
}
