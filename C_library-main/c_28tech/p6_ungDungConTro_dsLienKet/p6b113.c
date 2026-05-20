/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;//link
};

typedef struct node node;

void duyet(node *head){
    while(head != NULL){
        printf("%d ", head->data);
        //dich head sang node ben phai
        head = head->next;//quan trong
    }
    printf("\n");
}

int size(node *head){
    int cnt = 0;
    while(head != NULL){
        ++cnt;
        head = head->next;
    }
    return cnt;
}

int main(){
    // tao 3 node
    node *n1 = (node*)malloc(sizeof(node));
    node *n2 = (node*)malloc(sizeof(node));
    node *n3 = (node*)malloc(sizeof(node));
    // gan node
    n1->data = 10;
    n2->data = 20;
    n3->data = 30;
    // lien ket cac node
    node *head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;
    duyet(head);
    printf("Size = %d\n", size(head));
    return 0;
}
