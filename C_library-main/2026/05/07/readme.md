# Khởi tạo danh sách
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
//node: noi
    int data;
    struct node *next;
};

typedef struct node node;

int main(){
    node *head = (node*)malloc(sizeof(node));
    head->data = 100;
    head->next = NULL;
    printf("Gia tri cua head: %d\n", head);
    printf("Du lieu node ma head quan ly: %d", head->data);
    free(head);
    return 0;
}
```

# Duyệt và in danh sách liên kết
```
#include <stdio.h>
#include <stdlib.h>

struct Node{
//node: noi
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
    struct Node *head = NULL;
    
    //Tao 3 node
    struct Node *node1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node3 = (struct Node *)malloc(sizeof(struct Node));
    
    // Gan du lieu va lien ket
    node1->data = 10;
    node1->next = node2;
    node2->data = 20;
    node2->next = node3;
    node3->data = 30;
    node3->next = NULL;
    
    head = node1; // Head tro den node dau tien
    
    printList(head);
    
    free(node1);free(node2);free(node3);
    node1=NULL; node2=NULL; node3=NULL; head=NULL;
    
    return 0;
}
```

# Thêm node vào đầu danh sách
```
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;

// Ham duyet danh sach
void duyet(node *head) {

    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}
// Ham them vao dau
void themDau(node **head, int x) {

    node *newNode = (node *)malloc(sizeof(node));

    newNode->data = x;

    newNode->next = *head;

    *head = newNode;
}

int main() {

    node *head = NULL;

    // Them tu 1 den 10 vao dau
    for (int i = 1; i <= 10; i++) {
        themDau(&head, i);
    }

    // In danh sach
    duyet(head);

    return 0;
}
```

# Xoá node từ đầu danh sách
```
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node node;

void duyet(node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
        // cho head chuyen sang node ke tiep
    }
}

void themdau(node **head, int x){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->next = (*head);
    (*head) = newNode;
} 
void xoadau(node **head){
    if(*head == NULL) return; // DSLK rong

    node *deleteNode = *head;

    // Cho node head thanh node thu 2 trong DSLK
    (*head) = (*head)->next;

    // Giai phong vung nho
    free(deleteNode);
}

int main(){
    node *head = NULL;
    for(int i = 1; i <= 10; i++){
        themdau(&head, i);
    }
    duyet(head);
    xoadau(&head);
    printf("\n");
    duyet(head);
    return 0;
}
```

# Xoá node từ cuối danh sách
```
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node node;
void duyet(node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
        // cho head chuyen sang node ke tiep
    }
}
void themdau(node **head, int x){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->next = (*head);
    (*head) = newNode;
}
void xoacuoi(node **head){
    if(*head == NULL) return; // DSLK rong
    node *deleteNode = *head;
    // Neu chi co 1 node
    if((*head)->next == NULL){
        free(*head);
        (*head) = NULL;
    }
    else{
        // Luu node dau
        node *tmp = (*head);
        // Cho head sang node ke tiep
        (*head) = (*head)->next;
        // Giai phong node dau cu
        free(tmp);
    }
}

int main(){
    node *head = NULL;
    for(int i = 1; i <= 10; i++){
        themdau(&head, i);
    }
    duyet(head);
    xoacuoi(&head);
    printf("\n");
    duyet(head);
    return 0;
}
```

