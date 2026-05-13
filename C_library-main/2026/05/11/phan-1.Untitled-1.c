#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void printList(struct Node *head){
    struct Node *current = head;
    printf("Danh sach: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main(){
    int a[3];
    printf("Vui long nhap 3 so nguyen: ");
    for(int i = 0; i < 3; i++){
        scanf("%d", &a[i]);
    }
    int i, j, temp;
    int n = 3;
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(a[i] < a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    struct Node *head = NULL;
    struct Node *node[3];
    // le moi struct Node *node1 = (struct Node *)malloc(sizeof(struct Node));
    // lap thi struct Node *node[3]; roi lap node[i] = (struct Node *)malloc(sizeof(struct Node));
    for(i = 0; i < 3; i++){
        node[i] = (struct Node *)malloc(sizeof(struct Node));
    }
    for(i = 0; i < 2; i++){
            node[i]->data = a[i];
            node[i]->next = node[i+1];
    }
            node[2]->data = a[2];
            node[2]->next = NULL;
    head = node[0]; // Head tro den node dau tien
    printList(head);
    for(i = 0; i < 3; i++){
        free(node[i]);
        node[i]=NULL;
    }
        head=NULL;
}
