#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

typedef struct Node Node;

void duyet(Node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
        // cho head chuyen sang node ke tiep
    }
}

void themdau(Node **head, int x){
    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->data = x;
    newNode->next = NULL;

    newNode->next = (*head);
    (*head) = newNode;
}

struct Node* deleteTail(struct Node *head){
    // DSLK rong
    if(head == NULL) return NULL;

    // DSLK chi co 1 node
    if(head->next == NULL){
        free(head);
        return NULL;
    }

    struct Node *tmp = head;

    // Duyet den node truoc node cuoi
    while(tmp->next->next != NULL){
        tmp = tmp->next;
    }

    // Luu node cuoi de giai phong
    struct Node *deleteNode = tmp->next;

    // Cho node truoc cuoi tro NULL
    tmp->next = NULL;

    // Giai phong node cuoi
    free(deleteNode);

    return head;
}

int main(){
    Node *head = NULL;

    for(int i = 1; i <= 10; i++){
        themdau(&head, i);
    }

    duyet(head);

    head = deleteTail(head);

    printf("\n");

    duyet(head);

    return 0;
}